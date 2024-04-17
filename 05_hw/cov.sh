#!/usr/bin/env bash

./build.sh
./build/tests
lcov -t "build/tests" -o build/tests_cov.info -c -d build/
genhtml -o report build/tests_cov.info
