#include <stdlib.h>
#include <string.h>
#include "misc.h"
#include "algo.h"
#include "struct.h"

int		main(int argc, char **argv)
{
  t_struct	*s = NULL;
  
  s = xmalloc(sizeof(t_struct));
  s = memset(s, 0, sizeof(t_struct));
  s->spot_array = xmalloc(sizeof(int) * LIMIT);
  s->spot_array = memset(s->spot_array, 0, LIMIT);
  s->money = x_get_nbr();
  s->days = x_get_nbr();
  main_loop(s);
  xfree(s->spot_array);
  s->spot_array = NULL;
  xfree(s);
  s = NULL;
  return (0);
}
