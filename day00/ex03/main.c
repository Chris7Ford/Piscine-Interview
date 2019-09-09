#include "header.h"

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include <string.h>

struct s_test
{
	char	*name;
	int		result;
};

int		searchPrice(struct s_dict *dict, char *name);

int		count_art(char *filename)
{
	int		count = 0;
	FILE 	*fp = fopen(filename, "r");
	char 	buffer[1024];

	if (fp == 0)
		return -1;
	while (fgets(buffer, sizeof(buffer), fp) != 0)
		count++;
	fclose(fp);
	return (count);
}

int		get_index_of_split(char *str, char split)
{
	int i = 0;
	while (str[i] != split && str[i] != '\0')
		i++;
	return (i);
}

struct s_art	*create_node(char *title, int price)
{
	struct s_art	*elem;

	elem = malloc(sizeof(struct s_art));
	elem->name = title;
	elem->price = price;
	return (elem);
}

struct s_test create_test(char *name, int result)
{
	struct s_test test;
	test.name = name;
	test.result = result;
	return (test);
}

void	fill_array(struct s_art **arr, int works_count, char *filename)
{
	FILE 			*fp = fopen(filename, "r");
	char 			buffer[1024];
	char			*art;
	int				price;
	int				split_index;

	if (fp == 0)
		return ;
	//longest art work is 789 characters long
	for (int i = 0; i < works_count; i++)
	{
		fgets(buffer, sizeof(buffer), fp);
		buffer[strlen(buffer) - 1] = '\0';
		split_index = get_index_of_split(buffer, '=');
		art = strndup(buffer, split_index - 1);
		price = atoi(buffer + split_index + 3);
		arr[i] = create_node(art, price);
	}
	fclose(fp);
}

void	print_array(struct s_art **arr, int works_count)
{
	for (int i = 0; i < works_count; i++)
		printf("Artpiece: %s, price: %d\n", arr[i]->name, arr[i]->price);
}

void	free_it(struct s_art ***arr)
{
	for (int i = 0; (*arr)[i]; i++)
		free((*arr)[i]);
	free(*arr);
}

void	run_searchPriceV3_test(struct s_dict *dict, struct s_test test, int *testNum)
{
	int res = searchPrice(dict, test.name);
	if (test.result == res)
		printf("Test %d passed!\n", *testNum);
	else
		printf("Test %d failed! Expected %d and got %d\n", *testNum, test.result, res);
	*testNum += 1;
}

void	test_searchPriceV3(struct s_dict *dict, struct s_art **arr)
{
	int		testNum = 1;
	int		size;

	size = 0;
	while (arr[size])
		size++;
	run_searchPriceV3_test(dict, create_test("Paintings, Seong Moy", 1819821),&testNum);
	run_searchPriceV3_test(dict, create_test("Mona Lisa", 2000000000),&testNum);
	run_searchPriceV3_test(dict, create_test("I dont exist", -1),&testNum);
	run_searchPriceV3_test(dict, create_test("Handles Protect Hands", 7589816),&testNum);
	run_searchPriceV3_test(dict, create_test("Gravesend", 15335027),&testNum);
	run_searchPriceV3_test(dict, create_test("Repeat of pictorial initial A from page 128 (page 294) from LES PETITES FLEURS", 16850219),&testNum);
	run_searchPriceV3_test(dict, create_test("JOHN CHAPMAN PULLS OFF THE HIGHWAY TOWARDS KENTUCKY & CASTS A COLD EYE ON THE MOST ASTONISHING SIGN IN RECENT AMERICAN LETTERS", 53691),&testNum);
	run_searchPriceV3_test(dict, create_test("THE CORSET MAKER IN SOLOMON'S HAREM (double page plate, between pages 70 and 71) from AUS DEN MEMOIREN DES HERRN VON SCHNABELEWOPSKY", 11061766),&testNum);
	run_searchPriceV3_test(dict, create_test("Hot Dog Plans 16", 12958618),&testNum);
	run_searchPriceV3_test(dict, create_test("Another fake one shoudl be -1", -1),&testNum);
	run_searchPriceV3_test(dict, create_test("American Gothic", 80000000),&testNum);
	run_searchPriceV3_test(dict, create_test("Icy Night, New York", 10571848),&testNum);
	run_searchPriceV3_test(dict, create_test("Draft of the project description from Moveable type no documenta, “For ten days I visited people in Kassel, Germany…,” published in Prospectus 1998-2010. Forty-two works by Ben Kinmont", 11236643),&testNum);
}

int		main(int argc, char **argv)
{
	struct s_art	**arr;
	struct s_dict	*dict;

	if (argc == 2)
	{
		int works_count = count_art(argv[1]);
		arr = malloc(sizeof(struct s_art *) * (works_count + 1));
		fill_array(arr, works_count, argv[1]);
		arr[works_count] = 0;
//		print_array(arr, works_count);
//		sortArts(arr);
		dict = dictInit(HASH_CAP);
		for (int i = 0; arr[i]; i++)
			dictInsert(dict, arr[i]->name, arr[i]);
		test_searchPriceV3(dict, arr);
		free_it(&arr);
	}
	return (0);
}
