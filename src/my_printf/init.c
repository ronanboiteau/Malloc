#include "printf_flags.h"

int		init_flag(char flag_char,
			  t_uint (*fct)(int fd,
					t_uint printed,
					va_list ap),
			  t_flag *flags)
{
  flags->flag_char = flag_char;
  flags->fct = fct;
  return (0);
}

void		init_structures(t_flag *flags,
				t_cstring *str,
				const char *format)
{
  str->str = format;
  str->idx = 0;
  init_flag('c', &print_char, &flags[0]);
  init_flag('n', &ptr_printed_chars, &flags[1]);
  init_flag('S', &str_non_printable, &flags[2]);
  init_flag('i', &print_int, &flags[3]);
  init_flag('d', &print_int, &flags[4]);
  init_flag('b', &convert_binary, &flags[5]);
  init_flag('s', &print_str, &flags[6]);
  init_flag('x', &convert_hex_lowcase, &flags[7]);
  init_flag('X', &convert_hex_upcase, &flags[8]);
  init_flag('o', &convert_octal, &flags[9]);
  init_flag('u', &convert_decimal, &flags[10]);
  init_flag('p', &ptr_to_hex, &flags[11]);
  return ;
}
