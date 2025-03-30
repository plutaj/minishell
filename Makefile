# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jozefpluta <jozefpluta@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/30 16:06:32 by jozefpluta        #+#    #+#              #
#    Updated: 2025/03/30 16:22:24 by jozefpluta       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline
SRC = main.c utils.c commands_1.c
OBJ = $(SRC:.c=.o)
EXEC = minishell

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXEC)

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJ) $(EXEC)

# Remove everything (clean + remove executable)
fclean: clean
	rm -f $(EXEC)

# Rebuild everything
re: fclean all