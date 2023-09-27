# -*- Sub Makefile -*-
# Time-stamp: <2023-09-20 18:53:00 kmodi>

CC:=gcc
CFLAGS:=-Wall -Wextra

DODEBUG ?= 0
ifeq ($(DODEBUG), 1)
	CFLAGS += -DDEBUG_MODE=1
endif

B_DIR := ../build
E_DIR := ../exe
I_DIR := ../include
SRC=${wildcard *.c}
OBJ = $(patsubst %.c,$(B_DIR)/%.o,$(SRC))
EXE:=mlrcs


.PHONY: all clean

all:$(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(E_DIR)/$@
	@echo "Makefile: Done."
	@echo "	**********************************"
	@echo "	*  -h  for heuristic algorithm   *"
	@echo "	*  -e  for ILP formulation       *"
	@echo "	*  EX : mlrcs -e testfile.blif   *"
	@echo "	**********************************"
$(B_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -I $(I_DIR) -c $< -o $@
	@echo  "Building objective file $@ from $< ..."
clean:
	@echo "Makefile_sub : Cleaning up..."
	rm -rf ./../build
	rm -rf $(E_DIR)
	@echo "Makefile: Done."
	@tree ./../
