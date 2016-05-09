/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:31:30 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/21 18:06:05 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAB_H
# define FT_TAB_H

# include <stddef.h>

size_t		ft_tablen(char **tab);
char		**ft_tabnew(size_t size);
void		ft_tabdel(char ***tab_ptr);
char		**ft_tabdup(char **tab);
char		**ft_tabcpy(char **dst, char **src);
char		**ft_tabcat(char **dst, char **src);
void		ft_tabsort_quick(char **tab,
				int (*cmpf)(char const *, char const *));

void		ft_puttab(char **tab);
void		ft_puttab_fd(char **tab, int fd);

#endif
