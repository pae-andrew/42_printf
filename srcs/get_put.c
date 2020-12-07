/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:20:32 by pae-andrew        #+#    #+#             */
/*   Updated: 2020/12/02 19:27:12 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar_str(char *dst, int n, char c)
{
	dst[n] = c;
}

int		count_len(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

char	get_char(char *base, int n)
{
	if (g_printf->spec == 'x' && n >= 10)
		return (base[n] + 32);
	if (g_printf->spec == 'p' && n >= 10)
		return (base[n] + 32);
	return (base[n]);
}

void	ft_putnbr_base(unsigned long nb, char *dst, int i)
{
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, dst, i - 1);
		ft_putnbr_base(nb % 16, dst, i);
	}
	else
		ft_putchar_str(dst, i, get_char("0123456789ABCDEF", nb));
}

char	*get_hex(unsigned long nb)
{
	int		len;
	char	*str;

	len = count_len(nb);
	str = malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	ft_putnbr_base(nb, str, len - 1);
	return (str);
}
