#helloWorld.s (AT&T Assembly Syntax style)

.data                               #declaration of data segment
    # msg : .ascii "Hello world!\n"
    msg : .string "Hello world!\n" # output string
    len = . - msg                   # bytes length of msg
    
.text                               # declaration of code(text) segment

.globl _start                       # declare start function

_start:                             # show a string on screen
    movl $4, %eax                   # system call (sys_write)
    movl $1, %ebx                   # 1st param: file description (stdout)
    movl $msg, %ecx                 # 2nd param: address of string
    movl $len, %edx                 # 3rd param: length of string
    int  $0x80                      # soft interrupt for system call
                                    # exit program
    movl $1, %eax                   # system call (sys_exit)
    movl $0, %ebx                   # 1st param: exit code (1) 
    int  $0x80                      # soft interrupt for system call
