# matrix-command-line-tool

This is a complete matrix command line tool. It is capable of taking in user input and using it to perform matrix operations.

You might ask why you would use this over a graphing calculator. In response, I would say (a) it's much faster to use (b) it's nice to have on your desktop while doing some linear algebra. I actually created this during winter break after I took Math 33A, a lower-division linear algebra course at UCLA.

There are a few key-defining features of this tool, all in order to allow you to perform your matrix computations faster and more efficiently:
- you can save the result matrix as an operand matrix for your next operation
- you just have to enter the rows of your matrices, pressing ***Enter*** at the prompt when done. the program will figure out the dimensions for you
- you are given up to three tries with every prompt to enter valid input
- the program'll refactor your input to be extremely readable

As for the output, if you can blink before it's produced, then you can blink really fast.

As of right now, the program can perform the following operations, with more coming soon:

- scalar multiplication
- matrix addition
- matrix multiplication
- determinant

[This is what it looks like on your terminal.](./imgs/program-interface.png)

## basic instructions on how to use

- **This is the most important thing on this page:** once you're done inputting the data for a matrix, and you see `Row X: `, just press ***Enter***, and the program will be able to tell that you're done inputting your matrix. This is to allow you to input them as fast as possible, without having to type something like `Done` or `N/A`.

- The program will accept input of the forms `X.X`, `.X`, `-X.X`, `-.X`, but not `X.` or `-X.`.

- The program will accept input of the form `X.X -.X X` for the matrices (i.e, space separated numerical values). If you want to have 20 spaces between every value, you can do that, but you must have at least one space between any two values.

- Please note that matrices cannot have a different number of entries in each row ... i.e, once you choose a certain number of columns, stick with it. The program won't let you input if it doesn't match your initial row's number of columns. As for matrix operations, remember that certain matrices can't do certain things, and again, the program'll tell you.

- I think that's all, and I really doubt you'll have trouble using this, but if you do, you can email me at [Arteen Abrishami](mailto:arteen1000@gmail.com?subject=[github]%20matrix-command-line-tool), and I'll be happy to either (a) provide guidance or (b) adjust the program to suit your needs.

- Also, I don't think this'll come up, but if you have a terminal that doesn't support ANSI/VT100 escape sequences, you might run into some wonky output. Email me and I'll try to help resolve. Otherwise, just comment out the parts that have to do with refactoring input data before you compile the program, and it should run perfectly fine, only your input data won't be reformatted on your terminal prettily.

## setting up the program

### Linux/Unix platforms

Run these commands in your terminal, in the order provided, and you'll be good to go:

- `git clone https://github.com/arteen1000/matrix-command-line-tool.git matrix-clt`
- `cd matrix-clt/matrix-mult`
- `chmod +x compile.sh`
- `./compile.sh`

At this point, you'll have an executable file called called `matrix` in `../../matrix-clt/matrix-mult` that you can run at any time using `./matrix`.

If you know what you're doing, then if I were you, at this point I would run:

- `mv matrix path/to/your/directory/you/would/like/it/in`
- `cd ../..`
- `rm -rf matrix-clt`

and you'll just have the executable in `path/to/your/directory/you/would/like/it/in`, with no source code bloat :)

Otherwise, you can use a file manager, like `Finder` on MacOS, to do the same thing.
