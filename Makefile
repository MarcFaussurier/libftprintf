CSRC		:= $(shell ls ./wrapper/*.c ./source/*.c ./toa/*.c ./util/*.c)
NAME		:= libftprintf.a
DEBUG		:= 0
RM			:= rm -rf
AR			:= ar rcs
CC			:= gcc
CFLAGS		:= -Werror -Wextra -Wall -Wparentheses
COBJ		:= $(CSRC:.c=.o)
BONUSOBJ	:= $(BONUSSRC:.c=.o)
DEBUGFLAGS	:= -g #-fsanitize=address -fno-omit-frame-pointer
INC			:= ./
CFLAGS		:= $(CFLAGS) -I$(INC)
ifeq ($(DEBUG),1)
CFLAGS		+= $(DEBUGFLAGS)
endif

all:		$(NAME)
clean:
	$(RM) $(COBJ) $(BONUSOBJ)
fclean:		clean
	$(RM) $(NAME) test.out
re:			fclean all
norme:
	norminette
%.o:		%.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@
test:		$(NAME)
	gcc -g test.c libftprintf.a libft.a -o test.out && valgrind ./test.out
$(NAME):	$(COBJ)
	make -C libft
	mv libft/libft.a .
	$(AR) $(NAME) $(COBJ) libft.a
.PHONY:
		all fclean clean re bonus test
