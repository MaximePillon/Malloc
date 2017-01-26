/*
** main_sbrk_brk.c for PSU_2016_malloc in /home/god/TEK2/PSU_MEMOIRE/PSU_2016_malloc/main_sbrk_brk.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Mon Jan 23 10:16:32 2017 Maxime PILLON
** Last update Mon Jan 23 10:16:33 2017 Maxime PILLON
*/

#include <unistd.h>
#include <stdio.h>
#include "allocation.h"

int main()
{
  char *tmp;

  free((void*)43);
  tmp = malloc(20);
  tmp[0] = 'A';
  tmp[1] = '\0';
  printf("var: %s\n", tmp);
  free(tmp);
}
