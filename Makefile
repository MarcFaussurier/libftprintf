CSRC		:= ft_itob.c ft_register_defaults.c ft_vasprintf.c ft_asprintf.c ft_register_fmt_id.c
NAME		:= libftprintf.a
DEBUG		:= 0
RM			:= rm -rf
AR			:= ar rcs
CC			:= gcc
CFLAGS		:= -Werror -Wextra -Wall -Wparentheses -g
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
	cd libft && make bonus && mv libft.a ..
	$(AR) $(NAME) $(COBJ) libft.a
school:
	nvim -S school_workspace.vim
home:
	nvim -S home_workspace.vim
.PHONY:
		all fclean clean re bonus test
