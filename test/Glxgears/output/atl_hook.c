#include "atl_header.h"
#include "atl_uh.h"
#include <string.h>

// -- XDefaultScreen
extern int XDefaultScreen(Display* display)
{
    args_XDefaultScreen argp;
    
    // Set function specific args
    argp.display = display;
    
    return xdefaultscreen_uh(argp);
}

// -- XDisplayWidth
extern int XDisplayWidth(Display *display, int screen_number)
{
    args_XDisplayWidth argp;
    
    // Set function specific args
    argp.display = display;
	argp.screen_number = screen_number;
    
    return xdisplaywidth_uh(argp);
}

// -- XDisplayHeight
extern int XDisplayHeight(Display *display, int screen_number)
{
    args_XDisplayHeight argp;
    
    // Set function specific args
    argp.display = display;
	argp.screen_number = screen_number;
    
    return xdisplayheight_uh(argp);
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

// -- XOpenDisplay
extern Display *XOpenDisplay(_Xconst char *display_name)
{
    args_XOpenDisplay argp;
    
    // Set function specific args
    argp.display_name = display_name;
    
    return xopendisplay_uh(argp);
}

// -- XCreateColormap
extern Colormap XCreateColormap(Display* display, Window w, Visual*	visual, int	alloc )
{
    args_XCreateColormap argp;
    
    // Set function specific args
    argp.display = display;
	argp.w = w;
	argp.visual = visual;
	argp.alloc = alloc;
    
    return xcreatecolormap_uh(argp);
}

// -- XCreateWindow
extern Window XCreateWindow(Display* display, Window parent, int x, int y, unsigned int width, unsigned int height, unsigned int border_width, int	depth, unsigned int class, Visual* visual, unsigned long valuemask, XSetWindowAttributes* attributes)
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
    // Memcpy because of array
	argp.attributes = *attributes;
    
    return xcreatewindow_uh(argp);
}

// -- XInternAtom
extern Atom XInternAtom(Display *display, _Xconst char *atom_name, Bool only_if_exists)
{
    args_XInternAtom argp;
    
    // Set function specific args
    argp.display = display;
	argp.atom_name = atom_name;
	argp.only_if_exists = only_if_exists;
    
    return xinternatom_uh(argp);
}

// -- XChangeProperty
extern int XChangeProperty(Display *display, Window w, Atom property, Atom type, int format, int mode, _Xconst unsigned char *data, int nelements)
{
    args_XChangeProperty argp;

    // Set function specific args
    argp.display = display;
	argp.w = w;
	argp.property = property;
	argp.type = type;
	argp.format = format;
	argp.mode = mode;
	argp.data = data;
	argp.nelements = nelements;

    return xchangeproperty_uh(argp);
}

// -- XSetNormalHints
extern int XSetNormalHints(Display *display, Window w, XSizeHints *hints)
{
    args_XSetNormalHints argp;
    
    // Set function specific args
    argp.display = display;
	argp.w = w;
	argp.hints = *hints;
    
    return xsetnormalhints_uh(argp);
}

// -- XSetStandardProperties
extern int XSetStandardProperties(Display *display, Window w, _Xconst char *window_name, _Xconst char *icon_name, Pixmap icon_pixmap, char **argv, int argc, XSizeHints *hints)
{
    args_XSetStandardProperties argp;
    
    // Set function specific args
    argp.display = display;
	argp.w = w;
	argp.window_name = *window_name;
	argp.icon_name = *icon_name;
	argp.icon_pixmap = icon_pixmap;
	argp.argv = argv;
	argp.argc = argc;
	argp.hints = *hints;
    
    return xsetstandardproperties_uh(argp);
}

