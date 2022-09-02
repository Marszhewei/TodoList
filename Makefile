#makefile for build todolist app

CC := gcc
RM := rm -f

TARGET = app.out
OBJS = plans.o frame.o operate.o ui.o

all : ${TARGET}

${TARGET} : ${OBJS}
	$(CC) $^ -o $@

plans.o : plans.c
	$(CC) -c $^ -o $@

frame.o : src/frame.c
	$(CC) -c $^ -o $@

operate.o : src/operate.c
	$(CC) -c $^ -o $@

ui.o : src/ui.c
	$(CC) -c $^ -o $@


.PHONY : clean

clean:
	$(RM) ${TARGET} ${OBJS}