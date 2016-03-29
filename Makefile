# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#              #
#    Updated: 2016/02/26 13:50:50 by grass-kw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
DEBUG = no

### DIRECTORIES ###
DIRSRC	:= srcs
DIROBJ	:= obj
DIRINC	:= includes
DIRFT	:= libft

DIRMAIN 		:= $(DIRSRC)/main
DIRCOREUTILS 	:= $(DIRSRC)/coreutils
DIRPARSER 		:= $(DIRSRC)/parser
DIRPATH			:= $(DIRSRC)/path
DIRFTLONG		:= $(DIRSRC)/format_long

### FILES ###
HEAD	:= $(DIRINC)/$(NAME).h

include $(DIRMAIN)/sources.mk
include $(DIRCOREUTILS)/sources.mk
include $(DIRPARSER)/sources.mk
include $(DIRPATH)/sources.mk
include $(DIRFTLONG)/sources.mk

POBJ	:= $(addprefix $(DIROBJ)/, $(OBJ))

PFT	:= $(DIRFT).a

### COMPILATION VARIABLES ###
CC	:= gcc
ifneq ($(DEBUG),yes)
	C_FLAG	:= -Wall -Werror -Wextra -g
else
	C_FLAG	:= -Wall -Werror -Wextra
endif
C_INC	:= -I $(DIRINC) \
	-I $(DIRFT)/$(DIRINC)
L_FLAG	:= -L $(DIRFT) -lft

COMPIL	= @$(CC) -o $@ -c $< $(C_INC) $(C_FLAG)
LINK	= @$(CC) -o $@ $^ $(L_FLAG)

### RULES ###
.PHONY: all clean fclean re lldb
.SILENT:

all: $(PFT) $(NAME)
ifeq ($(DEBUG),yes)
	@echo "Generated in DEBUG mode"
else
	@echo "Generated in RELEASE mode"
endif

$(POBJ): |$(DIROBJ)

$(DIROBJ):
	mkdir $(DIROBJ)

$(NAME): $(POBJ)
	$(LINK)

### LIBS ###
$(PFT):
	@make -C $(DIRFT)

### MICS ###
clean:
	@rm -rf $(DIROBJ)

fclean: clean
	@rm -f $(NAME)
	@make -C $(DIRFT) fclean

re: fclean all

lldb: $(NAME)
	lldb $(NAME)

norme:
	@norminette $(SRCS)
	@norminette $(INC_PATH)
	@echo "[->] Total errors (May include object files) :" $(shell norminette $(NORM) | grep -v "Norme" | wc -l)

git:
	git add .
	echo "Please, enter your commit : "
	read root_path ; git commit -m "$$root_path"
	git push
