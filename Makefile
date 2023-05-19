CC=gcc
CFLAGS=-Wall -Wextra -Werror -g
FLAGS=-lreadline -L/usr/include -lreadline -L$$HOME/.brew/opt/readline/lib -I $$HOME/.brew/opt/readline/include/readline

NAME=minishell

SRC_DIR=libft
SRC=$(SRC_DIR)/ft_putchar_fd.c \
	$(SRC_DIR)/ft_putendl_fd.c \
	$(SRC_DIR)/ft_putstr_fd.c \
	$(SRC_DIR)/ft_split.c \
	$(SRC_DIR)/ft_strcmp.c \
	$(SRC_DIR)/ft_strdup.c \
	$(SRC_DIR)/ft_strlen.c \
	$(SRC_DIR)/ft_substr.c \
	$(SRC_DIR)/ft_strstr.c \
	$(SRC_DIR)/ft_strchr.c \
	$(SRC_DIR)/ft_strncmp.c \
	$(SRC_DIR)/ft_strcpy.c \
	$(SRC_DIR)/ft_strcat.c \
	$(SRC_DIR)/ft_memcpy.c	\
	$(SRC_DIR)/ft_atoi.c   \
	$(SRC_DIR)/ft_strjoin.c	\
	$(SRC_DIR)/ft_strtrim.c \
	$(SRC_DIR)/ft_calloc.c \
	$(SRC_DIR)/ft_itoa.c \
	$(SRC_DIR)/ft_bzero.c \
	$(SRC_DIR)/ft_strlcpy.c \
	builtins/ft_cd.c \
	builtins/ft_echo.c \
	builtins/ft_pwd.c \
	builtins/ft_unset.c \
	builtins/ft_export.c \
	builtins/ft_export2.c \
	builtins/ft_export3.c \
	builtins/ft_execve.c \
	builtins/ft_exit.c \
	builtins/ft_env.c \
	smart_split.c \
	mytrimmer.c \
	expander.c \
	display.c \
	redirection.c \
	redirection2.c \
	spacing.c \
	heredoc.c \
	heredoc2.c \
	display_prompt.c \
	display_prompt2.c \
	utils.c \
	yes_pipe.c \
	no_pipe.c \
	mytrimmer2.c \
	main.c \
	main2.c \
	main3.c \
	signal.c \

OBJ_DIR=obj
OBJ=$(SRC:%.c=$(OBJ_DIR)/%.o)

INCLUDE=libft/libft.h minishell.h

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@ $(FLAGS)

$(OBJ_DIR)/%.o: %.c $(INCLUDE)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
