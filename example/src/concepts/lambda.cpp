// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal.hpp>

#include <type_traits>

#include "example.hpp"

HIDDEN(namespace)
{
/// [ex1]
using lbd = void;
/// [ex1]

static_assert(std::is_same</**/metal::invoke_t<lbd>, void>::value, "");
}

HIDDEN(namespace)
{
/// [ex2]
using lbd = metal::_2;
/// [ex2]

static_assert(std::is_same</**/metal::invoke_t<lbd, int, int>, int>::value, "");
}

HIDDEN(namespace)
{
/// [ex3]
using lbd = metal::lambda<std::add_pointer>;
/// [ex3]

static_assert(std::is_same</**/metal::invoke_t<lbd, void>, void*>::value, "");
}

HIDDEN(namespace)
{
/// [ex4]
using lbd = std::add_pointer<void>;
/// [ex4]

static_assert(std::is_same</**/metal::invoke_t<lbd>, void*>::value, "");
}

HIDDEN(namespace)
{
/// [ex5]
using lbd = std::is_same</**/metal::_1, metal::lambda</**/std::common_type>>;
/// [ex5]

static_assert(metal::invoke_t<lbd, long, int, short>::value, "");
static_assert(!metal::invoke_t<lbd, int, long, short>::value, "");
static_assert(!metal::invoke_t<lbd, short, int, long>::value, "");
}