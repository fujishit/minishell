NAME = minishell
LIB_DIR = mylibft/
LIBFT = libft.a

# Config
# ****************************************************************************

CC = gcc
CFLAGS = $(INCLUDE) #-Wall -Werror -Wextra
INCLUDE = -I includes/ -I $(LIB_DIR)includes/
DEBUG = -g -fsanitize=address
LIBFLAGS = -L $(LIB_DIR) -lft
# Source files
# ****************************************************************************

MAIN_DIR =		main/
MAIN_FILES	=	main.c \
					#xxxx.c
MAIN_SRCS = $(addprefix $(MAIN_DIR), $(MAIN_FILES))

# XXXX_DIR =		XXXX/
# XXXX_FILES =	xxxx.c \
# 				xxxx.c
# XXXX_SRCS = $(addprefix $(XXXX_DIR), $(XXXX_FILES))

# XXXX_DIR =		XXXX/
# XXXX_FILES =	xxxx.c \
# 				xxxx.c
# XXXX_SRCS = $(addprefix $(XXXX_DIR), $(XXXX_FILES))

SRC_FILES =			$(MAIN_SRCS) \
					#$(XXXX_SRCS) \

# addprefix

SRC_DIR = srcs/

OBJ_DIR = objs/
OBJS = $(SRC_FILES:%.c=$(OBJ_DIR)%.o)
MAIN_OBJS = $(MAIN_FILES:%.c=$(OBJ_DIR)main/%.o)
# XXXX_OBJS = $(XXXX_FILES:%.c=$(OBJ_DIR)xxxx/%.o)
# XXXX_OBJS = $(XXXX_FILES:%.c=$(OBJ_DIR)xxxx/%.o)

# Recipe
# ****************************************************************************

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

$(OBJS): $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(MAIN_DIR)
#	mkdir -p $(OBJ_DIR)$(XXXX_DIR)
#	mkdir -p $(OBJ_DIR)$(XXXX_DIR)

debug: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(DEBUG) $(LIBFLAGS) $(OBJS) -o $(NAME)

clean:
	make clean -C $(LIB_DIR)
	rm -rf $(OBJ_DIR)
	rm -fr *.dSYM

fclean:
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME) $(OBJ_DIR)
	rm -fr *.dSYM

re: fclean all
.PHONY: all clean fclean re
