# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/04 00:28:28 by gunkim            #+#    #+#              #
#    Updated: 2021/06/23 20:22:09 by gunkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	push_swap - Makefile
#	----------------------------------------
#	Refer to : https://github.com/google/honggfuzz/blob/master/Makefile
#	Refer to : https://github.com/JaeSeoKim/42cursus/blob/master/01_ft_printf/Makefile

# =========================
# what we want to make
# =========================

PUSH_SWAP   := push_swap
CHECKER     := checker
SIMULATOR   := simulator
NAME        := $(PUSH_SWAP)

# =========================
# library path
# =========================

DIR_LIBFT   := lib/libft

LIB_LIBFT   := libft.a

NAME_LIBFT  := $(DIR_LIBFT)/$(LIB_LIBFT)

# =========================
# implicit rule
# =========================

CC        := gcc
# CFLAGS    := -g
CFLAGS    := -g3 -fsanitize=address
CFLAGS    += -Wall
CFLAGS    += -Wextra
CFLAGS    += -Werror

INCLUDES  := -I $(DIR_LIBFT)/include \
			 -I include
LIBFLAGS  := -L $(DIR_LIBFT) -lft

RM        := rm
RFLAGS    := -rf

# =========================
# path
# =========================

DIR_INC := include
DIR_OBJ := obj
DIR_SRC := src

# =========================
# source files
# =========================

DIR_SRC_COMMAND := command
SRCS_COMMAND := $(addprefix $(DIR_SRC_COMMAND)/, \
	ft_cmd_p.c \
	ft_cmd_rr.c \
	ft_cmd_r.c \
	ft_cmd_s_1.c \
	ft_cmd_s_2.c \
	ft_jump_command_undo.c \
	ft_jump_command.c \
)

DIR_SRC_ERROR := error
SRCS_ERROR := $(addprefix $(DIR_SRC_ERROR)/, \
	ft_destroy_array.c \
	ft_destroy_splits.c \
	ft_error_msg.c \
)

DIR_SRC_VALIDATE := validate
SRCS_VALIDATE := $(addprefix $(DIR_SRC_VALIDATE)/, \
	ft_validate_duplicate.c \
	ft_validate_number.c \
	ft_validate_range.c \
)

DIR_SRC_PREPROCESS := preprocess
SRCS_PREPROCESS := $(addprefix $(DIR_SRC_PREPROCESS)/, \
	$(SRCS_VALIDATE) \
	ft_atoi_array.c \
	ft_atoi_long.c \
	ft_init_stack.c \
	ft_merge_sort_array.c \
	ft_parse_string.c \
	ft_preprocess.c \
	ft_splits_len.c \
	ft_splits.c \
)

DIR_SRC_SORT := sort
SRCS_SORT := $(addprefix $(DIR_SRC_SORT)/, \
	ft_sort_3.c \
)

DIR_SRC_PUSH_SWAP := push_swap
SRCS_PUSH_SWAP := $(addprefix $(DIR_SRC_PUSH_SWAP)/, \
	$(SRCS_SORT) \
)

DIR_SRC_SIMULATOR := simulator
SRCS_SIMULATOR := $(addprefix $(DIR_SRC_SIMULATOR)/, \
	ft_print_devider_line.c \
	ft_print_init.c \
	ft_print_stack.c \
	ft_process_command.c \
	ft_validate_command.c \
)

DIR_SRC_STACK := stack
SRCS_STACK := $(addprefix $(DIR_SRC_STACK)/, \
	ft_check_end.c \
	ft_node_new.c \
	ft_stack_addback.c \
)

DIR_SRC_UTIL := util
SRCS_UTIL := $(addprefix $(DIR_SRC_UTIL)/, \
	ft_get_index_min.c \
	ft_max_int.c \
	ft_max_sizet.c \
	ft_min_int.c \
	ft_min_sizet.c \
)

SRCS_PUSH_SWAP := $(addprefix $(DIR_SRC)/, \
	push_swap.c \
	$(SRCS_COMMAND) \
	$(SRCS_ERROR) \
	$(SRCS_PREPROCESS) \
	$(SRCS_PUSH_SWAP) \
	$(SRCS_SIMULATOR) \
	$(SRCS_UTIL) \
	$(SRCS_STACK) \
)

