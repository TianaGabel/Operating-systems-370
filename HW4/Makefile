JC = javac

#This is the list of files
CLASSES = Consumer.java Main.java Monitor.java Producer.java

#this is the output file/ what we actually run
OUT_EXE = a.out 
#These are different build commands/modes
all: compile 
compile: $(CLASSES) 
	javac -cp . $(CLASSES) 
clean:
	$(RM) *.class
package: 
	zip -r Tatiana-Gabel-HW4.zip $(CLASSES) Makefile README.txt 