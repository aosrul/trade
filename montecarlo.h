#ifndef		MONTECARLO_H_
# define	MONTECARLO_H_

double		montecarlo(int spot, double vol, double mu);

#ifndef		RAND_MAX
# define	RAND_MAX 2147483647
#endif	     

#ifndef		N_SIM
# define	N_SIM 10000
#endif

#ifndef		N_DAYS
# define	N_DAYS 10
#endif	     

#endif		/* MONTECARLO_H_ */
