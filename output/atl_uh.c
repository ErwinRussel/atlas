
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
    printf("Detaching memory\n");
    shmdt((void *) ShmPTR);

    // call criu dump for checkpoint
    criu_dump();

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
        printf("*** shmget error (server) ***\n");
        exit(1);
    }}

    // Attach to memory
    ShmPTR = (struct MsgBlock *) shmat(ShmID, NULL, 0);
}}

// -- XOpenDisplay
Display* xopendisplay_uh(argp_XOpenDisplay argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_XOpenDisplay)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XOPENDISPLAY;
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
    if(ShmPTR->data_type != DISPLAYP){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(Display*);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    Display* result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- XMapWindow
int xmapwindow_uh(argp_XMapWindow argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_XMapWindow)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XMAPWINDOW;
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
    if(ShmPTR->data_type != INT){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(int);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    int result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glClearIndex
void glclearindex_uh(argp_glClearIndex argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glClearIndex)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCLEARINDEX;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glClearColor
void glclearcolor_uh(argp_glClearColor argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glClearColor)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCLEARCOLOR;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glClear
void glclear_uh(argp_glClear argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glClear)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCLEAR;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glIndexMask
void glindexmask_uh(argp_glIndexMask argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glIndexMask)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLINDEXMASK;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColorMask
void glcolormask_uh(argp_glColorMask argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColorMask)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLORMASK;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glAlphaFunc
void glalphafunc_uh(argp_glAlphaFunc argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glAlphaFunc)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLALPHAFUNC;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glBlendFunc
void glblendfunc_uh(argp_glBlendFunc argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glBlendFunc)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLBLENDFUNC;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLogicOp
void gllogicop_uh(argp_glLogicOp argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glLogicOp)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLOGICOP;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCullFace
void glcullface_uh(argp_glCullFace argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCullFace)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCULLFACE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glFrontFace
void glfrontface_uh(argp_glFrontFace argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glFrontFace)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLFRONTFACE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPointSize
void glpointsize_uh(argp_glPointSize argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPointSize)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPOINTSIZE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLineWidth
void gllinewidth_uh(argp_glLineWidth argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glLineWidth)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLINEWIDTH;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLineStipple
void gllinestipple_uh(argp_glLineStipple argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glLineStipple)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLINESTIPPLE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPolygonMode
void glpolygonmode_uh(argp_glPolygonMode argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPolygonMode)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPOLYGONMODE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPolygonOffset
void glpolygonoffset_uh(argp_glPolygonOffset argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPolygonOffset)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPOLYGONOFFSET;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPolygonStipple
void glpolygonstipple_uh(argp_glPolygonStipple argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPolygonStipple)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPOLYGONSTIPPLE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetPolygonStipple
void glgetpolygonstipple_uh(argp_glGetPolygonStipple argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetPolygonStipple)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETPOLYGONSTIPPLE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEdgeFlag
void gledgeflag_uh(argp_glEdgeFlag argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEdgeFlag)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLEDGEFLAG;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEdgeFlagv
void gledgeflagv_uh(argp_glEdgeFlagv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEdgeFlagv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLEDGEFLAGV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glScissor
void glscissor_uh(argp_glScissor argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glScissor)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLSCISSOR;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glClipPlane
void glclipplane_uh(argp_glClipPlane argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glClipPlane)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCLIPPLANE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetClipPlane
void glgetclipplane_uh(argp_glGetClipPlane argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetClipPlane)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETCLIPPLANE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glDrawBuffer
void gldrawbuffer_uh(argp_glDrawBuffer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glDrawBuffer)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLDRAWBUFFER;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glReadBuffer
void glreadbuffer_uh(argp_glReadBuffer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glReadBuffer)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLREADBUFFER;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEnable
void glenable_uh(argp_glEnable argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEnable)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLENABLE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glDisable
void gldisable_uh(argp_glDisable argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glDisable)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLDISABLE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glIsEnabled
GLboolean glisenabled_uh(argp_glIsEnabled argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glIsEnabled)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLISENABLED;
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
    if(ShmPTR->data_type != GLBOOLEAN){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(GLboolean);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    GLboolean result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glEnableClientState
void glenableclientstate_uh(argp_glEnableClientState argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEnableClientState)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLENABLECLIENTSTATE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glDisableClientState
void gldisableclientstate_uh(argp_glDisableClientState argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glDisableClientState)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLDISABLECLIENTSTATE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetBooleanv
void glgetbooleanv_uh(argp_glGetBooleanv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetBooleanv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETBOOLEANV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetDoublev
void glgetdoublev_uh(argp_glGetDoublev argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetDoublev)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETDOUBLEV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetFloatv
void glgetfloatv_uh(argp_glGetFloatv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetFloatv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETFLOATV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetIntegerv
void glgetintegerv_uh(argp_glGetIntegerv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetIntegerv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETINTEGERV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPushAttrib
void glpushattrib_uh(argp_glPushAttrib argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPushAttrib)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPUSHATTRIB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPopAttrib
void glpopattrib_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPOPATTRIB;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPushClientAttrib
void glpushclientattrib_uh(argp_glPushClientAttrib argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPushClientAttrib)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPUSHCLIENTATTRIB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPopClientAttrib
void glpopclientattrib_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPOPCLIENTATTRIB;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRenderMode
GLint glrendermode_uh(argp_glRenderMode argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRenderMode)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRENDERMODE;
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
    if(ShmPTR->data_type != GLINT){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(GLint);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    GLint result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glFinish
void glfinish_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLFINISH;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glFlush
void glflush_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLFLUSH;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glHint
void glhint_uh(argp_glHint argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glHint)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLHINT;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glClearDepth
void glcleardepth_uh(argp_glClearDepth argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glClearDepth)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCLEARDEPTH;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glDepthFunc
void gldepthfunc_uh(argp_glDepthFunc argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glDepthFunc)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLDEPTHFUNC;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glDepthMask
void gldepthmask_uh(argp_glDepthMask argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glDepthMask)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLDEPTHMASK;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glDepthRange
void gldepthrange_uh(argp_glDepthRange argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glDepthRange)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLDEPTHRANGE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glClearAccum
void glclearaccum_uh(argp_glClearAccum argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glClearAccum)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCLEARACCUM;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glAccum
void glaccum_uh(argp_glAccum argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glAccum)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLACCUM;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMatrixMode
void glmatrixmode_uh(argp_glMatrixMode argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMatrixMode)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMATRIXMODE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glOrtho
void glortho_uh(argp_glOrtho argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glOrtho)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLORTHO;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glFrustum
void glfrustum_uh(argp_glFrustum argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glFrustum)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLFRUSTUM;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glViewport
void glviewport_uh(argp_glViewport argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glViewport)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVIEWPORT;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPushMatrix
void glpushmatrix_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPUSHMATRIX;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPopMatrix
void glpopmatrix_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPOPMATRIX;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLoadIdentity
void glloadidentity_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLOADIDENTITY;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLoadMatrixd
void glloadmatrixd_uh(argp_glLoadMatrixd argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glLoadMatrixd)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLOADMATRIXD;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLoadMatrixf
void glloadmatrixf_uh(argp_glLoadMatrixf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glLoadMatrixf)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLOADMATRIXF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultMatrixd
void glmultmatrixd_uh(argp_glMultMatrixd argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultMatrixd)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTMATRIXD;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultMatrixf
void glmultmatrixf_uh(argp_glMultMatrixf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultMatrixf)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTMATRIXF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRotated
void glrotated_uh(argp_glRotated argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRotated)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLROTATED;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRotatef
void glrotatef_uh(argp_glRotatef argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRotatef)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLROTATEF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glScaled
void glscaled_uh(argp_glScaled argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glScaled)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLSCALED;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glScalef
void glscalef_uh(argp_glScalef argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glScalef)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLSCALEF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTranslated
void gltranslated_uh(argp_glTranslated argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTranslated)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTRANSLATED;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTranslatef
void gltranslatef_uh(argp_glTranslatef argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTranslatef)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTRANSLATEF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glIsList
GLboolean glislist_uh(argp_glIsList argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glIsList)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLISLIST;
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
    if(ShmPTR->data_type != GLBOOLEAN){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(GLboolean);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    GLboolean result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glDeleteLists
void gldeletelists_uh(argp_glDeleteLists argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glDeleteLists)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLDELETELISTS;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGenLists
GLuint glgenlists_uh(argp_glGenLists argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGenLists)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGENLISTS;
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
    if(ShmPTR->data_type != GLUINT){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(GLuint);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    GLuint result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glNewList
void glnewlist_uh(argp_glNewList argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glNewList)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLNEWLIST;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEndList
void glendlist_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLENDLIST;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCallList
void glcalllist_uh(argp_glCallList argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCallList)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCALLLIST;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCallLists
void glcalllists_uh(argp_glCallLists argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCallLists)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCALLLISTS;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glListBase
void gllistbase_uh(argp_glListBase argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glListBase)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLISTBASE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glBegin
void glbegin_uh(argp_glBegin argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glBegin)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLBEGIN;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEnd
void glend_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLEND;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex2d
void glvertex2d_uh(argp_glVertex2d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex2d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX2D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex2f
void glvertex2f_uh(argp_glVertex2f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex2f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX2F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex2i
void glvertex2i_uh(argp_glVertex2i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex2i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX2I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex2s
void glvertex2s_uh(argp_glVertex2s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex2s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX2S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex3d
void glvertex3d_uh(argp_glVertex3d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex3d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX3D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex3f
void glvertex3f_uh(argp_glVertex3f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex3f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX3F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex3i
void glvertex3i_uh(argp_glVertex3i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex3i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX3I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex3s
void glvertex3s_uh(argp_glVertex3s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex3s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX3S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex4d
void glvertex4d_uh(argp_glVertex4d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex4d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX4D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex4f
void glvertex4f_uh(argp_glVertex4f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex4f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX4F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex4i
void glvertex4i_uh(argp_glVertex4i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex4i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX4I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex4s
void glvertex4s_uh(argp_glVertex4s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex4s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX4S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex2dv
void glvertex2dv_uh(argp_glVertex2dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex2dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX2DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex2fv
void glvertex2fv_uh(argp_glVertex2fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex2fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX2FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex2iv
void glvertex2iv_uh(argp_glVertex2iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex2iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX2IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex2sv
void glvertex2sv_uh(argp_glVertex2sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex2sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX2SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex3dv
void glvertex3dv_uh(argp_glVertex3dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex3dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX3DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex3fv
void glvertex3fv_uh(argp_glVertex3fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex3fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX3FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex3iv
void glvertex3iv_uh(argp_glVertex3iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex3iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX3IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex3sv
void glvertex3sv_uh(argp_glVertex3sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex3sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX3SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex4dv
void glvertex4dv_uh(argp_glVertex4dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex4dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX4DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex4fv
void glvertex4fv_uh(argp_glVertex4fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex4fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX4FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex4iv
void glvertex4iv_uh(argp_glVertex4iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex4iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX4IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertex4sv
void glvertex4sv_uh(argp_glVertex4sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertex4sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEX4SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glNormal3b
void glnormal3b_uh(argp_glNormal3b argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glNormal3b)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLNORMAL3B;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glNormal3d
void glnormal3d_uh(argp_glNormal3d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glNormal3d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLNORMAL3D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glNormal3f
void glnormal3f_uh(argp_glNormal3f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glNormal3f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLNORMAL3F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glNormal3i
void glnormal3i_uh(argp_glNormal3i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glNormal3i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLNORMAL3I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glNormal3s
void glnormal3s_uh(argp_glNormal3s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glNormal3s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLNORMAL3S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glNormal3bv
void glnormal3bv_uh(argp_glNormal3bv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glNormal3bv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLNORMAL3BV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glNormal3dv
void glnormal3dv_uh(argp_glNormal3dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glNormal3dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLNORMAL3DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glNormal3fv
void glnormal3fv_uh(argp_glNormal3fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glNormal3fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLNORMAL3FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glNormal3iv
void glnormal3iv_uh(argp_glNormal3iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glNormal3iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLNORMAL3IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glNormal3sv
void glnormal3sv_uh(argp_glNormal3sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glNormal3sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLNORMAL3SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glIndexd
void glindexd_uh(argp_glIndexd argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glIndexd)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLINDEXD;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glIndexf
void glindexf_uh(argp_glIndexf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glIndexf)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLINDEXF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glIndexi
void glindexi_uh(argp_glIndexi argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glIndexi)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLINDEXI;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glIndexs
void glindexs_uh(argp_glIndexs argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glIndexs)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLINDEXS;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glIndexub
void glindexub_uh(argp_glIndexub argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glIndexub)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLINDEXUB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glIndexdv
void glindexdv_uh(argp_glIndexdv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glIndexdv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLINDEXDV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glIndexfv
void glindexfv_uh(argp_glIndexfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glIndexfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLINDEXFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glIndexiv
void glindexiv_uh(argp_glIndexiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glIndexiv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLINDEXIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glIndexsv
void glindexsv_uh(argp_glIndexsv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glIndexsv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLINDEXSV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glIndexubv
void glindexubv_uh(argp_glIndexubv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glIndexubv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLINDEXUBV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor3b
void glcolor3b_uh(argp_glColor3b argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor3b)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR3B;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor3d
void glcolor3d_uh(argp_glColor3d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor3d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR3D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor3f
void glcolor3f_uh(argp_glColor3f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor3f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR3F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor3i
void glcolor3i_uh(argp_glColor3i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor3i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR3I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor3s
void glcolor3s_uh(argp_glColor3s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor3s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR3S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor3ub
void glcolor3ub_uh(argp_glColor3ub argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor3ub)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR3UB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor3ui
void glcolor3ui_uh(argp_glColor3ui argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor3ui)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR3UI;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor3us
void glcolor3us_uh(argp_glColor3us argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor3us)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR3US;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor4b
void glcolor4b_uh(argp_glColor4b argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor4b)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR4B;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor4d
void glcolor4d_uh(argp_glColor4d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor4d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR4D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor4f
void glcolor4f_uh(argp_glColor4f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor4f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR4F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor4i
void glcolor4i_uh(argp_glColor4i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor4i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR4I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor4s
void glcolor4s_uh(argp_glColor4s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor4s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR4S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor4ub
void glcolor4ub_uh(argp_glColor4ub argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor4ub)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR4UB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor4ui
void glcolor4ui_uh(argp_glColor4ui argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor4ui)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR4UI;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor4us
void glcolor4us_uh(argp_glColor4us argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor4us)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR4US;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor3bv
void glcolor3bv_uh(argp_glColor3bv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor3bv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR3BV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor3dv
void glcolor3dv_uh(argp_glColor3dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor3dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR3DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor3fv
void glcolor3fv_uh(argp_glColor3fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor3fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR3FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor3iv
void glcolor3iv_uh(argp_glColor3iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor3iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR3IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor3sv
void glcolor3sv_uh(argp_glColor3sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor3sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR3SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor3ubv
void glcolor3ubv_uh(argp_glColor3ubv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor3ubv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR3UBV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor3uiv
void glcolor3uiv_uh(argp_glColor3uiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor3uiv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR3UIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor3usv
void glcolor3usv_uh(argp_glColor3usv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor3usv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR3USV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor4bv
void glcolor4bv_uh(argp_glColor4bv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor4bv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR4BV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor4dv
void glcolor4dv_uh(argp_glColor4dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor4dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR4DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor4fv
void glcolor4fv_uh(argp_glColor4fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor4fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR4FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor4iv
void glcolor4iv_uh(argp_glColor4iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor4iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR4IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor4sv
void glcolor4sv_uh(argp_glColor4sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor4sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR4SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor4ubv
void glcolor4ubv_uh(argp_glColor4ubv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor4ubv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR4UBV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor4uiv
void glcolor4uiv_uh(argp_glColor4uiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor4uiv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR4UIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColor4usv
void glcolor4usv_uh(argp_glColor4usv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColor4usv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLOR4USV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord1d
void gltexcoord1d_uh(argp_glTexCoord1d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord1d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD1D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord1f
void gltexcoord1f_uh(argp_glTexCoord1f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord1f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD1F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord1i
void gltexcoord1i_uh(argp_glTexCoord1i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord1i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD1I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord1s
void gltexcoord1s_uh(argp_glTexCoord1s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord1s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD1S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord2d
void gltexcoord2d_uh(argp_glTexCoord2d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord2d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD2D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord2f
void gltexcoord2f_uh(argp_glTexCoord2f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord2f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD2F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord2i
void gltexcoord2i_uh(argp_glTexCoord2i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord2i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD2I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord2s
void gltexcoord2s_uh(argp_glTexCoord2s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord2s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD2S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord3d
void gltexcoord3d_uh(argp_glTexCoord3d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord3d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD3D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord3f
void gltexcoord3f_uh(argp_glTexCoord3f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord3f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD3F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord3i
void gltexcoord3i_uh(argp_glTexCoord3i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord3i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD3I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord3s
void gltexcoord3s_uh(argp_glTexCoord3s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord3s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD3S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord4d
void gltexcoord4d_uh(argp_glTexCoord4d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord4d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD4D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord4f
void gltexcoord4f_uh(argp_glTexCoord4f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord4f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD4F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord4i
void gltexcoord4i_uh(argp_glTexCoord4i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord4i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD4I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord4s
void gltexcoord4s_uh(argp_glTexCoord4s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord4s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD4S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord1dv
void gltexcoord1dv_uh(argp_glTexCoord1dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord1dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD1DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord1fv
void gltexcoord1fv_uh(argp_glTexCoord1fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord1fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD1FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord1iv
void gltexcoord1iv_uh(argp_glTexCoord1iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord1iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD1IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord1sv
void gltexcoord1sv_uh(argp_glTexCoord1sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord1sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD1SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord2dv
void gltexcoord2dv_uh(argp_glTexCoord2dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord2dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD2DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord2fv
void gltexcoord2fv_uh(argp_glTexCoord2fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord2fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD2FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord2iv
void gltexcoord2iv_uh(argp_glTexCoord2iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord2iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD2IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord2sv
void gltexcoord2sv_uh(argp_glTexCoord2sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord2sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD2SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord3dv
void gltexcoord3dv_uh(argp_glTexCoord3dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord3dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD3DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord3fv
void gltexcoord3fv_uh(argp_glTexCoord3fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord3fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD3FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord3iv
void gltexcoord3iv_uh(argp_glTexCoord3iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord3iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD3IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord3sv
void gltexcoord3sv_uh(argp_glTexCoord3sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord3sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD3SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord4dv
void gltexcoord4dv_uh(argp_glTexCoord4dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord4dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD4DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord4fv
void gltexcoord4fv_uh(argp_glTexCoord4fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord4fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD4FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord4iv
void gltexcoord4iv_uh(argp_glTexCoord4iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord4iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD4IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoord4sv
void gltexcoord4sv_uh(argp_glTexCoord4sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoord4sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORD4SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos2d
void glrasterpos2d_uh(argp_glRasterPos2d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos2d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS2D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos2f
void glrasterpos2f_uh(argp_glRasterPos2f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos2f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS2F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos2i
void glrasterpos2i_uh(argp_glRasterPos2i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos2i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS2I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos2s
void glrasterpos2s_uh(argp_glRasterPos2s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos2s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS2S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos3d
void glrasterpos3d_uh(argp_glRasterPos3d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos3d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS3D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos3f
void glrasterpos3f_uh(argp_glRasterPos3f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos3f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS3F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos3i
void glrasterpos3i_uh(argp_glRasterPos3i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos3i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS3I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos3s
void glrasterpos3s_uh(argp_glRasterPos3s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos3s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS3S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos4d
void glrasterpos4d_uh(argp_glRasterPos4d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos4d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS4D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos4f
void glrasterpos4f_uh(argp_glRasterPos4f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos4f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS4F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos4i
void glrasterpos4i_uh(argp_glRasterPos4i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos4i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS4I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos4s
void glrasterpos4s_uh(argp_glRasterPos4s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos4s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS4S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos2dv
void glrasterpos2dv_uh(argp_glRasterPos2dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos2dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS2DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos2fv
void glrasterpos2fv_uh(argp_glRasterPos2fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos2fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS2FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos2iv
void glrasterpos2iv_uh(argp_glRasterPos2iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos2iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS2IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos2sv
void glrasterpos2sv_uh(argp_glRasterPos2sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos2sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS2SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos3dv
void glrasterpos3dv_uh(argp_glRasterPos3dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos3dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS3DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos3fv
void glrasterpos3fv_uh(argp_glRasterPos3fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos3fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS3FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos3iv
void glrasterpos3iv_uh(argp_glRasterPos3iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos3iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS3IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos3sv
void glrasterpos3sv_uh(argp_glRasterPos3sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos3sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS3SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos4dv
void glrasterpos4dv_uh(argp_glRasterPos4dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos4dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS4DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos4fv
void glrasterpos4fv_uh(argp_glRasterPos4fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos4fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS4FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos4iv
void glrasterpos4iv_uh(argp_glRasterPos4iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos4iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS4IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRasterPos4sv
void glrasterpos4sv_uh(argp_glRasterPos4sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRasterPos4sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRASTERPOS4SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRectd
void glrectd_uh(argp_glRectd argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRectd)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRECTD;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRectf
void glrectf_uh(argp_glRectf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRectf)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRECTF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRecti
void glrecti_uh(argp_glRecti argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRecti)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRECTI;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRects
void glrects_uh(argp_glRects argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRects)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRECTS;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRectdv
void glrectdv_uh(argp_glRectdv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRectdv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRECTDV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRectfv
void glrectfv_uh(argp_glRectfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRectfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRECTFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRectiv
void glrectiv_uh(argp_glRectiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRectiv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRECTIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glRectsv
void glrectsv_uh(argp_glRectsv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glRectsv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRECTSV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glVertexPointer
void glvertexpointer_uh(argp_glVertexPointer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glVertexPointer)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLVERTEXPOINTER;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glNormalPointer
void glnormalpointer_uh(argp_glNormalPointer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glNormalPointer)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLNORMALPOINTER;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColorPointer
void glcolorpointer_uh(argp_glColorPointer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColorPointer)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLORPOINTER;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glIndexPointer
void glindexpointer_uh(argp_glIndexPointer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glIndexPointer)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLINDEXPOINTER;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexCoordPointer
void gltexcoordpointer_uh(argp_glTexCoordPointer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexCoordPointer)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXCOORDPOINTER;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEdgeFlagPointer
void gledgeflagpointer_uh(argp_glEdgeFlagPointer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEdgeFlagPointer)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLEDGEFLAGPOINTER;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetPointerv
void glgetpointerv_uh(argp_glGetPointerv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetPointerv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETPOINTERV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glArrayElement
void glarrayelement_uh(argp_glArrayElement argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glArrayElement)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLARRAYELEMENT;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glDrawArrays
void gldrawarrays_uh(argp_glDrawArrays argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glDrawArrays)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLDRAWARRAYS;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glDrawElements
void gldrawelements_uh(argp_glDrawElements argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glDrawElements)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLDRAWELEMENTS;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glInterleavedArrays
void glinterleavedarrays_uh(argp_glInterleavedArrays argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glInterleavedArrays)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLINTERLEAVEDARRAYS;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glShadeModel
void glshademodel_uh(argp_glShadeModel argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glShadeModel)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLSHADEMODEL;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLightf
void gllightf_uh(argp_glLightf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glLightf)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLIGHTF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLighti
void gllighti_uh(argp_glLighti argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glLighti)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLIGHTI;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLightfv
void gllightfv_uh(argp_glLightfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glLightfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLIGHTFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLightiv
void gllightiv_uh(argp_glLightiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glLightiv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLIGHTIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetLightfv
void glgetlightfv_uh(argp_glGetLightfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetLightfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETLIGHTFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetLightiv
void glgetlightiv_uh(argp_glGetLightiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetLightiv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETLIGHTIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLightModelf
void gllightmodelf_uh(argp_glLightModelf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glLightModelf)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLIGHTMODELF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLightModeli
void gllightmodeli_uh(argp_glLightModeli argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glLightModeli)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLIGHTMODELI;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLightModelfv
void gllightmodelfv_uh(argp_glLightModelfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glLightModelfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLIGHTMODELFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLightModeliv
void gllightmodeliv_uh(argp_glLightModeliv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glLightModeliv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLIGHTMODELIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMaterialf
void glmaterialf_uh(argp_glMaterialf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMaterialf)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMATERIALF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMateriali
void glmateriali_uh(argp_glMateriali argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMateriali)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMATERIALI;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMaterialfv
void glmaterialfv_uh(argp_glMaterialfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMaterialfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMATERIALFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMaterialiv
void glmaterialiv_uh(argp_glMaterialiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMaterialiv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMATERIALIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetMaterialfv
void glgetmaterialfv_uh(argp_glGetMaterialfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetMaterialfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETMATERIALFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetMaterialiv
void glgetmaterialiv_uh(argp_glGetMaterialiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetMaterialiv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETMATERIALIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColorMaterial
void glcolormaterial_uh(argp_glColorMaterial argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColorMaterial)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLORMATERIAL;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPixelZoom
void glpixelzoom_uh(argp_glPixelZoom argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPixelZoom)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPIXELZOOM;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPixelStoref
void glpixelstoref_uh(argp_glPixelStoref argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPixelStoref)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPIXELSTOREF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPixelStorei
void glpixelstorei_uh(argp_glPixelStorei argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPixelStorei)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPIXELSTOREI;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPixelTransferf
void glpixeltransferf_uh(argp_glPixelTransferf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPixelTransferf)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPIXELTRANSFERF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPixelTransferi
void glpixeltransferi_uh(argp_glPixelTransferi argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPixelTransferi)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPIXELTRANSFERI;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPixelMapfv
void glpixelmapfv_uh(argp_glPixelMapfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPixelMapfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPIXELMAPFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPixelMapuiv
void glpixelmapuiv_uh(argp_glPixelMapuiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPixelMapuiv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPIXELMAPUIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPixelMapusv
void glpixelmapusv_uh(argp_glPixelMapusv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPixelMapusv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPIXELMAPUSV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetPixelMapfv
void glgetpixelmapfv_uh(argp_glGetPixelMapfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetPixelMapfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETPIXELMAPFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetPixelMapuiv
void glgetpixelmapuiv_uh(argp_glGetPixelMapuiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetPixelMapuiv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETPIXELMAPUIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetPixelMapusv
void glgetpixelmapusv_uh(argp_glGetPixelMapusv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetPixelMapusv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETPIXELMAPUSV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glBitmap
void glbitmap_uh(argp_glBitmap argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glBitmap)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLBITMAP;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glReadPixels
void glreadpixels_uh(argp_glReadPixels argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glReadPixels)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLREADPIXELS;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glDrawPixels
void gldrawpixels_uh(argp_glDrawPixels argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glDrawPixels)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLDRAWPIXELS;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCopyPixels
void glcopypixels_uh(argp_glCopyPixels argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCopyPixels)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOPYPIXELS;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glStencilFunc
void glstencilfunc_uh(argp_glStencilFunc argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glStencilFunc)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLSTENCILFUNC;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glStencilMask
void glstencilmask_uh(argp_glStencilMask argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glStencilMask)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLSTENCILMASK;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glStencilOp
void glstencilop_uh(argp_glStencilOp argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glStencilOp)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLSTENCILOP;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glClearStencil
void glclearstencil_uh(argp_glClearStencil argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glClearStencil)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCLEARSTENCIL;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexGend
void gltexgend_uh(argp_glTexGend argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexGend)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXGEND;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexGenf
void gltexgenf_uh(argp_glTexGenf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexGenf)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXGENF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexGeni
void gltexgeni_uh(argp_glTexGeni argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexGeni)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXGENI;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexGendv
void gltexgendv_uh(argp_glTexGendv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexGendv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXGENDV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexGenfv
void gltexgenfv_uh(argp_glTexGenfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexGenfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXGENFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexGeniv
void gltexgeniv_uh(argp_glTexGeniv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexGeniv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXGENIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetTexGendv
void glgettexgendv_uh(argp_glGetTexGendv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetTexGendv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETTEXGENDV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetTexGenfv
void glgettexgenfv_uh(argp_glGetTexGenfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetTexGenfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETTEXGENFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetTexGeniv
void glgettexgeniv_uh(argp_glGetTexGeniv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetTexGeniv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETTEXGENIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexEnvf
void gltexenvf_uh(argp_glTexEnvf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexEnvf)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXENVF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexEnvi
void gltexenvi_uh(argp_glTexEnvi argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexEnvi)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXENVI;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexEnvfv
void gltexenvfv_uh(argp_glTexEnvfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexEnvfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXENVFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexEnviv
void gltexenviv_uh(argp_glTexEnviv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexEnviv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXENVIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetTexEnvfv
void glgettexenvfv_uh(argp_glGetTexEnvfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetTexEnvfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETTEXENVFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetTexEnviv
void glgettexenviv_uh(argp_glGetTexEnviv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetTexEnviv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETTEXENVIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexParameterf
void gltexparameterf_uh(argp_glTexParameterf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexParameterf)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXPARAMETERF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexParameteri
void gltexparameteri_uh(argp_glTexParameteri argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexParameteri)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXPARAMETERI;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexParameterfv
void gltexparameterfv_uh(argp_glTexParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexParameterfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXPARAMETERFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexParameteriv
void gltexparameteriv_uh(argp_glTexParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexParameteriv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXPARAMETERIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetTexParameterfv
void glgettexparameterfv_uh(argp_glGetTexParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetTexParameterfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETTEXPARAMETERFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetTexParameteriv
void glgettexparameteriv_uh(argp_glGetTexParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetTexParameteriv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETTEXPARAMETERIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetTexLevelParameterfv
void glgettexlevelparameterfv_uh(argp_glGetTexLevelParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetTexLevelParameterfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETTEXLEVELPARAMETERFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetTexLevelParameteriv
void glgettexlevelparameteriv_uh(argp_glGetTexLevelParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetTexLevelParameteriv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETTEXLEVELPARAMETERIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexImage1D
void glteximage1d_uh(argp_glTexImage1D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexImage1D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXIMAGE1D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexImage2D
void glteximage2d_uh(argp_glTexImage2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexImage2D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXIMAGE2D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetTexImage
void glgetteximage_uh(argp_glGetTexImage argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetTexImage)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETTEXIMAGE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGenTextures
void glgentextures_uh(argp_glGenTextures argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGenTextures)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGENTEXTURES;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glDeleteTextures
void gldeletetextures_uh(argp_glDeleteTextures argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glDeleteTextures)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLDELETETEXTURES;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glBindTexture
void glbindtexture_uh(argp_glBindTexture argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glBindTexture)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLBINDTEXTURE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPrioritizeTextures
void glprioritizetextures_uh(argp_glPrioritizeTextures argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPrioritizeTextures)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPRIORITIZETEXTURES;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glAreTexturesResident
GLboolean glaretexturesresident_uh(argp_glAreTexturesResident argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glAreTexturesResident)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLARETEXTURESRESIDENT;
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
    if(ShmPTR->data_type != GLBOOLEAN){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(GLboolean);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    GLboolean result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glIsTexture
GLboolean glistexture_uh(argp_glIsTexture argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glIsTexture)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLISTEXTURE;
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
    if(ShmPTR->data_type != GLBOOLEAN){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(GLboolean);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    GLboolean result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glTexSubImage1D
void gltexsubimage1d_uh(argp_glTexSubImage1D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexSubImage1D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXSUBIMAGE1D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexSubImage2D
void gltexsubimage2d_uh(argp_glTexSubImage2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexSubImage2D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXSUBIMAGE2D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCopyTexImage1D
void glcopyteximage1d_uh(argp_glCopyTexImage1D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCopyTexImage1D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOPYTEXIMAGE1D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCopyTexImage2D
void glcopyteximage2d_uh(argp_glCopyTexImage2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCopyTexImage2D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOPYTEXIMAGE2D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCopyTexSubImage1D
void glcopytexsubimage1d_uh(argp_glCopyTexSubImage1D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCopyTexSubImage1D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOPYTEXSUBIMAGE1D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCopyTexSubImage2D
void glcopytexsubimage2d_uh(argp_glCopyTexSubImage2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCopyTexSubImage2D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOPYTEXSUBIMAGE2D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMap1d
void glmap1d_uh(argp_glMap1d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMap1d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMAP1D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMap1f
void glmap1f_uh(argp_glMap1f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMap1f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMAP1F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMap2d
void glmap2d_uh(argp_glMap2d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMap2d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMAP2D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMap2f
void glmap2f_uh(argp_glMap2f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMap2f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMAP2F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetMapdv
void glgetmapdv_uh(argp_glGetMapdv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetMapdv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETMAPDV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetMapfv
void glgetmapfv_uh(argp_glGetMapfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetMapfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETMAPFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetMapiv
void glgetmapiv_uh(argp_glGetMapiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetMapiv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETMAPIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEvalCoord1d
void glevalcoord1d_uh(argp_glEvalCoord1d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEvalCoord1d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLEVALCOORD1D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEvalCoord1f
void glevalcoord1f_uh(argp_glEvalCoord1f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEvalCoord1f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLEVALCOORD1F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEvalCoord1dv
void glevalcoord1dv_uh(argp_glEvalCoord1dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEvalCoord1dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLEVALCOORD1DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEvalCoord1fv
void glevalcoord1fv_uh(argp_glEvalCoord1fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEvalCoord1fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLEVALCOORD1FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEvalCoord2d
void glevalcoord2d_uh(argp_glEvalCoord2d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEvalCoord2d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLEVALCOORD2D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEvalCoord2f
void glevalcoord2f_uh(argp_glEvalCoord2f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEvalCoord2f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLEVALCOORD2F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEvalCoord2dv
void glevalcoord2dv_uh(argp_glEvalCoord2dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEvalCoord2dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLEVALCOORD2DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEvalCoord2fv
void glevalcoord2fv_uh(argp_glEvalCoord2fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEvalCoord2fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLEVALCOORD2FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMapGrid1d
void glmapgrid1d_uh(argp_glMapGrid1d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMapGrid1d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMAPGRID1D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMapGrid1f
void glmapgrid1f_uh(argp_glMapGrid1f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMapGrid1f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMAPGRID1F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMapGrid2d
void glmapgrid2d_uh(argp_glMapGrid2d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMapGrid2d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMAPGRID2D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMapGrid2f
void glmapgrid2f_uh(argp_glMapGrid2f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMapGrid2f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMAPGRID2F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEvalPoint1
void glevalpoint1_uh(argp_glEvalPoint1 argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEvalPoint1)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLEVALPOINT1;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEvalPoint2
void glevalpoint2_uh(argp_glEvalPoint2 argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEvalPoint2)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLEVALPOINT2;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEvalMesh1
void glevalmesh1_uh(argp_glEvalMesh1 argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEvalMesh1)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLEVALMESH1;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glEvalMesh2
void glevalmesh2_uh(argp_glEvalMesh2 argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glEvalMesh2)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLEVALMESH2;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glFogf
void glfogf_uh(argp_glFogf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glFogf)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLFOGF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glFogi
void glfogi_uh(argp_glFogi argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glFogi)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLFOGI;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glFogfv
void glfogfv_uh(argp_glFogfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glFogfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLFOGFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glFogiv
void glfogiv_uh(argp_glFogiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glFogiv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLFOGIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glFeedbackBuffer
void glfeedbackbuffer_uh(argp_glFeedbackBuffer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glFeedbackBuffer)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLFEEDBACKBUFFER;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPassThrough
void glpassthrough_uh(argp_glPassThrough argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPassThrough)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPASSTHROUGH;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glSelectBuffer
void glselectbuffer_uh(argp_glSelectBuffer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glSelectBuffer)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLSELECTBUFFER;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glInitNames
void glinitnames_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLINITNAMES;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLoadName
void glloadname_uh(argp_glLoadName argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glLoadName)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLOADNAME;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPushName
void glpushname_uh(argp_glPushName argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glPushName)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPUSHNAME;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glPopName
void glpopname_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLPOPNAME;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glDrawRangeElements
void gldrawrangeelements_uh(argp_glDrawRangeElements argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glDrawRangeElements)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLDRAWRANGEELEMENTS;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexImage3D
void glteximage3d_uh(argp_glTexImage3D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexImage3D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXIMAGE3D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glTexSubImage3D
void gltexsubimage3d_uh(argp_glTexSubImage3D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glTexSubImage3D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLTEXSUBIMAGE3D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCopyTexSubImage3D
void glcopytexsubimage3d_uh(argp_glCopyTexSubImage3D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCopyTexSubImage3D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOPYTEXSUBIMAGE3D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColorTable
void glcolortable_uh(argp_glColorTable argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColorTable)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLORTABLE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColorSubTable
void glcolorsubtable_uh(argp_glColorSubTable argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColorSubTable)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLORSUBTABLE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColorTableParameteriv
void glcolortableparameteriv_uh(argp_glColorTableParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColorTableParameteriv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLORTABLEPARAMETERIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glColorTableParameterfv
void glcolortableparameterfv_uh(argp_glColorTableParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glColorTableParameterfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOLORTABLEPARAMETERFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCopyColorSubTable
void glcopycolorsubtable_uh(argp_glCopyColorSubTable argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCopyColorSubTable)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOPYCOLORSUBTABLE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCopyColorTable
void glcopycolortable_uh(argp_glCopyColorTable argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCopyColorTable)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOPYCOLORTABLE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetColorTable
void glgetcolortable_uh(argp_glGetColorTable argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetColorTable)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETCOLORTABLE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetColorTableParameterfv
void glgetcolortableparameterfv_uh(argp_glGetColorTableParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetColorTableParameterfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETCOLORTABLEPARAMETERFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetColorTableParameteriv
void glgetcolortableparameteriv_uh(argp_glGetColorTableParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetColorTableParameteriv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETCOLORTABLEPARAMETERIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glBlendEquation
void glblendequation_uh(argp_glBlendEquation argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glBlendEquation)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLBLENDEQUATION;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glBlendColor
void glblendcolor_uh(argp_glBlendColor argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glBlendColor)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLBLENDCOLOR;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glHistogram
void glhistogram_uh(argp_glHistogram argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glHistogram)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLHISTOGRAM;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glResetHistogram
void glresethistogram_uh(argp_glResetHistogram argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glResetHistogram)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRESETHISTOGRAM;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetHistogram
void glgethistogram_uh(argp_glGetHistogram argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetHistogram)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETHISTOGRAM;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetHistogramParameterfv
void glgethistogramparameterfv_uh(argp_glGetHistogramParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetHistogramParameterfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETHISTOGRAMPARAMETERFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetHistogramParameteriv
void glgethistogramparameteriv_uh(argp_glGetHistogramParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetHistogramParameteriv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETHISTOGRAMPARAMETERIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMinmax
void glminmax_uh(argp_glMinmax argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMinmax)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMINMAX;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glResetMinmax
void glresetminmax_uh(argp_glResetMinmax argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glResetMinmax)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLRESETMINMAX;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetMinmax
void glgetminmax_uh(argp_glGetMinmax argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetMinmax)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETMINMAX;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetMinmaxParameterfv
void glgetminmaxparameterfv_uh(argp_glGetMinmaxParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetMinmaxParameterfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETMINMAXPARAMETERFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetMinmaxParameteriv
void glgetminmaxparameteriv_uh(argp_glGetMinmaxParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetMinmaxParameteriv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETMINMAXPARAMETERIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glConvolutionFilter1D
void glconvolutionfilter1d_uh(argp_glConvolutionFilter1D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glConvolutionFilter1D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCONVOLUTIONFILTER1D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glConvolutionFilter2D
void glconvolutionfilter2d_uh(argp_glConvolutionFilter2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glConvolutionFilter2D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCONVOLUTIONFILTER2D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glConvolutionParameterf
void glconvolutionparameterf_uh(argp_glConvolutionParameterf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glConvolutionParameterf)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCONVOLUTIONPARAMETERF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glConvolutionParameterfv
void glconvolutionparameterfv_uh(argp_glConvolutionParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glConvolutionParameterfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCONVOLUTIONPARAMETERFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glConvolutionParameteri
void glconvolutionparameteri_uh(argp_glConvolutionParameteri argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glConvolutionParameteri)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCONVOLUTIONPARAMETERI;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glConvolutionParameteriv
void glconvolutionparameteriv_uh(argp_glConvolutionParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glConvolutionParameteriv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCONVOLUTIONPARAMETERIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCopyConvolutionFilter1D
void glcopyconvolutionfilter1d_uh(argp_glCopyConvolutionFilter1D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCopyConvolutionFilter1D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOPYCONVOLUTIONFILTER1D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCopyConvolutionFilter2D
void glcopyconvolutionfilter2d_uh(argp_glCopyConvolutionFilter2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCopyConvolutionFilter2D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOPYCONVOLUTIONFILTER2D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetConvolutionFilter
void glgetconvolutionfilter_uh(argp_glGetConvolutionFilter argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetConvolutionFilter)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETCONVOLUTIONFILTER;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetConvolutionParameterfv
void glgetconvolutionparameterfv_uh(argp_glGetConvolutionParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetConvolutionParameterfv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETCONVOLUTIONPARAMETERFV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetConvolutionParameteriv
void glgetconvolutionparameteriv_uh(argp_glGetConvolutionParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetConvolutionParameteriv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETCONVOLUTIONPARAMETERIV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glSeparableFilter2D
void glseparablefilter2d_uh(argp_glSeparableFilter2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glSeparableFilter2D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLSEPARABLEFILTER2D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetSeparableFilter
void glgetseparablefilter_uh(argp_glGetSeparableFilter argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetSeparableFilter)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETSEPARABLEFILTER;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glActiveTexture
void glactivetexture_uh(argp_glActiveTexture argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glActiveTexture)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLACTIVETEXTURE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glClientActiveTexture
void glclientactivetexture_uh(argp_glClientActiveTexture argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glClientActiveTexture)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCLIENTACTIVETEXTURE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCompressedTexImage1D
void glcompressedteximage1d_uh(argp_glCompressedTexImage1D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCompressedTexImage1D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOMPRESSEDTEXIMAGE1D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCompressedTexImage2D
void glcompressedteximage2d_uh(argp_glCompressedTexImage2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCompressedTexImage2D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOMPRESSEDTEXIMAGE2D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCompressedTexImage3D
void glcompressedteximage3d_uh(argp_glCompressedTexImage3D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCompressedTexImage3D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOMPRESSEDTEXIMAGE3D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCompressedTexSubImage1D
void glcompressedtexsubimage1d_uh(argp_glCompressedTexSubImage1D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCompressedTexSubImage1D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOMPRESSEDTEXSUBIMAGE1D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCompressedTexSubImage2D
void glcompressedtexsubimage2d_uh(argp_glCompressedTexSubImage2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCompressedTexSubImage2D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOMPRESSEDTEXSUBIMAGE2D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glCompressedTexSubImage3D
void glcompressedtexsubimage3d_uh(argp_glCompressedTexSubImage3D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glCompressedTexSubImage3D)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCOMPRESSEDTEXSUBIMAGE3D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glGetCompressedTexImage
void glgetcompressedteximage_uh(argp_glGetCompressedTexImage argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glGetCompressedTexImage)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETCOMPRESSEDTEXIMAGE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord1d
void glmultitexcoord1d_uh(argp_glMultiTexCoord1d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord1d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD1D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord1dv
void glmultitexcoord1dv_uh(argp_glMultiTexCoord1dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord1dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD1DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord1f
void glmultitexcoord1f_uh(argp_glMultiTexCoord1f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord1f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD1F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord1fv
void glmultitexcoord1fv_uh(argp_glMultiTexCoord1fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord1fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD1FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord1i
void glmultitexcoord1i_uh(argp_glMultiTexCoord1i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord1i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD1I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord1iv
void glmultitexcoord1iv_uh(argp_glMultiTexCoord1iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord1iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD1IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord1s
void glmultitexcoord1s_uh(argp_glMultiTexCoord1s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord1s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD1S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord1sv
void glmultitexcoord1sv_uh(argp_glMultiTexCoord1sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord1sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD1SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord2d
void glmultitexcoord2d_uh(argp_glMultiTexCoord2d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord2d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD2D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord2dv
void glmultitexcoord2dv_uh(argp_glMultiTexCoord2dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord2dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD2DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord2f
void glmultitexcoord2f_uh(argp_glMultiTexCoord2f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord2f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD2F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord2fv
void glmultitexcoord2fv_uh(argp_glMultiTexCoord2fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord2fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD2FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord2i
void glmultitexcoord2i_uh(argp_glMultiTexCoord2i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord2i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD2I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord2iv
void glmultitexcoord2iv_uh(argp_glMultiTexCoord2iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord2iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD2IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord2s
void glmultitexcoord2s_uh(argp_glMultiTexCoord2s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord2s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD2S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord2sv
void glmultitexcoord2sv_uh(argp_glMultiTexCoord2sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord2sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD2SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord3d
void glmultitexcoord3d_uh(argp_glMultiTexCoord3d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord3d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD3D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord3dv
void glmultitexcoord3dv_uh(argp_glMultiTexCoord3dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord3dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD3DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord3f
void glmultitexcoord3f_uh(argp_glMultiTexCoord3f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord3f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD3F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord3fv
void glmultitexcoord3fv_uh(argp_glMultiTexCoord3fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord3fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD3FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord3i
void glmultitexcoord3i_uh(argp_glMultiTexCoord3i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord3i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD3I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord3iv
void glmultitexcoord3iv_uh(argp_glMultiTexCoord3iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord3iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD3IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord3s
void glmultitexcoord3s_uh(argp_glMultiTexCoord3s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord3s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD3S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord3sv
void glmultitexcoord3sv_uh(argp_glMultiTexCoord3sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord3sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD3SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord4d
void glmultitexcoord4d_uh(argp_glMultiTexCoord4d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord4d)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD4D;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord4dv
void glmultitexcoord4dv_uh(argp_glMultiTexCoord4dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord4dv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD4DV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord4f
void glmultitexcoord4f_uh(argp_glMultiTexCoord4f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord4f)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD4F;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord4fv
void glmultitexcoord4fv_uh(argp_glMultiTexCoord4fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord4fv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD4FV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord4i
void glmultitexcoord4i_uh(argp_glMultiTexCoord4i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord4i)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD4I;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord4iv
void glmultitexcoord4iv_uh(argp_glMultiTexCoord4iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord4iv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD4IV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord4s
void glmultitexcoord4s_uh(argp_glMultiTexCoord4s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord4s)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD4S;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord4sv
void glmultitexcoord4sv_uh(argp_glMultiTexCoord4sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord4sv)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD4SV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLoadTransposeMatrixd
void glloadtransposematrixd_uh(argp_glLoadTransposeMatrixd argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glLoadTransposeMatrixd)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLOADTRANSPOSEMATRIXD;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glLoadTransposeMatrixf
void glloadtransposematrixf_uh(argp_glLoadTransposeMatrixf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glLoadTransposeMatrixf)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLLOADTRANSPOSEMATRIXF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultTransposeMatrixd
void glmulttransposematrixd_uh(argp_glMultTransposeMatrixd argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultTransposeMatrixd)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTTRANSPOSEMATRIXD;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultTransposeMatrixf
void glmulttransposematrixf_uh(argp_glMultTransposeMatrixf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultTransposeMatrixf)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTTRANSPOSEMATRIXF;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glSampleCoverage
void glsamplecoverage_uh(argp_glSampleCoverage argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glSampleCoverage)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLSAMPLECOVERAGE;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glActiveTextureARB
void glactivetexturearb_uh(argp_glActiveTextureARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glActiveTextureARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLACTIVETEXTUREARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glClientActiveTextureARB
void glclientactivetexturearb_uh(argp_glClientActiveTextureARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glClientActiveTextureARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLCLIENTACTIVETEXTUREARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord1dARB
void glmultitexcoord1darb_uh(argp_glMultiTexCoord1dARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord1dARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD1DARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord1dvARB
void glmultitexcoord1dvarb_uh(argp_glMultiTexCoord1dvARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord1dvARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD1DVARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord1fARB
void glmultitexcoord1farb_uh(argp_glMultiTexCoord1fARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord1fARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD1FARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord1fvARB
void glmultitexcoord1fvarb_uh(argp_glMultiTexCoord1fvARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord1fvARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD1FVARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord1iARB
void glmultitexcoord1iarb_uh(argp_glMultiTexCoord1iARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord1iARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD1IARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord1ivARB
void glmultitexcoord1ivarb_uh(argp_glMultiTexCoord1ivARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord1ivARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD1IVARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord1sARB
void glmultitexcoord1sarb_uh(argp_glMultiTexCoord1sARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord1sARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD1SARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord1svARB
void glmultitexcoord1svarb_uh(argp_glMultiTexCoord1svARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord1svARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD1SVARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord2dARB
void glmultitexcoord2darb_uh(argp_glMultiTexCoord2dARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord2dARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD2DARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord2dvARB
void glmultitexcoord2dvarb_uh(argp_glMultiTexCoord2dvARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord2dvARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD2DVARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord2fARB
void glmultitexcoord2farb_uh(argp_glMultiTexCoord2fARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord2fARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD2FARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord2fvARB
void glmultitexcoord2fvarb_uh(argp_glMultiTexCoord2fvARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord2fvARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD2FVARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord2iARB
void glmultitexcoord2iarb_uh(argp_glMultiTexCoord2iARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord2iARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD2IARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord2ivARB
void glmultitexcoord2ivarb_uh(argp_glMultiTexCoord2ivARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord2ivARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD2IVARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord2sARB
void glmultitexcoord2sarb_uh(argp_glMultiTexCoord2sARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord2sARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD2SARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord2svARB
void glmultitexcoord2svarb_uh(argp_glMultiTexCoord2svARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord2svARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD2SVARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord3dARB
void glmultitexcoord3darb_uh(argp_glMultiTexCoord3dARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord3dARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD3DARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord3dvARB
void glmultitexcoord3dvarb_uh(argp_glMultiTexCoord3dvARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord3dvARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD3DVARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord3fARB
void glmultitexcoord3farb_uh(argp_glMultiTexCoord3fARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord3fARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD3FARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord3fvARB
void glmultitexcoord3fvarb_uh(argp_glMultiTexCoord3fvARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord3fvARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD3FVARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord3iARB
void glmultitexcoord3iarb_uh(argp_glMultiTexCoord3iARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord3iARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD3IARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord3ivARB
void glmultitexcoord3ivarb_uh(argp_glMultiTexCoord3ivARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord3ivARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD3IVARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord3sARB
void glmultitexcoord3sarb_uh(argp_glMultiTexCoord3sARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord3sARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD3SARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord3svARB
void glmultitexcoord3svarb_uh(argp_glMultiTexCoord3svARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord3svARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD3SVARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord4dARB
void glmultitexcoord4darb_uh(argp_glMultiTexCoord4dARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord4dARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD4DARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord4dvARB
void glmultitexcoord4dvarb_uh(argp_glMultiTexCoord4dvARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord4dvARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD4DVARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord4fARB
void glmultitexcoord4farb_uh(argp_glMultiTexCoord4fARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord4fARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD4FARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord4fvARB
void glmultitexcoord4fvarb_uh(argp_glMultiTexCoord4fvARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord4fvARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD4FVARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord4iARB
void glmultitexcoord4iarb_uh(argp_glMultiTexCoord4iARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord4iARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD4IARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord4ivARB
void glmultitexcoord4ivarb_uh(argp_glMultiTexCoord4ivARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord4ivARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD4IVARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord4sARB
void glmultitexcoord4sarb_uh(argp_glMultiTexCoord4sARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord4sARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD4SARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glMultiTexCoord4svARB
void glmultitexcoord4svarb_uh(argp_glMultiTexCoord4svARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glMultiTexCoord4svARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLMULTITEXCOORD4SVARB;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glBlendEquationSeparateATI
void glblendequationseparateati_uh(argp_glBlendEquationSeparateATI argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glBlendEquationSeparateATI)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLBLENDEQUATIONSEPARATEATI;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glXDestroyContext
void glxdestroycontext_uh(argp_glXDestroyContext argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXDestroyContext)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXDESTROYCONTEXT;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glXSwapBuffers
void glxswapbuffers_uh(argp_glXSwapBuffers argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXSwapBuffers)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXSWAPBUFFERS;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glXDestroyGLXPixmap
void glxdestroyglxpixmap_uh(argp_glXDestroyGLXPixmap argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXDestroyGLXPixmap)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXDESTROYGLXPIXMAP;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glXQueryExtension
Bool glxqueryextension_uh(argp_glXQueryExtension argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXQueryExtension)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXQUERYEXTENSION;
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
    if(ShmPTR->data_type != BOOL){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(Bool);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    Bool result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXQueryVersion
Bool glxqueryversion_uh(argp_glXQueryVersion argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXQueryVersion)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXQUERYVERSION;
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
    if(ShmPTR->data_type != BOOL){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(Bool);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    Bool result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXIsDirect
Bool glxisdirect_uh(argp_glXIsDirect argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXIsDirect)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXISDIRECT;
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
    if(ShmPTR->data_type != BOOL){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(Bool);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    Bool result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXGetCurrentContext
GLXContext glxgetcurrentcontext_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXGETCURRENTCONTEXT;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != GLXCONTEXT){
        printf("Payload data type incorrect\n");
    }

    // assert if correct payload size
    int ret_size = sizeof(GLXContext);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    GLXContext result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXGetCurrentDrawable
GLXDrawable glxgetcurrentdrawable_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXGETCURRENTDRAWABLE;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != GLXDRAWABLE){
        printf("Payload data type incorrect\n");
    }

    // assert if correct payload size
    int ret_size = sizeof(GLXDrawable);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    GLXDrawable result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXWaitGL
void glxwaitgl_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXWAITGL;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glXWaitX
void glxwaitx_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXWAITX;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glXUseXFont
void glxusexfont_uh(argp_glXUseXFont argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXUseXFont)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXUSEXFONT;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glXQueryExtensionsString
char* glxqueryextensionsstring_uh(argp_glXQueryExtensionsString argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXQueryExtensionsString)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXQUERYEXTENSIONSSTRING;
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
    if(ShmPTR->data_type != CHARP){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(char*);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    char* result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXQueryServerString
char* glxqueryserverstring_uh(argp_glXQueryServerString argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXQueryServerString)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXQUERYSERVERSTRING;
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
    if(ShmPTR->data_type != CHARP){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(char*);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    char* result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXGetClientString
char* glxgetclientstring_uh(argp_glXGetClientString argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXGetClientString)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXGETCLIENTSTRING;
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
    if(ShmPTR->data_type != CHARP){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(char*);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    char* result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXGetCurrentDisplay
Display* glxgetcurrentdisplay_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXGETCURRENTDISPLAY;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != DISPLAYP){
        printf("Payload data type incorrect\n");
    }

    // assert if correct payload size
    int ret_size = sizeof(Display*);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    Display* result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXDestroyWindow
void glxdestroywindow_uh(argp_glXDestroyWindow argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXDestroyWindow)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXDESTROYWINDOW;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glXDestroyPixmap
void glxdestroypixmap_uh(argp_glXDestroyPixmap argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXDestroyPixmap)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXDESTROYPIXMAP;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glXDestroyPbuffer
void glxdestroypbuffer_uh(argp_glXDestroyPbuffer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXDestroyPbuffer)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXDESTROYPBUFFER;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glXGetCurrentReadDrawable
GLXDrawable glxgetcurrentreaddrawable_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXGETCURRENTREADDRAWABLE;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != GLXDRAWABLE){
        printf("Payload data type incorrect\n");
    }

    // assert if correct payload size
    int ret_size = sizeof(GLXDrawable);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    GLXDrawable result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXGetProcAddressARB
__GLXextFuncPtr glxgetprocaddressarb_uh(argp_glXGetProcAddressARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXGetProcAddressARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXGETPROCADDRESSARB;
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
    if(ShmPTR->data_type != __GLXEXTFUNCPTR){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(__GLXextFuncPtr);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    __GLXextFuncPtr result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXGetProcAddress
void* glxgetprocaddress_uh(argp_glXGetProcAddress argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXGetProcAddress)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXGETPROCADDRESS;
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
    if(ShmPTR->data_type != VOIDP){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(void*);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    void* result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXAllocateMemoryNV
void* glxallocatememorynv_uh(argp_glXAllocateMemoryNV argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXAllocateMemoryNV)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXALLOCATEMEMORYNV;
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
    if(ShmPTR->data_type != VOIDP){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(void*);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    void* result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXFreeMemoryNV
void glxfreememorynv_uh(argp_glXFreeMemoryNV argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXFreeMemoryNV)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXFREEMEMORYNV;
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
}

// -- glXBindTexImageARB
Bool glxbindteximagearb_uh(argp_glXBindTexImageARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXBindTexImageARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXBINDTEXIMAGEARB;
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
    if(ShmPTR->data_type != BOOL){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(Bool);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    Bool result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXReleaseTexImageARB
Bool glxreleaseteximagearb_uh(argp_glXReleaseTexImageARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXReleaseTexImageARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXRELEASETEXIMAGEARB;
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
    if(ShmPTR->data_type != BOOL){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(Bool);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    Bool result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXDrawableAttribARB
Bool glxdrawableattribarb_uh(argp_glXDrawableAttribARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXDrawableAttribARB)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXDRAWABLEATTRIBARB;
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
    if(ShmPTR->data_type != BOOL){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(Bool);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    Bool result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXGetFrameUsageMESA
int glxgetframeusagemesa_uh(argp_glXGetFrameUsageMESA argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXGetFrameUsageMESA)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXGETFRAMEUSAGEMESA;
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
    if(ShmPTR->data_type != INT){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(int);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    int result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXBeginFrameTrackingMESA
int glxbeginframetrackingmesa_uh(argp_glXBeginFrameTrackingMESA argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXBeginFrameTrackingMESA)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXBEGINFRAMETRACKINGMESA;
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
    if(ShmPTR->data_type != INT){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(int);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    int result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXEndFrameTrackingMESA
int glxendframetrackingmesa_uh(argp_glXEndFrameTrackingMESA argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXEndFrameTrackingMESA)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXENDFRAMETRACKINGMESA;
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
    if(ShmPTR->data_type != INT){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(int);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    int result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXQueryFrameTrackingMESA
int glxqueryframetrackingmesa_uh(argp_glXQueryFrameTrackingMESA argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXQueryFrameTrackingMESA)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXQUERYFRAMETRACKINGMESA;
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
    if(ShmPTR->data_type != INT){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(int);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    int result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXSwapIntervalMESA
int glxswapintervalmesa_uh(argp_glXSwapIntervalMESA argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(argp_glXSwapIntervalMESA)
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXSWAPINTERVALMESA;
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
    if(ShmPTR->data_type != INT){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(int);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    int result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXGetSwapIntervalMESA
int glxgetswapintervalmesa_uh()
{
    // No inputs to copy

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXGETSWAPINTERVALMESA;
    ShmPTR->payload_size = 0;

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
    if(ShmPTR->data_type != INT){
        printf("Payload data type incorrect\n");
    }

    // assert if correct payload size
    int ret_size = sizeof(int);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    int result;
    memcpy(&result, ShmPTR->buffer, ret_size));

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}
