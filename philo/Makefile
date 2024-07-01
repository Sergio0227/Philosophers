# Define variables
SRC = main.c
OBJS = ${SRC:.c=.o}
NAME = philo
CC = cc
CFLAGS = -Werror -Wextra -Wall
LIBFT_PATH = ./libft
RM = rm -f

# Define colors
DEF_COLOR = \033[0;39m
ORANGE = \033[0;33m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: libft ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME} -L${LIBFT_PATH} -lft
	@echo "$(ORANGE)[Philosophers]:$(DEF_COLOR) exec file $(GREEN) \t=> Created!$(DEF_COLOR)";

libft: 
	@if [ ! -d "$(LIBFT_PATH)" ]; then \
		echo "downloading libft..."; \
		git clone git@github.com:Sergio0227/Libft.git $(LIBFT_PATH) > /dev/null 2>&1; \
	fi
	@${MAKE} -C ${LIBFT_PATH} > /dev/null 2>&1
	@echo "LIBFT MADE";

.c.o: 
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}


run: all
	@./philo;


clean:
	@${MAKE} -C ${LIBFT_PATH} clean > /dev/null 2>&1
	@${RM} ${OBJS}
	@echo -n "$(CYAN)[LIBFT]:$(DEF_COLOR) object files$(RED) \t => Removed!$(DEF_COLOR)\n"

fclean: clean
	@if [ -f "${NAME}" ]; then \
		echo -n "$(CYAN)[Philosophers]:$(DEF_COLOR) exec. files$(RED)  => Removed!$(DEF_COLOR)\n"; \
		${RM} ${NAME}; \
	fi
	@${RM} -rf ${LIBFT_PATH}
	@echo -n "$(CYAN)[LIBFT]:$(DEF_COLOR)    folder$(RED)    \t => Removed!$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re run
