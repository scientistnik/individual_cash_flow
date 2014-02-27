CC = javac
OBJ=individual_cash_flow

individual_cash_flow.class: $(OBJ).java
	clear
	$(CC) $(OBJ).java
go:
	java $(OBJ)
clean:
	rm -f $(OBJ).class *~ *.class *.o
