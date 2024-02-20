# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 16:20:31 by ltrevin-          #+#    #+#              #
#    Updated: 2024/02/20 16:20:32 by ltrevin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########  VARS CONFIG
NAME			= printf.a
HEADER_FILE		= printf.h
CC				= gcc
FLAGS			= -Wall -Wextra -Werror
AR				= ar rcs

##########  PATHS
SRCS_PATH		= ./src
INCLUDE_PATH	= ./include

##########  VARS FILES
SRC_FILES = numbers.c \
			ft_printf.c \
			tests.c
OBJECTS = $(SRC_FILES:.c=.o)

##########  RULES
all:  $(NAME) 

$(NAME):   $(INCLUDE_PATH)/$(HEADER_FILE) Makefile objs/$(OBJECTS) 
	@$(AR) $(NAME) objs/$(OBJECTS)
	@echo "🔅 Printf is ready to work!"


objs/%.o: $(SRCS_PATH)/%.c
#	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@ -I  $(INCLUDE_PATH)
	@echo "🛠  $(@:.o=) object created!"



clean: 
	@rm -f objs/$(OBJECTS)
	@echo "🧼 Removed object files from printf!"
	
fclean: clean
	@rm -f $(NAME)
	@echo "🛁 Removed $(NAME) file!"
	
re: fclean all
.PHONY: all clean fclean re