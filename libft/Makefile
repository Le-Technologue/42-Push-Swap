# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 13:50:48 by wetieven          #+#    #+#              #
#    Updated: 2021/09/16 21:25:28 by wetieven         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# =============== #
# === TARGETS === #
# =============== #

NAME		=	libft.a

ODIR		=	objs/
DDIR		=	deps/
SUBDIRS		=	$(ODIR) $(DDIR)

# =============== #
# === SOURCES === #
# =============== #

HDIR		=	incs/
SDIR		=	srcs/
SDIR		:=	$(shell find $(SDIR) -type d)

vpath %.h $(HDIR)
vpath %.c $(SDIR)
vpath %.d $(DDIR)
vpath %.o $(ODIR)


# ~~~ Placeholders ~~~ #

INCS		=	$(shell ls $(HDIR))
DEPS		=	$(SRCS:%.c=$(DDIR)%.d)
OBJS		=	$(SRCS:%.c=$(ODIR)%.o)

# ~~~ Main fonctions and additional functions ~~~ #
	# ~~~ sorted by chronological order ~~~ #

SRCS		=	ft_memchr.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_isupper.c \
				ft_islower.c \
				ft_isspace.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strlen.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_strcpy.c \
				ft_substr.c \
				ft_strtrim.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_digit_count.c \
				ft_itoa.c \
				ft_putnbr_fd.c \
				ft_strjoin.c \
				ft_word_count.c \
				ft_split.c \
				new_node.c \
				lst_push.c \
				lst_size.c \
				last_node.c \
				lst_queue.c \
				free_node.c \
				free_lst.c \
				lst_iter.c \
				lst_map.c \
				ft_in_da_base.c \
				ft_valid_base.c \
				ft_ltoa_base.c \
				ft_atol_base.c \
				ft_sztoa_base.c \
				ft_udigit_count.c \
				get_next_line.c \
				get_next_line_utils.c \
				ptr_atoi.c \
				fd_opener.c \
				fd_killer.c \
				vectors.c \
				fd_to_vctr.c \
				new_dln.c \
				dll_push.c \
				dll_queue.c \
				ft_swap.c \
				dln_pop.c \
				ft_isnumbr.c \
				ptr_atol_base.c \
				mrg_sort.c \
				chk_dupl.c \
				rotate_arrays.c \
				ft_printf.c \
				ptf_parsing.c \
				ptf_typecasting.c \
				ptf_text.c \
				ptf_integers.c \
				ptf_hexa.c \
				ptf_padding.c \
				stdin_gnl.c

# ====================== #
# === COMPILER SETUP === #
# ====================== #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g#-O3 -fno-builtin
CINCS		=	$(addprefix -I, $(HDIR))
DFLAGS		=	-MT $@ -MMD -MP -MF $(DDIR)$*.d


# ============= #
# === RULES === #
# ============= #

# ~~~ Default ~~~ #

all			:	$(SUBDIRS) $(NAME)

$(SUBDIRS)	:
				mkdir -p $(ODIR)
				mkdir -p $(DDIR)

# ~~~ Compiling  ~~~ #

$(ODIR)%.o	:	%.c $(DDIR)%.d
				$(CC) $(CFLAGS) $(CINCS) $(DFLAGS) -c $< -o $@

# ~~~ Lib archiving ~~~ #

$(NAME)		:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

# ~~~ Actions ~~~ #

norm		:
				norminette incs srcs

clean		:
				rm -rf $(ODIR)

fclean		:	clean
				rm -rf $(DDIR)
				$(RM) $(NAME)

re			:	fclean all

.PHONY : all norm bonus clean fclean re

$(DEPS)		:
include $(wildcard $(DEPS))
