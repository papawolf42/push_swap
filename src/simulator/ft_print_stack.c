/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:48:59 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/20 10:05:19 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "structure.h"
#include "simulator.h"

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

static size_t	ft_max_sizet(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	ft_max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
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

void	ft_print_stack_line_nbr(t_stack *stack, int width, size_t len)
{
	static t_node	*node;

	if (node == NULL)
		node = stack->head;
	printf("%*d", width, node->value);
	node = node->next;
	if (len == 1)
		node = NULL;
}

void	ft_print_stack_line(t_ctrl *ctrl, size_t len,
			int width_a, int width_b)
{
	if (len <= ctrl->a.len)
		ft_print_stack_line_nbr(&ctrl->a, width_a, len);
	printf(" ");
	if (len <= ctrl->b.len)
		ft_print_stack_line_nbr(&ctrl->b, width_b, len);
	printf("\n");
}

void	ft_print_stack_name(int width_a, int width_b)
{
	printf("%.*s %.*s\n", ft_max_int(width_a, 1), STR_DEVIDER_LINE,
		ft_max_int(width_b, 1), STR_DEVIDER_LINE);
	printf("%*s %*s\n", width_a, "a", width_b, "b");
}

/*
일단 2가지를 제야함,
1. 전체 높이 max_len, stack a와 b의 len 중 큰 것을 선택
2. 각 스텍의 최대 폭을 제야함. a와 b를 각각의 len만큼 돌면서,
	이 값은 매번 돌 필요 없이, 밖에서 한번만 재면 될듯.
3. 여기서 각 스텍의 최대 폭은 리턴되어 printf의 width로 들어감. 왼쪽 정렬하면 좋을 듯.
*/
void	ft_print_stack(t_ctrl *ctrl)
{
	static int	width_a;
	static int	width_b;
	size_t		len;

	if (width_a == 0 || width_b == 0)
	{
		width_a = ft_get_width(&ctrl->a);
		width_b = ft_get_width(&ctrl->b);
	}
	len = ft_max_sizet(ctrl->a.len, ctrl->b.len);
	while (len)
	{
		ft_print_stack_line(ctrl, len, width_a, width_b);
		len--;
	}
	ft_print_stack_name(width_a, width_b);
}
