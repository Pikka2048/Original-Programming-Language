#include "paser.h"
#include "node.h"
#include "./utility/DebugUtl.h"
#include "./utility/StringUtl.h"
#include <chrono>

void BenchmarkSplit(int num, std::string str)
{
    std::vector<std::string> delims = {"!", "?", "@", "#,", "$"};

    std::chrono::system_clock::time_point start, end;
    start = std::chrono::system_clock::now();
    for (int i = 0; i < num; i++)
    {
        split(str, delims);
    }
    end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Split Benchmark Number of trials\n"
              << num << "\n"
              << "elapsed :" << elapsed << std::endl;
}

int main()
{
    std::string readfile = LoadTextFile("example/program.hoge");
    Parse(readfile);
}
