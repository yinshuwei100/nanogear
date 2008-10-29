add_library(nanogear_rest SHARED
  data/challenge_request.cpp
  data/challenge_response.cpp
  data/challenge_scheme.cpp
  data/character_set.cpp
  data/client_info.cpp
#  data/conditions.cpp # TODO: Fix compile errors
  data/cookie.cpp
  data/cookie_setting.cpp
  data/encoding.cpp
# data/form.cpp # MISSING
# data/local_reference.cpp # MISSING
  data/metadata.cpp
  data/method.cpp
# data/message.cpp # MISSING
  data/parameter.cpp
  data/protocol.cpp
  data/reference.cpp
  data/request.cpp
# data/reference.cpp # MISSING
# data/reference_list.cpp # MISSING
  data/response.cpp
  data/media_type.cpp
  data/tag.cpp
  data/server_info.cpp
  data/status.cpp

  
  application.cpp
  client.cpp
#  component.cpp
  connector.cpp
  context.cpp
  filter.cpp
  controller.cpp
  uniform.cpp
)

