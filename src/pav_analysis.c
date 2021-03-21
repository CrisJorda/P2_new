#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N)
{
  float sum;
  int i;

  sum = 0;
  for (i = 0; i < N; i++)
  {
    sum += x[i] * x[i];
  }

  return 10 * log10f((sum/N));
}

float compute_am(const float *x, unsigned int N)
{
  float sum;
  int i;

  sum = 0;
  for (i = 0; i < N; i++)
  {
    sum += fabs(x[i]);
  }

  return sum/N;
}

float compute_zcr(const float *x, unsigned int N, float fm)
{
  float sum;
  int i;

  sum = 0;
  for (i = 0; i < N; i++)
  {
    if ((x[i] * x[i - 1]) < 0)
    {
      sum++;
    }
  }

  return (fm / (2 * (N - 1))) * sum;
}
