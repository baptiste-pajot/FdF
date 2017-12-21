/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 14:34:16 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 14:34:18 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (s1 != NULL && s2 != NULL)
	{
		p = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (p == NULL)
			return (NULL);
		ft_strcpy(p, s1);
		ft_strcat(p, s2);
		return (p);
	}
	else if (s1 != NULL)
		return ((char*)s1);
	else if (s2 != NULL)
		return ((char*)s2);
	else
		return (NULL);
}
