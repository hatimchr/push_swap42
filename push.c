/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchair <hchair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 06:41:33 by hchair            #+#    #+#             */
/*   Updated: 2024/07/04 06:57:59 by hchair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char *argv[])
{
    char **arg;
    
    if (ac < 2)
        return (write(1, "Error\n", 6));
    arg = ft_split(argv, ' ');
}