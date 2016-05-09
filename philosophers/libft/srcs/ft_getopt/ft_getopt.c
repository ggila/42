/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 17:53:37 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/11 13:59:19 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include "ft_str.h"

static int		is_minus_minus(t_opt *opt)
{
	if (ft_strequ(opt->av[opt->i], "--"))
	{
		opt->i += 1;
		opt->mem = -1;
		return (1);
	}
	return (0);
}

static int		is_arg_an_option(t_opt *opt)
{
	if (!opt->av[opt->i][0]
		|| opt->av[opt->i][0] != '-'
		|| ft_strequ(opt->av[opt->i], "-"))
	{
		opt->mem = -1;
		return (0);
	}
	return (1);
}

static void		opt_update(t_opt *opt)
{
	opt->mem = opt->av[opt->i][opt->i_str];
	opt->i_str++;
	if (!opt->av[opt->i][opt->i_str])
	{
		opt->i += 1;
		opt->i_str = 1;
	}
	return ;
}

int				ft_getopt(t_opt *opt)
{
	if (opt->mem >= 0 && opt->i < opt->ac)
	{
		if (is_minus_minus(opt))
			return (-1);
		if (!is_arg_an_option(opt))
			return (-1);
		opt_update(opt);
		return (opt->mem);
	}
	return (-1);
}
