.PHONY: all clean diff sync new rebuild new_clean

all clean:
	$(MAKE) -C cur $@

diff: clean new_clean
	diff -ruN cur new || true

sync: clean
	rm -Rf new/*
	cp -R cur/* new/

new:
	$(MAKE) -C new

rebuild:
	rm -Rf cur/*
	for p in `ls -v delta/*.patch`; do patch -dcur -p1 <$$p; done

new_clean:
	$(MAKE) -C new clean
