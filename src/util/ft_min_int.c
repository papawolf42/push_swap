/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:09:28 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/23 17:09:40 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_min_int(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}