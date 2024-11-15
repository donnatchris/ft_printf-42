#############################################################
## ARGUMENTS

NAME			= libftprintf.a
CFLAGS			= -Wall -Wextra -Werror
CC				= gcc
INCLUDES		= -I includes/

#############################################################
## SOURCES

SRC_FILES		= ft_printf.c ft_putchar_pf.c ft_putstr_pf.c ft_putint_pf.c ft_putuint_pf.c ft_puthexamin_pf.c ft_puthexamaj_pf.c ft_check_address_pf.c 

OBJ_FILES		= $(SRC_FILES:.c=.o)

##BONUS_FILES		=

##BONUS_OBJ_FILES	= $(BONUS_FILES:.c=.o)

#############################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

##bonus: $(OBJ_FILES) $(BONUS_OBJ_FILES)
##	ar rcs $(NAME) $(BONUS_OBJ_FILES)

clean:
	rm -rf $(OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
