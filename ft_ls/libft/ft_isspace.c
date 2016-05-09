/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:05:21 by ggilaber          #+#    #+#             */
/*   Updated: 2014/11/05 11:20:10 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\t' || c == '\n' || c == '\r' ||
			c == '\v')
		return (1);
	else
		return (0);
}
