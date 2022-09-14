#include "../inc/minishell.h"

static void    check(char *msg, char *expected)
{
    clean_space(msg);
	add_space(&msg);
    if (ft_str_is_equal(msg, expected))
        ft_printf("%s  :  OK\n", msg);
    else
        ft_printf("%s  :  FAIL\n", msg);
    free(msg);
}

int main (void)
{
    char *a;

    a = ft_strdup("asdasdasd");
    check(a, "asdasdasd");

    a = ft_strdup("<asdasdasd");
    check(a, "< asdasdasd");

    a = ft_strdup("'<'asdasdasd");
    check(a, "'<'asdasdasd");

    a = ft_strdup(" <asdasdasd");
    check(a, "  < asdasdasd");

    a = ft_strdup(" '<'asdasdasd");
    check(a, " '<'asdasdasd");

    a = ft_strdup(" '<'asd\"|\"asdasd");
    check(a, " '<'asd\"|\"asdasd");

    a = ft_strdup(" '<'asd\"|\"asd|asd");
    check(a, " '<'asd\"|\"asd | asd");

    a = ft_strdup(" '<'asd\"|\"asd|asd|");
    check(a, " '<'asd\"|\"asd | asd | ");

    a = ft_strdup("<<asdasdasd");
    check(a, "<< asdasdasd");

    a = ft_strdup("<<asda<<sdasd");
    check(a, "<< asda << sdasd");

    a = ft_strdup("|<<asda<<sdasd");
    check(a, " |  << asda << sdasd");

    a = ft_strdup("|<<as'<\"<'da<<sd\"<\"asd");
    check(a, " |  << as'<\"<'da << sd\"<\"asd");

    a = ft_strdup("|<<as'<\"<'da<'<s'd\"<\"asd");
    check(a, " |  << as'<\"<'da < '<s'd\"<\"asd");
}
