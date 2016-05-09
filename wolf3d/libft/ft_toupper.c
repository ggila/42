/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:24:26 by ggilaber          #+#    #+#             */
/*   Updated: 2014/11/03 21:54:22 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_toupper(int n)
{
	if (n >= 'a' && n <= 'z')
		n += 'A' - 'a';
	return (n);
}
