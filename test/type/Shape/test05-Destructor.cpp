#include "../../../src/type/type.hpp"
#include <iostream>

int main(void)
{
    Type::Shape  S1 = Type::Shape(3, 3, 1, 4);
    Type::Shape *S2 = new Type::Shape(3, 3, 1, 4);
    Type::Shape *S3 = new Type::Shape(3, 3, 1, 4);

    if (true) {
        Type::Shape S4 = Type::Shape(3, 3, 1, 4);
        Type::Shape *S5 = new Type::Shape(3, 3, 1, 4);
        Type::Shape *S6 = new Type::Shape(3, 3, 1, 4);

        delete S6;
    }

    delete S3;

    std::cout << S1.to_string() << std::endl;
    std::cout << S2->to_string() << std::endl;
    //std::cout << S3->to_string() << std::endl;

    return 0;
}
