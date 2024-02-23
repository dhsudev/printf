# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 16:20:31 by ltrevin-          #+#    #+#              #
#    Updated: 2024/02/23 17:53:33 by ltrevin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########  VARS CONFIG
NAME			= libftprintf.a
HEADER_FILE		= ft_printf.h
CC				= gcc
FLAGS			= -Wall -Wextra -Werror
AR				= ar rcs

##########  PATHS
SRCS_PATH		= ./src
INCLUDE_PATH	= ./include

##########  VARS FILES
SRC_FILES = ft_printf.c ft_numbers.c
OBJECTS = $(SRC_FILES:.c=.o)

##########  RULES
all: $(NAME)

$(NAME): $(INCLUDE_PATH)/$(HEADER_FILE) $(addprefix objs/, $(OBJECTS)) Makefile
	@$(AR) $(NAME) $(addprefix objs/, $(OBJECTS))
	@echo "🔅 Printf is ready to work!"

objs/%.o: $(SRCS_PATH)/%.c
	@mkdir -p objs
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDE_PATH)
	@echo "🛠  $(@F) object created!"

.PHONY: all clean fclean re

clean:
	@rm -rf objs
	@echo "🧼 Removed object files from printf!"

fclean: clean
	@rm -f $(NAME)
	@echo "🛁 Removed $(NAME) file!"

re: fclean all