/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:47:42 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/01/14 10:54:03 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	printstr(char *s)
{
	if (s)
		return (ft_putstr_fd(s, 1));
	return (write(1, "(null)", 6));
}

int	prointer(unsigned int p)
{
	write(1, "0x", 2);
	return (ft_putnbrbase(p, \
		"0123456789abcdef", 16, 1) + 2);
}

int	handler(int var, char c)
{
	if (c == 'x')
		return (ft_putnbrbase(var, "0123456789abcdef", 16, 1));
	if (c == 'X')
		return (ft_putnbrbase(var, "0123456789ABCDEF", 16, 1));
	if (c == 'c')
		return (ft_putchar_fd(var, 1));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(var, 1) + 1);
	return (0);
}

int	ft_printf(char *form, ...)
{
	int		i[2];
	va_list	var;

	i[0] = 0;
	i[1] = 0;
	va_start(var, form);
	while (form[i[0]])
	{
		if (form[i[0]] != '%')
		{
			i[1] += write(1, &form[i[0]++], 1);
			continue ;
		}
		if (form[++i[0]] == 'x' || form[i[0]] == 'X' || form[i[0]] == 'c' \
		|| form[i[0]] == 'i' || form[i[0]] == 'd')
			i[1] += handler(va_arg(var, int), form[i[0]]);
		if (form[i[0]] == 's')
			i[1] += printstr(va_arg(var, char *));
		if (form[i[0]] == 'p')
			i[1] += prointer(va_arg(var, unsigned int));
		if (form[i[0]++] == '%')
			i[1] += write(1, "\%", 1);
	}
	return (i[1]);
}

// // "%i\t%d\t%c\t%s\t%x\t%X\t%%\t%p\n"
// // , 42, -42, 'F', "I hate my life", 42, 2147483647, NULL
// #include <stdio.h>
// int	main()
// {
	
// 	int real;
// 	real = printf("%i\t%d\t%c\t%s\t%x\t%X\t%%\t%p\n", 42, -42, 'F', "I hate my life", 42, 2147483647, NULL);
// 	printf("%i\n", real);
// 	int out;
// 	out = ft_printf("%i\t%d\t%c\t%s\t%x\t%X\t%%\t%p\n", 42, -42, 'F', "I hate my life", 42, 2147483647, NULL);
// 	printf("%i\n", out);
// 	return (0);
// }