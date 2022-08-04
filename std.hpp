bool using_std (std::string str) {
    std::string str1 = "";
    std::string str2 = "";
    std::string str3 = "";
    int i = 0;
    while(true){
        while ((str[i] != ' ') && (str[i] != '\n') && (str[i] != '(') && (str[i] != ')') && (str[i] != 123) && (str[i] != 125) && (str[i] != '\t')) {
            str1 += str[i];
            i++;
        }
        int j = i + 1;
        while ((str[j] != ' ') && (str[j] != '\n') && (str[j] != '(') && (str[j] != ')') && (str[j] != 123) && (str[j] != 125) && (str[j] != '\t')) {
            str2 += str[j];
            j++;
        }
        int k = j + 1;
        while ((str[k] != ' ') && (str[k] != '\n') && (str[k] != '(') && (str[k] != ')') && (str[k] != 123) && (str[k] != 125) && (str[k] != '\t')) {
            str3 += str[k];
            k++;
        }
        if ((str1 == "using") && (str2 == "namespace") && (str3 == "std;")) {
            return true;
        }
        ++i;
        str1 = "";
        str2 = "";
        str3 = "";
        if (k == str.size()-1) {
            return false;
        }
    }
    //std::cout << "str1 = " << str1 << "\t\n" << "str2 = " << str2 << "\t\n" << "str3 = " << str3 << std::endl;
    return false;
}
