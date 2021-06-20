/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:37:57 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/20 18:26:37 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "simulator.h"
#include "error.h"
#include "command.h"

void	ft_wipe_and_print_command(t_ctrl *ctrl, char **split, int idx)
{
	static size_t	count;
	size_t			i;

	(void)ctrl;
	if (idx != -1)
	{
		i = 0;
		while (split[i])
			i++;
		count += i;
	}
	printf(ANSI_CURSOR_UP);
	printf(ANSI_ERASE_LINE);
	printf("Exec ");
	i = 0;
	while (split[i])
	{
		printf("%s ", split[i]);
		i++;
	}
	printf("[%zu]:", count);
	printf("\n");
}

t_bool	ft_process_command(t_ctrl *ctrl)
{
	char		buffer[100];
	char		**split;
	static int	i;

	while (1)
	{
		ft_putstr_fd("Please enter command: ", 1);
		scanf(" %[^\n]", buffer);
		split = ft_split(buffer, ' ');
		if (split == NULL)
			return (ft_error_msg(ERR_MALLOC_FAIL));
		if (ft_validate_command(split) == true)
		{
			ft_wipe_and_print_command(ctrl, split, i);
			i = 0;
			while (i != -1 && split[i] != NULL)
			{
				if (ft_jump_command(ctrl, split[i++]) == fail)
				{
					--i;
					while (--i >= 0)
						ft_jump_command_undo(ctrl, split[i]);
				}
			}
			if (i == -1)
				continue ;
			ft_destroy_splits(split);
			break ;
		}
		ft_destroy_splits(split);
	}
	return (success);
}
