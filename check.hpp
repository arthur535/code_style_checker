#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.hpp"
#include "snake.hpp"
#include "std.hpp"
bool check(std::string file_name) {
    std::ifstream fin;
    fin.open(file_name);
    if ( !fin ) {
        std::cout << "File could not be opened" << std::endl;
        return false;
    }
    char name;
    std::string str = "";
    while ( fin.get(name)){
        str += name;//fill everything in str from file
    }
    std::string str1 = "";//first word
    std::string str2 = "";//second word
    bool using_namespace_std = using_std(str);
    for ( int i = 0; i < str.size()-1; ++i) {
        
        if ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '(') || (str[i] == ')') || (str[i] == 123) || (str[i] == 125) || (str[i] == '\t')) {
            
            for (int j = ++i; j < str.size() ; ++j) {
                if ((str[j] == ' ') || (str[j] == '\n') || (str[j] == '(') || (str[j] == ')') || (str[j] == 123) || (str[j] == 125) || (str[j] == '\t')) {
                    break;
                }
                str2 += str[j];
                if ((str2[0] == ' ') || (str2[0] == '\n') || (str2[0] == '\t')) {
                    str2 = "";
                    continue;
                }
            }
            fill_identifiers(str1, str2);//
            //std::cout << "str1 = " << str1 << "\t\t" << "str2 = " << str2 << std::endl;
            if(!snake_case(str1, str2)){
                std::cout << "your identifier or function name " << str2 << " is not snake_case\n";
                std::cout << "don't use capital letters in your identifiers and functions names\n";
                std::cout << "error\n";
                return false;
            }//if you have identifier or function with capital letter in it
            else if (!one_letter(str1, str2)) {
                std::cout << "you cant have a variable or function name with one letter\n";
                std::cout << "error\n";
                return false;
            }//if you have identifier or function with one letter
            else if (!class_name_with_capital(str1, str2)) {
                std::cout << "your class name " << str2 << " should start with capital letter\n";
                std::cout << "error\n";
                return false;
            }//if your class name starts with capital letter
            else if (!union_name_with_capital(str1, str2)) {
                std::cout << "your union name " << str2 << " should start with capital letter\n";
                std::cout << "error\n";
                return false;
            }//if your union name starts with capital letter
                else if (!struct_name_with_capital(str1, str2)) {
                std::cout << "your struct name " << str2 << " should start with capital letter\n";
                std::cout << "error\n";
                return false;
            }//if your struct name starts with capital letter
            else if (!using_namespace_std) {
                if (!std_check(str1)) {
                    std::cout << "you should write std::\n";
                    std::cout << "error\n";
                    return false;
                }
            }//if there are words in file that belongs to std and therenis no std ahead
            else if (!directives(str1, str2)) {
                std::cout << "there must be only one space after " << str1 << "\n";
                std::cout << "error\n";
                return false;
            }
            else if (!type_after_type(str1, str2)) {
                std::cout << "you wrote type " << str2 << " after type " << str1 << "\n";
                std::cout << "error\n";
                return false;
            }
            else if (!check_identifiers_first_symbol()) {
                if (((identifiers[identifiers.size()-1][0]) >= '0')
                    && ((identifiers[identifiers.size()-1][0]) <= '9')) {
                    std::cout << "your identifier cant start with number \n";
                    std::cout << "error\n";
                    return false;
                }//if first symbol of identifier is number-return
            std::cout << "your identifier cant start with " << identifiers[identifiers.size()-1][0] << "\n";
            std::cout << "error\n";
            return false;
            }
            str1 = "";
            str2 = "";

        }
        str1 += str[i];
        if ((str1[0] == ' ') || (str1[0] == '\n') || (str1[0] == '\t')) {
            str1 = "";
            continue;
        }
    }
    std::cout << "everything is ok\n";
    return true;
}

