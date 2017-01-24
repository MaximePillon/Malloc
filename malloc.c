/*
** malloc.c for PSU_2016_malloc in /home/god/TEK2/PSU_MEMOIRE/PSU_2016_malloc/malloc/malloc.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Mon Jan 23 10:25:50 2017 Maxime PILLON
** Last update Tue Jan 24 14:14:03 2017 Sylvain CORSINI
*/

#include        <stddef.h>
#include        <unistd.h>
#include        "allocation.h"

void            *g_base_heap = 0;

static size_t   get_size_of_malloc(size_t size)
{
  size_t        page_size;
  size_t        page_size_total;

  page_size_total = (size_t)getpagesize();
  page_size = page_size_total;
  while (size + BLOCK_SIZE > page_size)
  {
    page_size += page_size_total;
  }
  return (page_size);
}

static t_block   *extend_heap(t_block *last_block, size_t size)
{
  t_block        *block;

  size = get_size_of_malloc(size);
  block = sbrk(0);
  if (sbrk(size) == (void*)-1)
    return (0);
  block->size = size - BLOCK_SIZE;
  block->next = 0;
  block->prev = last_block;
  if (last_block != 0)
    last_block->next = block;
  block->free = 0;
  return (block);
}

static t_block    *split_block(t_block *block, size_t size)
{
  t_block         *new_block;
  size_t          new_size;

  new_size = get_size_of_malloc(size);
  if (new_size - BLOCK_SIZE == block->size)
  {
    new_block = block + new_size;
    new_block->size = block->size - new_size - BLOCK_SIZE;
    block->size = new_size;
    new_block->prev = block;
    new_block->next = block->next;
    block->next = new_block;
    new_block->free = 1;
  }
  return (block);
}

static t_block     *find_block(t_block **last_block, size_t size)
{
  t_block          *block;

  block = g_base_heap;
  while (block && !(block->free == 1 && block->size >= size))
  {
    *last_block = block;
    block = block->next;
  }
  return (block);
}

void                *my_malloc(size_t size)
{
  t_block           *block;
  t_block           *last;

  if (g_base_heap == 0)
  {
    block = extend_heap(0, size);
    g_base_heap = block;
  }
  else
  {
    last = g_base_heap;
    block = find_block(&last, size);
    if (block == 0)
      block = extend_heap(last, size);
    else
      block = split_block(block, size);
  }
  if (block == 0)
    return (0);
  return ((void *)(block + BLOCK_SIZE));
}
