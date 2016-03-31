/*
** calc.c for 109titration in /home/VEYSSI_B/rendu/Maths/109titration
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Tue Mar 29 15:09:20 2016 Baptiste veyssiere
** Last update Thu Mar 31 16:01:05 2016 Baptiste veyssiere
*/

#include <math.h>
#include <stdio.h>
#include "titration.h"

void	calc(float **tab, int length)
{
  int	i;
  float	vol;
  float	derive;
  float	derive_min;
  float	derive_max;
  float	max;
  float	max_d;
  int	index;
  float	findex;
  float	increment_min;
  float	increment_max;
  float	sd_a;
  float	sd_b;
  float	sd_c;

  printf("Derivative:\n");
  i = 0;
  max = 0;
  max_d = 0;
  while (++i < (length - 1))
    {
      vol = tab[i][0];
      derive = (tab[i + 1][1] - tab[i - 1][1]) / (tab[i + 1][0] - tab[i - 1][0]);
      if (derive > max_d)
	{
	  index = i;
	  max = vol;
	  max_d = derive;
	}
      printf("volume: %.2g ml -> %.2f\n", vol, derive);
    }
  printf("\nEquivalent point at %.2g ml\n", max);
  printf("\nSecond derivative:\n");
  i = 1;
  sd_a = 0;
  sd_b = 0;
  sd_c = 0;
  while (++i < (length - 2))
    {
      vol = tab[i][0];
      derive_min = (tab[i][1] - tab[i - 2][1]) / (tab[i][0] - tab[i - 2][0]);
      derive_max = (tab[i + 2][1] - tab[i][1]) / (tab[i + 2][0] - tab[i][0]);
      derive = (derive_max - derive_min) / (tab[i + 1][0] - tab[i - 1][0]);
      if (i == (index - 1))
  	sd_a = derive;
      else if (i == index)
	sd_b = derive;
      else if (i == (index + 1))
	sd_c = derive;
      printf("volume: %.2g ml -> %.2f\n", vol, derive);
    }
  printf("\nSecond derivative estimated:\n");
  findex = tab[index - 1][0];
  increment_min = (sd_b - sd_a) / (tab[index][0] - tab[index - 1][0]) * 0.1;
  increment_max = (sd_c - sd_b) / (tab[index + 1][0] - tab[index][0]) * 0.1;
  derive = sd_a - increment_min;
  max = 1000000;
  while (findex <= (tab[index + 1][0] + 0.1))
    {
      vol = findex;
      if (findex <= tab[index][0] && sd_a)
  	derive += increment_min;
      else if (sd_c)
  	derive += increment_max;
      if (derive < max && derive >= 0.001)
  	derive_min = findex;
      printf("volume: %.2g ml -> %.2f\n", vol, derive);
      findex += 0.1;
    }
  /* printf("\nEquivalent point at %.2g ml\n", derive_min); */
}
