
CC = cc
CFLAGS    = -fsanitize=address -Wall -Werror -Wextra
INC = -I$(HOME)/.local/lib
MSRC := mandatory/srcs/main.c\
			 mandatory/srcs/julia.c\
			 mandatory/srcs/mandelbrot.c\
			 mandatory/srcs/utils.c\
			 mandatory/srcs/hooks.c\
			 mandatory/srcs/checks_mlxers.c
BSRC := bonus/srcs/main.c\
			 bonus/srcs/julia.c\
			 bonus/srcs/mandelbrot.c\
			 bonus/srcs/burningship.c\
			 bonus/srcs/utils.c\
			 bonus/srcs/check_mlxers.c\
			 bonus/srcs/hooks.c

NAME = fractol
BONUS = fractol_bonus
HEADER = mandatory/includes/fractol.h
HEADER_BONUS = bonus/includes/fractol.h

MLX = ~/.local/lib/libmlx.a

OBJ = $(MSRC:.c=.o)
BONUS_OBJ = $(BSRC:.c=.o)

all: $(NAME)
bonus: $(BONUS)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -lXext -lX11 -lm -lz -o $(NAME)

$(BONUS): $(BONUS_OBJ) $(MLX) 
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(MLX) -lXext -lX11 -lm -lz -o $(BONUS)

$(OBJ): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
    
$(BONUS_OBJ): %.o: %.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	# make clean -C minilibx-linux
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all
