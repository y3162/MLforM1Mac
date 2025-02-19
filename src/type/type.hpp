#pragma once

#include <iostream>
#include <stdarg.h>

namespace Type
{
    using data_t = double;

    class Shape
    {
    private:
        size_t dim;
        size_t *elems;

        void calloc_elems();

    public:
        Shape();
        Shape(size_t, ...);
        Shape(const Shape&);
        Shape(Shape&&) noexcept;
        ~Shape();

        size_t get_dim() const;

        Shape& operator=(const Shape&);
        Shape& operator=(Shape&&) noexcept;
        const size_t& operator[](size_t) const;
        bool operator==(const Shape&) const;
        bool operator!=(const Shape&) const;

        std::string to_string() const;
    };

    class RowVector
    {
    private:
        Shape shape;
        data_t *elems;

        void calloc_elems();

    public:
        RowVector();
        RowVector(size_t);
        RowVector(const Shape&);
        RowVector(const RowVector&);
        RowVector(RowVector&&) noexcept;
        ~RowVector();

        Shape get_shape() const;
        void reshape(const Shape&);
        void reshape(size_t);

        RowVector& operator=(const RowVector&);
        data_t& operator[](size_t);
        const data_t& operator[](size_t) const;
        RowVector operator+() const;
        RowVector operator+(const RowVector&) const;
        RowVector& operator+=(const RowVector&);
        RowVector operator+(data_t) const;
        RowVector& operator+=(data_t);
        friend RowVector operator+(data_t, const RowVector&);
        RowVector operator-() const;
        RowVector operator-(const RowVector&) const;
        RowVector& operator-=(const RowVector&);
        RowVector operator-(data_t) const;
        RowVector& operator-=(data_t);
        friend RowVector operator-(data_t, const RowVector&);
        RowVector operator*(data_t) const;
        friend RowVector operator*(data_t, RowVector&);
        RowVector& operator*=(data_t);

        std::string to_string() const;
    };

    class Matrix
    {
    private:
        Shape shape;
        RowVector **rows;

        void calloc_rows();

    public:
        Matrix();
        Matrix(size_t, size_t);
        Matrix(const Shape&);
        Matrix(const Matrix&);
        Matrix(Matrix&&) noexcept;
        ~Matrix();

        static Matrix zeros(const Shape&);
        static Matrix ones(const Shape&);

        Shape get_shape() const;
        void reshape(const Shape&);
        void reshape(size_t, size_t);

        Matrix& operator=(const Matrix&);
        RowVector& operator[](size_t);
        const RowVector& operator[](size_t) const;
        Matrix operator+() const;
        Matrix operator+(const Matrix&) const;
        Matrix& operator+=(const Matrix&);
        Matrix operator+(data_t) const;
        Matrix& operator+=(const data_t);
        friend Matrix operator+(data_t, Matrix&);
        Matrix operator-() const;
        Matrix operator-(const Matrix&) const;
        Matrix& operator-=(const Matrix&);
        Matrix operator-(data_t) const;
        Matrix& operator-=(const data_t);
        friend Matrix operator-(data_t, Matrix&);
        Matrix operator*(const Matrix&) const;
        Matrix& operator*=(const Matrix&);
        Matrix operator*(data_t) const;
        Matrix& operator*=(const data_t);
        friend Matrix operator*(data_t, const Matrix&);

        std::string to_string() const;
    };
}
