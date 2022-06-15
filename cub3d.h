/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 03:06:49 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/14 15:47:34 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./mlx_linux/mlx.h"
# include "./library/Libft/libft.h"
# include "./library/gnl/get_next_line.h"
# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_RESET	"\x1b[0m"

/*
//	Map Werte
//	0 --> leer,
//	1 --> Mauer,
//	2 --> Player Nordausrichtung,
//	3 --> Player Ostausrichtung,
//	4 --> Player Südausrichtung,
//	5 --> Player Westausrichtung
*/

typedef struct s_data
{
	char	**map;
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	int		rgb_floor[3];
	int		rgb_ceiling[3];
	int		map_width;
	int		map_height;

}	t_data;


// # ifdef __linux__
// #  include <linux/limits.h>
// # else
// #  include <sys/syslimits.h>
// # endif

/*----------------check_input--------------------*/

void	check_input_argv(int argc, char **argv);



/*----------------init_struct---------------------*/

void	init_struct(t_data *data);



/*----------------check_map-----------------------*/

int		get_map(t_data *data, char *filepath);
int		read_map_file(t_data *data, char *filepath);
void	get_map_dimensions(t_data *data, char **map_file);
void	store_map(t_data *data, char *map_str);
char	**ft_split_map(const char *s, char c);
void	get_map_dimensions(t_data *data, char **map_file);
void	store_map_array(t_data *data, char **map_file);
void	get_color_texture(t_data *data, char **map_file);
void	get_texture(t_data *data, char **map_file, int i, char c);
void	get_color(t_data *data, char **map_file, int i, char c);
int		check_map(t_data *data);
int		check_map_characters(t_data *data);
int		check_map_walls(t_data *data);

/*----------------Free-----------------------*/

void	ft_free_str(void **pntr);
void	ft_free_arry(void ***pntr);



/*----------------Error_handling-----------------------*/

void	printe(char *error_str);



#endif
