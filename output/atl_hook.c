#include "atl_header.h"

// -- XOpenDisplay
extern Display *XOpenDisplay(_Xconst char *display_name)
{
    argp_XOpenDisplay argp;
    
    // Set function specific args
    argp.display_name = display_name
    
    return xopendisplay_uh(&argp)
}

// -- XCreateSimpleWindow
Window XCreateSimpleWindow(Display *display, Window parent, int x, int y, unsigned int width, unsigned int height, unsigned int border_width, unsigned long border, unsigned long background)
{
    argp_XCreateSimpleWindow argp;
    
    // Set function specific args
    argp.display = display;
	argp.parent = parent;
	argp.x = x;
	argp.y = y;
	argp.width = width;
	argp.height = height;
	argp.border_width = border_width;
	argp.border = border;
	argp.background = background
    
    return xcreatesimplewindow_uh(&argp)
}

// -- XMapWindow
int XMapWindow(Display *display, Window w)
{
    argp_XMapWindow argp;
    
    // Set function specific args
    argp.display = display;
	argp.w = w
    
    return xmapwindow_uh(&argp)
}

// -- XSelectInput
int XSelectInput(Display *display, Window w, long event_mask)
{
    argp_XSelectInput argp;
    
    // Set function specific args
    argp.display = display;
	argp.w = w;
	argp.event_mask = event_mask
    
    return xselectinput_uh(&argp)
}

// -- XNextEvent
int XNextEvent(Display *display, XEvent *event_return) || XEvent
{
    argp_XNextEvent argp;
    
    // Set function specific args
    argp.display = display;
	argp.event_return = event_return
    
    return xnextevent_uh(&argp)
}

// -- XDefaultRootWindow
Window XDefaultRootWindow(Display *display)
{
    argp_XDefaultRootWindow argp;
    
    // Set function specific args
    argp.display = display
    
    return xdefaultrootwindow_uh(&argp)
}
