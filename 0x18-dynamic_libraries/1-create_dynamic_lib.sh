#!/bin/bash
gcc -fPIC -c *.c
gcc -shared -o Liball.so *.c
