AT&T vs Intel
===============================================================

## Basic Difference
| AT&T                 | Intel              |
| :--------------------| :------------------|
| pushl %eax  | push eax |
| pushl $1     | push 1 |
| addl $1, %eax  | add eax, 1  |
| movb val, %al  | mov al, byte ptr val  | 
| lret $stack_adjust | ret far stack_adjust |
| ljump $section, $offset | jmp far section:offset|
| lcall $section, $offset | call far section:offset |

## Addressing

在 AT&T 汇编格式中，内存操作数的寻址方式是:

```
section:disp(base, index, scale)
```

而在 Intel 汇编格式中，内存操作数的寻址方式为:

```
section:[base + index*scale + disp]
```

由于 Linux 工作在保护模式下，用的是 32 位线性地址，所以在计算地址时不用考虑段基址和偏移量，而是采用如下的地址计算方法:

```
disp + base + index * scale
```

下面是一些内存操作数的例子:

| AT&T                 | Intel              |
| :--------------------| :------------------|
| movl -4(%ebp), %eax |  mov eax, [ebp - 4]  |
| movl array(, %eax, 4), %eax | mov eax, [eax\*4 + array] |
| movw array(%ebx, %eax, 4), %cx | mov cx, [ebx + 4\*eax + array] |
| movb $4, %fs:(%eax) | mov fs:eax, 4|

## Assemble Tool

### Assembler for AT&T

```shell
$ as -o hello.o hello.s
```

### Assembler for Intel

```shell
$ nasm -f elf hello.asm
```

### Linker

由汇编器产生的目标代码是不能直接在计算机上运行的，它必须经过链接器(linker)的处理才能生成可执行代码。

```shell
$ ld -s -o hello hello.o
```
