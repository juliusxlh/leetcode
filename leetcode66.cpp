#include <regex>
class Solution {
public:
    bool isNumber(string s) {
        std::regex pattern("\\s*[\\+,-]{0,1}(([0-9]+[\\.]{0,1}[0-9]*)|([0-9]*[\\.]{0,1}[0-9]+))([e,E][\\+,-]{0,1}[0-9]+){0,1}\\s*");
        return regex_match(s,pattern);
    }
};
