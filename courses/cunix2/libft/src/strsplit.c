#include "../libft.h"

char    *get_word(char const*s, char c)
{
    int     len = -1;
    int     i = -1;
    char    *res;

    while (s[++len] && s[len] != c) ;

    if(!(res = (char*)malloc(sizeof(char) * (len + 1))))
        return NULL;

    while (len > ++i)
        res[i] = s[i];
    res[++i] = '\0';
    return res;
}

int     words_count(char const *s, char c)
{
    int     count = 0;
    int     i = 0;
    while (s[i])
    {
        if (s[i] == c)
            i++;
        else
        {
            count++;
            while (s[i] != c && s[i]) 
                i++;
        }
    }
    return count;
}

char    **ft_strsplit(char const *s, char c)
{
    char    *str = ft_strtrim(s);
    int     count = words_count(str, c);
    char    **strArr = (char**)malloc((count + 1) * sizeof(char*));
    int     i = -1;
    int     j = -1;
    
    while (++i < ft_strlen(str) && j < count)
    {
        if (str[i] == c)
            i++;
        else
        {
            strArr[++j] = get_word(&str[i], c);
            i += ft_strlen(strArr[j]) - 1;
        }
    }
    strArr[count] = NULL;
    return strArr;
}
