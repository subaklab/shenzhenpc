CPPUTEST_HOME = ../../cpputest-3.7.1
CPPFLAGS += -I$(CPPUTEST_HOME)/include
LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lpthread -static
OBJS = test_first.o
#OPTIONS = -std=c++11
OPTIONS = 
CC = g++

.SUFFIXES: .cpp

test: test_runner
	./$<

test_runner: $(OBJS)
	$(CC) -o $@ $(OBJS) $(CPPFLAGS) $(LD_LIBRARIES) $(OPTIONS)

.cpp.o:
	$(CC) -c $< -o $@ $(CPPFLAGS) $(OPTIONS)

clean:
	@rm test_runner *.o

test_first.o: test_first.cpp
