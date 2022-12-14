# Code Style Checker

<hr>

Code style helps to ensure the linear development of the project, significantly speeds up the adaptation of new employees and, in general, forms and educates the development culture. It is very important to write the code in right style so as not to irritate the eyes of other developers so that they can understand a lot at a glance at the code.  
_____________________________________________________________________________________
Description of VECTORS.HPP

There are 6 vectors in vectors.hpp file
1) Vector "identifiers
 "Vector "identifiers" involves variable and function names, which were used in users' code.
2) Vector "type"
 C++ language types are stored in "type" vector.
3) Vector "complex_types" 
  If user create complex types, using class, union and struct keywords, that complex types will be stored in "complex_types" vector.
4) Vector "complex_identifiers"
  If variable type in user code is complex, your wariable name will be kept in "complex_identifiers" vector. Also if user have a function in his code, that returns complex type or a complex type pointer/reference, it's name will be kept in this vector.
5) Vector "storage_classes_and_cv"
  Storage classes and CV qaulifiers keywords are stored in this vector.
6) Vector "std_vec"
  In "std_vec" vector are kept some important keywords and functions, which belong to std namespace.
  
Description of STD.HPP

There is only one function in std.hpp - using_std. It return true if user used "using namespace std" in code.
using_std function has 3 strings - 3 words of user code. Аfter each iteration the strings go forward in onwe word. If their combination is "using namespace std;", it returns true.

Description of TYPE_CHECK.HPP

Function type_check takes two std::string arguments, and, if first argument is in "type" or "complex_types" vectors, returns true;
It also adds new types to vector "type" or "complex_types".

Description of SNAKE.HPP

snake_case function exists to check if your variables and function names are written in snake_case. If in variables or function names are capital letters, function will return false.

Description of FUNCTIONS.HPP

1)struct_name_with_capital
2)class_name_with_capital
3)union_name_with_capital
These three functions check if names of classes, structs and unions starts with a capital letter
4)std_check -- if user don't have "using namespace std" in code and there are keywords or functions, which belong to std namespace, function will return false. 
5)one_letter -- if variables or function names have only one letter, then it is false.
6)directives -- if there are few spaces after directives
7)type_after_type -- if you wrote one type after second
8)fill_identifiers -- fill variable and function names in vector "identifiers"
9)check_identifiers_first_symbol -- if everything is ok with identifiers first symbol
10)before_type -- before type can be only storage class and CV qualifiers keywords.

Description of CHECK.HPP

This is "main" function of style checker. All the other functions are included into this one. Function check opens file and begin to read it. When it is problem with style, function returns error and the description of it.
<hr>
