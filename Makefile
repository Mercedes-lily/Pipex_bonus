NAME = push_swap
LIBFT = libft/libft.a
DEP = inc/push_swap.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

MK = mkdir -p					
RM = rm -rf

#Sources directories
INCDIR = inc
SRCDIR = src
LIBFTDIR = libft

SRC = 3_algorithm.c \
		5_algorithm.c \
		change_base.c \
		big_algorithm.c \
		big_sort.c \
		list.c \
		long_atoi.c \
		push_swap.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		to_the_left.c \
		to_the_right.c \
		verification.c 
		
VPATH = $(SRCDIR)

#Object directories
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/,$(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
$(OBJDIR)/%.o : %.c $(DEP)
	$(CC) $(CFLAGS) -I$(INCDIR) -Ilibft/inc -c $< -o $@

$(OBJDIR):
	$(MK) $(OBJDIR)

clean:
	$(RM) $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all