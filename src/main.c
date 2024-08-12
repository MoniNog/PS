/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:19:34 by moni              #+#    #+#             */
/*   Updated: 2024/08/12 14:17:30 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_stack	*new_node(int number)
{
	t_stack	*new;

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
	
	new->next = *stack_a;
	*stack_a = new;
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

void print_stack(t_stack *stack_a) {
	int index = 0;
	if (!stack_a) {
		printf("\033[1;34m┌───────────────┐\n"); // Rouge gras pour les en-têtes
		printf("│  \033[0;33mEmpty stack  \033[1;31m│\n"); // Jaune pour le texte
		printf("└───────────────┘\n"); // Reset du style
		printf("  * ** *** ** *  \033[0m\n"); // Reset du style
		return;
	}
	printf("\033[1;34m┌───────────────┐\n"); // Bleu gras
	printf("│    \033[1;34mStack A    \033[1;34m│\n"); // Vert pour le titre de la pile
	printf("└───────────────┘\n\033[1;34m");
	// printf("\033[0;34m  - .' ─┼─ '. -  \033[0;34m\n");
	printf("\033[1;34m┌─────┬─────────┐\n");
	printf("│ \033[1;91mInd \033[1;34m│  \033[1;37mValue  \033[1;34m│\n");
	printf("├─────┼─────────┤\n\033[0m");
	while (stack_a != NULL) {
		printf("\033[1;34m│ \033[\033[0;31m%2d  \033[1;34m│ \033[0m%5d   \033[1;34m│\n", index, stack_a->content);
		stack_a = stack_a->next;
		index++;
	}
	printf("└─────┴─────────┘\033[0m\n");
}

// void	print_stack(t_stack *stack_a)
// {
// 	int index = 0;
// 	if (!stack_a)
// 	{
// 		printf("┌───────────────┐\n");
// 		printf("│  Empty stack  │\n");
// 		printf("└───────────────┘\n");
// 		return;
// 	}
// 	printf("┌───────────────┐\n");
// 	printf("│    Stack A    │\n");
// 	printf("└───────────────┘\n\n");
// 	printf("┌─────┬─────────┐\n");
// 	printf("│ Ind │  Value  │\n");
// 	printf("├─────┼─────────┤\n");
// 	while (stack_a != NULL)
// 	{
// 		printf("│ %2d  │ %5d   │\n", index, stack_a->content);
// 		stack_a = stack_a->next;
// 		index++;
// 	}
// 	printf("└─────┴─────────┘\n");
// }

t_stack		*new_stack(void)
{
	t_stack		*stack_start;
	t_stack		*stack_next;
	t_stack		*stack_next_next;
	t_stack		*stack_last;

	stack_start = malloc(sizeof(t_stack));
	if (stack_start == NULL)// pourquoi on check pas a chaque fois ?
		return (NULL);

//	1 assiette
	stack_start->content = 3;

// 2 assiette
	stack_next = malloc(sizeof(t_stack));
	stack_start->next = stack_next;
	stack_next->content = 5;

// 3 assiette
	stack_next_next = malloc(sizeof(t_stack));
	stack_next->next = stack_next_next;
	stack_next_next->content = -1;

// 4 assiette (et derniere)
	stack_last = malloc(sizeof(t_stack));
	stack_next_next->next = stack_last;
	stack_last->content = 7;

// fin de la pile
	stack_last->next = NULL;

	return (stack_start);
}

int	main(void)
{
	t_stack	*stack_a;
	t_stack	*new_number;

	stack_a = new_stack();
	new_number = new_node(12);
	if(new_number)
		push(&stack_a, new_number); // moi javais ecris ca : push(**stack_a, (int)12); tu mexpliques pourquoi cest faux ?
	print_stack(stack_a);
	
	return (0);
}

// dans le stack_a, j'assigne la pile d'Elise (3,5,-1,7)