# BMP-Parser
[![CodeFactor](https://www.codefactor.io/repository/github/kibotrel/bmp-parser/badge)](https://www.codefactor.io/repository/github/kibotrel/bmp-parser)

This project is made to parse and load BMP [(Windows Bitmap)](https://en.wikipedia.org/wiki/BMP_file_format) files using this small library.

## Install

This should be fully portable (tested on **macOS Sierra 10.12.6**, **macOS Mojave 10.14.6**, **Debian Stretch 9.8** and **Ubuntu Bionic Beaver 18.04.4**). In order to use this BMP loader in another project, **libft.a**, [another library of mine](https://github.com/kibotrel/42-Libft) is required. Here is the install process :

```shell
$> git clone https://github.com/kibotrel/42-Libft libft
$> git clone https://github.com/kibotrel/BMP-Parser libbmp
$> make -C libft && make -C libbmp
```

You will get a static library called **libbmp.a** at the root of **libbmp** folder. In order to use it afterwards you may have to include it to the compilation when you call any function of the library in another project.

```shell
$> gcc -I./libft/incs -I./libmp/incs/ -L./libft/ -lft -L./libbmp/ -lbmp [...]
```

This process can be automated using a **Makefile** in the parent folder of these two libraries as folowing :

```Makefile

[...]

# All the directories needed to know where files should be.

LFT_DIR  = libft/
INCS_DIR = ./libft/incs/ ./libbmp/incs/ [...]
LBMP_DIR = libbmp/

# The two different libraries.

LFT     = ./libft/libft.a
LBMP   = ./libbmp/libbmp.a


# Setup compilation arguments.

CC       = gcc
LIBS     = -L$(LFT_DIR) -lft -L$(LBMP_DIR) -lbmp [...]
CFLAGS   = $(INCLUDES) -Wall -Wextra -Werror [...]
INCLUDES = $(foreach include, $(INCS_DIR), -I$(include))

# Compile the two libraries and then compile the main project where bmp_to_array() is used.

all: $(LFT) $(LBMP)
	$(CC) $(CFLAGS) $(LIBS) [...]

# Dependencies of rule all, compile each library.

$(LFT):
	make -C $(LFT_DIR) -j

$(LBMP):
	make -C $(LBMP_DIR) -j

[...]
```

The given example isn't complete, '[...]' represent the parts you need to fill with your sources files / extra flags or libraries in order to compile your main project correctly upon `make`.

## Usage
### Prototype

The only function that should be used from this library is :

```C
#include "bmp.h"

int     bmp_to_array(char *path, t_bmp *image);
```

This function returns `0` if the process ended correctly, a particular error-code (documented bellow) is returned. Said header files `bmp.h` and `./incs/`. Type `t_bmp` is defined as follow :
```C
typedef struct  s_bmp
{
    int32_t     width;
    int32_t     height;
    uint32_t    *pixels;
}               t_bmp;
```
### Breakdown

Quick explanation on each parameter and how they are supposed to be used...

Parameter | Description | Possible value
:---: | :---: | :---:
`path` | file's path that the function will parse | Only paths followed by ".bmp" could be a correct input depending on the informations stored in its [Header Chunk](https://en.wikipedia.org/wiki/BMP_file_format#File_structure) handled on the current version of the parser.
`image` | Where informations related to the given BMP would be stored at the end process | Any pointer is a valid value, however be careful, the given structure will be passed through a [bzero()](http://man7.org/linux/man-pages/man3/bzero.3.html) at the beginning of the parsing process no matter what happens after, this pointer will be updated and could be used afterwards in the process ended correctly otherwise it would be a **NULL** pointer.

### Error management
Each following error is handled by the program leading to a complete memory free :

* Failed to open the given file (*ERROR-CODE 1*)
* Failed memory allocation (*ERROR-CODE 2*)
* Failed to read the given file (*ERROR-CODE 3*)
* File size greater than 16MiB (*ERROR-CODE 4*)
* Failed to close the given file (*ERROR-CODE 5*)
* Wrong file signature (*ERROR-CODE 6*)
* Failed to reposition reading offset (*ERROR-CODE 7*)
* [DIB](https://en.wikipedia.org/wiki/BMP_file_format#DIB_header_(bitmap_information_header)) not supported by the parser (*ERROR-CODE 8*)
* Bits per pixel not supported (*ERROR-CODE 9*)
* Compression method not supported (*ERROR-CODE 10*)
* Corrupted header or DIB encountered (*ERROR-CODE 11*)
* Wrong image data offset (*ERROR-CODE 12*)
* Incorrect resolution found (*ERROR-CODE 13*)
* Incorrect scanline size in memory (*ERROR-CODE 14*)

Whenever one of these error occurs, the correct error message is displayed on the standard output and the parser returns an error code that you can retrieve.

### Example

Here is a valid implementation of `bmp_to_array()` :
```C
#include "bmp.h"

{
    t_bmp   image;

    [...]
    if (bmp_to_array("file.bmp", &image))
    {
        // Do stuff when an error is triggered.
    }
    else
    {
        // Do stuff when the file is correctly parsed.
    }
    [...]
}
```
