#define BOOST_TEST_MODULE uri_template

#include <string>
#include <iostream>
#include <boost/test/included/unit_test.hpp>

#include <nanogear/rest/util/uri_template.hpp>

using namespace nanogear::rest::util;


BOOST_AUTO_TEST_CASE(normalization) {
    // Simple normalization: -> all to lower case
    uri_template tpl("hTtp://wWw.EXAMPLE.com/usErs/{uSErID}");
    tpl["uSErID"] = "foo";
    BOOST_REQUIRE(tpl.expanded() == "http://www.example.com/users/foo");
}

BOOST_AUTO_TEST_CASE(variables) {
    // Simple variable
    uri_template tpl("http://example.org/?q={bar}");
    tpl["bar"] = "fred";
    BOOST_REQUIRE(tpl.expanded() == "http://example.org/?q=fred");

    // Variable with default value
    tpl = uri_template("http://example.org/?q={bar=fred}");
    BOOST_REQUIRE(tpl.expanded() == "http://example.org/?q=fred");
    // This time we define a value of 'bar'
    tpl = uri_template("http://example.org/?q={bar=fred}");
    tpl["bar"] = "foo";
    BOOST_REQUIRE(tpl.expanded() == "http://example.org/?q=foo");

    // Undefined variable
    tpl = uri_template("/{xyxyxy}");
    BOOST_REQUIRE(tpl.expanded() == "/");

    // Doubled variable
    tpl = uri_template("http://example.org/?q={bar}{bar}");
    tpl["bar"] = "fred";
    BOOST_REQUIRE(tpl.expanded() == "http://example.org/?q=fredfred");
}

BOOST_AUTO_TEST_CASE(commands) {
    // Opt: expand if defined($var)
    uri_template tpl("{-opt|fred@example.org|foo}");
    tpl["foo"] = "fred";
    BOOST_REQUIRE(tpl.expanded() == "fred@example.org");
    tpl = uri_template("{-opt|fred@example.org|bar}");
    tpl["foo"] = "fred";
    BOOST_REQUIRE(tpl.expanded() == "");

    // Neg: expand if not defined($var)
    tpl = uri_template("{-neg|fred@example.org|foo}");
    tpl["foo"] = "fred";
    BOOST_REQUIRE(tpl.expanded() == "");
    tpl = uri_template("{-neg|fred@example.org|bar}");
    tpl["foo"] = "fred";
    BOOST_REQUIRE(tpl.expanded() == "fred@example.org");

    // {-join|sep|var1,var2,var3}
    // Join: join values using $varname=$varvalue separated by 'sep'
    // Test1: simple
    // tpl = uri_template("http://example.org/?q={-join|&|foo,bar}");
    // tpl.var()[""]
    
//     uri_template tpl("http://example.org/?{-join|&|foo,bar,xyzzy,baz}");
//     tpl.var()["foo"] = "¥";
//     tpl.var()["bar"] = "fred";
//     tpl.var()["baz"] = "10,20,30";
//     BOOST_CHECK(tpl.expanded() == "http://example.org/?foo=%CE%8E&bar=fred&baz=10%2C20%2C30");
}
