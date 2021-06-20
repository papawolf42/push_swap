/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase_and_msg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:36:49 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/17 17:45:24 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"

t_bool	ft_erase_and_msg(char *msg)
{
	ft_putstr_fd(ESC_ERASE_LEFT, 1);
	ft_putstr_fd(ERR_BAD_COMMAND, 1);
}
