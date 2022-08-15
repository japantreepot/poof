// Programs using `poof` undergo two phases of compilation.
//
//
// First, `poof` looks through the program and executes metaprogramming
// routines as specified.  Poof generates C code which is output to header
// files.  Those headers are included inline, immediately after the meta code
// that was written by the programmer.
//
// After poof has run, the program gets compiled with a regular C or C++
// compiler.  In the case of these examples we'll use clang, but any compiler
// will do.


// One of the core design philosophies of `poof` is that:
//
// "If poof disappears, I should be left with a working program"
//
// All `poof` code lives inside the `meta` macro.

#define meta(...)

// As you can see, we can put any arbitrary junk inside the meta macro and the
// subsequent compilation step with `clang` will be unaffected.


int main()
{
  meta(Type whatever random crap in here you want clang will ignore it)
  return 0;
}

// This is not a valid `poof` program, we'll get to that in the next example,
// but it's important to understand that `poof` code evaporates during regular
// compilation.

