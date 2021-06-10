/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_devider_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:40:05 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/03 17:46:15 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "console.h"

void			ft_print_devider_line(void)
{
	ft_putstr_fd(STR_DEVIDER_LINE, 1);
	ft_putstr_fd(STR_DEVIDER_LINE, 1);
	ft_putchar_fd('\n', 1);
}
