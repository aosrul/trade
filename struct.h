#ifndef			STRUCT_H_
# define		STRUCT_H_

typedef struct		s_struct
{
  double		macd1;			/* macd (moving average convergence/divergence) at 12 days */
  double		macd2;			/* macd at 26 days */
  double		macd;			/* macd2 - macd1 */
  double		weighted_mean;		/* weighted arithmetic mean */
  double		mean;			/* arithmetic mean */
  double		std_dev;		/* standard deviation */
  double		variance;		/* variance */
  double		bollinger_high;		/* highest Bollinger band */
  double		bollinger_low;		/* lowest bollinger band */
  double		forward;		/* forward price of the stock */
  double		volatility;		/* current volatility of the stock*/
  double	        high_peak;		/* current std_dev added to the spot */
  double	        low_peak;		/* current std_dev subtracted to the spot */
  int			nb_bought;		/* number of stock bought */	       
  int			nb_to_sell;		/* number of stock to sell */		
  int			nb_to_buy;		/* number of stock to buy */
  int			spot;			/* current value of the stock */
  int			money;			/* initial capital */
  int			days;			/* total number of days */
  int			count;			/* current day */
  int			price;			/* price of the transaction */
  int			*spot_array;		/* array of spot values */
}			t_struct;

#endif			/* STRUCT_H_ */
