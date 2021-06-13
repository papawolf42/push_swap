/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:31:11 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/10 16:16:00 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <stddef.h>

typedef struct s_ctrl		t_ctrl;
typedef struct s_stack		t_stack;
typedef struct s_node		t_node;

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

struct			s_ctrl
{
	t_stack		a;
	t_stack		b;
	size_t		len;
	size_t		alen;
	size_t		blen;
};

#endif
