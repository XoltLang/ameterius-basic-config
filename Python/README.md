# Ameterius Basic Config Parser (Python Version)

This project is a simple configuration file parser written in Python. The parser supports a file format where each line contains a key-value pair separated by a colon `:`.

## Configuration File Format

Example configuration file (`custom_config.acfg`):

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

## Using the Parser

### 1. Import the Parser Module

To use the parser in your project, import the `parser` module:

```python
from amebc import parse_config, get_value
```

### 2. Parse the Configuration File

Use the `parse_config` function to read data from the configuration file:

```python
config = parse_config('custom_config.acfg')
```

### 3. Retrieve Configuration Values

Use the `get_value` function to retrieve values from the configuration file:

```python
server_ip = get_value(config, 'server', 'ip')
server_port = get_value(config, 'server', 'port')
db_host = get_value(config, 'database', 'host')
db_user = get_value(config, 'database', 'user')
db_password = get_value(config, 'database', 'password')
```

### 4. Print Configuration Values

Check if the value is not `None` and print it to the screen:

```python
if server_ip: print(f"Server IP: {server_ip}")
if server_port: print(f"Server Port: {server_port}")
if db_host: print(f"Database Host: {db_host}")
if db_user: print(f"Database User: {db_user}")
if db_password: print(f"Database Password: {db_password}")
```

## Example Usage

An example of using the configuration parser can be found in the `example.py` file. This file demonstrates how to read a configuration file and print the values to the screen.

