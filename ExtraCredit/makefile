CC=gcc #This is the compiler
#This is the list of files
FILES=profiler.c
#this is the output file/ what we actually run
OUT_EXE = a.out 
#These are different build commands/modes
all: build 
build: $(FILES) 
	$(CC) -o $(OUT_EXE) $(FILES) 
clean: 
	rm -f *.o $(OUT_EXE)
package: 
	zip -r Tatiana_Gabel_ExtraCredit.zip profiler.c makefile README.txt
#run:	${OUT_EXE}
#		./${OUT_EXE} ${ARGS}