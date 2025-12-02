# Simple Assembler

Assembler for the **myCPU** processor, a simple RISC CPU based on MIPS. The output is a binary file representing the memory map that will be used in the CPU simulator.

## Specifications

The instructions supported by myCPU are divided into three types: **R**, **I**, and **J**. By default, the Simple Assembler accepts the following instructions:

| Instruction | Type | Opcode | Funct  |
| ----------- | ---- | ------ | ------ |
| add         | R    |        | 100000 |
| addi        | I    | 100000 |        |
| sub         | R    |        | 100000 |
| and         | R    |        | 100100 |
| xor         | R    |        | 100110 |
| or          | R    |        | 100101 |
| beq         | I    | 000100 |        |
| bne         | I    | 000101 |        |
| j           | J    | 100000 |        |
| jal         | J    | 000011 |        |
| slt         | R    |        | 101010 |
| lw          | I    | 100011 |        |
| sw          | I    | 101011 |        |
| jr          | R    |        | 001000 |

The set of accepted instructions is flexible — instructions can be added or removed as needed, following the pattern below:

**The instructions are stored in the file `funcoes.txt`, organized as follows:**

> 1 `[R-instruction]:[funct]`,
> 2 `[I-instruction]:[opcode]`,
> 3 `[J-instruction]:[opcode]`,

Where lines **1**, **2**, and **3** refer to the respective sections of the file.

---

## Running the Application

```bash
# Cloning the repository
$ git clone https://github.com/Daniel-Alencar/simple-assembler
```

```bash
# Navigate to the project folder
$ cd simple-assembler
```

```bash
# Compiling the program
$ gcc assembler.c -o assembler
```

This will generate `assembler.exe` (Windows) or `assembler.out` (Linux).

```bash
# Running the assembler
# Linux
$ ./assembler [input_file.asm] [output_filename] (optional)

# Windows
$ assembler [input_file.asm] [output_filename] (optional)
```

This will generate `output_filename.dat` containing the binary sequence of the instructions (using little-endian format) extracted from the provided input file.
