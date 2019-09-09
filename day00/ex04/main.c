#include "header.h"
#include <stdio.h> //printf
#include <stdlib.h> //malloc

int		howManyJesus(char *bible, char *jesus);

struct s_test {
	char	*bible;
	char	*jesus;
	int		result;
};

struct s_test	*create_test(char *bible, char *jesus, int result)
{
	struct s_test	*new;

	new = malloc(sizeof(struct s_test));
	new->bible = bible;
	new->jesus = jesus;
	new->result = result;
	return (new);
}

void	exec_test(struct s_test *test, int *test_num)
{
	int		res;

	res = howManyJesus(test->bible, test->jesus);
	if (res == test->result)
		printf("Test %d passed!\n", *test_num);
	else
		printf("Test %d failed.. expected %d and got %d\n", *test_num, test->result, res);
	*test_num += 1;
}

void	test_howManyJesus()
{
	struct s_test	*test;
	int				test_num;

	test_num = 0;

	test = create_test("This is a test", "test", 1);
	exec_test(test, &test_num);
	free(test);

	test = create_test("This is a test", " ", 3);
	exec_test(test, &test_num);
	free(test);

	test = create_test("ChriChriChriChriChriChri", "Chri", 6);
	exec_test(test, &test_num);
	free(test);

	test = create_test("ChriChriChriChriChriChri", "chri", 0);
	exec_test(test, &test_num);
	free(test);

	test = create_test("", "", 0);
	exec_test(test, &test_num);
	free(test);

	test = create_test("StriStrinStriStringStriStriStrinStrinStringStrin", "String", 2);
	exec_test(test, &test_num);
	free(test);

	test = create_test("How about a failed test?", "ok", 0);
	exec_test(test, &test_num);
	free(test);
}

void	test_bible(char *str)
{
	printf("results for %s: %d\n", str, howManyJesus(BIBLE, str));
}

int		main(int argc, char **argv)
{
	if (argc == 2){
		test_bible(argv[1]);
	} else {
		test_howManyJesus();
	}
}
