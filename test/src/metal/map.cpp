// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/map.hpp>
#include <metal/list.hpp>
#include <metal/pair.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::transform_t<MAP(M), metal::first<ARG(0)>>), (metal::keys_t<MAP(M)>)); \
    ASSERT((metal::transform_t<MAP(M), metal::second<ARG(0)>>), (metal::values_t<MAP(M)>)); \
    ASSERT((metal::first_t<metal::transpose_t<MAP(INC(M))>>), (metal::keys_t<MAP(INC(M))>)); \
    ASSERT((metal::second_t<metal::transpose_t<MAP(INC(M))>>), (metal::values_t<MAP(INC(M))>)); \
    ASSERT((metal::at_t<MAP(LIMIT), metal::order_t<MAP(LIMIT), NUM(N)>>), (PAIR(N))); \
/**/

GEN(MATRIX)
