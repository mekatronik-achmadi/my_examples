#!/bin/bash

cc -fPIC -shared -o libcsum.so c_sum.c
python c_sum.py
rm libcsum.so
