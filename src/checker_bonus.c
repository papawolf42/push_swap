/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:02:45 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 01:30:20 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft.h"
#include "get_next_line.h"
#include "push_swap.h"
#include "structure.h"
#include "command.h"
#include "preprocess.h"
#include "error.h"
#include "bool.h"
#include "stack.h"

t_bool	ft_receive_and_execute(t_ctrl *ctrl)
{
	char	*line;
	int		rtn;

	while (1)
	{
		rtn = get_next_line(0, &line);
		if (rtn == GNL_END)
			break ;
		if (rtn == GNL_FAIL)
			return (fail);
		if (ft_jump_command(ctrl, line) == fail)
			return (ft_error_msg(NULL));
		free(line);
	}
	if (ft_jump_command(ctrl, line) == fail)
		return (ft_error_msg(NULL));
	free(line);
	return (success);
}

int		main(int argc, char *argv[])
{
	t_ctrl	ctrl;
	t_bool	bool;

	ft_bzero(&ctrl, sizeof(ctrl));
	ctrl.prog = checker;
	if (ft_preprocess(&ctrl, argc, argv))
		exit(1);
	if (ft_receive_and_execute(&ctrl))
		exit(1);
	bool = ft_check_end(&ctrl);
	if (bool == true)
		ft_putstr_fd("OK\n", 1);
	if (bool == false)
		ft_putstr_fd("KO\n", 1);
	ft_process_end(&ctrl);
	return (0);
}
