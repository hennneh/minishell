/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:07:20 by vheymans          #+#    #+#             */
/*   Updated: 2022/01/20 15:26:11 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
**Handles all the spliting of the input 
*/

/*
**check for quotes (could have $SOMETHING)
**check for pipes
**check for cmds (echo $sfds)
**check for args (include spaces after arg)
**check for FDs
** heredoc and what not
**output char **
*/

int		count_pipe(char *in)// what if it ends with a pipe == missing bash cmd
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 1;
	flag = 1;
	while (in[i])
	{
		if (in[i] == 34 || in[i] == '\'')
		{
			flag *= -1;
		}
		if (in[i] == PIPE)
		{
			if (in[i + 1] && in[i + 1] != PIPE && flag == 1) // missing cmd after '|' error
				count ++;
			if (in[i + 1] && in[i + 1] == PIPE)
				i ++;
		}
		i ++;
	}
	return (count);
}

int		pipe_split(t_shell *shell, char *in)
{
	int	n_pipes;
	int	pos1;
	int	pos2;
	int	flag;

	n_pipes = count_pipe(in);
	printf("count done : %d\n", n_pipes);
	if (n_pipes < 1)
		return (1);
	shell->seq = malloc(n_pipes + 1 * sizeof(t_seq *));
	if (!shell->seq)
		return (1);
	printf("calloc done\n");
	n_pipes = 0;
	pos1 = 0;
	pos2 = 0;
	flag = 1;
	while (in[pos2])
	{
		while ((in[pos2] != PIPE || flag == -1) && in[pos2])
		{
			printf("[%d]  ", pos2);
			if (in[pos2] == 34 || in[pos2] == '\'')
				flag *= -1;
			pos2 ++;
		}
		printf("\n");
		if (in[pos2 + 1] != PIPE && pos2 > pos1)
		{
			//printf("%d : [%s]\n", n_pipes, ft_substr(in, pos1, pos2 - pos1));
			shell->seq[n_pipes]->seq = ft_substr(in, pos1, pos2 - pos1 - 1);
			printf("substring done\n");
			printf("%d : [%s]\n", n_pipes, shell->seq[n_pipes]->seq);
			n_pipes ++;
		}
		else if (in[pos2 + 1] && in[pos2 + 1] == PIPE)
			pos2 ++;
		if (in[pos2 + 1])
			pos1 = ++ pos2;
	}
	return (0);
}

int main(int argc, char **argv)
{
	argc ++;
	t_shell s;
	int i = 0;

	pipe_split(&s, argv[1]);
	printf("pipe_split done\n");
	while (s.seq[i]->seq)
	{
		printf("%d : [%s]\n", i, s.seq[i]->seq);
		i ++;
	}
	return (0);
}
