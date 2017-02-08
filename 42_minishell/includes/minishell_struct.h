/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:17:56 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 14:26:05 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H
# include "libft.h"

typedef struct			s_dictionary
{
	t_list				*keys;
	t_list				*values;
}						t_dictionary;

typedef struct			s_ms_signals
{
	int					interrupt;
	int					eof;
}						t_ms_signals;

typedef struct			s_ms_ctx
{
	int					prompt_colour;
	t_ms_signals		signals;
	t_dictionary		key_map;
	t_dictionary		shell_var;
	t_dictionary		xkey_map;
	t_dictionary		cmds;
	t_dictionary		env;
	char				**env_as_sv;
	t_list				*history;
	t_list				*curr_files;
	t_list				*binary_files;
	char				**args;
}						t_ms_ctx;

typedef struct			s_ms_input_selector
{
	int					term_width_at_creation;
	int					current_value_grid;
	int					start_index;
	int					len;
	int					div_count;
	int					height;
	int					width;
	int					min_width;
	int					selected;
	t_list				*values;
	t_list				*value_grids;
	int					overwrite;
}						t_ms_input_selector;

typedef struct			s_ms_input
{
	int					xxkey;
	int					prompt_pos;
	int					height;
	int					curr_pos;
	int					buff_allocs;
	int					current_div;
	int					insert_mode;
	int					delete_mode;
	int					insert_index;
	long long			total_len;
	t_list				*str_div;
	char				**line;
	char				*match;
	int					select_mode;
	t_ms_input_selector	select;
	t_ms_ctx			*ctx;
}						t_ms_input;

typedef struct			s_ms_file
{
	char				*name;
	mode_t				mode;
}						t_ms_file;
#endif
