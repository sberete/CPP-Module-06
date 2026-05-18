CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98 -g3 -MMD
OBJ_DIR = objs

SRCS = $(shell find . -name '*.cpp')
OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRCS))

DEPENDS = $(OBJS:.o=.d)

NAME = identify
-include $(DEPENDS)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all