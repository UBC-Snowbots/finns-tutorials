function(my_sum retval msg)
  set(count 0)
  foreach(i IN LISTS ARGN)
    math(EXPR count ${i}+${count})
  endforeach(i)
  message(${msg})
  set(${retval} ${count} PARENT_SCOPE)
endfunction()

my_sum(cnt "My message" 1 2 3 4 5)
message("Count is: ${cnt}")