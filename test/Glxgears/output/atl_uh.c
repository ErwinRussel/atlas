
#include  "atl_header.h"
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <signal.h>
//#include  <criu/criu.h>
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
//    criu_dump();

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
//    criu_init_opts();
//    criu_set_images_dir_fd(fd); /* must be set for dump/restore */
//    criu_set_shell_job(True);
//    criu_set_leave_running(False);
//    criu_set_log_level(4);
//    criu_set_log_file("criu.log");

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

// -- XDisplayWidth
int xdisplaywidth_uh(args_XDisplayWidth argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XDisplayWidth);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XDISPLAYWIDTH;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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

// -- XDisplayHeight
int xdisplayheight_uh(args_XDisplayHeight argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XDisplayHeight);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XDISPLAYHEIGHT;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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

// -- XInternAtom
Atom xinternatom_uh(args_XInternAtom argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XInternAtom);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XINTERNATOM;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

    // ------ Waiting for Server -----

    // Wait for response
    while (ShmPTR->status != RESPONSE)
        ;

    // assert if the message is a function return
    if(ShmPTR->message_type != FUNC_RETURN){
        printf("Message type is not a function return\n");
    }

    // assert if the datatype is correct
    if(ShmPTR->data_type != ATOM){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(Atom);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    Atom result;
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- XChangeProperty
int xchangeproperty_uh(args_XChangeProperty argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XChangeProperty);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XCHANGEPROPERTY;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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

// -- XNextEvent
XEvent xnextevent_uh(args_XNextEvent argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XNextEvent);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XNEXTEVENT;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

    // ------ Waiting for Server -----

    // Wait for response
    while (ShmPTR->status != RESPONSE)
        ;

    // assert if the message is a function return
    if(ShmPTR->message_type != FUNC_RETURN){
        printf("Message type is not a function return\n");
    }

    // assert if the datatype is correct
    if(ShmPTR->data_type != XEVENT){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(XEvent);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    XEvent result;
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- XLookupKeysym
KeySym xlookupkeysym_uh(args_XLookupKeysym argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XLookupKeysym);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XLOOKUPKEYSYM;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

    // ------ Waiting for Server -----

    // Wait for response
    while (ShmPTR->status != RESPONSE)
        ;

    // assert if the message is a function return
    if(ShmPTR->message_type != FUNC_RETURN){
        printf("Message type is not a function return\n");
    }

    // assert if the datatype is correct
    if(ShmPTR->data_type != KEYSYM){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(KeySym);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    KeySym result;
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
}

// -- XLookupString
int xlookupstring_uh(args_XLookupString argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XLookupString);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XLOOKUPSTRING;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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

// -- XDestroyWindow
int xdestroywindow_uh(args_XDestroyWindow argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_XDestroyWindow);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = XDESTROYWINDOW;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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

// -- glGetString
GLubyte* glgetstring_uh(args_glGetString argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glGetString);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLGETSTRING;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

    // ------ Waiting for Server -----

    // Wait for response
    while (ShmPTR->status != RESPONSE)
        ;

    // assert if the message is a function return
    if(ShmPTR->message_type != FUNC_RETURN){
        printf("Message type is not a function return\n");
    }

    // assert if the datatype is correct
    if(ShmPTR->data_type != GLUBYTEP){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(GLubyte*);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
    GLubyte* result;
    memcpy(&result, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result;
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

// -- glXChooseVisual
XVisualInfo glxchoosevisual_uh(args_glXChooseVisual argp)
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

// -- glXMakeCurrent
Bool glxmakecurrent_uh(args_glXMakeCurrent argp)
{
    // Memcopy in Buffer
    int arg_size = sizeof(args_glXMakeCurrent);
    memcpy(ShmPTR->buffer, &argp, arg_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_CALL;
    ShmPTR->data_type = GLXMAKECURRENT;
    ShmPTR->payload_size = arg_size;

    // Set status to REQUEST
    ShmPTR->status = REQUEST;

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

// -- glXQueryExtensionsString
char result_glxExtensionsString[128];
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
    if(ShmPTR->data_type != CHARARR){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = sizeof(char[256]);

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // memcopy into result
//    char result[128];
    memcpy(&result_glxExtensionsString, ShmPTR->buffer, ret_size);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // return
    return result_glxExtensionsString;
}

// -- glXQueryDrawable
void glxquerydrawable_uh(args_glXQueryDrawable argp)
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
    if(ShmPTR->data_type != VOID){
        printf("Payload data type incorrect\n");
    }
    
    // assert if correct payload size
    int ret_size = 0;

    // assert if correct payload size
    if(ShmPTR->payload_size != ret_size){
        printf("Incorrect payload size\n");
    }

    // Nothing to memcopy for void

    // Set status to LISTEN
    ShmPTR->status = LISTEN;

    // Nothing to return
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
