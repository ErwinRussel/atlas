
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
Display* xopendisplay_uh(args_XOpenDisplay argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XOpenDisplay);
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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- XPending
int xpending_uh(args_XPending argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XPending);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XPENDING;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- XMapWindow
int xmapwindow_uh(args_XMapWindow argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XMapWindow);
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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

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

// -- XCreateWindow
Window xcreatewindow_uh(args_XCreateWindow argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XCreateWindow);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XCREATEWINDOW;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

    // ------ Waiting for Server -----

    // Wait for response
    while (ShmPTR->status != RESPONSE)
        ;

    // assert if the message is a function return
    if(ShmPTR->message_type != FUNC_RETURN){
        printf("Message type is not a function return\n");
    }

    // assert if the datatype is correct
    if(ShmPTR->data_type != WINDOW){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(Window);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    Window result;
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- XFree
int xfree_uh(args_XFree argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XFree);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XFREE;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- XSetNormalHints
int xsetnormalhints_uh(args_XSetNormalHints argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XSetNormalHints);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XSETNORMALHINTS;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- XSetStandardProperties
int xsetstandardproperties_uh(args_XSetStandardProperties argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XSetStandardProperties);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XSETSTANDARDPROPERTIES;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glClearIndex
void glclearindex_uh(args_glClearIndex argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glClearIndex);
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
void glclearcolor_uh(args_glClearColor argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glClearColor);
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
void glclear_uh(args_glClear argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glClear);
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
void glindexmask_uh(args_glIndexMask argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glIndexMask);
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
void glcolormask_uh(args_glColorMask argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColorMask);
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
void glalphafunc_uh(args_glAlphaFunc argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glAlphaFunc);
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
void glblendfunc_uh(args_glBlendFunc argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glBlendFunc);
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
void gllogicop_uh(args_glLogicOp argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glLogicOp);
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
void glcullface_uh(args_glCullFace argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCullFace);
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
void glfrontface_uh(args_glFrontFace argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glFrontFace);
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
void glpointsize_uh(args_glPointSize argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPointSize);
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
void gllinewidth_uh(args_glLineWidth argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glLineWidth);
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
void gllinestipple_uh(args_glLineStipple argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glLineStipple);
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
void glpolygonmode_uh(args_glPolygonMode argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPolygonMode);
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
void glpolygonoffset_uh(args_glPolygonOffset argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPolygonOffset);
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
void glpolygonstipple_uh(args_glPolygonStipple argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPolygonStipple);
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
void glgetpolygonstipple_uh(args_glGetPolygonStipple argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetPolygonStipple);
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
void gledgeflag_uh(args_glEdgeFlag argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEdgeFlag);
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
void gledgeflagv_uh(args_glEdgeFlagv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEdgeFlagv);
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
void glscissor_uh(args_glScissor argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glScissor);
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
void glclipplane_uh(args_glClipPlane argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glClipPlane);
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
void glgetclipplane_uh(args_glGetClipPlane argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetClipPlane);
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
void gldrawbuffer_uh(args_glDrawBuffer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glDrawBuffer);
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
void glreadbuffer_uh(args_glReadBuffer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glReadBuffer);
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
void glenable_uh(args_glEnable argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEnable);
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
void gldisable_uh(args_glDisable argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glDisable);
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
GLboolean glisenabled_uh(args_glIsEnabled argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glIsEnabled);
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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glEnableClientState
void glenableclientstate_uh(args_glEnableClientState argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEnableClientState);
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
void gldisableclientstate_uh(args_glDisableClientState argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glDisableClientState);
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
void glgetbooleanv_uh(args_glGetBooleanv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetBooleanv);
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
void glgetdoublev_uh(args_glGetDoublev argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetDoublev);
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
void glgetfloatv_uh(args_glGetFloatv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetFloatv);
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
void glgetintegerv_uh(args_glGetIntegerv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetIntegerv);
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
void glpushattrib_uh(args_glPushAttrib argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPushAttrib);
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
void glpushclientattrib_uh(args_glPushClientAttrib argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPushClientAttrib);
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
GLint glrendermode_uh(args_glRenderMode argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRenderMode);
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
    memcpy(&result, ShmPTR->buffer, ret_size);

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
void glhint_uh(args_glHint argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glHint);
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
void glcleardepth_uh(args_glClearDepth argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glClearDepth);
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
void gldepthfunc_uh(args_glDepthFunc argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glDepthFunc);
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
void gldepthmask_uh(args_glDepthMask argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glDepthMask);
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
void gldepthrange_uh(args_glDepthRange argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glDepthRange);
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
void glclearaccum_uh(args_glClearAccum argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glClearAccum);
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
void glaccum_uh(args_glAccum argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glAccum);
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
void glmatrixmode_uh(args_glMatrixMode argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMatrixMode);
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
void glortho_uh(args_glOrtho argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glOrtho);
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
void glfrustum_uh(args_glFrustum argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glFrustum);
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
void glviewport_uh(args_glViewport argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glViewport);
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
void glloadmatrixd_uh(args_glLoadMatrixd argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glLoadMatrixd);
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
void glloadmatrixf_uh(args_glLoadMatrixf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glLoadMatrixf);
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
void glmultmatrixd_uh(args_glMultMatrixd argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultMatrixd);
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
void glmultmatrixf_uh(args_glMultMatrixf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultMatrixf);
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
void glrotated_uh(args_glRotated argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRotated);
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
void glrotatef_uh(args_glRotatef argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRotatef);
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
void glscaled_uh(args_glScaled argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glScaled);
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
void glscalef_uh(args_glScalef argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glScalef);
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
void gltranslated_uh(args_glTranslated argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTranslated);
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
void gltranslatef_uh(args_glTranslatef argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTranslatef);
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
GLboolean glislist_uh(args_glIsList argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glIsList);
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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glDeleteLists
void gldeletelists_uh(args_glDeleteLists argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glDeleteLists);
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
GLuint glgenlists_uh(args_glGenLists argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGenLists);
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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glNewList
void glnewlist_uh(args_glNewList argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glNewList);
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
void glcalllist_uh(args_glCallList argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCallList);
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
void glcalllists_uh(args_glCallLists argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCallLists);
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
void gllistbase_uh(args_glListBase argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glListBase);
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
void glbegin_uh(args_glBegin argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glBegin);
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
void glvertex2d_uh(args_glVertex2d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex2d);
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
void glvertex2f_uh(args_glVertex2f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex2f);
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
void glvertex2i_uh(args_glVertex2i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex2i);
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
void glvertex2s_uh(args_glVertex2s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex2s);
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
void glvertex3d_uh(args_glVertex3d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex3d);
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
void glvertex3f_uh(args_glVertex3f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex3f);
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
void glvertex3i_uh(args_glVertex3i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex3i);
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
void glvertex3s_uh(args_glVertex3s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex3s);
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
void glvertex4d_uh(args_glVertex4d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex4d);
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
void glvertex4f_uh(args_glVertex4f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex4f);
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
void glvertex4i_uh(args_glVertex4i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex4i);
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
void glvertex4s_uh(args_glVertex4s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex4s);
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
void glvertex2dv_uh(args_glVertex2dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex2dv);
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
void glvertex2fv_uh(args_glVertex2fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex2fv);
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
void glvertex2iv_uh(args_glVertex2iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex2iv);
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
void glvertex2sv_uh(args_glVertex2sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex2sv);
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
void glvertex3dv_uh(args_glVertex3dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex3dv);
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
void glvertex3fv_uh(args_glVertex3fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex3fv);
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
void glvertex3iv_uh(args_glVertex3iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex3iv);
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
void glvertex3sv_uh(args_glVertex3sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex3sv);
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
void glvertex4dv_uh(args_glVertex4dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex4dv);
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
void glvertex4fv_uh(args_glVertex4fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex4fv);
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
void glvertex4iv_uh(args_glVertex4iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex4iv);
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
void glvertex4sv_uh(args_glVertex4sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertex4sv);
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
void glnormal3b_uh(args_glNormal3b argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glNormal3b);
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
void glnormal3d_uh(args_glNormal3d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glNormal3d);
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
void glnormal3f_uh(args_glNormal3f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glNormal3f);
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
void glnormal3i_uh(args_glNormal3i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glNormal3i);
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
void glnormal3s_uh(args_glNormal3s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glNormal3s);
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
void glnormal3bv_uh(args_glNormal3bv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glNormal3bv);
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
void glnormal3dv_uh(args_glNormal3dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glNormal3dv);
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
void glnormal3fv_uh(args_glNormal3fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glNormal3fv);
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
void glnormal3iv_uh(args_glNormal3iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glNormal3iv);
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
void glnormal3sv_uh(args_glNormal3sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glNormal3sv);
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
void glindexd_uh(args_glIndexd argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glIndexd);
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
void glindexf_uh(args_glIndexf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glIndexf);
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
void glindexi_uh(args_glIndexi argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glIndexi);
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
void glindexs_uh(args_glIndexs argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glIndexs);
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
void glindexub_uh(args_glIndexub argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glIndexub);
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
void glindexdv_uh(args_glIndexdv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glIndexdv);
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
void glindexfv_uh(args_glIndexfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glIndexfv);
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
void glindexiv_uh(args_glIndexiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glIndexiv);
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
void glindexsv_uh(args_glIndexsv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glIndexsv);
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
void glindexubv_uh(args_glIndexubv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glIndexubv);
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
void glcolor3b_uh(args_glColor3b argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor3b);
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
void glcolor3d_uh(args_glColor3d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor3d);
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
void glcolor3f_uh(args_glColor3f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor3f);
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
void glcolor3i_uh(args_glColor3i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor3i);
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
void glcolor3s_uh(args_glColor3s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor3s);
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
void glcolor3ub_uh(args_glColor3ub argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor3ub);
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
void glcolor3ui_uh(args_glColor3ui argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor3ui);
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
void glcolor3us_uh(args_glColor3us argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor3us);
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
void glcolor4b_uh(args_glColor4b argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor4b);
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
void glcolor4d_uh(args_glColor4d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor4d);
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
void glcolor4f_uh(args_glColor4f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor4f);
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
void glcolor4i_uh(args_glColor4i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor4i);
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
void glcolor4s_uh(args_glColor4s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor4s);
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
void glcolor4ub_uh(args_glColor4ub argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor4ub);
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
void glcolor4ui_uh(args_glColor4ui argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor4ui);
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
void glcolor4us_uh(args_glColor4us argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor4us);
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
void glcolor3bv_uh(args_glColor3bv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor3bv);
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
void glcolor3dv_uh(args_glColor3dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor3dv);
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
void glcolor3fv_uh(args_glColor3fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor3fv);
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
void glcolor3iv_uh(args_glColor3iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor3iv);
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
void glcolor3sv_uh(args_glColor3sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor3sv);
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
void glcolor3ubv_uh(args_glColor3ubv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor3ubv);
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
void glcolor3uiv_uh(args_glColor3uiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor3uiv);
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
void glcolor3usv_uh(args_glColor3usv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor3usv);
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
void glcolor4bv_uh(args_glColor4bv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor4bv);
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
void glcolor4dv_uh(args_glColor4dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor4dv);
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
void glcolor4fv_uh(args_glColor4fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor4fv);
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
void glcolor4iv_uh(args_glColor4iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor4iv);
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
void glcolor4sv_uh(args_glColor4sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor4sv);
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
void glcolor4ubv_uh(args_glColor4ubv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor4ubv);
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
void glcolor4uiv_uh(args_glColor4uiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor4uiv);
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
void glcolor4usv_uh(args_glColor4usv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColor4usv);
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
void gltexcoord1d_uh(args_glTexCoord1d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord1d);
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
void gltexcoord1f_uh(args_glTexCoord1f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord1f);
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
void gltexcoord1i_uh(args_glTexCoord1i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord1i);
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
void gltexcoord1s_uh(args_glTexCoord1s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord1s);
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
void gltexcoord2d_uh(args_glTexCoord2d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord2d);
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
void gltexcoord2f_uh(args_glTexCoord2f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord2f);
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
void gltexcoord2i_uh(args_glTexCoord2i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord2i);
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
void gltexcoord2s_uh(args_glTexCoord2s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord2s);
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
void gltexcoord3d_uh(args_glTexCoord3d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord3d);
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
void gltexcoord3f_uh(args_glTexCoord3f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord3f);
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
void gltexcoord3i_uh(args_glTexCoord3i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord3i);
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
void gltexcoord3s_uh(args_glTexCoord3s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord3s);
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
void gltexcoord4d_uh(args_glTexCoord4d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord4d);
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
void gltexcoord4f_uh(args_glTexCoord4f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord4f);
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
void gltexcoord4i_uh(args_glTexCoord4i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord4i);
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
void gltexcoord4s_uh(args_glTexCoord4s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord4s);
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
void gltexcoord1dv_uh(args_glTexCoord1dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord1dv);
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
void gltexcoord1fv_uh(args_glTexCoord1fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord1fv);
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
void gltexcoord1iv_uh(args_glTexCoord1iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord1iv);
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
void gltexcoord1sv_uh(args_glTexCoord1sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord1sv);
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
void gltexcoord2dv_uh(args_glTexCoord2dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord2dv);
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
void gltexcoord2fv_uh(args_glTexCoord2fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord2fv);
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
void gltexcoord2iv_uh(args_glTexCoord2iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord2iv);
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
void gltexcoord2sv_uh(args_glTexCoord2sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord2sv);
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
void gltexcoord3dv_uh(args_glTexCoord3dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord3dv);
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
void gltexcoord3fv_uh(args_glTexCoord3fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord3fv);
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
void gltexcoord3iv_uh(args_glTexCoord3iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord3iv);
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
void gltexcoord3sv_uh(args_glTexCoord3sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord3sv);
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
void gltexcoord4dv_uh(args_glTexCoord4dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord4dv);
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
void gltexcoord4fv_uh(args_glTexCoord4fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord4fv);
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
void gltexcoord4iv_uh(args_glTexCoord4iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord4iv);
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
void gltexcoord4sv_uh(args_glTexCoord4sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoord4sv);
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
void glrasterpos2d_uh(args_glRasterPos2d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos2d);
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
void glrasterpos2f_uh(args_glRasterPos2f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos2f);
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
void glrasterpos2i_uh(args_glRasterPos2i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos2i);
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
void glrasterpos2s_uh(args_glRasterPos2s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos2s);
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
void glrasterpos3d_uh(args_glRasterPos3d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos3d);
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
void glrasterpos3f_uh(args_glRasterPos3f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos3f);
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
void glrasterpos3i_uh(args_glRasterPos3i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos3i);
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
void glrasterpos3s_uh(args_glRasterPos3s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos3s);
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
void glrasterpos4d_uh(args_glRasterPos4d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos4d);
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
void glrasterpos4f_uh(args_glRasterPos4f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos4f);
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
void glrasterpos4i_uh(args_glRasterPos4i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos4i);
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
void glrasterpos4s_uh(args_glRasterPos4s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos4s);
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
void glrasterpos2dv_uh(args_glRasterPos2dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos2dv);
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
void glrasterpos2fv_uh(args_glRasterPos2fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos2fv);
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
void glrasterpos2iv_uh(args_glRasterPos2iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos2iv);
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
void glrasterpos2sv_uh(args_glRasterPos2sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos2sv);
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
void glrasterpos3dv_uh(args_glRasterPos3dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos3dv);
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
void glrasterpos3fv_uh(args_glRasterPos3fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos3fv);
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
void glrasterpos3iv_uh(args_glRasterPos3iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos3iv);
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
void glrasterpos3sv_uh(args_glRasterPos3sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos3sv);
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
void glrasterpos4dv_uh(args_glRasterPos4dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos4dv);
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
void glrasterpos4fv_uh(args_glRasterPos4fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos4fv);
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
void glrasterpos4iv_uh(args_glRasterPos4iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos4iv);
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
void glrasterpos4sv_uh(args_glRasterPos4sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRasterPos4sv);
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
void glrectd_uh(args_glRectd argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRectd);
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
void glrectf_uh(args_glRectf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRectf);
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
void glrecti_uh(args_glRecti argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRecti);
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
void glrects_uh(args_glRects argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRects);
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
void glrectdv_uh(args_glRectdv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRectdv);
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
void glrectfv_uh(args_glRectfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRectfv);
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
void glrectiv_uh(args_glRectiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRectiv);
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
void glrectsv_uh(args_glRectsv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glRectsv);
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
void glvertexpointer_uh(args_glVertexPointer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glVertexPointer);
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
void glnormalpointer_uh(args_glNormalPointer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glNormalPointer);
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
void glcolorpointer_uh(args_glColorPointer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColorPointer);
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
void glindexpointer_uh(args_glIndexPointer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glIndexPointer);
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
void gltexcoordpointer_uh(args_glTexCoordPointer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexCoordPointer);
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
void gledgeflagpointer_uh(args_glEdgeFlagPointer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEdgeFlagPointer);
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
void glgetpointerv_uh(args_glGetPointerv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetPointerv);
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
void glarrayelement_uh(args_glArrayElement argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glArrayElement);
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
void gldrawarrays_uh(args_glDrawArrays argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glDrawArrays);
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
void gldrawelements_uh(args_glDrawElements argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glDrawElements);
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
void glinterleavedarrays_uh(args_glInterleavedArrays argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glInterleavedArrays);
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
void glshademodel_uh(args_glShadeModel argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glShadeModel);
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
void gllightf_uh(args_glLightf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glLightf);
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
void gllighti_uh(args_glLighti argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glLighti);
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
void gllightfv_uh(args_glLightfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glLightfv);
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
void gllightiv_uh(args_glLightiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glLightiv);
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
void glgetlightfv_uh(args_glGetLightfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetLightfv);
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
void glgetlightiv_uh(args_glGetLightiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetLightiv);
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
void gllightmodelf_uh(args_glLightModelf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glLightModelf);
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
void gllightmodeli_uh(args_glLightModeli argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glLightModeli);
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
void gllightmodelfv_uh(args_glLightModelfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glLightModelfv);
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
void gllightmodeliv_uh(args_glLightModeliv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glLightModeliv);
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
void glmaterialf_uh(args_glMaterialf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMaterialf);
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
void glmateriali_uh(args_glMateriali argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMateriali);
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
void glmaterialfv_uh(args_glMaterialfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMaterialfv);
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
void glmaterialiv_uh(args_glMaterialiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMaterialiv);
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
void glgetmaterialfv_uh(args_glGetMaterialfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetMaterialfv);
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
void glgetmaterialiv_uh(args_glGetMaterialiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetMaterialiv);
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
void glcolormaterial_uh(args_glColorMaterial argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColorMaterial);
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
void glpixelzoom_uh(args_glPixelZoom argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPixelZoom);
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
void glpixelstoref_uh(args_glPixelStoref argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPixelStoref);
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
void glpixelstorei_uh(args_glPixelStorei argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPixelStorei);
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
void glpixeltransferf_uh(args_glPixelTransferf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPixelTransferf);
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
void glpixeltransferi_uh(args_glPixelTransferi argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPixelTransferi);
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
void glpixelmapfv_uh(args_glPixelMapfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPixelMapfv);
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
void glpixelmapuiv_uh(args_glPixelMapuiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPixelMapuiv);
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
void glpixelmapusv_uh(args_glPixelMapusv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPixelMapusv);
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
void glgetpixelmapfv_uh(args_glGetPixelMapfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetPixelMapfv);
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
void glgetpixelmapuiv_uh(args_glGetPixelMapuiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetPixelMapuiv);
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
void glgetpixelmapusv_uh(args_glGetPixelMapusv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetPixelMapusv);
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
void glbitmap_uh(args_glBitmap argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glBitmap);
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
void glreadpixels_uh(args_glReadPixels argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glReadPixels);
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
void gldrawpixels_uh(args_glDrawPixels argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glDrawPixels);
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
void glcopypixels_uh(args_glCopyPixels argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCopyPixels);
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
void glstencilfunc_uh(args_glStencilFunc argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glStencilFunc);
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
void glstencilmask_uh(args_glStencilMask argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glStencilMask);
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
void glstencilop_uh(args_glStencilOp argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glStencilOp);
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
void glclearstencil_uh(args_glClearStencil argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glClearStencil);
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
void gltexgend_uh(args_glTexGend argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexGend);
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
void gltexgenf_uh(args_glTexGenf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexGenf);
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
void gltexgeni_uh(args_glTexGeni argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexGeni);
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
void gltexgendv_uh(args_glTexGendv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexGendv);
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
void gltexgenfv_uh(args_glTexGenfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexGenfv);
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
void gltexgeniv_uh(args_glTexGeniv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexGeniv);
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
void glgettexgendv_uh(args_glGetTexGendv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetTexGendv);
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
void glgettexgenfv_uh(args_glGetTexGenfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetTexGenfv);
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
void glgettexgeniv_uh(args_glGetTexGeniv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetTexGeniv);
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
void gltexenvf_uh(args_glTexEnvf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexEnvf);
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
void gltexenvi_uh(args_glTexEnvi argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexEnvi);
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
void gltexenvfv_uh(args_glTexEnvfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexEnvfv);
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
void gltexenviv_uh(args_glTexEnviv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexEnviv);
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
void glgettexenvfv_uh(args_glGetTexEnvfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetTexEnvfv);
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
void glgettexenviv_uh(args_glGetTexEnviv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetTexEnviv);
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
void gltexparameterf_uh(args_glTexParameterf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexParameterf);
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
void gltexparameteri_uh(args_glTexParameteri argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexParameteri);
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
void gltexparameterfv_uh(args_glTexParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexParameterfv);
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
void gltexparameteriv_uh(args_glTexParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexParameteriv);
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
void glgettexparameterfv_uh(args_glGetTexParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetTexParameterfv);
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
void glgettexparameteriv_uh(args_glGetTexParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetTexParameteriv);
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
void glgettexlevelparameterfv_uh(args_glGetTexLevelParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetTexLevelParameterfv);
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
void glgettexlevelparameteriv_uh(args_glGetTexLevelParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetTexLevelParameteriv);
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
void glteximage1d_uh(args_glTexImage1D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexImage1D);
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
void glteximage2d_uh(args_glTexImage2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexImage2D);
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
void glgetteximage_uh(args_glGetTexImage argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetTexImage);
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
void glgentextures_uh(args_glGenTextures argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGenTextures);
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
void gldeletetextures_uh(args_glDeleteTextures argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glDeleteTextures);
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
void glbindtexture_uh(args_glBindTexture argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glBindTexture);
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
void glprioritizetextures_uh(args_glPrioritizeTextures argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPrioritizeTextures);
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
GLboolean glaretexturesresident_uh(args_glAreTexturesResident argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glAreTexturesResident);
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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glIsTexture
GLboolean glistexture_uh(args_glIsTexture argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glIsTexture);
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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glTexSubImage1D
void gltexsubimage1d_uh(args_glTexSubImage1D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexSubImage1D);
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
void gltexsubimage2d_uh(args_glTexSubImage2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexSubImage2D);
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
void glcopyteximage1d_uh(args_glCopyTexImage1D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCopyTexImage1D);
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
void glcopyteximage2d_uh(args_glCopyTexImage2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCopyTexImage2D);
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
void glcopytexsubimage1d_uh(args_glCopyTexSubImage1D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCopyTexSubImage1D);
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
void glcopytexsubimage2d_uh(args_glCopyTexSubImage2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCopyTexSubImage2D);
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
void glmap1d_uh(args_glMap1d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMap1d);
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
void glmap1f_uh(args_glMap1f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMap1f);
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
void glmap2d_uh(args_glMap2d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMap2d);
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
void glmap2f_uh(args_glMap2f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMap2f);
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
void glgetmapdv_uh(args_glGetMapdv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetMapdv);
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
void glgetmapfv_uh(args_glGetMapfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetMapfv);
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
void glgetmapiv_uh(args_glGetMapiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetMapiv);
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
void glevalcoord1d_uh(args_glEvalCoord1d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEvalCoord1d);
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
void glevalcoord1f_uh(args_glEvalCoord1f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEvalCoord1f);
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
void glevalcoord1dv_uh(args_glEvalCoord1dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEvalCoord1dv);
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
void glevalcoord1fv_uh(args_glEvalCoord1fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEvalCoord1fv);
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
void glevalcoord2d_uh(args_glEvalCoord2d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEvalCoord2d);
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
void glevalcoord2f_uh(args_glEvalCoord2f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEvalCoord2f);
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
void glevalcoord2dv_uh(args_glEvalCoord2dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEvalCoord2dv);
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
void glevalcoord2fv_uh(args_glEvalCoord2fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEvalCoord2fv);
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
void glmapgrid1d_uh(args_glMapGrid1d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMapGrid1d);
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
void glmapgrid1f_uh(args_glMapGrid1f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMapGrid1f);
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
void glmapgrid2d_uh(args_glMapGrid2d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMapGrid2d);
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
void glmapgrid2f_uh(args_glMapGrid2f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMapGrid2f);
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
void glevalpoint1_uh(args_glEvalPoint1 argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEvalPoint1);
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
void glevalpoint2_uh(args_glEvalPoint2 argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEvalPoint2);
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
void glevalmesh1_uh(args_glEvalMesh1 argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEvalMesh1);
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
void glevalmesh2_uh(args_glEvalMesh2 argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glEvalMesh2);
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
void glfogf_uh(args_glFogf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glFogf);
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
void glfogi_uh(args_glFogi argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glFogi);
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
void glfogfv_uh(args_glFogfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glFogfv);
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
void glfogiv_uh(args_glFogiv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glFogiv);
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
void glfeedbackbuffer_uh(args_glFeedbackBuffer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glFeedbackBuffer);
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
void glpassthrough_uh(args_glPassThrough argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPassThrough);
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
void glselectbuffer_uh(args_glSelectBuffer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glSelectBuffer);
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
void glloadname_uh(args_glLoadName argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glLoadName);
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
void glpushname_uh(args_glPushName argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glPushName);
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
void gldrawrangeelements_uh(args_glDrawRangeElements argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glDrawRangeElements);
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
void glteximage3d_uh(args_glTexImage3D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexImage3D);
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
void gltexsubimage3d_uh(args_glTexSubImage3D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glTexSubImage3D);
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
void glcopytexsubimage3d_uh(args_glCopyTexSubImage3D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCopyTexSubImage3D);
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
void glcolortable_uh(args_glColorTable argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColorTable);
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
void glcolorsubtable_uh(args_glColorSubTable argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColorSubTable);
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
void glcolortableparameteriv_uh(args_glColorTableParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColorTableParameteriv);
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
void glcolortableparameterfv_uh(args_glColorTableParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glColorTableParameterfv);
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
void glcopycolorsubtable_uh(args_glCopyColorSubTable argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCopyColorSubTable);
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
void glcopycolortable_uh(args_glCopyColorTable argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCopyColorTable);
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
void glgetcolortable_uh(args_glGetColorTable argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetColorTable);
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
void glgetcolortableparameterfv_uh(args_glGetColorTableParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetColorTableParameterfv);
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
void glgetcolortableparameteriv_uh(args_glGetColorTableParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetColorTableParameteriv);
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
void glblendequation_uh(args_glBlendEquation argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glBlendEquation);
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
void glblendcolor_uh(args_glBlendColor argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glBlendColor);
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
void glhistogram_uh(args_glHistogram argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glHistogram);
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
void glresethistogram_uh(args_glResetHistogram argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glResetHistogram);
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
void glgethistogram_uh(args_glGetHistogram argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetHistogram);
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
void glgethistogramparameterfv_uh(args_glGetHistogramParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetHistogramParameterfv);
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
void glgethistogramparameteriv_uh(args_glGetHistogramParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetHistogramParameteriv);
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
void glminmax_uh(args_glMinmax argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMinmax);
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
void glresetminmax_uh(args_glResetMinmax argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glResetMinmax);
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
void glgetminmax_uh(args_glGetMinmax argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetMinmax);
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
void glgetminmaxparameterfv_uh(args_glGetMinmaxParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetMinmaxParameterfv);
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
void glgetminmaxparameteriv_uh(args_glGetMinmaxParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetMinmaxParameteriv);
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
void glconvolutionfilter1d_uh(args_glConvolutionFilter1D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glConvolutionFilter1D);
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
void glconvolutionfilter2d_uh(args_glConvolutionFilter2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glConvolutionFilter2D);
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
void glconvolutionparameterf_uh(args_glConvolutionParameterf argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glConvolutionParameterf);
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
void glconvolutionparameterfv_uh(args_glConvolutionParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glConvolutionParameterfv);
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
void glconvolutionparameteri_uh(args_glConvolutionParameteri argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glConvolutionParameteri);
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
void glconvolutionparameteriv_uh(args_glConvolutionParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glConvolutionParameteriv);
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
void glcopyconvolutionfilter1d_uh(args_glCopyConvolutionFilter1D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCopyConvolutionFilter1D);
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
void glcopyconvolutionfilter2d_uh(args_glCopyConvolutionFilter2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCopyConvolutionFilter2D);
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
void glgetconvolutionfilter_uh(args_glGetConvolutionFilter argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetConvolutionFilter);
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
void glgetconvolutionparameterfv_uh(args_glGetConvolutionParameterfv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetConvolutionParameterfv);
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
void glgetconvolutionparameteriv_uh(args_glGetConvolutionParameteriv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetConvolutionParameteriv);
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
void glseparablefilter2d_uh(args_glSeparableFilter2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glSeparableFilter2D);
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
void glgetseparablefilter_uh(args_glGetSeparableFilter argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetSeparableFilter);
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
void glactivetexture_uh(args_glActiveTexture argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glActiveTexture);
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
void glclientactivetexture_uh(args_glClientActiveTexture argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glClientActiveTexture);
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
void glcompressedteximage1d_uh(args_glCompressedTexImage1D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCompressedTexImage1D);
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
void glcompressedteximage2d_uh(args_glCompressedTexImage2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCompressedTexImage2D);
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
void glcompressedteximage3d_uh(args_glCompressedTexImage3D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCompressedTexImage3D);
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
void glcompressedtexsubimage1d_uh(args_glCompressedTexSubImage1D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCompressedTexSubImage1D);
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
void glcompressedtexsubimage2d_uh(args_glCompressedTexSubImage2D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCompressedTexSubImage2D);
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
void glcompressedtexsubimage3d_uh(args_glCompressedTexSubImage3D argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glCompressedTexSubImage3D);
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
void glgetcompressedteximage_uh(args_glGetCompressedTexImage argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetCompressedTexImage);
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
void glmultitexcoord1d_uh(args_glMultiTexCoord1d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord1d);
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
void glmultitexcoord1dv_uh(args_glMultiTexCoord1dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord1dv);
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
void glmultitexcoord1f_uh(args_glMultiTexCoord1f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord1f);
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
void glmultitexcoord1fv_uh(args_glMultiTexCoord1fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord1fv);
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
void glmultitexcoord1i_uh(args_glMultiTexCoord1i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord1i);
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
void glmultitexcoord1iv_uh(args_glMultiTexCoord1iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord1iv);
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
void glmultitexcoord1s_uh(args_glMultiTexCoord1s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord1s);
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
void glmultitexcoord1sv_uh(args_glMultiTexCoord1sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord1sv);
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
void glmultitexcoord2d_uh(args_glMultiTexCoord2d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord2d);
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
void glmultitexcoord2dv_uh(args_glMultiTexCoord2dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord2dv);
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
void glmultitexcoord2f_uh(args_glMultiTexCoord2f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord2f);
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
void glmultitexcoord2fv_uh(args_glMultiTexCoord2fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord2fv);
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
void glmultitexcoord2i_uh(args_glMultiTexCoord2i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord2i);
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
void glmultitexcoord2iv_uh(args_glMultiTexCoord2iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord2iv);
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
void glmultitexcoord2s_uh(args_glMultiTexCoord2s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord2s);
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
void glmultitexcoord2sv_uh(args_glMultiTexCoord2sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord2sv);
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
void glmultitexcoord3d_uh(args_glMultiTexCoord3d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord3d);
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
void glmultitexcoord3dv_uh(args_glMultiTexCoord3dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord3dv);
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
void glmultitexcoord3f_uh(args_glMultiTexCoord3f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord3f);
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
void glmultitexcoord3fv_uh(args_glMultiTexCoord3fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord3fv);
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
void glmultitexcoord3i_uh(args_glMultiTexCoord3i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord3i);
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
void glmultitexcoord3iv_uh(args_glMultiTexCoord3iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord3iv);
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
void glmultitexcoord3s_uh(args_glMultiTexCoord3s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord3s);
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
void glmultitexcoord3sv_uh(args_glMultiTexCoord3sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord3sv);
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
void glmultitexcoord4d_uh(args_glMultiTexCoord4d argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord4d);
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
void glmultitexcoord4dv_uh(args_glMultiTexCoord4dv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord4dv);
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
void glmultitexcoord4f_uh(args_glMultiTexCoord4f argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord4f);
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
void glmultitexcoord4fv_uh(args_glMultiTexCoord4fv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord4fv);
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
void glmultitexcoord4i_uh(args_glMultiTexCoord4i argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord4i);
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
void glmultitexcoord4iv_uh(args_glMultiTexCoord4iv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord4iv);
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
void glmultitexcoord4s_uh(args_glMultiTexCoord4s argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord4s);
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
void glmultitexcoord4sv_uh(args_glMultiTexCoord4sv argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord4sv);
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

// -- glSampleCoverage
void glsamplecoverage_uh(args_glSampleCoverage argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glSampleCoverage);
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
void glactivetexturearb_uh(args_glActiveTextureARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glActiveTextureARB);
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
void glclientactivetexturearb_uh(args_glClientActiveTextureARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glClientActiveTextureARB);
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
void glmultitexcoord1darb_uh(args_glMultiTexCoord1dARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord1dARB);
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
void glmultitexcoord1dvarb_uh(args_glMultiTexCoord1dvARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord1dvARB);
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
void glmultitexcoord1farb_uh(args_glMultiTexCoord1fARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord1fARB);
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
void glmultitexcoord1fvarb_uh(args_glMultiTexCoord1fvARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord1fvARB);
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
void glmultitexcoord1iarb_uh(args_glMultiTexCoord1iARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord1iARB);
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
void glmultitexcoord1ivarb_uh(args_glMultiTexCoord1ivARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord1ivARB);
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
void glmultitexcoord1sarb_uh(args_glMultiTexCoord1sARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord1sARB);
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
void glmultitexcoord1svarb_uh(args_glMultiTexCoord1svARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord1svARB);
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
void glmultitexcoord2darb_uh(args_glMultiTexCoord2dARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord2dARB);
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
void glmultitexcoord2dvarb_uh(args_glMultiTexCoord2dvARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord2dvARB);
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
void glmultitexcoord2farb_uh(args_glMultiTexCoord2fARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord2fARB);
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
void glmultitexcoord2fvarb_uh(args_glMultiTexCoord2fvARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord2fvARB);
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
void glmultitexcoord2iarb_uh(args_glMultiTexCoord2iARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord2iARB);
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
void glmultitexcoord2ivarb_uh(args_glMultiTexCoord2ivARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord2ivARB);
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
void glmultitexcoord2sarb_uh(args_glMultiTexCoord2sARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord2sARB);
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
void glmultitexcoord2svarb_uh(args_glMultiTexCoord2svARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord2svARB);
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
void glmultitexcoord3darb_uh(args_glMultiTexCoord3dARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord3dARB);
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
void glmultitexcoord3dvarb_uh(args_glMultiTexCoord3dvARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord3dvARB);
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
void glmultitexcoord3farb_uh(args_glMultiTexCoord3fARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord3fARB);
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
void glmultitexcoord3fvarb_uh(args_glMultiTexCoord3fvARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord3fvARB);
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
void glmultitexcoord3iarb_uh(args_glMultiTexCoord3iARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord3iARB);
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
void glmultitexcoord3ivarb_uh(args_glMultiTexCoord3ivARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord3ivARB);
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
void glmultitexcoord3sarb_uh(args_glMultiTexCoord3sARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord3sARB);
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
void glmultitexcoord3svarb_uh(args_glMultiTexCoord3svARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord3svARB);
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
void glmultitexcoord4darb_uh(args_glMultiTexCoord4dARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord4dARB);
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
void glmultitexcoord4dvarb_uh(args_glMultiTexCoord4dvARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord4dvARB);
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
void glmultitexcoord4farb_uh(args_glMultiTexCoord4fARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord4fARB);
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
void glmultitexcoord4fvarb_uh(args_glMultiTexCoord4fvARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord4fvARB);
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
void glmultitexcoord4iarb_uh(args_glMultiTexCoord4iARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord4iARB);
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
void glmultitexcoord4ivarb_uh(args_glMultiTexCoord4ivARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord4ivARB);
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
void glmultitexcoord4sarb_uh(args_glMultiTexCoord4sARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord4sARB);
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
void glmultitexcoord4svarb_uh(args_glMultiTexCoord4svARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glMultiTexCoord4svARB);
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

// -- glXChooseVisual
XVisualInfo* glxchoosevisual_uh(args_glXChooseVisual argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXChooseVisual);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXCHOOSEVISUAL;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

    // ------ Waiting for Server -----

    // Wait for response
    while (ShmPTR->status != RESPONSE)
        ;

    // assert if the message is a function return
    if(ShmPTR->message_type != FUNC_RETURN){
        printf("Message type is not a function return\n");
    }

    // assert if the datatype is correct
    if(ShmPTR->data_type != XVISUALINFOP){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(XVisualInfo*);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    XVisualInfo* result;
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXQueryDrawable
int glxquerydrawable_uh(args_glXQueryDrawable argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXQueryDrawable);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXQUERYDRAWABLE;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXCreateContext
GLXContext glxcreatecontext_uh(args_glXCreateContext argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXCreateContext);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXCREATECONTEXT;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXDestroyContext
void glxdestroycontext_uh(args_glXDestroyContext argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXDestroyContext);
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
void glxswapbuffers_uh(args_glXSwapBuffers argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXSwapBuffers);
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
void glxdestroyglxpixmap_uh(args_glXDestroyGLXPixmap argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXDestroyGLXPixmap);
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
Bool glxqueryextension_uh(args_glXQueryExtension argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXQueryExtension);
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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXQueryVersion
Bool glxqueryversion_uh(args_glXQueryVersion argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXQueryVersion);
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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXIsDirect
Bool glxisdirect_uh(args_glXIsDirect argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXIsDirect);
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
    memcpy(&result, ShmPTR->buffer, ret_size);

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
    memcpy(&result, ShmPTR->buffer, ret_size);

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
    memcpy(&result, ShmPTR->buffer, ret_size);

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
void glxusexfont_uh(args_glXUseXFont argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXUseXFont);
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
char* glxqueryextensionsstring_uh(args_glXQueryExtensionsString argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXQueryExtensionsString);
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
    memcpy(&result, ShmPTR->buffer, ret_size);

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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXDestroyWindow
void glxdestroywindow_uh(args_glXDestroyWindow argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXDestroyWindow);
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
void glxdestroypixmap_uh(args_glXDestroyPixmap argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXDestroyPixmap);
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
void glxdestroypbuffer_uh(args_glXDestroyPbuffer argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXDestroyPbuffer);
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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXGetProcAddressARB
__GLXextFuncPtr glxgetprocaddressarb_uh(args_glXGetProcAddressARB argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXGetProcAddressARB);
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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXGetProcAddress
void* glxgetprocaddress_uh(args_glXGetProcAddress argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXGetProcAddress);
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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXAllocateMemoryNV
void* glxallocatememorynv_uh(args_glXAllocateMemoryNV argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXAllocateMemoryNV);
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
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXFreeMemoryNV
void glxfreememorynv_uh(args_glXFreeMemoryNV argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXFreeMemoryNV);
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
