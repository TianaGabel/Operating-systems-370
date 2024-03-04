JC = javac

#This is the list of files
CLASSES =

#this is the output file/ what we actually run
OUT_EXE = a.out 
#These are different build commands/modes
all: compile 
compile: $(CLASSES) 
	javac -d . --class-path $(CLASSES) 
clean:
        $(RM) *.class