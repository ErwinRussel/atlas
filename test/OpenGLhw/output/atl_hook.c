#include "atl_header.h"
#include "atl_uh.h"

// -- XOpenDisplay
extern Display *XOpenDisplay(_Xconst char *display_name)
{
    args_XOpenDisplay argp;
    
    // Set function specific args
    argp.display_name = display_name;
    
    return xopendisplay_uh(argp);
}

// -- XCreateWindow
extern Window XCreateWindow(Display *display, Window parent, int x, int y, unsigned int width, unsigned int height, unsigned int border_width, int	depth, unsigned int class, Visual *visual, unsigned long valuemask, XSetWindowAttributes *attributes)
{
    args_XCreateWindow argp;
    
    // Set function specific args
    argp.display = display;
	argp.parent = parent;
	argp.x = x;
	argp.y = y;
	argp.width = width;
	argp.height = height;
	argp.border_width = border_width;
	argp.depth = depth;
	argp.class = class;
	argp.visual = visual;
	argp.valuemask = valuemask;
	argp.attributes = attributes;
    
    return xcreatewindow_uh(argp);
}

// -- XMapWindow
extern int XMapWindow(Display *display, Window w)
{
    args_XMapWindow argp;
    
    // Set function specific args
    argp.display = display;
	argp.w = w;
    
    return xmapwindow_uh(argp);
}

// -- XIfEvent
extern int XIfEvent( Display *display, XEvent *event_return, Bool (*predicate)(), XPointer arg )
{
    args_XIfEvent argp;
    
    // Set function specific args
    argp.display = display;
	argp.event_return = event_return;
	argp.predicate = predicate;
	argp.arg = arg;
    
    return xifevent_uh(argp);
}

// -- glClearColor
void glClearColor( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha )
{
    args_glClearColor argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;
	argp.alpha = alpha;

    glclearcolor_uh(argp);
}

// -- glClear
void glClear( GLbitfield mask )
{
    args_glClear argp;

    // Set function specific args
    argp.mask = mask;

    glclear_uh(argp);
}

// -- glFlush
void glFlush()
{
    glflush_uh();
}

// -- glXChooseFBConfig
GLXFBConfig *glXChooseFBConfig(	Display *dpy, int screen, const int *attrib_list, int *nelements)
{
    args_glXChooseFBConfig argp;
    
    // Set function specific args
    argp.dpy = dpy;
	argp.screen = screen;
	argp.attrib_list = attrib_list;
	argp.nelements = nelements;
    
    return glxchoosefbconfig_uh(argp);
}

// -- glXGetVisualFromFBConfig
XVisualInfo *glXGetVisualFromFBConfig(	Display *dpy, GLXFBConfig config)
{
    args_glXGetVisualFromFBConfig argp;
    
    // Set function specific args
    argp.dpy = dpy;
	argp.config = config;
    
    return glxgetvisualfromfbconfig_uh(argp);
}

// -- glXCreateNewContext
GLXContext glXCreateNewContext(	Display *dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct)
{
    args_glXCreateNewContext argp;
    
    // Set function specific args
    argp.dpy = dpy;
	argp.config = config;
	argp.render_type = render_type;
	argp.share_list = share_list;
	argp.direct = direct;
    
    return glxcreatenewcontext_uh(argp);
}

// -- glXCreateWindow
GLXWindow glXCreateWindow(	Display *dpy, GLXFBConfig config, Window win, const int *attrib_list)
{
    args_glXCreateWindow argp;
    
    // Set function specific args
    argp.dpy = dpy;
	argp.config = config;
	argp.win = win;
	argp.attrib_list = attrib_list;
    
    return glxcreatewindow_uh(argp);
}

// -- glXMakeContextCurrent
Bool glXMakeContextCurrent(	Display *display, GLXDrawable draw, GLXDrawable read, GLXContext ctx)
{
    args_glXMakeContextCurrent argp;
    
    // Set function specific args
    argp.display = display;
	argp.draw = draw;
	argp.read = read;
	argp.ctx = ctx;
    
    return glxmakecontextcurrent_uh(argp);
}

// -- glXSwapBuffers
void glXSwapBuffers( Display *dpy, GLXDrawable drawable )
{
    args_glXSwapBuffers argp;

    // Set function specific args
    argp.dpy = dpy;
	argp.drawable = drawable;

    glxswapbuffers_uh(argp);
}
