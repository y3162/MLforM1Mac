#include "../../../src/type/type.hpp"
#include <iostream>

int main(void)
{
    Type::Shape  S1 = Type::Shape(6, 3, 1, 4, 1, 5, 9);
    Type::Shape  S2 = Type::Shape(S1);
    Type::Shape  S3 = S2;
    Type::Shape *S4 = new Type::Shape(S3);

    S1 = Type::Shape(3, 3, 1, 4);
    S2 = Type::Shape(4, 3, 1, 4, 1);
    S3 = Type::Shape(5, 3, 1, 4, 1, 5);

    std::cout << S1.to_string() << std::endl;
    std::cout << S2.to_string() << std::endl;
    std::cout << S3.to_string() << std::endl;
    std::cout << S4->to_string() << std::endl;

    return 0;
}
