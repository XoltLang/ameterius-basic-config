from amebc import parse_config, get_value

def main():
    config = parse_config('custom_config.acfg')

    server_ip = get_value(config, 'server', 'ip')
    server_port = get_value(config, 'server', 'port')
    db_host = get_value(config, 'database', 'host')
    db_user = get_value(config, 'database', 'user')
    db_password = get_value(config, 'database', 'password')

    if server_ip: print(f"Server IP: {server_ip}")
    if server_port: print(f"Server Port: {server_port}")
    if db_host: print(f"Database Host: {db_host}")
    if db_user: print(f"Database User: {db_user}")
    if db_password: print(f"Database Password: {db_password}")

if __name__ == "__main__":
    main()
