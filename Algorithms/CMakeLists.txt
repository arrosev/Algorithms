cmake_minimum_required(VERSION 3.19)
project(Algorithms C)

set(CMAKE_C_STANDARD 11)

add_executable(Algorithms main.c leetcode.c leetcode.h list.c list.h error.c error.h stack.c stack.h queue.c queue.h searchtree.c searchtree.h avltree.c avltree.h utility.c utility.h sephash.c sephash.h)