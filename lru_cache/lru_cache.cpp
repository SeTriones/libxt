#include "lru_cache.hpp"

LRUCache::LRUCache(int capacity):capacity(capacity){
	size = 0;
	list = (double_linked_list*)malloc(sizeof(double_linked_list));
	init_list();
}

int LRUCache::get(int key){
	it = hash.find(key);
	if(it == hash.end())	
		return -1;
	mv_node_to_header(list, it->second.node, 0);
	return it->second.value;
}

void LRUCache::set(int key, int value, int overwrite){
	it = hash.find(key);
	if(it != hash.end()) {
		if(overwrite) {
			it->second.value = value;
			mv_node_to_header(list, it->second.node, 0);
		}
		else
			mv_node_to_header(list, it->second.node, 0);
	}
	if(size == capacity) {
		node *n = rm_node_from_tail2(list);
		hash.erase(n->key);
		free(n);
		size--;
	}
	node *tmp = (node *)malloc(sizeof(node));
	tmp->key = key;
	tmp->next = NULL;
	tmp->prev = NULL;
	mv_node_to_header(list, tmp, 1);
	size++;
}
