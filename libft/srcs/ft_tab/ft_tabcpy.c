/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 16:46:10 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 22:12:39 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tab.h"

char	**ft_tabcpy(char **dst, char **src)
{
	size_t	i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	while ((dst[i] = *src++))
		i++;
	return (dst);
}
