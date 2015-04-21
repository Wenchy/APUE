/*
 * void va_start( va_list arg_ptr, prev_param ); 
 * type va_arg( va_list arg_ptr, type ); 
 * void va_end( va_list arg_ptr );
 *
 * VC++ stdarg.h头文件,有如下几个宏定义:
 * #define _INTSIZEOF(n)   ((sizeof(n)+sizeof(int)-1)&~(sizeof(int) - 1) ) 
 * //第一个可选参数地址
 * #define va_start(ap,v) ( ap = (va_list)&v + _INTSIZEOF(v) )           
 * // 下一个参数地址
 * #define va_arg(ap,t) ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) ) 
 * // 将指针置为无效
 * #define va_end(ap)    ( ap = (va_list)0 )                            
 *
 * a.可以在第一个起始参数中指定参数个数,那么就可以在循环还中读取所有的可变参数
 * b.定义一个结束标记,在调用函数的时候,在最后一个参数中传递这个标记,这样在遍历可变参数的时候,可以根据这个标记结束可变参数的遍历
 */
#include <stdarg.h>
#include <stdio.h>

void arg_cnt( int cnt, ... )
{
    int value = 0;
    int i = 0;
    va_list arg_ptr;
    va_start(arg_ptr, cnt);
    for ( i = 0; i < cnt; i++ )
    {
        value = va_arg(arg_ptr, int);
        printf("value%d: %d\n", i+1, value);
    }
    va_end(arg_ptr);
}

// Need to be understood.
void arg_test(int i, ... )
{
    int j = 0;
    va_list arg_ptr;
    va_start(arg_ptr, i);
    printf("&i = %p sizeof(int) = %lu\n", &i, sizeof(int));
    printf("arg_ptr = %p\n", arg_ptr);
    j = *((int *)arg_ptr);
    printf( "%d %d\n", i, j );
    j = va_arg(arg_ptr, int);
    printf("arg_ptr = %p\n", arg_ptr);
    va_end(arg_ptr);
    printf("%d %d\n", i, j);
}

int main( int argc, char *argv[] )
{
    printf("------ arg_cnt -----\n");
    arg_cnt( 8, 1, 2, 3, 4, 11, 15, 18, 20 ); 
    printf("------ arg_test -----\n");
    arg_test(1,2);
    return 0;
}
