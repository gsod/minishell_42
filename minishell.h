/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsodano <gsodano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:30:17 by rpoggi            #+#    #+#             */
/*   Updated: 2023/05/19 15:46:17 by gsodano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <limits.h>
# include <sys/wait.h>
# include <stddef.h>
# include <sys/stat.h>
# include <signal.h>
# include <dirent.h>
# include <stdbool.h>

extern int	g_exitstatus;

typedef struct env_var
{
	char	*name;
	char	*value;
}	t_env_var;

typedef struct env_list
{
	t_env_var		*var;
	struct env_list	*next;
}	t_env_list;

typedef struct s_info
{
	bool	myexit;
	char	**pipe_mat;
	char	**space_mat;
	char	*input;
	int		*ascii;
	char	**path;
	pid_t	pid_execve;
	pid_t	pid_display;
	int		pipes[2];
	char	*exp;
	int		num_com;
	char	*tmp_exp;
	char	*ret_exp;
	int		flag;
	int		end_word_hedoc;
	int		disp_flag;
	int		disp_aux;
	int		mystd_in;
	int		**hedoc_fd;
	char	*delim;
	char	*line;
	int		status;
	char	**myenvp;
	int		std_in_copy;
	bool	yespipe;
	bool	nopipe;
	int		std_out_copy;
	int		ascii_s;
	int		**redir_fd;
}				t_info;

void	display_prompt(t_info *info);
char	**envp_cop(char **envp);
int		ft_cd(char *args, t_info *info);
void	free_int(int **mat, t_info *info);
int		ft_echo(t_info *info);
char	*check_echo(char *args, int i, int j, char *tmp);
void	no_pipe2(t_info *info, int bob, int j);
void	rl_replace_line(const char *text, int clear_undo);
void	ft_ctrlc(char **envp);
void	ft_signal(void);
int		ft_unset(t_info *info);
void	ft_sigint(int sig);
void	no_pipe(t_info *info, int bob, int j, int tmp);
int		aux_export1(t_info *info, int i, int j);
void	aux_export2(t_info *info, int i, int j, char *key);
int		aux_export3(t_info *info, int i, int j);
void	aux_export4(t_info *info, char **newenv, int *i);
void	main_while(t_info *info);
int		ft_execve(t_info *info, int i, int j, int status);
char	*aux_execve(t_info *info, int *j);
int		aux_execve4(t_info *info);
int		aux_execve2(t_info *info, char *str, int status, pid_t *pid);
int		aux_execve3(t_info *info, char *str);
void	ft_shlvl(t_info *info);
void	ft_pwd(void);
int		ft_execution(char **input, char *bin, char **envp);
void	print_env(void);
char	**ft_path(char *pathvar);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	splitting(t_info *info, char *input);
void	path_abs(char *input, char **envp);
char	*mytrimmer(char *str, char c);
int		ft_builtin(t_info *info);
int		len_funct(const char *str, char c);
int		skipper(const char *s, int i, char c);
int		counter(const char *s, char c);
int		check_input_ap(t_info *info);
int		check_input_pipe(t_info *info, int c);
int		check_input_red(t_info *info, int c);
int		checker_space(t_info *info);
char	*get_env_var(char	*var_name);
void	set_env_var(const char *var_name, const char *value);
void	free_matrix(char **matrix);
char	**ft_add_envp(t_info *info, char *key, int arg);
void	aux_unset(t_info *info, int *j, int *unset);
char	*ft_analyzer_input(char **input, char **envp);
char	*search_in_envp(char **envp, char *str);
int		ft_exit(char **input, t_info *info);
int		ft_env(char **envp);
int		ft_mystrchr(char *s, char c);
int		ft_export(t_info *info);
char	**ft_sort(char **envp);
int		redirec(t_info *info, int i, int j);
int		input_redir(t_info *info, int i, int j);
int		db_output_redir(t_info *info, int i, int j);
int		output_redir(t_info *info, int i, int j);
int		ft_delim_rep(t_info *info, int i);
int		output_rep(t_info *info, int i);
int		ft_input_rep(t_info *info);
int		ft_doutput_rep(t_info *info, int i, int j);
int		ft_space_replace(t_info *info);
char	*read_heredoc(char *delimiter);
int		heredoc(t_info *info, int i, int j);
int		ft_isalnum(int c);
char	*first_word(char *str);
void	ft_quotes(char **envp);
char	*expander(char *str, int i);
char	*sostitution(t_info *info, char *str, char *exp, int i);
void	free_mat(char **mat);
char	*ft_strtrim(char const *s1, char const *set);
char	**smartsplit(const char *s, char c);
int		ft_add_variable(t_info *info, int i, char *key, int j);
int		aux_trimmer(char *str, int i, char c, int new);
void	yes_pipe3(t_info *info);
void	yes_pipe4(t_info *info, int i);
void	yes_pipe5(t_info *info, int i);
void	yes_pipe6(t_info *info, int bob, int j, int tmp);
void	yes_pipe7(t_info *info, int i);
void	aux_redirection4(t_info *info, int i, int *j);
int		aux_redirection2(t_info *info, int i, int j);
int		aux_redirection1(t_info *info, int *i, int *j);
void	aux_redirection3(t_info *info, int *i, int *j);
void	heredoc_aux5(t_info *info, int i, int *j);
void	heredoc_aux4(t_info *info, int *i, int *j);
void	heredoc_aux3(t_info *info, int j, int i, int *c);
void	heredoc_aux2(t_info *info, int j, int i, int *c);
int		heredoc_aux1(t_info *info, int i, int j);
void	aux_nopipe1(t_info *info);
void	aux_nopipe2(t_info *info, int *j, int *aux, int *flag);
void	aux_nopipe3(t_info *info, int *bob, int j, int *tmp);
void	display_prompt2(t_info *info, int i);
char	*aux_exp(t_info *info, char *str, char *exp, int i);
int		ft_space_replace(t_info *info);
void	yes_pipe(t_info *info, int i, int bob, int tmp);
char	*mytrimmer2(char *str);
int		how_many(char *str, char c);
int		find_first_between(char *str);
int		main_while_aux(t_info *info, int z);
int		check_main_aux(t_info *info, int i);
int		check_main_while_2(t_info *info, int i);
void	check_main_while_3(t_info *info, int *i, int *c);
void	aux_display2(t_info *info);
int		aux_display(t_info *info, int bob, int j, int tmp);
void	aux_disp_pr2(t_info *info, int *bob, int *j, int *tmp);
void	aux_disp_pr3(t_info *info, int i);
void	aux_disp_pr4(t_info *info, int *j, int *bob, int *tmp);
void	aux_disp_pr(t_info *info, int j, int *bob);
int		check_input_red2(int c);
void	check_input_red3(t_info *info, int *i, int *c);
void	mytrimmer2_aux(char *str, char *ret, int *i, int *j);
#endif