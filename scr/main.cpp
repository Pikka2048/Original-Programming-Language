#include "paser.h"
#include "node.h"
#include "./utility/DebugUtl.h"
#include "./utility/StringUtl.h"
#include <chrono>

void Example()
{
    node_t *root = MakeRootNode();
    std::string root_str = root->data;
    std::cout << "Root is " << root_str << std::endl;

    node_t *child;
    child = AddNode(root, "Apple");
    std::string child_str = child->data;
    std::cout << "Child is " << child_str << std::endl;

    node_t *grandchild;
    grandchild = AddNode(child, "Grepe");
    std::string grandchild_str = grandchild->data;
    std::cout << "Child is " << grandchild_str << std::endl;

    DebugString("---------------------------");
    DisplayNodeConsole(root);
    DebugString("---------------------------");
    auto readfile = LoadTextFile(".././program.hoge");
    Parse(readfile);
    DebugString("---------------------------");
    std::vector<std::string> delims = {"(", ")", R"(")"};
    ;
    std::vector<std::string> result = split(R"(print("Hello My Lang"))", delims);
    for (std::string x : result)
    {
        std::cout << x << "\n";
    }
}
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
    std::string test_str1 = "Although it!s true?you have@little control#over most$of#what@happens!in the world, you$have tremendous!influence over#your?experience?of the events!and circumstances@of your#life.";
    BenchmarkSplit(100000, test_str1);
    //Example();
}
