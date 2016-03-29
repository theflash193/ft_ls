MAIN	:=	find_all_path_files.c find_files.c display_files.c \
			destroyed_files.c \

OBJ	:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRPATH)/%.c $(HEAD)
	$(COMPIL)
