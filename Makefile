.PHONY : clean test

compile : test.cpp check_op.h
	${CXX} test.cpp -o test -g

test :
	./test
clean :
	rm test
