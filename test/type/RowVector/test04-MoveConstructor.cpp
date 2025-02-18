#include "../../../src/type/type.hpp"
#include <iostream>

int main(void)
{
    Type::RowVector  R1 = Type::RowVector(2);
    Type::RowVector  R2 = std::move(R1);
    Type::RowVector *R3 = new Type::RowVector(4);
    Type::RowVector  R4 = std::move(*R3);
    
    R1 = Type::RowVector(1);
    R3 = new Type::RowVector(3);

    std::cout << R1.to_string() << std::endl;
    std::cout << R2.to_string() << std::endl;
    std::cout << R3->to_string() << std::endl;
    std::cout << R4.to_string() << std::endl;

    return 0;
}
