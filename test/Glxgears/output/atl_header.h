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
    DEFAULTSCREEN,
	INT,
	DISPLAYWIDTH,
	DISPLAYHEIGHT,
	ROOTWINDOW,
	WINDOW,
	XOPENDISPLAY,
	DISPLAYP,
	XCREATECOLORMAP,
	COLORMAP,
	XCREATEWINDOW,
	XINTERNATOM,
	ATOM,
	XCHANGEPROPERTY,
	XSETNORMALHINTS,
	XSETSTANDARDPROPERTIES,
	XFREE,
	XMAPWINDOW,
	XPENDING,
	XNEXTEVENT,
	XEVENT,
	XLOOKUPKEYSYM,
	KEYSYM,
	XLOOKUPSTRING,
	XDESTROYWINDOW,
	XDESTROYWINDOW,
	GLGETSTRING,
	GLUBYTEP,
	GLLIGHTFV,
	VOID,
	GLENABLE,
	GLGENLISTS,
	GLUINT,
	GLNEWLIST,
	GLMATERIALFV,
	GLENDLIST,
	GLSHADEMODEL,
	GLNORMAL3F,
	GLBEGIN,
	GLVERTEX3F,
	GLEND,
	GLVIEWPORT,
	GLMATRIXMODE,
	GLLOADIDENTITY,
	GLFRUSTUM,
	GLTRANSLATEF,
	GLDRAWBUFFER,
	GLPUSHMATRIX,
	GLPOPMATRIX,
	GLTRANSLATED,
	GLCLEAR,
	GLROTATEF,
	GLCALLLIST,
	GLDELETELISTS,
	GLXDESTROYCONTEXT,
	GLXCHOOSEVISUAL,
	XVISUALINFOP,
	GLXCREATECONTEXT,
	GLXCONTEXT,
	GLXMAKECURRENT,
	BOOL,
	GLXQUERYEXTENSIONSSTRING,
	CHARP,
	GLXQUERYDRAWABLE,
	GLXGETPROCADDRESSARB,
	__GLXEXTFUNCPTR,
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


// -- DefaultScreen
struct args_DefaultScreen{
    Display *display;
};

typedef struct args_DefaultScreen args_DefaultScreen;


// -- DisplayWidth
struct args_DisplayWidth{
    Display *display;
	 int screen_number;
};

typedef struct args_DisplayWidth args_DisplayWidth;


// -- DisplayHeight
struct args_DisplayHeight{
    Display *display;
	 int screen_number;
};

typedef struct args_DisplayHeight args_DisplayHeight;


// -- RootWindow
struct args_RootWindow{
    Display *display;
	 int screen_number;
};

typedef struct args_RootWindow args_RootWindow;


// -- XOpenDisplay
struct args_XOpenDisplay{
    _Xconst char *display_name;
};

typedef struct args_XOpenDisplay args_XOpenDisplay;


// -- XCreateColormap
struct args_XCreateColormap{
    Display* display;
	 Window w;
	 Visual*	visual;
	 int	alloc ;
};

typedef struct args_XCreateColormap args_XCreateColormap;


// -- XCreateWindow
struct args_XCreateWindow{
    Display* display;
	 Window parent;
	 int x;
	 int y;
	 unsigned int width;
	 unsigned int height;
	 unsigned int border_width;
	 int	depth;
	 unsigned int class;
	 Visual* visual;
	 unsigned long valuemask;
	 XSetWindowAttributes* attributes;
};

typedef struct args_XCreateWindow args_XCreateWindow;


// -- XInternAtom
struct args_XInternAtom{
    Display *display;
	 char *atom_name;
	 Bool only_if_exists;
};

typedef struct args_XInternAtom args_XInternAtom;


// -- XChangeProperty
struct args_XChangeProperty{
    Display *display;
	 Window w;
	 Atom property;
	 Atom type;
	 int format;
	 int mode;
	 unsigned char *data;
	 int nelements;
};

typedef struct args_XChangeProperty args_XChangeProperty;


// -- XSetNormalHints
struct args_XSetNormalHints{
    Display *display;
	 Window w;
	 XSizeHints *hints;
};

typedef struct args_XSetNormalHints args_XSetNormalHints;


// -- XSetStandardProperties
struct args_XSetStandardProperties{
    Display *display;
	 Window w;
	 _Xconst char *window_name;
	 _Xconst char *icon_name;
	 Pixmap icon_pixmap;
	 char **argv;
	 int argc;
	 XSizeHints *hints;
};

typedef struct args_XSetStandardProperties args_XSetStandardProperties;


// -- XFree
struct args_XFree{
    void* data;
};

typedef struct args_XFree args_XFree;


// -- XMapWindow
struct args_XMapWindow{
    Display *display;
	 Window w;
};

typedef struct args_XMapWindow args_XMapWindow;


// -- XPending
struct args_XPending{
    Display *display;
};

typedef struct args_XPending args_XPending;


// -- XNextEvent
struct args_XNextEvent{
    Display *display;
	 XEvent *event_return;
};

typedef struct args_XNextEvent args_XNextEvent;


// -- XLookupKeysym
struct args_XLookupKeysym{
    XKeyEvent *key_event;
	 int index;
};

typedef struct args_XLookupKeysym args_XLookupKeysym;


// -- XLookupString
struct args_XLookupString{
    XKeyEvent *event_struct;
	 char *buffer_return;
	 int bytes_buffer;
	 KeySym *keysym_return;
	 XComposeStatus *status_in_out;
};

