#include "../../../src/type/type.hpp"
#include <iostream>

int main(void)
{
    Type::Matrix  M1 = Type::Matrix(3, 2);
    Type::Matrix *M2 = new Type::Matrix(3, 2);
    Type::Matrix  M3 = Type::Matrix(Type::Shape(2, 3, 2));
    Type::Matrix *M4 = new Type::Matrix(Type::Shape(2, 3, 2));
    
    std::cout << M1.to_string() << std::endl;
    std::cout << M2->to_string() << std::endl;
    std::cout << M3.to_string() << std::endl;
    std::cout << M4->to_string() << std::endl;

    return 0;
}
