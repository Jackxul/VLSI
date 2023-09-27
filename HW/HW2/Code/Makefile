# -*-Out Makefile -*-
# Time-stamp: <2023-09-20 18:32:00 kmodi>

build:=$(shell mkdir -p build)
build:=$(shell mkdir -p exe)

DODEBUG = 1

sub: 
	$(MAKE) -C src DODEBUG=$(DODEBUG)
	@echo "Call Sub Makefile : Done."
.PHONY: clean
clean:
	@echo "Makefile_out : Cleaning up..."
	@rm -rf build
	@rm -rf exe 
	@echo "Makefile Clean : Done."
	@tree . -L 2
