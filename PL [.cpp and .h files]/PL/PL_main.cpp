
#include "tree.h"
#include "PL_func.h"


int main()
{
	bool MY_DEBUG_REGIME = get_config();

	printf("Hello in my PL!\n");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* text = fopen("text.txt", "r");
	assert(text && "Can't open text.txt file");
	
	Objects* objs = fill_structures(text);
	fclose(text);


	tree PL_tree("PL_TREE");

	PL_tree.fill_tree(objs, MY_DEBUG_REGIME);

	PL_tree.create_asm_text_file(MY_DEBUG_REGIME);

	printf("DONE!\n");
	
	if (MY_DEBUG_REGIME)
	{
		print_objects(objs);
		system("Pause");
	}

	return 0;
}