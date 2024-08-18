/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:19:34 by moni              #+#    #+#             */
/*   Updated: 2024/08/18 20:11:16 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

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

void	print_stack(t_stack *stack_a) {
	int index = 1;
	if (!stack_a)
	{
		printf("\033[1;34m┌───────────────┐\n");
		printf("│  \033[0;33mEmpty stack  \033[1;31m│\n");
		printf("└───────────────┘\n");
		printf("  * ** *** ** *  \033[0m\n");
		return;
	}
	printf("\033[1;34m┌───────────────┐\n");
	printf("│    \033[1;34mStack A    \033[1;34m│\n");
	printf("└───────────────┘\n\033[1;34m");
	printf("\033[1;34m┌─────┬─────────┐\n");
	printf("│ \033[1;91mInd \033[1;34m│  \033[1;37mValue  \033[1;34m│\n");
	printf("├─────┼─────────┤\n\033[0m");
	while (stack_a != NULL)
	{
		printf("\033[1;34m│ \033[\033[0;31m%2d  \033[1;34m│ \033[0m%5d   \033[1;34m│\n", index, stack_a->content);
		stack_a = stack_a->next;
		index++;
	}
	printf("└─────┴─────────┘\033[0m\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*new_number;
	int		i;
	
	if (ac > 1)
	{
		stack_a = new_node(av[1]);
		i = 2;
		while (i != ac)
		{
			new_number = new_node(av[i]);
			if(new_number)
				push_back(&stack_a, new_number); // moi javais ecris ca : push(**stack_a, (int)12); tu mexpliques pourquoi cest faux ?
			i++;
		}
		print_stack(stack_a);
	}
	return (0);
}
