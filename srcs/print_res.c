/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:39:33 by gcredibl          #+#    #+#             */
/*   Updated: 2020/12/02 19:28:49 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_char(void)
{
	char	*str;
	char	c;
	char	*res;

	if ((res = malloc(sizeof(char) * 2)) == NULL)
	{
		g_printf->error = -1;
		return ;
	}
	if (g_printf->spec == '%')
		c = '%';
	else
		c = (char)va_arg(g_printf->list, int);
	res[0] = c;
	res[1] = '\0';
	if (c == '\0' && g_printf->width > 0)
		g_printf->width--;
	str = check_width(res);
	if (c == '\0')
		return (print_end_char(str));
	ft_putstr(str);
	free(str);
}

void		print_string(void)
{
	char	*str;
	size_t	len;

	str = va_arg(g_printf->list, char*);
	if (str == NULL)
		str = check_width(ft_memcpy(malloc(sizeof(char) * 8), "(null)", 8));
	else
	{
		len = ft_strlen(str);
		str = ft_memcpy(malloc(sizeof(char) * len + 1), str, len + 1);
		if (str == NULL)
		{
			g_printf->error = -1;
			return ;
		}
		str = check_width(str);
	}
	ft_putstr(str);
	free(str);
}

void		print_pointer(void)
{
	char			*str;
	char			*cp;
	unsigned long	x;

	x = va_arg(g_printf->list, unsigned long);
	if (x == 0 && g_printf->flag_dot == 1 && g_printf->prec == 0)
		str = ft_memset(malloc(1), '\0', 1);
	else
		str = get_hex(x);
	if (str == NULL)
	{
		g_printf->error = -1;
		return ;
	}
	str = get_dec_precision(str);
	cp = str;
	str = ft_strjoin("0x", str);
	free(cp);
	str = check_width(str);
	ft_putstr(str);
	free(str);
}

void		print_digit(void)
{
	char			*str;
	long int		x;

	x = va_arg(g_printf->list, int);
	if (x == 0 && g_printf->flag_dot == 1 && g_printf->prec == 0)
		str = ft_memset(malloc(1), '\0', 1);
	else
		str = ft_itoa(x);
	if (str == NULL)
	{
		g_printf->error = -1;
		return ;
	}
	str = get_dec_precision(str);
	str = check_width(str);
	ft_putstr(str);
	free(str);
}

void		print_unsigned_digit(void)
{
	char		*str;
	unsigned	x;

	x = va_arg(g_printf->list, int);
	if (x == 0 && g_printf->flag_dot == 1 && g_printf->prec == 0)
		str = ft_memset(malloc(1), '\0', 1);
	else
		str = ft_itoa_unsigned(x);
	if (str == NULL)
	{
		g_printf->error = -1;
		return ;
	}
	str = get_dec_precision(str);
	str = check_width(str);
	ft_putstr(str);
	free(str);
}
