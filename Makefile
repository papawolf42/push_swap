# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/04 00:28:28 by gunkim            #+#    #+#              #
#    Updated: 2021/06/06 15:50:17 by gunkim           ###   ########.fr        #
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
NAME        := $(SIMULATOR)
# NAME        += $(PUSH_SWAP)
# NAME        += $(CHECKER)

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
CFLAGS    := -g
# CFLAGS    := -g3 -fsanitize=address
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

DIR_SRC_CONSOLE := console
SRCS_CONSOLE := $(addprefix $(DIR_SRC_CONSOLE)/, \
	ft_separate_line.c \
)

DIR_SRC_ERROR := error
SRCS_ERROR := $(addprefix $(DIR_SRC_ERROR)/, \
	ft_destroy_splits.c \
	ft_error_msg.c \
)

DIR_SRC_VALIDATE := validate
SRCS_VALIDATE := $(addprefix $(DIR_SRC_VALIDATE)/, \
	ft_validate_are_duplicate.c \
	ft_validate_are_number.c \
)

DIR_SRC_PREPROCESS := preprocess
SRCS_PREPROCESS := $(addprefix $(DIR_SRC_PREPROCESS)/, \
	$(SRCS_VALIDATE) \
	ft_atoi_array.c \
	ft_merge_sort_array.c \
	ft_parse_string.c \
	ft_preprocess.c \
	ft_strslen.c \
)

SRCS := $(addprefix $(DIR_SRC)/, \
	checker.c \
	push_swap.c \
	simulator.c \
	$(SRCS_CONSOLE) \
	$(SRCS_ERROR) \
	$(SRCS_PREPROCESS) \
)

# =========================
# vpath
# =========================

vpath %.c \
	$(DIR_SRC) \
	$(DIR_SRC)/$(DIR_SRC_CONSOLE) \
	$(DIR_SRC)/$(DIR_SRC_ERROR) \
	$(DIR_SRC)/$(DIR_SRC_PREPROCESS) \
	$(DIR_SRC)/$(DIR_SRC_PREPROCESS)/$(DIR_SRC_VALIDATE)

# =========================
# object files
# =========================

OBJS := $(addprefix $(DIR_OBJ)/, $(notdir $(SRCS:.c=.o)))

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

.PHONY: all clean fclean re

all : $(NAME)

bonus : $(NAME)

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

$(PUSH_SWAP) : $(DIR_OBJ) $(NAME_LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFLAGS) $(OBJS) -o $@
	@printf "$(ERCR)[$(NAME)] ✔️  Make $(PUSH_SWAP) !!$(LF)"

$(CHECKER) : $(DIR_OBJ) $(NAME_LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFLAGS) $(OBJS) -o $@
	@printf "$(ERCR)[$(NAME)] ✔️  Make $(CHECKER) !!$(LF)"

$(SIMULATOR) : $(DIR_OBJ) $(NAME_LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFLAGS) $(OBJS) -o $@
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
