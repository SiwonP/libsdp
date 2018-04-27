add_library(
    libsdp SHARED
    description.c
    )

set_target_properties(libsdp PROPERTIES VERSION ${PROJECT_VERSION})

