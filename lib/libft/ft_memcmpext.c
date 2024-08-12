/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmpext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:21:20 by moni              #+#    #+#             */
/*   Updated: 2024/05/28 15:15:10 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// Compare l'extension du fichier.
// Retourne true (1) si identiques, false (0) sinon.

int ft_memcmpext(const void *s1, char *extension)
{
	const unsigned char *ptr_s1;
	const unsigned char *ptr_extension;
	size_t len_s1;
	size_t len_ext;
	size_t n;

	len_s1 = ft_strlen(s1);
	len_ext = ft_strlen(extension);
	n = len_ext;
	ptr_s1 = (const unsigned char *)s1 + len_s1 - 1;
	ptr_extension = (const unsigned char *)extension + len_ext - 1;
	if (len_s1 < n)
		return (0);
	while (n > 0)
	{
		if (*ptr_s1 != *ptr_extension)
			return (0);
		ptr_s1--;
		ptr_extension--;
		n--;
	}
	return (1);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 3)
// 	{
// 		printf("Usage: %s <string1> <extension>\n", argv[0]);
// 		return EXIT_FAILURE;
// 	}
// 	bool result = ft_memcmpext(argv[1], argv[2]);
// 	printf("Result: %d\n", result);
// 	return 0;
// }
