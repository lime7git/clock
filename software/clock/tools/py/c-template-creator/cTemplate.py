import sys
from datetime import datetime

author = 'lime7git'
current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

def create_source_file(name):

    content = f'''/*
* {name}.c
*
*  Created on: {current_time}
*      Author: {author}
*/

#include "{name}.h"


'''
    file_name = f"{name}.c"
    with open(file_name, 'w') as file:
        file.write(content)
    print(f"File '{file_name}' created successfully.")

def create_header_file(name):
    
    content = f'''/*
* {name}.h
*
*  Created on: {current_time}
*      Author: {author}
*/

#ifndef {name.upper()}_H_
#define {name.upper()}_H_



#endif /* {name.upper()}_H_ */'''
    
    file_name = f"{name}.h"
    with open(file_name, 'w') as file:
        file.write(content)
    print(f"File '{file_name}' created successfully.")

def main():
    if len(sys.argv) != 3 or sys.argv[1] not in ['source', 'header', 'pair']:
        print("Usage: cTemplate <source/header/pair> <name>")
        sys.exit(1)

    file_type, name = sys.argv[1], sys.argv[2]

    if file_type == 'source':
        create_source_file(name)
    elif file_type == 'header':
        create_header_file(name)
    elif file_type == 'pair':
        create_source_file(name)
        create_header_file(name)
    else:
        print("Invalid file type. Use 'source', 'header' or 'pair'.")

if __name__ == "__main__":
    main()
