/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexamin_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:12:20 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/15 12:22:43 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexamin_pf(unsigned int n, int *count)
{
	char	*str;

	str = "0123456789abcdef";
	if (n > 15)
		ft_puthexamin_pf(n / 16, count);
	ft_putchar_pf(str[n % 16], count);
}
