#!/bin/sh
# TODO:
# ? build:
#   - set flags per project? (per version too?).
#   - add build status (OK, FAIL, unknown), must be secure though.

projects() {
cat <<!__EOF__
dmenu	tools.suckless.org/dmenu/patches
dwm	dwm.suckless.org/patches
ii	tools.suckless.org/ii/patches
sent	tools.suckless.org/sent/patches
sic	tools.suckless.org/sic/patches
slock	tools.suckless.org/slock/patches
st	st.suckless.org/patches
surf	surf.suckless.org/patches
tabbed	tools.suckless.org/tabbed/patches
!__EOF__
}

wikidir="$(pwd)/sites"
repodir="$(pwd)/repos"
revdir="$(pwd)/rev"
resultsdir="$(pwd)/results"
builddir="$(pwd)/build"

# dryrun patch command (OpenBSD).
# must be unified diff (-u, so no ed script), -t and -C are dryrun (non-POSIX).
dryrun="patch -u -p1 -t -C"

# getdateutc()
getdateutc() {
	# date as UTC+0 time.
	TZ="UTC+0" date
}

# log(s)
log() {
	s="[$(date)] $1"
	echo "$s" >&2
}

# getprojects()
getprojects() {
	# allow commenting to disable.
	projects | grep -v '^#'
}

# clone()
clone() {
	getprojects | while read -r -- project dir; do
		test -d "$repodir/$project" && continue

		git clone --bare "git://git.suckless.org/$project" "$repodir/$project"
	done
}

# pull()
pull() {
	getprojects | while read -r -- project dir; do
		test -d "$repodir/$project" || continue

		GIT_DIR="$repodir/$project" git fetch "git://git.suckless.org/$project"
	done
}

# listpatches()
listpatches() {
	getprojects | while read -r -- project dir; do
		find "$wikidir/$dir" -name "*.diff" | while read -r p; do
			test -f "$p" || continue

			b=$(basename "$p")
			bb="${b%.diff}"
			bb="${bb#${project}-}"

			# NOTE: historical patches like "r1506" (mercurial) are ignored.
			v=$(echo "$bb" | sed -En 's@^([0-9a-f\.]+)-.*$@\1@p')
			if test -z "$v"; then
				v=$(echo "$bb" | sed -En 's@^.*-([0-9a-f\.]+)$@\1@p')
			fi

			# version not found, skip.
			if test -z "$v"; then
				continue
			fi

			name="${p%.diff}"
			name="${name##*/patches/}"
			name="${name%%/*}"

			printf '%s\t%s\t%s\t%s\t%s\n' "$project" "$v" "$dir" "$name" "$p"
		done
	done
}

# checkoutrev(project, version)
checkoutrev() {
	project="$1"
	v="$2"

	test -f "$revdir/$project/$v/fail" && return 1
	test -d "$revdir/$project/$v" && return 0

	cur=$(pwd)
	d="$revdir/$project/$v"
	mkdir -p "$d"
	cd "$d" || return 1

	GIT_DIR="$repodir/$project" \
		git archive "$v" 2> "$revdir/$project/$v/fail" | \
		tar xf - 2>/dev/null
	status=$?
	if test x"$status" != x"0"; then
		status=1
	else
		rm -f "$revdir/$project/$v/fail"
	fi
	cd "$cur"

	return $status
}

# preparebuilds()
preparebuilds() {
	listpatches | while read -r -- project v dir name p; do
		test -f "$p" || continue

		# version quirks (wrong tagging).
		if test x"$project" = x"sent"; then
			if test x"$v" = x"1.0"; then
				v="1"
				test -e "$revdir/$project/1.0" || \
					ln -sf "$v" "$revdir/$project/1.0"
			fi
		fi
		if test x"$project" = x"ii"; then
			if test x"$v" = x"1.7"; then
				v="v1.7"
				test -e "$revdir/$project/1.7" || \
					ln -sf "$v" "$revdir/$project/1.7"
			fi
		fi

		# prepare clean build directory for patch.
		b=$(basename "$p")
		b="${b%.diff}"

		# cannot prepare revision for build: skip.
		if ! checkoutrev "$project" "$v"; then
			log "CANNOT CHECKOUT REVISION: $project v=$v, name=$name, patch=$b, error=$(cat "$revdir/$project/$v/fail")"
			continue
		fi

		# already has clean builddir.
		test -d "$builddir/$project/$b" && continue
		cleanbuild "$project" "$v" "$b"
	done
}

# cleanbuild(project, version, build)
cleanbuild() {
	project="$1"
	v="$2"
	b="$3"

	test -d "$builddir/$project/$b" && rm -rf "$builddir/$project/$b"

	mkdir -p "$builddir/$project"
	cp -r "$revdir/$project/$v" "$builddir/$project/$b"
}

