/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 19:49:38 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/21 14:16:00 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"
#include "ft_mem.h"
#include "ft_str.h"
#include <unistd.h>

static t_mem		*mem_new(int const fd, t_hlist *head)
{
	t_mem	*mem;

	if (!(mem = FT_MALLOC(t_mem, 1)))
		return (NULL);
	ft_bzero(mem, sizeof(t_mem));
	mem->fd_mem = fd;
	ft_hlst_add(&mem->lst, head);
	return (mem);
}

static t_mem		*mem_get(int const fd, t_hlist *head)
{
	t_hlist		*lst;

	lst = head->next;
	while (lst != head)
	{
		if (C_MEM(lst)->fd_mem == fd)
			return (C_MEM(lst));
		lst = lst->next;
	}
	return (mem_new(fd, head));
}

static int			read_mem(t_mem *mem, char **line)
{
	char		*cursor;

	if ((cursor = ft_strchr(mem->data, '\n')))
		*(cursor++) = 0;
	if (!(*line = ft_strdup(mem->data)))
		return (-1);
	if (cursor)
	{
		ft_strcpy(mem->data, cursor);
		return (1);
	}
	ft_strclr(mem->data);
	return (0);
}

static int			read_buf(char *buf, t_mem *mem, char **line)
{
	char		*cursor;
	char		*tmp;

	if ((cursor = ft_strchr(buf, '\n')))
		*(cursor++) = 0;
	tmp = *line;
	if (!(*line = ft_strjoin(*line, buf)))
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	if (cursor)
	{
		ft_strcpy(mem->data, cursor);
		return (1);
	}
	return (0);
}

int					ft_gnl(int const fd, char **line)
{
	static t_hlist	head = HLIST_HEAD(head);
	char			buf[GNL_BUFF_SIZE + 1];
	t_mem			*mem;
	int				r;

	ft_strdel(line);
	if (!(mem = mem_get(fd, &head)))
		return (-1);
	r = read_mem(mem, line);
	if (!r)
	{
		while ((r = read(fd, buf, GNL_BUFF_SIZE)))
		{
			if (r < 0)
				return (-1);
			buf[r] = 0;
			if ((r = read_buf(buf, mem, line)))
				return (r);
		}
		return ((**line) ? 1 : 0);
	}
	return (r);
}
