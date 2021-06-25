/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_pivot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:46:03 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/25 18:19:00 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "push_swap.h"
#include "util.h"

/*
gap의 경우, 모든 값에 대응되야겠음.
모든 경우의 수를 생각해보자.
size: 1 -> gap = 0;
size: 2 -> gap = 0;
size: 3 -> gap = 1;
size: 4 -> gap = 1; 1 1 2 div 1 mod 1
size: 5 -> gap = 1; 1 2 2
size: 6 -> gap = 2; 2 2 2
size: 7 -> gap = 2; 2 2 3
size: 8 -> gap = 2; 2 3 3
size: 9 -> gap = 3; 3 3 3
...
size가 3이라면 종료조건이므로 애초에 이곳에 들어오지 않음.
그러면 size가 4일때 부터, 이 함수로 들어옴.
4에서 1 1 2를 만들어도 되지만, 1 2 1, 2 1 1을 만들어도 상관없음.
어떤 걸 2로 만들지는 사실 결정하기 힘듬. 일단 만들어보자. 
지금 보니까, /를 할게 아니라 %를 하는게 좋아보임.

4개인 경우의 인덱스는 1, 2, 3, 4이다.
그렇다면 1이하, 3이상 이렇게 나누면 되나? 다 해보자.
4의 경우 div 1 mod 1
5의 경우 div 1 mod 2
6의 경우 div 2 mod 0
자 100이 있다고 치자. 그럼 1 ~ 33, 34 ~ 66, 67 ~ 100 해서 33, 33, 34개로 나눌것임.
100 / 3 은 33이고, 100 % 3 은 1이다. 그러면 알고리즘 OK.
만약에 101이다? 그러면 33 34 34가 되야할 것임.
그럼 1 ~ 33, 34 ~ 67, 68 ~ 101이 될 것임. 즉 2라면, 
*/
void	ft_select_pivot(t_ctrl *ctrl, t_type stack, t_parts *parts, size_t size)
{
	size_t	div;
	size_t	mod;
	size_t	offset;

	offset = ft_get_index_min(ft_get_head_from_stack(ctrl, stack), size) - 1;
	div = size / 3;
	mod = size % 3;
	parts->size = size;
	parts->pivot_1 = offset + div;
	parts->pivot_2 = offset + 2 * div + (mod == 2) + 1;
	if (stack == a)
	{
		parts->hold_down.size = div + (mod == 1) + (mod == 2);
		parts->push_up.size = div + (mod == 2);
		parts->push_down.size = div;
	}
	else if (stack == b)
	{
		parts->hold_down.size = div;
		parts->push_up.size = div + (mod == 2);
		parts->push_down.size = div + (mod == 1) + (mod == 2);
	}
	parts->hold_down.stack = stack;
	parts->push_up.stack = !stack;
	parts->push_down.stack = !stack;
}
