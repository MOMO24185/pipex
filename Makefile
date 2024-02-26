SRCS = main.c\
		pipex.c\
		pipex_file_utils.c\
		ft_strcmp.c
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./
NAME = pipex.a
PROGRAM = pipex
CC = cc
OBJECTS = ${SRCS:.c=.o}

${NAME}: ${SRCS}
	echo "Compiling LIBFT archive"
	make -C ./libft fclean all clean
	mv ./libft/libft.a ${NAME}
	${CC} ${CFLAGS} ${SRCS} ${NAME} -I ${INCLUDES} -o ${PROGRAM}

all: ${NAME}

clean:
	echo "Cleaning all object files and archives"
	make -C ./libft clean
	rm -f ${OBJECTS} ${NAME}

fclean:	clean
	echo "Cleaning all objects, archives, and program files"
	make -C ./libft fclean
	rm -f ${PROGRAM}

re:	fclean all

.PHONY:	all clean fclean re
