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
    const std::string result_simple("http://example.org/?q=fred");
    const std::string result_undefined("/");
    const std::string result_doubled("http://example.org/?q=fredfred");

    // Simple variable
    uri_template tpl("http://example.org/?q={bar}");
    tpl.var()["bar"] = "fred";
    BOOST_CHECK(tpl.expanded() == result_simple);

    // Undefined variable
    tpl = uri_template("/{xyxyxy}");
    BOOST_CHECK(tpl.expanded() == result_undefined);

    // Doubled variable
    tpl = uri_template("http://example.org/?q={bar}{bar}");
    tpl.var()["bar"] = "fred";
    BOOST_CHECK(tpl.expanded() == result_doubled);
}
