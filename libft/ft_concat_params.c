/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpajot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:56:17 by bpajot            #+#    #+#             */
/*   Updated: 2017/11/17 15:24:16 by bpajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_length_arg(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			j++;
			k++;
		}
		j++;
	}
	return (j);
}

char			*ft_concat_params(int argc, char **argv)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	j = ft_length_arg(argc, argv);
	str = (char*)malloc(sizeof(*str) * (j));
	i = 0;
	j = 0;
	while (++i < argc)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			str[j] = argv[i][k];
			j++;
			k++;
		}
		if (i == argc - 1)
			str[j] = '\0';
		else
			str[j] = '\n';
		j++;
	}
	return (str);
}
