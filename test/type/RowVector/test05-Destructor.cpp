#include "../../../src/type/type.hpp"
#include <iostream>

int main(void)
{
    Type::RowVector  S1 = Type::RowVector(3);
    Type::RowVector *S2 = new Type::RowVector(3);
    Type::RowVector *S3 = new Type::RowVector(3);

    if (true) {
        Type::RowVector S4 = Type::RowVector(3);
        Type::RowVector *S5 = new Type::RowVector(3);
        Type::RowVector *S6 = new Type::RowVector(3);

        delete S6;
    }

    delete S3;

    std::cout << S1.to_string() << std::endl;
    std::cout << S2->to_string() << std::endl;
    //std::cout << S3->to_string() << std::endl;

    return 0;
}
