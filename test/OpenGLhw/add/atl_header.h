#ifndef ATLAS_STUB_HEADER_H
#define ATLAS_STUB_HEADER_H

#endif //ATLAS_STUB_HEADER_H

#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glx.h>

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

typedef enum {
    XCREATECOLORMAP,
	COLORMAP
} data_types;

// Create messageblock after declaration of data_types
struct MsgBlock {
    int  status;
    message_types message_type;
    data_types data_type;
    int payload_size;
    char buffer[SHMEM_BUFF];
};

// Function arg structs


// -- XCreateColormap
struct args_XCreateColormap{
    Display *display;
	 Window w;
	 Visual *visual;
	 int alloc;
};

typedef struct args_XCreateColormap args_XCreateColormap;

