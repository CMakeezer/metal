// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_PAIR_PAIR_HPP
#define METAL_PAIR_PAIR_HPP

#include <metal/config.hpp>

#include <metal/list/list.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename val>
        struct _is_pair;
    }
    /// \endcond

    /// \ingroup pair
    ///
    /// ### Description
    /// Checks whether some \value is a \pair.
    ///
    /// ### Usage
    /// For any \value `val`
    /// \code
    ///     using result = metal::is_pair<val>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `val` is a \pair, then
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet pair.cpp is_pair
    ///
    /// ### See Also
    /// \see pair, is_value, is_number, is_lambda, is_list, is_map
    template<typename val>
    using is_pair = typename detail::_is_pair<val>::type;

    /// \ingroup pair
    ///
    /// ### Description
    /// Constructs a \pair out of a pair of \values.
    ///
    /// ### Usage
    /// For any pair of \values `x` and `y`
    /// \code
    ///     using result = metal::pair<x, y>;
    /// \endcode
    ///
    /// \returns: \pair
    ///
    /// ### See Also
    /// \see is_pair
    template<typename x, typename y>
    using pair = metal::list<x, y>;
}

#include <metal/number/number.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename val>
        struct _is_pair :
            false_
        {};

        template<typename x, typename y>
        struct _is_pair<list<x, y>> :
            true_
        {};
    }
    /// \endcond
}

#endif
