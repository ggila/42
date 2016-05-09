/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 18:55:11 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 21:09:56 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void		ft_init_term(void)
{
	char	buf[2048];
	char	buf2[40];
	char	*res;
	char	*area;

	tgetent(buf, getenv("TERM"));
	tcgetattr(0, &g_term);
	g_term_init = g_term;
	g_term.c_lflag &= ~(ICANON);
	g_term.c_lflag &= ~(ECHO);
	g_term.c_cc[VMIN] = 1;
	g_term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &g_term);
	area = buf2;
	res = tgetstr("im", &area);
	tputs(res, 1, ft_putchar_tputs);
}

static void	ft_init_hist(void)
{
	if (!(g_hist = (t_hll*)malloc(sizeof(t_hll))))
		ft_error("error in malloc (ft_init_hist)");
	g_hist->line = NULL;
	g_hist->p = NULL;
	g_hist->n = NULL;
}

static void	ft_init_screen(void)
{
	g_disp.size = tgetnum("co");
	g_disp.cur_line = 1;
	g_disp.nb_line = 1;
	g_disp.pos = 0;
}

void		ft_init(char **env)
{
	struct sigaction	sig;
	char				buf[40];
	char				*area;

	ft_memclr(g_tampon, 4096);
	ft_init_env(env);
	ft_init_term();
	ft_init_hist();
	ft_init_screen();
	sig.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sig, NULL);
	ft_putendl("\n    hi there, welcome\n");
	area = buf;
	tputs(tgetstr("bl", &area), 1, ft_putchar_tputs);
	tputs(tgetstr("vb", &area), 1, ft_putchar_tputs);
}
