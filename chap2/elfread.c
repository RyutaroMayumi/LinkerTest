// staticオプションを指定してコンパイルしないとSegmentation faultになる
// refer to https://stackoverflow.com/questions/39486061/load-elf-file-into-memory

#include <stdio.h>
#include <elf.h>
#include <stdlib.h>

int main()
{
    Elf64_Ehdr *ehdr;

    ehdr = (Elf64_Ehdr *)0x0000000000400000;

    printf("0x%02x%c%c%c\n", 
        ehdr->e_ident[EI_MAG0], 
        ehdr->e_ident[EI_MAG1], 
        ehdr->e_ident[EI_MAG2], 
        ehdr->e_ident[EI_MAG3]);

    exit(0);
}
