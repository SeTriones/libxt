#include "double_linked_list.h"

double_linked_list* init_list() {
	double_linked_list* ret = (double_linked_list*)malloc(sizeof(double_linked_list));
	if (!ret) {
		return NULL;
	}
	ret->header = NULL;
	ret->tail = ret->header;
	ret->node_cnt = 0;
	return ret;
}

void destroy_list(double_linked_list* lst) {
	if (lst == NULL) {
		return;
	}
	node* n = lst->header;
	node* cur;
	while (n) {
		cur = n;
		n = n->next;
		free(cur);
	}
	free(lst);
	return;
}

void mv_node_to_header(double_linked_list* lst, node* n, int is_new_node) {
	node* next = NULL;
	node* prev = NULL;
	if (is_new_node == 0) {
		if (n == lst->header) {
			return;
		}
		prev = n->prev;
		next = n->next;
		n->prev->next = next;
		if (n->next) {
			n->next->prev= prev;
		}
		if (n == lst->tail) {
			lst->tail = prev;
		}
	}
	else {
		if (1 == ++lst->node_cnt) {
			lst->tail = n;
		}
	}
	n->prev = NULL;
	n->next = lst->header;
	if (lst->header) {
		lst->header->prev = n;
	}
	lst->header = n;
	return;	
}

int rm_node_from_tail(double_linked_list* lst, int cnt) {
	node* n = lst->tail;
	node* cur;
	int ret = 0;
	while (n && cnt > 0) {
		cur = n;
		n = n->prev;
		free(cur);
		cnt--;
		lst->node_cnt--;
		ret++;
	}
	lst->tail = n;
	if (!n) {
		lst->header = NULL;
	}
	return ret; 
}
