std::vector<std::string> type {"int", "double", "float", "char", "bool", "std::string", "std::vector", "std::map", "long", "short", "auto", "unsigned", "signed", "void"};//վեկտոր,որի մեջ պահվում են տիպ հանդիսացող բառեր
std::vector<std::string> std_vec { "cout", "cin", "endl", "vector", "string", "map", "unordered_map", "cerr", "exit(", "bitset<", "ctime(", "cend", "copy(", "count(", "sort(", "swap("};//std namespace-ի անդամ հանդիսացող բառեր
std::vector<std::string> identifiers;//պահվեն փոփոխականները
std::vector<std::string> complex_identifiers;
std::vector<std::string> complex_types{};
std::vector<std::string> storage_classes_and_cv {"static", "thread_local", "extern", "mutable", "const", "volatile"};//register-ը չի օգտագործվում    auto-ն արդեն կա type-ի մեջ
