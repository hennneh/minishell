/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_extract_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:09:37 by hlehmann          #+#    #+#             */
/*   Updated: 2022/04/11 15:09:38 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * does all of the extracting
 * @param sh [t_shell *] shell
 * @return [int] 0 if successful, something else
*/
int	extract_cmd(t_shell *sh)
{
	int	flag;

	flag = 0;
	if (pipe_split(sh, sh->input, 0, 0))
		flag = -1;
	else
		flag = parse(sh, 0);
	if (flag > 0)
	{
		clean_seq(sh);
		close_fd();
	}
	return (flag);
}
