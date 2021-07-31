# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 13:50:48 by wetieven          #+#    #+#              #
#    Updated: 2021/07/31 10:55:58 by wetieven         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# =============== #
# === TARGETS === #
# =============== #

LIB			=	libpsw.a

DEPS		=	$(SRCS:%.c=$(DDIR)%.d)
OBJS		=	$(SRCS:%.c=$(ODIR)%.o)
LIBS		=	$(shell find $(LDIR) -name '*.a' -exec basename {} ';')

EXEC		=	push_swap#checker

EOBJ		=	$(EXEC:%=$(ODIR)%.o)

### ~~~ Folders ~~~ ###

DDIR		=	deps/
ODIR		=	objs/
#ODIR		:=	$(SDIR:$(SDIR)=$(ODIR))
LDIR		=	libs/
LDIR		:=	$(shell find $(LDIR) -mindepth 1 -maxdepth 1 -type d)

SUBDIRS		=	$(ODIR) $(DDIR)

# =============== #
# === SOURCES === #
# =============== #

INCS		=	$(shell find $(HDIR) -name '*.h')
SRCS		=	algo.c push_swap.c

ESRC		=	$(EXEC:%=$(SRCS)%.c)

### ~~~ Folders ~~~ ###

HDIR		=	incs/ $(LDIR)/incs
SDIR		=	srcs/
SDIR		:=	$(shell find $(SDIR) -mindepth 1 -maxdepth 1 -type d)

vpath %.h $(HDIR)
vpath %.c $(SDIR)

vpath %.d $(DDIR)
vpath %.o $(ODIR)
vpath %.a $(LDIR)

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

all			:	make_libs $(SUBDIRS) $(OBJS) $(EXEC)

$(SUBDIRS)	:
				mkdir -p $(SUBDIRS)

# ~~~ Objects Compiling  ~~~ #

$(ODIR)%.o	:	%.c $(DDIR)%.d
				$(CC) $(CFLGS) $(CINCS) $(DEPFL) -c $< -o $@

# ~~~ Libs compiling and archiving ~~~ #

$(LIB)		:	$(OBJS)
				ar rcs $(LDIR)$(LIBS) $(OBJS)

$(LIBS)		:	make_libs

make_libs	:
				$(MAKE) -C $(LDIR)

# ~~~ Executables Compiling  ~~~ #

$(EXEC)		:	$(EOBJ)
				$(CC) $< -o $@ $(CLDIR) $(CLIBS)

# ~~~ Actions ~~~ #

norm		:
				norminette incs srcs

clean		:
				rm -rf $(ODIR)
				rm -rf $(DDIR)
#				$(MAKE) -C $(LDIR) clean

fclean		:	clean
#				$(MAKE) -C $(LDIR) fclean
#				$(RM) $(LIBS)
				$(RM) $(EXEC)

re			:	fclean all

.PHONY : all make_libs norm bonus clean fclean re

$(DEPS)		:
include $(wildcard $(DEPS))
