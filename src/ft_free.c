/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 06:28:15 by tguth             #+#    #+#             */
/*   Updated: 2022/06/08 07:01:25 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_str(void **pntr)
{
	if (pntr == NULL || *pntr == NULL)
		return ;
	free(*pntr);
	*pntr = NULL;
}

void	ft_free_arry(void ***pntr)
{
	int	i;

	i = -1;
	if (pntr == NULL || **pntr == NULL)
		return ;
	while ((*pntr)[++i] != NULL)
	{
		free((*pntr)[i]);
		(*pntr)[i] = NULL;
	}
	free(*pntr);
	*pntr = NULL;
}