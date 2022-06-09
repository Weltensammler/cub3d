/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:58:33 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/09 11:55:29 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_counter(const char *s, char c)
{
	int	counter;
	int	i;

	counter = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			counter++;
		i++;
	}
	return (counter + 1);
}

char	**ft_split(const char *s, char c)
{
	char			**str;
	int				i;
	unsigned int	pos_1;
	int				count_str;

	count_str = 0;
	pos_1 = 0;
	i = 0;
	if (!s)
		return (NULL);
	str = ft_calloc(sizeof(char *), ft_counter(s, c));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		pos_1 = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i - 1] != c)
			str[count_str] = ft_substr(s, pos_1, i - pos_1);
		count_str++;
	}
	return (str);
}
