#include "../../../src/type/type.hpp"
#include <iostream>

int main(void)
{
    Type::Shape  S1;
    Type::Shape  S2 = Type::Shape();
    Type::Shape *S3 = new Type::Shape();

    std::cout << S1.to_string() << std::endl;
    std::cout << S2.to_string() << std::endl;
    std::cout << S3->to_string() << std::endl;

    return 0;
}
