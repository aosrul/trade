#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "misc.h"
#include "algo.h"
#include "get_math.h"
#include "montecarlo.h"
#include "actions.h"

int		get_data(t_struct *s, int size, int i)
{
  double	forward = 0.0;
  double	mu = 0.0;

  s->mean = get_mobile_mean(s->spot_array, size);    
  s->weighted_mean = get_exponential_mean(s->spot_array, size);
  if (i == MACD1 - 1)
    s->macd1 = get_exponential_mean(s->spot_array, MACD1);
  if (i == MACD2 - 1)
    {
      s->macd2 = get_exponential_mean(s->spot_array, MACD2);
      s->macd = s->macd2 - s->macd1;
    }
  s->variance = get_variance(s->spot_array, size, s->mean);
  s->std_dev = get_standard_deviation(s->spot_array, size, s->mean);
  s->volatility = (s->std_dev*100)/s->spot;
  s->high_peak = s->weighted_mean + s->std_dev;
  s->low_peak = s->weighted_mean - s->std_dev;
  s->bollinger_high = s->mean + (N * s->std_dev);
  s->bollinger_low = s->mean - (N * s->std_dev);
  return (0);
}

int		main_loop(t_struct *s)
{
  int		i = 0;
  int		size = 1;
  int		count = 0;

  while (count < s->days)
    {
      s->spot = x_get_nbr();
      if (s->spot == 0)
	break;
      if (i == LIMIT)
	{
	  i = 0;
	  size = LIMIT;
	}
      s->spot_array[i] = s->spot;
      s->count = count;
      get_data(s, size, i);
      actions(s);
      count++;
      i++;
      if (size < LIMIT)
	size++;
    }
   return (0);
}
