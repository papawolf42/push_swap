/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:27:16 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/16 10:36:35 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

long	ft_atoi_long(const char *nstr)
{
	unsigned long long	result;
	int					sign;

	result = 0;
	sign = 1;
	while ((9 <= *nstr && *nstr <= 13) || *nstr == ' ')
		nstr++;
	if (*nstr == '+' || *nstr == '-')
		if (*nstr++ == '-')
			sign *= -1;
	while ('0' <= *nstr && *nstr <= '9')
	{
		result = result * 10 + *nstr - '0';
		nstr++;
	}
	if (result >= (unsigned long long)LONG_MAX && sign == 1)
		return (LONG_MAX);
	else if (result >= (unsigned long long)LONG_MIN && sign == -1)
		return (LONG_MIN);
	return (sign * result);
}
