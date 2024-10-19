// test.c
#include "headers/amebc.h"

int main() {
    Config config;
    memset(&config, 0, sizeof(config));

    parse_config("example_config.acfg", &config);

    const char *server_ip = get_value(&config, "server", "ip");
    const char *server_port = get_value(&config, "server", "port");
    const char *db_host = get_value(&config, "database", "host");
    const char *db_user = get_value(&config, "database", "user");
    const char *db_password = get_value(&config, "database", "password");

    if (server_ip) printf("Server IP: %s\n", server_ip);
    if (server_port) printf("Server Port: %s\n", server_port);
    if (db_host) printf("Database Host: %s\n", db_host);
    if (db_user) printf("Database User: %s\n", db_user);
    if (db_password) printf("Database Password: %s\n", db_password);

    return 0;
}
