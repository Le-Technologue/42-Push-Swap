# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 13:50:48 by wetieven          #+#    #+#              #
#    Updated: 2021/07/21 17:42:39 by wetieven         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# =============== #
# === TARGETS === #
# =============== #

LIBS		=	psw.a
PRGS		=	push_swap #checker

DEPS		=	$(SRCS:%.c=$(DDIR)%.d)
OBJS		=	$(SRCS:%.c=$(ODIR)%.o)
LIBS		=	$(shell find $(LDIR) -name '*.a' -exec basename {} ';')

### ~~~ Folders ~~~ ###

DDIR		=	deps/
ODIR		=	objs/
LDIR		=	libs/

## ~~~ Placeholders ~~~ ##

SUBDIRS		=	$(ODIR) $(DDIR)
LDIR		:=	$(shell find $(LDIR) -mindepth 1 -maxdepth 1 -type d)

# =============== #
# === SOURCES === #
# =============== #

INCS		=	$(shell find $(HDIR) -name '*.h')
SRCS		=	.c
ESRC		=	push_swap.c #checker.c

### ~~~ Folders ~~~ ###

HDIR		=	incs/
SDIR		=	srcs/

## ~~ Placeholders ~~ ##

HDIR		:=	$(LDIR)/incs # ~ Library headers folders
SDIR		=	$(shell find srcs -type d)

vpath %.h $(HDIR)
vpath %.c $(SDIR)

vpath %.d $(DDIR)
vpath %.o $(ODIR)
vpath %.a $(LDIR)

# ~~~ Placeholders ~~~ #

DEPS		=	$(SRCS:%.c=$(DDIR)%.d)
OBJS		=	$(SRCS:%.c=$(ODIR)%.o)

# ====================== #
# === COMPILER SETUP === #
# ====================== #

CC			=	gcc

WRNFL		=	-Wall -Wextra -Werror
OPTFL		=	-O3 -march=native #-fno-builtin
DBGFL		=	-g
CFLGS		=	$(WRNFL) $(OPTFL)#$(DBGFL)
DEPFL		=	-MT $@ -MMD -MP -MF $(DDIR)$*.d

CINCS		=	$(addprefix -I, $(HDIR))
CLDIR		=	$(addprefix -L, $(LDIR))
CLIBS		=	$(LIBS:lib%.a=-l%)

# ============= #
# === RULES === #
# ============= #

# ~~~ Default ~~~ #

all			:	make_libs $(SUBDIRS) $(OBJS) #executables

$(SUBDIRS)	:
				mkdir -p $(DDIR)
				mkdir -p $(ODIR)
				mkdir -p $(LDIR)

# ~~~ Compiling  ~~~ #

$(ODIR)%.o	:	%.c $(DDIR)%.d
				$(CC) $(CFLGS) $(CINCS) $(DEPFL) -c $< -o $@

$(LIBS)		:	make_libs

make_libs	:
				$(MAKE) -C $(LDIR)

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

.PHONY : all make_libs bonus clean fclean re

$(DEPS)		:
include $(wildcard $(DEPS))
