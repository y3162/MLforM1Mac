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

        void reshape(const Shape&);
        void reshape(size_t);

    public:
        RowVector();
        RowVector(size_t);
        RowVector(const Shape&);
        RowVector(const RowVector&);
        RowVector(RowVector&&) noexcept;
        ~RowVector();

        Shape get_shape() const;

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
}
