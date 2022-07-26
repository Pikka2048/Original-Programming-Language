#include "StringUtl.h"
#include "DebugUtl.h"

std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim))
    {
        if (!item.empty())
        {
            elems.push_back(item);
        }
    }
    return elems;
}
// 区切り文字リストを指定し、文字列を区切り、Vectorで返す関数
// 区切りリストを使って検索する
// ヒットしたIndexで２つに分割する
// std::string "Hello,World"
// std::vector ["Hello","World"]
// Indexの[0]は結果となり、スタックする。
// [1]は次回検索の入力となる
// 最後まで行ったら次の区切り文字で区切る

std::vector<std::string> split2(const std::string &s, std::vector<std::string> delims)
{
    std::vector<std::string> elems;

    for (int i = 0; i < delims.size(); i++)
    {
        std::stringstream ss(s);
        std::string item;
        // HACK なんで動いてるのかわからん
        char delim = delims[i][0];
        while (getline(ss, item, delim))
        {
            if (!item.empty())
            {
                elems.push_back(item);
            }
        }
    }

    return elems;
}
// Fire,In!The,Hole
//[Hit]がdelimsのいずれかなら、HITで区切る
//[0:Hit]をスタックする
std::vector<std::string> split3(const std::string &str, std::vector<std::string> delims)
{
    std::vector<std::string> results;
    std::vector<int> hits;
    std::string current = str;
    for (std::string delim : delims)
    {
        int count_char = 0;
        for (int i = 0; i < current.size(); i++)
        {
            if (current[i] == delim[0])
            {
                hits.push_back(count_char);
            }
            count_char++;
        }
    }
    std::sort(hits.begin(), hits.end());
    for (int i = 0; i <= hits.size(); i++)
    {
        std::string result;
        if (i == 0)
        {
            result = current.substr(0, hits[i]);
        }
        else
        {
            //+1 Delete Delim: ,Hello! → Hello!
            int debugA = hits[i - 1] + 1;
            //-1 Delete Delim  Hello! → Hello
            int debugB = hits[i] - hits[i - 1] - 1;
            result = current.substr(debugA, debugB);
        }

        results.push_back(result);
    }
    return results;
}
