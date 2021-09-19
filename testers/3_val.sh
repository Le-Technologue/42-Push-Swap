# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    3_val.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 20:22:48 by wetieven          #+#    #+#              #
#    Updated: 2021/09/19 20:26:37 by wetieven         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Exhaustive permutations of 3 values without duplicates (3! = 6)

#!/bin/bash

echo "../push_swap 1 2 3"
../push_swap 1 2 3
echo "../push_swap 2 1 3"
../push_swap 2 1 3
echo "../push_swap 3 1 2"
../push_swap 3 1 2
echo "../push_swap 2 3 1"
../push_swap 2 3 1
echo "../push_swap 3 2 1"
../push_swap 3 2 1
echo "../push_swap 1 3 2"
../push_swap 1 3 2
