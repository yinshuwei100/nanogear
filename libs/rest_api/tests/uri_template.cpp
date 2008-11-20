
#include <boost/test/unit_test.hpp>
#include <nanogear/rest/util/uri_template.hpp>

#define BOOST_TEST_MODULE uri_template_test

using namespace nanogear::rest::util;

BOOST_AUTO_TEST_CASE(simple) {
    uri_template t("http://www.example.com/users/{userid}");
    t.set("userid", "fred");
    
}
