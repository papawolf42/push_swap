/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:03:26 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/10 21:42:49 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "structure.h"
#include "preprocess.h"

int			main(int argc, char *argv[])
{
	t_ctrl		ctrl;

	(void)argc;
	ft_preprocess(&ctrl, argv[1]);
	// while (1)
	// {
	// 	if (ft_validate_end())
	// 		break;
	// 	ft_print_devider_line();
	// 	ft_print_status();
	// 	ft_print_stack();
	// }
	return (true);
}
