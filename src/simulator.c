/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:03:26 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/21 00:46:39 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "simulator.h"
#include "preprocess.h"
#include "stack.h"

int	main(int argc, char *argv[])
{
	t_ctrl		ctrl;

	if (ft_preprocess(&ctrl, argc, argv))
		exit (0);
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
