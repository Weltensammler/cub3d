/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 06:10:10 by tguth             #+#    #+#             */
/*   Updated: 2022/06/09 17:23:40 by bschende         ###   ########.fr       */
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
	// printf("%s\n", map_str);
	return (1);
}

/* reads the map string and stores the data in the data struct */
void	store_map(t_data *data, char *map_str)
{
	// int	i;
	// int	j;
	// int	z;
	// int	t;

	// i = 0;
	// j = 0;
	// z = 0;
	// while (map_str[i])
	// {
	// 	if (z < 9)
	// 	{
	// 		i += 3
	// 		while (map_str[i] && map_str[i] != '\n' && z == 0)
	// 			data->n_texture[j++] = map_str[i++];
	// 		i++;
	// 		z++;
	// 		while (map_str[i] && map_str[i] != '\n' && z == 0)
	// 			data->s_texture[j++] = map_str[i++];
	// 		i++;
	// 		z++;
	// 		while (map_str[i] && map_str[i] != '\n' && z == 0)
	// 			data->w_texture[j++] = map_str[i++];
	// 		i++;
	// 		z++;
	// 		while (map_str[i] && map_str[i] != '\n' && z == 0)
	// 			data->e_texture[j++] = map_str[i++];
	// 		i += 4;
	// 		z += 2;
			
	// 	}
		
	// }
	char	**temp;
	int		i;
	int		z; 

	z = 0;
	i = 0;
	temp = ft_split(map_str, '\n');
	while (temp[z])
		printf("(%s)\n", temp[z++]);
	get_color_texture(data, temp);
	get_map_dimensions(data, temp);
	// printf("%s\n", data->map[6]);
}

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
		z++;
		i++;
	}
	data->map_height = i;
	printf("%i\n", i);
	z = 6;
	i = 0;
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
	printf("%i\n", j);
}

void	get_color_texture(t_data *data, char *map_file);
{
	int	i

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
			printe("Map data wrong format, please try again :D")
		i++;
	}
}