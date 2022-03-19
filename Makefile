LIBFT_DIR	= ./libft

LIBFT		= ./libft/libft.a

NAME		= pipex

BNAME		= pipex_bonus

SRC			= main.c\
			  pipex.c\
			  put_error.c\
			  parse.c

BSRC		= main_bonus.c\
			  pipex.c\
			  put_error.c\
			  parse.c\
			  here_doc_bonus.c\
			  get_next_line_bonus.c\
			  get_next_line_utils_bonus.c

OBJ			= $(SRC:.c=.o)

BOBJ		= $(BSRC:.c=.o)

FLAGS		= -Wall -Wextra -Werror

RM			= rm -f

%.o:		%.c pipex.h Makefile
			gcc $(FLAGS) -c $< -o $(<:.c=.o) -I.

all:		$(NAME)

bonus:		$(BNAME)

.FORCE:

$(LIBFT):	.FORCE
			$(MAKE) -C $(LIBFT_DIR)

$(NAME):	$(OBJ) $(LIBFT)
			gcc $(FLAGS) -include pipex.h -o $(NAME) $(OBJ) $(LIBFT)
		
$(BNAME):	$(BOBJ) $(LIBFT)
			gcc $(FLAGS) -include pipex.h -o $(BNAME) $(BOBJ) $(LIBFT)

clean:
			$(MAKE) clean -C $(LIBFT_DIR)
			$(RM) $(OBJ) $(BOBJ)

fclean:		clean
			$(MAKE) fclean -C $(LIBFT_DIR)
			$(RM) $(NAME) $(BNAME)

re:			fclean all

.PHONY:		all clean fclean re .FORCE