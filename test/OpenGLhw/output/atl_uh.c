
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

// -- XRootWindow
Window xrootwindow_uh(args_XRootWindow argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XRootWindow);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XROOTWINDOW;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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

// -- XIfEvent
int xifevent_uh(args_XIfEvent argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XIfEvent);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XIFEVENT;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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

// -- XDefaultScreen
int xdefaultscreen_uh(args_XDefaultScreen argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XDefaultScreen);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XDEFAULTSCREEN;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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

// -- glXChooseFBConfig
GLXFBConfig glxchoosefbconfig_uh(args_glXChooseFBConfig argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXChooseFBConfig);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXCHOOSEFBCONFIG;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

    // ------ Waiting for Server -----

    // Wait for response
    while (ShmPTR->status != RESPONSE)
        ;

    // assert if the message is a function return
    if(ShmPTR->message_type != FUNC_RETURN){
        printf("Message type is not a function return\n");
    }

    // assert if the datatype is correct
    if(ShmPTR->data_type != GLXFBCONFIG){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(GLXFBConfig);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    GLXFBConfig result;
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXGetVisualFromFBConfig
XVisualInfo glxgetvisualfromfbconfig_uh(args_glXGetVisualFromFBConfig argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXGetVisualFromFBConfig);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXGETVISUALFROMFBCONFIG;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

    // ------ Waiting for Server -----

    // Wait for response
    while (ShmPTR->status != RESPONSE)
        ;

    // assert if the message is a function return
    if(ShmPTR->message_type != FUNC_RETURN){
        printf("Message type is not a function return\n");
    }

    // assert if the datatype is correct
    if(ShmPTR->data_type != XVISUALINFO){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(XVisualInfo);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    XVisualInfo result;
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXCreateNewContext
GLXContext glxcreatenewcontext_uh(args_glXCreateNewContext argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXCreateNewContext);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXCREATENEWCONTEXT;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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

// -- glXCreateWindow
GLXWindow glxcreatewindow_uh(args_glXCreateWindow argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXCreateWindow);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXCREATEWINDOW;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

    // ------ Waiting for Server -----

    // Wait for response
    while (ShmPTR->status != RESPONSE)
        ;

    // assert if the message is a function return
    if(ShmPTR->message_type != FUNC_RETURN){
        printf("Message type is not a function return\n");
    }

    // assert if the datatype is correct
    if(ShmPTR->data_type != GLXWINDOW){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(GLXWindow);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    GLXWindow result;
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- glXMakeContextCurrent
Bool glxmakecontextcurrent_uh(args_glXMakeContextCurrent argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXMakeContextCurrent);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXMAKECONTEXTCURRENT;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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
