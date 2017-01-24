/*
** malloc.c for PSU_2016_malloc in /home/god/TEK2/PSU_MEMOIRE/PSU_2016_malloc/malloc/malloc.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Mon Jan 23 10:25:50 2017 Maxime PILLON
** Last update Mon Jan 23 10:25:50 2017 Maxime PILLON
*/

#include 	<stdio.h>
#include 	<stddef.h>
#include <unistd.h>
#include 	"../inc/allocation.h"

void 		*malloc(size_t size)
{
  t_struct new;
  void *ptr;

  new.dataSize = size;
  if ((ptr = sbrk(0)) == (void *)-1)
    return NULL;

  sbrk(size + BLOCK_SIZE);
  return ptr;
  //brk / sbrk + increment pointer !!
}