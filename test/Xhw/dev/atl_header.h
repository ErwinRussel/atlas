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
    XOPENDISPLAY,
	DISPLAYP,
	XCREATESIMPLEWINDOW,
	WINDOW,
	XMAPWINDOW,
	INT,
	XSELECTINPUT,
	XNEXTEVENT,
	XEVENT,
	XDEFAULTROOTWINDOW
} data_types;

// Create messageblock after declaration of data_types
struct MsgBlock {
    int  status;
    message_types message_type;
    data_types data_type;
    int payload_size;
    char buffer[SHMEM_BUFF];
};

// Strgblock --> same as msgblock but without the status flag
struct StrgBlock {
    message_types message_type;
    data_types data_type;
    int payload_size;
    char buffer[SHMEM_BUFF];
};

// Function arg structs


// -- XOpenDisplay
struct args_XOpenDisplay{
    _Xconst char *display_name;
};

typedef struct args_XOpenDisplay args_XOpenDisplay;


// -- XCreateSimpleWindow
struct args_XCreateSimpleWindow{
    Display *display;
	 Window parent;
	 int x;
	 int y;
	 unsigned int width;
	 unsigned int height;
	 unsigned int border_width;
	 unsigned long border;
	 unsigned long background;
};

typedef struct args_XCreateSimpleWindow args_XCreateSimpleWindow;


// -- XMapWindow
struct args_XMapWindow{
    Display *display;
	 Window w;
};

typedef struct args_XMapWindow args_XMapWindow;


// -- XSelectInput
struct args_XSelectInput{
    Display *display;
	 Window w;
	 long event_mask;
};

typedef struct args_XSelectInput args_XSelectInput;


// -- XNextEvent
struct args_XNextEvent{
    Display *display;
	 XEvent *event_return;
};

typedef struct args_XNextEvent args_XNextEvent;


// -- XDefaultRootWindow
struct args_XDefaultRootWindow{
    Display *display;
};

typedef struct args_XDefaultRootWindow args_XDefaultRootWindow;

