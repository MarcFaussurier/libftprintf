CSRC		:= $(shell ls ft_*.c sources/* convertors/* specifiers/*)
NAME		:= libftprintf.a
TEST		:= test
TEST_SRC	:= test.c
DEBUG		:= 1
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
	$(RM) $(NAME) $(TEST)
re:			fclean all
norme:
	norminette
%.o:	%.c	libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@
test:		$(NAME) $(CSRC)	$(TEST_SRC)	
	$(CC) $(TEST_SRC) $(NAME) -o $(TEST)
	./$(TEST)
rtest:
	./$(TEST)
valtest:
	valgrind --leak-check=full ./$(TEST)
$(NAME):	$(COBJ)
	/usr/bin/git submodule init
	/usr/bin/git submodule update
	@cd libft && make bonus
	$(AR) $(NAME) $(COBJ) $(shell ls libft/*.o)
	ranlib $(NAME)
.PHONY:
	all fclean clean re bonus
