CC=gcc
FLAGS=-Wall -Wextra -Werror
MAKEOBJ=-c
COMPOBJ=-o
NAME=ft_ls
HPATH=-I./libft/includes
INCPATH=-L./libft
LIBS=-lft

SRC=env_getter.c \
	ls_flag_error.c \
	ls_set_date.c \
	ft_ls.c \
	ls_get_sorter.c \
	ls_is_sub_dir.c \
	ls_alpha_sort.c \
	ls_alpha_sort_proto.c \
	ls_get_input.c \
	ls_set_permissions.c \
	ls_iterate_read.c \
	ls_month.c \
	ls_put_grid.c \
	ls_reader.c \
	ls_time_sort.c \
	ls_new_info.c \
	ls_permission_str.c \
	ls_put_info.c \
	ls_l_info_del.c \
	ls_sort_dirs_initial.c \
	ls_get_cols.c \
	ls_get_sub_dirs.c \
	ls_put_longform.c \
	ls_get_link_len.c \

OBJS_BASE=$(SRC:.c=.o)
OBJDIR = ./objects/
OBJS=$(join $(addsuffix $(OBJDIR), $(dir $(OBJS_BASE), $(OBJS_BASE))))
LIBFTDIR=libft

$(NAME):
	make re -C $(LIBFTDIR)
	$(CC) $(HPATH) $(MAKEOBJ) $(SRC)
	$(CC) $(COMPOBJ) $(NAME) $(OBJS_BASE) $(HPATH) $(INCPATH) $(LIBS) $(FLAGS)
	mkdir -p $(OBJDIR)
	mv $(OBJS_BASE) $(OBJDIR)

compile:
	$(CC) $(HPATH) $(MAKEOBJ) $(SRC)
	$(CC) $(COMPOBJ) $(NAME) $(OBJS_BASE) $(HPATH) $(INCPATH) $(LIBS) $(FLAGS)
	mkdir -p $(OBJDIR)
	mv $(OBJS_BASE) $(OBJDIR)

re : fclean $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean : clean
	rm -rf  $(NAME)
