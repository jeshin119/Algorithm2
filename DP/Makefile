NAME=a.out
SRCS=dp1_retry.cpp
CMP=dp1_3.cpp
$(NAME):
	c++ $(SRCS) -o $(NAME)
	c++ $(CMP) -o cmp
d:
	c++ -g -fsanitize=address $(SRCS)
test:
	@bash test.sh
clean:
	rm $(NAME)
re: clean
	make