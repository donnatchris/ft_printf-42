/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:09:22 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/15 12:23:32 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pf(char *s, int *count)
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
