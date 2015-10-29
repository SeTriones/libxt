#include "double_linked_list.h"

double_linked_list* init_list() {
	double_linked_list* ret = (double_linked_list*)malloc(sizeof(double_linked_list));
	if (!ret) {
		return NULL;
	}
	ret->header = (node*)malloc(sizeof(node));
	ret->tail = ret->header;
	ret->node_cnt = 0;
	return ret;
}

void destroy_list(double_linked_list* lst) {
	if (lst == NULL) {
		return;
	}
	node* n = lst->header->next;
	node* cur;
	while (!n) {
		cur = n;
		n = n->next;
		free(cur);
	}
	free(node->header);
	free(lst);
	return;
}

int mv_node_to_header(double_linked_list* lst, node* n, int is_new_node) {
	node* next = NULL;
	node* prev = NULL;
	if (is_new_node == 0) {
		prev = n->prev;
		next = n->next;
		n->prev->next = next;
		if (n->next) {
			n->next->prev= prev;
		}
	}
	n->next = lst->header->next;
	n->prev = lst->header;
	return 0;	
}

int rm_node_from_tail(double_linked_list* lst, int cnt) {
}
