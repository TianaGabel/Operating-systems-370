# CC=gcc
# FILES=Coordinator.c 
# OUT_EXE = a.out 
# all: build 
# build: $(FILES) 
# 	$(CC) -o $(OUT_EXE) $(FILES) 
# clean: 
# 	rm -f *.o $(OUT_EXE)


#list of files 
C_SRCS = Coordinator.c Checker.c 
C_OBJS = Coordinator.o Checker.o 

#C_HEADERS, the lower case versions are the object image and what will be called in execlp()
OBJS = ${C_OBJS} 
EXE1 = coordinator 
EXE2 = checker 

#compiler and loader commands and flags 
GCC = gcc 
GCC_FLAGS = -std=c11 -g -Wall -c -I. 
LD_FLAGS = -std=c11 -g -Wall -I. 

#compile .c files to .o files 
.c.o: 
	$(GCC) $(GCC_FLAGS) $< 

#target is the executable, these are all of the make commands
all: coordinator checker 
coordinator: Coordinator.o 
	$(GCC) $(LD_FLAGS) Coordinator.o -o $(EXE1) 
checker: Checker.o 
	$(GCC) $(LD_FLAGS) Checker.o -o $(EXE2) 

#recomplile c objects if headers change 
$(C_OBJS): ${C_HEADERS} 

#clean up directory The package command will zip all of these files for you
clean: 
	rm -f *.o *- $(EXE1) $(EXE2) 
package: 
	zip -r Tatiana-Gabel-HW2.zip Coordinator.c Checker.c Makefile README.txt 
