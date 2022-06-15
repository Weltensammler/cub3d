/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschende <bschende@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:39:17 by bschende          #+#    #+#             */
/*   Updated: 2022/06/15 14:30:49 by bschende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	int		read_count;
	char	c;
	char	*line;

	i = 0;
	read_count = 0;
	line = malloc(10000);
	while ((read_count = read(fd, &c, 1) > 0))
	{
		line[i++] = c;
		if (c == '\n')
			break;
	}
	if ((!read_count && !line[i - 1]) || read_count == -1)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

// size_t	ft_gnlstrlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (*(str + i))
// 		i++;
// 	return (i);
// }

// char	*ft_gnlstrchr(char *str, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (*(str + i))
// 	{
// 		if (*(str + i) == (char) c)
// 			return ((char *)&str[i]);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_gnlstrjoin(char *string1, char *string2)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	if(!string1)
// 		string1 = malloc(1 * sizeof(char));
// 	if(!string1 || !string2)
// 		return (NULL);
// 	str = malloc(ft_gnlstrlen(string1) + ft_gnlstrlen(string2) + 1);
// 	if(!str)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while(*(string1 + i))
// 	{
// 		*(str + i) = *(string1 + i);
// 		i++;
// 	}
// 	while(*(string2 + j))
// 		*(str + i++) = *(string2 + j++);
// 	*(str + i) = '\0';
// 	return (str);
// }

// char	*fillstring(int fd, char *string1)
// {
// 	char	*buffer;
// 	int		i;

// 	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
// 	if(!buffer)
// 		return (NULL);
// 	i = 1;
// 	while(!ft_gnlstrchr(string1, '\n') && i != 0)
// 	{
// 		i = read(fd, buffer, BUFFER_SIZE);
// 		if(i == -1)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		*(buffer + i) = '\0';
// 		string1 = ft_gnlstrjoin(string1, buffer);
// 	}
// 	free(buffer);
// 	return (string1);
// }

// char	*output(char *string1)
// {
// 	int		i;
// 	char*	str;

// 	i = 0;
// 	if(!*(string1 + i))
// 		return (NULL);
// 	while(*(string1 + i) && *(string1 + i) != '\n')
// 		i++;
// 	str = malloc((i * sizeof(char)) + 2);
// 	if(!str)
// 		return (NULL);
// 	i = 0;
// 	while(*(string1 + i) && *(string1 + i) != '\n')
// 	{
// 		*(str + i) = *(string1 + i);
// 		i++;
// 	}
// 	if(*(string1 + i) == '\n')
// 	{
// 		*(str + i) = *(string1 + i);
// 		i++;
// 	}
// 	*(str + i) = '\0';
// 	return (str);
// }

// char	*new_string(char *string1)
// {
// 	int		i;
// 	int		j;
// 	char	*str;

// 	i = 0;
// 	while(*(string1 + i) && *(string1 + i) != '\n')
// 		i++;
// 	if(!string1)
// 	{
// 		free(string1);
// 		return (NULL);
// 	}
// 	str = malloc((ft_gnlstrlen(string1) - i + 1) * sizeof(char));
// 	if(!str)
// 		return (NULL);
// 	i++;
// 	j = 0;
// 	while(*(string1 + i))
// 		*(str + j++) = *(string1 + i++);
// 	*(str + j) = '\0';
// 	free(string1);
// 	return (str);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*string1;
// 	char		*string2;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (0);
// 	string1 = fillstring(fd, string1);
// 	if(!string1)
// 		return (NULL);
// 	string2 = output(string1);
// 	string1 = new_string(string1);
// 	return (string2);
// }

// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	fd = open("text.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
// 	while ((s = get_next_line(fd)))
// 	{
// 		printf("%s", s);
// 		printf("%i", fd);
// 	}
// 	if (!s)
// 			printf("OK");
// 	close(fd);
// 	return (0);
// }