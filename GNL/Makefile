NAME	= get_next_line.a
SRCS	= test_GNL.c get_next_line.c get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}
HEADER	= get_next_line.h

CC	= gcc
RM	= rm -f

$(NAME):	${OBJS}
			ar -rcs ${NAME} ${OBJS}

%.o: %.c
		${CC} -c $@ $< -I ${HEADER}

all:		${NAME}

clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:	${NAME} all clean fclean re
