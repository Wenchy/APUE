Advanced Programming in the Unix Environment (APUE), 3rd Editon
===============================================================

## Practice

>Do coding yourself now!
>Learn real Unix/Linux system by realizing every sample.

## Makefile

Make是最常用的构建工具，诞生于1977年，主要用于C语言的项目。实际上 ，只要某个文件有变化，就需要重新构建的项目，都可以用Make构建。

### Basic Rule

Makefile文件的格式

```Makefile
target : prerequisites
    recipe
    …
```

### Comments (注释) 

井号`#`在Makefile中表示注释。

### Echoing (回声) 

正常情况下，make会打印每条命令，然后再执行，这就叫做回声（echoing）。
在命令的前面加上`@`，就可以关闭回声。

```Makefile
test :
    @# 这是测试
    @echo TODO
```

### Wildcard (通配符)

Makefile的通配符与Bash一致，主要有星号`*`, 问号`？`和 `[]`。比如， `*.o` 表示所有后缀名为o的文件。

```Makefile
clean :
    rm -f *.o
```

### Pattern Rules (模式匹配)

> For example, `%.c` as a pattern matches any file name that ends in `.c`. `s.%.c` as a pattern matches any file name that starts with `s.`, ends in `.c` and is at least five characters long. (There must be at least one character to match the `%`.) The substring that the `%` matches is called the **stem**.
Make命令允许对文件名，进行类似正则运算的匹配，主要用到的匹配符是%。比如，假定当前目录下有 f1.c 和 f2.c 两个源码文件，需要将它们编译为对应的对象文件。

```Makefile
%.o : %.c
```

等同于

```Makefile
f1.o : f1.c
f2.o : f2.c
```

### Variable and Assignments (变量和赋值)

1. VARIABLE = value # 在执行时扩展，允许递归扩展。

2. VARIABLE := value # 在定义时扩展。

3. VARIABLE ?= value # 只有在该变量为空时才设置值。

4. VARIABLE += value # 将值追加到变量的尾端。

### Implicit Variables (内置变量)

1. **AR**
Archive-maintaining program; default ‘ar’.

2. **AS**
Program for compiling assembly files; default ‘as’.

3. **CC**
Program for compiling C programs; default ‘cc’.

4. **CFLAGS**
Extra flags to give to the C compiler.

5. **LDFLAGS**
Extra flags to give to compilers when they are supposed to invoke the linker, `ld`, such as `-L`. Libraries (-lfoo) should be added to the LDLIBS variable instead.

6. **LDLIBS**
Library flags or names given to compilers when they are supposed to invoke the linker, `ld`. LOADLIBES is a deprecated (but still supported) alternative to LDLIBS. Non-library linker flags, such as -L, should go in the LDFLAGS variable.

### Automatic Variables (自动变量)

1. `$@` The file name of the target of the rule.

2. `$<` The name of the first prerequisite.

3. `$^` The names of all the prerequisites, with spaces between them.

4. `$?` The names of all the prerequisites that are newer than the target, with spaces between them.

5. `$(@D)` The directory part of the file name of the target, with the trailing slash removed. Also `$(<D)`.

6. `$(@F)` The file-within-directory part of the file name of the target.If the value of `$@` is dir/foo.o then `$(@F)` is foo.o. `$(@F)` is equivalent to `$(notdir $@)`. Also `$(<F)`

### Judge and Loop (判断和循环)

Makefile使用 Bash 语法，完成判断和循环。

```Makefile
CC = gcc

ifeq ($(CC),gcc)
    libs=$(libs_for_gcc)
else
    libs=$(normal_libs)
endif

LIST = one two three
loop :
    for  item in $(LIST); don \
        echo $$item; \
    done
```

### Function (函数)

Makefile 还可以使用函数，格式如下:

```Makefile
$(function arguments)
# or
${function arguments}
```

Makefile提供了许多内置函数，可供调用。下面是几个常用的内置函数。

1. shell 函数 `srcfiles := $(shell echo src/{00..99}.txt)`

2. wildcard 函数 `srcfiles := $(wildcard src/*.txt)`

3. subst 函数 `$(subst from,to,text)`

4. patsubst函数 `$(patsubst pattern,replacement,text)`

5. 替换后缀名 `$(OUTPUT:.js=.min.js)`

### References and Links

* [Make 命令教程](http://www.ruanyifeng.com/blog/2015/02/make.html) - 阮一峰

* [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html) - Official Manual 

* [跟我一起写Makefile](http://htwm.readthedocs.org/zh_CN/latest/index.html) - 陈皓
