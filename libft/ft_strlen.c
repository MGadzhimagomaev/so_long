/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:39:17 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/12/24 15:11:12 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char *tests[] = {"", "Hello", "42 School", "   Lead sp", "Spec chr!@#"};
    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++)
    {
        printf("ft_strlen(\"%s\") = %zu, strlen(\"%s\") = %zu\n",
            tests[i], ft_strlen(tests[i]),
            tests[i], strlen(tests[i]));
    }
}//*/
