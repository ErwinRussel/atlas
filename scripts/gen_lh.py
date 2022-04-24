# -- MARK: lower half strings
h1 = '''
#include  "atl_header.h"
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

// Global pointers to use from init
key_t           ShmKEY;
int             ShmID;
struct MsgBlock *ShmPTR;

// Constructor
void init(){
    // Bind to the shared memory file
    ShmKEY = ftok(".", 'x');

    // Get SysV ID for block to use with shmat etc.
    ShmID = shmget(ShmKEY, sizeof(struct MsgBlock), IPC_CREAT | 0666);
    if (ShmID < 0) {
        printf("*** shmget error (server) ***\\n");
        exit(1);
    }

    // Attach to pointer
    ShmPTR = (struct MsgBlock *) shmat(ShmID, NULL, 0);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;
}
'''
func_lh = '''
// -- {name}
{ret_type} *{name_lower}_lh(args_{name} *argp)
{{
    // Get function specific args
    {argp_set}

    // Call actual function
    {ret_type} result = {name}({arg_vars});

    // Memcopy in Buffer
    int ret_size = sizeof({ret_type});
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = {ret_type_upper};
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}}

'''
listener = '''
void service_listener() {{
    // Server loop
    while(1){{
        // Wait on request
        printf("Listening...\\n");
        while (ShmPTR->status != REQUEST)
            ;

        // assert if FUNC_CALL
        if(ShmPTR->message_type != FUNC_CALL){{
            printf("No function call\\n");
            ShmPTR->status = LISTEN;
            continue;
        }}

        // read function type header
        data_types func_type = ShmPTR->data_type;
        printf("REQUEST: Function type: %d\\n", func_type);

        // Call function from desired function type
        switch (func_type)
        {{
            {cases}

            default:
                // Change this print error so we know what happens
                printf("Message data type unrecognized\\n\\n");
                ShmPTR->status = LISTEN;
                break;
        }}
    }}
}}
'''
case = '''
            case {name_upper}: ;
                args_{name} argp_{name_lower};

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_{name})){{
                    printf("Wrong payload size\\n\\n");
                    ShmPTR->status = LISTEN;
                    break;
                }}

                // Memcopy from Buffer
                memcpy(&argp_{name_lower}, ShmPTR->buffer, sizeof(args_{name}));

                // Execute function call
                {name_lower}_lh(&argp_{name_lower});

                // Print
                printf("RESPONSE: Data type: %d\\n\\n", ShmPTR->data_type);
                break;
'''
main = '''
int main(int  argc, char *argv[]){
    init();
    service_listener();
    return 0;
}
'''

def get_argp_set(function_args):
    argp_set = []
    for arg in function_args:
        var_name = arg.split()[-1]
        if var_name[0] == '*':
            var_name = var_name[1:]
        set_line = "{arg} = argp->{var_name};".format(arg=arg, var_name=var_name)
        argp_set.append(set_line)

    return ";\n\t".join(argp_set)

def get_arg_vars(function_args):
    arg_vars = []
    for arg in function_args:
        var_name = arg.split()[-1]
        if var_name[0] == '*':
            var_name = var_name[1:]
        arg_vars.append(var_name)
    return ", ".join(arg_vars)


def gen_lower_half(functions):
    with open("output/atl_lh.c", 'w') as f:
        # add h1
        f.write(h1)

        # add func_lh and create cases for listener
        cases = []
        for function in functions:
            name = function['name']
            name_lower = name.lower()
            ret_type = function['ret_type']
            ret_type_upper = ret_type.upper()
            # If we have a pointer type, replace asterisk with 'P'
            if ret_type_upper[-1] == "*":
                ret_type_upper = ret_type_upper[:-1] + 'P'
            argp_set = get_argp_set(function['args'])
            arg_vars = get_arg_vars(function['args'])
            f.write(func_lh.format(name=name, name_lower=name_lower,
                                   ret_type=ret_type, ret_type_upper=ret_type_upper,
                                   arg_vars=arg_vars, argp_set=argp_set))
            # create case
            name_upper = name.upper()
            cases.append(case.format(name=name, name_lower=name_lower, name_upper=name_upper))

        # add listener
        f.write(listener.format(cases="".join(cases)))

        # add main_lh
        f.write(main)