// -- XFree
extern int XFree(void* data)
{
//    args_XFree argp;
//
//    // Set function specific args
//    argp.visinfo = *data;
//
//    return xfree_uh(argp);
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

// -- XPending
extern int XPending(Display *display)
{
    args_XPending argp;
    
    // Set function specific args
    argp.display = display;
    
    return xpending_uh(argp);
}

// -- XNextEvent
int XNextEvent(Display *display, XEvent *event_return)
{
    args_XNextEvent argp;

    // Set function specific args
    argp.display = display;
    argp.event_return = event_return;

    XEvent event = xnextevent_uh(argp);

    *event_return = event;

    return 0;
}

// -- XLookupKeysym
extern KeySym XLookupKeysym(XKeyEvent *key_event, int index)
{
    args_XLookupKeysym argp;
    
    // Set function specific args
    argp.key_event = key_event;
	argp.index = index;
    
    return xlookupkeysym_uh(argp);
}

// -- XLookupString
extern int XLookupString(XKeyEvent *event_struct, char *buffer_return, int bytes_buffer, KeySym *keysym_return, XComposeStatus *status_in_out)
{
    args_XLookupString argp;
    
    // Set function specific args
    argp.event_struct = event_struct;
	argp.buffer_return = buffer_return;
	argp.bytes_buffer = bytes_buffer;
	argp.keysym_return = keysym_return;
	argp.status_in_out = status_in_out;
    
    return xlookupstring_uh(argp);
}

// -- XDestroyWindow
extern int XDestroyWindow(Display *display, Window w)
{
    args_XDestroyWindow argp;
    
    // Set function specific args
    argp.display = display;
	argp.w = w;
    
    return xdestroywindow_uh(argp);
}

// -- glGetString
const GLubyte *glGetString(	GLenum name)
{
    args_glGetString argp;
    
    // Set function specific args
    argp.name = name;
    
    return glgetstring_uh(argp);
}

// -- glLightfv
void glLightfv( GLenum light, GLenum pname, const GLfloat *params )
{
    args_glLightfv argp;

    // Set function specific args
    argp.light = light;
	argp.pname = pname;
    // Memcpy because of arr
    memcpy(argp.params, params, sizeof(params));

    gllightfv_uh(argp);
}

// -- glEnable
void glEnable( GLenum cap )
{
    args_glEnable argp;

    // Set function specific args
    argp.cap = cap;

    glenable_uh(argp);
}

// -- glGenLists
GLuint glGenLists( GLsizei range )
{
    args_glGenLists argp;
    
    // Set function specific args
    argp.range = range;
    
    return glgenlists_uh(argp);
}

// -- glNewList
void glNewList( GLuint list, GLenum mode )
{
    args_glNewList argp;

    // Set function specific args
    argp.list = list;
	argp.mode = mode;

    glnewlist_uh(argp);
}

// -- glMaterialfv
void glMaterialfv( GLenum face, GLenum pname, const GLfloat *params )
{
    args_glMaterialfv argp;

    // Set function specific args
    argp.face = face;
	argp.pname = pname;
    // Memcpy because of arr
    memcpy(argp.params, params, sizeof(params));

    glmaterialfv_uh(argp);
}

// -- glEndList
void glEndList()
{
    glendlist_uh();
}

// -- glShadeModel
void glShadeModel( GLenum mode )
{
    args_glShadeModel argp;

    // Set function specific args
    argp.mode = mode;

    glshademodel_uh(argp);
}

// -- glNormal3f
void glNormal3f( GLfloat nx, GLfloat ny, GLfloat nz )
{
    args_glNormal3f argp;

    // Set function specific args
    argp.nx = nx;
	argp.ny = ny;
	argp.nz = nz;

    glnormal3f_uh(argp);
}

// -- glBegin
void glBegin( GLenum mode )
{
    args_glBegin argp;

    // Set function specific args
    argp.mode = mode;

    glbegin_uh(argp);
}

// -- glVertex3f
void glVertex3f( GLfloat x, GLfloat y, GLfloat z )
{
    args_glVertex3f argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;

    glvertex3f_uh(argp);
}

// -- glEnd
void glEnd()
{
    glend_uh();
}

// -- glViewport
void glViewport( GLint x, GLint y, GLsizei width, GLsizei height )
{
    args_glViewport argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.width = width;
	argp.height = height;

    glviewport_uh(argp);
}

// -- glMatrixMode
void glMatrixMode( GLenum mode )
{
    args_glMatrixMode argp;

    // Set function specific args
    argp.mode = mode;

    glmatrixmode_uh(argp);
}

// -- glLoadIdentity
void glLoadIdentity()
{
    glloadidentity_uh();
}

// -- glFrustum
void glFrustum( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val )
{
    args_glFrustum argp;

    // Set function specific args
    argp.left = left;
	argp.right = right;
	argp.bottom = bottom;
	argp.top = top;
	argp.near_val = near_val;
	argp.far_val = far_val;

    glfrustum_uh(argp);
}

// -- glTranslatef
void glTranslatef( GLfloat x, GLfloat y, GLfloat z )
{
    args_glTranslatef argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;

    gltranslatef_uh(argp);
}

// -- glDrawBuffer
void glDrawBuffer( GLenum mode )
{
    args_glDrawBuffer argp;

    // Set function specific args
    argp.mode = mode;

    gldrawbuffer_uh(argp);
}

// -- glPushMatrix
void glPushMatrix()
{
    glpushmatrix_uh();
}

// -- glPopMatrix
void glPopMatrix()
{
    glpopmatrix_uh();
}

// -- glTranslated
void glTranslated( GLdouble x, GLdouble y, GLdouble z )
{
    args_glTranslated argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;

    gltranslated_uh(argp);
}

// -- glClear
void glClear( GLbitfield mask )
{
    args_glClear argp;

    // Set function specific args
    argp.mask = mask;

    glclear_uh(argp);
}

// -- glRotatef
void glRotatef( GLfloat angle, GLfloat x, GLfloat y, GLfloat z )
{
    args_glRotatef argp;

    // Set function specific args
    argp.angle = angle;
	argp.x = x;
	argp.y = y;
	argp.z = z;

    glrotatef_uh(argp);
}

// -- glCallList
void glCallList( GLuint list )
{
    args_glCallList argp;

    // Set function specific args
    argp.list = list;

    glcalllist_uh(argp);
}

// -- glDeleteLists
void glDeleteLists( GLuint list, GLsizei range )
{
    args_glDeleteLists argp;

    // Set function specific args
    argp.list = list;
	argp.range = range;

    gldeletelists_uh(argp);
}

// -- glXDestroyContext
void glXDestroyContext( Display *dpy, GLXContext ctx )
{
    args_glXDestroyContext argp;

    // Set function specific args
    argp.dpy = dpy;
	argp.ctx = ctx;

    glxdestroycontext_uh(argp);
}

// -- glXChooseVisual
XVisualInfo visualinfo;
XVisualInfo* glXChooseVisual(Display *dpy, int screen, int *attribList)
{
    args_glXChooseVisual argp;
    
    // Set function specific args
    argp.dpy = dpy;
	argp.screen = screen;
    // Memcpy because of array
    memcpy(argp.attribList, attribList, sizeof(attribList));

    visualinfo = glxchoosevisual_uh(argp);

    return &visualinfo;
}

// -- glXCreateContext
GLXContext glXCreateContext(Display *dpy, XVisualInfo *vis, GLXContext shareList, Bool direct)
{
    args_glXCreateContext argp;
    
    // Set function specific args
    argp.dpy = dpy;
	argp.vis = *vis;
	argp.shareList = shareList;
	argp.direct = direct;
    
    return glxcreatecontext_uh(argp);
}

// -- glXMakeCurrent
Bool glXMakeCurrent(Display * dpy, GLXDrawable drawable, GLXContext ctx)
{
    args_glXMakeCurrent argp;
    
    // Set function specific args
    argp.dpy = dpy;
	argp.drawable = drawable;
	argp.ctx = ctx;
    
    return glxmakecurrent_uh(argp);
}

// -- glXQueryExtensionsString
const char* glxExtensionsString;
const char *glXQueryExtensionsString( Display *dpy, int screen )
{
    args_glXQueryExtensionsString argp;
    
    // Set function specific args
    argp.dpy = dpy;
	argp.screen = screen;

    const char* glxExtensionsString = glxqueryextensionsstring_uh(argp);
    
    return glxExtensionsString;
}

// -- glXQueryDrawable
extern void glXQueryDrawable(Display *dpy, GLXDrawable draw, int attribute, unsigned int *value)
{
    args_glXQueryDrawable argp;

    // Set function specific args
    argp.dpy = dpy;
	argp.draw = draw;
	argp.attribute = attribute;
	argp.value = *value;

    glxquerydrawable_uh(argp);
}

// -- glXGetProcAddressARB
extern __GLXextFuncPtr glXGetProcAddressARB (const GLubyte *procname)
{
    args_glXGetProcAddressARB argp;
    
    // Set function specific args
    argp.procname = procname;
    
    return glxgetprocaddressarb_uh(argp);
}

// -- glXSwapBuffers
void glXSwapBuffers( Display *dpy, GLXDrawable drawable ){
    args_glXSwapBuffers argp;

    // Set function specific args
    argp.dpy = dpy;
	argp.drawable = drawable;

    glxswapbuffers_uh(argp);
}
