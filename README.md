# matrix-command-line-tool

This is a complete matrix command line tool. It is capable of taking in user input and using it to perform matrix operations.

There are a few key-defining features of this tool, all in order to allow you to perform your matrix computations faster and more efficiently:
- you can save the results of a computation for your next operation
- you can enter the rows of your matrices, just pressing `Enter` when done. the program will figure out the dimensions for you
- you are given infinite retries to enter valid input
- the program'll refactor your input to be extremely readable

As for the output, if you can blink before it's produced, then you can blink really fast (timed to be <20 µs in common case).

As of right now, it can perform the following operations:

- scalar multiplication
- matrix addition
- matrix multiplication
- determinant

[This is what it looks like on your terminal.](./imgs/program-interface.png)

## basic instructions on how to use

- **This is the most important thing on this page:** once you're done inputting the data for a matrix, and you see `Row X: `, just press ***`Enter`***, and the program will be able to tell that you're done inputting your matrix. This is to allow you to input them as fast as possible, without having to type something like `Done` or `N/A`.

- The program will accept input of the forms `X`, `X.X`, `.X`, `-X.X`, `-.X`, but not `X.` or `-X.`

- The program will accept input of the form `X X X` for the matrices (i.e, space separated numerical values). If you want to have 20 spaces between every value, you can do that, but you must have at least one space between any two values.

- Please note that matrices cannot have a different number of entries in each row ... i.e, once you choose a certain number of columns, stick with it. The program won't let you input if it doesn't match your initial row's number of columns. As for matrix operations, remember that certain matrices can't do certain things, and again, the program'll tell you.

- If you don't have a terminal that supports ANSI/VT-100 escape sequences, then there'll be some wonky output. You can either comment it out or submit an issue.

## setting up the program

### Linux/Unix platforms

Run these steps, in the order provided, in your terminal, and you'll be good to go:

- `git clone https://github.com/arteen1000/matrix-command-line-tool.git matrix-clt`
- `cd matrix-clt/matrix-mult`
- `chmod +x compile.sh`
- `./compile.sh`

At this point, you'll have an executable file called called `matrix` that you can run at any time using `./matrix`.

If you know what you're doing, then if I were you, at this point I would run:

- `mv matrix path/to/your/directory/you/would/like/it/in` (I would recommend `/usr/bin/matrix`)
- `cd ../..`
- `rm -rf matrix-clt`

and you'll just have the executable in `path/to/your/directory/you/would/like/it/in`, with no source code bloat (though it's not truly bloated).
