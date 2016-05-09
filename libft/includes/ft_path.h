/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:31:30 by jsaglio           #+#    #+#             */
/*   Updated: 2015/10/12 15:28:19 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PATH_H
# define FT_PATH_H

# include "ft_string.h"
# include <sys/stat.h>
# include <limits.h>

void			ft_path_clean(char *path);
int				ft_path_istype(char *path, unsigned int type);
int				ft_path_isrelative(char *target);
t_string		*ft_path_getcwd(t_string *path);
int				ft_path_get_folder(t_string *buf, char *path);
int				ft_path_get_file(t_string *buf, char *path);
int				ft_path_resolve(t_string *buf, char *env, char *name,
					int (*iserror)(t_string *));

#endif
