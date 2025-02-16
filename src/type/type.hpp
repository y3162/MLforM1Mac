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
}
