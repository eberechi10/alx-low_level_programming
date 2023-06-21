#!/bin/bash
wget -P ../ https://github.com/eberechi10/alx-low_level_programming/raw/master/0x18-dynamic_libraries/libjackpot.so
export LD_PRELOAD=../libjackpot.so
