CPPUTEST_HOME = ../../cpputest-3.7.1
CPPFLAGS += -I$(CPPUTEST_HOME)/include
#LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lpthread -static
LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lpthread
OBJS = test_first.o test_LightScheduler.o # TODO: ADD TEST OBJ
#OPTIONS = -std=c++11
OPTIONS = 
CC = g++

CPPFLAGS += -I../HomeAutomation
vpath %.c ../HomeAutomation
vpath %.cpp ../HomeAutomation
OBJS += LightScheduler.o LightController.o TimeService.o # TODO: ADD Production OBJ
OBJS += FakeTimeService.o LightControllerSpy.o # TODO: ADD Test Double OBJ

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

# TODO: ADD TEST CPP SOURCE
test_LightScheduler.o: test_LightScheduler.cpp
LightScheduler.o: LightScheduler.cpp
LightController.o: LightController.cpp
TimeService.o: TimeService.cpp

FakeTimeService.o: FakeTimeService.cpp
LightControllerSpy.o: LightControllerSpy.cpp

