/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 08:34:54 by tguth             #+#    #+#             */
/*   Updated: 2022/06/08 11:34:41 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_map_characters(t_data *data)
{
	int	x;
	int	y;
	int	startposition;

	x = -1;
	y = -1;
	startposition = 0;
	while (data->map[++y][x] != NULL)
	{
		while (data->map[y][++x] != NULL)
		{
			if (data->map[y][x] != ' '									//Spaces i.O.
				&& data->map[y][x] != 0 && data->map[y][x] != 1)		//empty and walls i.O.
				return (-1);
			else if (data->map[y][x] == 'N' || data->map[y][x] == 'S'	//Zählt die Anzahl an Startpositionen
				|| data->map[y][x] == 'W' || data->map[y][x] == 'O')
				startposition++;
		}
		x = -1;
	}
	if (startposition != 1)												//wenn mehr oder weniger als eine Startposition vorhanden --> Error
		return (-1);
	return (0);
}

/*
int	check_map_walls(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(data->map[++y][x] != NULL)
	{
		while(data->map[y][++x] != NULL)
		{

		}
		x = -1;
	}
}*/

int	check_map(t_data *data)
{
	if (check_map_characters(data) == -1)							//check auf nur erlaubte Zeichen
		return (-1);
}