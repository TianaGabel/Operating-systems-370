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
#run:	${OUT_EXE}
#		./${OUT_EXE} ${ARGS}