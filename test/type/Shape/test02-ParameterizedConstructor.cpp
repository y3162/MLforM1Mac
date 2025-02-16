#include "../../../src/type/type.hpp"
#include <iostream>

int main(void)
{
    Type::Shape  S1 = Type::Shape(3, 3, 1, 4);
    Type::Shape *S2 = new Type::Shape(4, 3, 1, 4, 1);
    
    std::cout << S1.to_string() << std::endl;
    std::cout << S2->to_string() << std::endl;

    return 0;
}
