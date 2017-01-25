INC_DIR		= include/

CC		= gcc
CFLAGS		+= -I $(INC_DIR)
CFLAGS		+= -Wall -Wextra -Werror -Wno-deprecated
CFLAGS		+= -fPIC

RM		= rm -f

NAME		= libmy_malloc.so

SRCS_DIR	= src/
SRCS_FILES	= malloc.c				\
		  find_chunk.c				\
		  my_memcpy.c				\
		  tools.c				\
		  my_strlen.c				\
		  my_char_isprintable.c			\
		  my_printf/compare_char.c		\
		  my_printf/my_printf.c			\
		  my_printf/find_flag.c			\
		  my_printf/flag_char.c			\
		  my_printf/flag_int.c			\
		  my_printf/flag_ptr.c			\
		  my_printf/flag_str.c			\
		  my_printf/flag_uint.c			\
		  my_printf/init.c			\
		  my_printf/my_putchar.c		\
		  my_printf/my_putnbr_base.c		\
		  my_printf/my_put_nbr.c		\
		  my_printf/my_putstr.c			\
		  my_printf/my_showstr.c
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS		= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -fPIC -shared -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
