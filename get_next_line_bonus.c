/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounadi <mounadi1337@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 04:55:14 by amounadi          #+#    #+#             */
/*   Updated: 2022/03/04 19:30:50 by amounadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_delete_line(char *stock)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		ft_free(&stock);
		return (NULL);
	}
	res = (char *)malloc(ft_strlen(stock) - i + 1);
	if (!res)
		return (NULL);
	i++;
	while (stock[i])
		res[j++] = stock[i++];
	res[j] = '\0';
	ft_free(&stock);
	return (res);
}

char	*ft_read_line(char *stock, int fd)
{
	char	*buff;
	int		check_error;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	check_error = 1;
	if (!buff)
		return (NULL);
	buff[0] = '\0';
	while (!ft_strchr(stock, '\n') && check_error != 0)
	{
		check_error = read(fd, buff, BUFFER_SIZE);
		if (check_error == -1)
		{
			ft_free(&buff);
			return (NULL);
		}
		buff[check_error] = '\0';
		if (buff[0])
			stock = ft_strjoin(stock, buff);
	}
	ft_free(&buff);
	return (stock);
}

int	ft_strlen_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char		*stock[OPEN_MAX];
	char			*line;
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	stock[fd] = ft_read_line(stock[fd], fd);
	if (!stock[fd])
		return (NULL);
	if (!stock[fd][i])
		if (!(ft_free(&stock[fd])))
			return (NULL);
	line = (char *)malloc(ft_strlen_newline(stock[fd]) + 2);
	if (!line)
		return (NULL);
	i = -1;
	while (stock[fd][++i] && stock[fd][i] != '\n')
		line[i] = stock[fd][i];
	if (stock[fd][i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	stock[fd] = ft_delete_line(stock[fd]);
	return (line);
}
