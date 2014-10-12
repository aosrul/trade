#include <stdbool.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "misc.h"

bool		is_time_to_buy(t_struct *s)
{
  int		nb = 0;
  
  nb = (int)(s->money / s->spot);
  nb = (nb > 0) ? nb : 0;
  s->price = (int)(s->spot * nb * (1+COMM));
  if (s->spot < s->low_peak && nb > 0)
    {
      s->nb_to_buy = nb;
      return (true);
    }
  return (false);
}

bool		is_time_to_sell(t_struct *s)
{
  if (s->spot > s->high_peak)
    {
      s->nb_to_sell = s->nb_bought;
      return (true);
    }
  return (false);
}

bool		buy(t_struct *s)
{
  char		*str = NULL;

  str = xmalloc(sizeof(char) * STR_LENGTH);
  if (is_time_to_buy(s) == true)
    {
      sprintf(str, "buy %d\n", s->nb_to_buy);
      if (my_write(str, strlen(str)) == -1)
	exit(EXIT_FAILURE);
      s->nb_bought = s->nb_bought + s->nb_to_buy;
      s->money = s->money - s->price;
      s->nb_to_buy = 0;
      s->price = 0;
      xfree(str);
      return (true);
    }
  return (false);
}

bool		sell(t_struct *s)
{
  char		*str = NULL;
  bool		flag = false;
  int		price = 0;

  

  str = xmalloc(sizeof(char) * STR_LENGTH);
  if ((s->count == s->days-1 || is_time_to_sell(s) == true) && s->nb_bought > 0)
    {
      s->nb_to_sell = s->nb_bought;
      price = (int)(s->spot * s->nb_to_sell * (1-COMM));
      s->money = s->money + price;
      s->nb_bought = 0;
      flag = true;
    }
  else if (is_time_to_sell(s) == true && s->nb_bought > 0)
    {
      s->nb_bought = s->nb_bought - s->nb_to_sell;
      flag = true;
    }
  if (flag == true)
    {
      sprintf(str, "sell %d\n", s->nb_to_sell);
      if (my_write(str, strlen(str)) == -1)
	exit(EXIT_FAILURE);
      xfree(str);
      s->nb_to_sell = 0;
    }
  return (flag);
}

int		actions(t_struct *s)
{
  if (buy(s) == false && sell(s) == false)
    {
      if (my_write("wait\n", 5) == -1)
	exit(EXIT_FAILURE);
    }
  return (0);
}
