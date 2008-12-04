add_subdirectory(tests)

add_library(nanogear_rest SHARED
  nanogear/rest/data/challenge_request.cpp
  nanogear/rest/data/challenge_response.cpp
  nanogear/rest/data/challenge_scheme.cpp
  nanogear/rest/data/character_set.cpp
  nanogear/rest/data/client_info.cpp
#  nanogear/rest/data/conditions.cpp # TODO: Fix compile errors
  nanogear/rest/data/cookie.cpp
  nanogear/rest/data/cookie_setting.cpp
  nanogear/rest/data/encoding.cpp
# nanogear/rest/data/form.cpp # MISSING
# nanogear/rest/data/local_reference.cpp # MISSING
  nanogear/rest/data/metadata.cpp
  nanogear/rest/data/method.cpp
  nanogear/rest/data/message.cpp
  nanogear/rest/data/parameter.cpp
  nanogear/rest/data/product.cpp
  nanogear/rest/data/protocol.cpp
  nanogear/rest/data/reference.cpp
  nanogear/rest/data/request.cpp
# nanogear/rest/data/reference.cpp # MISSING
# nanogear/rest/data/reference_list.cpp # MISSING
  nanogear/rest/data/response.cpp
  nanogear/rest/data/media_type.cpp
  nanogear/rest/data/tag.cpp
  nanogear/rest/data/server_info.cpp
  nanogear/rest/data/status.cpp

  nanogear/rest/resource/representation.cpp
  nanogear/rest/resource/variant.cpp

  nanogear/rest/util/engine.cpp
  nanogear/rest/util/uri_template.cpp

  nanogear/rest/application.cpp
  nanogear/rest/client.cpp
#  nanogear/rest/component.cpp
  nanogear/rest/connector.cpp
  nanogear/rest/context.cpp
  nanogear/rest/controller.cpp
  nanogear/rest/route.cpp
  nanogear/rest/router.cpp
  nanogear/rest/uniform.cpp
  nanogear/rest/virtual_host.cpp
  nanogear/rest/server.cpp
  nanogear/rest/handler.cpp
)

target_link_libraries(nanogear_rest)

