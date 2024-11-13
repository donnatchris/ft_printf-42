/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:09:26 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/13 11:19:27 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdarg.h"
#include "unistd.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void  ft_putstr(char *s)
{
	if (s == NULL)
		write(1, "null", 4);
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

static void	ft_putint (int n)
{
	int		sign;
	size_t	i;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putint(n / 10);
	ft_putchar((n % 10) + 48);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;

	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				ft_putchar(va_arg(ap, int));
			else if (str[i]  == 's')
				ft_putstr(va_arg(ap, char *));
		//	else if (str[i + 1] == 'p')
		//		//?
		//	else if (str[i + 1] == 'd')
		//		ft_putnbr(va_arg(ap, int));
			else if (str[i] == 'i')
				ft_putint(va_arg(ap, int));
		//	else if (str[i + 1] == 'u')
		//		//?
		//	else if (str[i + 1] == 'x')
		//		//?
		//	else if (str[i + 1] == 'X')
		//		//?
		//	esle if (str[i + 1] == '%')
		//		write(1, '%', 1);
			else
			{
				write(2, "input error in ft_printf\n", 25);
				return (0);
			}
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	printf("Mon printf:\n");
	ft_printf("%i Hello %c %s World!", 42, 'q', "lol");
	printf("\n");
	printf("printf temoin:\n");
	printf("%i Hello %c %s World!", 42, 'q', "lol");
	return (0);
}
/*
Here are the requirements:
• Don’t implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%
• Your function will be compared against the original printf().
• You must use the command ar to create your library.
Using the libtool command is forbidden.
• Your libftprintf.a has to be created at the root of your repository

You have to implement the following conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.

Bonus list:
• Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions.
• Manage all the following flags: ’# +’ (Yes, one of them is a space)
*/
