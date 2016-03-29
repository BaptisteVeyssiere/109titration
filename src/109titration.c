/*
** 109titration.c for 109titration in /home/VEYSSI_B/rendu/Maths/109titration
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Tue Mar 29 15:07:12 2016 Baptiste veyssiere
** Last update Tue Mar 29 15:34:14 2016 Baptiste veyssiere
*/

#include <math.h>
#include "titration.h"

int	main(int ac, char **av)
{
  float	tab[13][2];

  tab[0][0] = 1;
  tab[0][1] = 2;
  tab[1][0] = 2;
  tab[1][1] = 3;
  tab[2][0] = 3;
  tab[2][1] = 4;
  tab[3][0] = 5;
  tab[3][1] = 4.4;
  tab[4][0] = 6;
  tab[4][1] = 4.6;
  tab[5][0] = 7;
  tab[5][1] = 6;
  tab[6][0] = 7.5;
  tab[6][1] = 6.8;
  tab[7][0] = 8;
  tab[7][1] = 8;
  tab[8][0] = 9;
  tab[8][1] = 10;
  tab[9][0] = 12;
  tab[9][1] = 11.3;
  tab[10][0] = 14;
  tab[10][1] = 11.46;
  tab[11][0] = 16;
  tab[11][1] = 11.6;
  tab[12][0] = 20;
  tab[12][1] = 11.8;
  calc(tab, 13);
  return (0);
}
