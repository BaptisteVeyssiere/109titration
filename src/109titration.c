/*
** 109titration.c for 109titration in /home/VEYSSI_B/rendu/Maths/109titration
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Tue Mar 29 15:07:12 2016 Baptiste veyssiere
** Last update Thu Mar 31 02:18:13 2016 nathan scutari
*/

#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "titration.h"

int	errmath(char *str)
{
  write(2, str, my_strlen(str));
  return (84);
}

int	reall_tab(float ***tab, int size)
{
  int	x;
  float	**new_float;

  if ((new_float = malloc(sizeof(float*) * (size + 1))) == NULL)
    return (errmath("Can not perform malloc\n"));
  x = -1;
  while (++x < size)
    new_float[x] = (*tab)[x];
  if ((new_float[size] = malloc(sizeof(float) * 2)) == NULL)
    return (errmath("Can not perform malloc\n"));
  if (*tab != NULL)
    free(*tab);
  *tab = new_float;
  return (0);
}

int	verify_syntax(char *line)
{
  int	x;
  int	point;
  int	save;

  x = -1;
  point = 0;
  while (line[++x] && (line[x] >= '0' && line[x] <= '9') || line[x] == '.')
    if (line[x] == '.')
      point++;
  if (line[x] != ';' || x < 1 || point > 1)
    return (84);
  save = x;
  point = 0;
  while (line[++x] && (line[x] >= '0' && line[x] <= '9') || line[x] == '.')
    if (line[x] == '.')
      point++;
  if (line[x] != 0 || x - save < 2 || point > 1)
    return (84);
}

int	get_nbr1(char *line, char **nbr1)
{
  int	x;
  int	length;

  length = -1;
  while (line[++length] != ';');
  if ((*nbr1 = malloc(length + 1)) == NULL)
    return (errmath("Can not perform malloc\n"));
  x = -1;
  while (++x < length)
    (*nbr1)[x] = line[x];
  (*nbr1)[x] = 0;
  return (0);
}

int	get_nbr2(char *line, char **nbr2)
{
  int	x;
  int	length;
  int	save;

  save = -1;
  while (line[++save] != ';');
  save++;
  x = -1;
  length = -1;
  while (line[++length + save] != 0);
  if ((*nbr2 = malloc(length + 1)) == NULL)
    return (errmath("Can not perform malloc\n"));
  while (++x < length)
    (*nbr2)[x] = line[x + save];
  (*nbr2)[x] = 0;
  return (0);
}

float	**check_line(char *line, float **tab, int size)
{
  char	*nbr1;
  char	*nbr2;

  if (verify_syntax(line) == 84 ||
      get_nbr1(line, &nbr1) == 84 ||
      get_nbr2(line, &nbr2) == 84 ||
      reall_tab(&tab, size) == 84)
    return (NULL);
  tab[size][0] = atof(nbr1);
  tab[size][1] = atof(nbr2);
  return (tab);
}

float	**check_file(char *file, int *size)
{
  int	fd;
  char	*line;
  float	**tab;

  if ((fd = open(file, O_RDONLY)) == -1)
    {
      errmath("Can not open the file\n");
      return (NULL);
    }
  tab = NULL;
  while ((line = get_next_line(fd)) != NULL)
    {
      if ((tab = check_line(line, tab, *size)) == NULL)
	return (NULL);
      (*size)++;
    }
  if (tab == NULL)
    {
      errmath("Nothing has been found in the file\n");
      return (NULL);
    }
  return (tab);
}

int	main(int ac, char **av)
{
  float	**tab;
  int	size;

  size = 0;
  if (ac < 2)
    return (errmath("Not enough arguments\n"));
  if (av[1][0] != 0 && av[1][0] == '-' && av[1][1] == 'h')
    {
      printf("USAGE\n             ./109titration file\n\nDESCRIPTION\n");
      printf("            file    a csv file containing \042vol;ph\042lines\n");
      return (84);
    }
  if ((tab = check_file(av[1], &size)) == NULL)
    return (errmath("Error while loading the file\n"));
  calc(tab, size);
  return (0);
}
