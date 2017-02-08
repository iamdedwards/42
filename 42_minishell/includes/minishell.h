/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 13:07:49 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 13:32:52 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/wait.h>
# include "libft.h"
# include <termios.h>
# include <signal.h>
# include <termios.h>
# include <term.h>
# include <time.h>
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include "minishell_struct.h"
# define MS_UNDEF  0
# define MS_CAN_EXEC  1
# define MS_CANT_EXEC  1
# define MS_FILE  2
# define MS_DIR  3
# define MS_FAKE_TAB (char[]){' ', ' ', ' ', ' ', 0}
# define MS_BUFF_SIZE 1024

t_list				*l_s_n_equals(t_list *x, void *args);
t_list				*l_s_inner(t_list *x, void *args);

void				ms_buff_len_check(t_ms_input *input);
void				ms_overwrite(t_ms_input *input, char *s);
void				ms_find_exec(t_ms_ctx *ctx);
void				ms_set_termios(int on_off);
void				ms_new_selection_div(t_ms_input *input);
void				sv_del(char ***sv);

void				ms_set_sig_interrupt(int n);
t_ms_ctx			*ms_get_ctx(void);
void				ms_set_ctx(t_ms_ctx *ctx, char **env);
void				ms_env_node_del(void **env_values_as_list);
void				ms_destroy_ctx(t_ms_ctx *ctx);
void				ms_env_node_del(void **x);
void				ms_destroy_input(t_ms_input *input);

void				ms_loop(t_ms_ctx *ctx);
char				**ms_args(t_ms_ctx *ctx, char *s);
void				ms_s_clean(char **s);
int					ms_script(t_ms_ctx *ctx, char *ln);
int					ms_is_file(char *filename);
void				ms_free_ctx_args(t_ms_ctx *ctx);
int					ms_execute(t_ms_ctx *ctx);
int					ms_binary_exists(t_ms_ctx *ctx, char *filename);
int					ms_is_minishell_exec(t_ms_ctx *ctx);
void				ms_set_shlvl(t_ms_ctx *ctx, int inc_dec);
int					ms_vertical_pos(void);

void				ms_refresh_selection_div(t_ms_input *input);

void				ms_print_selection_grids(t_ms_input *input, int len);

char				*ms_get_line(t_ms_ctx *ctx);
void				ms_s_clean(char **s);
void				ms_alloc_buff(t_ms_input *input, char *content);
char				*ms_fresh_buff(t_ms_input *input);
void				ms_erase_put(t_ms_input *input, int addition_len);
void				ms_reader(t_ms_input *input);
void				ms_insert_var(t_ms_ctx *ctx, char **ln);
void				ms_reader_write(t_ms_input *input, char *buff);
void				ms_create_selection_array(t_ms_input *input, t_list *values,
					int len);
void				ms_calc_selection_height(t_ms_input *input, t_list *values);
int					ms_remove_select_values(t_ms_input *input);
void				ms_destroy_select_values(t_ms_input *input);
void				ms_trunc_select(t_ms_input *input);
int					ms_cursor_end_index(t_ms_input *input);

void				ms_reduce_current_buff(t_ms_input *input);
t_list				*ms_current_buff_node(t_ms_input *input);
char				*ms_current_buff(t_ms_input *input);
void				ms_append(t_ms_input *input, char *s, int offset);
void				ms_clear_buffs(t_ms_input *input);

typedef void		(*t_ms_input_func)(t_ms_input *);
void				ms_init_keymaps(t_ms_ctx *ctx);
void				ms_sig_interupt(t_ms_input *input);
void				ms_sig_eof(t_ms_input *input);
void				ms_reduce_line(t_ms_input *input);
void				ms_erase (t_ms_input *input);
void				ms_tab (t_ms_input *input);
void				ms_escape (t_ms_input *input);
void				ms_up (t_ms_input *input);
void				ms_down (t_ms_input *input);
void				ms_left (t_ms_input *input);
void				ms_right (t_ms_input *input);
void				ms_home (t_ms_input *input);
void				ms_end (t_ms_input *input);

int					ms_complete_command(t_ms_input *input);
int					ms_find_command(t_ms_input *input);
void				ms_next_selection(t_ms_input *input);
typedef int			(*t_ms_cmd)();
void				ms_init_cmds(t_ms_ctx *ctx);
int					ms_cd();
int					ms_echo();
int					ms_exit();
int					ms_setenv();
int					ms_env();
int					ms_unsetenv();
int					ms_export();

int					ms_env_val_set_proto(t_ms_ctx *ctx,
					char *key, char *val, int cat);
void				ms_set_binary_files(t_ms_ctx *ctx);
void				ms_set_curr_files(t_ms_ctx *ctx);
int					ms_alpha_sort(void *curr, void *next);

typedef void		(*t_ms_env_val_setter)(t_list **, t_list *);
void				ms_env_unset_val(t_ms_ctx *ctx, char *key);
void				dict_xset_val(t_dictionary *env_dict, char *key, void *val);
int					ms_get_cols(void);
int					ms_buffs_len(t_ms_input *input);
t_list				*ms_env_get_list(t_dictionary env_dict, char *key);
char				*ms_env_get_str(t_dictionary env_dict, char *key);
void				ms_env_xset_val(t_ms_ctx *ctx, char *key, void *val);
void				ms_env_cat_val(t_ms_ctx *ctx, char *key, void *valo);
t_dictionary		dict_init(void ***vals);
void				ms_prompt();
void				ms_zprompt(t_ms_ctx *ctx);
void				s_clear(char *ln, size_t size);
void				*dict_get_val(t_dictionary env_dict, char *key);
void				dict_set_val(t_dictionary *env_dict, char *key, void *val);
void				s_clean(char **s);
char				**ms_env_sv(t_dictionary dict);
void				ms_env_v_to_dict(t_dictionary *dict, char **env);
void				ms_set_env_val(t_dictionary *env_dict, char *key,
					char *val);
void				ms_init_env(t_ms_ctx *ctx, char **env);
int					ms_env_key_vals(t_dictionary *env, char *key,
					t_list **keys, t_list **values);
#endif
