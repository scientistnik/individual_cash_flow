cc = gcc
OBJ = main.o io.o
individual_cash_flow.exe: $(OBJ)
	cc -o individual_cash_flow.exe $(OBJ)
$(OBJ): io.h

clean:
#if [ ls *.o *~ ];	then \
#rm *.o *~ 2> /dev/null \	
#fi
	rm $(OBJ) *~
