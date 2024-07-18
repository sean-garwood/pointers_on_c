# chapter 14 notes: the preprocessor

## macros

form:
`#define macro_name(macro_parameters_list) stuff`

* `macro_parameters_list` is a comma separated list of symbols that may appear
  in `stuff`
* no whitespace between name and params open paren.

when macros are invoked, name is followed by c-s list of values (one for each
param)

Actual value given for each param is subbed into stuff

```c
// here's a macro that takes one param:
#define SQUARE(x) x * x

// now, all appearances of `SQUARE(x)` in source are replaced by `x * x` at compile time.
// be sure to wrap stuff in parens to avoid weird behaviour
```

## substitutions

steps:

1. for macro invocations, args examined to see if contain #define symbols.
  a. if so, they are replaced first.
1. sub text inserted into program. macro args are replaced by values
1. resultant text scanned again. if any define exist, go to 1.

macro args and #define defs can contain other #define'd symbols.

**string literals are not scanned for #define**
