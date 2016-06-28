SRC=main.C image.C sink.C source.C PNMreader.C PNMwriter.C filters.C
OBJ=$(SRC:.C=.o)

prog: $(OBJ)
	g++ $(OBJ) -o proj

.C.o: $<
	g++ -I. -c $<

clean:
	rm *.o proj
