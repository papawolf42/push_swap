/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_devider_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:31:18 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/16 19:22:38 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "simulator.h"

void	ft_print_devider_line(void)
{
	ft_putstr_fd(DIVIDER_LINE, 1);
	ft_putstr_fd(DIVIDER_LINE, 1);
	ft_putchar_fd('\n', 1);
}
