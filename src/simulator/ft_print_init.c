/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 22:12:11 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/19 22:58:59 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulator.h"
#include "libft.h"
#include "structure.h"
#include "bool.h"

void	ft_print_init(t_ctrl *ctrl)
{
	ft_print_devider_line();
	ft_putstr_fd(MSG_INIT, 1);
	ft_print_stack(ctrl);
}
