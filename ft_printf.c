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

static void	ft_putchar_pf(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

static void	ft_putstr_pf(char *s, int *count)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		(*count) += 6;
		return ;
	}
	while (*s)
	{
		ft_putchar_pf(*s, count);
		s++;
	}
}

static void	ft_putint_pf(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*count) += 11;
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		(*count)++;
		n = -n;
	}
	if (n > 9)
		ft_putint_pf(n / 10, count);
	ft_putchar_pf((n % 10) + 48, count);
}

static void	ft_putuint_pf(unsigned int n, int *count)
{
	if (n > 9)
		ft_putuint_pf(n / 10, count);
	ft_putchar_pf((n % 10) + 48, count);
}

static void	ft_puthexamin_pf(unsigned int n, int *count)
{
	char	*str;

	str = "0123456789abcdef";
	if (n > 15)
		ft_puthexamin_pf(n / 16, count);
	ft_putchar_pf(str[n % 16], count);
}

static void	ft_puthexamaj_pf(unsigned int n, int *count)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (n > 15)
		ft_puthexamaj_pf(n / 16, count);
	ft_putchar_pf(str[n % 16], count);
}

static void	ft_put_mem_address_pf(uintptr_t n, int *count)
{
	char	*str;

	str = "0123456789abcdef";
	if (n > 15)
		ft_put_mem_address_pf(n / 16, count);
	ft_putchar_pf(str[n % 16], count);
}

static void	ft_parse_pf(char format, va_list *ap, int *count)
{
	if (format == 'c')
		ft_putchar_pf((char) va_arg(*ap, int), count);
	else if (format == 's')
		ft_putstr_pf(va_arg(*ap, char *), count);
	else if (format == 'p')
	{
		write(1, "0x", 2);
		(*count) += 2;
		ft_put_mem_address_pf((uintptr_t) va_arg(*ap, void *), count);
	}
	else if (format == 'd')
		ft_putint_pf(va_arg(*ap, int), count);
	else if (format == 'i')
		ft_putint_pf(va_arg(*ap, int), count);
	else if (format == 'u')
		ft_putuint_pf(va_arg(*ap, unsigned int), count);
	else if (format == 'x')
		ft_puthexamin_pf(va_arg(*ap, unsigned int), count);
	else if (format == 'X')
		ft_puthexamaj_pf(va_arg(*ap, unsigned int), count);
	else if (format == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	int		count;

	count = 0;
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_parse_pf(str[i], &ap, &count);
		}
		else
			ft_putchar_pf(str[i], &count);
		i++;
	}
	va_end(ap);
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	int n1 = -2147483648;
	unsigned int n2 = 4000000000;
	int n3 = 8945;
	int	n4 = 8945;
	int count;

	printf("Test of my ft_printf:\n");
	count = ft_printf("%d, %u, %x, %X \n", 0, 0, 0, 0);
	printf("Le retour vaut: %d\n", count);
	printf("Witness:\n");
	count = printf("%d, %u, %x, %X \n", 0, 0, 0, 0);
	printf("Le retour vaut: %d\n", count);
	printf("\n");

	printf("Test of my ft_printf:\n");
	count = ft_printf("%d, %u, %p \n", n1, n2, &n1);
	printf("Le retour vaut: %d\n", count);
	printf("Witness:\n");
	count = printf("%d, %u, %p \n", n1, n2, &n1);
	printf("Le retour vaut: %d\n", count);
	printf("\n");

	printf("Test avec des valeurs NULL et des entiers limites:\n");
	printf("Test of my ft_printf:\n");
	count = ft_printf("%s %d %u %x %X %p\n", (char *) /
		NULL, n1, 0xFFFFFFFF, 0, 0, NULL);
	printf("Witness:\n");
	printf("Le retour vaut: %d\n", count);
	count = printf("%s %d %u %x %X %p\n", (char *) /
		NULL, n1, 0xFFFFFFFF, 0, 0, NULL);
	printf("Le retour vaut: %d\n", count);
	printf("\n");

	printf("Test avec des erreurs:\n");
	ft_printf("Test of my ft_printf:\n");
	count = ft_printf("% what? %. \n");
	printf("Le retour vaut: %d\n", count);
//	printf("Witness:\n");
//	count = printf("% what? %. \n");
//	printf("Le retour vaut: %d\n", count);
	printf("\n");

	return (0);
}
*/
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
• Manage any combination of the following flags:
’-0.’ and the field minimum width
under all conversions.
• Manage all the following flags: ’# +’ (Yes, one of them is a space)
*/
