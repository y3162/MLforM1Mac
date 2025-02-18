#include "type.hpp"
using namespace Type;

/*
Shape shape;
size_t *elems;
*/

RowVector& RowVector::operator=(const RowVector &rv)
{
    if (this == &rv) {
        return *this;
    }

    if (elems) {
        free(elems);
    }

    shape = rv.shape;
    calloc_elems();

    for (int i=0; i<shape[0]; ++i) {
        elems[i] = rv.elems[i];
    }

    return *this;
}

data_t& RowVector::operator[](size_t index)
{
    return elems[index];
}

const data_t& RowVector::operator[](size_t index) const
{
    return elems[index];
}

RowVector RowVector::operator+() const
{
    // +R
    return *this;
}

RowVector RowVector::operator+(const RowVector &rv) const
{
    // R + R
    if (shape != rv.shape) {
        fprintf(stderr, "RowVector::operator+ : Only RowVectors of the same shape can add. (%lu) is not equal to (%lu).\n", shape[0], rv.shape[0]);
        exit(1);
    }

    RowVector ret(shape);
    for (int i=0; i<shape[0]; ++i) {
        ret[i] = elems[i] + rv.elems[i];
    }

    return ret;
}

RowVector& RowVector::operator+=(const RowVector &rv)
{
    // R1 += R2
    if (shape != rv.shape) {
        fprintf(stderr, "RowVector::operator+= : Only RowVectors of the same shape can add. (%lu) is not equal to (%lu).\n", shape[0], rv.shape[0]);
        exit(1);
    }

    for (int i=0; i<shape[0]; ++i) {
        elems[i] += rv.elems[i];
    }

    return *this;
}

RowVector RowVector::operator+(const data_t x) const
{
    // R + x
    RowVector ret(shape);
    for (int i=0; i<shape[0]; ++i) {
        ret.elems[i] = elems[i] + x;
    }

    return ret;
}

RowVector& RowVector::operator+=(data_t x)
{
    // R += x
    for (int i=0; i<shape[0]; ++i) {
        elems[i] += x;
    }

    return *this;
}

RowVector Type::operator+(data_t x, const RowVector &rv)
{
    // x + R
    RowVector ret(rv.shape);
    for (int i=0; i<rv.shape[0]; ++i) {
        ret.elems[i] = x + rv.elems[i];
    }

    return ret;
}

RowVector RowVector::operator-() const
{
    // -R
    RowVector ret(shape);
    for (int i=0; i<shape[0]; ++i) {
        ret[i] = - elems[i];
    }

    return ret;
}

RowVector RowVector::operator-(const RowVector &rv) const
{
    // R1 - R2
    if (shape != rv.shape) {
        fprintf(stderr, "RowVector::operator- : Only RowVectors of the same shape can subtract. (%lu) is not equal to (%lu).\n", shape[0], rv.shape[0]);
        exit(1);
    }

    RowVector ret(shape);
    for (int i=0; i<shape[0]; ++i) {
        ret[i] = elems[i] - rv.elems[i];
    }

    return ret;
}

RowVector& RowVector::operator-=(const RowVector &rv)
{
    // R1 -= R2
    if (shape != rv.shape) {
        fprintf(stderr, "RowVector::operator-= : Only RowVectors of the same shape can subtract. (%lu) is not equal to (%lu).\n", shape[0], rv.shape[0]);
        exit(1);
    }

    for (int i=0; i<shape[0]; ++i) {
        elems[i] -= rv.elems[i];
    }

    return *this;
}

RowVector RowVector::operator-(const data_t x) const
{
    // R - x
    RowVector ret(shape);
    for (int i=0; i<shape[0]; ++i) {
        ret.elems[i] = elems[i] - x;
    }

    return ret;
}

RowVector& RowVector::operator-=(data_t x)
{
    // R -= x
    for (int i=0; i<shape[0]; ++i) {
        elems[i] -= x;
    }

    return *this;
}

RowVector Type::operator-(data_t x, const RowVector &rv)
{
    // x - R
    RowVector ret(rv.shape);
    for (int i=0; i<rv.shape[0]; ++i) {
        ret.elems[i] = x - rv.elems[i];
    }

    return ret;
}

RowVector RowVector::operator*(data_t x) const
{
    // R * x
    RowVector ret(shape);
    for (int i=0; i<shape[0]; ++i) {
        ret.elems[i] = elems[i] * x;
    }
    return ret;
}

RowVector& RowVector::operator*=(data_t x)
{
    // R *= x
    for (int i=0; i<shape[0]; ++i) {
        elems[i] *= x;
    }
    return *this;
}

RowVector Type::operator*(data_t x, RowVector &rv)
{
    // x * R
    RowVector ret(rv.shape);
    for (int i=0; i<ret.shape[0]; ++i) {
        ret.elems[i] = x * rv.elems[i];
    }
    return ret;
}
