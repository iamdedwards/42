# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/03 13:57:50 by dedwards          #+#    #+#              #
#    Updated: 2016/11/07 14:36:04 by dedwards         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=ms_env_key_vals.c \
	ms_env_sv.c \
	ms_env_val_set2.c \
	ms_env_val_set.c \
	ms_is_file.c \
	ms_filter.c \
	ms_complete_command.c \
	ms_find_command.c \
	ms_create_selection_array.c \
	ms_next_selection.c \
	ms_set_termios.c \
	ms_args.c \
	ms_destroy_ctx.c \
	ms_escape.c \
	ms_format.c \
	env.c \
	dict.c \
	sv_del.c \
	ms_buff.c \
	ms_buff2.c \
	ms_buff_len.c \
	ms_cd.c \
	ms_echo.c \
	ms_cursor_end_index.c \
	ms_end.c \
	ms_env.c \
	ms_erase.c \
	ms_erase_put.c \
	ms_execute.c \
	ms_binary_exists.c \
	ms_set_shlvl.c \
	ms_exit.c \
	ms_get_cols.c \
	ms_get_files.c \
	ms_get_line.c \
	ms_history.c \
	ms_home.c \
	ms_init_cmds.c \
	ms_init_keymap.c \
	ms_insert_var.c \
	ms_lattr.c \
	ms_loop.c \
	ms_main.c \
	ms_move_in_line.c \
	ms_reader.c \
	ms_reader_signal_handlers.c \
	ms_reader_write.c \
	ms_reduce_buffs.c \
	ms_reduce_line.c \
	ms_remove_select_values.c \
	ms_s_clean.c \
	ms_script.c \
	ms_set_sig_interrupt.c \
	ms_setenv.c \
	ms_tab.c \
	ms_selection.c \

NAME=minishell
CC=gcc -Wall -Wextra -Werror
HPATH=-I./includes -I./libft/includes
INCPATH=-L./libft
LIBS=-lft -ltermcap
DSRC=$(join $(addsuffix src/, $(dir $(SRC))), $(SRC))
PROGRAM=minishell
OBJ=$(SRC:.c=.o)

$(NAME):
	make re -s -C libft
	$(CC) $(FLAGS) $(HPATH) -c $(DSRC)
	$(CC) -o $(PROGRAM) $(OBJ) $(INCPATH) $(LIBS)
	mkdir -p objects
	mv $(OBJ) objects

re: fclean $(NAME)

clean:
	rm -rf objects
fclean: clean
	rm -rf objects
	rm -rf $(NAME)
	make fclean -C libft
