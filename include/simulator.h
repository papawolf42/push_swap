/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:36:56 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/27 19:04:01 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATOR_H
# define SIMULATOR_H

# include "bool.h"
# include "structure.h"

# define ANSI_CURSOR_UP			"\033[1A"
# define ANSI_ERASE_LINE		"\033[2K"

# define STR_DEVIDER_LINE		"----------------------------------------"
# define MSG_INIT				"Init a and b\n"

void	ft_print_init(t_ctrl *ctrl);
void	ft_print_devider_line(void);
t_bool	ft_process_command(t_ctrl *ctrl);
void	ft_print_stack(t_ctrl *ctrl);
t_bool	ft_validate_command(char **split);

#endif
