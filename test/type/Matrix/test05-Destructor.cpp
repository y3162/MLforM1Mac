#include "../../../src/type/type.hpp"
#include <iostream>

int main(void)
{
    Type::Matrix  M1 = Type::Matrix(3, 3);
    Type::Matrix *M2 = new Type::Matrix(3, 3);
    Type::Matrix *M3 = new Type::Matrix(3, 3);

    if (true) {
        Type::Matrix M4 = Type::Matrix(3, 3);
        Type::Matrix *M5 = new Type::Matrix(3, 3);
        Type::Matrix *M6 = new Type::Matrix(3, 3);

        delete M6;
    }

    delete M3;

    std::cout << M1.to_string() << std::endl;
    std::cout << M2->to_string() << std::endl;
    //std::cout << M3->to_string() << std::endl;

    return 0;
}
