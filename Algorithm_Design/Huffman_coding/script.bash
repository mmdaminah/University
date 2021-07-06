#!/bin/bash
gcc huffman.c
./a.out testCase1Input.txt
if diff -q output.txt testCase1Output.txt
then
    echo "test case 1 passed :)"
else
    echo "test case 1 failed :("
fi

./a.out testCase2Input.txt
if diff -q output.txt testCase2Output.txt
then
    echo "test case 2 passed :)"
else
    echo "test case 2 failed :("
fi