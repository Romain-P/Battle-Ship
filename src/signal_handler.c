/*
** signal_handler.c for  in /home/romain.pillot/projects/PSU_2016_navy/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun Feb 19 18:37:01 2017 romain pillot
** Last update Tue Feb 21 11:29:09 2017 romain pillot
*/

#include "config.h"
#include <stdlib.h>
#include <stdbool.h>
#include "ship.h"
#include <unistd.h>
#include <signal.h>
#include "display.h"
#include "number.h"

static void	next_attack(int pid)
{
  int		i;
  t_cell	*attack;

  navy->cell.x = 0;
  while (!(attack = read_parse_cell()));
  putnbr(attack->x);
  putnbr(attack->y);
  i = -1;
  while (++i < attack->x)
    {
      kill(pid, SIGUSR1);
      usleep(100);
    }
  i = -1;
  while (++i < attack->y)
    {
      kill(pid, SIGUSR2);
      usleep(100);
    }
  kill(pid, SIGUSR1);
  free(attack);
}

static bool	onsigus_rone(int pid)
{
  bool		hit;

  if (!navy->cell.y)
    navy->cell.x++;
  else
    {
      if (!navy->cell.x)
	{
	  attack_cell(navy->holder, ENEMY, true);
	  hit = !alive(ENEMY, true);
	  if (!hit)
	    display("waiting for enemy's attack...\n");
	  navy->cell.y = 0;
	  return (hit);
	}
      hit = attack_cell(navy->cell, ALLY, false);
      display_map(ALLY);
      display_map(ENEMY);
      kill(pid, hit ? SIGUSR1 : SIGUSR2);
      if (hit && !alive(ALLY, true))
	return (true);
      next_attack(pid);
    }
  return (false);
}

static void	onsigus_rtwo(int pid)
{
  (void) pid;
  if (navy->cell.x)
    navy->cell.y++;
  else
    {
      attack_cell(navy->holder, ENEMY, false);
      display("waiting for enemy's attack...\n");
      navy->cell.y = 0;
    }
}

static void	handle_signal(int signal, siginfo_t *infos, void *ctx)
{
  (void) ctx;
  if (!navy->init)
    {
      display(signal == SIGUSR1 ?
	      "enemy connected\n\n\n" : "successfully connected\n\n\n");
      display_map(ALLY);
      display_map(ENEMY);
      if (signal == SIGUSR1)
	{
	  kill(infos->si_pid, SIGUSR2);
	  next_attack(infos->si_pid);
	}
      else
        display("waiting for enemy's attack\n");
      navy->init = true;
    }
  else if (signal == SIGUSR1 && onsigus_rone(infos->si_pid))
    return ;
  else if (signal == SIGUSR2)
    onsigus_rtwo(infos->si_pid);
  if (alive(ALLY, true))
    pause();
}

bool			listen_signals()
{
  struct sigaction	action;

  sigemptyset(&action.sa_mask);
  action.sa_sigaction = &handle_signal;
  action.sa_flags = SA_NODEFER | SA_SIGINFO;
  return (!sigaction(SIGUSR1, &action, NULL)
	  && !sigaction(SIGUSR2, &action, NULL));
}
