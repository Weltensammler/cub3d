/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:58:02 by bschende          #+#    #+#             */
/*   Updated: 2022/06/15 15:09:07 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* counts how many elements will be created by ft_split_map */
static	int	ft_counter(const char *s, char c)
{
	int	counter;
	int	i;

	counter = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != '\0')
			counter++;
		i++;
	}
	return (counter + 1);
}

/* a customized version of ft_split, deletes emty lines before the
map and leaves them in the map part */
char	**ft_split_map(const char *s, char c)
{
	char			**str;
	int				i;
	int				j;
	unsigned int	pos_1;
	int				count_str;

	count_str = 0;
	pos_1 = 0;
	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = ft_calloc(sizeof(char *), ft_counter(s, c));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		if (j < 7)
		{
			while (s[i] == c && s[i] != '\0')
				i++;
			pos_1 = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i - 1] != c)
			{
				str[count_str] = ft_substr(s, pos_1, i - pos_1);
				j++;
			}
		}
		else
		{
			i++;
			pos_1 = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			str[count_str] = ft_substr(s, pos_1, i - pos_1);
			j++;
		}
		count_str++;
	}
	return (str);
}

/* preselection of the functions to store color and textures of the map */
void	get_color_texture(t_data *data, char **map_file)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (map_file[i][0] == 'N' && map_file[i][1] == 'O' /*&& !map_file[i][2]*/)
			get_texture(data, map_file, i, map_file[i][0]);
		else if (map_file[i][0] == 'S' && map_file[i][1] == 'O' /*&& !map_file[i][2]*/)
			get_texture(data, map_file, i, map_file[i][0]);
		else if (map_file[i][0] == 'W' && map_file[i][1] == 'E' /*&& !map_file[i][2]*/)
			get_texture(data, map_file, i, map_file[i][0]);
		else if (map_file[i][0] == 'E' && map_file[i][1] == 'A' /*&& !map_file[i][2]*/)
			get_texture(data, map_file, i, map_file[i][0]);
		else if (map_file[i][0] == 'F')
			get_color(data, map_file, i, map_file[i][0]);
		else if (map_file[i][0] == 'C')
			get_color(data, map_file, i, map_file[i][0]);
		else
			printe("Map data wrong format, please try again :D");
		i++;
	}
}

/* gets the path to the wall textures of the map and stores it in the struct */
void	get_texture(t_data *data, char **map_file, int i, char c)
{
	char	**temp;

	temp = ft_split(map_file[i], ' ');
	if (c == 'N')
		data->n_texture = ft_strdup(temp[1]);
	if (c == 'S')
		data->s_texture = ft_strdup(temp[1]);
	if (c == 'W')
		data->w_texture = ft_strdup(temp[1]);
	if (c == 'E')
		data->e_texture = ft_strdup(temp[1]);
	ft_free_arry((void *) &temp);
}

/* gets the colors of the ceiling and the floor of
the map and stores it in the struct */
void	get_color(t_data *data, char **map_file, int i, char c)
{
	char	**temp1;
	char	**temp2;
	int		j;

	j = 0;
	temp1 = ft_split(map_file[i], ' ');
	temp2 = ft_split(temp1[1], ',');
	while (j < 3)
	{
		if (c == 'F')
			data->rgb_floor[j] = ft_atoi(temp2[j]);
		if (c == 'C')
			data->rgb_ceiling[j] = ft_atoi(temp2[j]);
		j++;
	}
	ft_free_arry((void *) &temp1);
	ft_free_arry((void *) &temp2);
}
