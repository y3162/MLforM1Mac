#ifdef DEBUG_MATRIX
#define LOG_MATRIX(msg) std::cerr << "[DEBUG] " << msg << std::endl
#else
#define LOG_MATRIX(msg)
#endif

#include "type.hpp"
using namespace Type;

/*
Shape shape;
RowVector **rows;
*/

Matrix::Matrix()
: shape(Shape(2, 0, 0)), rows(nullptr)
{
    LOG_MATRIX("Matrix()");
}

Matrix::Matrix(size_t H, size_t W)
: shape(Shape(2, H, W))
{
    LOG_MATRIX("Matrix(size_t, size_t)");

    calloc_rows();

    for (int i=0; i<shape[0]; ++i) {
        rows[i] = new RowVector(shape[1]);
    }
}

Matrix::Matrix(const Shape &shape)
: shape(shape)
{
    LOG_MATRIX("Matrix(const Shape&)");

    if (shape.get_dim() != 2) {
        fprintf(stderr, "Matrix : Specified size must be 2-dimension, but %lu-dimension was given.\n", shape.get_dim());
        exit(1);
    }

    calloc_rows();

    for (int i=0; i<shape[0]; ++i) {
        rows[i] = new RowVector(shape[1]);
    }
}

Matrix::Matrix(const Matrix &mat)
: shape(mat.shape)
{
    LOG_MATRIX("Matrix(const Matrix&)");

    calloc_rows();

    for (int i=0; i<shape[0]; ++i) {
        rows[i] = new RowVector(*mat.rows[i]);
    }
}

Matrix::Matrix(Matrix &&mat) noexcept
: shape(std::move(mat.shape)), rows(std::exchange(mat.rows, nullptr))
{
    LOG_MATRIX("Matrix(Matrix&&)");

    mat.shape = Shape(2, 0, 0);
}

Matrix::~Matrix()
{
    LOG_MATRIX("~Matrix()");

    size_t H = shape[0];

    //shape.~Shape()

    for (int i=0; i<H; ++i) {
        delete rows[i];
    }
    if (rows) {
        free(rows);
    }
    rows = nullptr;
}

Matrix Matrix::zeros(const Shape &shape)
{   
    Matrix M = Matrix(shape);
    
    return M;
}

Matrix Matrix::ones(const Shape &shape)
{
    Matrix M = Matrix::zeros(shape);
    
    return M + 1;
}

void Matrix::calloc_rows()
{   
    size_t H = shape[0];
    rows = (RowVector**)calloc(H, sizeof(RowVector*));
    if (!rows) {
        perror("Matrix");
        exit(1);
    }

    size_t W = shape[1];
}

Shape Matrix::get_shape() const
{
    return shape;
}

void Matrix::reshape(const Shape &shape)
{
    if (shape.get_dim() != 2) {
        fprintf(stderr, "Matrix : Specified size must be 2-dimension, but %lu-dimension was given.\n", shape.get_dim());
        exit(1);
    }

    reshape(shape[0], shape[1]);
}

void Matrix::reshape(size_t H, size_t W)
{
    rows = (RowVector**)realloc(rows, H * sizeof(RowVector*));
    if (!rows) {
        perror("Matrix");
        exit(1);
    }

    for (int i=0; i<H; ++i) {
        if (i < shape[0]) {
            rows[i]->reshape(W);
        } else {
            rows[i] = new RowVector(W);
        }
    }

    shape = Shape(2, H, W);
}

std::string Matrix::to_string() const
{
    std::string str = "[";

    size_t H = shape[0];

    for (int i=0; i<H; ++i) {
        str += rows[i]->to_string();
        if (i < H-1) {
            str += ",\n ";
        }
    }

    str += "]";

    return str;
}
