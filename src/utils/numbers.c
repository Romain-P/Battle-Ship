/*
** my_getnbr.c for my_getnbr in /home/romain.pillot/projects/CPool_Day04
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Oct  7 21:03:32 2016 romain pillot
** Last update Mon Feb 20 01:16:14 2017 romain pillot
*/

#include <stdbool.h>
#include "number.h"
#include "display.h"

static bool	is_digit(char c)
{
  return (c >= '0' && c <= '9');
}

static int     my_getnbr_sub(char *str, int i, int n, int s)
{
  if ((str[i] == '-' || str[i] == '+') && (i == 0 || !is_digit(str[i - 1])))
    return (my_getnbr_sub(str, i + 1, n, str[i] == '-' ? s * - 1 : s));
  else if (is_digit(str[i]))
    if ((((long)n * 10) + (str[i] - 48)) > 2147483647)
      return (0);
    else
      return (my_getnbr_sub(str, i + 1, (n * 10) + (str[i] - 48), s));
  else
    return (n * s);
}

int     getnbr(char *str)
{
  return (my_getnbr_sub(str, 0, 0, 1));
}

void	putnbr(int nbr)
{
  int i;

  i = 1;
  while (i <= nbr)
    i *= 10;
  i /= 10;
  while (i > 0)
    {
      display_char((nbr / i % 10) + '0');
      i /= 10;
    }  
}
