#PATH="$PATH:~/.local/bin"

PS1="%F{cyan}[%n@%m]%f %F{red}::%f %F{green}%~%f %F{magenta}%#%f " 


# Functions
function chpwd() {
    exa
}

# History Settings
HISTORY="$HOME/.zsh_history"
HISTSIZE=5000
SAVEHIST=1000
setopt HIST_EXPIRE_DUPS_FIRST
setopt HIST_IGNORE_DUPS
setopt HIST_IGNORE_SPACE
setopt SHARE_HISTORY

# Misc Options
setopt AUTOCD
setopt CORRECT
setopt AUTO_MENU
EDITOR="micro"
#PRIVESC="sudo"
PRIVESC="doas"

# Plugins
#source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
#source /usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh
source ~/.config/zsh-plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
source ~/.config/zsh-plugins/zsh-autosuggestions/zsh-autosuggestions.zsh

# Aliases
alias ls="exa"
alias la="exa -a"
alias ll="exa -l"
alias lla="exa -a -l"
alias emacs="emacsclient -c"
alias rick="$HOME/scripts/rick.sh"
alias vim="nvim"
alias rm="srm -P"
alias cp="rsync -a"
alias s="sudo"
alias d="doas"
alias e="$PRIVESC"
alias reboot="$PRIVESC reboot"
alias poweroff="$PRIVESC poweroff"
alias ed="$EDITOR"

## Package Management

### Arch
alias p="pacman"
alias ep="$PRIVESC pacman"

### Void
alias xbpi="$PRIVESC xbps-install"
alias xbpr="$PRIVESC xbps-remove"
alias xbprc="xbps-reconfigure"
alias xbpq="xbps-query"
alias xbpa="xbps-alternatives"
alias xbpri="xbps-rindex"
alias xbpp="xbps-pkgdb"

# Autocomplete

## The following lines were added by compinstall
zstyle ':completion:*' completer _expand _complete _ignored _correct _approximate
zstyle ':completion:*' list-colors ${(s.:.)LS_COLORS}
zstyle ':completion:*' list-prompt %SAt %p: Hit TAB for more, or the character to insert%s
zstyle ':completion:*' matcher-list '' 'm:{[:lower:][:upper:]}={[:upper:][:lower:]}' 'r:|[._-]=* r:|=*'
zstyle ':completion:*' menu select=1
zstyle ':completion:*' select-prompt %SScrolling active: current selection at %p%s
zstyle :compinstall filename '/home/hens/.zshrc'

autoload -Uz compinit
compinit
## End of lines added by compinstall



# External Variables
export PAGER=most
