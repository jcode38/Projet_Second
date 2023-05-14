CC			=	gcc
CFLAGS		=	-W	-Wall	-Wextra
CPPFLAGS	=	-I/usr/include -I include
LDFLAGS		=   -L/usr/lib/x86_64-linux-gnu -lcsfml-window -lcsfml-graphics -lm

#SRC			=	$(wildcard src/*.c)
SRC			=	$(shell find . -type f -name "*.c")
OBJ			=	$(SRC:.c=.o)

TARGET		=	project_second

all			:	$(TARGET)

$(TARGET)	:	$(OBJ)
			$(CC) -o $@ $^ $(LDFLAGS)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(TARGET)

re			:	fclean all