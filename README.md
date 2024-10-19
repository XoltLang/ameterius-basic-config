# Ameterius Basic Config

This repository contains a simple configuration file parser implemented in both C and Python. The parser supports a file format where each line contains a key-value pair separated by a colon `:`.

>[!WARNING]
>Intended for [LazyXolt](https://github.com/XoltLang/LazyXolt), to achieve independence ([Post](https://t.me/xoltlanguagedevblog/12))\
>So it doesn't have much use, but if needed, feel free to use it

## Configuration File Format

Example configuration file (`example.acfg`):

```plaintext
server:ip:192.168.1.1
server:port:8080
database:host:localhost
database:user:admin
database:password:secret
```

Each line contains three parts:

1. Block name (`block_name`).
2. Key (`key`).
3. Value (`value`).

>[!TIP]
>If you don't want to mention that you're using it, you don't have to\
>Mentioning our parser is not mandatory, so good luck with your development!

## Using the Parser

### C Version

For detailed instructions on how to use the C version of the parser, please refer to the [C/README.md](C/README.md) file.

### Python Version

For detailed instructions on how to use the Python version of the parser, please refer to the [Python/README.md](Python/README.md) file.

## Limitations and Constraints

### 1. Fixed Size Limits

- **MAX_LINE_LENGTH**: The maximum length of a line in the configuration file is limited to 256 characters.
- **MAX_BLOCKS**: The maximum number of blocks that can be stored in the configuration is limited to 10.
- **MAX_KEYS**: The maximum number of keys per block is limited to 10.

### 2. No Error Handling for Exceeding Limits

The parser does not handle cases where the number of blocks or keys exceeds the predefined limits. This could lead to undefined behavior if the configuration file is too large.

### 3. No Support for Nested Blocks

The parser does not support nested blocks or hierarchical configurations. Each block is treated as a flat structure with key-value pairs.

### 4. No Support for Complex Data Types

The parser only supports string values. It does not support complex data types such as arrays, lists, or nested structures.

### 5. No Support for Escaping Characters

The parser does not support escaping characters in keys or values. Special characters like colons (`:`) within keys or values will cause parsing errors.

### 6. No Support for Comments within Lines

Comments are only supported at the beginning of a line. Comments within lines are not recognized and will cause parsing errors.

