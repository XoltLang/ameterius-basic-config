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

### 1. Include the Header File

To use the parser in your project, include the header file `amebc.h`:

```c
#include "headers/amebc.h"
```

### 2. Initialize the Configuration Structure

Create a `Config` structure and initialize it with zeros:

```c
Config config;
memset(&config, 0, sizeof(config));
```

### 3. Parse the Configuration File

Use the `parse_config` function to read data from the configuration file:

```c
parse_config("custom_config.acfg", &config);
```

### 4. Retrieve Configuration Values

Use the `get_value` function to retrieve values from the configuration file:

```c
const char *server_ip = get_value(&config, "server", "ip");
const char *server_port = get_value(&config, "server", "port");
const char *db_host = get_value(&config, "database", "host");
const char *db_user = get_value(&config, "database", "user");
const char *db_password = get_value(&config, "database", "password");
```

### 5. Print Configuration Values

Check if the value is not `NULL` and print it to the screen:

```c
if (server_ip) printf("Server IP: %s\n", server_ip);
if (server_port) printf("Server Port: %s\n", server_port);
if (db_host) printf("Database Host: %s\n", db_host);
if (db_user) printf("Database User: %s\n", db_user);
if (db_password) printf("Database Password: %s\n", db_password);
```

## Compilation and Execution

Save the code in the corresponding files and compile it using GCC:

```bash
gcc -o example example.c headers/amebc.c
```

Run the program:

```bash
./example
```

## Example Usage

An example of using the configuration parser can be found in the `example.c` file. This file demonstrates how to read a configuration file and print the values to the screen.
