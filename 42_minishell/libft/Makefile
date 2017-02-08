NAME=libft.a

CC=gcc

FLAGS=

HPATH=-I./includes

STRSRCDIR=strft/
CHARSRCDIR=charft/
INITSRCDIR=initialiseft/
ITOSSRCDIR=itosft/
IOSRCDIR=ioft/
INTSRCDIR=intft/
LSTSRCDIR=lstft/
MAPSRCDIR=mapft/
XSRCDIR=xft/
FTPRINTFSRCDIR=ft_printf/

CHARSRC=c_is_alnum.c \
		c_is_alpha.c \
		c_is_ascii.c \
		c_is_digit.c \
		c_is_lower.c \
		c_is_print.c \
		c_is_upper.c \
		c_to_lower.c \
		c_to_s.c \
		c_to_upper.c \

MAPSRC=s_s_map_value.c \
	   oo_map_getval.c \
	   oo_map_del.c \

INITSRC=buff_val.c \
		init_val.c \
		init_zero.c \
		f_alloc.c \
		b_all_zero.c \

INTSRC=i_in_iv.c  \
		i_numlen.c \
		i_tens.c \

IOSRC=ft_sssplit.c \
		get_line.c \
		get_next_line.c \
		put_error.c \
		p.c \
		pc.c \
		pc_fd.c \
		pl.c \
		pn.c \
		pn_fd.c \
		pnl.c \
		pnl_fd.c \
		ps.c \
		ps_fd.c \

ITOSSRC=f_to_s.c \
		i_to_s.c \
		my_limits.c \
		cval_to_s.c \
		long_to_s.c \
		longlong_to_s.c \
		i_to_s_base.c \
		short_to_s.c \
		zd_to_s_base.c \
		f_to_i.c \

LSTSRC=l_add.c \
		l_aggr.c \
		l_slice.c \
		l_push_sort.c \
		l_snap_after.c \
		l_init.c \
		l_chars.c \
		l_count.c \
		l_destroy.c \
		l_destroy_content.c \
		l_dup.c \
		l_each.c \
		l_filter.c \
		l_to_sv.c \
		l_filteri.c \
		l_first_by_index.c \
		l_goto.c \
		l_grab.c \
		l_grab_index.c \
		l_grab_ref.c \
		l_has.c \
		l_has_c.c \
		l_hop.c \
		l_index_pos.c \
		l_insert.c \
		l_last.c \
		l_map.c \
		l_new.c \
		l_previous.c \
		l_push.c \
		l_reduce.c \
		l_reduce_str.c \
		l_refindex.c \
		l_remove.c \
		l_reverse.c \
		l_split.c \


STRSRC=s_move.c \
		s_tail.c \
		s_between.c \
		s_bin_to_i.c \
		s_cat.c \
		s_char.c \
		s_clr.c \
		s_cmp.c \
		s_cpy.c \
		s_del.c \
		s_dup.c \
		s_has.c \
		s_equals.c \
		s_haschar.c \
		s_ifnull.c \
		s_inner.c \
		s_iter.c \
		s_iteri.c \
		s_join.c \
		s_len.c \
		s_map.c \
		s_mapi.c \
		s_n_cat.c \
		s_n_cmp.c \
		s_n_cpy.c \
		s_n_dup.c \
		s_n_equals.c \
		s_n_haschar.c \
		s_n_inner.c \
		s_nchar.c \
		s_new.c \
		s_nto_char.c \
		s_nto_inner.c \
		s_nto_pass_char.c \
		s_replace.c \
		s_split.c \
		s_squeeze.c \
		s_sub.c \
		s_to_i.c \
		s_trim.c \
		s_v_reduce.c \
		s_v_to_lst.c \
		sv_join.c \
		ws_to_s.c \

XSRC=x_del.c \
	stall.c \

FTPRINTFSRC=sf_add_formatter_attr.c \
		sf_add_size.c \
		ft_str_format.c \
		s_format.c \
		sf_get_from_void.c \
		sf_rgb.c \
		sf_decide.c \
		sf_get_arg.c \
		sf_get_arg_float.c \
		sf_get_arg_pointer.c \
		sf_get_formats.c \
		sf_get_num.c \
		sf_iter.c \
		sf_n_format.c \
		sf_n_sign.c \
		sf_number.c \
		sf_parse.c \
		sf_principal.c \
		sf_proto.c \
		sf_string.c \
		sf_structs_init.c \
		sf_get_str.c \
		sf_get_wstr.c \
		sf_get_char.c \
		sf_get_wchar.c \
		sf_put_if_mapped.c \
		sf_escape_codes.c \
		sf_color_put.c \
		sf_out.c \
		sf_save.c \
		ft_printf_fd.c \
		pf_fd_out.c \

FSTRSRC=$(join $(addsuffix $(STRSRCDIR), $(dir $(STRSRC))), $(STRSRC))
FINTSRC=$(join $(addsuffix $(INTSRCDIR), $(dir $(INTSRC))), $(INTSRC))
FINITSRC=$(join $(addsuffix $(INITSRCDIR), $(dir $(INITSRC))), $(INITSRC))
FIOSRC=$(join $(addsuffix $(IOSRCDIR), $(dir $(IOSRC))), $(IOSRC))
FITOSSRC=$(join $(addsuffix $(ITOSSRCDIR), $(dir $(ITOSSRC))), $(ITOSSRC))
FLSTSRC=$(join $(addsuffix $(LSTSRCDIR), $(dir $(LSTSRC))), $(LSTSRC))
FCHARSRC=$(join $(addsuffix $(CHARSRCDIR), $(dir $(CHARSRC))), $(CHARSRC))
FXSRC=$(join $(addsuffix $(XSRCDIR), $(dir $(XSRC))), $(XSRC))
FMAPSRC=$(join $(addsuffix $(MAPSRCDIR), $(dir $(MAPSRC))), $(MAPSRC))
FFTPRINTFSRC=$(join $(addsuffix $(FTPRINTFSRCDIR), $(dir $(FTPRINTFSRC))), $(FTPRINTFSRC))

G_SRC = $(INITSRC) $(STRSRC) $(CHARSRC) $(LSTSRC) $(INTSRC) $(ITOSSRC) $(IOSRC) $(XSRC) $(MAPSRC) $(FTPRINTFSRC)
GF_SRC = $(FINITSRC) $(FSTRSRC) $(FCHARSRC) $(FLSTSRC) $(FINTSRC) $(FITOSSRC) $(FIOSRC) $(FXSRC) $(FMAPSRC) $(FFTPRINTFSRC)
OBJDIR = ./objects/
G_OBJ = $(G_SRC:.c=.o)
OBJ= $(join $(addsuffix $(OBJDIR), $(dir $(G_SRC:.c=.o))), $(G_SRC:.c=.o))

QUIET=

$(NAME):
	$(QUIET)$(CC) $(FLAGS) -c $(GF_SRC) $(HPATH)
	$(QUIET)mkdir -p $(OBJDIR)
	$(QUIET)mv $(G_OBJ) $(OBJDIR)
	$(QUIET)ar rc $(NAME) $(OBJ)
	$(QUIET)ranlib $(NAME)

all: $(NAME)

clean:
	$(QUIET)rm -rf $(OBJ)
	$(QUIET)rm -rf $(OBJDIR)

fclean: clean
	$(QUIET)rm -f $(NAME)

re: fclean all
