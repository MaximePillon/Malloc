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



#include 	<unistd.h>
#include 	"allocation.h"

t_block *get_block(void *ptr)
{
  t_block *tmp;
  tmp = ptr;
  tmp -= BLOCK_SIZE;
  return (tmp);
}

int valid_addr(void *ptr)
{
  t_block *block;

  if (g_base_heap != 0)
  {
    if (ptr > g_base_heap && ptr < sbrk(0))
    {
      block = get_block(ptr);
      return (block->ptr == ptr);
    }
  }
  return (0);
}

t_block *fusion_block(t_block *block)
{
  block->size += block->next->size + BLOCK_SIZE;
  block->next = block->next->next;
  if (block->next != 0)
    block->next->prev = block;
  return (block);
}

void free(void *ptr)
{
  t_block *block;

  if (valid_addr(ptr) == 1)
  {
    block = get_block(ptr);
    block->free = 1;
    if (block->next != 0 && block->next->free == 1)
      fusion_block(block);
    if (block->prev != 0 && block->prev->free == 1)
      block = fusion_block(block->prev);
    if (block->next == 0)
    {
      if (block->prev != 0)
        block->prev->next = 0;
      else
        g_base_heap = 0;
      brk(block);
    }
  }
}
