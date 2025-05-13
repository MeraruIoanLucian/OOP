#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cctype>

int main() {
    std::ifstream fin("/Users/ionutmeraru/CLionProjects/OOP/Lab8/input.txt");
    std::string phrase, line;
    while (std::getline(fin, line)) {
        if (!phrase.empty()) phrase += ' ';
        phrase += line;
    }
    fin.close();

    std::map<std::string,int> counts;
    const std::string sep = " ,?!.";
    for (size_t i = 0; i < phrase.size(); ) {
        i = phrase.find_first_not_of(sep, i);
        if (i == std::string::npos) break;
        size_t j = phrase.find_first_of(sep, i);
        std::string w = phrase.substr(i, j - i);
        for (char &c : w) c = static_cast<char>(std::tolower(c));
        counts[w]++;
        if (j == std::string::npos) break;
        i = j + 1;
    }

    auto cmp = [](const std::pair<std::string,int>& a,
                  const std::pair<std::string,int>& b){
        if (a.second != b.second) return a.second < b.second;
        return a.first  > b.first;
    };
    std::priority_queue<
        std::pair<std::string,int>,
        std::vector<std::pair<std::string,int>>,
        decltype(cmp)
    > pq(cmp);

    for (auto &p : counts) pq.push(p);

    while (!pq.empty()) {
        auto &p = pq.top();
        std::cout << p.first << " => " << p.second << "\n";
        pq.pop();
    }

    return 0;
}