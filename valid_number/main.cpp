#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool is_num(char c) { return isdigit(c); }
    bool is_e(char c) { return c == 'e' || c == 'E'; }
    bool is_dot(char c) { return c == '.'; }
    bool is_sign(char c) { return c == '+' || c == '-'; }

    bool isNumber(string s) {
        string s2 = s;
        int dot_count = 0;
        int e_count = 0;
        int sign_count = 0;
        int num_count = 0;
        string rm = "0123456789.+-eE";

        s2.erase(std::remove_if(
                     s2.begin(), s2.end(),
                     [&rm](char c) { return rm.find(c) != std::string::npos; }),
                 s2.end());

        if (s2.size() != 0) {
            return false;
        }

        s.insert(0, " ");
        s.append(" ");

        for (size_t i = 1; i < s.size(); i++) {

            if (is_num(s[i])) {
                ++num_count;
            }

            if (is_dot(s[i])) {
                if (e_count > 0){
                    return false;
                } 
                dot_count++;
            }

            if (is_e(s[i])) {

                if (num_count < 1){
                    return false;
                }

                e_count++;

                if (!is_num(s[i - 1]) && !is_dot (s[i-1])) {
                    return false;
                }
                if ((!is_num(s[i + 1]) && !is_sign(s[i + 1])) ||
                    (is_sign(s[i + 1]) &&
                     !is_num(s[i + 2]))) { 
                    cout << "-3";
                    return false;
                }
            }

            if (is_sign(s[i])) {
                sign_count++;
                if ((sign_count > 1) && (e_count < 1)) {
                    return false;
                }
                if ((i != 1) && (!is_e(s[i - 1]))) {
                    return false;
                }
            }
        }

        if ((dot_count > 1) || (sign_count > 2) || (e_count > 1) ||
            (num_count < 1) || ((e_count > 0) && (num_count < 2))) {
            return false;
        }

        return true;
    }
};
