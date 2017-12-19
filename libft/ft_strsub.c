/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpajot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:13:03 by bpajot            #+#    #+#             */
/*   Updated: 2017/11/17 12:57:35 by bpajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (s != NULL)
	{
		p = ft_strnew(len);
		if (p == NULL)
			return (NULL);
		if (len == 0)
			p[0] = '\0';
		else
			p = ft_strncpy(p, &s[start], len);
		return (p);
	}
	else
		return (NULL);
}
