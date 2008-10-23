add_library(nanogear_rest SHARED
  data/challenge_request.cpp
  data/challenge_response.cpp
  data/challenge_scheme.cpp
  data/client_info.cpp
#  data/conditions.cpp
#    Missing class: tag
  data/cookie.cpp
  data/cookie_setting.cpp
  data/metadata.cpp
  data/method.cpp
  data/parameter.cpp
  data/protocol.cpp
  data/reference.cpp
  data/request.cpp
  data/response.cpp
  data/character_set.cpp
  data/preference.cpp

  
  application.cpp
  client.cpp
#  component.cpp
  connector.cpp
  context.cpp
  filter.cpp
  controller.cpp
  uniform.cpp
)

