/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msgget_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 14:31:34 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/14 16:28:09 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_message.h"
#include "ft_str.h"

int			ft_msgget_id(char *msg, t_message *msg_list)
{
	size_t	i;

	if (!msg_list || !msg)
		return (-1);
	i = -1;
	while (msg_list[++i].msg)
	{
		if (ft_strequ(msg, msg_list[i].msg))
			return (msg_list[i].id);
	}
	return (-1);
}
