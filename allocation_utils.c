/*
** allocation_utils.c for PSU_2016_malloc in /home/sylvain/Travail/Epitech/PSU_2016_malloc
**
** Made by Sylvain CORSINI
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Tue Jan 24 14:25:25 2017 Sylvain CORSINI
** Last update Tue Jan 24 14:25:25 2017 Sylvain CORSINI
*/

#include <unistd.h>
#include "allocation.h"

size_t get_sufficient_size_of_malloc(size_t required_size)
{
  size_t sufficient_size;
  size_t page_size;

  page_size = (size_t) getpagesize();
  //page_size = 2;
  sufficient_size = page_size;
  while (required_size + BLOCK_SIZE > sufficient_size)
    {
      //sufficient_size *= page_size;
      sufficient_size += page_size;
    }
  return (sufficient_size);
}

t_block *get_block(void *ptr)
{
  return ((t_block *) (ptr - BLOCK_SIZE));
}

int valid_block(void *ptr)
{
  t_block *block;

  if (g_base_heap != NULL && ptr > g_base_heap && ptr < sbrk(0))
    {
      block = get_block(ptr);
      return (block->magic_number == ptr);
    }
  return (0);
}

t_block *split_block(t_block *block, size_t size)
{
  t_block *new_block;
  size_t new_size;

  new_size = get_sufficient_size_of_malloc(size);
  if (new_size - BLOCK_SIZE != block->max_size)
    {
      new_block = (void *) block + new_size;
      new_block->max_size = block->max_size - new_size;
      new_block->required_size = new_block->max_size;
      block->max_size = new_size - BLOCK_SIZE;
      new_block->prev = block;
      new_block->next = block->next;
      block->next = new_block;
      new_block->free = 1;
      new_block->magic_number = (void *) new_block + BLOCK_SIZE;
    }
  block->required_size = size;
  return (block);
}

t_block *fusion_block(t_block *block)
{
  block->max_size += block->next->max_size + BLOCK_SIZE;
  block->required_size = block->max_size;
  block->next = block->next->next;
  if (block->next != NULL)
    block->next->prev = block;
  return (block);
}
