cmake_minimum_required(VERSION 3.4)

set(A 1)
if(A)
  message(A) # prints
endif()

set(B Y)
if(B)
  message(B) # prints
endif()

set(C y)
if(C)
  message(C) # prints
endif()

set(D no)
if(D)
  message(D) #doesn't print
endif()

# what does this one do? read the docs very carefully... :)
set(Y OFF)
if(Y)
  message(Y_weird)
endif()
# to avoid the madness, you can write it like this
if("${Y}")
  message(Y_fixed)
endif()
