#include <iostream>
#include <cmath>
#include <benchmark/benchmark.h>
#include "../stack.h"

class StackBenchmark : public benchmark::Fixture {
protected:
  Stack stack;

  void SetUp(const ::benchmark::State& st) override {
    initStack(&stack);
  }

  void TearDown(const ::benchmark::State&) override {
    destroyStack(&stack);
  }
};

BENCHMARK_DEFINE_F(StackBenchmark, PushBenchmark)(benchmark::State& state)
{
    for (auto _ : state)
    {
        size_t n = state.range(1);
        for (size_t i = 0; i < n; i++) {
            push(&stack, 10);
        }
    }
}
BENCHMARK_REGISTER_F(StackBenchmark, PushBenchmark)->ArgPair(0, 1000)->ArgPair(0, 100000)->ArgPair(0, 10000000)->Unit(benchmark::kMillisecond);


BENCHMARK_DEFINE_F(StackBenchmark, PopBenchmark)(benchmark::State& state)
{
    for (auto _ : state)
    {
        size_t n = state.range(0);
        state.PauseTiming();
        for (size_t i = 0; i < n; i++) {
            push(&stack, 1);
        }
        state.ResumeTiming();
        for (size_t i = 0; i < n; i++) {
            pop(&stack);
        }
    }
}
BENCHMARK_REGISTER_F(StackBenchmark, PopBenchmark)->ArgPair(1000, 0)->ArgPair(100000, 0)->ArgPair(10000000, 0)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
