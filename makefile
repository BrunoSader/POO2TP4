CPFLAGS = -Wall -ansi -pedantic -std=c++11  -g
EXECUTABLE = main.o reader.o top10.o graphGen.o
ENTETES = reader.h top10.h graphGen.h

analog : $(EXECUTABLE)
	@echo "EDL"
	g++ -o analog $(EXECUTABLE)

%.o : %.cpp %.h
	@echo "Compil de :$@"
	g++ -c $(CPFLAGS) $<

main.o : $(ENTETES)

top10.o : reader.h

graphGen.o: reader.h

clean :
	rm *.o

run :
	./analog
