#include "type_check.hpp"
bool snake_case(std::string& str1, std::string& str2) {
    if (type_check(str1, str2)) {
        std::string str3 = "";
        for (int i = 0; i < str2.size(); ++i) {
        //  std::cout << "str2 = " <<  str2 << std::endl;
            if ((str2[i] != '(') && (str2[i] != ' ') && (str2[i] != '\n') && (str2[i] != 123) && (str2[i] != ')') && (str2[i] != 125)) {
                str3 += str2[i];
            }
            else{
                break;
            }
        }
        int count_of_capitals = 0;
        for (int i = 0; i < str3.size(); ++i) {
            if ((str3[i] >= 'A') && (str3[i] <= 'Z')) {
                count_of_capitals++;
            }
        }
        if (count_of_capitals > 0) {
            if (str3[str3.size() - 1] == ';')  {
                str3[str3.size() - 1] = '\0';
            }
            str2 = "";
            str2 = str3;
            return false;
        }
    }
    return true;
}

