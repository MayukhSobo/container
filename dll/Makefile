##############################################
#	Author  :  Mayukh Sarkar
#       Email   :  mayukh2012@icloud.com
#       Type    :  Intermediate
#       License :  GPL v3
##############################################

###########  Macros Deifines ##############
CC 		:=  gcc
C++11 		:= -std=c++11
C++14 		:= -std=c++14
CXXFLAGS	:= -c
LINK      := -o
EXE       := dll	
.PHONY    := clean

SRC       := $(wildcard *.c)
OBJ	  := $(patsubst %.c, %.o, $(SRC))
##########################################


############# Makefile Rules  #############
all: $(EXE)
	@echo
	@echo ------- Running ./$(EXE) -------------
	@./$(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(LINK) $@ 

%.o:	%.c
	$(CC) $(CXXFLAGS) $< -o $@

clean:
	rm -rf ./$(EXE) $(OBJ)
###########################################
