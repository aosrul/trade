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
#endif /* _MISC_H_ */
