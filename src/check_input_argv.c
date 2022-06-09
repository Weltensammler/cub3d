/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 05:06:21 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/09 01:04:17 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Prints Error_String in red with a newline + exit(1) */
void	printe(char *error_str)
{
	printf(ANSI_COLOR_RED "%s\n" ANSI_COLOR_RESET, error_str);
	exit(1);
}

/* Checks that there are 2 input args and the right file type */
void	check_input_argv(int argc, char **argv)
{
	int	i;
	int	is_valid;

	i = 0;
	is_valid = 0;
	if (argc != 2)
		printe("Error - Wrong Input try this => ./cub3d mapname.cub");
	while (argv[1][i])
	{
		if (argv[1][i] == '.' && argv[1][i + 1] == 'c' && argv[1][i + 2] == 'u'
			&& argv[1][i + 3] == 'b' && argv[1][i + 4] == '\0')
		{
			is_valid = 1;
			break ;
		}
		i++;
	}
	if (is_valid != 1)
		printe("Error - Wrong Input try this => ./cub3d mapname.cub");
}
