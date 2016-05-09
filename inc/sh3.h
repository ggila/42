/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh2.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 09:49:41 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 21:38:45 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH3_H
# define SH3_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <term.h>
# include <dirent.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

# define SET_BLACK ft_putstr("\033[1;30m")
# define SET_BLUE ft_putstr("\033[1;34m")
# define SET_WHITE ft_putstr("\033[1;37m")
# define SET_BLUE_BACK ft_putstr("\033[1;44m")
# define SET_WHITE_BACK ft_putstr("\033[1;47m")

# define OK 0
# define KO 1

# define MISS_EOF 'a'
# define MISS_PAR '('
# define EMPTY ' '
# define INIT 'i'
# define HEREDOC '<'

# define CTRL_A 1
# define CTRL_D 4
# define CTRL_E 5
# define CTRL_G 7
# define CTRL_L 12
# define CTRL_N 14
# define CTRL_P 16
# define TAB 9
# define ENTER 10
# define FLECHE 27
# define SPACE 32
# define WORD 59
# define UP 65
# define DOWN 66
# define RIGHT 67
# define LEFT 68
# define DEL2 91
# define KEY_G 103
# define DEL1 126
# define BCK_SP 127

# define PATH 0
# define DI 1
# define FIL 2

# define PROMPT_SIZE 15

# define MASK 1U
# define MASK_ENV_I MASK<<0

# define L(line) (*line)->line

typedef struct		s_screen
{
	int				size;
	int				cur_line;
	int				nb_line;
	int				cur_lines;
	int				nb_lines;
	int				pos;
}					t_screen;

typedef struct		s_line
{
	struct s_line	*p;
	struct s_line	*n;
	char			line[4096];
	int				cur_line;
	int				nb_line;
	int				pos;
}					t_line;

typedef	struct		s_hdll
{
	struct s_hdll	*n;
	struct s_hdll	*p;
	char			*heredoc;
	char			eof[40];
	char			nb;
}					t_hdll;

typedef struct		s_hll
{
	struct s_hll	*p;
	struct s_hll	*n;
	char			*line;
	char			eof[40];
}					t_hll;

typedef struct		s_rll
{
	struct s_rll	*n;
	char			redir[3];
	char			*file;
	int				fd;
}					t_rll;

typedef struct		s_pll
{
	struct s_pll	*n;
	int				fd[2];
}					t_pll;

char				**g_env;
char				g_flag;
struct termios		g_term;
struct termios		g_term_init;
t_hll				*g_hist;
t_screen			g_disp;
t_hdll				*g_heredoc;
t_line				*g_line;
char				g_tampon[4096];

void				ft_init_term(void);
void				ft_init(char **env);

void				ft_setup_env(void);
void				ft_init_env(char **env);

int					ft_in_env(char *name);
char				*ft_get_env_value(char *name);
int					ft_setenv(char *name, char *value, int overwrite);
int					ft_unsetenv(char *name);
int					ft_add2env(char *name, char *value);

char				**ft_get_cmd(void);

void				ft_read_line_init(int *cur, char buf[3]);
void				ft_read_line(char c);

void				ft_change_line(int *cur, char buf[]);

void				ft_edit_current_line(void);
void				ft_new_line(char buf[], int *cur);

char				*ft_get_tline(t_line *line, char c);
void				ft_tline_new(void);
void				ft_free_tline(void);

char				ft_check_end(char **cmd);

int					ft_get_heredoc(char *cmd);

void				ft_handle_tilde(t_line *line);

int					ft_is_map(char buf[]);
void				ft_map(char *buf, int *cur, char c);

void				ft_fleche(char c, int *cur, char *buf_line);
void				ft_hist(char c, int *cur, char line_buf[]);

void				ft_wildcard_explode(char ***cmd);

void				ft_del_line(int cur, char *line);
void				ft_del(int cur, char *line);
void				ft_del_pre(int *cur, char *line);

void				ft_linebuf_insert(char c, int *cur);
void				ft_linebuf_word_insert(char *word, int *cur);

