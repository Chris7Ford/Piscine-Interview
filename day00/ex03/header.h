# define HASH_CAP 10000

struct			s_art {
	char		*name;
	int			price;
};

struct s_item { 
	char	*key;
	struct s_art	*value;
	struct s_item 	*next;
};

struct s_dict {
	struct s_item **items;
	int		capacity;
};

struct s_dict	*dictInit(int capacity);
int				dictInsert(struct s_dict *dict, char *key, struct s_art *value);
