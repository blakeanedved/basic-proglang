# basic-proglang
A basic interpreter for a simple programming language.

Example
-------
Below is the format for a BPL program

![alt text](https://i.imgur.com/jzHmMfu.png)

The data section is to declare variables, and the input section, as it is named, is for input.
The program section is where it gets complex, each line in the program section is a command comprising of 4 parts split up like this: `+0|000|000|000` (addressed as `op|adr1|adr2|adr3` from now on) with the first group being the identifier for the command, with 20 different values, and the other 3 values being pointers to a memory address. Everthing in BPL is zero-based, and any errors generated, thown, and then the program is stopped.

The 20 instructions are as follows:

+0
-------
##### Arguments
| adr1   | adr2   | adr3   |
| ------ | ------ | ------ |
| unused | unused | unused |

exits the program

+1
-------
##### Arguments
| adr1   | adr2   | adr3 |
| ------ | ------ | ---- |
| unused | unused | adr  |

Jumps to `adr` in the program section

+2
-------
##### Arguments
| adr1 | adr2 | adr3             |
| --------- | --------- | --------------------- |
| num1 | num2 | result |

Adds together `num1` and `num2` and stores the answer in `result`

+3
-------
##### Arguments
| adr1 | adr2 | adr3 |
| --- | --- | --- |
| num1 | num2 | result |

Subtracts `num2` from `num1` and stores the answer in `result`

+4
-------
##### Arguments
| adr1 | adr2 | adr3 |
| --- | --- | --- |
| num1 | num2 | result |

Multiplies `num1` by `num2` and stores the answer in `result`

+5
-------
##### Arguments
| adr1 | adr2 | adr3 |
| --- | --- | --- |
| num1 | num2 | result |

Divides `num1` by `num2` and stores the answer in `result`

+6
-------
##### Arguments
| adr1 | adr2 | adr3 |
| --- | --- | --- |
| num1 | num2 | result |

Performs `num1` (mod `num2`) and stores the answer in `result`

+7
-------
##### Arguments
| adr1   | adr2 | adr3 |
| ------ | ---- | ---- |
| unused | src  | dest |

Stores the data value from `src` into `dest`

+8
-------
##### Arguments
| adr1   | adr2   | adr3 |
| ------ | ------ | ---- |
| unused | unused | dest |

Takes the next input value and stores it in `dest`

+9
-------
##### Arguments
| adr1   | adr2   | adr3 |
| ------ | ------ | ---- |
| unused | unused | num  |

Prints `num`

-0
-------
##### Arguments
| adr1 | adr2 | adr3 |
| --------- | --------- | --------- |
| num1 | num2 | adr       |

Jumps to `adr` if `num1` is equal to `num2`

-1
-------
##### Arguments
| adr1 | adr2 | adr3 |
| --- | --- | --- |
| num1 | num2 | adr |

Jumps to `adr` if `num1` is less than `num2`

-2
-------
##### Arguments
| adr1 | adr2 | adr3 |
| --- | --- | --- |
| num1 | num2 | adr |

Jumps to `adr` if `num1` is greater than `num2`

-3
-------
##### Arguments
| adr1 | adr2 | adr3 |
| --- | --- | --- |
| num1 | num2 | adr |

Jumps to `adr` if `num1` is less than or equal to `num2`

-4
-------
##### Arguments
| adr1 | adr2 | adr3 |
| --- | --- | --- |
| num1 | num2 | adr |

Jumps to `adr` if `num1` is greater than or equal to `num2`

-5
-------
##### Arguments
| adr1 | adr2 | adr3 |
| --- | --- | --- |
| num1 | num2 | adr |

Jumps to `adr` if `num1` is not equal to `num2`

-6
-------
##### Arguments
| adr1 | adr2 | adr3 |
| --- | --- | --- |
| num1 | num2 | result |

Raises `num1` to the `num2` power and stores the answer in `result`

-7
-------
##### Arguments
| adr1     | adr2 | adr3 |
| --------- | ----- | ----- |
| unused | adr   | dest |

Stores the memory address of `adr` in `dest`

-8
-------
##### Arguments
| adr1 | adr2 | adr3 |
| --- | --- | --- |
| unused | adr | dest |

Dereferences the pointer at the value of `adr` and stores it in `dest`

-9
-------
##### Arguments
| adr1   | adr2 | adr3   |
| ------ | ---- | ------ |
| unused | x    | result |

Generates a random number and performs random (mod `x`) and stores the answer in `result`
