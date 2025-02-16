#include "type.hpp"

using namespace Type;

/*
size_t dim
size_t *elems
*/

Shape& Shape::operator=(const Shape &shape)
{
    if (this == &shape) {
        return *this;
    }

    if (elems != nullptr) {
        free(elems);
    }

    dim = shape.dim;
    calloc_elems();
    
    for (int i=0; i<dim; ++i) {
        elems[i] = shape.elems[i];
    }
    return *this;
}

Shape& Shape::operator=(Shape&& shape) noexcept
{
    if (this == &shape) {
        return *this;
    }

    if (elems) {
        free(elems);
    }

    dim = std::exchange(shape.dim, 0);
    elems = std::exchange(shape.elems, nullptr);

    return *this;
}

const size_t& Shape::operator[](size_t index) const
{
    return elems[index];
}

bool Shape::operator==(const Shape &shape) const
{
    if (dim != shape.dim) {
        return false;
    }

    for (int i=0; i<dim; ++i) {
        if (elems[i] != shape.elems[i]) {
            return false;
        }
    }

    return true;
}

bool Shape::operator!=(const Shape &shape) const
{
    if (dim != shape.dim) {
        return true;
    }

    for (int i=0; i<dim; ++i) {
        if (elems[i] != shape.elems[i]) {
            return true;
        }
    }

    return false;
}
