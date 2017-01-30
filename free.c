/*
** free.c for PSU_2016_malloc in /home/god/TEK2/PSU_MEMOIRE/PSU_2016_malloc/free/free.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Mon Jan 23 10:27:22 2017 Maxime PILLON
** Last update Tue Jan 24 14:25:25 2017 Sylvain CORSINI
*/

#include <stdio.h>
#include <unistd.h>
#include "allocation.h"

void free(void *ptr)
{
  t_block *block;

  if (valid_block(ptr) == 1)
    {
      block = get_block(ptr);
      block->free = 1;
      if (block->prev != NULL && block->prev->free == 1)
	block = fusion_block(block->prev);
      if (block->next != NULL && block->next->free == 1)
	fusion_block(block);
      if (block->next == NULL)
	{
	  if (block->prev != NULL)
	    block->prev->next = NULL;
	  else
	    g_base_heap = NULL;
	  //sbrk(-(block->max_size + BLOCK_SIZE));
	  brk(block);
	}
    }
}
