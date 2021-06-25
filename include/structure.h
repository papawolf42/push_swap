/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:31:11 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/25 20:07:56 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <stddef.h>
# include "structure.h"
# include "bool.h"

typedef struct s_ctrl			t_ctrl;
typedef struct s_command		t_cmd;
typedef struct s_commands		t_cmds;
typedef struct s_stack			t_stack;
typedef struct s_node			t_node;

typedef enum e_type				t_type;

typedef struct s_pft_command	t_pft_command;

typedef struct s_partitions		t_parts;
typedef struct s_partition		t_part;

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

struct			s_command
{
	char		*cmd;
	t_cmd		*next;
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
};

enum			e_type
{
	a,
	b
};

struct			s_pft_command
{
	char		key[4];
	size_t		len;
	t_bool		(*ft_command)(t_ctrl *ctrl);
};

struct			s_partition
{
	t_type		stack;
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

#endif
