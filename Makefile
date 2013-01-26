NAME		=	base

CXXFLAGS	=	-I include/ -Wextra -Wall -fpermissive

LDFLAGS		=	-lm

CC		=	g++
RM		=	rm -fv

SRC		=	src/main.cpp		\
			src/Serveur.cpp		\
			src/Client.cpp

OBJ		=	$(SRC:.cpp=.o)

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CXXFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
