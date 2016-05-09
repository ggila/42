/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 08:18:30 by ggilaber          #+#    #+#             */
/*   Updated: 2015/01/21 23:49:01 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define BUFSIZE 200
# define STOP 1000
# define FAIL 5000
# define OK 1

# include "libft.h"
# include <stdlib.h>
# include <dirent.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <errno.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

typedef struct	s_flag
{
	int			term_size;
	int			longest;
	int			not_dir;
	int			last;
	int			long_format;
	int			dot_file;
	int			recursive;
	int			t;
	int			u;
	int			reverse;
	int			has_print;
	int			print_dir;
	int			a;
	int			un;
	int			ll;
	int			size;
	int			f;
	int			m;
}				t_flag;

typedef struct	s_dir
{
	char		*dir;
	char		**files;
}				t_dir;

typedef struct	s_merge
{
	void		*tab;
	int			(*f_cmp)(void*, void*);
	int			type_size;
	int			last_index;
}				t_merge;

typedef union	u_key
{
	time_t		time;
	int			ent;
}				t_key;

typedef struct	s_key_sort
{
	char		*str;
	t_key		key;
}				t_key_sort;

typedef struct	s_long
{
	int			total;
	int			link;
	int			uid;
	int			gid;
	int			bytes;
	int			major;
	int			minor;
}				t_long;

t_flag			g_flag;

void			ft_display(t_dir dir, char c);
int				ft_dot_only(t_dir tab_dir[], int *ac);
int				ft_my_sort_opt(t_dir dir, int ac, char c);
int				ft_quit(t_dir tab_dir[], int ac);
int				ft_tab_init(t_dir tab_dir[], int ac, int not_dir);
int				ft_set_tab(int *ac, char **av, t_dir dir_tab[], char c);
int				ft_get_opt(int *ac, char ***av);
int				ft_get_stat(char *str, struct stat *buf, char c);
int				ft_get_dir(t_dir *dir);
int				ft_get_file(t_dir dir, char c);
int				ft_is_dir(char *dir, char *file, int size, char c);
int				ft_rec(char *path, char *file, int size, char c);
void			ft_print_un(char *dir, char **files);
void			ft_set_content(char **files, char *cp_files[]);
void			ft_print(t_dir dir);
void			ft_print_dir(char **files);
void			ft_check_flag(t_dir tab_dir[], int ac);
int				ft_check_av(char **av, int *ac);
int				ft_check_error(int ac, char **av);
void			ft_check_longest(char **files);
int				ft_cmp_int(void *s1, void *s2);
int				ft_cmp_lex(void *s1, void *s2);
int				ft_cmp_opt(void *s1, void *s2);
int				ft_cmp_time(void *s1, void *s2);
int				ft_cmp_file_dir(void *s1, void *s2);
int				ft_cmp_dot(void *s1, void *s2);
int				ft_time_sort(t_dir dir, t_key_sort tab[], int len, char c);
int				ft_ll_sort(t_dir dir, t_key_sort tab[], int len, char c);
int				ft_size_sort(t_dir dir, t_key_sort tab[], int len, char c);
void			ft_sort_key(t_dir dir, int len, char c, char k);
int				ft_my_sort_opt(t_dir dir, int len, char c);
void			ft_my_sort(void *tab, int (*f_cmp)(void*, void*),
					int type_size, int last_index);
t_long			ft_check_long_format(char *dir, char **files);
void			ft_print_lf(char *dir, char **files);
void			ft_get_size(t_long *tlong, struct stat buf);
void			ft_putl_mode(struct stat buf, int *flag);
void			ft_putl_type(struct stat buf, int *flag);
void			ft_putl_link(struct stat buf, int len);
void			ft_putl_uid(struct stat buf, int len);
void			ft_putl_gid(struct stat buf, int len);
void			ft_get_size_uidgid(t_long *tlong, struct stat buf, int *n);
void			ft_putl_bytes(struct stat buf, int len_bytes, int len_major,
					int len_minor);
void			ft_putl_date(struct stat buf);
void			ft_putl_acl(struct stat buf, int len);
void			ft_putl_linkto(char *path);
int				ft_count(char *str);
int				ft_col(int i, int nb_file);
char			*ft_make_path(char *dir, char *file);
void			ft_set_key_sort(char **file, t_key_sort tab[], char c);
int				ft_count_digit(int n);
void			ft_print_init(int *flag, int *n, int *len, int len_while);
void			ft_set_lopt(char c);

#endif
