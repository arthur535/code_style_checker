# Code Style Checker

<hr>


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


<hr>
