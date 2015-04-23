# VARIABLE = value
# 在执行时扩展，允许递归扩展。
#
# VARIABLE := value
# # 在定义时扩展。
#
# VARIABLE ?= value
# # 只有在该变量为空时才设置值。
#
# VARIABLE += value
# # 将值追加到变量的尾端。

CC = gcc
CFLAGS = -Wall -g
LDFLAGS = 
TARGET =
SRCS = $(wildcard *.c) 
OBJS = $(patsubst %.c, %.out, $(SRCS)) 

.PHONY: all clean

all: $(OBJS)

%.out: %.c
	$(CC) $< $(CFLAGS) -o $@ 

clean:
	rm -rf $(TARGET) 
	rm -rf $(OBJS) 
	rm -rf *.o
