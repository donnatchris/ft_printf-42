/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:09:26 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/14 10:43:34 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdarg.h"
#include "unistd.h"

static void	ft_putchar_pf(char c)
{
	write(1, &c, 1);
}

static void	ft_putstr_pf(char *s)
{
	if (s == NULL)
		write(1, "null", 4);
	while (*s)
	{
		ft_putchar_pf(*s);
		s++;
	}
}

static void	ft_putint_pf(int n)
{
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
		ft_putint_pf(n / 10);
	ft_putchar_pf((n % 10) + 48);
}

static void	ft_putuint_pf(unsigned int n)
{
	if (n > 9)
		ft_putuint_pf(n / 10);
	ft_putchar_pf((n % 10) + 48);
}

static void	ft_puthexamin_pf(unsigned int n)
{
	char	*str;

	str = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 15)
		ft_puthexamin_pf(n / 16);
	ft_putchar_pf(str[n % 16]);
}

static void	ft_puthexamaj_pf(unsigned int n)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 15)
		ft_puthexamaj_pf(n / 16);
	ft_putchar_pf(str[n % 16]);
}

static void	ft_put_mem_address_pf(uintptr_t n)
{
	char	*str;

	str = "0123456789abcdef";
	if (n > 15)
		ft_put_mem_address_pf(n / 16);
	ft_putchar_pf(str[n % 16]);
}

static void	ft_parse_pf(char format, va_list *ap)
{
	if (format == 'c')
		ft_putchar_pf((char) va_arg(*ap, int));
	else if (format == 's')
		ft_putstr_pf(va_arg(*ap, char *));
	else if (format == 'p')
	{
		write(1, "0x", 2);
		ft_put_mem_address_pf((uintptr_t) va_arg(*ap, void *));
	}
	else if (format == 'd')
		ft_putint_pf(va_arg(*ap, int));
	else if (format == 'i')
		ft_putint_pf(va_arg(*ap, int));
	else if (format == 'u')
		ft_putuint_pf(va_arg(*ap, unsigned int));
	else if (format == 'x')
		ft_puthexamin_pf(va_arg(*ap, unsigned int));
	else if (format == 'X')
		ft_puthexamaj_pf(va_arg(*ap, unsigned int));
	else if (format == '%')
		write(1, "%", 1);
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
			ft_parse_pf(str[i], &ap);
		}
		else
			ft_putchar_pf(str[i]);
		i++;
	}
	va_end(ap);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	int n1 = -2147483648;
	unsigned int n2 = 4000000000;
	int n3 = 8945;
	int	n4 = 8945;

	printf("Test of my ft_printf:\n");
	ft_printf("%d, %u, %x, %X \n", 0, 0, 0, 0);
	printf("Witness:\n");
	printf("%d, %u, %x, %X \n", 0, 0, 0, 0);
	printf("\n");
	printf("Test of my ft_printf:\n");
	ft_printf("%d, %u, %p \n", n1, n2, &n1);
	printf("Witness:\n");
	printf("%d, %u, %p \n", n1, n2, &n1);
	printf("\n");
	printf("Test of my ft_printf:\n");
	ft_printf("%p %i Hello %c %s World! %d %u %% %x %X \n", &n1, 42, 'q', "lol", n1, n2, n3, n4);
	printf("Witness:\n");
	printf("%p %i Hello %c %s World! %d %u %% %x %X \n", &n1, 42, 'q', "lol", n1, n2, n3, n4);
	printf("\n");
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
