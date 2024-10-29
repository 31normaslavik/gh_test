#pragma once

#include <iostream>
#include <string>

inline void foo(){
    std::cout << "foo" << std::endl;
}
inline void foo(int i){
    std::cout << "foo " << std::to_string(i) << std::endl;
}