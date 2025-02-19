#include "../../../src/type/type.hpp"
#include <iostream>

int main(void)
{
    Type::Matrix  M1 = Type::Matrix(4, 4);
    Type::Matrix  M2 = Type::Matrix(M1);
    Type::Matrix  M3 = M2;
    Type::Matrix *M4 = new Type::Matrix(M3);

    M1 = Type::Matrix(1, 1);
    M2 = Type::Matrix(2, 2);
    M3 = Type::Matrix(3, 3);

    std::cout << M1.to_string() << std::endl;
    std::cout << M2.to_string() << std::endl;
    std::cout << M3.to_string() << std::endl;
    std::cout << M4->to_string() << std::endl;

    return 0;
}
