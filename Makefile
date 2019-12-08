CSRC			:=./ft_strnstr.c\
./ft_isdigit.c\
./ft_strlcpy.c\
./ft_strlen.c\
./ft_strnlen.c\
./ft_strchr.c\
./ft_strjoin.c\
./ft_isascii.c\
./ft_isprint.c\
./ft_toupper.c\
./ft_split.c\
./ft_strrchr.c\
./ft_isalpha.c\
./ft_substr.c\
./ft_strncmp.c\
./ft_strcpy.c\
./ft_strmapi.c\
./ft_strtrim.c\
./ft_islower.c\
./ft_isupper.c\
./ft_strlcat.c\
./ft_strtrim_end.c\
./ft_count_occ.c\
./ft_strdup.c\
./ft_atoi.c\
./ft_strtrim_begin.c\
./ft_isalnum.c\
./ft_itoa.c\
./ft_isspace.c\
./ft_tolower.c\
./ft_is_char_in.c\
./ft_putstr_fd.c\
./ft_putnbr.c\
./ft_putnbr_fd.c\
./ft_putendl.c\
./ft_putendl_fd.c\
./ft_putchar.c\
./ft_read.c\
./ft_putchar_fd.c\
./ft_read_fd.c\
./ft_putstr.c\
./ft_memcmp.c\
./ft_bzero.c\
./ft_memcpy.c\
./ft_memccpy.c\
./ft_realloc.c\
./ft_free_until.c\
./ft_memchr.c\
./ft_memset.c\
./ft_memmove.c\
./ft_calloc.c\
./ft_numlen.c\
./ft_bytes_digits.c
BONUSSRC		:=./ft_lstadd_back_bonus.c\
./ft_lstnew_bonus.c\
./ft_lstlast_bonus.c\
./ft_lstclear_bonus.c\
./ft_lstiter_bonus.c\
./ft_lstmap_bonus.c\
./ft_lstsize_bonus.c\
./ft_lstadd_front_bonus.c\
./ft_lstdelone_bonus.c
NAME		:= libft.a
DEBUG		:= 0
RM			:= rm -rf
AR			:= ar rcs
CC			:= gcc
CFLAGS		:= -Werror -Wextra -Wall -Wparentheses
COBJ		:= $(CSRC:.c=.o)
BONUSOBJ	:= $(BONUSSRC:.c=.o)
DEBUGFLAGS	:= -g -fsanitize=address -fno-omit-frame-pointer
INC			:= ./
CFLAGS		:= $(CFLAGS) -I$(INC)
ifeq ($(DEBUG),1)
CFLAGS		+= $(DEBUGFLAGS)
endif

all:		$(NAME)
clean:
	$(RM) $(COBJ) $(BONUSOBJ)
fclean:		clean
	$(RM) $(NAME)
re:		fclean all
norme:
	norminette
bonus:		$(COBJ) $(BONUSOBJ)
	$(AR) $(NAME) $(COBJ) $(BONUSOBJ)
%.o:	%.c		libft.h
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME):	$(COBJ)
	$(AR) $(NAME) $(COBJ)
.PHONY:
		all fclean clean re bonus
