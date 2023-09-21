# -*-Out Makefile -*-
# Time-stamp: <2016-03-31 16:32:00 kmodi>

build:=$(shell mkdir -p build)
build:=$(shell mkdir -p exe)


sub: 
	cd src && $(MAKE)
	@echo "Call Sub Makefile : Done."
.PHONY: clean
clean:
	@echo "Makefile_out : Cleaning up..."
	@rm -rf build
	@rm -rf exe 
	@echo "Makefile Clean : Done."
	@tree .
