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
	XCREATEWINDOW,
	WINDOW,
	XMAPWINDOW,
	INT,
	XIFEVENT,
	GLCLEARCOLOR,
	VOID,
	GLCLEAR,
	GLFLUSH,
	GLXCHOOSEFBCONFIG,
	GLXFBCONFIGP,
	GLXGETVISUALFROMFBCONFIG,
	XVISUALINFOP,
	GLXCREATENEWCONTEXT,
	GLXCONTEXT,
	GLXCREATEWINDOW,
	GLXWINDOW,
	GLXMAKECONTEXTCURRENT,
	BOOL,
	GLXSWAPBUFFERS
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


// -- XOpenDisplay
struct args_XOpenDisplay{
    _Xconst char *display_name;
};

typedef struct args_XOpenDisplay args_XOpenDisplay;


// -- XCreateWindow
struct args_XCreateWindow{
    Display *display;
	 Window parent;
	 int x;
	 int y;
	 unsigned int width;
	 unsigned int height;
	 unsigned int border_width;
	 int	depth;
	 unsigned int class;
	 Visual *visual;
	 unsigned long valuemask;
	 XSetWindowAttributes *attributes;
};

typedef struct args_XCreateWindow args_XCreateWindow;


// -- XMapWindow
struct args_XMapWindow{
    Display *display;
	 Window w;
};

typedef struct args_XMapWindow args_XMapWindow;


// -- XIfEvent
struct args_XIfEvent{
     Display *display;
	 XEvent *event_return;
     Bool (*predicate)();
	 XPointer arg ;
};

typedef struct args_XIfEvent args_XIfEvent;


// -- glClearColor
struct args_glClearColor{
     GLclampf red;
	 GLclampf green;
	 GLclampf blue;
	 GLclampf alpha ;
};

typedef struct args_glClearColor args_glClearColor;


// -- glClear
struct args_glClear{
     GLbitfield mask ;
};

typedef struct args_glClear args_glClear;


// -- glXChooseFBConfig
struct args_glXChooseFBConfig{
    	Display *dpy;
	 int screen;
	 const int *attrib_list;
	 int *nelements;
};

typedef struct args_glXChooseFBConfig args_glXChooseFBConfig;


// -- glXGetVisualFromFBConfig
struct args_glXGetVisualFromFBConfig{
    	Display *dpy;
	 GLXFBConfig config;
};

typedef struct args_glXGetVisualFromFBConfig args_glXGetVisualFromFBConfig;


// -- glXCreateNewContext
struct args_glXCreateNewContext{
    	Display *dpy;
	 GLXFBConfig config;
	 int render_type;
	 GLXContext share_list;
	 Bool direct;
};

typedef struct args_glXCreateNewContext args_glXCreateNewContext;


// -- glXCreateWindow
struct args_glXCreateWindow{
    	Display *dpy;
	 GLXFBConfig config;
	 Window win;
	 const int *attrib_list;
};

typedef struct args_glXCreateWindow args_glXCreateWindow;


// -- glXMakeContextCurrent
struct args_glXMakeContextCurrent{
    	Display *display;
	 GLXDrawable draw;
	 GLXDrawable read;
	 GLXContext ctx;
};

typedef struct args_glXMakeContextCurrent args_glXMakeContextCurrent;


// -- glXSwapBuffers
struct args_glXSwapBuffers{
     Display *dpy;
	 GLXDrawable drawable ;
};

typedef struct args_glXSwapBuffers args_glXSwapBuffers;

