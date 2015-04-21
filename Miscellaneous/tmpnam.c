/********************************* 
char *tmpnam(char *sptr);
sptr可以是NULL或者一个栈地址。当sptr为NULL时，返回一个内部静态内存地址(保存了临时文件名),当下一次以NULL调用函数的时候,该内存会被修改。栈地址必须至少有L_tmpnam内存,这样名字保存在那个数组里面,如数组 char buffer [L_tmpnam],注意用此文件名去打开文件流所创建的文件都是临时性的。tmpnam可以被一个程序最多调用TMP_MAX(最少为几千次)，每一次它都会返回一个不同的文件名。
************************************/
#include <stdio.h>

int main(void)
{
    char name[L_tmpnam];
    tmpnam(name);
    printf("Temporary name: %s\nL_tmpnam: %d\n", name, L_tmpnam);
    return 0;
}
