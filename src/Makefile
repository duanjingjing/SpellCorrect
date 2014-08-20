.PHONY:clean
CC=g++
CFLAGS=-Wall -g
BIN=main
OBJS=TextQuery.o Configure2.o QueryServer.o WordIndex.o
LINK=-lpthread
STAR=-std=c++0x
OTHER=test_query.cpp

$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $(OTHER) $^ -o $@ $(LINK) $(STAR) -lecho
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(STAR)
clean:
	rm -f *.o $(BIN)
