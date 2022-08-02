bool type_check (std::string& str1, std::string& str2) {
    //fill complex types in vector
    if ((str1 == "struct") || (str1 == "class") || (str1 == "union")) {
        bool already_in = true;
        for (int i = 0; i < complex_types.size(); ++i) {
            if (str2 == complex_types[i]) {
                already_in = false;
            }
        }
        if (already_in) {
            complex_types.push_back(str2);
        }
    }
    
    for (int i = 0; i < type.size(); ++i) {
        if (str1 == type[i]) {
            return true;
        }
        else if ( (str1.find(type[i]) == 0) && (str1[str1.size()-1] == '*')) {
            bool already_in = true;
            for (int i = 0; i < type.size(); ++i) {
                if (str1 == type[i]) {
                    already_in = false;
                }
            }
            if (already_in) {
                type.push_back(str1);
            }
            return true;
        }//in case of pointers
        else if ( (str1.find(type[i]) == 0) && (str1[str1.size()-1] == '&')) {
            bool already_in = true;
            for (int i = 0; i < type.size(); ++i) {
                if (str1 == type[i]) {
                    already_in = false;
                }
            }
            return true;
        }//in case of references
    }
    
    for (int i = 0; i < complex_types.size(); ++i) {
        if (str1 == complex_types[i]) {
            return true;
        }
        else if ( (str1.find(complex_types[i]) == 0) && (str1[str1.size()-1] == '*')) {
            bool already_in = true;
            for (int i = 0; i < complex_types.size(); ++i) {
                if (str1 == complex_types[i]) {
                    already_in = false;
                }
            }
            if (already_in) {
                complex_types.push_back(str1);
            }
            return true;
        }//in case of pointers
        else if ( (str1.find(complex_types[i]) == 0) && (str1[str1.size()-1] == '&')) {
            bool already_in = true;
            for (int i = 0; i < complex_types.size(); ++i) {
                if (str1 == complex_types[i]) {
                    already_in = false;
                }
            }
            if (already_in) {
                complex_types.push_back(str1);
            }
            return true;
        }//in case of references
    }
    return false;
}
