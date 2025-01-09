/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picsou06 <picsou06@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:27:28 by picsou06          #+#    #+#             */
/*   Updated: 2025/01/09 20:27:41 by picsou06         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
