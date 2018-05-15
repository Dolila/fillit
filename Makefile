NAME= fillit

CC= gcc
CFLAGS= -Wall -Werror -Wextra

SRC= 2fillit.c  fillit.c  fillit.h  lexicorder_tab.c
SRCPATH= libfillit/
SRCFIN= $(addprefix $(SRCPATH), $(SRC))

LIBFT= libft.a
LIBFTPATH= Libft/
LIBFTFIN= $(addprefix $(LIBFTPATH), $(LIBFT))

DEL= rm -rf

all : $(NAME)

$(NAME):
	$(CC) $(FLAG) $(LIBFTFIN) $(SRCFIN) -o $(NAME)
	echo "make -> $(NAME) created"

clean:
	$(DEL) fillit.h.gch libft.h.gch

fclean: clean
	$(DEL) $(NAME)

re: fclean all

