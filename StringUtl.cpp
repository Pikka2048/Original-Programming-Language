#include "StringUtl.h"
#include "DebugUtl.h"

std::vector<std::string> split(const std::string &str, std::vector<std::string> delims)
{
    std::vector<std::string> results;
    std::vector<int> hits;
    // Find and make hit index list
    for (std::string delim : delims)
    {
        int count_char = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == delim[0])
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
            result = str.substr(0, hits[i]);
        }
        else
        {
            //+1 Delete Delim: ,Hello! → Hello!
            int debugA = hits[i - 1] + 1;
            //-1 Delete Delim  Hello! → Hello
            int debugB = hits[i] - hits[i - 1] - 1;
            result = str.substr(debugA, debugB);
        }
        results.push_back(result);
    }
    return results;
}