# testpatches()
testpatches() {
	# sort by project, name, version
	listpatches | sort -k1,1 -k4,4 -k2,2 | \
		while read -r -- project v dir name p; do
		test -f "$p" || continue

		# cannot prepare revision for build: skip.
		checkoutrev "$project" "$v" || continue

		b=$(basename "$p")
		b="${b%.diff}"

		test -d "$builddir/$project/$b" || continue
		cd "$builddir/$project/$b" || continue

		# copy patch file for convenience / debugging.
		cp "$p" "$builddir/$project/$b/p.diff"

		# lenient: copy config.def.h to config.h if config.h doesn't exist.
		#rm -f "$builddir/$project/$b/config.h" # DEBUG
		#if test -f "$builddir/$project/$b/config.def.h"; then
		#	if ! test -f "$builddir/$project/$b/config.h"; then
		#		cp "$builddir/$project/$b/config.def.h" "$builddir/$project/$b/config.h"
		#	fi
		#fi

		# patch (dryrun).
		$dryrun < "$p" 2> "$builddir/$project/$b/patch.2.log" >"$builddir/$project/$b/patch.1.log"
		applystatus=$?

		# write results to metadata file (for creating views).
		printf "%s\t%s\t%s\t%s\t%s\t%s\n" \
			"$project" "$v" "$dir" "$name" "$applystatus" "$b" > "$builddir/$project/$b/metadata"

		log "$p	$applystatus"
	done
}

# outputhtml()
outputhtml() {
	index="$resultsdir/index.html"
	title="Last updated on $(getdateutc)"

cat > "$index" <<!__EOF__
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>$title - Patch applystatus</title>
<style type="text/css">
table       { border-collapse: collapse; }
td          { padding: 2px; }
thead td    { background-color: #eee; }
.s-0 td     { background-color: #ccffcc; }
.s-1 td     { background-color: #ffcccc; }
.s-2 td     { background-color: #ff0000; color: #fff; }
</style>
</head>
<body>
<h1>$title</h1>
<table>
<thead>
<tr>
	<td><b>Project</b></td>
	<td><b>Version/revision</b></td>
	<td><b>Patch</b></td>
	<td><b>Patch</b></td>
	<td><b>Patch file</b></td>
	<td><b>Patch stdout</b></td>
	<td><b>Patch stderr</b></td>
	<td><b>Exitcode</b></td>
	<td><b>Status</b></td>
</tr>
</thead>
<tbody>
!__EOF__

	# sort by project, name, version
	find "$builddir" -name "metadata" -type f -exec cat {} \; | \
		sort -k1,1 -k4,4 -k2,2 | \
		while read -r -- project v dir name applystatus b; do
		test -d "$builddir/$project/$b" || continue

		# HTML output test
		mkdir -p "$resultsdir/$b/"
		cp \
			"$builddir/$project/$b/p.diff"\
			"$builddir/$project/$b/patch.2.log"\
			"$builddir/$project/$b/patch.1.log"\
			"$resultsdir/$b/"

		statustext="OK"
		pageurl="https://$dir/$name/"

		case "$applystatus" in
		0) statustext="OK";;
		1) statustext="FAIL";;
		2) statustext="CORRUPT";;
		*) statustext="UNKNOWN";;
		esac

		cat >> "$index" <<!__EOF__
<tr class="s-$applystatus">
	<td><a href="https://git.suckless.org/$project/">$project</a></td>
	<td>$v</td>
	<td><a href="$pageurl">$name</a></td>
	<td><a href="$pageurl">$b</a></td>
	<td><a href="$b/p.diff">[patch]</a></td>
	<td><a href="$b/patch.1.log">[stdout]</a></td>
	<td><a href="$b/patch.2.log">[stderr]</a></td>
	<td>$applystatus</td>
	<td>$statustext</td>
</tr>
!__EOF__
	done

	echo "</tbody></table></body></html>" >> "$index"
}

# outputcsv()
outputcsv() {
	index="$resultsdir/index.csv"

	# sort by project, name, version
	find "$builddir" -name "metadata" -type f -exec cat {} \; | \
		sort -k1,1 -k4,4 -k2,2 | \
		while read -r -- project v dir name applystatus b; do
		test -d "$builddir/$project/$b" || continue

		printf '%s\n' "$project	$v	$name	$b	$applystatus" >> "$index"
	done
}

case "$1" in
clone|pull)
	mkdir -p "$repodir"
	$1
	;;
clean)
	rm -rf "$revdir" "$builddir"
	;;
prepare)
	mkdir -p "$builddir" "$revdir"
	preparebuilds
	;;
test)
	testpatches
	;;
results)
	# output results
	rm -rf "$resultsdir"
	mkdir -p "$resultsdir"
	outputhtml
	outputcsv
	;;
*)
	echo "usage: $0 <clone | pull | clean | prepare | test | results>" >&2
	exit 1
	;;
esac
