# XORCrypt

XORCrypt is a tool to encrypt and decrypt files using the XOR Cipher.

## Usage

XORCrypt [-ih] InputFileName
XORCrypt [-ih] InputFileName [-k] KeyFileName

Options:
-i   Encrypt or decrypt a text file.

-k   Specify the file name for the key file, If this option isn't used the default file name "key.dat" will be used.

-h   Display this help.

Example:
XORCrypt -i filename -k keyfile //Encrypt or decrypt the text file "filename" using the key in the file "keyfile".

## Building

### Linux

To compile, clone the XORCrypt repo:

~~~
git clone
~~~

Then cd to the XORCrypt directory and run make:

~~~
cd XORCrypt
make
~~~

If you need to clean the XORCrypt directory run:

~~~
make clean
~~~
