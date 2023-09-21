# -*- Sub Makefile -*-
# Time-stamp: <2016-03-31 16:32:00 kmodi>

CC:=gcc
CFLAGS:=-Wall -c
B_DIR := ../build
E_DIR := ../exe
I_DIR := ../include
SRC=${wildcard *.c}
OBJ = $(patsubst %.c,$(B_DIR)/%.o,$(SRC))

exe:=start

$(exe): $(OBJ)
	$(CC) $(OBJ) -lncurses -o $(E_DIR)/$@
	@echo "Makefile: Done."
$(B_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -I $(I_DIR) -c $< -o $@
	@echo  "Building objective file $@ from $< ..."
.PHONY: clean
clean:
	@echo "Makefile_sub : Cleaning up..."
	rm -rf ./../build
	rm -rf $(E_DIR)
	@echo "Makefile: Done."
	@tree ./../