typedef struct args_XLookupString args_XLookupString;


// -- XDestroyWindow
struct args_XDestroyWindow{
    Display *display;
	 Window w;
};

typedef struct args_XDestroyWindow args_XDestroyWindow;


// -- XDestroyWindow
struct args_XDestroyWindow{
    Display* display;
	 Window w;
};

typedef struct args_XDestroyWindow args_XDestroyWindow;


// -- glGetString
struct args_glGetString{
    	GLenum name;
};

typedef struct args_glGetString args_glGetString;


// -- glLightfv
struct args_glLightfv{
     GLenum light;
	 GLenum pname;
	 const GLfloat *params ;
};

typedef struct args_glLightfv args_glLightfv;


// -- glEnable
struct args_glEnable{
     GLenum cap ;
};

typedef struct args_glEnable args_glEnable;


// -- glGenLists
struct args_glGenLists{
     GLsizei range ;
};

typedef struct args_glGenLists args_glGenLists;


// -- glNewList
struct args_glNewList{
     GLuint list;
	 GLenum mode ;
};

typedef struct args_glNewList args_glNewList;


// -- glMaterialfv
struct args_glMaterialfv{
     GLenum face;
	 GLenum pname;
	 const GLfloat *params ;
};

typedef struct args_glMaterialfv args_glMaterialfv;


// -- glShadeModel
struct args_glShadeModel{
     GLenum mode ;
};

typedef struct args_glShadeModel args_glShadeModel;


// -- glNormal3f
struct args_glNormal3f{
     GLfloat nx;
	 GLfloat ny;
	 GLfloat nz ;
};

typedef struct args_glNormal3f args_glNormal3f;


// -- glBegin
struct args_glBegin{
     GLenum mode ;
};

typedef struct args_glBegin args_glBegin;


// -- glVertex3f
struct args_glVertex3f{
     GLfloat x;
	 GLfloat y;
	 GLfloat z ;
};

typedef struct args_glVertex3f args_glVertex3f;


// -- glViewport
struct args_glViewport{
     GLint x;
	 GLint y;
	 GLsizei width;
	 GLsizei height ;
};

typedef struct args_glViewport args_glViewport;


// -- glMatrixMode
struct args_glMatrixMode{
     GLenum mode ;
};

typedef struct args_glMatrixMode args_glMatrixMode;


// -- glFrustum
struct args_glFrustum{
     GLdouble left;
	 GLdouble right;
	 GLdouble bottom;
	 GLdouble top;
	 GLdouble near_val;
	 GLdouble far_val ;
};

typedef struct args_glFrustum args_glFrustum;


// -- glTranslatef
struct args_glTranslatef{
     GLfloat x;
	 GLfloat y;
	 GLfloat z ;
};

typedef struct args_glTranslatef args_glTranslatef;


// -- glDrawBuffer
struct args_glDrawBuffer{
     GLenum mode ;
};

typedef struct args_glDrawBuffer args_glDrawBuffer;


// -- glTranslated
struct args_glTranslated{
     GLdouble x;
	 GLdouble y;
	 GLdouble z ;
};

typedef struct args_glTranslated args_glTranslated;


// -- glClear
struct args_glClear{
     GLbitfield mask ;
};

typedef struct args_glClear args_glClear;


// -- glRotatef
struct args_glRotatef{
     GLfloat angle;
	 GLfloat x;
	 GLfloat y;
	 GLfloat z ;
};

typedef struct args_glRotatef args_glRotatef;


// -- glCallList
struct args_glCallList{
     GLuint list ;
};

typedef struct args_glCallList args_glCallList;


// -- glDeleteLists
struct args_glDeleteLists{
     GLuint list;
	 GLsizei range ;
};

typedef struct args_glDeleteLists args_glDeleteLists;


// -- glXDestroyContext
struct args_glXDestroyContext{
     Display *dpy;
	 GLXContext ctx ;
};

typedef struct args_glXDestroyContext args_glXDestroyContext;


// -- glXChooseVisual
struct args_glXChooseVisual{
    Display *dpy;
	 int screen;
	 int *attribList;
};

typedef struct args_glXChooseVisual args_glXChooseVisual;


// -- glXCreateContext
struct args_glXCreateContext{
    Display *dpy;
	 XVisualInfo *vis;
	 GLXContext shareList;
	 Bool direct;
};

typedef struct args_glXCreateContext args_glXCreateContext;


// -- glXMakeCurrent
struct args_glXMakeCurrent{
    Display * dpy;
	 GLXDrawable drawable;
	 GLXContext ctx;
};

typedef struct args_glXMakeCurrent args_glXMakeCurrent;


// -- glXQueryExtensionsString
struct args_glXQueryExtensionsString{
     Display *dpy;
	 int screen ;
};

typedef struct args_glXQueryExtensionsString args_glXQueryExtensionsString;


// -- glXQueryDrawable
struct args_glXQueryDrawable{
    Display *dpy;
	 GLXDrawable draw;
	 int attribute;
	 unsigned int *value;
};

typedef struct args_glXQueryDrawable args_glXQueryDrawable;


// -- glXGetProcAddressARB
struct args_glXGetProcAddressARB{
    const GLubyte *procname;
};

typedef struct args_glXGetProcAddressARB args_glXGetProcAddressARB;


// -- glXSwapBuffers
struct args_glXSwapBuffers{
     Display *dpy;
	 GLXDrawable drawable ;
};

typedef struct args_glXSwapBuffers args_glXSwapBuffers;

