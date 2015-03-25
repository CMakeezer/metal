// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_INTEGRAL_BOOLEAN_HPP
#define BOOST_MPL2_CORE_INTEGRAL_BOOLEAN_HPP

#include <boost/mpl2/core/integral.hpp>
#include <boost/mpl2/core/compat/alias.hpp>

namespace boost
{
    namespace mpl2
    {
        template<bool constant>
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(bool_, (integral<bool, constant>));

        typedef bool_<true> true_;
        typedef bool_<false> false_;
    }
}

#endif
