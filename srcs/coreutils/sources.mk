MAIN	:= ft_path_add.c create_elem.c ft_print_path.c insertion_sort.c \
			ft_path_size.c ft_pathdel.c ft_path_delone.c is_option.c \
			set_flags.c print_bit.c create_node.c route_postfix.c \
			route_suffix.c display_btree.c flag_is_active.c add_node.c \
			compare_date.c compare_name.c format.c search_stat.c \
			construct_path.c is_valid_directory.c delete_node.c \
			delete_elem.c format_error.c print_path.c \
			get_file_name.c file.c format_basic.c set_stat_max.c is_cached.c \
			is_bonus.c \

OBJ	:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRCOREUTILS)/%.c $(HEAD)
	$(COMPIL)
