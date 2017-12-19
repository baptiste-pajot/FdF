/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpajot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:03:35 by bpajot            #+#    #+#             */
/*   Updated: 2017/11/13 16:05:37 by bpajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	i;

	i = 0;
	if (s != NULL && ft_strlen(s) > 0 && f != NULL)
	{
		p = ft_strnew(ft_strlen(s));
		if (p == NULL)
			return (NULL);
		while (i < ft_strlen(s))
		{
			p[i] = f(i, s[i]);
			i++;
		}
		return (p);
	}
	else
		return (NULL);
}
