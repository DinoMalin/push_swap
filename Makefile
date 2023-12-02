NAME = push_swap
NAME_BONUS = checker

LIBFT = lib/libft.a

CC = cc

CFLAGS =	-Wall -Wextra -Werror -g \
			-Iinclude

LFLAGS =	-Llib \
			-lft

FILES = main basic_instructions sort init_nodes move_nodes utils verifications
FILES_BONUS = main_checker utils_checker

OBJ_DIR = obj/
SRC_DIR = src/
BONUS_DIR = bonus/
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))
SRCS_BONUS = $(addprefix $(BONUS_DIR), $(addsuffix .c, $(FILES_BONUS)))
OBJS_BONUS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_BONUS))) $(filter-out $(OBJ_DIR)main.o, $(OBJS))

all: $(NAME)

bonus: $(NAME_BONUS)

clean :
	rm -rf $(OBJ_DIR)
	make fclean -C lib

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	make fclean -C lib

re: fclean all

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) -o $@ $(OBJS) $(LFLAGS)

$(NAME_BONUS): $(OBJ_DIR) $(OBJS_BONUS) $(LIBFT)
	$(CC) -o $@ $(OBJS_BONUS) $(LFLAGS)

$(LIBFT):
	make -C lib

$(OBJ_DIR):
	mkdir $@

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: bonus/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus