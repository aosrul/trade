#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "montecarlo.h"
#include "normsinv.h"

double		montecarlo(int spot, double vol, double mu)
{
  int		i = 0;
  int		j = 1;
  double	alea = 0;
  double	delta = 0.0;
  double	Sn[N_DAYS];
  double	S = 0.0;
  double	mean = 0.0;
  double	brownian = 0.0;

  Sn[0] = (double)spot;
  while (i < N_SIM)
    {
      while (j < N_DAYS)
	{
	  alea = (double)rand() / ((double)RAND_MAX - 1);
	  brownian = normsinv(alea);
	  delta = (vol * brownian) - ((vol * vol) / 2);
	  Sn[j] = Sn[j-1] + (mu * j) + (vol * delta) + sqrt(j);
	  j++;
	}
      mean = mean + Sn[j-1];
      j = 1;
      i++;
    }
  mean = mean / N_SIM;
  return (mean);
}
