#makefile for build todolist app

vpath %.h include
vpath %.c src

CC := gcc
RM := rm -f

TARGET := app.out
OBJS := $(patsubst %.c,%.o,$(wildcard *.c))
OBJS += $(patsubst %.c,%.o,$(wildcard src/*.c))

.PHONY : all

all : ${TARGET}

${TARGET} : ${OBJS}
	$(CC) $^ -o $@
	@echo "build finished"

${OBJS} : include/data.h

frame.o : include/operate.h include/ui.h

.PHONY : clean

clean:
	$(RM) ${TARGET} ${OBJS}