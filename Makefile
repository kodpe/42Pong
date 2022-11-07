r		=	"\033[0m"
n		=	$(NAME)"       "
cr		=	echo $(r)"\033[1;31m   - \033[0;31m"$(n)
cg		=	$(r)"\033[1;32m   + \033[0;32m"$(n)
cb		=	echo "\n"$(r)"\033[1;34m   > \033[0;34m"$(n)
cm		=	echo $(r)"\033[1;35m   > \033[0;35m"$(n)
sls		=	$(shell ls $(SRC_DIR)/*.c 2>/dev/null | tr ' ' '\n')
e_src	=	$(shell ls $(SRC_DIR)/*.c 2>/dev/null | wc -l | tr -d '\n')" sources"
e_obj	=	$(shell ls $(OBJ_DIR)/*.o 2>/dev/null | wc -l | tr -d '\n')" objects"
grepr	=	$(shell grep -nH --color printf $(SRC_DIR)/*.c | grep -v "ft_printf")
grepgc	=	$(shell grep -nH --color getchar $(SRC_DIR)/*.c)
#-auto-sources-##############131553061122#
SRC = $(addsuffix .c, \
	pong_com \
	racket \
	waiting_room \
	smlx \
	game_room \
	main \
	dir \
	starting_room \
	ball \
	)
#-auto-sources-##############131553061122#

INC_DIR	=	inc
SRC_DIR	=	src
OBJ_DIR	=	obj
OBJ		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
SRC_PATH=	$(addprefix $(SRC_DIR)/, $(SRC))

PATH_MLX=	mlx_linux
MAKEMLX =	$(MAKE) $(MFG) -C $(PATH_MLX)

PATH_LIB=	libft/
LIB 	=	libft.a
INC_LIB	=	libft
MAKELIB =	$(MAKE) $(MFG) -C $(PATH_LIB)

NAME	=	miniRT

CC		=	@gcc
CFLAGS 	=	-Wall -Wextra -Werror -I $(INC_DIR) -I $(INC_LIB)
# CFLAGS 	=	-Wall -Wextra -Werror -g3 -fsanitize=address -I $(INC_DIR) 

MLX		=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MKDIR	=	@mkdir -p
RM		=	rm -rf
MFG 	=	--no-print-directory

#########################################

all: 	$(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
		$(MKDIR) $(dir $@)
# $(CC) $(CFLAGS) -c $< -o $@
		$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
#\
		
		@echo $(cg)"(@) "$@" (<) "$<

mlx:
		$(MAKEMLX)

$(LIB):
		$(MAKELIB)

$(NAME):$(LIB) mlx $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(SRC_PATH) $(PATH_LIB)$(LIB) $(MLX)
		echo -n $(cg) && du -bh $(NAME) | tr -d '$(NAME)' && echo -n $(r)

clean:
		$(MAKELIB) clean
		$(RM) $(OBJ_DIR)
		$(cr)$(e_obj)

fclean: clean_mlx
		$(MAKELIB) fclean
		$(RM) $(OBJ_DIR) $(NAME)
		$(cr)$(e_obj) && echo -n $(r)

clean_mlx:
		$(MAKEMLX) clean

re:		fclean all

val:
		valgrind \
		--show-leak-kinds=all \
		--track-origins=yes \
		--leak-check=full \
		./$(NAME)
#--suppressions=suppr.valgrind \
#--trace-children=yes \
#--track-fds=yes \

testvre:	re
	make val

testv: all
	make val

#########################################
a:
		$(MAKELIB) a
		$(cb)$(e_src) && ls $(SRC_PATH)
		$(cm)"diff check *"
		echo $(sls) | tr ' ' '\n' | sort > o_sls.out
		echo $(SRC_PATH) | tr ' ' '\n' | sort > o_src.out
		-diff -y --color --suppress-common-lines o_sls.out o_src.out && rm *.out
		$(cm)"printf check * $(grepr)"
		$(cm)"getchar check * $(grepgc)"

true:
		$(MAKE) $(MFG) true -C $(PATH_LIB)
		$(cm)"scan nm" && nm $(NAME) | grep "ft"

.PHONY:	all clean fclean re a true mlx clean_mlx

.SILENT: all clean fclean clean_mlx re a true $(NAME) $(LIB)
