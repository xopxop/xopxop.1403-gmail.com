/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:52:21 by ihwang            #+#    #+#             */
/*   Updated: 2020/04/18 23:01:29 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# define KEY 1
# define VAL 0
# define PARENT 1
# define CHILD 0
# define SET 1
# define UNSET 0
# define F_TYPE_MASK 0170000
# define PRINT 1
# define ER 0
# define PMPT 2
# define CLIP_SAVE 0
# define CLIP_TAKE 1
# define CLIP_DELT 2


# ifdef __APPLE__
#  if __MAC_OS_X_VERSION_MIN_REQUIRED <= 101200
#   define OS "sierra"
#   define LEFT "#4"
#  else
#   define LEFT "kl"
#   define OS "not_sierra"
#  endif
# else
#  define LEFT "kl"
#  define OS "not_apple"
# endif


# include <term.h>
# include <termios.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <dirent.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

char					**g_env;
int						g_status;

typedef struct dirent	t_dir;
typedef struct stat		t_stat;
typedef struct termios	t_term;

typedef struct			s_cmd
{
	int					ac;
	char				**av;
	struct s_cmd		*next;
}						t_cmd;

typedef struct			s_l
{
	char				*line;
	int					co;
	int					nb;
	int					x;
	int					y;
	int					curr;
}						t_l;

typedef struct			s_h
{
	char				*data;
	struct s_h			*next;
	short				nb;
	int					len;
}						t_h;

	void					ft_get_line(t_l *l, t_h **h);
	void					apply_termcap_str(char *str, int x, int y);
	void					delete_save_history(t_h **h);


void					print_semicolon_error(char *line);
void					print_is_dir(char *str);
void					print_no_cmd(char *str);
void					print_set_unset(char *str, int opt);
int						there_is_p(t_cmd *c);
int						there_is_d(t_cmd *c);
void					make_child_not_env(t_cmd *c, t_h **h);
void					make_child_env(t_cmd *c, char *path, t_h **h);
int						is_eof(char *line);
char					*is_in_path(t_cmd *c);
void					ft_pwd(void);
void					ft_echo(t_cmd *c);
void					ft_exit(t_cmd *comm, int opt, t_h **h);
void					ft_env(void);
void					ft_cd(t_cmd *c);
void					ft_unsetenv(t_cmd *c);
void					ft_setenv(t_cmd *c);
void					sig_controller(int option);
void					cmd_del(t_cmd *c);
char					*get_env(char *name, int keyval);
void					apply_t_d(t_cmd *c);
void					execute_cmd(t_cmd *c, char *patt, t_h **h);
void					parse_line(char **line, t_h **h);
void					get_prompt(void);
#endif
