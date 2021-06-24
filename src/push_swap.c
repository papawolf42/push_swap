/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:01:46 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/23 20:09:24 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structure.h"
#include "preprocess.h"
#include "simulator.h"
#include "push_swap.h"
// #include "stack.h"

int	main(int argc, char *argv[])
{
	t_ctrl	ctrl;

	if (ft_preprocess(&ctrl, argc, argv))
		exit (0);
	ft_sort_3(&ctrl, a, ctrl.a.head);
	ft_print_stack(&ctrl);
	return (true);
}
