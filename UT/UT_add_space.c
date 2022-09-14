#include "../inc/minishell.h"

static  check_double_test(char **str, int *i, int type)
{
    int index_beetween;

    index_beetween = 1;
    if (*i > 0)
    {
        if ((*str)[*i - index_beetween] != type)
        {
            *str = ft_str_insert_free(*str, SPACE, *i);
            index_beetween++;
        }
    }
    if ((*str)[*i + index_beetween] != type)
        *str = ft_str_insert_free(*str, SPACE, *i + index_beetween);
    *i = *i + 1;
}

void	add_space_test(char **str)
{
	int	i;
	int quote_type;
	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == D_QUOTE || (*str)[i] == S_QUOTE)
        {
            quote_type = (*str)[i];
            i++;
            while ((*str)[i] && (*str)[i] != quote_type)
                i++;
        }
		if ((*str)[i] == PIPE)
        {
			*str = ft_str_insert_free(*str, SPACE, i);
            *str = ft_str_insert_free(*str, SPACE, i + 2);
            i += 2;
        }
        if ((*str)[i] == I_REDIRECT || (*str)[i] == O_REDIRECT)
            check_double(str, &i, (*str)[i]);
        i++;
	}
}

int main(void)
{
    char    *cavalinho = ft_strdup("<as<das||asda<sasdasdas<<asdas|<");
    add_space_test(&cavalinho);
    ft_printf("%s\n", cavalinho);
    free(cavalinho);
}