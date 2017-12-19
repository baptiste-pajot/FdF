/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpajot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:59:35 by bpajot            #+#    #+#             */
/*   Updated: 2017/11/10 14:01:12 by bpajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s) && s[ft_strlen(s) - i] != c)
	{
		i++;
	}
	if (i > ft_strlen(s))
		return (NULL);
	else
		return ((char*)&s[ft_strlen(s) - i]);
}
