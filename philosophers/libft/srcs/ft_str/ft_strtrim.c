/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:25:58 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 13:01:30 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_misc.h"

static int	ft_getstart(char const *s)
{
	unsigned int i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	i;
	size_t			len;
	size_t			s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	start = ft_getstart(s);
	i = 0;
	while ((i < s_len) && (ft_isspace(s[s_len - i - 1])))
		i++;
	len = (i + start > s_len) ? 0 : s_len - i - start;
	return (ft_strsub(s, start, len));
}
