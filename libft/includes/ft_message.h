/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:31:30 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/07 22:46:12 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MESSAGE_H
# define FT_MESSAGE_H

typedef	struct		s_message
{
	int		id;
	char	*msg;
}					t_message;

int					ft_msgget_id(char *msg, t_message *msg_list);
char				*ft_msgget_msg(int id, t_message *msg_list);

#endif
