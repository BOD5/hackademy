#include "../libft.h"

div_t ft_div(int a, int b)
{
    div_t res;
    res.quot = a / b;
    res.rem = a % b;
    return res;
}
