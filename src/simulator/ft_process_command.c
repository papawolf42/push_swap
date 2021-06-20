/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:37:57 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/20 10:11:39 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "simulator.h"
#include "error.h"
#include "command.h"

void	ft_wipe_and_print_command(t_ctrl *ctrl, char **split)
{
	static size_t	count;
	size_t			i;

	(void)ctrl;
	count++;
	printf(ANSI_CURSOR_UP);
	printf(ANSI_ERASE_LINE);
	printf("[%zu]Exec ", count);
	i = 0;
	while (split[i])
	{
		printf("%s ", split[i]);
		i++;
	}
	printf("\n");
}

t_bool	ft_process_command(t_ctrl *ctrl)
{
	char		buffer[100];
	char		**split;
	size_t		i;

	while (1)
	{
		ft_putstr_fd("Please enter command: ", 1);
		scanf("%s", buffer);
		split = ft_split(buffer, ' ');
		if (split == NULL)
			return (ft_error_msg(ERR_MALLOC_FAIL));
		if (ft_validate_command(split) == true)
			break ;
		ft_destroy_splits(split);
	}
	ft_wipe_and_print_command(ctrl, split);
	i = 0;
	while (split[i] != NULL)
		ft_jump_command(ctrl, split[i++]);
	ft_destroy_splits(split);
	return (success);
}
