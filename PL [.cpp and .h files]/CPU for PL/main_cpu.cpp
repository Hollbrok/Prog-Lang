#include "cpu.h"

int main()
{
    printf("CPU in progress..\n");

    FILE* text = fopen("[!]assembler_code.txt", "rb");
	assert(text && "Can't open assembler_code.txt");

    Bytecode byte_class;
    byte_class.fill(text);//(text);
    byte_class.CPU();

    printf("DONE!!\n");
    system("PAUSE");
    return 0;
}
