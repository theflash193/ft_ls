MAIN	:= 	acl.c file_mode.c file_type.c format_long.c get_time.c \
			group_name.c long_symlink.c long_time.c major_minor_size.c \
			number_of_link.c owner_name.c spaces_characteristics.c \
			sticky_bit.c ino_number.c \

OBJ	:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRFTLONG)/%.c $(HEAD)
	$(COMPIL)
