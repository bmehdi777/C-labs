#!/bin/bash
cc -Wall -g -DNDEBUG -c -o ex22.o ex22.c
cc -Wall -g -DNDEBUG stack.c ex22.o -o stack
