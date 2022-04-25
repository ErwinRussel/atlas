h1 = '''
#include  "atl_header.h"
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <signal.h>
#include  <criu/criu.h>
#include  <string.h>
#include  <fcntl.h>

// Global
key_t          ShmKEY;
int            ShmID;
struct MsgBlock  *ShmPTR;

// Setup constructor
__attribute__((constructor)) void init (void);

// Criu handler
void criu_signal_handler(){{
    printf("Detaching memory\\n");
    shmdt((void *) ShmPTR);

    // call criu dump for checkpoint
    criu_dump();

    // We restore after the previous call - reattaching memories
    printf("Reattaching memory\\n");
    ShmPTR = (struct MsgBlock *) shmat(ShmID, NULL, 0);
}}

// constructor
void init(){{
//     Setup sigusr criu_signal_handler()
    signal(SIGUSR1, criu_signal_handler);

    // Setup criu stuff
    int fd = open("/home/erwinrussel/CLionProjects/atlas/checkpoints", O_DIRECTORY);
    criu_init_opts();
    criu_set_images_dir_fd(fd); /* must be set for dump/restore */
    criu_set_shell_job(True);
    criu_set_leave_running(False);
    criu_set_log_level(4);
    criu_set_log_file("criu.log");

    // Bind to the shared memory file
    ShmKEY = ftok(".", 'x');

    // Get SysV ID for block to use with shmat etc.
    ShmID = shmget(ShmKEY, sizeof(struct MsgBlock),0666);
    if (ShmID < 0) {{
        printf("*** shmget error (server) ***\\n");
        exit(1);
    }}

    // Attach to memory
    ShmPTR = (struct MsgBlock *) shmat(ShmID, NULL, 0);
}}
'''
func_uh = '''
// -- {name}
{ret_type} {name_lower}_uh(args_{name} argp)
{{
    // Memcopy in Buffer
    int arg_size = sizeof(args_{name})
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = {name_upper};
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

    // ------ Waiting for Server -----

    // Wait for response
    while (ShmPTR->status != RESPONSE)
        ;

    // assert if the message is a function return
    if(ShmPTR->message_type != FUNC_RETURN){{
        printf("Message type is not a function return\\n");
    }}

    // assert if the datatype is correct
    if(ShmPTR->data_type != {ret_type_upper}){{
        printf("Payload data type incorrect\\n");
    }}
    
    // assert if correct payload size
    int ret_size = sizeof({ret_type});

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){{
        printf("Incorrect payload size\\n");
    }}

    // memcopy into result
    {ret_type} result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}}
'''
func_uh_ni = '''
// -- {name}
{ret_type} {name_lower}_uh()
{{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = {name_upper};
    ShmPTR->payload_size = 0;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

    // ------ Waiting for Server -----

    // Wait for response
    while (ShmPTR->status != RESPONSE)
        ;

    // assert if the message is a function return
    if(ShmPTR->message_type != FUNC_RETURN){{
        printf("Message type is not a function return\\n");
    }}

    // assert if the datatype is correct
    if(ShmPTR->data_type != {ret_type_upper}){{
        printf("Payload data type incorrect\\n");
    }}

    // assert if correct payload size
    int ret_size = sizeof({ret_type});

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){{
        printf("Incorrect payload size\\n");
    }}

    // memcopy into result
    {ret_type} result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}}
'''
func_uh_void = '''
// -- {name}
void {name_lower}_uh(args_{name} argp)
{{
    // Memcopy in Buffer
    int arg_size = sizeof(args_{name})
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = {name_upper};
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

    // ------ Waiting for Server -----

    // Wait for response
    while (ShmPTR->status != RESPONSE)
        ;

    // assert if the message is a function return
    if(ShmPTR->message_type != FUNC_RETURN){{
        printf("Message type is not a function return\\n");
    }}

    // assert if the datatype is correct
    if(ShmPTR->data_type != {ret_type_upper}){{
        printf("Payload data type incorrect\\n");
    }}
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){{
        printf("Incorrect payload size\\n");
    }}

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}}
'''
func_uh_ni_void = '''
// -- {name}
{ret_type} {name_lower}_uh()
{{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = {name_upper};
    ShmPTR->payload_size = 0;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

    // ------ Waiting for Server -----

        // Wait for response
    while (ShmPTR->status != RESPONSE)
        ;

    // assert if the message is a function return
    if(ShmPTR->message_type != FUNC_RETURN){{
        printf("Message type is not a function return\\n");
    }}

    // assert if the datatype is correct
    if(ShmPTR->data_type != {ret_type_upper}){{
        printf("Payload data type incorrect\\n");
    }}
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){{
        printf("Incorrect payload size\\n");
    }}

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}}
'''

def gen_upper_half(functions):
    with open('output/atl_uh.c', 'w') as f:
        # write header
        f.write(h1)

        # write functions
        for function in functions:
            name = function['name']
            name_upper = name.upper()
            name_lower = name.lower()
            ret_type = function['ret_type']
            ret_type_upper = ret_type.upper()
            args = function['args']
            # If void function, no return type
            if ret_type == "void":
                # Make sure we use no input func if there are no inputs
                if len(args) == 1 and args[0] == '':
                    f.write(
                        func_uh_ni_void.format(name=name, name_upper=name_upper, name_lower=name_lower, ret_type=ret_type,
                                          ret_type_upper=ret_type_upper))
                    continue

                f.write(func_uh_void.format(name=name, name_upper=name_upper, name_lower=name_lower, ret_type=ret_type,
                                       ret_type_upper=ret_type_upper))
            else:
                # Todo: what to do about this
                if len(ret_type) > 0:
                    # Replace asterisk with 'P'
                    if ret_type_upper[-1] == "*":
                        ret_type_upper = ret_type_upper[:-1] + 'P'

                # Make sure we use no input func if there are no inputs
                if len(args) == 1 and args[0] == '':
                    f.write(func_uh_ni.format(name=name, name_upper=name_upper, name_lower=name_lower, ret_type=ret_type,
                                           ret_type_upper=ret_type_upper))
                    continue

                f.write(func_uh.format(name=name, name_upper=name_upper, name_lower=name_lower, ret_type=ret_type, ret_type_upper=ret_type_upper))
