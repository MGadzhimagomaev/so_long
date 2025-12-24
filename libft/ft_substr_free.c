/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:58:39 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/12/24 17:05:20 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_free(char const *s, unsigned int start, size_t len,
			int to_free)
{
	char	*output;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	output = (char *)ft_calloc(len + 1, sizeof(char));
	if (!output)
		return (NULL);
	ft_strlcpy(output, s + start, len);
	if (to_free == 1)
		free((void *)s);
	return (output);
}
/*
#include <stdio.h>

int	main(void)
{
	char *s = "libft is cool";

	printf("ft_substr: %s\n", ft_substr(s, 6, 4)); // should print "is c"
}
//*/
