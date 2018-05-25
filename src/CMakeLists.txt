add_library(
    sdp SHARED
    description.c
    )

set_target_properties(sdp PROPERTIES VERSION ${PROJECT_VERSION})

