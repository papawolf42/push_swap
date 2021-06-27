# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/04 00:28:28 by gunkim            #+#    #+#              #
#    Updated: 2021/06/28 01:30:12 by gunkim           ###   ########.fr        #
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

DIR_LIBFT           := lib/libft
DIR_GET_NEXT_LINE   := lib/get_next_line

LIB_LIBFT           := libft.a
LIB_GET_NEXT_LINE   := libgnl.a

NAME_LIBFT          := $(DIR_LIBFT)/$(LIB_LIBFT)
NAME_GET_NEXT_LINE  := $(DIR_GET_NEXT_LINE)/$(LIB_GET_NEXT_LINE)

# =========================
# implicit rule
# =========================

CC        := gcc
# CFLAGS    := -g
CFLAGS    := -g3 -fsanitize=address
CFLAGS    += -Wall
CFLAGS    += -Wextra
CFLAGS    += -Werror

INCLUDES     := -I $(DIR_LIBFT)/include \
				-I $(DIR_GET_NEXT_LINE) \
				-I include
LIBFLAG_FT  := -L $(DIR_LIBFT) -lft
LIBFLAG_GNL := -L $(DIR_GET_NEXT_LINE) -lgnl
LIBFLAGS    := $(LIBFLAG_FT) $(LIBFLAG_GNL)

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
SRC_COMMAND := $(addprefix $(DIR_SRC_COMMAND)/, \
	ft_cmd_addback.c \
	ft_cmd_p.c \
	ft_cmd_rr.c \
	ft_cmd_r.c \
	ft_cmd_s_1.c \
	ft_cmd_s_2.c \
	ft_jump_command_undo.c \
	ft_jump_command.c \
)

DIR_SRC_ERROR := error
SRC_ERROR := $(addprefix $(DIR_SRC_ERROR)/, \
	ft_destroy_array.c \
	ft_destroy_split.c \
	ft_destroy_splits.c \
	ft_error_msg.c \
)

DIR_SRC_VALIDATE := validate
SRC_VALIDATE := $(addprefix $(DIR_SRC_VALIDATE)/, \
	ft_validate_duplicate.c \
	ft_validate_number.c \
	ft_validate_range.c \
)

DIR_SRC_PREPROCESS := preprocess
SRC_PREPROCESS := $(addprefix $(DIR_SRC_PREPROCESS)/, \
	$(SRC_VALIDATE) \
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
SRC_SORT := $(addprefix $(DIR_SRC_SORT)/, \
	ft_sort_3_at_first.c \
	ft_sort_3.c \
	ft_sort_less_3.c \
)

DIR_SRC_PUSH_SWAP := push_swap
SRC_PUSH_SWAP := $(addprefix $(DIR_SRC_PUSH_SWAP)/, \
	$(SRC_SORT) \
	ft_combine_command.c \
	ft_get_head_from_stack.c \
	ft_print_commands.c \
	ft_process_end.c \
	ft_push_back.c \
	ft_push_two_third.c \
	ft_push_two_thrid_without_reverse.c \
	ft_select_pivot.c \
)

DIR_SRC_SIMULATOR := simulator
SRC_SIMULATOR := $(addprefix $(DIR_SRC_SIMULATOR)/, \
	ft_print_devider_line.c \
	ft_print_init.c \
	ft_print_stack.c \
	ft_process_command.c \
	ft_validate_command.c \
)

DIR_SRC_STACK := stack
SRC_STACK := $(addprefix $(DIR_SRC_STACK)/, \
	ft_check_end.c \
	ft_node_new.c \
	ft_stack_addback.c \
)

DIR_SRC_UTIL := util
SRC_UTIL := $(addprefix $(DIR_SRC_UTIL)/, \
	ft_get_index_min.c \
	ft_max_int.c \
	ft_max_sizet.c \
	ft_min_int.c \
	ft_min_sizet.c \
)

SRCS_PUSH_SWAP := $(addprefix $(DIR_SRC)/, \
	push_swap.c \
	$(SRC_COMMAND) \
	$(SRC_ERROR) \
	$(SRC_PREPROCESS) \
	$(SRC_PUSH_SWAP) \
	$(SRC_SIMULATOR) \
	$(SRC_STACK) \
	$(SRC_UTIL) \
)

SRCS_CHECKER := $(addprefix $(DIR_SRC)/, \
	checker_bonus.c \
	$(SRC_COMMAND) \
	$(SRC_ERROR) \
	$(SRC_PREPROCESS) \
	$(SRC_PUSH_SWAP) \
	$(SRC_STACK) \
	$(SRC_UTIL) \
)

SRCS_SIMULATOR := $(addprefix $(DIR_SRC)/, \
	simulator.c \
	$(SRC_COMMAND) \
	$(SRC_ERROR) \
	$(SRC_PREPROCESS) \
	$(SRC_SIMULATOR) \
	$(SRC_STACK) \
	$(SRC_UTIL) \
)

SRCS := $(addprefix $(DIR_SRC)/, \
	push_swap.c \
	checker_bonus.c \
	simulator.c \
	$(SRC_COMMAND) \
	$(SRC_ERROR) \
	$(SRC_PREPROCESS) \
	$(SRC_PUSH_SWAP) \
	$(SRC_SIMULATOR) \
	$(SRC_STACK) \
	$(SRC_UTIL) \
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
OBJS           := $(addprefix $(DIR_OBJ)/, $(notdir $(SRCS:.c=.o)))

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

.PHONY: all bonus clean fclean re

all : $(PUSH_SWAP)

bonus : $(CHECKER)

clean :
	@$(MAKE) clean -C $(DIR_LIBFT)
	@$(MAKE) clean -C $(DIR_GET_NEXT_LINE)
	@$(RM) $(RFLAGS) $(OBJS)

fclean :
	@$(MAKE) fclean -C $(DIR_LIBFT)
	@$(MAKE) fclean -C $(DIR_GET_NEXT_LINE)
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
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFLAG_FT) $(OBJS_PUSH_SWAP) -o $@
	@printf "$(ERCR)[$(PUSH_SWAP)] ✔️  Make $(PUSH_SWAP) !!$(LF)"

$(CHECKER) : $(DIR_OBJ) $(NAME_LIBFT) $(NAME_GET_NEXT_LINE) $(OBJS_CHECKER)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFLAGS) $(OBJS_CHECKER) -o $@
	@printf "$(ERCR)[$(CHECKER)] ✔️  Make $(CHECKER) !!$(LF)"

