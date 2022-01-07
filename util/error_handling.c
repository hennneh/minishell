/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:06:42 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/01/07 15:21:52 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
**	in case of unclosed quotes || characters with undefined behaviour: detect
**	and break off the execution
**
**	counters for the following characters:	" ' \ * ;
**											1 2 3 4 5
**
**	No Message display system yet, (linelimit)
*/
int	error_handling(char *input)
{
	int	counter[6];

	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0;
	counter[3] = 0;
	counter[4] = 0;
	counter[5] = 0;
	while (input[counter[0]])
	{
		if (input[counter[0]] == '"')
			counter[1]++;
		if (input[counter[0]] == '\'')
			counter[2]++;
		if (input[counter[0]] == '\\')
			counter[3]++;
		if (input[counter[0]] == '*')
			counter[4]++;
		if (input[counter[0]] == ';')
			counter[5]++;
		if (counter[1] % 2 || counter[2] % 2 || counter[3] \
						|| counter[4] || counter[5])
			return (1);
	}
	return (0);
}
