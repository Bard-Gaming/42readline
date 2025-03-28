# 42readline

## Project Description
This library is used for the [42sh](https://github.com/Bard-Gaming/42sh)
project.

The library adds the ``readline`` function, which behaves much like
the c standard library's ``getline`` function, with a few notable differences.

For instance, the ``readline`` handles cursor control (i.e. controlling
the terminal cursor with arrow keys) if the given file stream is a tty stream.


## Compile Instructions
To compile the standard version of readline,
simply run make:

```bash
make
```

To compile a version with debug symbols enabled,
use the ``debug`` rule:

```bash
make debug
```
This project uses the address sanitizer to ensure no
memory leaks are produced. To compile the library with
the address sanitizer enabled, please use the
``sanitize`` rule:

```bash
make sanitize
```

When you're done, you can use the ``clean`` rule
to delete any temporary files, or the ``fclean``
rule to delete everything but the source code.
