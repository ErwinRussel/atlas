
#include  "atl_header.h"
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <signal.h>
// #include  <criu/criu.h>
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
    printf("Detaching memory\n");
    shmdt((void *) ShmPTR);

    // call criu dump for checkpoint
    // criu_dump();

    // We restore after the previous call - reattaching memories
    printf("Reattaching memory\n");
    ShmPTR = (struct MsgBlock *) shmat(ShmID, NULL, 0);
}}

// constructor
void init(){{
//     Setup sigusr criu_signal_handler()
    signal(SIGUSR1, criu_signal_handler);

    // Setup criu stuff
    int fd = open("/home/erwinrussel/CLionProjects/atlas/checkpoints", O_DIRECTORY);
    // criu_init_opts();
    // criu_set_images_dir_fd(fd); /* must be set for dump/restore */
    // criu_set_shell_job(True);
    // criu_set_leave_running(False);
    // criu_set_log_level(4);
    // criu_set_log_file("criu.log");

    // Bind to the shared memory file
    ShmKEY = ftok(".", 'x');

    // Get SysV ID for block to use with shmat etc.
    ShmID = shmget(ShmKEY, sizeof(struct MsgBlock),0666);
    if (ShmID < 0) {{
        printf("*** shmget error (server) ***\n");
        exit(1);
    }}

    // Attach to memory
    ShmPTR = (struct MsgBlock *) shmat(ShmID, NULL, 0);
}}

// -- XCreateColormap
Colormap xcreatecolormap_uh(args_XCreateColormap argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XCreateColormap);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XCREATECOLORMAP;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

    // ------ Waiting for Server -----

    // Wait for response
    while (ShmPTR->status != RESPONSE)
        ;

    // assert if the message is a function return
    if(ShmPTR->message_type != FUNC_RETURN){
        printf("Message type is not a function return\n");
    }

    // assert if the datatype is correct
    if(ShmPTR->data_type != COLORMAP){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(Colormap);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    Colormap result;
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}
