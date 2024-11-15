/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:11:25 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/15 12:23:57 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuint_pf(unsigned int n, int *count)
{
	if (n > 9)
		ft_putuint_pf(n / 10, count);
	ft_putchar_pf((n % 10) + 48, count);
}
