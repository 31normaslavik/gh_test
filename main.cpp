#include "myheader.h"
#include <iostream>
#include <vector>
#include <version>

#ifdef __cpp_lib_format 
  #ifdef  __cpp_lib_format_ranges //>= 201907L
    #include <format>
  #endif  
#endif // __cpp_lib_format

int main(int, char**){

#if __cpp_lib_format >= 201907L
    // #if __cpp_lib_format_ranges >= 202207L
        std::cout << std::format("header <format> include and work!\n");
    // #endif // __cpp_lib_format_ranges >= 202207L
#else
    std::cout << "Hello, CMake! Without Format library\n";
#endif // __cpp_lib_format

    std::string str1 = "Hello, CMake!";
    
    if(str1.contains("CMake!"))
        std::cout << "contains work in string: " << str1 << "!\n";

    // std::cout << "Hello, from testCmake!\n";
    std::vector<std::string> v;
    /** from myheader.h */
    foo();
    foo();
    int i = double(3.14);

    #ifndef NDEBUG
      std::cout << "ifndef NDEBUG  DEBUG NOW!\n";
    #else
      std::cout << "ifdef NDEBUG RELEASE NOW\n";
    #endif // NDEBUG
    
    
}
