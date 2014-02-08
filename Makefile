CC = g++

individual_cash_flow.exe: main.cpp
	$(CC) main.cpp -o individual_cash_flow.exe
$(OBJ): 

clean:
	rm -f $(OBJ) *~ *.exe *.o
