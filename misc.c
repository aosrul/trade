#include <stdlib.h>
#include <stdio.h>
#include "misc.h"
#include "struct.h"

int		x_get_nbr(void)
{
  int		m = 0;
  char		*str = NULL;
  int		size = STR_LENGTH;
  int		nb = 0;

  str =xmalloc(size);
  nb = getline(&str, &size, stdin);
  if (nb == 0 || nb > STR_LENGTH)
    exit(EXIT_FAILURE);
  m = atoi(str);
  free(str);
  str = NULL;
  return (m);
}

int		my_write(char *str, int size)
{
  int		res = 0;

  if (str == NULL)
    return (-1);
  if (size <= 0)
    return (-1);
  if ((res = write(1, str, size)) == -1)
    return (-1);
  return (res);
}

void		*xmalloc(int size)
{
  void		*b = NULL;
  if ((b = malloc(size)) == NULL)
    exit(EXIT_FAILURE);
  return (b);
}

void		xfree(void *buff)
{
  if (buff != NULL)
    free(buff);
}
