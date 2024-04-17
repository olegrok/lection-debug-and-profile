#!/usr/bin/env bash

cmake -S . -B build/ -DENABLE_ASAN=0 -DENABLE_GCOV=1 && cmake --build build/
./build/tests
lcov -t "build/tests" -o build/tests_cov.info -c -d build/
genhtml -o report build/tests_cov.info
