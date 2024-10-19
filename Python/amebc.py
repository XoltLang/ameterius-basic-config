# Copyright: Xolt Language Community
# Author: Ametero
# Version: 2.3 RLS

def parse_config(filename):
    config = {}
    with open(filename, 'r') as file:
        for line in file:
            line = line.strip()
            if not line or line.startswith('#'):
                continue
            block_name, key, value = line.split(':', 2)
            if block_name not in config:
                config[block_name] = {}
            config[block_name][key] = value
    return config

def get_value(config, block_name, key):
    if block_name in config and key in config[block_name]:
        return config[block_name][key]
    return None
