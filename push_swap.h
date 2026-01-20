/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falamlih <falamlih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 09:30:50 by falamlih          #+#    #+#             */
/*   Updated: 2026/01/17 15:45:29 by falamlih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_ilist
{
	long			value;
	int				rank;
	struct s_ilist	*next;
}					t_ilist;

int					alloc(long *dup, int l, long **arr);
int					ft_parse(const char *str, long **arr);
long				ft_atoi(const char *nptr);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_isdigit(int c);
char				**ft_split(char const *s, char c);
int					ft_arv(char **arv);
t_ilist				*ft_list(int arc, char **arv);
void				pa(t_ilist **alist, t_ilist **blist);
void				pac(t_ilist **alist, t_ilist **blist);
void				ss(t_ilist **alist, t_ilist **blist);
void				rr(t_ilist **lista, t_ilist **listb);
void				rb(t_ilist **list);
void				ra(t_ilist **list);
void				pb(t_ilist **alist, t_ilist **blist);
void				pbc(t_ilist **alist, t_ilist **blist);
void				rotate(t_ilist **list);
void				rrb(t_ilist **list);
void				rrr(t_ilist **lista, t_ilist **listb);
void				swap(t_ilist **list);
void				reverse(t_ilist **list);
int					ft_lstsize(t_ilist *lst);
t_ilist				*ft_stackb(int arc, char **arv, int push);
int					ft_max(t_ilist *stackb);
void				ft_error(void);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_join(char *s1, char const *s2);
void				free_split(char **st);
void				free_list(t_ilist *stack);
t_ilist				*ft_checker(int arc, char **arv);
t_ilist				*is_sorted(t_ilist *stacka);
int					num(int arc, char **arv, t_ilist **stacka);
void				ft_five(t_ilist **stack, t_ilist **stackb);
void				ft_th_four(t_ilist **stack, t_ilist **stackb);
void				sa(t_ilist **stacka);
void				rra(t_ilist **list);

#endif