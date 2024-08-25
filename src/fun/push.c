/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:53:45 by moni              #+#    #+#             */
/*   Updated: 2024/08/25 21:24:02 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void		ppush(t_stack **dest, t_stack **src)
{
	t_stack		*node_to_push;

	if (*src == NULL)
		return;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_stack **a, t_stack **b)// PUSH B - Prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
{
	ppush(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)// PUSH B - Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
{
	ppush(b, a);
	write(1, "pb\n", 3);
}

