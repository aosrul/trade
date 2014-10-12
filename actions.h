#ifndef ACTIONS_H_
# define ACTIONS_H_


bool		is_time_to_buy(t_struct *s);
bool		is_time_to_sell(t_struct *s);
int		actions(t_struct *s);
bool		buy(t_struct *s);
bool		sell(t_struct *s);


#endif /* ACTIONS_H_ */
