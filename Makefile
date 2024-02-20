##########  VARS CONFIG
NAME			= printf.a
HEADER_FILE		= printf.h
CC				= gcc
FLAGS			= -Wall -Wextra -Werror
AR				= ar rcs

##########  PATHS
LIBFT_PATH		= ./libft
SRCS_PATH		= ./src
INCLUDE_PATH	= ./include


##########  LIBFT
LIBFT 			= $(LIBFT_PATH)/libft.a

##########  VARS FILES
SRC_FILES = numbers.c \
			ft_printf.c \
			tests.c
OBJECTS = $(SRC_FILES:.c=.o)

##########  RULES
all:  $(NAME) 

$(NAME): $(LIBFT)  $(INCLUDE_PATH)/$(HEADER_FILE) Makefile objs/$(OBJECTS) 
	@$(AR) $(NAME) objs/$(OBJECTS)
	@echo "🔅 Printf is ready to work!"

$(LIBFT):	
	@make bonus -C $(LIBFT_PATH) > /dev/null
	@echo "📚 Libft created!"
#bonus: $(OBJECTS) $(OBJECTS_BNS) $(HEADER_FILE) Makefile
#	@$(AR) $(NAME) $(OBJECTS) $(OBJECTS_BNS)
#	@echo "🔅 Library with bonus created!"
#	@touch bonus

objs/%.o: $(SRCS_PATH)/%.c
#	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@ -I  $(INCLUDE_PATH)
	@echo "🛠  $(@:.o=) object created!"

libftclean: 
	@make fclean -C $(LIBFT_PATH)

clean: libftclean
	@rm -f objs/$(OBJECTS)
	@echo "🧼 Removed object files from printf!"
	
fclean: clean
	@rm -f $(NAME)
	@echo "🛁 Removed $(NAME) file!"
	
re: fclean all
.PHONY: all clean fclean re