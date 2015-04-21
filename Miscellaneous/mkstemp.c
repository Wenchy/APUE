/*
 * int mkstemp(char *template);
 * mkstemp函数在系统中以唯一的文件名创建一个文件并打开，而且只有当前用户才能访问这个临时文件，并进行读、写操作。 mkstemp函数只有一个参数，这个参数是个以“XXXXXX”结尾的非空字符串。mkstemp函数会用随机产生的字符串替换“XXXXXX”，保证 了文件名的唯一性。 函数返回一个文件描述符，如果执行失败返回-1。
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd;
    char temp_file[] = "tmp_XXXXXX";
    //create a temp file
    if((fd = mkstemp(temp_file)) == -1)
    {
        fprintf(stderr, "create temp file fail.\n");
        exit(1);
    }
    // unlink the temp file
    unlink(temp_file);
    printf("Temporary name: %s\n", temp_file);
    // then we can read or write the temp file
    /* ADD YOUR CODE*/
    // close temp file, when exit this program, the temp file will be removed.
    close(fd);

}
