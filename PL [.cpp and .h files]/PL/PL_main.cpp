#include "tree.h"
#include "PL_func.h"

const bool DEBUG_STATE = false;

int main()
{
	printf("Hello in my PL!\n");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* text = fopen("text.txt", "r");
	assert(text && "Can't open text.txt file");
	
	Objects* objs = fill_structures(text);
	fclose(text);


	tree PL_tree("PL_TREE");

	if(DEBUG_STATE)
		print_objects(objs);

	PL_tree.fill_tree(objs, DEBUG_STATE);

	PL_tree.create_asm_text_file(DEBUG_STATE);

	printf("DONE!\n");

	return 0;
}