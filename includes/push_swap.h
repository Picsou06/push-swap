#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_element
{
	int					nbr;
	int					pos;
	struct s_element	*next;
}						t_element;

typedef struct s_list
{
	t_element	*first;
	int			nb_elem;
}				t_list;

#endif
