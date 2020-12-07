/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:46:34 by gcredibl          #+#    #+#             */
/*   Updated: 2020/11/26 17:14:28 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_hex(void)
{
	unsigned int	x;
	char			*str;

	x = va_arg(g_printf->list, unsigned int);
	if (x == 0 && g_printf->flag_dot == 1 && g_printf->prec == 0)
		str = ft_memset(malloc(1), '\0', 1);
	else
		str = get_hex(x);
	str = get_dec_precision(str);
	str = check_width(str);
	ft_putstr(str);
	free(str);
}

void		print_end_char(char *str)
{
	if (g_printf->flag_min == 0)
		ft_putstr(str);
	write(1, "\0", 1);
	if (g_printf->flag_min == 1)
		ft_putstr(str);
	g_printf->len++;
	free(str);
}

int			check_global(void)
{
	if (g_printf->flag_zero == 1 && g_printf->flag_min == 1)
		g_printf->flag_zero = 0;
	if (g_printf->flag_zero == 1 && g_printf->flag_dot == 0)
		g_printf->prec = g_printf->width;
	if (g_printf->flag_zero == 1 && g_printf->flag_dot == 1)
		g_printf->flag_zero = 0;
	if (g_printf->prec == 0)
		return (1);
	return (0);
}
