# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 13:50:48 by wetieven          #+#    #+#              #
#    Updated: 2021/06/03 10:54:27 by wetieven         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# =============== #
# === TARGETS === #
# =============== #

LIBS		=	psw.a
PRGS		=	push_swap #checker

# ~~~ Folders ~~~ #

DDIR		=	deps/
ODIR		=	objs/
LDIR		=	libs/
SUBDIRS		=	$(ODIR) $(DDIR)

vpath %.d $(DDIR)
vpath %.o $(ODIR)
vpath %.a $(LDIR)

# =============== #
# === SOURCES === #
# =============== #

SRCS		=	.c
ESRC		=	push_swap.c #checker.c

# ~~~ Folders ~~~ #

HDIR		=	incs/
SDIR		=	$(shell find srcs -type d)
LDIR		=	$(shell find libs -type d) ## Couldn't we use $(LDIR) here ?

vpath %.h $(HDIR)
vpath %.c $(SDIR)

# ~~~ Placeholders ~~~ #

INCS		=	$(shell find $(HDIR) -name '*.h')
DEPS		=	$(SRCS:%.c=$(DDIR)%.d)
OBJS		=	$(SRCS:%.c=$(ODIR)%.o)

# ====================== #
# === COMPILER SETUP === #
# ====================== #

CC			=	gcc
CFLGS		=	-Wall -Wextra -Werror -O3 -fno-builtin
DFLGS		=	-MT $@ -MMD -MP -MF $(DDIR)$*.d

CINCS		=	$(addprefix -I, $(HDIR))
CLIBS		=	$(addprefix -L, $(LDIR))

# ============= #
# === RULES === #
# ============= #

# ~~~ Default ~~~ #

all			:	$(SUBDIRS) $(LIBS) $(PRGS)

$(SUBDIRS)	:
				mkdir -p $(DDIR)
				mkdir -p $(ODIR)
				mkdir -p $(LDIR)

# ~~~ Compiling  ~~~ #

$(ODIR)%.o	:	%.c $(DDIR)%.d
				$(CC) $(CFLGS) $(CINCS) $(DFLGS) -c $< -o $@

$(PRGS)		:	$(LIBS) $(ESRC)
				$(CC) $(CFLGS) $(CINCS) $(LIBS) $(ESRC) -o $(PRGS)

# ~~~ Lib archiving ~~~ #

$(LDIR)$(LIBS)	:	$(OBJS)
					ar rcs $(LIBS) $(OBJS)

# ~~~ Actions ~~~ #

clean		:
				rm -rf $(ODIR)

fclean		:	clean
				rm -rf $(DDIR)
				$(RM) $(LIBS)

re			:	fclean all

.PHONY : all exec bonus clean fclean re

$(DEPS)		:
include $(wildcard $(DEPS))
