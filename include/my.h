#ifndef MY_H_
# define MY_H_

# include "my_macro.h"
# include "my_typedef.h"

int	my_char_isprintable(const char letter);
int	my_dprintf(int fd, const char *format, ...);
int	my_printf(const char *format, ...);
int	my_strlen(const char *str);

#endif /* !MY_H_ */
