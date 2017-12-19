/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpajot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:24:54 by bpajot            #+#    #+#             */
/*   Updated: 2017/11/14 17:59:18 by bpajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
	{
		return ((char*)haystack);
	}
	else
	{
		while (i < ft_strlen(haystack) && i < len)
		{
			j = 0;
			while (haystack[i + j] == needle[j] && i + j <= ft_strlen(haystack)
					&& i + j < len)
			{
				if (j + 1 == ft_strlen(needle))
					return ((char*)&haystack[i]);
				j++;
			}
			i++;
		}
	}
	return (NULL);
}
