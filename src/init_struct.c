/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 05:07:12 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/09 02:46:25 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Sets array[size] to value zero */
void	set_array_to_zero(int *array, int size)
{
	int	i;

	while (i < size)
	{
		array[i] = 0;
		i++;
	}
}

/* Initialize all struct values to zero */
void	init_struct(t_data *data)
{
	data->map = NULL;
	data->n_texture = NULL;
	data->s_texture = NULL;
	data->w_texture = NULL;
	data->e_texture = NULL;
	data->map_width = 0;
	data->map_height = 0;
	set_array_to_zero(data->rgb_floor, 3);
	set_array_to_zero(data->rgb_ceiling, 3);
}
