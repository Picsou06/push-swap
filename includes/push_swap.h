#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

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

t_list	*ft_parse(int ac, char **av);
void	show_list(t_list *list);


#endif
