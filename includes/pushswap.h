/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:13:16 by moni              #+#    #+#             */
/*   Updated: 2024/08/25 21:23:10 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct	s_info
{
	int			ac;
}				t_info;

void	free_stack(t_stack *stack);
t_stack	*new_node(char *av);
void	push(t_stack **stack_a, t_stack *new);
void	push_back(t_stack **stack_a, t_stack *new);
t_stack		*pop(t_stack **stack);
void		ppush(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);


#endif