SRCS_SIMULATOR := $(addprefix $(DIR_SRC)/, \
	simulator.c \
	$(SRCS_COMMAND) \
	$(SRCS_ERROR) \
	$(SRCS_PREPROCESS) \
	$(SRCS_SIMULATOR) \
	$(SRCS_UTIL) \
	$(SRCS_STACK) \
)

# =========================
# vpath
# =========================

vpath %.c \
	$(DIR_SRC) \
	$(DIR_SRC)/$(DIR_SRC_COMMAND) \
	$(DIR_SRC)/$(DIR_SRC_ERROR) \
	$(DIR_SRC)/$(DIR_SRC_PREPROCESS) \
	$(DIR_SRC)/$(DIR_SRC_PREPROCESS)/$(DIR_SRC_VALIDATE) \
	$(DIR_SRC)/$(DIR_SRC_PUSH_SWAP) \
	$(DIR_SRC)/$(DIR_SRC_PUSH_SWAP)/$(DIR_SRC_SORT) \
	$(DIR_SRC)/$(DIR_SRC_SIMULATOR) \
	$(DIR_SRC)/$(DIR_SRC_STACK) \
	$(DIR_SRC)/$(DIR_SRC_UTIL)

# =========================
# object files
# =========================

OBJS_PUSH_SWAP := $(addprefix $(DIR_OBJ)/, $(notdir $(SRCS_PUSH_SWAP:.c=.o)))
OBJS_CHECKER   := $(addprefix $(DIR_OBJ)/, $(notdir $(SRCS_CHECKER:.c=.o)))
OBJS_SIMULATOR := $(addprefix $(DIR_OBJ)/, $(notdir $(SRCS_SIMULATOR:.c=.o)))

# =========================
# dependency files
# =========================

DEPS := $(SRCS:.c=.d)

# =========================
# ANSI/VT100
# =========================

LF      := \n
CR      := \r
ESC     := \e

ER      := $(ESC)[1K
CRLF    := $(CR)$(LF)
ERCR    := $(ER)$(CR)

# =========================
# rules
# =========================

.PHONY: all bonus simulator clean fclean re

all : $(PUSH_SWAP)

bonus : $(PUSH_SWAP) $(CHECKER)

clean :
	@$(MAKE) clean -C $(DIR_LIBFT)
	@$(RM) $(RFLAGS) $(OBJS)

fclean :
	@$(MAKE) fclean -C $(DIR_LIBFT)
	@$(RM) $(RFLAGS) $(NAME) $(OBJS)
	@printf "[$(NAME)] ✔️  Cleaned all !!$(LF)"

re : fclean all

.PHONY: depend clean_depend

depend : $(DEPS)

clean_depend :
	@$(RM) $(RFLAGS) depend_file
	@printf "[$(NAME)] 🧹 Cleaned dependency files$(LF)"

%.d : %.c
	@$(CC) $(INCLUDES) -MM $< | sed 's|^|$(DIR_OBJ)/|' | sed 's|$(DIR_OBJ)/  ||' >> depend_file

$(PUSH_SWAP) : $(DIR_OBJ) $(NAME_LIBFT) $(OBJS_PUSH_SWAP)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFLAGS) $(OBJS_PUSH_SWAP) -o $@
	@printf "$(ERCR)[$(NAME)] ✔️  Make $(PUSH_SWAP) !!$(LF)"

$(CHECKER) : $(DIR_OBJ) $(NAME_LIBFT) $(OBJS_CHECKER)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFLAGS) $(OBJS_CHECKER) -o $@
	@printf "$(ERCR)[$(NAME)] ✔️  Make $(CHECKER) !!$(LF)"

$(SIMULATOR) : $(DIR_OBJ) $(NAME_LIBFT) $(OBJS_SIMULATOR)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFLAGS) $(OBJS_SIMULATOR) -o $@
	@printf "$(ERCR)[$(NAME)] ✔️  Make $(SIMULATOR) !!$(LF)"

$(DIR_OBJ) :
	@mkdir -p $(DIR_OBJ)
	@printf "[$(NAME)] 📁 Created directory $(DIR_OBJ)$(LF)"

$(DIR_OBJ)/%.o : %.c
	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@ -I $(DIR_INC)
	@printf "$(ERCR)[$(NAME)] 🔧 Compiling object file $@"

$(NAME_LIBFT) :
	@$(MAKE) -s all -C $(DIR_LIBFT)

# DO NOT DELETE
