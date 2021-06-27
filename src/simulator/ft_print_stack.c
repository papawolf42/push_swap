/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:48:59 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 01:55:49 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "structure.h"
#include "simulator.h"
#include "util.h"

static size_t	ft_count_digit(long nbr)
{
	int		digit;
	long	multi;

	digit = 0;
	multi = 1;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		digit += 1;
	}
	while (nbr >= multi)
	{
		multi *= 10;
		digit++;
	}
	return (digit);
}

static size_t	ft_get_width(t_stack *stack)
{
	t_node	*node;
	size_t	width;
	size_t	i;

	node = stack->head;
	width = 0;
	i = 0;
	while (i < stack->len)
	{
		width = ft_max_sizet(width, ft_count_digit((long)node->value));
		node = node->next;
		i++;
	}
	return (width);
}

void			ft_print_stack_line_nbr_a(t_stack *stack, int width, size_t len)
{
	static t_node	*node;

	if (node == NULL)
		node = stack->head;
	printf("%*d", width, node->value);
	node = node->next;
	if (len == 1)
		node = NULL;
}

void			ft_print_stack_line_nbr_b(t_stack *stack, int width, size_t len)
{
	static t_node	*node;

	if (node == NULL)
		node = stack->head;
	printf("%*d", width, node->value);
	node = node->next;
	if (len == 1)
		node = NULL;
}

void			ft_print_stack_line(t_ctrl *ctrl, size_t len,
			int width)
{
	if (len <= ctrl->a.len)
		ft_print_stack_line_nbr_a(&ctrl->a, width, len);
	else
		printf("%.*s", width, "            ");
	printf(" ");
	if (len <= ctrl->b.len)
		ft_print_stack_line_nbr_b(&ctrl->b, width, len);
	printf("\n");
}

void			ft_print_stack_name(int width)
{
	printf("%.*s %.*s\n", ft_max_int(width, 1), STR_DEVIDER_LINE,
		ft_max_int(width, 1), STR_DEVIDER_LINE);
	printf("%*s %*s\n", width, "a", width, "b");
	printf(STR_DEVIDER_LINE);
	printf(STR_DEVIDER_LINE);
	printf("\n");
}

void			ft_print_stack(t_ctrl *ctrl)
{
	static int	width;
	size_t		len;

	if (width == 0)
		width = ft_get_width(&ctrl->a);
	len = ft_max_sizet(ctrl->a.len, ctrl->b.len);
	while (len)
	{
		ft_print_stack_line(ctrl, len, width);
		len--;
	}
	ft_print_stack_name(width);
}
