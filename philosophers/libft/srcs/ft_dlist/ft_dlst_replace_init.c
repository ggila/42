/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_replace_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/29 13:01:00 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 01:55:27 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void			ft_dlst_replace_init(t_dlist *old, t_dlist *new)
{
	ft_dlst_replace(old, new);
	ft_dlst_init_head(old);
}
