#include "type.hpp"
using namespace Type;

/*
private:
    Shape shape;
    RowVector **rows;
*/

Matrix& Matrix::operator=(const Matrix &mat)
{
    if (this == &mat) {
        return *this;
    }

    for (int i=0; i<shape[0]; ++i) {
        delete rows[i];
    }
    if (rows != nullptr) {
        free(rows);
    }

    shape = mat.shape;
    calloc_rows();

    for (int i=0; i<shape[0]; ++i) {
        rows[i] = new RowVector(*mat.rows[i]);
    }

    return *this;
}

RowVector& Matrix::operator[](size_t index)
{
    return *rows[index];
}

const RowVector& Matrix::operator[](size_t index) const
{
    return *rows[index];
}

Matrix Matrix::operator+() const
{
    // +M
    return Matrix(*this);
}

Matrix Matrix::operator+(const Matrix &mat) const
{
    // M1 + M2
    if (shape != mat.shape) {
        fprintf(stderr, "Matrix::operator+ : Only Matirces of the same shape can add. (%lu, %lu) is not equal to (%lu, %lu).\n", shape[0], shape[1], mat.shape[0], mat.shape[1]);
        exit(1);
    }

    Matrix ret(shape);

    for (int i=0; i<shape[0]; ++i) {
        *ret.rows[i] = *rows[i] + *mat.rows[i];
    }

    return ret;
}

Matrix& Matrix::operator+=(const Matrix &mat)
{
    // M1 += M2
    if (shape != mat.shape) {
        fprintf(stderr, "Matrix::operator+= : Only Matrices of the same shape can add. (%lu, %lu) is not equal to (%lu, %lu).\n", shape[0], shape[1], mat.shape[0], mat.shape[1]);
        exit(1);
    }

    for (int i=0; i<shape[0]; ++i) {
        *rows[i] += *mat.rows[i];
    }

    return *this;
}

Matrix Matrix::operator+(data_t x) const
{
    // M + x
    Matrix ret(shape);

    for (int i=0; i<shape[0]; ++i) {
        *ret.rows[i] = *rows[i] + x;
    }

    return ret;
}

Matrix& Matrix::operator+=(const data_t x)
{
    // M += x
    for (int i=0; i<shape[0]; ++i) {
        *rows[i] += x;
    }

    return *this;
}

Matrix Type::operator+(data_t x, Matrix &mat)
{
    // x + M
    Matrix ret(mat.shape);

    for (int i=0; i<mat.shape[0]; ++i) {
        *ret.rows[i] = x + *mat.rows[i];
    }

    return ret;
}

Matrix Matrix::operator-() const
{
    // -M
    Matrix ret(shape);

    for (int i=0; i<shape[0]; ++i) {
        *ret.rows[i] = - *rows[i];
    }

    return ret;
}

Matrix Matrix::operator-(const Matrix &mat) const
{
    // M1 - M2
    if (shape != mat.shape) {
        fprintf(stderr, "Matrix::operator- : Only Matrices of the same shape can subtract. (%lu, %lu) is not equal to (%lu, %lu).\n", shape[0], shape[1], mat.shape[0], mat.shape[1]);
        exit(1);
    }

    Matrix ret(shape);
    
    for (int i=0; i<shape[0]; ++i) {
        *ret.rows[i] = *rows[i] - *mat.rows[i];
    }

    return ret;
}

Matrix& Matrix::operator-=(const Matrix &mat)
{
    // M1 -= M2
    if (shape != mat.shape) {
        fprintf(stderr, "Matrix::operator+= : Only Matrices of the same shape can subtract. (%lu, %lu) is not equal to (%lu, %lu).\n", shape[0], shape[1], mat.shape[0], mat.shape[1]);
        exit(1);
    }

    for (int i=0; i<shape[0]; ++i) {
        *rows[i] -= *mat.rows[i];
    }

    return *this;
}

Matrix Matrix::operator-(data_t x) const
{
    // M - x
    Matrix ret(shape);

    for (int i=0; i<shape[0]; ++i) {
        *ret.rows[i] = *rows[i] - x;
    }

    return ret;
}

Matrix& Matrix::operator-=(const data_t x)
{
    // M -= x
    for (int i=0; i<shape[0]; ++i) {
        *rows[i] -= x;
    }

    return *this;
}

Matrix Type::operator-(data_t x, Matrix &mat)
{
    // x - M
    Matrix ret(mat.shape);

    for (int i=0; i<mat.shape[0]; ++i) {
        *ret.rows[i] = x - *mat.rows[i];
    }

    return ret;
}

Matrix Matrix::operator*(const Matrix &mat) const
{
    // M1 * M2
    if (shape[1] != mat.shape[0]) {
        fprintf(stderr, "Matrix::operator* : The number of columns in the first Matrix and the number of rows in the second Matrix must be the same. (%lu, %lu) and (%lu, %lu) cannot be multiplied.\n", shape[0], shape[1], mat.shape[0], mat.shape[1]);
        exit(1);
    }

    size_t H = shape[0];
    size_t K = shape[1];
    size_t W = mat.shape[1];
    Matrix ret(H, W);

    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            ret[i][j] = 0;
            for (int k=0; k<K; ++k) {
                ret[i][j] += (*rows[i])[k] * (*mat.rows[k])[j];
            }
        }
    }

    return ret;
}

Matrix& Matrix::operator*=(const Matrix &mat)
{
    // M1 *= M2
    if (shape[1] != mat.shape[0]) {
        fprintf(stderr, "Matrix::operator*= : The number of columns in the first Matrix and the number of rows in the second Matrix must be the same. (%lu, %lu) and (%lu, %lu) cannot be multiplied.\n", shape[0], shape[1], mat.shape[0], mat.shape[1]);
        exit(1);
    }

    size_t H = shape[0];
    size_t K = shape[1];
    size_t W = mat.shape[1];
    Matrix copy = *this;
    this->reshape(H, W);

    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            (*rows[i])[j] = 0;
            for (int k=0; k<K; ++k) {
                (*rows[i])[j] += (*copy.rows[i])[k] * (*mat.rows[k])[j];
            }
        }
    }

    return *this;
}

Matrix Matrix::operator*(data_t x) const
{
    // M * x
    Matrix ret(shape);

    for (int i=0; i<shape[0]; ++i) {
        *ret.rows[i] = *rows[i] * x;
    }

    return ret;
}

Matrix& Matrix::operator*=(const data_t x)
{
    // M *= x
    for (int i=0; i<shape[0]; ++i) {
        *rows[i] *= x;
    }

    return *this;
}

Matrix Type::operator*(data_t x, const Matrix &mat)
{
    // x * M
    Matrix ret(mat.shape);

    for (int i=0; i<mat.shape[0]; ++i) {
        *ret.rows[i] = x * *mat.rows[i];
    }

    return ret;
}
