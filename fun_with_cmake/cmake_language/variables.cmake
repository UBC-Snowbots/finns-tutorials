
set(I_AM_A_STRING foo)
message("I_AM_A_STRING: ${I_AM_A_STRING}")

set(I_AM_A_LIST a b c;d)
message("I_AM_A_LIST:")
foreach(i ${I_AM_A_LIST})
  message(${i})
endforeach()

# how to escape semicolons
# note: may or may not work depending on context - be suspicious if your lists start acting up...
message("escaping semicolons:")
foreach(i a\;b\;c d)
  message(${i})
endforeach()

set(ALSO_FOO ${I_AM_A_STRING})
message("ALSO_FOO: ${ALSO_FOO}")
