#ifndef _MISC_H_
# define _MISC_H_

#include <stdio.h>
#include "struct.h"

#define		STR_LENGTH 10
#define		COMM 0.0015

int		my_write(char *str, int size);
void		*xmalloc(int size);
int		x_get_nbr(void);
void		xfree(void *buff);
int		my_print_infos(t_struct *s, int count, int option, FILE *file);
#endif /* _MISC_H_ */
