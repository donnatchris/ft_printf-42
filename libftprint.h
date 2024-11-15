/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:56:59 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/15 11:01:23 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINT_H
# define LIBFTPRIT_H

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

static void	ft_putchar_pf(char c, int *count)
static void	ft_putstr_pf(char *s, int *count)
static void	ft_putint_pf(int n, int *count)
static void	ft_putuint_pf(unsigned int n, int *count)
static void	ft_puthexamin_pf(unsigned int n, int *count)
static void	ft_puthexamaj_pf(unsigned int n, int *count)
static void	ft_put_mem_address_pf(uintptr_t address, int *count)

#endif
