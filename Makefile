##
## Makefile for  in /home/god/TEK2/PSU_MEMOIRE/PSU_2016_malloc
## 
## Made by Pillon maxime
## Login   <god@epitech.net>
## 
## Started on  Wed Feb  8 16:04:13 2017 Pillon maxime
## Last update Wed Feb  8 16:04:21 2017 Pillon maxime
##

cc		=	gcc

LD		=	ld

FLAGS        	=    	-shared -o

RM		=	rm -rf

CFLAGS		+=    	-c -fPIC -DPIC -W -Wall -Werror -Wextra -I include

NAME        	=	libmy_malloc.so

SRCS        	=	malloc.c \
			free.c \
			realloc.c \
			show_mem_alloc.c \
			allocation_utils.c

OBJS        	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(LD) $(FLAGS) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re