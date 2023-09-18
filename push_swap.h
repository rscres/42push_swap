/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:47:42 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/18 00:10:09 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

void	swap_a(t_dbl_list **stack_a);
void	swap_a(t_dbl_list **stack_b);
void	swap_all(t_dbl_list **stack_a, t_dbl_list **stack_b);
void	rotate_a(t_dbl_list **stack_a);
void	rotate_b(t_dbl_list **stack_b);
void	rotate_all(t_dbl_list **stack_a, t_dbl_list **stack_b);


#endif //PUSH_SWAP_H