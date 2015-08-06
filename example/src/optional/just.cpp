// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/just.hpp>

namespace is_just
{
    /// [is_just]
    struct nothing
    {};

    struct something
    {
        struct type;
    };

    static_assert(!metal::is_just<nothing>::value, "");
    static_assert(metal::is_just<something>::value, "");
    /// [is_just]
}

int main()
{
    return 0;
}
