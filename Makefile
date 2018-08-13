PROG = ulist
CC = g++
CPPFLAGS = -g -Wall

OBJS = main.o Linked_List.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o:
	$(CC) $(CPPFLAGS) -c main.cpp

Linked_List.o : Linked_List.h
	$(CC) $(CPPFLAGS) -c Linked_List.cpp
    
clean:
	rm -f core $(PROG) $(OBJS)


