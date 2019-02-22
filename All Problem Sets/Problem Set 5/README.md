# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

It is the longest word in the dictionaries with a 45 length.
The word describes a lung disease caused by inhaling very fine ash and sand dust.

## According to its man page, what does `getrusage` do?

It gets resource usage measures for a process(es), like CPU time and memory used.

## Per that same man page, how many members are in a variable of type `struct rusage`?

 It has 16 members

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

First, we save memory because there isnt a need of creating a copy of the variables
Secondly, calculate() need to have access to the latest variable data.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

main() first ensures the arguments are valid and correct. It also defaultly use dictionaries/large if user doesn't specify which
dictionary to use. It then calls getrusage() and calculate() to measure load times before and afterstarts reading a text
The for loop in main() tries to read the text symbol-by-symbol, to read separate words. A word is completed
when one or more alphabetic symbols are read, and when we encounter a non-alphanumeric character (like spacebar, or newline). If
there is a digit, or a string tends to be too long, we traverse this word and won't check it for misspellings. If not, we will
check our word for misspellings, reset the word index to zero, and continue the symbol reading loop.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

First, we must allocate a memory for a string before reading it from file, and there are no limits of a length of a word
in a text file. Using fscanf also cause problems with alphanumeric strings or texts containing formatting errors. This is very
not flexible for us

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

Because we don't want those parameters accidentally modified in the functions. It is sort of a safety measures
