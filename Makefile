# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 14:24:15 by sel-fcht          #+#    #+#              #
#    Updated: 2021/11/17 14:29:25 by sel-fcht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = *.c 
NAME = philosopher
FLAGs = -Wall -Werror -Wextra 


all: $(NAME)

$(NAME) : $(SRC)
	gcc $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean



norm:
	norminette

push:
	git add .
	git commit -m "philox"
	git push
re: fclean all
