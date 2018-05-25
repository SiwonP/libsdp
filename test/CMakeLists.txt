enable_testing()

find_library(NAMES criterion)

add_executable(unit_test
    test.c
    ../src/description.c
    )

add_test(NAME unit_test COMMAND unit_test)

target_link_libraries(unit_test criterion)
