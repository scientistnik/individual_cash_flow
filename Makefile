CC = gcc
OBJ = main.o
individual_cash_flow.exe: main.c
	$(CC) main.c -o individual_cash_flow.exe
$(OBJ): 

clean:
	rm -f $(OBJ) *~ *.exe *.o
