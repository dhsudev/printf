##########  VARS CONFIG
NAME          = printf.a
HEADER_FILE   = printf.h
CC            = gcc
FLAGS         = -Wall -Wextra -Werror
AR            = ar rcs
##########  VARS FILES
SRC_FILES     = tests.c
OBJECTS       = $(SRC_FILES:.c=.o)
##########  RULES
all:  $(NAME) 
$(NAME): $(OBJECTS)  $(HEADER_FILE) Makefile
	@$(AR) $(NAME) $(OBJECTS)
	@echo "📚 Library created!"
	
#bonus: $(OBJECTS) $(OBJECTS_BNS) $(HEADER_FILE) Makefile
#	@$(AR) $(NAME) $(OBJECTS) $(OBJECTS_BNS)
#	@echo "🔅 Library with bonus created!"
#	@touch bonus

%.o: %.c 
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "🛠  $(@:.o=) object created!"

clean:
	@rm -f $(OBJECTS)
	@echo "🧼 Removed object files!"
	
fclean: clean
	@rm -f $(NAME)
	@echo "🧼 Removed $(NAME) file!"
	
re: fclean all
.PHONY: all clean fclean re