NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I includes/
AR = ar
ARFLAGS = rc

LIBFT_DIR = libft/
LIBFT_SRC = \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_SRC))

GNL_DIR = get_next_line/
GNL_SRC = \
	get_next_line.c \
	get_next_line_utils.c
GNL = $(addprefix $(GNL_DIR), $(GNL_SRC))

MYLIB_DIR =	mylib/
MYLIB_SRC =	\
	ft_strcmp.c \
	ft_swap.c \
	ft_heapsort.c \
	ft_strndup.c \
	ft_strcount.c
MYLIB = $(addprefix $(MYLIB_DIR), $(MYLIB_SRC))

SRC_DIR = srcs/
SRCS =	$(LIBFT) \
		$(GNL) \
		$(MYLIB)

OBJ_DIR = objs/
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJS): $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(LIBFT_DIR)
	mkdir -p $(OBJ_DIR)$(GNL_DIR)
	mkdir -p $(OBJ_DIR)$(MYLIB_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean:
	rm -rf $(NAME) $(OBJ_DIR)

re: fclean $(NAME)

.PHONY	: all clean fclean re
