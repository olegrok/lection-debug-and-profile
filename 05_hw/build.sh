cmake -S . -B build/ \
-DENABLE_ASAN=0 \
-DBUILD_BENCHMARKS=1 \
-DENABLE_GCOV=0 \
-DCMAKE_BUILD_TYPE=Release \
$@ \
&& cmake --build build/