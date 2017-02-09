/*
** malloc.c for PSU_2016_malloc in /home/god/TEK2/PSU_MEMOIRE/PSU_2016_malloc/malloc/malloc.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Mon Jan 23 10:25:50 2017 Maxime PILLON
** Last update Tue Jan 24 14:28:01 2017 Sylvain CORSINI
*/

#include <stddef.h>
#include <unistd.h>
#include <memory.h>
#include <limits.h>
#include "allocation.h"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *g_base_heap = NULL;

static t_block *extend_heap(t_block *last_block, size_t size)
{
  t_block *block;
  size_t sufficient_size;

  sufficient_size = get_sufficient_size_of_malloc(size);
  block = sbrk(0);
  if (sbrk(sufficient_size) == (void *) -1)
      return (NULL);
  block->max_size = sufficient_size - BLOCK_SIZE;
  block->required_size = size;
  block->next = NULL;
  block->magic_number = (void *) block + BLOCK_SIZE;
  block->prev = last_block;
  if (last_block != NULL)
    last_block->next = block;
  block->free = 0;
  return (block);
}

static t_block *find_block(t_block **last_block, size_t size)
{
  t_block *block;

  block = g_base_heap;
  while (block != NULL && !(block->free == 1 && block->max_size >= size))
    {
      *last_block = block;
      block = block->next;
    }
  return (block);
}

void *thread_malloc(size_t size)
{
  t_block *block;
  t_block *last_block;

  if (size + BLOCK_SIZE > LONG_MAX)
    return (NULL);
  if (g_base_heap == NULL)
    {
      block = extend_heap(NULL, size);
      g_base_heap = block;
    }
  else
    {
      last_block = g_base_heap;
      block = find_block(&last_block, size);
      if (block == NULL)
	block = extend_heap(last_block, size);
      else
	{
	  block = split_block(block, size);
	  block->free = 0;
	}
    }
  if (block == NULL)
    return (NULL);
  return ((void *) block + BLOCK_SIZE);
}

void *malloc(size_t size)
{
  void *ptr;

  pthread_mutex_lock(&lock);
  ptr = thread_malloc(size);
  pthread_mutex_unlock(&lock);
  return (ptr);
}

void *calloc(size_t nmemb, size_t size)
{
  void *ptr;

  pthread_mutex_lock(&lock);
  ptr = thread_malloc(nmemb * size);
  if (ptr == NULL)
    {
      pthread_mutex_unlock(&lock);
      return (NULL);
    }
  memset(ptr, 0, nmemb * size);
  pthread_mutex_unlock(&lock);
  return (ptr);
}
