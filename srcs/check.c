/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:55:01 by gcredibl          #+#    #+#             */
/*   Updated: 2020/12/02 19:29:05 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*append_start(char *str, char c, size_t n)
{
	char	*res;
	size_t	len;

	len = ft_strlen(str);
	if (len >= n)
		return (str);
	res = malloc(sizeof(char) * n + 1);
	if (res == NULL)
	{
		g_printf->error = -1;
		return ((char *)0);
	}
	res = ft_memset(res, c, n - len);
	res[n - len] = '\0';
	ft_strlcat(res, str, n + 1);
	free(str);
	return (res);
}

char	*append(char *str, char c, size_t n)
{
	char	*res;
	size_t	len;

	len = ft_strlen(str);
	if (len >= n)
		return (str);
	res = malloc(sizeof(char) * n + 1);
	if (res == NULL)
	{
		g_printf->error = -1;
		return ((char *)0);
	}
	res = ft_memset(res, c, n);
	res[n] = '\0';
	ft_memcpy(res, str, len);
	free(str);
	return (res);
}

char	*print_string_precision(char *str)
{
	str[g_printf->prec] = '\0';
	return (str);
}

char	*check_width(char *str)
{
	if (g_printf->prec > 0 && ft_strchr("iuxX", g_printf->spec))
		str = append_start(str, '0', g_printf->prec);
	if (g_printf->flag_dot != 0 && g_printf->spec == 's')
		str[g_printf->prec] = '\0';
	if (g_printf->flag_zero == 1 && g_printf->flag_min == 0)
		str = append_start(str, '0', g_printf->width);
	if (g_printf->flag_min == 1)
		str = append(str, ' ', g_printf->width);
	if ((g_printf->flag_zero == 0) ||
	(g_printf->flag_zero == 1 && g_printf->flag_min == 0
	&& g_printf->prec != 0 &&
	!ft_strrchr("dixXou", g_printf->spec)))
		str = append_start(str, ' ', g_printf->width);
	return (str);
}

char	*get_dec_precision(char *str)
{
	unsigned int	len;
	int				minus;

	if (check_global())
		return (str);
	minus = 0;
	if ((len = ft_strlen(str)) > 0 && str[0] == '-')
		minus = 1;
	if (g_printf->flag_dot == 1 && minus)
		g_printf->prec++;
	if ((unsigned int)g_printf->prec > len)
	{
		if (minus)
			str[0] = '0';
		str = ft_memcpy(malloc(1 * len + 2), str, ft_strlen(str) + 1);
		if (str == NULL)
			g_printf->error = -1;
		str = append_start(str, '0', g_printf->prec);
		if (minus == 1)
			str[0] = '-';
	}
	return (str);
}
