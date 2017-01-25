#ifndef LIBMY_MALLOC_H_
# define LIBMY_MALLOC_H_

# include <stdlib.h>
# include <stdbool.h>

typedef struct	s_chunk t_chunk;

struct		s_chunk
{
  t_chunk	*prev;
  t_chunk	*next;
  bool		is_free;
  size_t	size;
  void		*address;
};

void		show_alloc_mem();
void		free(void *ptr);
void		*malloc(size_t size);
void		*calloc(size_t nmemb, size_t size);
void		*realloc(void *ptr, size_t size);
t_chunk		*find_chunk(t_chunk *tmp, void *ptr);
void		my_memcpy(t_chunk *dest, t_chunk *src);
t_chunk		*free_this_chunk(t_chunk *tmp);
t_chunk		*find_free_chunk(size_t const size, t_chunk *tmp);
void		*init_memory_map(size_t const size);
void		*create_chunk(size_t const size, t_chunk *tmp);
void		use_free_chunk(t_chunk *chunk, size_t size);

#endif /* !LIBMY_MALLOC_H_ */
