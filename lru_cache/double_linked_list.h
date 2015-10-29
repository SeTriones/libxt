#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

typedef struct {
	node* prev;
	node* next;
} node;

typedef struct {
	node* header;
	node* tail;
	int node_cnt;
} double_linked_list;

#ifdef __cplusplus
extern "C"
{
#endif

double_linked_list* init_list();
void destroy_list(double_linked_list* lst);
int mv_node_to_header(double_linked_list* lst, node* node, int is_new_node);
int rm_node_from_tail(double_linked_list* lst, int cnt);

#ifdef __cplusplus
}
#endif

#endif
