.PHONY: all clean diff sync new new_clean

all clean:
	$(MAKE) -C cur $@

diff: clean new_clean
	diff -ruN cur new

sync:
	rm -Rf new/*
	cp -R cur/* new/

new:
	$(MAKE) -C new

new_clean:
	$(MAKE) -C new clean