void				ft_screen_word_insert(char *word, char line_buf[], int cur);
void				ft_screen_insert(char c, char line_buf[], int cur);

void				ft_write_word(char *word, char line_buf[], int *cur);
void				ft_write_char(char c, char line_buf[], int *cur);

void				ft_rewrite_newline(t_line *line, int cur);
void				ft_rewrite(t_line *line, int cur);

void				ft_error(char *str);
void				ft_restore_term(void);
void				ft_free(char **ptr);
void				ft_freefree(char ***ptr);
void				ft_quit_ok(void);

void				ft_clear_screen(void);
int					ft_putchar_tputs(int c);
void				ft_lineclr(char *line);
void				ft_tabcpy(char *line, char temp[], int cur);

void				ft_prompt_end(char c);
void				ft_prompt_begin(void);

void				ft_unify_space(char *str);
char				*ft_get_file(char *cmd);
void				ft_edit_init(int *cur);
int					ft_check_error(char c);
int					ft_check_pipe(char *cmd);

void				ft_update_screen_insert_pos(int len);
void				ft_update_updown_pos(int cur, char *line);

void				ft_go_up(void);
void				ft_go_down(void);
void				ft_go_left(void);
void				ft_go_right(void);
void				ft_pass_prompt(void);

void				ft_go_upleft(void);
void				ft_go_upright(void);
void				ft_go_downleft(void);
void				ft_go_downright(void);

void				ft_line_init(int *cur);
t_line				*ft_go_previous_line(t_line *line, int *cur);
t_line				*ft_go_next_line(t_line *line, int *cur);
void				ft_go_bottom(t_line *line, int *cur);

char				*ft_sub_home(char *str);
char				**ft_get_path(char *str);
void				ft_set_pwd(void);
char				*ft_make_path(char *s1, char *s2);

int					ft_check_dir(char *path);
int					ft_check_prog(char *path);
int					ft_check_file(char *path);

void				ft_save_hist(char *line);
void				ft_free_hist(void);

char				**ft_get_fit(int *cur, char *line);
char				*ft_get_word(int *cur, char *line);
void				ft_tab(char *buf, int *cur, char *line);

void				ft_star(int *cur, char *line);

int					ft_count(char *dir, char *file);
void				ft_fill_fit(char **fit, char *dir, char *file);

void				ft_execute(char **cmd);
char				*ft_make_path(char *s1, char *s2);

int					ft_get_prog_path(char **cmd_words);

char				***ft_cmd_explode(char *cmd);

void				ft_one_do(char *cmd, t_rll *fd);

int					ft_is_builtin(char *cmd);
void				ft_map_builtin(char *cmd);

void				ft_sent2unsetenv(char **cmd_words);
void				ft_sent2setenv(char **cmd_words, int overwrite);
int					ft_check_setvar(char *str);

void				ft_change_dir(char *str);
void				ft_cd(char **cmd_words);

void				ft_handle_oldpwd(void);
int					ft_handle_home(char **cmd_words);
int					ft_cdpath(char *cmd_words);
int					ft_just_cd(void);

int					ft_open_fd(char *cmd, t_rll **fd);

void				ft_opfd(t_rll *new, char redir[], char *file);
int					ft_close_fdr(t_rll *fd);
void				ft_close_fdp(t_pll *fd);

void				ft_first_pipe(char *cmd, t_rll *fd);

void				ft_handle_redir(char *cmd, t_rll *fd);

t_pll				*ft_pll_new(void);
t_pll				*ft_pll_add(t_pll *fd);

void				ft_new_hdll(void);
void				ft_free_hdll(void);
void				ft_rewind_hdll(void);

void				ft_plug_heredoc(char *cmd, int fd[2]);

void				ft_write_tline(int fd, t_line *line);
void				ft_write_info(int fd, int cur);

void				ft_visual(char buf[], int *cur, char bufline[]);

int					ft_handle_par(char **cmd, char par[]);

void				ft_clear_lineline(t_line *line);
void				ft_clear_all(t_line *line, char *buf);
#endif
