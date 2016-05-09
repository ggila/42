/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putl2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 11:18:04 by ggilaber          #+#    #+#             */
/*   Updated: 2015/01/21 22:12:14 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putl_bytes(struct stat buf, int len_bytes, int len_major,
			int len_minor)
{
	int n_whitespace;

	if ((buf.st_mode & S_IFMT) != S_IFCHR
			&& (buf.st_mode & S_IFMT) != S_IFBLK)
	{
		n_whitespace = len_bytes - ft_count_digit(buf.st_size) - 1;
		while (n_whitespace--)
			ft_putchar(' ');
		ft_putnbr(buf.st_size);
	}
	else
	{
		n_whitespace = 2 + len_major - ft_count_digit(buf.st_rdev >> 24);
		while (n_whitespace--)
			ft_putchar(' ');
		ft_putnbr(buf.st_rdev >> 24);
		ft_putstr(", ");
		n_whitespace = ft_count_digit(buf.st_rdev & ((1U << 24) - 1));
		n_whitespace = n_whitespace > 3 ? 0 : len_minor - n_whitespace - 1;
		while (n_whitespace--)
			ft_putchar(' ');
		ft_putnbr(buf.st_rdev & ((1U << 24) - 1));
	}
	ft_putchar(' ');
}

void	ft_putl_date(struct stat buf)
{
	time_t	time_file;
	time_t	time_now;
	char	*str;

	time_file = g_flag.t ? buf.st_mtimespec.tv_sec : buf.st_atimespec.tv_sec;
	time_now = time(NULL);
	str = ctime(&time_file);
	str = ft_strchr(str, ' ') + 1;
	write(1, str, 7);
	if (time_now - 15688000 < time_file && time_file < time_now + 1)
		write(1, str + 7, 5);
	else
		write(1, str + 15, 5);
}

void	ft_putl_linkto(char *path)
{
	char	buf[BUFSIZE];
	int		i;

	i = -1;
	while (++i < BUFSIZE)
		buf[i] = '\0';
	if (readlink(path, buf, BUFSIZE) == -1)
		exit(errno);
	ft_putstr(" -> ");
	ft_putstr(buf);
}

void	ft_putl_link(struct stat buf, int len)
{
	int n;

	n = 1 + len - ft_count_digit(buf.st_nlink);
	while (n--)
		ft_putchar(' ');
	ft_putnbr(buf.st_nlink);
}
