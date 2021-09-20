# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 13:50:48 by wetieven          #+#    #+#              #
#    Updated: 2021/09/20 09:23:27 by wetieven         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# =============== #
# === TARGETS === #
# =============== #

#LIB			=	libpsw.a

EXEC		=	push_swap
BONUS		=	checker

## ~~ Folders ~~ ##

DDIR		=	deps/
ODIR		=	objs/

# =============== #
# === SOURCES === #
# =============== #

SRCS		=	push_swap.c \
				psw_parsing.c \
				psw_inst.c \
				psw_push.c \
				psw_swap.c \
				psw_rotate.c \
				psw_rev_rotate.c \
				psw_algo.c \
				psw_five_srt.c \
				psw_probes.c \
				psw_inst_mngr.c \
				psw_qcksrt.c \
				psw_inssrt.c \
				psw_monitor.c \
				psw_chk_dupl.c \
				checker.c

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

OBJS		=	$(SRCS:%.c=$(ODIR)%.o)

DEPS		=	$(SRCS:%.c=$(DDIR)%.d)

LIBS		=	$(shell find $(LDIR) -name '*.a')
LNAMES		=	$(shell find $(LDIR) -name '*.a' -exec basename {} ';')

EOBJ		=	$(EXEC:%=$(ODIR)%.o)
BOBJ		=	$(BONUS:%=$(ODIR)%.o)

SOBJ		:=	$(filter-out $(EOBJ) $(BOBJ),$(OBJS))

## ~~ Folders ~~ ##

LDIR		:=	$(shell find $(LDIR) -mindepth 1 -maxdepth 1 -type d)

SUBDIRS		=	$(ODIR) $(DDIR)
#SUBDIRS		=	$(SDIR:srcs/%=$(ODIR)%) $(SDIR:srcs/%=$(DDIR)%)

### ~~~ SOURCES ~~~ ###

INCS		=	$(shell find $(HDIR) -name '*.h')
#SRCS		:=	$(realpath $(SRCS))

ESRC		=	$(EXEC:%=$(SRCS)%.c)

## ~~ Folders ~~ ##

SDIR		:=	$(shell find $(SDIR) -mindepth 1 -maxdepth 1 -type d)

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
OPTFL		=	-O3 -march=native#-fno-builtin
DBGFL		=	-g
CFLGS		=	$(WRNFL) $(DBGFL) $(OPTFL)
DEPFL		=	-MT $@ -MMD -MP -MF $(DDIR)$*.d

CINCS		=	$(addprefix -I, $(HDIR))
CLDIR		=	$(addprefix -L, $(LDIR))
CLIBS		=	$(LNAMES:lib%.a=-l%)

# ============= #
# === RULES === #
# ============= #

# ~~~ Default ~~~ #

all			:	make_libs $(SUBDIRS) $(EXEC)

$(SUBDIRS)	:
				mkdir -p $(SUBDIRS)

# ~~~ Objects Compiling  ~~~ #

$(ODIR)%.o	:	%.c $(DDIR)%.d
				$(CC) $(CFLGS) $(CINCS) $(DEPFL) -c $< -o $@

# ~~~ Library archiving ~~~ #

#$(LIB)		:	$(SOBJ)
#				ar rcs $(LDIR)$(LIB) $?

$(LIBS)		:	make_libs

make_libs	:
				$(MAKE) -C $(LDIR)

# ~~~ Executables Compiling  ~~~ #

$(EXEC)		:	$(EOBJ) $(SOBJ) $(LIBS)
				$(CC) $^ -o $@ $(CLDIR) $(CLIBS)

$(BONUS)	:	$(BOBJ) $(SOBJ) $(LIBS)
				$(CC) $^ -o $@ $(CLDIR) $(CLIBS)

# ~~~ Actions ~~~ #

bonus		:	make_libs $(SUBDIRS) $(BONUS)

norm		:
				norminette incs srcs

clean		:
				rm -rf $(ODIR)
				$(MAKE) -C $(LDIR) clean

fclean		:	clean
				rm -rf $(DDIR)
				$(MAKE) -C $(LDIR) fclean
				$(RM) $(EXEC)
				$(RM) $(BONUS)
				$(RM) $(LIBS)

re			:	fclean all

.PHONY : all make_libs norm bonus clean fclean re

$(DEPS)		:
include $(wildcard $(DEPS))
