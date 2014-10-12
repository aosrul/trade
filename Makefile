CC		=	gcc
NAME		=	trade
SRC		=	main.c		\
			misc.c		\
			get_math.c	\
			algo.c		\
			normsinv.c	\
			montecarlo.c	\
			actions.c

LIB		=	-lm
OBJ		=	$(SRC:.c=.o)
CFLAGS		=	-W -Werror -ansi -pedantic -Wstrict-prototypes


all		:	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)


clean		:	
			rm -rf $(OBJ)

fclean		:	clean
			rm -rf $(NAME)
			rm -rf *~
			rm -rf log.*

re		:	fclean all