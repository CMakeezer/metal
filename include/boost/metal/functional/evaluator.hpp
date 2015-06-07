// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_EVALUATOR_HPP
#define BOOST_METAL_FUNCTIONAL_EVALUATOR_HPP

#include <boost/metal/functional/eval.hpp>

namespace boost
{
    namespace metal
    {
        template<template<typename...> class expr>
        struct evaluator
        {
            using type = evaluator;

            template<typename... args>
            struct call :
                    eval<expr, args...>
            {};
        };
    }
}

#endif