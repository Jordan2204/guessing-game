# Copyright (c) Open Enclave SDK contributors.
# Licensed under the MIT License.
add_custom_command(
  OUTPUT guessing_u.h guessing_u.c guessing_args.h
  DEPENDS ${CMAKE_SOURCE_DIR}/guessing.edl
  COMMAND
    openenclave::oeedger8r --untrusted ${CMAKE_SOURCE_DIR}/guessing.edl
    --search-path ${OE_INCLUDEDIR} --search-path
    ${OE_INCLUDEDIR}/openenclave/edl/sgx)

add_executable(guessing_host host.c
                               ${CMAKE_CURRENT_BINARY_DIR}/guessing_u.c)

if (WIN32)
  copy_oedebugrt_target(guessing_host_oedebugrt)
  add_dependencies(guessing_host guessing_host_oedebugrt)
endif ()

target_include_directories(
  guessing_host PRIVATE # Needed for the generated file guessing_u.h
                          ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(guessing_host openenclave::oehost)
