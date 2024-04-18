#!/usr/bin/env bash

./build.sh -DENABLE_GCOV=1 -DCMAKE_BUILD_TYPE=Debug
./build/tests
lcov -t "build/tests" -o build/tests_cov.info -c -d build/
genhtml -o report build/tests_cov.info
