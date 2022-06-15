/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 06:10:10 by tguth             #+#    #+#             */
/*   Updated: 2022/06/15 15:31:52 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_map(t_data *data, char *filepath)
{
	int	i;

	i = 0;
	read_map_file(data, filepath);
	printf("(%s)\n", data->n_texture);
	printf("(%s)\n", data->s_texture);
	printf("(%s)\n", data->w_texture);
	printf("(%s)\n", data->e_texture);
	while (data->map[i])
		printf("(%s)\n", data->map[i++]);
	ft_free_arry((void *) &data->map);
	ft_free_str((void *) &data->n_texture);
	ft_free_str((void *) &data->s_texture);
	ft_free_str((void *) &data->w_texture);
	ft_free_str((void *) &data->e_texture);
	return (0);
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
		ft_free_str((void *) &temp);
	}
	store_map(data, map_str);
	ft_free_str((void *) &map_str);
	return (1);
}

/* reads the map string and stores the data in the data struct */
void	store_map(t_data *data, char *map_str)
{
	char	**temp;
	int		i;
	int		z;
	int		j;

	i = 6;
	temp = ft_split_map(map_str, '\n');
	get_color_texture(data, temp);
	while (temp[i])
	{
		z = 1;
		j = ft_strlen(temp[i]);
		printf("j = (%i) z = (%i) temp = (%s)\n", j, z, temp[i]);
		while (z <= j)
		{
			if (temp[i][j - z] == ' ')
			{
				temp[i][j - z] = '\0';
				printf("string = (%s)\n",temp[i]);
			}
			else
				break ;
			z++;
		}
		i++;
	}
	get_map_dimensions(data, temp);
	store_map_array(data, temp);
	ft_free_arry((void *) &temp);
}

/* stores the map in the structs **map array */
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
		printf("compare\n(%s)\n(%s)\n", map_file[j], data->map[z]);
		j++;
		z++;
	}
	data->map[j] = NULL;
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
	while (map_file[z] == NULL)
		z--;
	data->map_height = (z - 6);
}
