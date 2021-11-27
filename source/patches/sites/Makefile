CFLAGS = -Wall -Wextra -std=c99 -pedantic
LDFLAGS = -static -s

all: html

gph: build-page
	find * -type d -exec sh -ec './build-page -g "$$0" >$$0/index.gph' {} \;

html: build-page
	find * -type d -exec sh -ec './build-page "$$0" >$$0/index.html' {} \;

build-page: build-page.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ build-page.c

clean:
	rm -f build-page
