#include "../inc/minishell.h"

static char	*ft_str_insert_free_test(char *str, char chr, int index)
{
	char	*new_str;
	int		i_ns;
	int		i_s;

	i_ns = 0;
	i_s = 0;
	if (index > (int)ft_strlen(str))
	{
		new_str = ft_strdup(str);
		return (free(str), new_str);
	}
	new_str = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
	while (i_ns < (int)ft_strlen(str) + 1)
	{
		if (i_ns == index)
			new_str[i_ns] = chr;
		else
        {
			new_str[i_ns] = str[i_s];
            i_s++;
        }
		i_ns++;
	}
    new_str[i_ns] = '\0';
	ft_printf("TESTE = %s\n", new_str);
    free(str);
    return (new_str);
}

int main (void)
{
    // char    *cavalinho = ft_strdup("cavalinho");

    // cavalinho = ft_str_insert_free(cavalinho, 'a', 5);
    // ft_printf("%s\n", cavalinho);
    // free(cavalinho);

	char	*cavalinho = ft_strdup("a");
    cavalinho = ft_str_insert_free_test(cavalinho, 'a', 1);
    ft_printf("%s\n", cavalinho);
    free(cavalinho);
}