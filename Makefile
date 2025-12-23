NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g $(SYSTEM)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLXFLAGS =  -Lmlx_Linux -lmlx_Linux -L ./mlx -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz
endif
ifeq ($(UNAME_S), Darwin)
	MLXFLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
endif

AR			=	ar rcs
RM			=	rm -f
MD			=	mkdir -p
CP			=	cp -f

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	inc/

LIBFT		=	libft/libft.a

INCLUDE		+= -I $(INC_DIR)

SL_SRCS	=		error_messages.c free_memory.c game_finished.c \
				generate_map.c hook.c main.c movement.c print.c \
				validate_input.c validate_path.c file_to_image.c

SRCS			+=	$(addprefix $(SRC_DIR), $(SL_SRCS))

OBJS			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

DEPS			+=	$(addsuffix .d, $(basename $(OBJS)))

$(OBJ_DIR)%.o : %.c Makefile
	@$(MD) $(dir $@)
	@make -sC mlx
	@make -sC libft
	@echo "$(WARN_COLOR)Compiling: $<$(NO_COLOR)"
	@$(CC) -MT $@ -MMD -MP -c $(CFLAGS) $(INCLUDE) -Imlx   $< -o $@ 

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS)  $(LIBFT) $(OBJS) -o $(NAME) $(MLXFLAGS)
			@echo "$(OK_COLOR)Compiled!$(NO_COLOR)"

clean:
			@make clean -sC mlx
			@make clean -sC libft
			@$(RM) -r $(OBJ_DIR)
			@$(RM) get_next_line/get_next_line.o
			@echo "$(ERROR_COLOR)Dependencies and objects removed$(NO_COLOR)"

fclean:		clean
			@make fclean -sC libft
			@$(RM) $(NAME)
			@echo "$(ERROR_COLOR)Programs removed$(NO_COLOR)"

re:			fclean all


-include $(DEPS)
.PHONY: all bonus clean fclean re