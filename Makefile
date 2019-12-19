CSRC		:= $(shell ls ./utils/*.c ./sources/*.c ./wrappers/*.c)
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
	$(RM) $(NAME) *.out tags *.dSYM
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
school:
	nvim -S school_workspace.vim
home:
	nvim -S home_workspace.vim
.PHONY:
		all fclean clean re bonus test
