NAME = minitalk
BONUS = minitalk_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
FLAGS = -Wall -Wextra -Werror -g3

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

LIBS = -L./libft -l:libft.a

SERVER_SRC_FILES = server.c
CLIENT_SRC_FILES = client.c

OBJ_FILES = $(SERVER_SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)  
	$(CC) $(FLAGS) server.c -o server $(LIBS)
	$(CC) $(FLAGS) client.c -o client $(LIBS)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f *.o
	$(MAKE) -C libft clean

fclean: clean
	rm -f server
	rm -f client
	$(MAKE) -C libft fclean

re: fclean $(NAME)

$(BONUS): $(LIBFT) $(BONUS_OBJ_FILES)
	$(CC) $(FLAGS) $(BONUS_OBJ_FILES) $(LIBS) -o $(BONUS) 

bonus: $(BONUS)
