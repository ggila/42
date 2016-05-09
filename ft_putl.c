/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 02:36:41 by ggilaber          #+#    #+#             */
/*   Updated: 2015/01/21 23:09:05 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putl_type(struct stat buf, int *flag)
{
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		ft_putchar('d');
	else if ((buf.st_mode & S_IFMT) == S_IFIFO)
		ft_putchar('p');
	else if ((buf.st_mode & S_IFMT) == S_IFCHR)
		ft_putchar('c');
	else if ((buf.st_mode & S_IFMT) == S_IFBLK)
		ft_putchar('b');
	else if ((buf.st_mode & S_IFMT) == S_IFLNK)
	{
		ft_putchar('l');
		*flag = 1;
	}
	else if ((buf.st_mode & S_IFMT) == S_IFSOCK)
		ft_putchar('s');
	else
		ft_putchar('-');
}

void	ft_putl_mode(struct stat buf, int *flag)
{
	ft_putl_type(buf, flag);
	ft_putchar((buf.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((buf.st_mode & S_IWUSR) ? 'w' : '-');
	if (buf.st_mode & S_ISUID)
		ft_putchar((buf.st_mode & S_IXUSR) ? 's' : 'S');
	else
		ft_putchar((buf.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((buf.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((buf.st_mode & S_IWGRP) ? 'w' : '-');
	if (buf.st_mode & S_ISGID)
		ft_putchar((buf.st_mode & S_IXGRP) ? 's' : 'S');
	else
		ft_putchar((buf.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((buf.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((buf.st_mode & S_IWOTH) ? 'w' : '-');
	if (buf.st_mode & S_ISVTX)
		ft_putchar((buf.st_mode & S_IXOTH) ? 't' : 'T');
	else
		ft_putchar((buf.st_mode & S_IXOTH) ? 'x' : '-');
}

void	ft_get_size_uidgid(t_long *tlong, struct stat buf, int *n)
{
	struct passwd	*pass;

	if (!(pass = getpwuid(buf.st_uid)))
		*n = ft_count_digit(buf.st_uid);
	else
		*n = ft_strlen(getpwuid(buf.st_uid)->pw_name);
	if (*n > tlong->uid - 1)
		tlong->uid = *n + 1;
	if (!getgrgid(buf.st_gid))
		*n = ft_count_digit(buf.st_gid);
	else
		(*n = ft_strlen(getgrgid(buf.st_gid)->gr_name));
	if (*n > tlong->gid - 1)
		tlong->gid = *n + 1;
}

void	ft_putl_uid(struct stat buf, int len)
{
	int				n;
	char			*str;
	struct passwd	*pass;

	ft_putchar(' ');
	if (!(pass = getpwuid(buf.st_uid)))
	{
		ft_putnbr(buf.st_uid);
		n = len - ft_count_digit(buf.st_uid);
	}
	else
	{
		str = pass->pw_name;
		n = len - ft_strlen(str);
		ft_putstr(pass->pw_name);
	}
	while (n-- > 0)
		ft_putchar(' ');
}

void	ft_putl_gid(struct stat buf, int len)
{
	int				n;
	char			*str;

	ft_putchar(' ');
	if (!getgrgid(buf.st_gid))
	{
		ft_putnbr(buf.st_gid);
		n = len - ft_count_digit(buf.st_gid);
	}
	else
	{
		str = getgrgid(buf.st_gid)->gr_name;
		n = len - ft_strlen(str);
		ft_putstr(str);
	}
	++n;
	while (n-- > 0)
		ft_putchar(' ');
}
