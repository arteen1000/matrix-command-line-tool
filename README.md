# matrix-command-line-tool

This is a complete matrix command line tool. It is capable of taking in user input and using it to perform matrix operations.

The biggest and most defining feature of this tool is that you are able to input the row data of your matrices and the program will figure out the dimensions for you, providing error checking for different operations. This means that if you're checking your homework answers, or just using this on your desktop, it's fast. Really fast. Much faster than typing all those buttons on your clunky graphing calculator, or at least on mine.

As for the output, if you can blink before it's produced, then you can blink really fast.

As of right now, it can perform the following operations, with more coming soon:

- scalar multiplication
- matrix addition
- matrix multiplication

## basic instructions on how to use

- **This is the most important thing on this page:** once you're done inputting the data for a matrix, and you see `Row X: `, just press ***`Enter`***, and the program will be able to tell that you're done inputting your matrix. This is to allow you to input them as fast as possible, without having to type something like `Done` or `N/A`.

- The program will accept input of the forms `X.X`, `.X`, `-X.X`, `-.X`, but not `X.` or `-X.`. If you would seriously like to format your input in this way, you can file a complaint at arteen1000@gmail.com.

- The program will accept input of the form `Y Y Y` for the matrices (i.e, space separated numerical values). If you don't typically use spaces to separate your values, I don't know what to tell you. If you want to have 20 spaces between every value, you can do that, but you must have at least one space between any two values.

- Please note that matrices cannot have a different number of entries in each row ... i.e, once you choose a certain number of columns, stick with it. The program won't let you input if it doesn't match your initial row's number of columns.

- I think that's all, and I really doubt you'll have trouble using this, but if you do, you have my email, and I'll be happy to either (a) provide guidance or (b) adjust the program to suit your needs.

- Also, I don't think this'll come up, but if you have a terminal that doesn't support ANSI/VT100 escape sequences, you might run into some wonky output. Email me and I'll try to help resolve. If you don't want to email me, just comment out the parts that have to do with refactoring input data before you compile the program, and it should run perfectly fine, only your ugly input data won't be reformatted on your terminal prettily.

## setting up the program

Run these steps, in the order provided, in your terminal, and you'll be good to go:

- `git clone https://github.com/arteen1000/matrix-command-line-tool.git matrix-clt`
- `cd matrix-clt/matrix-mult`
- `./compile.sh`

At this point, you'll have an executable file called called `matrix` that you can run at any time using `./matrix`.

If I were you, at this point I would run:

- `mv matrix path/to/your/directory/you/would/like/it/in`
- `cd ../..`
- `rm -rf matrix-clt`

and you'll just have the executable in `path/to/your/directory/you/would/like/it/in`, with no source code bloat :)
