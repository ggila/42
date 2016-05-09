/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 16:44:29 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 22:06:18 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tab.h"
#include "ft_mem.h"

char	**ft_tabnew(size_t size)
{
	char	**tab;

	if (!(tab = FT_ZMALLOC(char *, size + 1)))
		return (NULL);
	return (tab);
}
