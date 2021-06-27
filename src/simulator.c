/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:03:26 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/27 21:35:48 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "preprocess.h"
#include "simulator.h"
#include "stack.h"
#include "error.h"

int	main(int argc, char *argv[])
{
	t_ctrl		ctrl;

	ft_bzero(&ctrl, sizeof(ctrl));
	ctrl.prog = simulator;
	if (ft_preprocess(&ctrl, argc, argv))
		ft_exit(&ctrl);
	ft_print_init(&ctrl);
	while (1)
	{
		if (ft_check_end(&ctrl))
			break ;
		ft_print_devider_line();
		ft_process_command(&ctrl);
		ft_print_stack(&ctrl);
	}
	ft_print_devider_line();
	return (true);
}
