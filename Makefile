# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 10:59:02 by lbellmas          #+#    #+#              #
#    Updated: 2025/01/25 18:55:08 by lbellmas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = push_swap.a
AR       = ar
ARFLAGS  = -rcs
CC       = cc
CFLAGS   = -Wall -Wextra -Werror
OFLAGS   = -MMD -MF $(@:.o=.d)

SRCDIR   = src
UTILSDIR = utils
SORTSDIR = sorts
MOVEDIR  = movements
DEPSDIR  = deps
OBJDIR   = objs
OUTILSDIR = $(OBJDIR)/outils
OSORTSDIR = $(OBJDIR)/osorts
OMOVEDIR  = $(OBJDIR)/omove
PRINTFDIR = printf

PRINTF   = $(PRINTFDIR)/libftprintf.a
MOVE     = ft_push.c ft_rev_rotate.c ft_rotate.c ft_swap.c
SORTS    = ft_sorts.c ft_sorts_mid_top.c ft_sorts_mid_bot.c \
           ft_sorts_min_bot.c ft_sorts_min_top.c ft_sorts_max_top.c \
           ft_sorts_max_bot.c ft_sorts_mis_min.c
UTILS    = ft_base.c ft_numbers.c ft_push_error.c ft_status.c
SRCS     = ft_analisis.c ft_move.c

OUTILS   = $(addprefix $(OUTILSDIR)/, $(UTILS:.c=.o))
OSORTS   = $(addprefix $(OSORTSDIR)/, $(SORTS:.c=.o))
OMOVE    = $(addprefix $(OMOVEDIR)/, $(MOVE:.c=.o))
OBJS     = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
DEPS     = $(addprefix $(DEPSDIR)/, $(SRCS:.c=.d) $(MOVE:.c=.d) $(SORTS:.c=.d) $(UTILS:.c=.d))
MAIN     = ft_push_swap.c

RED      = \033[0;31m
GREEN    = \033[0;32m
YELLOW   = \033[0;33m
BLUE     = \033[0;34m
PURPLE   = \033[0;35m
CYAN     = \033[0;36m
RESET    = \033[m

all: $(NAME)
	$(CC) $(CFLAGS) -g $(MAIN) $(NAME) -o push_swap

-include $(DEPS)

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.c | $(OBJDIR) $(DEPSDIR)
	@printf "%-42b%b" "$(PURPLE)$<:" "$(BLUE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@
	@mv objs/*.d deps/

$(OUTILS): $(OUTILSDIR)/%.o : $(UTILSDIR)/%.c | $(OUTILSDIR) $(DEPSDIR)
	@printf "%-42b%b" "$(PURPLE)$<:" "$(BLUE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@
	@mv $(OUTILSDIR)/*.d deps/

$(OSORTS): $(OSORTSDIR)/%.o : $(SORTSDIR)/%.c | $(OSORTSDIR) $(DEPSDIR)
	@printf "%-42b%b" "$(PURPLE)$<:" "$(BLUE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@
	@mv $(OSORTSDIR)/*.d deps/

$(OMOVE): $(OMOVEDIR)/%.o : $(MOVEDIR)/%.c | $(OMOVEDIR) $(DEPSDIR)
	@printf "%-42b%b" "$(PURPLE)$<:" "$(BLUE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@
	@mv $(OMOVEDIR)/*.d deps/

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OUTILSDIR):
	@mkdir -p $(OUTILSDIR)

$(OSORTSDIR):
	@mkdir -p $(OSORTSDIR)

$(OMOVEDIR):
	@mkdir -p $(OMOVEDIR)

$(DEPSDIR):
	@mkdir -p $(DEPSDIR)

$(PRINTF):
	@printf "%b" "$(BLUE)$(@F)$(RESET)\n"
	@$(MAKE) --silent -C $(PRINTFDIR)

$(NAME): $(OBJS) $(PRINTF) $(OMOVE) $(OUTILS) $(OSORTS)
	@printf "%-42b%b" "$(PURPLE)$<:" "$(BLUE)$(@F)$(RESET)\n"
	@cp $(PRINTF) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OMOVE) $(OSORTS) $(OUTILS)

clean:
	@printf "%b" "$(BLUE)Cleaning objects...$(RESET)\n"
	@rm -rf $(OBJDIR)
	@rm -rf $(DEPSDIR)
	@rm -rf $(OMOVEDIR)
	@rm -rf $(OSORTSDIR)
	@rm -rf $(OUTILSDIR)
	@$(MAKE) -C $(PRINTFDIR) clean --silent

fclean: clean
	@printf "%b" "$(BLUE)Cleaning all files...$(RESET)\n"
	@rm -f push_swap
	@rm -f $(NAME)
	@$(MAKE) -C $(PRINTFDIR) fclean --silent

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus $(PRINTF)
