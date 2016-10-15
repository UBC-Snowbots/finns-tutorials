# cpp

This tutorial is designed to bring you up to speed on features of C++ that can help you increase your productivity and quality of life as a C++ programmer.

## Do you really need that pointer?

Plain pointers are a relic of the past - look at code from 10 years ago (or the code some of you saw in your labs :) ), and you'll see `new`s everywhere `delete`s, and one of your bugs of choice might be segmentation faults and memory leaks.

This is simply unnecessary these days.

Here are some steps you can apply to get your code shorter and simpler:
 - Do you need a pointer at all? Try just instantiating your object on the stack. Maybe it'll just work.
 - OK, maybe it didn't work. You need a pointer. Use std::unique_ptr - it is largely equivalent to removing your `delete` and replacing your `X*` with `std::unique_ptr<X>`. You'll never forget to `delete` again.
 - You need to keep multiple copies of your pointer? Try `std::shared_ptr`, it implements reference couting for you
 - You thought of `shared_ptr` and figured it didn't make sense, you have more than one reference to your object, and you know some references should never be the last one holding a pointer to your object. Then, maybe you can just use a pointer - just make sure the one that is supposed to `delete` is a unique_ptr - you can still do that :)

## Standard algorithms: what can they do for you?

Whenever you're writing some code, you might want to consider if it can be replaced with a single function call (or two).

- Do you need to find something? `std::find` could work.
- Do you need to sort an array? `std::sort` has your back.
- Need to perform some strange permutation of elements in an array? `std::rotate` might help.
- Need to copy a bunch of stuff? `std::copy` could be of use - and even sometimes faster than your own code (I've seen optimisations in std::copy that use SSE)
- Need to remove duplicates in a range? `std::unique` does this.
- Need to sum together a list of numbers? `std::accumulate` does this.
- Need to combine all the elements in a list into one? `std::accumulate` also does this.
- Need to do X? Look it up [here](http://en.cppreference.com/w/cpp/algorithm). Maybe you'll find it.

## C++-fu: the wrapper

So, you've done all this stuff in your own code, but your library is written in C... pointers everywhere - how do you cope?

Moar std::unique_ptr!

See example.
