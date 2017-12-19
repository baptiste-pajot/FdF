/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_nb_words.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 18:00:51 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 19:22:28 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_nb_words(char const *s, char c)
{
	size_t		i;
	size_t		nb_word;

	if (s != NULL && ft_strlen(s) > 0)
	{
		i = 0;
		while (s[i] != '\0')
		{
			if (i == 0)
			{
				if (s[i] == c)
					nb_word = 0;
				else
					nb_word = 1;
			}
			else if ((s[i - 1] == c) && s[i] != c)
			{
				nb_word++;
			}
			i++;
		}
		return (nb_word);
	}
	return (0);
}
