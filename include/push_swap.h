/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:25:31 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/10 00:12:01 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <limits.h>
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

// Initialisation
int		mid_insertion(t_list *list, t_element *element, int nw_nbr);
t_list	*init_list(int nbr);
int		insert_list(t_list *list, int nbr);

// Parsing
t_list	*ft_parse(int ac, char **av);

// Sorting
void	sort_big_stack(t_list *a);
void	sort_small_stack(t_list *a);
void	sort_five(t_list *a);
void	sort_four(t_list *a);
void	sort_three(t_list *a, int smallest, int median, int greatest);
t_list	*sort_list(t_list *a);

// Operations
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);
void	pa(t_list *a, t_list *b);
void	pb(t_list *a, t_list *b);
void	ra(t_list *a);
void	rb(t_list *b);
void	rr(t_list *a, t_list *b);
void	rra(t_list *a);
void	rrb(t_list *b);
void	rrr(t_list *a, t_list *b);

// Utils
int		a_is_sorted(t_list *list);
void	swap_element(t_element *a, t_element *b);
void	nbr_pos(t_list *a);
void	attribute_order(t_list *to_order, t_list *sorted);
int		free_all_list(t_list *list);
void	show_list(t_list *list);
t_list	*copy_list(t_list *a);

#endif
