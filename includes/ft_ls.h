/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubard <jaubard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:16:56 by jaubard           #+#    #+#             */
/*   Updated: 2016/02/25 17:22:20 by jaubard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <pwd.h>
# include <time.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>

# define ALL 0x01
# define LONG 0x02
# define REVERSE 0x04
# define RECURSIVE 0x08
# define TIME 0x10
# define HIDE_GROUP 0x20
# define DISPLAY_ID 0x40
# define LIST_ALL_ENTRIES 0x80
# define BIRTH_DATE 0x100
# define INO_NUMBER 0x200

typedef struct		s_stat
{
	mode_t			st_dev;
	ino_t			st_ino;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	dev_t			st_rdev;
	struct timespec st_atimespec;
	struct timespec	st_mtimespec;
	struct timespec	st_ctimespec;
	struct timespec st_birthtimespec;
	off_t			st_size;
	quad_t			st_blocks;
	u_long			st_blksize;
	u_long			st_flags;
	u_long			st_gen;
}					t_stat;

typedef struct		s_path
{
	char			*elem;
	char			*link;
	t_stat			stat;
	struct s_path	*next;
}					t_path;

typedef struct		s_btree
{
	char			*name;
	t_stat			stat;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

typedef struct		s_env
{
	char			*path;
	char			*new_path;
	int				flags;
	t_path			*list_path;
	struct stat		*st;
	char			*tmp_path;
	char			*save_path;
	int				useful;
	int				nb_link_max;
	int				user_max;
	int				group_max;
	int				size_max;
	int				one_path;
	int				total;
	time_t			current_times;
	int				case_invalid;
	int				max_minor;
	int				max_major;
	int				max_ino;
}					t_env;

/*
*** coreutils
*/

int					insertion_sort(t_path **begin_path, t_path *new_elem,
		int (*cmp)(), t_env *e);
void				ft_path_add(t_path **begin_path, t_path *new_elem,
		t_env *e);
t_path				*ft_create_elem(char *elem, t_env *e);
void				ft_print_path(t_path *begin_path);
unsigned int		ft_path_size(t_path **begin_path);
void				ft_pathdel(t_path **begin_path);
void				ft_path_delone(t_path **alst);
void				set_flags(char option, t_env *e);
void				print_bit(unsigned int b, size_t n);
t_btree				*create_node(struct dirent *dp, t_env *e);
t_btree				*add_node(t_btree *root, t_btree *new_node, int(*cmp)());
int					compare_name(char *a, char *b);
int					compare_date(char *a, char *b);
void				display_btree(t_btree *root, void (*route)(t_btree *,
			t_env), t_env e);
void				route_suffix(t_btree *root, t_env e);
void				route_postfix(t_btree *root, t_env e);
int					flag_is_active(int test_bit, int flags);
void				destroyed_suffix(t_btree **root, t_env e);
void				destroyed_postfix(t_btree **root, t_env e);
t_stat				search_stat(t_btree *file, char *path);
char				*construct_path(char *path_racine, char *directory);
int					is_valid_directory(t_btree *file);
t_stat				search_stat(t_btree *file, char *path);
void				delete_node(t_btree **root);
void				delete_elem(char *elem, t_path **root);
char				*format_error(char *path);
void				print_path(char *path, t_env *e);
char				*get_file_name(char *path);
void				format_basic(char *path, t_env *e, t_stat st);
int					len_number(int nb);
void				set_stat_max(t_stat st, t_env *e);
void				initialize_max(t_env *e);
int					compare_date_path(t_path *a, t_path *b);
int					compare_date_btree(t_btree *a, t_btree *b);
int					compare_name_path(t_path *a, t_path *b);
int					compare_name_btree(t_btree *a, t_btree *b);
int					open_cached_directory(t_btree *file, t_env *e);
int					is_dot_directory(t_btree *file);
int					dot_including(t_env *e);
int					dot_dir_not_including(char *name, t_env *e);
int					is_cached(char *name);

/*
*** parser
*/

void				parser(t_env *e, char **av);
int					isfile(char *params);
void				active_flags(char *s, t_env *e);
int					is_option(char c);
void				invalid_option(char	*invalid);
void				mode_options(char **av, int *i, t_env *e);
void				mode_files(char **av, int *i, t_path **list_path);

/*
*** path
*/

void				find_all_path_files(t_env *e);
void				find_files(char *path, t_env e);
void				format(t_btree *root, t_env e);
void				display_files(t_btree *files, t_env *e);
void				destroyed_files(t_btree *files, t_env *e);
void				destroyed_postfix(t_btree **root, t_env e);
void				destroyed_suffix(t_btree **root, t_env e);
char				*construct_path(char *path_racine, char *directory);
void				file(t_env *e);

/*
*** format_long
*/

void				acl(t_stat st);
void				file_mode(t_stat st);
void				ft_file_type(t_stat st);
void				format_long(char *name, t_stat st, t_env *e);
void				ft_get_time(char *date);
void				group_name(t_stat st, t_env *e);
void				path_name(char *name, t_stat st, t_env *e);
void				last_modif(t_env *e, t_stat st);
void				number_of_bytes(t_stat st, t_env *e);
void				number_of_link(t_stat st, t_env *e);
void				owner_name(t_stat st, t_env *e);
void				ft_spaces_characteristics(int nb);
void				ft_long_permissions(t_stat st);

/*
*** bonus
*/

int					hide_group(t_env *e);
int					display_id(t_env *e);
int					compare_birth_path(t_path *a, t_path *b);
int					compare_birth_btree(t_btree *a, t_btree *b);
void				ino_number(t_stat st, t_env *e);

#endif
