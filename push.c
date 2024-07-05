/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchair <hchair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 06:41:33 by hchair            #+#    #+#             */
/*   Updated: 2024/07/05 10:57:29 by hchair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char *argv[])
{
    int i;
    char **arg;
    
    i = 1;
    if (ac < 2)
        return (write(1, "Error\n", 6));
    arg = ft_split(argv, ' ');
    while (arg[i] != NULL)
    {
        ft_printf("[%s] ", arg[i]);
        i++;
        // ft_printf("(%d) ", i);
    }
    
}