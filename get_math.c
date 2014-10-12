#include <math.h>
#include "struct.h"
#include "get_math.h"

double		get_mobile_mean(int *spot_array, int size)
{
  int		i;
  double	m;

  i = 0;
  m = 0.0;
  if (size == 0)
    return (0.0);
  while (i < size)
    {
      m = m + spot_array[i];
      i++;
    }
  m = m / size;
  return (m);
}

double		get_exponential_mean(int *spot_array, int size)
{
  int		i;
  double	m;
  double	coeff;
  
  i = 0;
  m = 0;
  coeff = 0;
  while (i < size)
    {
      m = m + spot_array[i] * (i + 1);
      coeff = coeff + (i + 1);
      i++;
    }
  if (coeff != 0)
    m = m / coeff;
  return (m);
}

double		get_variance(int *spot_array, int size, double mean)
{
  int		i;
  double	variance;
  double	diff;
  double	diff_sum;

  i = 0;
  variance = 0.0;
  diff = 0.0;
  diff_sum = 0.0;
  if (size == 0)
    return (0.0);
  while (i < size)
    {
      diff = spot_array[i] - mean;
      diff_sum = diff_sum + (diff * diff);
      i++;
    }
  variance = diff_sum/ size;
  return (variance);
}

double		get_standard_deviation(int *spot_array, int size, double mean)
{
  double	std_dev;
  double	variance;
  
  variance = 0.0;
  std_dev = 0.0;
  variance = get_variance(spot_array, size, mean);
  std_dev = sqrt(variance);
  return (std_dev);
}
