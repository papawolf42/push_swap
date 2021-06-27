/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 08:10:19 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 01:43:25 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "libft.h"
#include "bool.h"
#include "error.h"

static void		ft_merge_sorting(t_var_merge_sort *v, int *arr, int *temp)
{
	while (v->i < v->end - v->start + 1)
	{
		if (v->left < v->half && v->right < v->last)
		{
			if (arr[v->left] > arr[v->right])
			{
				temp[v->start + v->i] = arr[v->right];
				v->right++;
			}
			else
			{
				temp[v->start + v->i] = arr[v->left];
				v->left++;
			}
		}
		else if (v->left >= v->half)
			temp[v->start + v->i] = arr[v->right++];
		else if (v->right >= v->last)
			temp[v->start + v->i] = arr[v->left++];
		v->i++;
	}
}

static void		ft_merge_sort(int start, int end, int *arr, int *temp)
{
	t_var_merge_sort	v;

	v.i = 0;
	v.start = start;
	v.end = end;
	v.left = v.start;
	v.right = v.start + (v.end - v.start + 1) / 2;
	v.half = v.right;
	v.last = v.end + 1;
	ft_merge_sorting(&v, arr, temp);
	while (v.i--)
	{
		arr[v.start] = temp[v.start];
		v.start++;
	}
}

static void		ft_recursive_merge_sort(int start, int end, int *arr, int *temp)
{
	if (end - start >= 2)
	{
		ft_recursive_merge_sort(start, start + (end - start + 1) / 2 - 1,
			arr, temp);
		ft_recursive_merge_sort(start + (end - start + 1) / 2, end, arr, temp);
	}
	ft_merge_sort(start, end, arr, temp);
}

t_bool			ft_merge_sort_array(int *array, size_t len)
{
	int			*temp;

	temp = (int *)malloc(sizeof(int) * len);
	if (temp == NULL)
		return (ft_error_msg(ERR_MALLOC_FAIL));
	ft_bzero(temp, sizeof(int) * len);
	ft_recursive_merge_sort(0, len - 1, array, temp);
	ft_destroy_array(temp);
	return (success);
}
