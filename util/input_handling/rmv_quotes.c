/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmv_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:52:09 by vheymans          #+#    #+#             */
/*   Updated: 2022/02/05 17:05:44 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	arg_len(char *s)
{
	int		i;
	int		count;
	char	c;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			c = s[i];
			i ++;
			while (s[i] && s[i] != c)
			{
				i ++;
				count ++;
			}
			count --;
		}
		else
			count ++;
		i ++;
	}
}

char	*rmv_quotes(char * s)
{

}