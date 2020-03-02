#include "head.h"

int main(void) {
	Link link;
	make_name();
	link.Gethead();


	for(int i = 1; i < 10; i++) {
		link.link_Node(name_list[i], i);
	}

	link.print();
	return 0;
}