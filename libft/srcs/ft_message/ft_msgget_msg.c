/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msgget_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:46:52 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/14 16:28:03 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_message.h"

char		*ft_msgget_msg(int id, t_message *msg_list)
{
	int		i;

	if (!msg_list)
		return (0);
	i = -1;
	while (msg_list[++i].msg)
	{
		if (id == msg_list[i].id)
			return (msg_list[i].msg);
	}
	return (0);
}
