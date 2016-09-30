# Fun with CMake

Welcome to my little tutorial on CMake - hopefully I can help take some of the magic out of this strange tool.

This tutorial is split into 4 distinct sections:

1. How to build "Hello World!"
2. The CMake language
3. How to test things
4. So how does catkin fit into all this?

I recommend you keep the [CMake reference](https://cmake.org/cmake/help/v3.6/) around, especially [this page](https://cmake.org/cmake/help/v3.6/manual/cmake-commands.7.html) - it describes the exact semantics of the commands I will be using in much more detail than I can.

## How to build "Hello World!"

Example code is in the [hello_world](./hello_world) folder. To run the build, type `cmake . && make`.

To build produce an executable, use the [`add_executable`](https://cmake.org/cmake/help/v3.6/command/add_executable.html) command.

```cmake
add_executable(hello_world hello_world.cpp)
```

...wait what's a command? Let's take this to bits so we can start to understand how the CMake language works.

A CMake command is a line that goes something like this:
```cmake
# this is how you write a comment by the way
do_the_thing(a b NEXT_BIT c d AFTER_THAT e WITH_CHEESE_ON_TOP)
```

Each command has its own name which comes before the brackets. Between the brackets, there are a series of arguments separated by spaces (to pass an argument with a space in it, write `a\ b` or one of the other tricks you can find [here](https://cmake.org/cmake/help/v3.0/manual/cmake-language.7.html#command-arguments).

By convention, arguments in block caps are either flags enabling some feature or are separators that say something about the arguments that come after them. Take this boilerplate you'll find at the top of all the files we use in this tutorial for example:
```cmake
cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

project(version1 CXX)
```

This means `cmake_minimum_required` receives a VERSION of 3.6.2, and has the FATAL_ERROR flag set. `project` defines the name to be "version1" (just plain positional parameter passing) and enables the language CXX (C++).

The only datatype in CMake is strings, so they had to get a little creative to allow the passing of structured data between functions.

## The CMake language

The CMake reference manual and some experimenting will tell you more than I ever could, but here I hope to highlight some interesting ~~features~~ gotchas of the language.

I have attached some scripts you can run with `cmake -P thescript.cmake` in the [cmake_language](./cmake_language) folder.

Topic list:

- Variables
- Booleans when they're strings...
- Functions in brief

### Variables

Observation: everything in CMake is a string. Let's try defining some variables:
```cmake
set(FOO foo)
set(BAR 22)
```

This uses the `set` command to define two variables: `FOO` and `BAR`. Their respective values are "foo" and "22".

A note on convention: for global variables and constants, people use block caps, otherwise lowercase is fine.

So far so good... now how do you make anything other than a string? Boring answer: you don't. More interesting answer - like this:

```cmake
set(I_AM_A_LIST a b c)
set(SAME_HERE a;b;c d)
set(NUMBER 2) # still a string, but an be interpreted as a number
```

Valid lists are just strings with the elements separated by `;`. This has some advantages in terms of flexibility - you can space-separate arguments or you can semicolon-separate them.

While your mileage may vary, semicolons can be escaped using '\\'. If this fails, you can try quotes.

```cmake
set(A a)
# ${A} is replaced with the value of A
set(B ${A})
```
This works because variables are replaced as if you had literally typed their contents in their place. Use this if you want to use the value of a variable, but if using lists you sometimes need to do things like `"${L}"` in order to void passing each element of `L` as its own parameter instead of a one parameter.

### Booleans when they're strings...

Booleans in CMake are quite interesting and deserve their own section.

Here is an excerpt from the CMake 3.6 documentation:
> True if the constant is 1, ON, YES, TRUE, Y, or a non-zero number. False if the constant is 0, OFF, NO, FALSE, N, IGNORE, NOTFOUND, the empty string, or ends in the suffix -NOTFOUND. Named boolean constants are case-insensitive

Have fun with that.

Brief example of said fun:
```cmake
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
```

### Functions in brief

This topic is for the more hardcore - hopefully you can get by with a couple of lists and some `add_executable` (and related) commands.

This is how you define a function:
```cmake
function(my_sum retval msg)
  set(count 0)
  foreach(i IN LISTS ARGN)
    math(EXPR count ${i}+${count})
  endforeach(i)
  message(${msg})
  set(${retval} ${count} PARENT_SCOPE)
endfunction()

my_sum(cnt "My Function" 1 2 3 4 5)
message("Count is: ${cnt}")
```

Note the lack of proper return values and the options you can give to various builtins for special behaviour. If you need to do something special, it's worth checking to see if CMake can't just do it for you with a special option somewhere.

## How to test things

Testing is very simplistic. All you need is to write a test program using the framework of your choice (see my example under [testing](./testing) - it doesn't use a framework, only standard assert) and register it using the `add_test` function.

```cmake
# actually build stuff...

enable_testing() # important
# CMake runs with testing disabled by default

#add_executable(<your test executable...>), etc...

add_test(NAME <test name> COMMAND <how to run the test>)
```

To run the tests once you've built your code (using `cmake . && make`):
```shell
# runs the tests (and tells you what broke
#  - by default it doesn't :D)
ctest --output-on-failure
```

I recommend using one of these frameworks to get started with C++ unit testing:
- [gtest](https://github.com/google/googletest/) (Snowbots-endorsed!)
- [CATCH](https://github.com/philsquared/Catch)

## How does catkin fit into all this?

TODO
