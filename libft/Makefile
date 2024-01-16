SRCS = ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memchr.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memcmp.c\
		ft_memset.c\
		ft_split.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_calloc.c\
		ft_itoa.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_tolower.c\
		ft_toupper.c\
		get_next_line_utils.c\
		get_next_line.c
BONUSES = ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c
CFLAGS = -Wall -Wextra -Werror -c
INCLUDES = ./
NAME = libft.a
CC = cc
OBJECTS = ${SRCS:.c=.o}
BONUS_OBJECTS = ${BONUSES:.c=.o}
AR = ar
ARFLAGS = -rcs

${NAME}: ${SRCS}
	echo "${CC} ${CFLAGS} ${SRCS} -I ${INCLUDES}"
	${CC} ${CFLAGS} ${SRCS} -I ${INCLUDES}
	echo "${AR} ${ARFLAGS} ${NAME} ${OBJECTS}"
	${AR} ${ARFLAGS} ${NAME} ${OBJECTS}

all: ${NAME}

bonus: ${BONUSES}
	echo "${CC} ${CFLAGS} ${BONUSES} -I ${INCLUDES}"
	${CC} ${CFLAGS} ${BONUSES} -I ${INCLUDES}
	echo "${AR} ${ARFLAGS} ${NAME} ${BONUS_OBJECTS}"
	${AR} ${ARFLAGS} ${NAME} ${BONUS_OBJECTS}

clean:
	echo "rm -f ${OBJECTS} ${BONUS_OBJECTS}"
	rm -f ${OBJECTS} ${BONUS_OBJECTS}

fclean:	clean
	echo "rm -f ${NAME}"
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
