add_library(nanogear_rest SHARED
#  data/challenge_request.cpp
#    Missing class: parameter
  data/challenge_response.cpp
  data/challenge_scheme.cpp
#  data/client_info.cpp
#    Missing class: preference
#    Function declarations needs to be fixed
#  data/conditions.cpp
#    Missing class: tag
#  data/cookie.cpp
#    Missing class: parameter
#  data/cookie_setting.cpp
#    Depends on cookie which depends on missing class: parameter
  data/metadata.cpp
  data/method.cpp
  data/protocol.cpp
  data/reference.cpp
  data/request.cpp
#  data/response.cpp
#    Depends on cookie_settings which depends on cookie which
#    depends on the missing class: parameter
  data/character_set.cpp

  
#  application.cpp
#    Depends on missing class parameter
#  client.cpp
#    Depends on response which depends on parameter (missing)
  component.cpp
  connector.cpp
  context.cpp
  filter.cpp
  controller.cpp
  uniform.cpp
)

