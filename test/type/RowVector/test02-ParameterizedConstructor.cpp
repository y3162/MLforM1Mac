#include "../../../src/type/type.hpp"
#include <iostream>

int main(void)
{
    Type::RowVector  R1 = Type::RowVector(10);
    Type::RowVector *R2 = new Type::RowVector(10);
    Type::RowVector  R3 = Type::RowVector(Type::Shape(1, 5));
    Type::RowVector *R4 = new Type::RowVector(Type::Shape(1, 5));
    
    std::cout << R1.to_string() << std::endl;
    std::cout << R2->to_string() << std::endl;
    std::cout << R3.to_string() << std::endl;
    std::cout << R4->to_string() << std::endl;

    return 0;
}
