# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 14:17:48 by lbellmas          #+#    #+#              #
#    Updated: 2024/11/28 10:51:15 by lbellmas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
AR		=    ar
ARFLAGS	=    -rcs
CC		=    cc
CFLAGS	=    -g -Wall -Wextra -Werror -MMD -MF $(@:.o=.d)

SRCDIR	= src
DEPSDIR = deps
OBJDIR	= objs
LIBFTDIR	= libft
LIBFT	= $(LIBFTDIR)/libft.a
SRCS	= ft_printf.c ft_printf_utils.c ft_printf_utils2.c ft_printf_bonus.c ft_printf_calculate.c ft_printf_calculate_falgs.c ft_printf_cases.c ft_printf_cases_bonus.c ft_printf_cases_bonus2.c ft_printf_malloc.c
OBJS	= $(addprefix $(OBJDIR)/, ${SRCS:.c=.o})
DEPS	= $(addprefix $(DEPSDIR)/, ${SRCS:.c=.d})

RED         	= \033[0;31m
GREEN       	= \033[0;32m
YELLOW      	= \033[0;33m
BLUE        	= \033[0;34m
PURPLE      	= \033[0;35m
CYAN        	= \033[0;36m
RESET			= \033[m

all: $(NAME) 

-include $(DEPS)

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.c | $(OBJDIR) $(DEPSDIR)
	@printf "%-42b%b" "$(PURPLE)$(<):" "$(BLUE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@
	@mv objs/*.d deps/

$(OBJDIR):
	@mkdir $(OBJDIR)

$(DEPSDIR):
	@mkdir $(DEPSDIR)

$(LIBFT):
	@printf "%b" "$(BLUE)$(@F)$(RESET)\n"
	@$(MAKE) --silent -C $(LIBFTDIR) 

$(NAME): $(OBJS) $(LIBFT) 
	@printf "%-42b%b" "$(PURPLE)$(<):" "$(BLUE)$(@F)$(RESET)\n"
	@cp $(LIBFT) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	@printf "%b" "$(BLUE)$(@)ing...$(RESET)\n"
	@rm -rf $(OBJDIR)
	@rm -rf $(DEPSDIR)
	@$(MAKE) -C $(LIBFTDIR) clean --silent

fclean: clean
	@printf "%b" "$(BLUE)$(@)ing...$(RESET)\n"
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean --silent

re: fclean all

bonus: all

.PHONY: all clean fclean re $(LIBFT)
