# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 10:59:02 by lbellmas          #+#    #+#              #
#    Updated: 2025/01/21 12:03:21 by lbellmas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap.a
AR		=    ar
ARFLAGS	=    -rcs
CC		=    cc
CFLAGS	=    -g -Wall -Wextra -Werror
OFLAGS	=	-MMD -MF $(@:.o=.d)

SRCDIR	= src
DEPSDIR = deps
OBJDIR	= objs
PRINTFDIR	= printf
PRINTF	= $(PRINTFDIR)/libftprintf.a
SRCS	= ft_status.c ft_base.c ft_push.c ft_swap.c ft_rotate.c ft_rev_rotate.c ft_analisis.c ft_move.c ft_push_error.c ft_chunks.c ft_numbers.c ft_sorts.c ft_sorts_mid_top.c ft_sorts_mid_bot.c ft_sorts_min_top.c ft_sorts_min_bot.c ft_sorts_max_top.c ft_sorts_max_bot.c
OBJS	= $(addprefix $(OBJDIR)/, ${SRCS:.c=.o})
DEPS	= $(addprefix $(DEPSDIR)/, ${SRCS:.c=.d})
MAIN	= ft_push_swap.c

RED         	= \033[0;31m
GREEN       	= \033[0;32m
YELLOW      	= \033[0;33m
BLUE        	= \033[0;34m
PURPLE      	= \033[0;35m
CYAN        	= \033[0;36m
RESET			= \033[m

all: $(NAME)
	$(CC) -g -Wall -Wextra -Werror $(MAIN) $(NAME)

-include $(DEPS)

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.c | $(OBJDIR) $(DEPSDIR)
	@printf "%-42b%b" "$(PURPLE)$(<):" "$(BLUE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@
	@mv objs/*.d deps/

$(OBJDIR):
	@mkdir $(OBJDIR)

$(DEPSDIR):
	@mkdir $(DEPSDIR)

$(PRINTF):
	@printf "%b" "$(BLUE)$(@F)$(RESET)\n"
	@$(MAKE) --silent -C $(PRINTFDIR) 

$(NAME): $(OBJS) $(PRINTF) 
	@printf "%-42b%b" "$(PURPLE)$(<):" "$(BLUE)$(@F)$(RESET)\n"
	@cp $(PRINTF) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	@printf "%b" "$(BLUE)push_swap $(@)ing...$(RESET)\n"
	@rm -rf $(OBJDIR)
	@rm -rf $(DEPSDIR)
	@$(MAKE) -C $(PRINTFDIR) clean --silent

fclean: clean
	@printf "%b" "$(BLUE)push_swap $(@)ing...$(RESET)\n"
	@rm a.out
	@rm -rf $(NAME)
	@$(MAKE) -C $(PRINTFDIR) fclean --silent

re: fclean all

bonus: all

.PHONY: all clean fclean re $(PRINTF)
