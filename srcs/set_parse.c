/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:57:15 by gcredibl          #+#    #+#             */
/*   Updated: 2020/12/02 19:29:17 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	set_flag(char *str)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			g_printf->flag_min = 1;
		else
			g_printf->flag_zero = 1;
		i++;
	}
	return (i);
}

int	set_width(char *str)
{
	int i;

	i = 0;
	if (str[i] == '*')
	{
		if ((g_printf->width = va_arg(g_printf->list, int)) < 0)
		{
			g_printf->width = -g_printf->width;
			g_printf->flag_min = 1;
			g_printf->flag_zero = 0;
		}
		return (1);
	}
	while (ft_isdigit(str[i]))
		i++;
	if (i > 0)
		g_printf->width = ft_atoi(str);
	if (g_printf->width < 0)
	{
		g_printf->width = -g_printf->width;
		g_printf->flag_min = 1;
		g_printf->flag_zero = 0;
	}
	return (i);
}

int	set_prec(char *str)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (str[i] != '.')
		return (0);
	g_printf->flag_dot = 1;
	i++;
	if (str[i] == '*')
	{
		if ((k = va_arg(g_printf->list, int)) < 0)
		{
			k = 0;
			g_printf->flag_dot = 0;
		}
		g_printf->prec = k;
		return (i + 1);
	}
	g_printf->prec = ft_atoi(str + i);
	if (g_printf->prec < 0)
		g_printf->flag_dot = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int	set_spec(char *str)
{
	if (ft_strchr(g_printf->set_spec, *str))
		g_printf->spec = *str;
	else
		g_printf->spec = '\0';
	return (1);
}
