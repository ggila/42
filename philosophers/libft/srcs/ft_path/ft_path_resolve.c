/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_resolve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 18:41:10 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/29 14:42:17 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_path.h"
#include "ft_str.h"

static int	s_cwd_isvalid(t_string *buf, char *name, int (*iserror)(t_string *))
{
	if (!ft_path_getcwd(buf)
		|| (ft_string_cat(buf, "/") < 0)
		|| (ft_string_cat(buf, name) < 0))
		return (0);
	if (!iserror(buf))
		return (1);
	return (0);
}

static int	s_prefix_isvalid(t_string *buf, char *name,
				int (*iserror)(t_string *))
{
	if ((ft_string_cat(buf, "/") < 0)
		|| (ft_string_cat(buf, name) < 0))
		return (0);
	if (!iserror(buf))
		return (1);
	return (0);
}

static int	s_prefix_loop_isvalid(t_string *buf, char *prefix, char *name,
					int (*iserror)(t_string *))
{
	size_t		offset;

	while (prefix[0])
	{
		offset = ft_strlen_c(prefix, ':');
		if (!offset)
		{
			if (s_cwd_isvalid(buf, name, iserror))
				return (1);
		}
		else
		{
			ft_string_ncpy(buf, prefix, offset);
			if (s_prefix_isvalid(buf, name, iserror))
				return (1);
		}
		if (!prefix[offset])
			break ;
		prefix += (offset + 1);
	}
	return (0);
}

int			ft_path_resolve(t_string *buf, char *env, char *name,
					int (*iserror)(t_string *))
{
	if (!buf || !env || !env[0] || !iserror)
		return (-1);
	if (s_prefix_loop_isvalid(buf, env, name, iserror))
		return (0);
	if ((env[ft_strlen(env) - 1] == ':') && s_cwd_isvalid(buf, name, iserror))
		return (0);
	return (1);
}
