/*
** source : http://home.online.no/~pjacklam/notes/invnorm/impl/natarajan/normsinv.h
*/


#include <math.h>
#include "normsinv.h"

long double normsinv(long double p)
{
  long double x = 0.0;
  long double q, r, u, e = 0.0;
  
  if ((0 < p)  && (p < P_LOW))
    {
      q = sqrt(-2 * log(p));
      x = (((((C1 * q + C2) * q + C3) * q + C4) * q +C5) * q + C6) / ((((D1 * q + D2) * q + D3) * q + D4) * q + 1);
    }
  else
    {
      if ((P_LOW <= p) && (p <= P_HIGH))
	{
	  q = p - 0.5;
	  r = q * q;
	  x = (((((A1 * r + A2) * r +A3) * r + A4) * r + A5) * r + A6) * q /(((((B1 * r + B2) * r + B3) * r + B4) * r + B5) * r + 1);
      }
      else
	{
	  if ((P_HIGH < p) && (p < 1))
	    {
	      q = sqrt(-2 * log(1 - p));
	      x = -(((((C1 * q +C2) * q + C3) * q + C4) * q + C5) * q + C6) / ((((D1 * q + D2) * q + D3) * q + D4) * q + 1);
	    }
	}
    }
  return (x);
}
