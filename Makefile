# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 13:50:48 by wetieven          #+#    #+#              #
#    Updated: 2021/08/01 22:17:33 by wetieven         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# =============== #
# === TARGETS === #
# =============== #

#LIB			=	libpsw.a
EXEC		=	push_swap#checker
#BONUS		=	checker

## ~~ Folders ~~ ##

DDIR		=	deps/
ODIR		=	objs/

# =============== #
# === SOURCES === #
# =============== #

SRCS		=	push_swap.c \
				algo.c 

## ~~ Folders ~~ ##

HDIR		=	incs/ $(LDIR)/incs
SDIR		=	srcs/

# ================= #
# === RESOURCES === #
# ================= #

LDIR		=	libs/
RSRC		=	libs/

# ==================== #
# === PLACEHOLDERS === #
# ==================== #

### ~~~ TARGETS ~~~ ###

DEPS		=	$(SRCS:%.c=$(DDIR)%.d)
OBJS		=	$(SRCS:%.c=$(ODIR)%.o)
LIBS		=	$(shell find $(LDIR) -name '*.a' -exec basename {} ';')

EOBJ		=	$(EXEC:%=$(ODIR)%.o)

## ~~ Folders ~~ ##

LDIR		:=	$(shell find $(LDIR) -mindepth 1 -maxdepth 1 -type d)

#SUBDIRS		=	$(SDIR:srcs/%=$(ODIR)%) $(SDIR:srcs/%=$(DDIR)%)
SUBDIRS		=	$(ODIR) $(DDIR)

### ~~~ SOURCES ~~~ ###

INCS		=	$(shell find $(HDIR) -name '*.h')
#SRCS		:=	$(realpath $(SRCS))

ESRC		=	$(EXEC:%=$(SRCS)%.c)

## ~~ Folders ~~ ##

SDIR		:=	$(shell find $(SDIR) -mindepth 1 -maxdepth 1 -type d)

SUBMAKES	=	$(shell find $(RSRC) -mindepth 1 -maxdepth 1 -type d)

vpath %.d $(DDIR)
vpath %.o $(ODIR)
vpath %.a $(LDIR)

vpath %.h $(HDIR)
vpath %.c $(SDIR)

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

# ~~~ Library archiving ~~~ #

$(LIB)		:	$(OBJS)
				ar rcs $(LDIR)$(LIB) $(OBJS)

$(LIBS)		:	make_libs

make_libs	:
				$(MAKE) -C $(SUBMAKES)

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
