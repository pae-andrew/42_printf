/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:23:39 by pae-andrew        #+#    #+#             */
/*   Updated: 2020/12/01 17:44:54 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		getlen(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	copy;
	int				len;
	char			*res;

	copy = (n > 0) ? n : -n;
	len = getlen(n);
	if (!(res = malloc(sizeof(char) * len + 1)))
		return (NULL);
	*(res + len--) = '\0';
	while (copy > 0)
	{
		*(res + len--) = copy % 10 + '0';
		copy /= 10;
	}
	if (n < 0)
	{
		*res = '-';
	}
	if (n == 0)
		*res = '0';
	return (res);
}
