# -- MARK: header strings
h1 = '''#ifndef ATLAS_STUB_HEADER_H
#define ATLAS_STUB_HEADER_H

#endif //ATLAS_STUB_HEADER_H

#include <X11/Xlib.h>

// Dynamic mem buffer, buffer size in ints
#define SHMEM_BUFF 1024

// Status flags -> should be enum?
#define  REQUEST       1
#define  RESPONSE      2
#define  LISTEN        0

typedef enum {
    FUNC_CALL,
    FUNC_RETURN
} message_types;
'''
enum = '''
typedef enum {{
    {data_types}
}} data_types;
'''
msgblock = '''
// Create messageblock after declaration of data_types
struct MsgBlock {
    int  status;
    message_types message_type;
    data_types data_type;
    int payload_size;
    char buffer[SHMEM_BUFF];
};

// Function arg structs

'''
struct_block = '''
// -- {name}
struct args_{name}{{
    {args}
}}

typedef struct args_{name} args_{name};

'''


# -- MARK: Header file
# todo: add the includes header files
def gen_shared_header(functions):
    with open("output/atl_header.h", "w") as f:
        # add h1
        f.write(h1)

        # Create enum
        data_types_l = []
        for function in functions:
            data_types_l.append(function['name'].upper())
            ret_type = function['ret_type'].upper()
            # Make sure we are not adding data types double
            if ret_type not in data_types_l:
                data_types_l.append(ret_type)
        data_types = ",\n\t".join(data_types_l)
        f.write(enum.format(data_types=data_types))

        # add msgblock
        f.write(msgblock)

        # Add all the function structs
        for function in functions:
            args_str = ",\n\t".join(function['args'])
            f.write(struct_block.format(name=function['name'], args=args_str))


