#include <tr1/unordered_map>
#include "double_linked_list.h"

struct HashItem{
	__node *node;
	int value;
};

class LRUCache{
public:
	LRUCache(int capacity);

	int get(int key);

	void set(int key, int value, int overwrite=0);

private:

	int size;
	int capacity;
	double_linked_list *list;
	std::tr1::unordered_map<int, struct HashItem> hash;
	std::tr1::unordered_map<int, struct HashItem>::iterator it;
};
