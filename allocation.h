/*
** allocation.h for PSU_2016_malloc in /home/god/TEK2/PSU_MEMOIRE/PSU_2016_malloc/inc/allocation.h
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Mon Jan 23 12:29:30 2017 Maxime PILLON
** Last update Tue Jan 24 13:49:34 2017 Sylvain CORSINI
*/

#ifndef PSU_2016_MALLOC_ALLOCATION_H
# define PSU_2016_MALLOC_ALLOCATION_H

# include <stddef.h>
# include <pthread.h>
# include <time.h>

struct block
{
  size_t max_size;
  size_t required_size;
  struct block *next;
  struct block *prev;
  int free;
  void *magic_number;
};

typedef struct block t_block;

# define        BLOCK_SIZE (sizeof(struct block))

extern void *g_base_heap;

extern pthread_mutex_t lock;


void *calloc(size_t nmemb, size_t size);

void *thread_malloc(size_t size);

void *malloc(size_t size);

void thread_free(void *ptr);

void free(void *ptr);

void *realloc(void *ptr, size_t size);

size_t get_sufficient_size_of_malloc(size_t size);

t_block *get_block(void *ptr);

int valid_block(void *ptr);

t_block *split_block(t_block *block, size_t size);

t_block *fusion_block(t_block *block);

void show_alloc_mem();

void extend_show_alloc_mem();

#endif //PSU_2016_MALLOC_ALLOCATION_H
