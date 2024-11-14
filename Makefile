#############################################################
## ARGUMENTS

NAME			= libftprintf.a
CFLAGS			= -Wall -Wextra -Werror
CC				= gcc
INCLUDES		= -I includes/

#############################################################
## SOURCES

SRC_FILES		= ft_printf.c

OBJ_FILES		= $(SRC_FILES:.c=.o)

BONUS_FILES		=

BONUS_OBJ_FILES	= $(BONUS_FILES:.c=.o)

#############################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(OBJ_FILES) $(BONUS_OBJ_FILES)
	ar rcs $(NAME) $(BONUS_OBJ_FILES)

clean:
	rm -rf $(OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
