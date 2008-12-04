#include <string>
#include <iostream>

#define BOOST_TEST_MODULE uri_template_test
#include <boost/test/included/unit_test.hpp>

#include <nanogear/rest/util/uri_template.hpp>

using namespace nanogear::rest::util;

// Test for URI normalization (i.e: make it all lowercase)
// BOOST_AUTO_TEST_CASE(normalization) {
//     uri_template t("hTtp://wWw.EXAMPLE.com/usErs/{uSErID}");
//     std::string s("http://www.example.com/users/{userid}");
//     BOOST_CHECK(t.expanded() ==  s);
// }

BOOST_AUTO_TEST_CASE(variables) {
    // result with simple assignment (no default value)
    const std::string result1("http://example.org/?q=fred");
    uri_template t1("http://example.org/?q={bar}");
    t1.var()["bar"] = "fred";
    BOOST_CHECK(t1.expanded() == result1);

    // result with no defined variable
    const std::string result2("/");
    uri_template t2("/{xyxyxy}");
    BOOST_CHECK(t2.expanded() == result2);
}
