#include <stdio.h>
#include <iostream>

int PrintBuf(char* buf);

int main()
{
    char* buf  = (char*) calloc (2, sizeof(char));
    FILE* file = fopen("0.com", "r+");

    fseek(file, 0x8F, SEEK_SET);
    buf[0] = 0xEB; //90
    buf[1] = 0x14; //91
    fwrite(buf, sizeof(char), 2, file);
    fclose(file);
}

int PrintBuf(char* buf)
{
    int i = 0;
    while(buf[i] != EOF && i < 100)
    {
        printf("%c", buf[i]);
        i++;
    }
    printf("\n");
    return 0;
}
