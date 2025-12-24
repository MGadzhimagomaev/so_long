
#include "libft.h"

int is_delimiter (char c, char del)
{
    if (c == del)
        return (1);
    return (0);
}

int word_count (char *str, char del)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] && (i == 0 || is_delimiter(str[i - 1], del)) && !is_delimiter(str[i], del))
            count++;
        i++;
    }
    return (count);
}

int find_next_word (char *str, int *start, int *end, char del)
{
    int i;

    i = *start;
    while (str[i])
    {
        if (str[i] && (i == 0 || is_delimiter(str[i - 1], del)) 
        && !is_delimiter(str[i], del))
        {
            *start = i;
            while (str[i] && !is_delimiter(str[i], del))
                i++;
            *end = i - 1;
            return(1);
        }
        i++;
    }
    return (0);
}

char **fill_words(char **output, char *str, int word_count, char del)
{
    int start = 0;
    int end = 1;
    int i;
    int word;

    word = 0;
    while (word < word_count && find_next_word (str, &start, &end, del))
    {
        i = 0;
        output[word] = malloc(sizeof(char) * (end - start + 2));
        if (!output[word])
            return(free(output[word]), NULL);
        while (start <= end)
        {
            output[word][i++] = str[start++];
        }
        output[word][i] = '\0';
        word++;
    }
    output[word] = NULL;
    return (output);
}

char    **ft_split(char *str, char del)
{
    char **output;

    output = malloc(sizeof(char*) * (word_count(str, del) + 1));
    if (!output)
        return NULL;
    return (fill_words(output, str, word_count(str, del), del));
}