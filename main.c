/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 03:13:55 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/09 10:42:14 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int args, char *argv[])
{
	t_data	data;
	// void	*mlx;
	// void	*mlx_win;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 256, 128, "Hello world!");
	// mlx_loop(mlx);

	check_input_argv(args, argv);
	init_struct(&data);
	get_map(&data, argv[1]);
	printf("Hello\n");
	return (0);
}
