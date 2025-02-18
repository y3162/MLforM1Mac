#!/bin/bash

g++ -O0 -D DEBUG_ROWVECTOR -c ../../../src/MLforM1Mac.cpp -o MLforM1Mac.o -std=c++14

for file in *.cpp
do
    name=${file%.cpp}
    g++ -g -c ${name}.cpp -o test.o -std=c++14
    g++ -g MLforM1Mac.o test.o -o test

    ./test 1> output.txt 2>&1
    diff ${name}.ans output.txt

    if [ $? -eq 0 ]; then
        echo ✅RowVector:${name}
    else
        echo ❌RowVector:${name}
    fi

    rm test.o test output.txt
    done

rm MLforM1Mac.o
