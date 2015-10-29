export DISTRIB_ROOT=$(PWD)

MAKE:=make

.PHONY: all clean

all:
	$(MAKE) -C lru_cache

clean:
	$(MAKE) -C lru_cache clean
