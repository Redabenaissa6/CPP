#include <iostream>
// #include <cctype>

char    *ft_upper(char *s)
{
    for(int i = 0; s[i]; i++)
        s[i] = toupper(s[i]);
    return (s);
}

int main(int arc, char **arv)
{
    if (arc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std:: endl;
        return 0;
    }
    for(int i = 1; arv[i]; i++)
    {
        std::cout << ft_upper(arv[i]);
    }
    std::cout << std::endl;
    return 0;
}
