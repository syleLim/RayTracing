TARGET = RAYTRACER
CC = gcc
FLAG = -Wall -Werror -Wextra
OBJS = main.c SRC/*/*/*.c SRC/*/*.c SRC/*.c \
		VECTOR/*.c PARSER/*/*.c PARSER/*.c \
		EXPORT/*.c ERROR/*.c
HEADER = -I HEADER
LIB = -lm
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

$(TARGET) : $(OBJS)
	$(CC) $(FLAG) -o $(TARGET) $(OBJS) $(HEADER) $(LIB) $(MLX)

all : $(TARGET)

clean :
	echo "no obj file"
fclean : clean
	rm -f $(TARGET)

re : fclean all

