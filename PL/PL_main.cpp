#include "tree.h"
#include "PL_func.h"

int main()
{
	printf("Hello in PL!\n");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* text = fopen("text.txt", "r");
	assert(text && "Can't open text.txt file");


	Objects* objs = fill_structures(text);
	tree PL_tree("PL_TREE");

	//print_objects(objs);

	PL_tree.fill_tree(objs, true);
	//PL_tree.show_tree();

	char* asm_text_buf = PL_tree.make_assem_text();
	
	FILE* asm_text_file = fopen("user_code[for_user].asm", "wb");
	assert(asm_text_file);

	fwrite(asm_text_buf, sizeof(char), strlen(asm_text_buf), asm_text_file);
	
	printf("[%s]\n", asm_text_buf);
	//dif_tree.make_article();

	printf("DONE!\n");
	return 0;
}