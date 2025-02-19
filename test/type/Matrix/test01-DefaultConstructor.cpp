#include "../../../src/type/type.hpp"
#include <iostream>

int main(void)
{
    Type::Matrix  M1;
    Type::Matrix  M2 = Type::Matrix();
    Type::Matrix *M3 = new Type::Matrix();

    std::cout << M1.to_string() << std::endl;
    std::cout << M2.to_string() << std::endl;
    std::cout << M3->to_string() << std::endl;

    return 0;
}
