r		=	"\033[0m"
n		=	$(NAME)"       "
cr		=	echo $(r)"\033[1;31m   - \033[0;31m"$(n)
cg		=	$(r)"\033[1;32m   + \033[0;32m"$(n)
cb		=	echo "\n"$(r)"\033[1;34m   > \033[0;34m"$(n)
cm		=	echo $(r)"\033[1;35m   > \033[0;35m"$(n)
sls		=	$(shell ls $(SRC_DIR)/*.c 2>/dev/null | tr ' ' '\n')
e_src	=	$(shell ls $(SRC_DIR)/*.c 2>/dev/null | wc -l | tr -d '\n')" sources"
e_obj	=	$(shell ls $(OBJ_DIR)/*.o 2>/dev/null | wc -l | tr -d '\n')" objects"
#-auto-sources-##############551203190822#
SRC = $(addsuffix .c, \
	main \
	)
#-auto-sources-##############551203190822#

SRC_DIR	=	src
SRC_PATH=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ_DIR	=	obj
OBJ		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEPS	=	$(OBJ:.o=.d))
# DEPS	=	$(OBJ:.o=.d)

NAME	=	prog

CC		=	gcc
CFLAGS 	=	-MMD -Wall -Wextra -Werror -g3
FCFLAGS =	-MMD -Wall -Wextra -Werror -g3 -fsanitize=address
INC		=	-I ./inc/
RM		=	rm -rf

PATH_LIB=	libft/
LIB 	=	libft.a
INC_LIB	=	libft
MAKELIB =	$(MAKE) $(MFG) -C $(PATH_LIB)
MFG 	=	--no-print-directory

LIBS	=	-lreadline

#########################################
all: 	$(NAME)

$(NAME):$(LIB) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INC) $(PATH_LIB)$(LIB) $(LIBS)
		echo -n $(cg) && du -bh $(NAME) | tr -d '$(NAME)' && echo -n $(r)

$(LIB):
		$(MAKELIB)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
#\

		@echo $(cg)"(@) "$@" (<) "$<

testf: $(LIB) $(OBJ)
	$(CC) $(FCFLAGS) $(OBJ) -o $(NAME) $(INC) $(PATH_LIB)$(LIB) $(LIBS)
	@echo $(r)
	@./$(NAME)

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

clean:
		$(MAKELIB) clean
		$(RM) $(OBJ_DIR)
		$(cr)$(e_obj)

fclean:
		$(MAKELIB) fclean
		$(RM) $(OBJ_DIR) $(NAME)
		$(cr)$(e_obj) && echo -n $(r)

re:		fclean
	make all

bonus: all

#########################################
a:
		$(cb)$(e_src) && ls $(SRC_PATH)

-include $(DEPS)

.PHONY: all clean fclean re bonus a

.SILENT: all clean fclean re bonus a $(NAME) $(LIB)
