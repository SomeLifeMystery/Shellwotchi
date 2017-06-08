CC=	gcc

RM=	rm -f

CFLAGS+=-I./ansiGraphic
CFLAGS+=-I./inc

LDFLAGS=

NAME=	Shellwotchi

SRCS=	ansiGraphic/ansiGraphic2.c\
	src/dhms_clock.c\
	src/display.c\
	src/events.c\
	src/game_data.c\
	src/process.c\
	src/raw_data.c\
	src/shellwotchi.c\
	src/state_manager.c\

OBJS=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
