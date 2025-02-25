#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    freetwo(void **arr, int seg)
{
    int i;

    i = -1;
    while (arr[++i] != NULL)
        free(arr[i]);
    if (!seg)
        free(arr);
}

int	ft_free(const char *s, ...)
{
	int		i;
	va_list	p;

	i = -1;
	va_start(p, s);
	while (s[++i] != '\0')
	{
		if (s[i] == '1' && (s[i + 1] == 'p' || s[i + 1] == 's'))
			free((va_arg(p, void *)));
        if (s[i] == '2' && s[i + 1] == 'p')
            freetwo(va_arg(p, void **), 0);
	}
	va_end(p);
	return (0);
}
