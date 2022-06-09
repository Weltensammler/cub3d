/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:56:34 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/08 17:11:45 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		len_1;
	int		len_2;
	char	*s3;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == 0 || s2 == 0)
		return (0);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	s3 = ft_calloc ((len_1 + len_2 + 1), sizeof(char));
	if (s3 == 0)
		return (0);
	ft_strlcat(s3, s1, len_1 + 1);
	ft_strlcat(s3, s2, len_1 + len_2 + 1);
	free(s1);
	return (s3);
}

// char	*ft_strjoin(char *string1, char *string2)
// {
// 	char	*str;
// 	int		i;
// 	int		j;


// 	if (!string1 || !string2)
// 		return (NULL);
// 	str = malloc(ft_strlen(string1) + ft_strlen(string2) + 1);
// 	if (!str)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	if (string1)
// 		while (*(string1 + ++i))
// 			*(str + i) = *(string1 + i);
// 	while (*(string2 + j))
// 		*(str + i++) = *(string2 + j++);
// 	*(str + i) = '\0';
// 	free(string1);
// 	return (str);
// }
