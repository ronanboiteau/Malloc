#ifndef STRING_H_
# define STRING_H_

typedef struct	s_string
{
  char		*str;
  unsigned int	idx;
}		t_string;

typedef struct	s_cstring
{
  const char	*str;
  unsigned int	idx;
}		t_cstring;

#endif /* !STRING_H_ */
