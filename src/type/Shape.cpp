#ifdef DEBUG_SHAPE
#define LOG_SHAPE(msg) std::cerr << "[DEBUG] " << msg << std::endl
#else
#define LOG_SHAPE(msg)
#endif

#include "type.hpp"

using namespace Type;

/*
size_t dim
size_t *elems
*/

Shape::Shape()
: dim(0), elems(nullptr)
{
    LOG_SHAPE("Shape()");
}

Shape::Shape(size_t dim, ...)
: dim(dim)
{
    LOG_SHAPE("Shape(size_t, ...)");

    calloc_elems();

    va_list vl;
    va_start(vl, dim);
    for (int i=0; i<dim; ++i) {
        elems[i] = va_arg(vl, size_t);
    }
    va_end(vl);
}

Shape::Shape(const Shape &shape)
: dim(shape.dim)
{
    LOG_SHAPE("Shape(const Shape&)");

    calloc_elems();

    for (int i=0; i<dim; ++i) {
        elems[i] = shape.elems[i];
    }
}

Shape::Shape(Shape &&shape) noexcept
: dim(std::exchange(shape.dim, 0)), elems(std::exchange(shape.elems, nullptr))
{
    LOG_SHAPE("Shape(Shape&&)");
}

Shape::~Shape()
{
    LOG_SHAPE("~Shape()");

    dim = 0;
    if (elems) {
        free(elems);
    }
    elems = nullptr;
}

void Shape::calloc_elems()
{
    elems = (size_t*)calloc(dim, sizeof(size_t));
    if (elems == nullptr) {
        perror("Shape");
        exit(1);
    }
}

size_t Shape::get_dim() const
{
    return dim;
}

std::string Shape::to_string() const
{
    std::string str = "(";
    
    for (int i=0; i<dim; ++i) {
        str += std::to_string(elems[i]);
        if (i < dim-1) {
            str += ", ";
        }
    }
    str += ")";

    return str;
}
