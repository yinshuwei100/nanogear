#include <string>
#include <iostream>

#define BOOST_TEST_MODULE method_test
#include <boost/test/included/unit_test.hpp>

#include <nanogear/rest/data/method.hpp>

using namespace nanogear::rest::data;

BOOST_AUTO_TEST_CASE(presets) {
    BOOST_CHECK(method::CONNECT == method::value_of("CONNECT"));
    BOOST_CHECK(method::CONNECT.name() == "CONNECT");
    BOOST_CHECK(method::COPY == method::value_of("COPY"));
    BOOST_CHECK(method::COPY.name() == "COPY");
    BOOST_CHECK(method::DELETE == method::value_of("DELETE"));
    BOOST_CHECK(method::DELETE.name() == "DELETE");
    BOOST_CHECK(method::GET == method::value_of("GET"));
    BOOST_CHECK(method::GET.name() == "GET");
    BOOST_CHECK(method::HEAD == method::value_of("HEAD"));
    BOOST_CHECK(method::HEAD.name() == "HEAD");
    BOOST_CHECK(method::LOCK == method::value_of("LOCK"));
    BOOST_CHECK(method::LOCK.name() == "LOCK");
    BOOST_CHECK(method::MKCOL == method::value_of("MKCOL"));
    BOOST_CHECK(method::MKCOL.name() == "MKCOL");
    BOOST_CHECK(method::MOVE == method::value_of("MOVE"));
    BOOST_CHECK(method::MOVE.name() == "MOVE");
    BOOST_CHECK(method::OPTIONS == method::value_of("OPTIONS"));
    BOOST_CHECK(method::OPTIONS.name() == "OPTIONS");
    BOOST_CHECK(method::POST == method::value_of("POST"));
    BOOST_CHECK(method::POST.name() == "POST");
    BOOST_CHECK(method::PROPFIND == method::value_of("PROPFIND"));
    BOOST_CHECK(method::PROPFIND.name() == "PROPFIND");
    BOOST_CHECK(method::PROPPATCH == method::value_of("PROPPATCH"));
    BOOST_CHECK(method::PROPPATCH.name() == "PROPPATCH");
    BOOST_CHECK(method::PUT == method::value_of("PUT"));
    BOOST_CHECK(method::PUT.name() == "PUT");
    BOOST_CHECK(method::TRACE == method::value_of("TRACE"));
    BOOST_CHECK(method::TRACE.name() == "TRACE");
    BOOST_CHECK(method::UNLOCK == method::value_of("UNLOCK"));
    BOOST_CHECK(method::UNLOCK.name() == "UNLOCK");
}
