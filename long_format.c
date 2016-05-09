/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 14:10:41 by ggilaber          #+#    #+#             */
/*   Updated: 2015/01/21 22:28:08 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_tlong_init(t_long *tlong)
{
	tlong->total = 0;
	tlong->link = 0;
	tlong->uid = 0;
	tlong->gid = 0;
	tlong->bytes = 0;
	tlong->major = 0;
	tlong->minor = 0;
}

t_long		ft_check_long_format(char *dir, char **files)
{
	int			i;
	char		*pathfile;
	t_long		tlong;
	struct stat	buf;

	i = -1;
	ft_tlong_init(&tlong);
	while (files[++i])
	{
		pathfile = ft_make_path(dir, files[i]);
		lstat(pathfile, &buf);
		ft_get_size(&tlong, buf);
		tlong.total += buf.st_blocks;
	}
	return (tlong);
}

void		ft_get_size(t_long *tlong, struct stat buf)
{
	int n;

	if ((n = ft_count_digit(buf.st_nlink)) > tlong->link - 1)
		tlong->link = n + 1;
	ft_get_size_uidgid(tlong, buf, &n);
	if ((buf.st_mode & S_IFMT) == S_IFCHR
		|| (buf.st_mode & S_IFMT) == S_IFBLK)
	{
		if ((n = ft_count_digit(buf.st_rdev >> 24)) > tlong->major)
			tlong->major = n;
		n = ft_count_digit(buf.st_rdev & ((1U << 24) - 1));
		if (n > tlong->minor)
			tlong->minor = n > 4 ? 4 : n;
		n = 2 + ft_count_digit(buf.st_rdev >> 24) +
			ft_count_digit(buf.st_rdev & ((1U << 24) - 1));
		if (n > tlong->bytes)
			tlong->bytes = n;
	}
	else if ((n = ft_count_digit(buf.st_size)) > tlong->bytes - 1)
		tlong->bytes = n + 1;
	tlong->bytes = (tlong->bytes > 2 + (tlong->major + tlong->minor)) ?
		tlong->bytes : 2 + tlong->major + tlong->minor;
}

static void	ft_putl(char *dir, char *files, t_long tlong)
{
	char		*path;
	struct stat	buf;
	int			flag;

	flag = 0;
	path = ft_make_path(dir, files);
	ft_get_stat(path, &buf, 'n');
	ft_putl_mode(buf, &flag);
	ft_putl_link(buf, tlong.link);
	ft_putl_uid(buf, tlong.uid);
	ft_putl_gid(buf, tlong.gid);
	ft_putl_bytes(buf, tlong.bytes, tlong.major, tlong.minor);
	ft_putl_date(buf);
	ft_putchar(' ');
	ft_putstr(files);
	if (flag)
		ft_putl_linkto(path);
	ft_putchar('\n');
}

void		ft_print_lf(char *dir, char **files)
{
	int		i;
	t_long	tlong;
	char	*str;

	if (!(str = dir ? dir : ft_strdup(".")))
		exit (errno);
	tlong = ft_check_long_format(str, files);
	if (dir && ft_strstrlen(files))
	{
		ft_putstr("total ");
		ft_putnbr(tlong.total);
		ft_putchar('\n');
	}
	i = -1;
	while (files[++i])
		ft_putl(str, files[i], tlong);
	g_flag.has_print = 1;
	g_flag.print_dir = 1;
}