$(SIMULATOR) : $(DIR_OBJ) $(NAME_LIBFT) $(OBJS_SIMULATOR)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFLAG_FT) $(OBJS_SIMULATOR) -o $@
	@printf "$(ERCR)[$(SIMULATOR)] ✔️  Make $(SIMULATOR) !!$(LF)"

$(DIR_OBJ) :
	@mkdir -p $(DIR_OBJ)
	@printf "[$(NAME)] 📁 Created directory $(DIR_OBJ)$(LF)"

$(DIR_OBJ)/%.o : %.c
	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@ -I $(DIR_INC)
	@printf "$(ERCR)[$(NAME)] 🔧 Compiling object file $@"

$(NAME_LIBFT) :
	@$(MAKE) -s all -C $(DIR_LIBFT)

$(NAME_GET_NEXT_LINE) :
	@$(MAKE) -s all -C $(DIR_GET_NEXT_LINE)

# DO NOT DELETE

obj/push_swap.o: src/push_swap.c lib/libft/include/libft.h \
include/structure.h include/bool.h include/preprocess.h \
include/simulator.h include/push_swap.h
obj/checker_bonus.o: src/checker_bonus.c include/checker_bonus.h \
include/structure.h include/bool.h lib/libft/include/libft.h \
lib/get_next_line/get_next_line.h include/push_swap.h \
include/command.h include/preprocess.h include/error.h include/stack.h
obj/simulator.o: src/simulator.c lib/libft/include/libft.h \
include/preprocess.h include/structure.h include/bool.h \
include/simulator.h include/stack.h include/error.h
obj/ft_cmd_addback.o: src/command/ft_cmd_addback.c include/bool.h \
include/structure.h
obj/ft_cmd_p.o: src/command/ft_cmd_p.c lib/libft/include/libft.h \
include/bool.h include/structure.h include/simulator.h \
include/command.h
obj/ft_cmd_rr.o: src/command/ft_cmd_rr.c lib/libft/include/libft.h \
include/bool.h include/structure.h include/simulator.h \
include/command.h
obj/ft_cmd_r.o: src/command/ft_cmd_r.c lib/libft/include/libft.h \
include/bool.h include/structure.h include/simulator.h \
include/command.h
obj/ft_cmd_s_1.o: src/command/ft_cmd_s_1.c include/bool.h include/structure.h \
include/command.h include/simulator.h
obj/ft_cmd_s_2.o: src/command/ft_cmd_s_2.c lib/libft/include/libft.h \
include/bool.h include/structure.h
obj/ft_jump_command_undo.o: src/command/ft_jump_command_undo.c \
lib/libft/include/libft.h include/bool.h include/structure.h \
include/command.h
obj/ft_jump_command.o: src/command/ft_jump_command.c \
lib/libft/include/libft.h include/bool.h include/structure.h \
include/command.h
obj/ft_destroy_array.o: src/error/ft_destroy_array.c include/bool.h
obj/ft_destroy_split.o: src/error/ft_destroy_split.c include/bool.h
obj/ft_destroy_splits.o: src/error/ft_destroy_splits.c include/bool.h \
include/error.h include/structure.h
obj/ft_error_msg.o: src/error/ft_error_msg.c lib/libft/include/libft.h \
include/bool.h
obj/ft_validate_duplicate.o: src/preprocess/validate/ft_validate_duplicate.c \
include/bool.h include/error.h include/structure.h
obj/ft_validate_number.o: src/preprocess/validate/ft_validate_number.c \
lib/libft/include/libft.h include/bool.h include/error.h \
include/structure.h
obj/ft_validate_range.o: src/preprocess/validate/ft_validate_range.c \
include/bool.h include/error.h include/structure.h
obj/ft_atoi_array.o: src/preprocess/ft_atoi_array.c include/bool.h \
include/preprocess.h include/structure.h include/error.h
obj/ft_atoi_long.o: src/preprocess/ft_atoi_long.c
obj/ft_init_stack.o: src/preprocess/ft_init_stack.c lib/libft/include/libft.h \
include/structure.h include/bool.h include/stack.h include/error.h
obj/ft_merge_sort_array.o: src/preprocess/ft_merge_sort_array.c \
lib/libft/include/libft.h include/bool.h include/error.h \
include/structure.h
obj/ft_parse_string.o: src/preprocess/ft_parse_string.c \
lib/libft/include/libft.h include/bool.h include/error.h \
include/structure.h include/preprocess.h
obj/ft_preprocess.o: src/preprocess/ft_preprocess.c include/bool.h \
include/error.h include/structure.h include/preprocess.h
obj/ft_splits_len.o: src/preprocess/ft_splits_len.c
obj/ft_splits.o: src/preprocess/ft_splits.c lib/libft/include/libft.h \
include/bool.h
obj/ft_sort_3.o: src/push_swap/sort/ft_sort_3.c include/structure.h \
include/bool.h include/command.h include/util.h
obj/ft_sort_less_3.o: src/push_swap/sort/ft_sort_less_3.c include/structure.h \
include/bool.h include/push_swap.h include/command.h
obj/ft_combine_command.o: src/push_swap/ft_combine_command.c \
include/structure.h include/bool.h
obj/ft_get_head_from_stack.o: src/push_swap/ft_get_head_from_stack.c \
include/structure.h include/bool.h
obj/ft_print_commands.o: src/push_swap/ft_print_commands.c \
include/structure.h include/bool.h
obj/ft_process_end.o: src/push_swap/ft_process_end.c include/structure.h \
include/bool.h
obj/ft_push_back.o: src/push_swap/ft_push_back.c include/structure.h \
include/bool.h include/command.h
obj/ft_push_two_third.o: src/push_swap/ft_push_two_third.c \
include/push_swap.h include/structure.h include/bool.h \
include/command.h include/util.h
obj/ft_push_two_thrid_without_reverse.o: \
src/push_swap/ft_push_two_thrid_without_reverse.c include/structure.h \
include/bool.h include/command.h include/util.h
obj/ft_select_pivot.o: src/push_swap/ft_select_pivot.c include/structure.h \
include/bool.h include/push_swap.h include/util.h
obj/ft_print_devider_line.o: src/simulator/ft_print_devider_line.c \
lib/libft/include/libft.h include/simulator.h include/bool.h \
include/structure.h
obj/ft_print_init.o: src/simulator/ft_print_init.c include/simulator.h \
include/bool.h include/structure.h lib/libft/include/libft.h
obj/ft_print_stack.o: src/simulator/ft_print_stack.c include/structure.h \
include/bool.h include/simulator.h include/util.h
obj/ft_process_command.o: src/simulator/ft_process_command.c \
lib/libft/include/libft.h include/simulator.h include/bool.h \
include/structure.h include/error.h include/command.h
obj/ft_validate_command.o: src/simulator/ft_validate_command.c include/bool.h
obj/ft_check_end.o: src/stack/ft_check_end.c include/bool.h \
include/structure.h
obj/ft_node_new.o: src/stack/ft_node_new.c include/bool.h include/structure.h
obj/ft_stack_addback.o: src/stack/ft_stack_addback.c include/structure.h \
include/bool.h
obj/ft_get_index_min.o: src/util/ft_get_index_min.c include/structure.h \
include/bool.h include/util.h
obj/ft_max_int.o: src/util/ft_max_int.c
obj/ft_max_sizet.o: src/util/ft_max_sizet.c
obj/ft_min_int.o: src/util/ft_min_int.c
obj/ft_min_sizet.o: src/util/ft_min_sizet.c
