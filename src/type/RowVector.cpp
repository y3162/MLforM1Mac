#ifdef DEBUG_ROWVECTOR
#define LOG_ROWVECTOR(msg) std::cerr << "[DEBUG] " << msg << std::endl
#else
#define LOG_ROWVECTOR(msg)
#endif

#include "type.hpp"
using namespace Type;

/*
Shape shape;
size_t *elems;
*/

RowVector::RowVector()
: shape(Shape(1, 0)), elems(nullptr)
{
    LOG_ROWVECTOR("RowVector()");
}

RowVector::RowVector(size_t length)
: shape(Shape(1, length))
{
    LOG_ROWVECTOR("RowVector(size_t)");

    calloc_elems();
}

RowVector::RowVector(const Shape &shape)
: shape(shape)
{
    LOG_ROWVECTOR("RowVector(const Shape&)");

    if (shape.get_dim() != 1) {
        fprintf(stderr, "RowVector : Specified size must be 1-dimension, but got %lu-dimension.\n", shape.get_dim());
        exit(1);
    }

    calloc_elems();
}

RowVector::RowVector(const RowVector &rowvec)
: shape(rowvec.shape)
{
    LOG_ROWVECTOR("RowVector(const RowVector&)");
    
    calloc_elems();

    size_t L = shape[0];
    for (int i=0; i<L; ++i) {
        elems[i] = rowvec.elems[i];
    }
}

RowVector::RowVector(RowVector &&rowvec) noexcept
: shape(std::move(rowvec.shape)), elems(std::exchange(rowvec.elems, nullptr))
{
    LOG_ROWVECTOR("RowVector(RowVector&&)");

    rowvec.shape = Shape(1, 0);
}

RowVector::~RowVector()
{   
    LOG_ROWVECTOR("~RowVector()");

    //shape.~Shape()

    if (elems) {
        free(elems);
    }
    elems = nullptr;
}

void RowVector::calloc_elems()
{
    elems = (data_t*)calloc(shape[0], sizeof(data_t));
    if (!elems) {
        perror("RowVector");
        exit(1);
    }
}

Shape RowVector::get_shape() const
{
    return shape;
}

void RowVector::reshape(const Shape &shape)
{
    reshape(shape[0]);
}

void RowVector::reshape(size_t L)
{
    elems = (data_t*)realloc(elems, L * sizeof(data_t));
    if (!elems) {
        perror("RowVector");
        exit(1);
    }
    for (int i=shape[0]; i<L; ++i) {
        elems[i] = 0;
    }

    shape = Shape(1, L);
}

std::string RowVector::to_string() const
{
    std::string str = "[";
    size_t L = shape[0];
    for (int i=0; i<L; ++i) {
        str += std::to_string(elems[i]);
        if (i < L-1) {
            str += ", ";
        }
    }
    str += ']';

    return str;
}
