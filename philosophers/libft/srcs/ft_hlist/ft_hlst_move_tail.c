/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hlst_move_tail.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 19:49:16 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 13:17:32 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hlist.h"

void			ft_hlst_move_tail(t_hlist *list, t_hlist *head_src,
					t_hlist *head_dst)
{
	ft_hlst_del(list, head_src);
	ft_hlst_add_tail(list, head_dst);
}
