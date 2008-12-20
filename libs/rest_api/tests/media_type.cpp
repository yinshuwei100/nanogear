#include <string>
#include <iostream>

#define BOOST_TEST_MODULE media_type_test
#include <boost/test/included/unit_test.hpp>

#include <nanogear/rest/data/media_type.hpp>

using namespace nanogear::rest::data;

BOOST_AUTO_TEST_CASE(presets) {
    #if 0
    BOOST_CHECK(media_type::UNLOCK == media_type::value_of("UNLOCK"));
    BOOST_CHECK(media_type::UNLOCK.name() == "UNLOCK");
    #endif
    BOOST_CHECK(media_type::all == media_type::value_of("*/*"));
    BOOST_CHECK(media_type::all.name() == "*/*");
    BOOST_CHECK(media_type::application::all == media_type::value_of("application/*"));
    BOOST_CHECK(media_type::application::all.name() == "application/*");
    BOOST_CHECK(media_type::audio::all == media_type::value_of("audio/*"));
    BOOST_CHECK(media_type::audio::all.name() == "audio/*");
    BOOST_CHECK(media_type::image::all == media_type::value_of("image/*"));
    BOOST_CHECK(media_type::image::all.name() == "image/*");
    BOOST_CHECK(media_type::message::all == media_type::value_of("message/*"));
    BOOST_CHECK(media_type::message::all.name() == "message/*");
    BOOST_CHECK(media_type::model::all == media_type::value_of("model/*"));
    BOOST_CHECK(media_type::model::all.name() == "model/*");
    BOOST_CHECK(media_type::multipart::all == media_type::value_of("multipart/*"));
    BOOST_CHECK(media_type::multipart::all.name() == "multipart/*");
    BOOST_CHECK(media_type::text::all == media_type::value_of("text/*"));
    BOOST_CHECK(media_type::text::all.name() == "text/*");
    BOOST_CHECK(media_type::video::all == media_type::value_of("video/*"));
    BOOST_CHECK(media_type::video::all.name() == "video/*");
}
