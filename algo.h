#ifndef	        ALGO_H_
# define	ALGO_H_

#include "struct.h"

#define LIMIT	100
#define MACD1	12
#define MACD2	26
#define	N	2

int		main_loop(t_struct *s);
int		actions(t_struct *s);
int		get_data(t_struct *s, int size, int i);

#endif		/* ALGO_H_ */
