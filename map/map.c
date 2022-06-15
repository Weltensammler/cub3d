/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 06:10:10 by tguth             #+#    #+#             */
/*   Updated: 2022/06/15 08:12:40 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_map(t_data *data, char *filepath)
{
	// char	*gnl_temp;
	// int		fd;

	// check_map_file()
	read_map_file(data, filepath);
	// fd = open (filepath, O_RDONLY);
	// if (fd <= 2)
		// return (-1);	//gegen Zeile 23 tauschen
	//	err_handler(data);
	// while()
	// {
	// 	get_next_line();
	// }
}

/* reads the map file and stores it in a string */
int	read_map_file(t_data *data, char *filepath)
{
	char	*map_str;
	char	*temp;
	int		i;
	int		fd;

	map_str = NULL;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		printe("Failed to read map");
	i = 1;
	while (i != 0)
	{
		temp = get_next_line(fd);
		if (temp)
			map_str = ft_strjoin(map_str, temp);
		else
			i--;
	}
	store_map(data, map_str);
	printf("(%s)\n", data->n_texture);
	printf("(%s)\n", data->s_texture);
	printf("(%s)\n", data->e_texture);
	printf("(%s)\n", data->w_texture);
	printf("%i, %i, %i\n", data->rgb_floor[0], data->rgb_floor[1], data->rgb_floor[2]);
	printf("%i, %i, %i\n", data->rgb_ceiling[0], data->rgb_ceiling[1], data->rgb_ceiling[2]);
	return (1);
}

/* reads the map string and stores the data in the data struct */
void	store_map(t_data *data, char *map_str)
{
	char	**temp;
	int		i;
	int		z;
	int		j;

	z = 0;
	i = 6;
	temp = ft_split_map(map_str, '\n');
	get_color_texture(data, temp);
	while (temp[i])
	{
		z = 1;
		j = ft_strlen(temp[i]);
		while (z <= j)
		{
			printf("in while(%s) i = %i char = %c\n", temp[i], ft_strlen(temp[i]) - z, temp[i][ft_strlen(temp[i]) - z]);
			if (temp[i][j - z] == ' ')
				temp[i][j - z] = '\0';
			else
				break ;
			z++;
		}
		i++;
	}
	printf("nach while i = %i\n", i);
	get_map_dimensions(data, temp);
	store_map_array(data, temp);
	z = 0;	
	while (temp[z])
		printf("(%s)\n", temp[z++]);
}

void	store_map_array(t_data *data, char **map_file)
{
	int	i;
	int	j;
	int	z;

	j = 6;
	z = 0;
	data->map = ft_calloc(data->map_height + 1, sizeof(char *));
	if (!data->map)
		printe("Map allocation failed!");
	while (map_file[j] && j < data->map_height + 6)
	{
		data->map[z] = ft_calloc(data->map_width + 1, sizeof(char));
		i = 0;
		while (map_file[j][i])
		{
			data->map[z][i] = map_file[j][i];
			i++;
		}
		if ((map_file[j][i]) == '\0' && i < data->map_width)
		{
			while (i < data->map_width)
			{
				data->map[z][i] = ' ';
				i++;
			}
		}
		printf("store_map_array array[%i] = (%s)\n", z, data->map[z]);
		j++;
		z++;
	}
	data->map[j] = '\0';
}

/* gets the height and width of the map and stores it in the struct */
void	get_map_dimensions(t_data *data, char **map_file)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 0;
	z = 6;
	while (map_file[z])
	{
		while (map_file[z][i])
		{
			i++;
			if (i > j)
				j = i;
		}
		i = 0;
		z++;
	}
	data->map_width = j;
	printf("width = %i z = %i\n", j, z);
	while (map_file[z] == '\0')
		z--;
	data->map_height = (z - 6);
	printf("height = %i z = %i\n", data->map_height, z);
}

/* preselection of the functions to store color and textures of the map */
void	get_color_texture(t_data *data, char **map_file)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (map_file[i][0] == 'N')
			get_texture(data, map_file, i, map_file[i][0]);
		else if (map_file[i][0] == 'S')
			get_texture(data, map_file, i, map_file[i][0]);
		else if (map_file[i][0] == 'W')
			get_texture(data, map_file, i, map_file[i][0]);
		else if (map_file[i][0] == 'E')
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
		data->n_texture = temp[1];
	if (c == 'S')
		data->s_texture = temp[1];
	if (c == 'W')
		data->w_texture = temp[1];
	if (c == 'E')
		data->e_texture = temp[1];
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
}

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
	i = 0;
	while (str[i])
		printf("Split (%s)\n", str[i++]);
	return (str);
}
