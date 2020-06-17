TARGET = RAYTRACER
CC = gcc
FLAG = -Wall -Werror -Wextra
OBJS = main.c SRC/*/*.c VECTOR/*.c
HEADER = -I HEADER
LIB = -lm

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(HEADER) $(LIB)

all : $(TARGET)
