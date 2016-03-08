
VPATH=:./inc/:./src/:./obj

TARGET1=TMerge

HEADER= -I ./inc

CFLAGS=-g -Wall -lpthread


$(TARGET1) : TMerge.o TMerge_Sort.o App.o
	gcc -o $(TARGET1) $^ $(HEADER) $(CFLAGS)
	mv *.o ./obj

%.o : %.c
	gcc -c $< $(HEADER) $(CFLAGS)
		


clean :
	rm -f $(TARGET1) $(TARGET2)
	rm -f ./obj/*
	rm -f *.o

rmbackup : 
	rm -f *~
	rm -f ./src/*~
	rm -f ./inc/*~

