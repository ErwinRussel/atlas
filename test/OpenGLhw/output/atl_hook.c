#include "atl_header.h"
#include "atl_uh.h"
#include <string.h>
#include <stdio.h>

// -- XOpenDisplay
extern Display *XOpenDisplay(_Xconst char *display_name)
{
    args_XOpenDisplay argp;
    
    // Set function specific args
    argp.display_name = display_name;
    
    return xopendisplay_uh(argp);
}

// -- XRootWindow
extern Window XRootWindow(Display *display, int screen_number)
{
    args_XRootWindow argp;

    // Set function specific args
    argp.display = display;
    argp.screen_number = screen_number;

    return xrootwindow_uh(argp);
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
	argp.attributes = *attributes;
    
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

// -- XIfEvent -- We do nothing with this event
extern int XIfEvent( Display *display, XEvent *event_return, Bool (*predicate)(), XPointer arg )
{
    args_XIfEvent argp;
    
    // Set function specific args
    argp.display = display;
	argp.event_return = event_return;
	argp.predicate = predicate;
    printf("So far so good..\n");
	argp.arg = arg;
    printf("That shouldve worked\n");
    
    return xifevent_uh(argp);
}

// -- XDefaultScreen
extern int XDefaultScreen(Display* display)
{
    args_XDefaultScreen argp;
    
    // Set function specific args
    argp.display = display;
    
    return xdefaultscreen_uh(argp);
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
GLXFBConfig config;
GLXFBConfig *glXChooseFBConfig(	Display *dpy, int screen, const int *attrib_list, int *nelements)
{
    args_glXChooseFBConfig argp;
    
    // Set function specific args
    argp.dpy = dpy;
	argp.screen = screen;
//	argp.attrib_list = attrib_list;
    // memcpy because of array
    memcpy(argp.attrib_list, attrib_list, sizeof(attrib_list));
	argp.nelements = *nelements;

    // Return pointer from set
    config = glxchoosefbconfig_uh(argp);
    
    return &config;
}

// -- glXGetVisualFromFBConfig
XVisualInfo visualinfo;
XVisualInfo* glXGetVisualFromFBConfig(Display *dpy, GLXFBConfig config)
{
    args_glXGetVisualFromFBConfig argp;

    // Set function specific args
    argp.dpy = dpy;
	argp.config = config;

    visualinfo = glxgetvisualfromfbconfig_uh(argp);

    return &visualinfo;
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

// -- XCreateColormap
Colormap XCreateColormap(Display *display, Window w, Visual *visual, int alloc){
    args_XCreateColormap argp;

    // Set function specific args
    argp.display = display;
    argp.w = w;
    argp.visual = visual;
    argp.alloc = alloc;

    return xcreatecolormap_uh(argp);
}
