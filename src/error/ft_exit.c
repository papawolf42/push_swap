/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 10:05:30 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/27 17:00:03 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structure.h"
#include "error.h"

int	ft_exit(t_ctrl *ctrl)
{
	(void)ctrl;
	exit(1);
	return (1);
}
