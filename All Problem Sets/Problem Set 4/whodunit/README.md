# Questions

## What's `stdint.h`?

// It's a header file for some C/C++ primitive data types, like uint8_t,uint32_t,int32_t,uint16_t.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

// They are aliases for some C/C++ primitive data types.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

// 1 byte, 4 bytes, 4 bytes, 2 bytes.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

// 0x424d

## What's the difference between `bfSize` and `biSize`?

// biSize = sizeof(BITMAPINFOHEADER), bfSize = biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)

## What does it mean if `biHeight` is negative?

// If biHeight is negative, the bitmap is a top-down DIB with the origin at the upper left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

// biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

// If the file isn't successfully opened, a null pointer will be returned.

## Why is the third argument to `fread` always `1` in our code?

// It only reads one element.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

// 3

## What does `fseek` do?

// skip over padding

## What is `SEEK_CUR`?

// It specifies that 'padding' is a count of characters from the current 'inptr' position.

## Whodunit?

// It was Professor Plum with the candlestick in the library.
