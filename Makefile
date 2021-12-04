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

MAIN_DIR	=	main/
MAIN_FILES	=	main.c \
				#xxxx.c
MAIN_SRCS	 =	$(addprefix $(MAIN_DIR), $(MAIN_FILES))

INPUT_DIR	=	input/
INPUT_FILES	=	input.c \
				parser.c \
				lexer.c \
				separate.c \
				#xxxx.c
INPUT_SRCS =	$(addprefix $(INPUT_DIR), $(INPUT_FILES))

ERROR_DIR 	=	error/
ERROR_FILES	=	free.c \
				#xxxx.c
ERROR_SRCS	=	$(addprefix $(ERROR_DIR), $(ERROR_FILES))

ECHO_DIR	=	echo/
ECHO_FILES	=	main.c \
				#xxxx.c
ECHO_SRCS	=	$(addprefix $(ECHO_DIR), $(ECHO_FILES))

PWD_DIR		=	pwd/
PWD_FILES	=	main.c \
				#xxxx.c
PWD_SRCS	=	$(addprefix $(PWD_DIR), $(PWD_FILES))

EXIT_DIR	=	exit/
EXIT_FILES	=	main.c \
				#xxxx.c
EXIT_SRCS	=	$(addprefix $(EXIT_DIR), $(EXIT_FILES))

SRC_FILES =			$(MAIN_SRCS) \
					$(INPUT_SRCS) \
					$(ERROR_SRCS) \
					$(ECHO_SRCS) \
					$(PWD_SRCS) \
					$(EXIT_SRCS) \

# addprefix

SRC_DIR = srcs/

OBJ_DIR = objs/
OBJS = $(SRC_FILES:%.c=$(OBJ_DIR)%.o)
MAIN_OBJS = $(MAIN_FILES:%.c=$(OBJ_DIR)main/%.o)
INPUT_OBJS = $(INPUT_FILES:%.c=$(OBJ_DIR)input/%.o)
ERROR_OBJS = $(ERROR_FILES:%.c=$(OBJ_DIR)error/%.o)

ECHO_OBJS = $(ECHO_FILES:%.c=$(OBJ_DIR)echo/%.o)
PWD_OBJS = $(PWD_FILES:%.c=$(OBJ_DIR)pwd/%.o)
EXIT_OBJS = $(EXIT_FILES:%.c=$(OBJ_DIR)exit/%.o)

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
	mkdir -p $(OBJ_DIR)$(INPUT_DIR)
	mkdir -p $(OBJ_DIR)$(ERROR_DIR)
	mkdir -p $(OBJ_DIR)$(ECHO_DIR)
	mkdir -p $(OBJ_DIR)$(PWD_DIR)
	mkdir -p $(OBJ_DIR)$(EXIT_DIR)

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
