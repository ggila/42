/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hlst_replace_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 19:49:16 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 13:17:30 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hlist.h"

void			ft_hlst_replace_init(t_hlist *old, t_hlist *new, t_hlist *head)
{
	ft_hlst_replace(old, new, head);
	ft_hlst_init_head(old);
}
