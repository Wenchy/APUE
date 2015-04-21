/*
 * FILE *tmpfile(void); //以wb+形式创建一个临时二进制文件
 */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *tmpfp;
    tmpfp = tmpfile();
    if(tmpfile)
        printf("Temporary file created\n");
    else
    {
        fprintf(stderr, "Unable to create temporary file\n");
        exit(1);
    }
    return 0;
}
