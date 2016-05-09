/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:32:15 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 13:07:15 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert.h"
#include "ft_str.h"

static int	get_size(int n)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_strrev(char *s, int len)
{
	int		i;
	char	c;

	i = 0;
	while (i < len - 1 - i)
	{
		c = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = c;
		i++;
	}
}

char		*ft_itoa(int n)
{
	char	*dst;
	int		sgn;
	int		str_len;
	int		i;

	sgn = (n < 0) ? -1 : 1;
	str_len = get_size(n) - ((sgn - 1) / 2);
	if (!(dst = ft_strnew(str_len)))
		return (NULL);
	dst[str_len] = '\0';
	if (n == 0)
		*dst = '0';
	i = 0;
	while (n != 0)
	{
		dst[i] = '0' + sgn * (n % 10);
		n = n / 10;
		i++;
	}
	if (sgn < 0)
		dst[i] = '-';
	ft_strrev(dst, str_len);
	return (dst);
}
