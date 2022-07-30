#include <iostream>
#include <fstream>
#include <string>
#include <vector>
std::vector<std::string> type;
std::vector<std::string> std_vec;
void fill_std_vec(){
    std_vec.push_back("cout");
    std_vec.push_back("cin");
    std_vec.push_back("endl");
    std_vec.push_back("vector");
    std_vec.push_back("string");
    std_vec.push_back("map");
    std_vec.push_back("unordered_map");
}
void fill_type_vec(){
    type.push_back("int");
    type.push_back("double");
    type.push_back("float");
    type.push_back("char");
    type.push_back("std::string");
    type.push_back("std::vector");
    type.push_back("bool");
    type.push_back("std::map");
    type.push_back("std::unordered_map");
}
bool struct_name_with_capital(std::string& str1, std::string& str2){
    if (str1 == "struct") {
        if (!((str2[0] >= 'A') && (str2[0] <= 'Z'))) {
            return false;
        }
    }
    return true;
}
bool class_name_with_capital(std::string& str1, std::string& str2){
    if (str1 == "class") {
        if (!((str2[0] >= 'A') && (str2[0] <= 'Z'))) {
            return false;
        }
    }
    return true;
}
bool type_check (std::string& str1, std::string& str2) {
    if ((str1 == "struct") || (str1 == "class")) {
        bool boolean = true;
        for (int i = 0; i < type.size(); ++i) {
            if (str2 == type[i]) {
                boolean = false;
            }
        }
        if (boolean) {
            type.push_back(str2);
        }
    }
    for (int i = 0; i < type.size(); ++i) {
        if (str1 == type[i]) {
            return true;
        }
        else if ( (str1.find(type[i]) == 0) && (str1[str1.size()-1] == '*')){
            return true;
        }
    }
    return false;
}
bool std_check(std::string& str1){
    std::string str2 = "";
    for (int i = 0; i < str1.size(); ++i) {
        if (str1[i] != '<') {
            str2 += str1[i];
        }
        else{
            break;
        }
    }
    for (int i = 0; i < std_vec.size(); ++i) {
        if (str2 == std_vec[i]) {
            return false;
        }
    }
    return true;
}
bool one_letter(std::string& str1, std::string& str2){
    if (type_check(str1, str2)) {
        std::string str3 = "";
        for (int i = 0; i < str2.size(); ++i) {
        //  std::cout << "str2 = " <<  str2 << std::endl;
            if ((str2[i] != '(') && (str2[i] != ' ') && (str2[i] != '\n') && (str2[i] != 123)) {
                str3 += str2[i];
            }
            else{
                break;
            }
        }
        if (str3.size() == 1) {
//             std::cout << str3 << std::endl;
             return false;
        }
    }
    return true;
}
bool snake_case(std::string& str1, std::string& str2){
    if (type_check(str1, str2)) {
        std::string str3 = "";
        for (int i = 0; i < str2.size(); ++i) {
        //  std::cout << "str2 = " <<  str2 << std::endl;
            if ((str2[i] != '(') && (str2[i] != ' ') && (str2[i] != '\n') && (str2[i] != 123)) {
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
        if (count_of_capitals > 1) {
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
std::string check(std::string file_name) {
    std::ifstream fin;
    fin.open(file_name);
    if ( !fin ) {
        std::cout << "File could not be opened" << std::endl;
        std::exit(1);
    }
    char name;
    std::string str = "";
    while ( fin.get(name)){
        str += name;
    }
    std::string str1 = "";
    std::string str2 = "";
    fill_type_vec();
    fill_std_vec();
    for ( int i = 0; i < str.size()-1; ++i) {
        
        if ((str[i] == ' ') || (str[i] == '\n')) {
            
            for (int j = ++i; (str[j] != ' ') && (str[j] != '\n'); ++j) {
                str2 += str[j];
            }
            //std::cout << "str1 = " << str1 << "\t\t" << "str2 = " << str2 << std::endl;
            if(!snake_case(str1, str2)){
                std::cout << "your variable or function name " << str2 << " is not snake_case" << std::endl;
                return "error\n";
            }
            else if (!one_letter(str1, str2)) {
                std::cout << "you cant have a variable or function name with one letter\n";
                return "error\n";
            }
            else if (!class_name_with_capital(str1, str2)) {
                std::cout << "your class name should start with capital letter\n";
                return "error\n";
            }
            else if (!struct_name_with_capital(str1, str2)) {
                std::cout << "your struct name should start with capital letter\n";
                return "error\n";
            }
            else if (!std_check(str1)) {
                std::cout << "you should write std::\n";
                return "error\n";
            }
            str1 = "";
            str2 = "";
        }
        str1 += str[i];
    }
    return "everything is ok\n";
}

int main() {
    std::string file_name;
    std::cin >> file_name;
    std::cout << check(file_name);
return 0;
}
