/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:49:37 by moni              #+#    #+#             */
/*   Updated: 2024/08/19 17:02:16 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

t_stack	*new_node(char *av)
{
	t_stack		*new;
	int			number;

	number = ft_atoi(av);
	new = malloc(sizeof(t_stack));
	if(!new)
		return NULL;
	new->content = number;
	new->next = NULL;
	return (new);
}

void	push(t_stack **stack_a, t_stack *new)
{
	if (!new)
		return ;
	if (!*stack_a)
	{
		*stack_a = new;
		return;
	}
	new->next = *stack_a;
	*stack_a = new;
}

void	push_back(t_stack **stack_a, t_stack *new)
{
	t_stack *temp;

	if (!*stack_a)
	{
		*stack_a = new;
		return;
	}
	temp = *stack_a;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

void	pop(t_stack **stack_a)
{
	t_stack	*tmp;

	if (stack_a != NULL)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;// pourquoi (*stack_a)->next et pas *stack_a->next ?
		free(tmp);
	}
}