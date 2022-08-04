#include <iostream>
#include <string>
#include <vector>
#include "vectors.hpp"
bool struct_name_with_capital(std::string&, std::string&);//struct name should start with capital
bool class_name_with_capital(std::string&, std::string&);//class name should start with capital
bool union_name_with_capital(std::string&, std::string&);//union name should start with capital
bool std_check(std::string&);
bool one_letter(std::string&, std::string&);
bool directives(std::string&, std::string&);//if there are few spaces after directives
bool type_after_type(std::string&, std::string&);//if you wrote one type after second
void fill_identifiers(std::string&, std::string&);//fill identifiers in vector
bool check_identifiers_first_symbol();//if everything is ok with identifiers
bool before_type(std::string&, std::string&);
void func_arg(std::string&, std::string&);


//implementation of functions
bool struct_name_with_capital(std::string& str1, std::string& str2) {
    if (str1 == "struct") {
        if (!((str2[0] >= 'A') && (str2[0] <= 'Z'))) {
            return false;
        }
    }
    return true;
}


bool class_name_with_capital(std::string& str1, std::string& str2) {
    if (str1 == "class") {
        if (!((str2[0] >= 'A') && (str2[0] <= 'Z'))) {
            return false;
        }
    }
    return true;
}


bool union_name_with_capital(std::string& str1, std::string& str2) {
    if (str1 == "union") {
        if (!((str2[0] >= 'A') && (str2[0] <= 'Z'))) {
            return false;
        }
    }
    return true;
}


bool std_check(std::string& str1) {
    for (int i = 0; i < std_vec.size(); ++i) {
        if (0 == str1.find(std_vec[i])) {
            return false;
        }
    }
    return true;
}


bool one_letter(std::string& str1, std::string& str2) {
    for (int i = 0; i < type.size(); ++i) {
        if (str1 == type[i]) {
            if (1 == str2.size()) {
                return false;
            }
        }
    }
    return true;
}


bool directives(std::string& str1, std::string& str2) {
    if (str1[0] == '#') {
        if ((str2[0] != '"') && (str2[0] != '<')) {
            return false;
        }
    }
    return true;
}


bool type_after_type(std::string& str1, std::string& str2) {
    for (int i = 0; i < type.size(); ++i) {
        for (int j = 0; j < type.size(); ++j) {
            if ((str1 == type[i]) && (str2 == type[j])) {
                if (((str1 == "unsigned") || (str1 == "signed")) &&
                    ((str2 == "long") || (str2 == "short") || (str2 == "int") || (str2 == "char"))) {
                    return true;
                }
                if (str1 == "auto") {
                    return true;
                }
                return false;
            }
        }
    }
    return true;
}


void fill_identifiers(std::string& str1, std::string& str2){
    for (int i = 0; i < type.size(); ++i) {
        if ( (str1 == type[i]) ||
            ((str1.find(type[i]) == 0) && (str1[str1.size()-1] == '*')) ||
            ((str1.find(type[i]) == 0) && (str1[str1.size()-1] == '&')))
        {
//          std::cout << "str1 = " << str1 << std::endl;
//          std::cout << "str2 = " << str2 << std::endl;
            if ((str2.find("main(") == 0) || str2[0] == '{') {
                return;
            }
            if ((str2[str2.size()-1] == ';') || (str2[str2.size()-1] == ',')) {
                str2[str2.size()-1] = '\0';
            }
            if (str2[0] == '&') {
                str1 += "&";
                for (int i = 0; i < str2.size()-1; ++i) {
                    str2[i] = str2[i+1];
                }
                str2[str2.size()-1] = '\0';
            }
            std::string str3 = "";
            for (int i = 0; i < str2.size(); ++i) {
                if ((str2[i] != '(') && (str2[i] != ' ') && (str2[i] != '\n') && (str2[i] != 123) && (str2[i] != ')') && (str2[i] != 125)) {
                    str3 += str2[i];
                }
                else{break;}
            }
            identifiers.push_back(str3);
//          std::cout << "str2 = " << str2 << std::endl;
        }
    }
    for (int i = 0; i < complex_types.size(); ++i) {
        if ( (str1 == complex_types[i]) ||
            ((str1.find(complex_types[i]) == 0) && (str1[str1.size()-1] == '*')) ||
            ((str1.find(complex_types[i]) == 0) && (str1[str1.size()-1] == '&')))
        {
            if ((str2.find("main(") == 0) || str2[0] == 123) {
                return;
            }
            if (str2[str2.size()-1] == ';') {
                str2[str2.size()-1] = '\0';
            }
            if (str2[0] == '&') {
                for (int i = 0; i < str2.size()-1; ++i) {
                    str2[i] = str2[i+1];
                }
                str2[str2.size()-1] = '\0';
            }
            std::string str3 = "";
            for (int i = 0; i < str2.size(); ++i) {
                if ((str2[i] != '(') && (str2[i] != ' ') && (str2[i] != '\n') && (str2[i] != 123) && (str2[i] != ')') && (str2[i] != 125)) {
                    str3 += str2[i];
                }
                else{break;}
            }
            complex_identifiers.push_back(str3);
        }
    }
}

bool check_identifiers_first_symbol() {
    if (identifiers.size() == 0) {
        return true;
    }
    int i = (int)identifiers.size()-1;
    if (!((identifiers[i][0] >= 'a') && (identifiers[i][0] <= 'z')) && !((identifiers[i][0] >= 'A') && (identifiers[i][0] <= 'Z')) && (identifiers[i][0] != '_') && (identifiers[i][0] != '&') && (identifiers[i][0] != '$')) {
        return false;
    }
    return true;
}


bool before_type(std::string& str1, std::string& str2){
    for (int i = 0; i < type.size(); ++i) {
        if (str2 == type[i]) {
            for (int j = 0; j < storage_classes_and_cv.size(); ++j) {
                if (str1 == storage_classes_and_cv[j]) {
                    return true;
                }
            }
        }
    }
    return true;
}
