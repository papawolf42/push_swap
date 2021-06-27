/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:31:11 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 01:38:14 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <stddef.h>
# include "structure.h"
# include "bool.h"

typedef enum e_which_program	t_prog;

typedef struct s_ctrl			t_ctrl;

typedef struct s_stack			t_stack;
typedef enum e_which_stack		t_wstack;
typedef struct s_node			t_node;

typedef struct s_command		t_cmd;
typedef struct s_commands		t_cmds;
typedef enum e_which_command	t_wcmd;

typedef struct s_pft_command	t_pft_command;

typedef struct s_partitions		t_parts;
typedef struct s_partition		t_part;

typedef struct s_var_merge_sort	t_var_merge_sort;

enum			e_which_program
{
	push_swap,
	checker,
	simulator
};

struct			s_node
{
	int			value;
	size_t		index;
	t_node		*next;
	t_node		*before;
};

struct			s_stack
{
	t_node		*head;
	t_node		*tail;
	size_t		len;
};

enum			e_which_stack
{
	a,
	b
};

enum			e_which_command
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

struct			s_command
{
	t_wcmd		cmd;
	t_cmd		*next;
	t_cmd		*before;
};

struct			s_commands
{
	t_cmd		*head;
	t_cmd		*tail;
	size_t		len;
};

struct			s_ctrl
{
	t_stack		a;
	t_stack		b;
	size_t		len;
	t_cmds		cmds;
	t_prog		prog;
};

struct			s_pft_command
{
	char		key[4];
	t_bool		(*ft_command)(t_ctrl *ctrl);
};

struct			s_partition
{
	t_wstack	stack;
	t_node		*head;
	size_t		size;
	size_t		count;
};

struct			s_partitions
{
	t_node		*head;
	size_t		size;
	size_t		offset;
	t_part		hold_down;
	size_t		pivot_1;
	t_part		push_up;
	size_t		pivot_2;
	t_part		push_down;
};

struct			s_var_merge_sort
{
	int			i;
	int			start;
	int			end;
	int			left;
	int			right;
	int			half;
	int			last;
};

#endif
