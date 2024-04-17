cmake -S . -B build/ \
-DENABLE_ASAN=0 \
-DBUILD_BENCHMARKS=1 \
-DENABLE_GCOV=0 \
&& cmake --build build/