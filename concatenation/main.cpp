#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    std::vector<std::string> line;
    std::vector<std::string> temp;
    std::vector<int> indexes;

    void hasDuplicates (std::vector<std::string>& line) {
    for (size_t i = 0; i < line.size(); ++i) {
        for (size_t j = i + 1; j < line.size(); ++j) {
            if (line[i] == line[j]) {
                line.erase(line.begin () + i); // Найдены одинаковые элементы
            }
        }
    }
}

    void alg(std::vector<std::string>& words, int size) {
        if (size == 1) {
            for (int i = 0; i < words.size(); i++) {
                temp.push_back(words[i]);
                std::cout << words[i];
            }
            std::cout << "\n";
            return;
        } else {
            for (int i = 0; i < (size - 1); i++) {
                alg(words, size - 1);
                if (size % 2 == 0) {
                    std::swap(words[i], words[size - 1]);
                } else {
                    std::swap(words[0], words[size - 1]);
                }
            }
        }
        alg(words, size - 1);
    }

    void my_find(const std::string& s, const std::string& ss,std::vector<int>& indexes, size_t pos = 0) {
            if (s.length() < ss.length()){
            return;
        }
        for (int i = pos; i <= (s.length() - ss.length()); i++) {
            bool match = true;
            for (size_t j = 0; j < ss.length(); j++) {
                if (s[i + j] != ss[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                indexes.push_back(i);
            }
        }
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        alg(words, words.size());

        std::ostringstream oss;

        for (size_t i = 0; i < temp.size(); ++i) {
            if (i % words.size() == 0 && i != 0) { 
                line.push_back(
                    oss.str()); 
                oss.str("");    
                oss.clear();   
            }
            oss << temp[i]; 
        }

        if (!oss.str().empty()) {
            line.push_back(oss.str());
        }

        hasDuplicates(line);

        for (const auto& str : line) {
            my_find(s, str, *&indexes);
        }

        return indexes;
    }
};