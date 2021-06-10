/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 08:10:19 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/05 08:10:41 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "error.h"

static void		ft_merge_sort(int start, int end, int *arr, int *temp)
{
	int		i;
	int		left;
	int		right;
	int		half;
	int		last;

	i = 0;
	left = start;
	right = start + (end - start + 1) / 2;
	half = right;
	last = end + 1;
	while (i < end - start + 1)
	{
		if (left < half && right < last)
		{
			if (arr[left] > arr[right])
			{
				temp[start + i] = arr[right];
				right++;
			}
			else
			{
				temp[start + i] = arr[left];
				left++;
			}
		}
		else if (left >= half)
		{
			temp[start + i] = arr[right];
			right++;
		}
		else if (right >= last)
		{
			temp[start + i] = arr[left];
			left++;
		}
		i++;
	}
	while (i--)
	{
		arr[start] = temp[start];
		start++;
	}
}

static void		ft_recursive_merge_sort(int start, int end, int *arr, int *temp)
{
	if (end - start >= 2) // 8 - 0 + 1 >= 4, 3 - 0 + 1 >= 4
	{
		ft_recursive_merge_sort(start, start + (end - start + 1) / 2 - 1, arr, temp);// (0, 3), (0, 1) (4, 5)
		ft_recursive_merge_sort(start + (end - start + 1) / 2, end, arr, temp);//(2, 3), (4, 8), (6, 8)
	}
	ft_merge_sort(start, end, arr, temp);
}

t_bool			ft_merge_sort_array(int *array, size_t strslen)
{
	int			*temp;

	temp = (int *)malloc(sizeof(int) * (strslen));
	if (temp == NULL)
		return (ft_error_msg(ERR_MALLOC_FAIL));
	ft_bzero(temp, sizeof(int) * (strslen));
	ft_recursive_merge_sort(0, strslen - 1, array, temp);
	return (success);
}
