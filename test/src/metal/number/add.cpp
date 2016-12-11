// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/add.hpp>
#include <metal/number/number.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, VALUE(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, VALUE(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, VALUE(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, VALUE(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, VALUE(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, VALUE(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, NUMBER(M) COMMA(N) VALUES(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, NUMBER(M) COMMA(N) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, NUMBER(M) COMMA(N) PAIRS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, NUMBER(M) COMMA(N) LISTS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, NUMBER(M) COMMA(N) MAPS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, NUMBER(M) COMMA(N) LAMBDAS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, PAIR(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, PAIR(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, PAIR(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, PAIR(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, PAIR(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, PAIR(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LIST(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LIST(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LIST(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LIST(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LIST(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LIST(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, MAP(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, MAP(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, MAP(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, MAP(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, MAP(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, MAP(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LAMBDA(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LAMBDA(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LAMBDA(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LAMBDA(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LAMBDA(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LAMBDA(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LAMBDA(_) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LAMBDA(_) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LAMBDA(_) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LAMBDA(_) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LAMBDA(_) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::add>, LAMBDA(_) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::add<NUMBERS(M) COMMA(AND(M, N)) NUMBERS(N)>), (metal::number<M*(M - 1)/2 + N*(N - 1)/2>)); \
/**/

GEN(MATRIX)
