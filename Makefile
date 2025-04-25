# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/30 16:06:32 by jozefpluta        #+#    #+#              #
#    Updated: 2025/04/25 17:05:15 by jpluta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline
SRC = \
minishell.c \
libft/ft_split/ft_split.c \
enviromentals.c built_ins.c \
edge_cases.c \
create_command_list.c \
t_data_utils.c \
execution.c \
cmd_ls_utils.c \
echo_utils.c \
cd_utils.c \

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

EXEC = minishell

# Default target
all: $(LIBFT) $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(EXEC)

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean up generated files
clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

# Remove everything (clean + remove executable)
fclean: clean
	rm -f $(EXEC)
	make -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all