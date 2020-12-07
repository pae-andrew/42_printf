/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:08:45 by gcredibl          #+#    #+#             */
/*   Updated: 2020/11/08 17:57:09 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *s, size_t len)
{
	char	*copy;
	int		i;

	i = 0;
	if (!(copy = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len > 0)
	{
		copy[i] = (char)s[i];
		i++;
		len--;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		if (!(copy = malloc(sizeof(char))))
			return (NULL);
		*copy = '\0';
		return (copy);
	}
	else if (s)
		return (ft_strndup(&s[start], len));
	else
		return (NULL);
}
