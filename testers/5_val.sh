# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    5_val.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 20:22:54 by wetieven          #+#    #+#              #
#    Updated: 2021/09/19 20:26:52 by wetieven         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Exhaustive permutations of 5 values (5! = 120)

#!/bin/bash
# 1 2
echo "../push_swap 1 2 3 4 5"
../push_swap 1 2 3 4 5
echo "../push_swap 1 2 3 5 4"
../push_swap 1 2 3 5 4
echo "../push_swap 1 2 4 3 5"
../push_swap 1 2 4 3 5
echo "../push_swap 1 2 4 5 3"
../push_swap 1 2 4 5 3
echo "../push_swap 1 2 5 3 4"
../push_swap 1 2 5 3 4
echo "../push_swap 1 2 5 4 3"
../push_swap 1 2 5 4 3

# 1 3
echo "../push_swap 1 3 2 4 5"
../push_swap 1 3 2 4 5
echo "../push_swap 1 3 2 5 4"
../push_swap 1 3 2 5 4
echo "../push_swap 1 3 4 2 5"
../push_swap 1 3 4 2 5
echo "../push_swap 1 3 4 5 2"
../push_swap 1 3 4 5 2
echo "../push_swap 1 3 5 2 4"
../push_swap 1 3 5 2 4
echo "../push_swap 1 3 5 4 2"
../push_swap 1 3 5 4 2

# 1 4
echo "../push_swap 1 4 2 3 5"
../push_swap 1 4 2 3 5
echo "../push_swap 1 4 2 5 3"
../push_swap 1 4 2 5 3
echo "../push_swap 1 4 3 2 5"
../push_swap 1 4 3 2 5
echo "../push_swap 1 4 3 5 2"
../push_swap 1 4 3 5 2
echo "../push_swap 1 4 5 2 3"
../push_swap 1 4 5 2 3
echo "../push_swap 1 4 5 3 2"
../push_swap 1 4 5 3 2

# 1 5
echo "../push_swap 1 5 2 3 4"
../push_swap 1 5 2 3 4
echo "../push_swap 1 5 2 4 3"
../push_swap 1 5 2 4 3
echo "../push_swap 1 5 3 2 4"
../push_swap 1 5 3 2 4
echo "../push_swap 1 5 3 4 2"
../push_swap 1 5 3 4 2
echo "../push_swap 1 5 4 2 3"
../push_swap 1 5 4 2 3
echo "../push_swap 1 5 4 3 2"
../push_swap 1 5 4 3 2

# 2 1
echo "../push_swap 2 1 3 4 5"
../push_swap 2 1 3 4 5
echo "../push_swap 2 1 3 5 4"
../push_swap 2 1 3 5 4
echo "../push_swap 2 1 4 3 5"
../push_swap 2 1 4 3 5
echo "../push_swap 2 1 4 5 3"
../push_swap 2 1 4 5 3
echo "../push_swap 2 1 5 3 4"
../push_swap 2 1 5 3 4
echo "../push_swap 2 1 5 4 3"
../push_swap 2 1 5 4 3

# 2 3
echo "../push_swap 2 3 1 4 5"
../push_swap 2 3 1 4 5
echo "../push_swap 2 3 1 5 4"
../push_swap 2 3 1 5 4
echo "../push_swap 2 3 4 1 5"
../push_swap 2 3 4 1 5
echo "../push_swap 2 3 4 5 1"
../push_swap 2 3 4 5 1
echo "../push_swap 2 3 5 1 4"
../push_swap 2 3 5 1 4
echo "../push_swap 2 3 5 4 1"
../push_swap 2 3 5 4 1

# 2 4
echo "../push_swap 2 4 1 3 5"
../push_swap 2 4 1 3 5
echo "../push_swap 2 4 1 5 3"
../push_swap 2 4 1 5 3
echo "../push_swap 2 4 3 1 5"
../push_swap 2 4 3 1 5
echo "../push_swap 2 4 3 5 1"
../push_swap 2 4 3 5 1
echo "../push_swap 2 4 5 1 3"
../push_swap 2 4 5 1 3
echo "../push_swap 2 4 5 3 1"
../push_swap 2 4 5 3 1

# 2 5
echo "../push_swap 2 5 1 3 4"
../push_swap 2 5 1 3 4
echo "../push_swap 2 5 1 4 3"
../push_swap 2 5 1 4 3
echo "../push_swap 2 5 3 1 4"
../push_swap 2 5 3 1 4
echo "../push_swap 2 5 3 4 1"
../push_swap 2 5 3 4 1
echo "../push_swap 2 5 4 1 3"
../push_swap 2 5 4 1 3
echo "../push_swap 2 5 4 3 1"
../push_swap 2 5 4 3 1

# 3 1
echo "../push_swap 3 1 2 4 5"
../push_swap 3 1 2 4 5
echo "../push_swap 3 1 2 5 4"
../push_swap 3 1 2 5 4
echo "../push_swap 3 1 4 2 5"
../push_swap 3 1 4 2 5
echo "../push_swap 3 1 4 5 2"
../push_swap 3 1 4 5 2
echo "../push_swap 3 1 5 2 4"
../push_swap 3 1 5 2 4
echo "../push_swap 3 1 5 4 2"
../push_swap 3 1 5 4 2

# 3 2
echo "../push_swap 3 2 1 4 5"
../push_swap 3 2 1 4 5
echo "../push_swap 3 2 1 5 4"
../push_swap 3 2 1 5 4
echo "../push_swap 3 2 4 1 5"
../push_swap 3 2 4 1 5
echo "../push_swap 3 2 4 5 1"
../push_swap 3 2 4 5 1
echo "../push_swap 3 2 5 1 4"
../push_swap 3 2 5 1 4
echo "../push_swap 3 2 5 4 1"
../push_swap 3 2 5 4 1

