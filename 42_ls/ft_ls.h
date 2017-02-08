/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 16:40:59 by dan               #+#    #+#             */
/*   Updated: 2016/10/19 14:54:09 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include "libft.h"
# include <sys/ioctl.h>

# define LS_NO_GRID 0
# define LS_DIFF 0
# define EMPTY_STR ""
# define LS_DIR_COLOUR "\e[38;5;214m\e[1m"
# define LS_REG_COLOUR "\e[38;5;7m"
# define LS_EXC_COLOUR "\e[1m\e[38;5;28m"
# define LS_LINK_COLOUR "\e[1m\e[38;5;32m"
# define LS_BLOCK_DEVICE_COLOUR "\e[48;5;184m\e[38;5;16m"
# define LS_DEVICE_COLOUR "\e[48;5;42m\e[38;5;16m"
# define LS_PIPE_COLOUR "\e[38;5;121m"
# define LS_END_COLOUR "\e[0m"
# define LS_INFO_NODE(a) CONTENT_OF(a, t_ls_info *)
# define LS_INFO_DEL(a)

char				*stringer(void *obj);
typedef int			(*t_sorter)(void *, void *);
typedef struct		s_ls_sorters
{
	t_sorter		alpha;
	t_sorter		time;
}					t_ls_sorters;

enum				e_ls_types
{
	LS_BLOCK_DEVICE,
	LS_DEVICE,
	LS_UNKNOWN = 99,
};

enum				e_ls_error
{
	FLAG_ERROR,
};

typedef struct		s_ls_info
{
	char			*colour;
	char			*filename;
	char			*fullname;
	char			*sym_link_to;
	nlink_t			link_count;
	time_t			date_modified;
	struct timespec	date_modified_spec;
	struct timespec date_accessed_spec;
	struct timespec birth_spec;
	struct timespec status_spec;
	char			*date_modified_str;
	char			*permissions;
	char			*group_name;
	char			*user_name;
	char			*size_str;
	mode_t			mode;
	int				size;
	int				major;
	int				minor;
	size_t			filename_len;
	size_t			blocks;
}					t_ls_info;

void				ls_out_colour(t_list *runner, int min_width, int no_grid);
int					get_link_len(t_list *x);
void				ls_set_permissions(t_ls_info **info,
					struct stat *stats, int is_link);
void				ls_set_date(char **date_str_p, long date_ticks);
void				ls_put_longform(t_list *l, int hide, int faff);
void				sort_dirs_initial(t_list **dirs, t_list *flags);
size_t				ls_get_cols(void);
void				ls_set_cols(t_list *flags);
t_list				*ls_get_sub_dirs2(t_ls_info **info,
					t_list **ls_info_list, t_list *flags);
void				ls_info_del(t_ls_info **x);
int					month(char *s);
int					ls_alpha_sort_proto(void *curr, void *next, int rev);
t_list				*ls_reader2(t_ls_info **dir_head, t_list *flags, int is_x);
t_list				*get_dirs(t_list *lav);
t_list				*get_flags(t_list *lav);
void				iterate_read2(t_list **dirs, t_list *flags, int is_multi);
size_t				ls_get_cols(void);
void				ls_grid(t_list *l, t_list *flags);
void				ls_put_grid(t_list *l, int x, int min_width);
t_list				*l_init_env(char **env);
char				*get_env_var(t_list *env_lst, char *key);
void				put_info(char *path_str, t_list *l, t_list *flags, int x);
char				*join_dirs(char *arg1, char *arg2);
t_list				*ls_is_sub_dir(t_list *ls_info_list);
t_list				*ls_is_not_secret_sub_dir(t_list *a);
t_list				*l_new_ls_info(char *dir_name,
					char *filename, int fn_len, t_list *flags);
t_sorter			get_sorter(t_list *sort_flags);
void				dir_error(char *dir_attempt);
void				*flag_error(char flag_attempt);
char				*permission_str(mode_t mode,
					int is_link, int is_acl, int is_attr);
int					ls_alpha_sort(void *curr, void *next);
int					ls_alpha_sort_rev(void *curr, void *next);
int					ls_time_sort(void *curr, void *next);
int					ls_time_sort_rev(void *curr, void *next);
#endif
