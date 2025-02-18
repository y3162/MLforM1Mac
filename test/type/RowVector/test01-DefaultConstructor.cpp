#include "../../../src/type/type.hpp"
#include <iostream>

int main(void)
{
    Type::RowVector  R1;
    Type::RowVector  R2 = Type::RowVector();
    Type::RowVector *R3 = new Type::RowVector();

    std::cout << R1.to_string() << std::endl;
    std::cout << R2.to_string() << std::endl;
    std::cout << R3->to_string() << std::endl;

    return 0;
}