# 3 4
echo "../push_swap 3 4 1 2 5"
../push_swap 3 4 1 2 5
echo "../push_swap 3 4 1 5 2"
../push_swap 3 4 1 5 2
echo "../push_swap 3 4 2 1 5"
../push_swap 3 4 2 1 5
echo "../push_swap 3 4 2 5 1"
../push_swap 3 4 2 5 1
echo "../push_swap 3 4 5 1 2"
../push_swap 3 4 5 1 2
echo "../push_swap 3 4 5 2 1"
../push_swap 3 4 5 2 1

# 3 5
echo "../push_swap 3 5 1 2 4"
../push_swap 3 5 1 2 4
echo "../push_swap 3 5 1 4 2"
../push_swap 3 5 1 4 2
echo "../push_swap 3 5 2 1 4"
../push_swap 3 5 2 1 4
echo "../push_swap 3 5 2 4 1"
../push_swap 3 5 2 4 1
echo "../push_swap 3 5 4 1 2"
../push_swap 3 5 4 1 2
echo "../push_swap 3 5 4 2 1"
../push_swap 3 5 4 2 1

# 4 1
echo "../push_swap 4 1 2 3 5"
../push_swap 4 1 2 3 5
echo "../push_swap 4 1 2 5 3"
../push_swap 4 1 2 5 3
echo "../push_swap 4 1 3 2 5"
../push_swap 4 1 3 2 5
echo "../push_swap 4 1 3 5 2"
../push_swap 4 1 3 5 2
echo "../push_swap 4 1 5 2 3"
../push_swap 4 1 5 2 3
echo "../push_swap 4 1 5 3 2"
../push_swap 4 1 5 3 2

# 4 2
echo "../push_swap 4 2 1 3 5"
../push_swap 4 2 1 3 5
echo "../push_swap 4 2 1 5 3"
../push_swap 4 2 1 5 3
echo "../push_swap 4 2 3 1 5"
../push_swap 4 2 3 1 5
echo "../push_swap 4 2 3 5 1"
../push_swap 4 2 3 5 1
echo "../push_swap 4 2 5 1 3"
../push_swap 4 2 5 1 3
echo "../push_swap 4 2 5 3 1"
../push_swap 4 2 5 3 1

# 4 3
echo "../push_swap 4 3 1 2 5"
../push_swap 4 3 1 2 5
echo "../push_swap 4 3 1 5 2"
../push_swap 4 3 1 5 2
echo "../push_swap 4 3 2 1 5"
../push_swap 4 3 2 1 5
echo "../push_swap 4 3 2 5 1"
../push_swap 4 3 2 5 1
echo "../push_swap 4 3 5 1 2"
../push_swap 4 3 5 1 2
echo "../push_swap 4 3 5 2 1"
../push_swap 4 3 5 2 1

# 4 5
echo "../push_swap 4 5 1 2 3"
../push_swap 4 5 1 2 3
echo "../push_swap 4 5 1 3 2"
../push_swap 4 5 1 3 2
echo "../push_swap 4 5 2 1 3"
../push_swap 4 5 2 1 3
echo "../push_swap 4 5 2 3 1"
../push_swap 4 5 2 3 1
echo "../push_swap 4 5 3 1 2"
../push_swap 4 5 3 1 2
echo "../push_swap 4 5 3 2 1"
../push_swap 4 5 3 2 1

# 5 1
echo "../push_swap 5 1 2 3 4"
../push_swap 5 1 2 3 4
echo "../push_swap 5 1 2 4 3"
../push_swap 5 1 2 4 3
echo "../push_swap 5 1 3 2 4"
../push_swap 5 1 3 2 4
echo "../push_swap 5 1 3 4 2"
../push_swap 5 1 3 4 2
echo "../push_swap 5 1 4 2 3"
../push_swap 5 1 4 2 3
echo "../push_swap 5 1 4 3 2"
../push_swap 5 1 4 3 2

# 5 2
echo "../push_swap 5 2 1 3 4"
../push_swap 5 2 1 3 4
echo "../push_swap 5 2 1 4 3"
../push_swap 5 2 1 4 3
echo "../push_swap 5 2 3 1 4"
../push_swap 5 2 3 1 4
echo "../push_swap 5 2 3 4 1"
../push_swap 5 2 3 4 1
echo "../push_swap 5 2 4 1 3"
../push_swap 5 2 4 1 3
echo "../push_swap 5 2 4 3 1"
../push_swap 5 2 4 3 1

# 5 3
echo "../push_swap 5 3 1 2 4"
../push_swap 5 3 1 2 4
echo "../push_swap 5 3 1 4 2"
../push_swap 5 3 1 4 2
echo "../push_swap 5 3 2 1 4"
../push_swap 5 3 2 1 4
echo "../push_swap 5 3 2 4 1"
../push_swap 5 3 2 4 1
echo "../push_swap 5 3 4 1 2"
../push_swap 5 3 4 1 2
echo "../push_swap 5 3 4 2 1"
../push_swap 5 3 4 2 1

# 5 4
echo "../push_swap 5 4 1 2 3"
../push_swap 5 4 1 2 3
echo "../push_swap 5 4 1 3 2"
../push_swap 5 4 1 3 2
echo "../push_swap 5 4 2 1 3"
../push_swap 5 4 2 1 3
echo "../push_swap 5 4 2 3 1"
../push_swap 5 4 2 3 1
echo "../push_swap 5 4 3 1 2"
../push_swap 5 4 3 1 2
echo "../push_swap 5 4 3 2 1"
../push_swap 5 4 3 2 1
