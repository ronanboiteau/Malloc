#include <unistd.h>
#include "libmy_malloc.h"
#include "my.h"

t_chunk		*g_heap_start = NULL;

void		show_alloc_mem()
{
  t_chunk	*tmp;

  my_printf("break : %p\n", sbrk(0));
  tmp = g_heap_start;
  while (tmp != NULL)
    {
      if (tmp->is_free == false)
	my_printf("%p - %p : %u bytes\n", tmp->address,
		  tmp->address + tmp->size, tmp->size);
      tmp = tmp->next;
    }
}

void		*calloc(size_t nmemb, size_t size)
{
  t_uchar	*ptr;
  size_t	idx;

  if ((ptr = malloc(size * nmemb)) == NULL)
    return (NULL);
  idx = 0;
  while (idx < size)
    {
      ptr[idx] = 0;
      ++idx;
    }
  return (ptr);
}

void		*realloc(void *ptr, size_t size)
{
  void		*new_ptr;
  t_chunk	*old;
  t_chunk	*new;

  if ((new_ptr = malloc(size)) == NULL)
    {
      free(ptr);
      return (NULL);
    }
  old = find_chunk(g_heap_start, ptr);
  new = find_chunk(g_heap_start, new_ptr);
  if (old == NULL || new == NULL)
    return (new_ptr);
  my_memcpy(new, old);
  free(ptr);
  return (new_ptr);
}

void		free(void *ptr)
{
  t_chunk	*tmp;

  if (ptr == NULL)
    return ;
  tmp = g_heap_start;
  while (tmp != NULL)
    {
      if (tmp->address == ptr)
	{
	  if (free_this_chunk(tmp) == NULL)
	    g_heap_start = NULL;
	  return ;
	}
      tmp = tmp->next;
    }
}

void		*malloc(size_t size)
{
  t_chunk	*chunk;

  if (size == 0)
    return (NULL);
  if (g_heap_start == NULL)
    {
      if ((g_heap_start = init_memory_map(size)) == NULL)
	return (NULL);
      return (g_heap_start->address);
    }
  if ((chunk = find_free_chunk(size, g_heap_start)) != NULL)
    {
      chunk->is_free = false;
      return (chunk->address);
    }
  else
    {
      if ((chunk = create_chunk(size, g_heap_start)) == NULL)
	return (NULL);
      return (chunk->address);
    }
  return (NULL);
}
