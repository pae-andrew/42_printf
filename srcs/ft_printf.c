/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:36:25 by gcredibl          #+#    #+#             */
/*   Updated: 2020/12/02 19:27:52 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_printf *g_printf;

void		restore_flags(void)
{
	g_printf->flag_dot = 0;
	g_printf->flag_zero = 0;
	g_printf->flag_min = 0;
	g_printf->width = 0;
	g_printf->prec = 0;
}

void		print_res(void)
{
	if (g_printf->spec == 'c' || g_printf->spec == '%')
		print_char();
	else if (g_printf->spec == 's')
		print_string();
	else if (g_printf->spec == 'p')
		print_pointer();
	else if (g_printf->spec == 'd' || g_printf->spec == 'i')
		print_digit();
	else if (g_printf->spec == 'u')
		print_unsigned_digit();
	else if (g_printf->spec == 'x' || g_printf->spec == 'X')
		print_hex();
	else if (g_printf->spec == '\0')
		return ;
}

static void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			restore_flags();
			i += set_flag(str + i);
			i += set_width(str + i);
			i += set_prec(str + i);
			i += set_spec(str + i);
			print_res();
		}
		if (str[i] != '\0' && str[i] != '%')
		{
			g_printf->len++;
			write(1, &str[i], 1);
			i++;
		}
	}
	return ;
}

int			check(char *str)
{
	if (!(g_printf = malloc(sizeof(t_printf) + 1)))
		return (-1);
	if (!(g_printf->set_spec = malloc(sizeof(char) * 10)))
		return (-1);
	if (!str)
		return (-1);
	g_printf->set_spec = "cspdiuxX%";
	g_printf->error = 1;
	g_printf->len = 0;
	return (1);
}

int			ft_printf(const char *format, ...)
{
	char	*str;

	str = (char *)format;
	if (check(str) < 0)
		return (-1);
	g_printf->str = str;
	va_start(g_printf->list, format);
	print_str(g_printf->str);
	va_end(g_printf->list);
	if (g_printf->error == -1)
		return (-1);
	return (g_printf->len);
}
