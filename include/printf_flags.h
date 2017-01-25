#ifndef PRINTF_FLAGS_H_
# define PRINTF_FLAGS_H_

# include <stdarg.h>
# include "string.h"
# include "my.h"

# define FLAGS_NBR (12)

typedef struct	s_flag
{
  t_uint	(*fct)(int fd, t_uint printed, va_list ap);
  char		flag_char;
}		t_flag;

int		char_isflag(const char letter, const t_flag *flags);
int		char_isletter(const char letter);
t_uint		print_char(int fd, t_uint printed, va_list ap);
t_uint		print_str(int fd, t_uint printed, va_list ap);
t_uint		str_non_printable(int fd, t_uint printed, va_list ap);
t_uint		print_int(int fd, t_uint printed, va_list ap);
t_uint		convert_binary(int fd, t_uint printed, va_list ap);
t_uint		convert_decimal(int fd, t_uint printed, va_list ap);
t_uint		convert_hex_lowcase(int fd, t_uint printed, va_list ap);
t_uint		convert_hex_upcase(int fd, t_uint printed, va_list ap);
t_uint		convert_octal(int fd, t_uint printed, va_list ap);
t_uint		ptr_to_hex(int fd, t_uint printed, va_list ap);
t_uint		ptr_printed_chars(int fd, t_uint printed, va_list ap);
t_uint		double_decimal(int fd, t_uint printed, va_list ap);
int		init_flag(char flag_char,
			  t_uint (*fct)(int fd,
					t_uint printed,
					va_list ap),
			  t_flag *flags);
void		init_structures(t_flag *flags,
				t_cstring *str,
				const char *format);
const char	*find_flag(t_cstring *str,
			   t_uint *printed,
			   int fd,
			   va_list ap);

#endif /* !PRINTF_FLAGS_H_ */
