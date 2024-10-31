NAME=a.out
SRCS=dp1_2.cpp
$(NAME):
	c++ $(SRCS) -o $(NAME)
d:
	c++ -g -fsanitize=address $(SRCS)
test:
	@bash test.sh
clean:
	rm $(NAME)
re: clean
	make