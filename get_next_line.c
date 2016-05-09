/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 01:54:10 by ggilaber          #+#    #+#             */
/*   Updated: 2014/11/20 01:10:11 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_isline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

static int		ft_free(void *p, int n, char **line, t_list *list)
{
	free(p);
	if (n)
		return (n);
	if (!n && !(*line))
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (n);
	}
	if (!n && **line && !((t_gnl*)(list->content))->str)
		++n;
	else if (!n && list && *((t_gnl*)(list->content))->str)
	{
		++n;
		free((void*)((t_gnl*)(list->content))->str);
		if (!(((t_gnl*)(list->content))->str = ft_strdup("")))
			return (-1);
	}
	if (!n && **line)
		++n;
	return (n);
}

static int		ft_savenextline(char *line, t_list *list, int fd, int ret)
{
	int		i;
	t_list	*temp;

	temp = list;
	while (temp && ((t_gnl*)(temp->content))->fd != fd)
		temp = temp->next;
	i = 0;
	while (line[i] != '\n' && line[i])
		++i;
	if (!line[i])
	{
		if (!list)
			return (0);
		*((t_gnl*)(temp->content))->str = '\0';
		return (0);
	}
	line[i] = '\0';
	i++;
	ret++;
	if (!(((t_gnl*)(temp->content))->str = ft_strnew(ft_strlen(line + i))))
		return (1);
	ft_strcpy(((t_gnl*)(temp->content))->str, line + i);
	if (!ret && ft_isline(line + i))
		*line = '\0';
	return (0);
}

static int		ft_getline(int fd, char **str, t_list **list)
{
	t_gnl		*new;
	t_list		*temp;

	temp = *list;
	while (temp && ((t_gnl*)(temp->content))->fd != fd)
		temp = temp->next;
	if (!temp)
	{
		if (!(new = (t_gnl*)malloc(sizeof(t_gnl))))
			return (1);
		new->fd = fd;
		new->str = NULL;
		ft_lstadd(list, ft_lstnew((void*)new, sizeof(t_gnl)));
		if (!list)
			return (ft_free((void*)new, 1, str, *list));
		temp = *list;
		while (temp && ((t_gnl*)(temp->content))->fd != fd)
			temp = temp->next;
	}
	*str = ft_strdup(((t_gnl*)(temp->content))->str);
	if (!(*str) && ((t_gnl*)(temp->content))->str)
		return (ft_free((void*)new, 1, str, *list));
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*list = NULL;
	char			*buf;
	int				ret;
	char			*temp;

	if (!(ret = BUFF_SIZE) || !line || fd < 0)
		return (-1);
	if (ft_getline(fd, line, &list))
		return (-1);
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (ret && !ft_isline(*line))
	{
		ft_strclr(buf);
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (ft_free((void*)buf, -1, line, list));
		if (!(*buf))
			return (ft_free((void*)buf, 0, line, list));
		temp = *line;
		*line = ft_strjoin(*line, buf);
		free(temp);
	}
	if (ft_savenextline(*line, list, fd, ret))
		return (ft_free((void*)buf, -1, line, list));
	return (ft_free((void*)buf, 1, line, list));
}
