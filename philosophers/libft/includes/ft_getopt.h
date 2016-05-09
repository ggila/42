/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 17:04:06 by jsaglio           #+#    #+#             */
/*   Updated: 2015/12/07 12:59:24 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

# define OPT_NEW(AC, AV)			((t_opt){AC, AV, 1, 1, 0})
# define OPT_AC(opt_ptr)			(opt_ptr->ac - opt_ptr->i)
# define FT_OPT_INIT(opt, ac, av)	opt = OPT_NEW(ac, av)

/*
** Parser: option
*/

typedef struct	s_opt
{
	int			ac;
	char		**av;
	int			i;
	int			i_str;
	int			mem;
}				t_opt;

int				ft_getopt(t_opt *opt);

#endif
