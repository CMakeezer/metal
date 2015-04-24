// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_CALL_HPP
#define BOOST_MPL2_LAMBDA_CALL_HPP

#include <boost/mpl2/lambda/pack.hpp>
#include <boost/mpl2/lambda/forward.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename function, typename... args>
        struct call :
                forward<function::template call, pack<args...> >
        {};
    }
}

#endif
