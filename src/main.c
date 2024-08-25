/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:19:34 by moni              #+#    #+#             */
/*   Updated: 2024/08/25 21:23:51 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"


// void	print_stack(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	index;

// 	index = 1;
// 	if (!stack_a)
// 	{
// 		printf("\033[1;34m┌───────────────┐\n");
// 		printf("│  \033[0;33mEmpty stack  \033[1;31m│\n");
// 		printf("└───────────────┘\n");
// 		printf("  * ** *** ** *  \033[0m\n");
// 		return;
// 	}
// 	printf("\033[1;34m┌───────────────┐\t┌───────────────┐\n");
// 	printf("│    \033[1;34mStack A    \033[1;34m│\t");
// 	printf("│    \033[1;34mStack B    \033[1;34m│\n");
// 	printf("└───────────────┘\t└───────────────┘\n\033[1;34m");
// 	printf("\033[1;34m┌─────┬─────────┐\t┌─────┬─────────┐\n");
// 	printf("│ \033[1;91mInd \033[1;34m│  \033[1;37mValue  \033[1;34m│\t");
// 	printf("│ \033[1;91mInd \033[1;34m│  \033[1;37mValue  \033[1;34m│\n");
// 	printf("├─────┼─────────┤\t├─────┼─────────┤\n\033[0m");
// 	while (index < 10)
// 	{
// 		printf("\033[1;34m│ \033[\033[0;31m%2d  \033[1;34m│ \033[0m%5d   \033[1;34m│\t", index, stack_a->content);
// 		if (stack_b)
// 			{
// 				printf("│ \033[\033[0;31m%2d  \033[1;34m│ \033[0m%5d   \033[1;34m│\n", index, stack_b->content);
// 				stack_b = stack_b->next;
// 			}
// 		else
// 			printf("│     │         │\n");
// 		stack_a = stack_a->next;
// 		index++;
// 	}
// 	printf("└─────┴─────────┘\t└─────┴─────────┘\033[0m\n");
// }

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int			index;
	// t_stack		*start_a;
	// t_stack		*start_b;

	// start_a = stack_a;
	// start_b = stack_b;

	index = 1;
	if (!stack_a)
	{
		printf("\033[1;34m┌───────────────┐\n");
		printf("│  \033[0;33mEmpty stack  \033[1;31m│\n");
		printf("└───────────────┘\n");
		printf("  * ** *** ** *  \033[0m\n");
		return;
	}
	printf("\033[1;34m┌───────────────┐\t┌───────────────┐\n");
	printf("│    \033[1;34mStack A    \033[1;34m│\t");
	printf("│    \033[1;34mStack B    \033[1;34m│\n");
	printf("└───────────────┘\t└───────────────┘\n\033[1;34m");
	printf("\033[1;34m┌─────┬─────────┐\t┌─────┬─────────┐\n");
	printf("│ \033[1;91mInd \033[1;34m│  \033[1;37mValue  \033[1;34m│\t");
	printf("│ \033[1;91mInd \033[1;34m│  \033[1;37mValue  \033[1;34m│\n");
	printf("├─────┼─────────┤\t├─────┼─────────┤\n\033[0m");
	while (index < 10)
	{
		if (stack_a)
		{
			printf("\033[1;34m│ \033[\033[0;31m%2d  \033[1;34m│ \033[0m%5d   \033[1;34m│\t", index, stack_a->content);
			stack_a = stack_a->next;
		}
		else
			printf("│     │         │\n");
		if (stack_b)
		{
			printf("│ \033[\033[0;31m%2d  \033[1;34m│ \033[0m%5d   \033[1;34m│\n", index, stack_b->content);
			stack_b = stack_b->next;
		}
		else
			printf("│     │         │\n");
		index++;
	}
	printf("└─────┴─────────┘\t└─────┴─────────┘\033[0m\n");
}


int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*new_number;
	int		i;
	char	*nb;

	stack_a = NULL;
	stack_b = NULL;
	
	if (ac > 1)
	{
		stack_a = new_node(av[1]);
		i = 2;
		while (i < ac)
		{
			new_number = new_node(av[i]);
			if (new_number)
				push_back(&stack_a,new_number);
			i++;
		}
		nb = "14444";
		print_stack(stack_a, stack_b);
		push(&stack_b, new_node(nb));
		print_stack(stack_a, stack_b);
		pa(&stack_a, &stack_b);
		print_stack(stack_a, stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		print_stack(stack_a, stack_b);
		

		// pop(&stack_a);
		// print_stack(stack_a, stack_b);
		// pop(&stack_a);
		// print_stack(stack_a, stack_b);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	
	return (0);
}
