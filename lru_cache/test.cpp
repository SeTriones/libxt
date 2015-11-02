#include <stdio.h>
#include <stdlib.h>
#include "lru_cache.hpp"

// test lru cache
int main(int argc, char* argv[]) {
	fprintf(stderr,"test\n");
	FILE *fp = fopen("in","r");
	int size,key,val;
	fscanf(fp,"%d",&size);
	LRUCache *lru = new LRUCache(size);
	char cmd[10];
	while(fscanf(fp,"%s ",cmd) !=EOF){
		if(strcmp(cmd,"set")==0){
			fscanf(fp,"%d,%d\n",&key,&val);
			lru->set(key,val);
		}
		else {
			fscanf(fp,"%d\n",&key);
			fprintf(stderr,"get %d = %d\n",key,lru->get(key));
		}
	}
	return 0;
}
