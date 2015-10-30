#x This makefile reuses the minimal one, but runs it in a sibling directory
include ../minimal/Makefile

CFLAGS += -I../HomeAutomation
vpath %.c ../HomeAutomation
vpath %.cpp ../HomeAutomation
OBJS += LightScheduler.o LightController.o TimeService.o # TODO: ADD Production OBJ

firmware.elf: main.o gcc_startup_lpc8xx.o $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $^

LightScheduler.o: LightScheduler.cpp
LightController.o: LightController.cpp
TimeService.o: TimeService.cpp
