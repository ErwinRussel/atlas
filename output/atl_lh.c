
#include  "atl_header.h"
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

// Global pointers to use from init
key_t           ShmKEY;
int             ShmID;
struct MsgBlock *ShmPTR;

// Constructor
void init(){
    // Bind to the shared memory file
    ShmKEY = ftok(".", 'x');

    // Get SysV ID for block to use with shmat etc.
    ShmID = shmget(ShmKEY, sizeof(struct MsgBlock), IPC_CREAT | 0666);
    if (ShmID < 0) {
        printf("*** shmget error (server) ***\n");
        exit(1);
    }

    // Attach to pointer
    ShmPTR = (struct MsgBlock *) shmat(ShmID, NULL, 0);

    // Set status to LISTEN
    ShmPTR->status = LISTEN;
}

// -- XOpenDisplay
Display* *xopendisplay_lh(args_XOpenDisplay *argp)
{
    // Get function specific args
    _Xconst char *display_name = argp->display_name;;

    // Call actual function
    Display* result = XOpenDisplay(display_name);

    // Memcopy in Buffer
    int ret_size = sizeof(Display*);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = DISPLAYP;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- XMapWindow
int *xmapwindow_lh(args_XMapWindow *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 Window w = argp->w;;

    // Call actual function
    int result = XMapWindow(display, w);

    // Memcopy in Buffer
    int ret_size = sizeof(int);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = INT;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- XCreateColormap
Colormap *xcreatecolormap_lh(args_XCreateColormap *argp)
{
    // Get function specific args
    Display* display = argp->display;;
	 Window w = argp->w;;
	 Visual*	visual = argp->visual;;
	 int	alloc  = argp->alloc;;

    // Call actual function
    Colormap result = XCreateColormap(display, w, visual, alloc);

    // Memcopy in Buffer
    int ret_size = sizeof(Colormap);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = COLORMAP;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- XCreateWindow
Window *xcreatewindow_lh(args_XCreateWindow *argp)
{
    // Get function specific args
    Display* display = argp->display;;
	 Window parent = argp->parent;;
	 int x = argp->x;;
	 int y = argp->y;;
	 unsigned int width = argp->width;;
	 unsigned int height = argp->height;;
	 unsigned int border_width = argp->border_width;;
	 int	depth = argp->depth;;
	 unsigned int class = argp->class;;
	 Visual* visual = argp->visual;;
	 unsigned long valuemask = argp->valuemask;;
	 XSetWindowAttributes* attributes = argp->attributes;;

    // Call actual function
    Window result = XCreateWindow(display, parent, x, y, width, height, border_width, depth, class, visual, valuemask, attributes);

    // Memcopy in Buffer
    int ret_size = sizeof(Window);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = WINDOW;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- XFree
int *xfree_lh(args_XFree *argp)
{
    // Get function specific args
    void* data = argp->data;;

    // Call actual function
    int result = XFree(data);

    // Memcopy in Buffer
    int ret_size = sizeof(int);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = INT;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- XSetNormalHints
 *xsetnormalhints_lh(args_XSetNormalHints *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 Window w = argp->w;;
	 XSizeHints *hints = argp->hints;;

    // Call actual function
     result = XSetNormalHints(display, w, hints);

    // Memcopy in Buffer
    int ret_size = sizeof();
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = ;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- XSetStandardProperties
 *xsetstandardproperties_lh(args_XSetStandardProperties *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 Window w = argp->w;;
	 char *window_name = argp->window_name;;
	 char *icon_name = argp->icon_name;;
	 Pixmap icon_pixmap = argp->icon_pixmap;;
	 char **argv = argp->*argv;;
	 int argc = argp->argc;;
	 XSizeHints *hints = argp->hints;;

    // Call actual function
     result = XSetStandardProperties(display, w, window_name, icon_name, icon_pixmap, *argv, argc, hints);

    // Memcopy in Buffer
    int ret_size = sizeof();
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = ;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glClearIndex
void *glclearindex_lh(args_glClearIndex *argp)
{
    // Get function specific args
     GLfloat c  = argp->c;;

    // Call actual function
    glClearIndex(c);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glClearColor
void *glclearcolor_lh(args_glClearColor *argp)
{
    // Get function specific args
     GLclampf red = argp->red;;
	 GLclampf green = argp->green;;
	 GLclampf blue = argp->blue;;
	 GLclampf alpha  = argp->alpha;;

    // Call actual function
    glClearColor(red, green, blue, alpha);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glClear
void *glclear_lh(args_glClear *argp)
{
    // Get function specific args
     GLbitfield mask  = argp->mask;;

    // Call actual function
    glClear(mask);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIndexMask
void *glindexmask_lh(args_glIndexMask *argp)
{
    // Get function specific args
     GLuint mask  = argp->mask;;

    // Call actual function
    glIndexMask(mask);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColorMask
void *glcolormask_lh(args_glColorMask *argp)
{
    // Get function specific args
     GLboolean red = argp->red;;
	 GLboolean green = argp->green;;
	 GLboolean blue = argp->blue;;
	 GLboolean alpha  = argp->alpha;;

    // Call actual function
    glColorMask(red, green, blue, alpha);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glAlphaFunc
void *glalphafunc_lh(args_glAlphaFunc *argp)
{
    // Get function specific args
     GLenum func = argp->func;;
	 GLclampf ref  = argp->ref;;

    // Call actual function
    glAlphaFunc(func, ref);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glBlendFunc
void *glblendfunc_lh(args_glBlendFunc *argp)
{
    // Get function specific args
     GLenum sfactor = argp->sfactor;;
	 GLenum dfactor  = argp->dfactor;;

    // Call actual function
    glBlendFunc(sfactor, dfactor);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLogicOp
void *gllogicop_lh(args_glLogicOp *argp)
{
    // Get function specific args
     GLenum opcode  = argp->opcode;;

    // Call actual function
    glLogicOp(opcode);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCullFace
void *glcullface_lh(args_glCullFace *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;;

    // Call actual function
    glCullFace(mode);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glFrontFace
void *glfrontface_lh(args_glFrontFace *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;;

    // Call actual function
    glFrontFace(mode);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPointSize
void *glpointsize_lh(args_glPointSize *argp)
{
    // Get function specific args
     GLfloat size  = argp->size;;

    // Call actual function
    glPointSize(size);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLineWidth
void *gllinewidth_lh(args_glLineWidth *argp)
{
    // Get function specific args
     GLfloat width  = argp->width;;

    // Call actual function
    glLineWidth(width);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLineStipple
void *gllinestipple_lh(args_glLineStipple *argp)
{
    // Get function specific args
     GLint factor = argp->factor;;
	 GLushort pattern  = argp->pattern;;

    // Call actual function
    glLineStipple(factor, pattern);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPolygonMode
void *glpolygonmode_lh(args_glPolygonMode *argp)
{
    // Get function specific args
     GLenum face = argp->face;;
	 GLenum mode  = argp->mode;;

    // Call actual function
    glPolygonMode(face, mode);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPolygonOffset
void *glpolygonoffset_lh(args_glPolygonOffset *argp)
{
    // Get function specific args
     GLfloat factor = argp->factor;;
	 GLfloat units  = argp->units;;

    // Call actual function
    glPolygonOffset(factor, units);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPolygonStipple
void *glpolygonstipple_lh(args_glPolygonStipple *argp)
{
    // Get function specific args
     const GLubyte *mask  = argp->mask;;

    // Call actual function
    glPolygonStipple(mask);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetPolygonStipple
void *glgetpolygonstipple_lh(args_glGetPolygonStipple *argp)
{
    // Get function specific args
     GLubyte *mask  = argp->mask;;

    // Call actual function
    glGetPolygonStipple(mask);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEdgeFlag
void *gledgeflag_lh(args_glEdgeFlag *argp)
{
    // Get function specific args
     GLboolean flag  = argp->flag;;

    // Call actual function
    glEdgeFlag(flag);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEdgeFlagv
void *gledgeflagv_lh(args_glEdgeFlagv *argp)
{
    // Get function specific args
     const GLboolean *flag  = argp->flag;;

    // Call actual function
    glEdgeFlagv(flag);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glScissor
void *glscissor_lh(args_glScissor *argp)
{
    // Get function specific args
     GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLsizei width = argp->width;;
	 GLsizei height = argp->height;;

    // Call actual function
    glScissor(x, y, width, height);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glClipPlane
void *glclipplane_lh(args_glClipPlane *argp)
{
    // Get function specific args
     GLenum plane = argp->plane;;
	 const GLdouble *equation  = argp->equation;;

    // Call actual function
    glClipPlane(plane, equation);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetClipPlane
void *glgetclipplane_lh(args_glGetClipPlane *argp)
{
    // Get function specific args
     GLenum plane = argp->plane;;
	 GLdouble *equation  = argp->equation;;

    // Call actual function
    glGetClipPlane(plane, equation);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glDrawBuffer
void *gldrawbuffer_lh(args_glDrawBuffer *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;;

    // Call actual function
    glDrawBuffer(mode);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glReadBuffer
void *glreadbuffer_lh(args_glReadBuffer *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;;

    // Call actual function
    glReadBuffer(mode);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEnable
void *glenable_lh(args_glEnable *argp)
{
    // Get function specific args
     GLenum cap  = argp->cap;;

    // Call actual function
    glEnable(cap);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glDisable
void *gldisable_lh(args_glDisable *argp)
{
    // Get function specific args
     GLenum cap  = argp->cap;;

    // Call actual function
    glDisable(cap);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIsEnabled
GLboolean *glisenabled_lh(args_glIsEnabled *argp)
{
    // Get function specific args
     GLenum cap  = argp->cap;;

    // Call actual function
    GLboolean result = glIsEnabled(cap);

    // Memcopy in Buffer
    int ret_size = sizeof(GLboolean);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = GLBOOLEAN;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEnableClientState
void *glenableclientstate_lh(args_glEnableClientState *argp)
{
    // Get function specific args
     GLenum cap  = argp->cap;;

    // Call actual function
    glEnableClientState(cap);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glDisableClientState
void *gldisableclientstate_lh(args_glDisableClientState *argp)
{
    // Get function specific args
     GLenum cap  = argp->cap;;

    // Call actual function
    glDisableClientState(cap);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetBooleanv
void *glgetbooleanv_lh(args_glGetBooleanv *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLboolean *params  = argp->params;;

    // Call actual function
    glGetBooleanv(pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetDoublev
void *glgetdoublev_lh(args_glGetDoublev *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLdouble *params  = argp->params;;

    // Call actual function
    glGetDoublev(pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetFloatv
void *glgetfloatv_lh(args_glGetFloatv *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLfloat *params  = argp->params;;

    // Call actual function
    glGetFloatv(pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetIntegerv
void *glgetintegerv_lh(args_glGetIntegerv *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLint *params  = argp->params;;

    // Call actual function
    glGetIntegerv(pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPushAttrib
void *glpushattrib_lh(args_glPushAttrib *argp)
{
    // Get function specific args
     GLbitfield mask  = argp->mask;;

    // Call actual function
    glPushAttrib(mask);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPopAttrib
void *glpopattrib_lh()
{
    // No function specific args

    // Call actual function
    glPopAttrib();

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPushClientAttrib
void *glpushclientattrib_lh(args_glPushClientAttrib *argp)
{
    // Get function specific args
     GLbitfield mask  = argp->mask;;

    // Call actual function
    glPushClientAttrib(mask);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPopClientAttrib
void *glpopclientattrib_lh()
{
    // No function specific args

    // Call actual function
    glPopClientAttrib();

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRenderMode
GLint *glrendermode_lh(args_glRenderMode *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;;

    // Call actual function
    GLint result = glRenderMode(mode);

    // Memcopy in Buffer
    int ret_size = sizeof(GLint);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = GLINT;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glFinish
void *glfinish_lh()
{
    // No function specific args

    // Call actual function
    glFinish();

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glFlush
void *glflush_lh()
{
    // No function specific args

    // Call actual function
    glFlush();

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glHint
void *glhint_lh(args_glHint *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum mode  = argp->mode;;

    // Call actual function
    glHint(target, mode);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glClearDepth
void *glcleardepth_lh(args_glClearDepth *argp)
{
    // Get function specific args
     GLclampd depth  = argp->depth;;

    // Call actual function
    glClearDepth(depth);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glDepthFunc
void *gldepthfunc_lh(args_glDepthFunc *argp)
{
    // Get function specific args
     GLenum func  = argp->func;;

    // Call actual function
    glDepthFunc(func);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glDepthMask
void *gldepthmask_lh(args_glDepthMask *argp)
{
    // Get function specific args
     GLboolean flag  = argp->flag;;

    // Call actual function
    glDepthMask(flag);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glDepthRange
void *gldepthrange_lh(args_glDepthRange *argp)
{
    // Get function specific args
     GLclampd near_val = argp->near_val;;
	 GLclampd far_val  = argp->far_val;;

    // Call actual function
    glDepthRange(near_val, far_val);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glClearAccum
void *glclearaccum_lh(args_glClearAccum *argp)
{
    // Get function specific args
     GLfloat red = argp->red;;
	 GLfloat green = argp->green;;
	 GLfloat blue = argp->blue;;
	 GLfloat alpha  = argp->alpha;;

    // Call actual function
    glClearAccum(red, green, blue, alpha);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glAccum
void *glaccum_lh(args_glAccum *argp)
{
    // Get function specific args
     GLenum op = argp->op;;
	 GLfloat value  = argp->value;;

    // Call actual function
    glAccum(op, value);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMatrixMode
void *glmatrixmode_lh(args_glMatrixMode *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;;

    // Call actual function
    glMatrixMode(mode);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glOrtho
void *glortho_lh(args_glOrtho *argp)
{
    // Get function specific args
     GLdouble left = argp->left;;
	 GLdouble right = argp->right;;
	 GLdouble bottom = argp->bottom;;
	 GLdouble top = argp->top;;
	 GLdouble near_val = argp->near_val;;
	 GLdouble far_val  = argp->far_val;;

    // Call actual function
    glOrtho(left, right, bottom, top, near_val, far_val);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glFrustum
void *glfrustum_lh(args_glFrustum *argp)
{
    // Get function specific args
     GLdouble left = argp->left;;
	 GLdouble right = argp->right;;
	 GLdouble bottom = argp->bottom;;
	 GLdouble top = argp->top;;
	 GLdouble near_val = argp->near_val;;
	 GLdouble far_val  = argp->far_val;;

    // Call actual function
    glFrustum(left, right, bottom, top, near_val, far_val);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glViewport
void *glviewport_lh(args_glViewport *argp)
{
    // Get function specific args
     GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLsizei width = argp->width;;
	 GLsizei height  = argp->height;;

    // Call actual function
    glViewport(x, y, width, height);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPushMatrix
void *glpushmatrix_lh()
{
    // No function specific args

    // Call actual function
    glPushMatrix();

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPopMatrix
void *glpopmatrix_lh()
{
    // No function specific args

    // Call actual function
    glPopMatrix();

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLoadIdentity
void *glloadidentity_lh()
{
    // No function specific args

    // Call actual function
    glLoadIdentity();

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLoadMatrixd
void *glloadmatrixd_lh(args_glLoadMatrixd *argp)
{
    // Get function specific args
     const GLdouble *m  = argp->m;;

    // Call actual function
    glLoadMatrixd(m);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLoadMatrixf
void *glloadmatrixf_lh(args_glLoadMatrixf *argp)
{
    // Get function specific args
     const GLfloat *m  = argp->m;;

    // Call actual function
    glLoadMatrixf(m);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultMatrixd
void *glmultmatrixd_lh(args_glMultMatrixd *argp)
{
    // Get function specific args
     const GLdouble *m  = argp->m;;

    // Call actual function
    glMultMatrixd(m);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultMatrixf
void *glmultmatrixf_lh(args_glMultMatrixf *argp)
{
    // Get function specific args
     const GLfloat *m  = argp->m;;

    // Call actual function
    glMultMatrixf(m);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRotated
void *glrotated_lh(args_glRotated *argp)
{
    // Get function specific args
     GLdouble angle = argp->angle;;
	 GLdouble x = argp->x;;
	 GLdouble y = argp->y;;
	 GLdouble z  = argp->z;;

    // Call actual function
    glRotated(angle, x, y, z);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRotatef
void *glrotatef_lh(args_glRotatef *argp)
{
    // Get function specific args
     GLfloat angle = argp->angle;;
	 GLfloat x = argp->x;;
	 GLfloat y = argp->y;;
	 GLfloat z  = argp->z;;

    // Call actual function
    glRotatef(angle, x, y, z);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glScaled
void *glscaled_lh(args_glScaled *argp)
{
    // Get function specific args
     GLdouble x = argp->x;;
	 GLdouble y = argp->y;;
	 GLdouble z  = argp->z;;

    // Call actual function
    glScaled(x, y, z);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glScalef
void *glscalef_lh(args_glScalef *argp)
{
    // Get function specific args
     GLfloat x = argp->x;;
	 GLfloat y = argp->y;;
	 GLfloat z  = argp->z;;

    // Call actual function
    glScalef(x, y, z);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTranslated
void *gltranslated_lh(args_glTranslated *argp)
{
    // Get function specific args
     GLdouble x = argp->x;;
	 GLdouble y = argp->y;;
	 GLdouble z  = argp->z;;

    // Call actual function
    glTranslated(x, y, z);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTranslatef
void *gltranslatef_lh(args_glTranslatef *argp)
{
    // Get function specific args
     GLfloat x = argp->x;;
	 GLfloat y = argp->y;;
	 GLfloat z  = argp->z;;

    // Call actual function
    glTranslatef(x, y, z);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIsList
GLboolean *glislist_lh(args_glIsList *argp)
{
    // Get function specific args
     GLuint list  = argp->list;;

    // Call actual function
    GLboolean result = glIsList(list);

    // Memcopy in Buffer
    int ret_size = sizeof(GLboolean);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = GLBOOLEAN;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glDeleteLists
void *gldeletelists_lh(args_glDeleteLists *argp)
{
    // Get function specific args
     GLuint list = argp->list;;
	 GLsizei range  = argp->range;;

    // Call actual function
    glDeleteLists(list, range);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGenLists
GLuint *glgenlists_lh(args_glGenLists *argp)
{
    // Get function specific args
     GLsizei range  = argp->range;;

    // Call actual function
    GLuint result = glGenLists(range);

    // Memcopy in Buffer
    int ret_size = sizeof(GLuint);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = GLUINT;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glNewList
void *glnewlist_lh(args_glNewList *argp)
{
    // Get function specific args
     GLuint list = argp->list;;
	 GLenum mode  = argp->mode;;

    // Call actual function
    glNewList(list, mode);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEndList
void *glendlist_lh()
{
    // No function specific args

    // Call actual function
    glEndList();

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCallList
void *glcalllist_lh(args_glCallList *argp)
{
    // Get function specific args
     GLuint list  = argp->list;;

    // Call actual function
    glCallList(list);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCallLists
void *glcalllists_lh(args_glCallLists *argp)
{
    // Get function specific args
     GLsizei n = argp->n;;
	 GLenum type = argp->type;;
	 const GLvoid *lists  = argp->lists;;

    // Call actual function
    glCallLists(n, type, lists);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glListBase
void *gllistbase_lh(args_glListBase *argp)
{
    // Get function specific args
     GLuint base  = argp->base;;

    // Call actual function
    glListBase(base);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glBegin
void *glbegin_lh(args_glBegin *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;;

    // Call actual function
    glBegin(mode);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEnd
void *glend_lh()
{
    // No function specific args

    // Call actual function
    glEnd();

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex2d
void *glvertex2d_lh(args_glVertex2d *argp)
{
    // Get function specific args
     GLdouble x = argp->x;;
	 GLdouble y  = argp->y;;

    // Call actual function
    glVertex2d(x, y);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex2f
void *glvertex2f_lh(args_glVertex2f *argp)
{
    // Get function specific args
     GLfloat x = argp->x;;
	 GLfloat y  = argp->y;;

    // Call actual function
    glVertex2f(x, y);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex2i
void *glvertex2i_lh(args_glVertex2i *argp)
{
    // Get function specific args
     GLint x = argp->x;;
	 GLint y  = argp->y;;

    // Call actual function
    glVertex2i(x, y);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex2s
void *glvertex2s_lh(args_glVertex2s *argp)
{
    // Get function specific args
     GLshort x = argp->x;;
	 GLshort y  = argp->y;;

    // Call actual function
    glVertex2s(x, y);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex3d
void *glvertex3d_lh(args_glVertex3d *argp)
{
    // Get function specific args
     GLdouble x = argp->x;;
	 GLdouble y = argp->y;;
	 GLdouble z  = argp->z;;

    // Call actual function
    glVertex3d(x, y, z);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex3f
void *glvertex3f_lh(args_glVertex3f *argp)
{
    // Get function specific args
     GLfloat x = argp->x;;
	 GLfloat y = argp->y;;
	 GLfloat z  = argp->z;;

    // Call actual function
    glVertex3f(x, y, z);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex3i
void *glvertex3i_lh(args_glVertex3i *argp)
{
    // Get function specific args
     GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLint z  = argp->z;;

    // Call actual function
    glVertex3i(x, y, z);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex3s
void *glvertex3s_lh(args_glVertex3s *argp)
{
    // Get function specific args
     GLshort x = argp->x;;
	 GLshort y = argp->y;;
	 GLshort z  = argp->z;;

    // Call actual function
    glVertex3s(x, y, z);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex4d
void *glvertex4d_lh(args_glVertex4d *argp)
{
    // Get function specific args
     GLdouble x = argp->x;;
	 GLdouble y = argp->y;;
	 GLdouble z = argp->z;;
	 GLdouble w  = argp->w;;

    // Call actual function
    glVertex4d(x, y, z, w);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex4f
void *glvertex4f_lh(args_glVertex4f *argp)
{
    // Get function specific args
     GLfloat x = argp->x;;
	 GLfloat y = argp->y;;
	 GLfloat z = argp->z;;
	 GLfloat w  = argp->w;;

    // Call actual function
    glVertex4f(x, y, z, w);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex4i
void *glvertex4i_lh(args_glVertex4i *argp)
{
    // Get function specific args
     GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLint z = argp->z;;
	 GLint w  = argp->w;;

    // Call actual function
    glVertex4i(x, y, z, w);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex4s
void *glvertex4s_lh(args_glVertex4s *argp)
{
    // Get function specific args
     GLshort x = argp->x;;
	 GLshort y = argp->y;;
	 GLshort z = argp->z;;
	 GLshort w  = argp->w;;

    // Call actual function
    glVertex4s(x, y, z, w);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex2dv
void *glvertex2dv_lh(args_glVertex2dv *argp)
{
    // Get function specific args
     const GLdouble *v  = argp->v;;

    // Call actual function
    glVertex2dv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex2fv
void *glvertex2fv_lh(args_glVertex2fv *argp)
{
    // Get function specific args
     const GLfloat *v  = argp->v;;

    // Call actual function
    glVertex2fv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex2iv
void *glvertex2iv_lh(args_glVertex2iv *argp)
{
    // Get function specific args
     const GLint *v  = argp->v;;

    // Call actual function
    glVertex2iv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex2sv
void *glvertex2sv_lh(args_glVertex2sv *argp)
{
    // Get function specific args
     const GLshort *v  = argp->v;;

    // Call actual function
    glVertex2sv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex3dv
void *glvertex3dv_lh(args_glVertex3dv *argp)
{
    // Get function specific args
     const GLdouble *v  = argp->v;;

    // Call actual function
    glVertex3dv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex3fv
void *glvertex3fv_lh(args_glVertex3fv *argp)
{
    // Get function specific args
     const GLfloat *v  = argp->v;;

    // Call actual function
    glVertex3fv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex3iv
void *glvertex3iv_lh(args_glVertex3iv *argp)
{
    // Get function specific args
     const GLint *v  = argp->v;;

    // Call actual function
    glVertex3iv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex3sv
void *glvertex3sv_lh(args_glVertex3sv *argp)
{
    // Get function specific args
     const GLshort *v  = argp->v;;

    // Call actual function
    glVertex3sv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex4dv
void *glvertex4dv_lh(args_glVertex4dv *argp)
{
    // Get function specific args
     const GLdouble *v  = argp->v;;

    // Call actual function
    glVertex4dv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex4fv
void *glvertex4fv_lh(args_glVertex4fv *argp)
{
    // Get function specific args
     const GLfloat *v  = argp->v;;

    // Call actual function
    glVertex4fv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex4iv
void *glvertex4iv_lh(args_glVertex4iv *argp)
{
    // Get function specific args
     const GLint *v  = argp->v;;

    // Call actual function
    glVertex4iv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertex4sv
void *glvertex4sv_lh(args_glVertex4sv *argp)
{
    // Get function specific args
     const GLshort *v  = argp->v;;

    // Call actual function
    glVertex4sv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glNormal3b
void *glnormal3b_lh(args_glNormal3b *argp)
{
    // Get function specific args
     GLbyte nx = argp->nx;;
	 GLbyte ny = argp->ny;;
	 GLbyte nz  = argp->nz;;

    // Call actual function
    glNormal3b(nx, ny, nz);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glNormal3d
void *glnormal3d_lh(args_glNormal3d *argp)
{
    // Get function specific args
     GLdouble nx = argp->nx;;
	 GLdouble ny = argp->ny;;
	 GLdouble nz  = argp->nz;;

    // Call actual function
    glNormal3d(nx, ny, nz);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glNormal3f
void *glnormal3f_lh(args_glNormal3f *argp)
{
    // Get function specific args
     GLfloat nx = argp->nx;;
	 GLfloat ny = argp->ny;;
	 GLfloat nz  = argp->nz;;

    // Call actual function
    glNormal3f(nx, ny, nz);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glNormal3i
void *glnormal3i_lh(args_glNormal3i *argp)
{
    // Get function specific args
     GLint nx = argp->nx;;
	 GLint ny = argp->ny;;
	 GLint nz  = argp->nz;;

    // Call actual function
    glNormal3i(nx, ny, nz);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glNormal3s
void *glnormal3s_lh(args_glNormal3s *argp)
{
    // Get function specific args
     GLshort nx = argp->nx;;
	 GLshort ny = argp->ny;;
	 GLshort nz  = argp->nz;;

    // Call actual function
    glNormal3s(nx, ny, nz);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glNormal3bv
void *glnormal3bv_lh(args_glNormal3bv *argp)
{
    // Get function specific args
     const GLbyte *v  = argp->v;;

    // Call actual function
    glNormal3bv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glNormal3dv
void *glnormal3dv_lh(args_glNormal3dv *argp)
{
    // Get function specific args
     const GLdouble *v  = argp->v;;

    // Call actual function
    glNormal3dv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glNormal3fv
void *glnormal3fv_lh(args_glNormal3fv *argp)
{
    // Get function specific args
     const GLfloat *v  = argp->v;;

    // Call actual function
    glNormal3fv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glNormal3iv
void *glnormal3iv_lh(args_glNormal3iv *argp)
{
    // Get function specific args
     const GLint *v  = argp->v;;

    // Call actual function
    glNormal3iv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glNormal3sv
void *glnormal3sv_lh(args_glNormal3sv *argp)
{
    // Get function specific args
     const GLshort *v  = argp->v;;

    // Call actual function
    glNormal3sv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIndexd
void *glindexd_lh(args_glIndexd *argp)
{
    // Get function specific args
     GLdouble c  = argp->c;;

    // Call actual function
    glIndexd(c);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIndexf
void *glindexf_lh(args_glIndexf *argp)
{
    // Get function specific args
     GLfloat c  = argp->c;;

    // Call actual function
    glIndexf(c);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIndexi
void *glindexi_lh(args_glIndexi *argp)
{
    // Get function specific args
     GLint c  = argp->c;;

    // Call actual function
    glIndexi(c);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIndexs
void *glindexs_lh(args_glIndexs *argp)
{
    // Get function specific args
     GLshort c  = argp->c;;

    // Call actual function
    glIndexs(c);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIndexub
void *glindexub_lh(args_glIndexub *argp)
{
    // Get function specific args
     GLubyte c  = argp->c;;

    // Call actual function
    glIndexub(c);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIndexdv
void *glindexdv_lh(args_glIndexdv *argp)
{
    // Get function specific args
     const GLdouble *c  = argp->c;;

    // Call actual function
    glIndexdv(c);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIndexfv
void *glindexfv_lh(args_glIndexfv *argp)
{
    // Get function specific args
     const GLfloat *c  = argp->c;;

    // Call actual function
    glIndexfv(c);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIndexiv
void *glindexiv_lh(args_glIndexiv *argp)
{
    // Get function specific args
     const GLint *c  = argp->c;;

    // Call actual function
    glIndexiv(c);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIndexsv
void *glindexsv_lh(args_glIndexsv *argp)
{
    // Get function specific args
     const GLshort *c  = argp->c;;

    // Call actual function
    glIndexsv(c);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIndexubv
void *glindexubv_lh(args_glIndexubv *argp)
{
    // Get function specific args
     const GLubyte *c  = argp->c;;

    // Call actual function
    glIndexubv(c);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor3b
void *glcolor3b_lh(args_glColor3b *argp)
{
    // Get function specific args
     GLbyte red = argp->red;;
	 GLbyte green = argp->green;;
	 GLbyte blue  = argp->blue;;

    // Call actual function
    glColor3b(red, green, blue);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor3d
void *glcolor3d_lh(args_glColor3d *argp)
{
    // Get function specific args
     GLdouble red = argp->red;;
	 GLdouble green = argp->green;;
	 GLdouble blue  = argp->blue;;

    // Call actual function
    glColor3d(red, green, blue);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor3f
void *glcolor3f_lh(args_glColor3f *argp)
{
    // Get function specific args
     GLfloat red = argp->red;;
	 GLfloat green = argp->green;;
	 GLfloat blue  = argp->blue;;

    // Call actual function
    glColor3f(red, green, blue);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor3i
void *glcolor3i_lh(args_glColor3i *argp)
{
    // Get function specific args
     GLint red = argp->red;;
	 GLint green = argp->green;;
	 GLint blue  = argp->blue;;

    // Call actual function
    glColor3i(red, green, blue);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor3s
void *glcolor3s_lh(args_glColor3s *argp)
{
    // Get function specific args
     GLshort red = argp->red;;
	 GLshort green = argp->green;;
	 GLshort blue  = argp->blue;;

    // Call actual function
    glColor3s(red, green, blue);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor3ub
void *glcolor3ub_lh(args_glColor3ub *argp)
{
    // Get function specific args
     GLubyte red = argp->red;;
	 GLubyte green = argp->green;;
	 GLubyte blue  = argp->blue;;

    // Call actual function
    glColor3ub(red, green, blue);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor3ui
void *glcolor3ui_lh(args_glColor3ui *argp)
{
    // Get function specific args
     GLuint red = argp->red;;
	 GLuint green = argp->green;;
	 GLuint blue  = argp->blue;;

    // Call actual function
    glColor3ui(red, green, blue);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor3us
void *glcolor3us_lh(args_glColor3us *argp)
{
    // Get function specific args
     GLushort red = argp->red;;
	 GLushort green = argp->green;;
	 GLushort blue  = argp->blue;;

    // Call actual function
    glColor3us(red, green, blue);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor4b
void *glcolor4b_lh(args_glColor4b *argp)
{
    // Get function specific args
     GLbyte red = argp->red;;
	 GLbyte green = argp->green;;
	 GLbyte blue = argp->blue;;
	 GLbyte alpha  = argp->alpha;;

    // Call actual function
    glColor4b(red, green, blue, alpha);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor4d
void *glcolor4d_lh(args_glColor4d *argp)
{
    // Get function specific args
     GLdouble red = argp->red;;
	 GLdouble green = argp->green;;
	 GLdouble blue = argp->blue;;
	 GLdouble alpha  = argp->alpha;;

    // Call actual function
    glColor4d(red, green, blue, alpha);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor4f
void *glcolor4f_lh(args_glColor4f *argp)
{
    // Get function specific args
     GLfloat red = argp->red;;
	 GLfloat green = argp->green;;
	 GLfloat blue = argp->blue;;
	 GLfloat alpha  = argp->alpha;;

    // Call actual function
    glColor4f(red, green, blue, alpha);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor4i
void *glcolor4i_lh(args_glColor4i *argp)
{
    // Get function specific args
     GLint red = argp->red;;
	 GLint green = argp->green;;
	 GLint blue = argp->blue;;
	 GLint alpha  = argp->alpha;;

    // Call actual function
    glColor4i(red, green, blue, alpha);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor4s
void *glcolor4s_lh(args_glColor4s *argp)
{
    // Get function specific args
     GLshort red = argp->red;;
	 GLshort green = argp->green;;
	 GLshort blue = argp->blue;;
	 GLshort alpha  = argp->alpha;;

    // Call actual function
    glColor4s(red, green, blue, alpha);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor4ub
void *glcolor4ub_lh(args_glColor4ub *argp)
{
    // Get function specific args
     GLubyte red = argp->red;;
	 GLubyte green = argp->green;;
	 GLubyte blue = argp->blue;;
	 GLubyte alpha  = argp->alpha;;

    // Call actual function
    glColor4ub(red, green, blue, alpha);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor4ui
void *glcolor4ui_lh(args_glColor4ui *argp)
{
    // Get function specific args
     GLuint red = argp->red;;
	 GLuint green = argp->green;;
	 GLuint blue = argp->blue;;
	 GLuint alpha  = argp->alpha;;

    // Call actual function
    glColor4ui(red, green, blue, alpha);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor4us
void *glcolor4us_lh(args_glColor4us *argp)
{
    // Get function specific args
     GLushort red = argp->red;;
	 GLushort green = argp->green;;
	 GLushort blue = argp->blue;;
	 GLushort alpha  = argp->alpha;;

    // Call actual function
    glColor4us(red, green, blue, alpha);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor3bv
void *glcolor3bv_lh(args_glColor3bv *argp)
{
    // Get function specific args
     const GLbyte *v  = argp->v;;

    // Call actual function
    glColor3bv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor3dv
void *glcolor3dv_lh(args_glColor3dv *argp)
{
    // Get function specific args
     const GLdouble *v  = argp->v;;

    // Call actual function
    glColor3dv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor3fv
void *glcolor3fv_lh(args_glColor3fv *argp)
{
    // Get function specific args
     const GLfloat *v  = argp->v;;

    // Call actual function
    glColor3fv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor3iv
void *glcolor3iv_lh(args_glColor3iv *argp)
{
    // Get function specific args
     const GLint *v  = argp->v;;

    // Call actual function
    glColor3iv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor3sv
void *glcolor3sv_lh(args_glColor3sv *argp)
{
    // Get function specific args
     const GLshort *v  = argp->v;;

    // Call actual function
    glColor3sv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor3ubv
void *glcolor3ubv_lh(args_glColor3ubv *argp)
{
    // Get function specific args
     const GLubyte *v  = argp->v;;

    // Call actual function
    glColor3ubv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor3uiv
void *glcolor3uiv_lh(args_glColor3uiv *argp)
{
    // Get function specific args
     const GLuint *v  = argp->v;;

    // Call actual function
    glColor3uiv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor3usv
void *glcolor3usv_lh(args_glColor3usv *argp)
{
    // Get function specific args
     const GLushort *v  = argp->v;;

    // Call actual function
    glColor3usv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor4bv
void *glcolor4bv_lh(args_glColor4bv *argp)
{
    // Get function specific args
     const GLbyte *v  = argp->v;;

    // Call actual function
    glColor4bv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor4dv
void *glcolor4dv_lh(args_glColor4dv *argp)
{
    // Get function specific args
     const GLdouble *v  = argp->v;;

    // Call actual function
    glColor4dv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor4fv
void *glcolor4fv_lh(args_glColor4fv *argp)
{
    // Get function specific args
     const GLfloat *v  = argp->v;;

    // Call actual function
    glColor4fv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor4iv
void *glcolor4iv_lh(args_glColor4iv *argp)
{
    // Get function specific args
     const GLint *v  = argp->v;;

    // Call actual function
    glColor4iv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor4sv
void *glcolor4sv_lh(args_glColor4sv *argp)
{
    // Get function specific args
     const GLshort *v  = argp->v;;

    // Call actual function
    glColor4sv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor4ubv
void *glcolor4ubv_lh(args_glColor4ubv *argp)
{
    // Get function specific args
     const GLubyte *v  = argp->v;;

    // Call actual function
    glColor4ubv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor4uiv
void *glcolor4uiv_lh(args_glColor4uiv *argp)
{
    // Get function specific args
     const GLuint *v  = argp->v;;

    // Call actual function
    glColor4uiv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColor4usv
void *glcolor4usv_lh(args_glColor4usv *argp)
{
    // Get function specific args
     const GLushort *v  = argp->v;;

    // Call actual function
    glColor4usv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord1d
void *gltexcoord1d_lh(args_glTexCoord1d *argp)
{
    // Get function specific args
     GLdouble s  = argp->s;;

    // Call actual function
    glTexCoord1d(s);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord1f
void *gltexcoord1f_lh(args_glTexCoord1f *argp)
{
    // Get function specific args
     GLfloat s  = argp->s;;

    // Call actual function
    glTexCoord1f(s);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord1i
void *gltexcoord1i_lh(args_glTexCoord1i *argp)
{
    // Get function specific args
     GLint s  = argp->s;;

    // Call actual function
    glTexCoord1i(s);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord1s
void *gltexcoord1s_lh(args_glTexCoord1s *argp)
{
    // Get function specific args
     GLshort s  = argp->s;;

    // Call actual function
    glTexCoord1s(s);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord2d
void *gltexcoord2d_lh(args_glTexCoord2d *argp)
{
    // Get function specific args
     GLdouble s = argp->s;;
	 GLdouble t  = argp->t;;

    // Call actual function
    glTexCoord2d(s, t);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord2f
void *gltexcoord2f_lh(args_glTexCoord2f *argp)
{
    // Get function specific args
     GLfloat s = argp->s;;
	 GLfloat t  = argp->t;;

    // Call actual function
    glTexCoord2f(s, t);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord2i
void *gltexcoord2i_lh(args_glTexCoord2i *argp)
{
    // Get function specific args
     GLint s = argp->s;;
	 GLint t  = argp->t;;

    // Call actual function
    glTexCoord2i(s, t);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord2s
void *gltexcoord2s_lh(args_glTexCoord2s *argp)
{
    // Get function specific args
     GLshort s = argp->s;;
	 GLshort t  = argp->t;;

    // Call actual function
    glTexCoord2s(s, t);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord3d
void *gltexcoord3d_lh(args_glTexCoord3d *argp)
{
    // Get function specific args
     GLdouble s = argp->s;;
	 GLdouble t = argp->t;;
	 GLdouble r  = argp->r;;

    // Call actual function
    glTexCoord3d(s, t, r);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord3f
void *gltexcoord3f_lh(args_glTexCoord3f *argp)
{
    // Get function specific args
     GLfloat s = argp->s;;
	 GLfloat t = argp->t;;
	 GLfloat r  = argp->r;;

    // Call actual function
    glTexCoord3f(s, t, r);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord3i
void *gltexcoord3i_lh(args_glTexCoord3i *argp)
{
    // Get function specific args
     GLint s = argp->s;;
	 GLint t = argp->t;;
	 GLint r  = argp->r;;

    // Call actual function
    glTexCoord3i(s, t, r);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord3s
void *gltexcoord3s_lh(args_glTexCoord3s *argp)
{
    // Get function specific args
     GLshort s = argp->s;;
	 GLshort t = argp->t;;
	 GLshort r  = argp->r;;

    // Call actual function
    glTexCoord3s(s, t, r);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord4d
void *gltexcoord4d_lh(args_glTexCoord4d *argp)
{
    // Get function specific args
     GLdouble s = argp->s;;
	 GLdouble t = argp->t;;
	 GLdouble r = argp->r;;
	 GLdouble q  = argp->q;;

    // Call actual function
    glTexCoord4d(s, t, r, q);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord4f
void *gltexcoord4f_lh(args_glTexCoord4f *argp)
{
    // Get function specific args
     GLfloat s = argp->s;;
	 GLfloat t = argp->t;;
	 GLfloat r = argp->r;;
	 GLfloat q  = argp->q;;

    // Call actual function
    glTexCoord4f(s, t, r, q);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord4i
void *gltexcoord4i_lh(args_glTexCoord4i *argp)
{
    // Get function specific args
     GLint s = argp->s;;
	 GLint t = argp->t;;
	 GLint r = argp->r;;
	 GLint q  = argp->q;;

    // Call actual function
    glTexCoord4i(s, t, r, q);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord4s
void *gltexcoord4s_lh(args_glTexCoord4s *argp)
{
    // Get function specific args
     GLshort s = argp->s;;
	 GLshort t = argp->t;;
	 GLshort r = argp->r;;
	 GLshort q  = argp->q;;

    // Call actual function
    glTexCoord4s(s, t, r, q);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord1dv
void *gltexcoord1dv_lh(args_glTexCoord1dv *argp)
{
    // Get function specific args
     const GLdouble *v  = argp->v;;

    // Call actual function
    glTexCoord1dv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord1fv
void *gltexcoord1fv_lh(args_glTexCoord1fv *argp)
{
    // Get function specific args
     const GLfloat *v  = argp->v;;

    // Call actual function
    glTexCoord1fv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord1iv
void *gltexcoord1iv_lh(args_glTexCoord1iv *argp)
{
    // Get function specific args
     const GLint *v  = argp->v;;

    // Call actual function
    glTexCoord1iv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord1sv
void *gltexcoord1sv_lh(args_glTexCoord1sv *argp)
{
    // Get function specific args
     const GLshort *v  = argp->v;;

    // Call actual function
    glTexCoord1sv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord2dv
void *gltexcoord2dv_lh(args_glTexCoord2dv *argp)
{
    // Get function specific args
     const GLdouble *v  = argp->v;;

    // Call actual function
    glTexCoord2dv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord2fv
void *gltexcoord2fv_lh(args_glTexCoord2fv *argp)
{
    // Get function specific args
     const GLfloat *v  = argp->v;;

    // Call actual function
    glTexCoord2fv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord2iv
void *gltexcoord2iv_lh(args_glTexCoord2iv *argp)
{
    // Get function specific args
     const GLint *v  = argp->v;;

    // Call actual function
    glTexCoord2iv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord2sv
void *gltexcoord2sv_lh(args_glTexCoord2sv *argp)
{
    // Get function specific args
     const GLshort *v  = argp->v;;

    // Call actual function
    glTexCoord2sv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord3dv
void *gltexcoord3dv_lh(args_glTexCoord3dv *argp)
{
    // Get function specific args
     const GLdouble *v  = argp->v;;

    // Call actual function
    glTexCoord3dv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord3fv
void *gltexcoord3fv_lh(args_glTexCoord3fv *argp)
{
    // Get function specific args
     const GLfloat *v  = argp->v;;

    // Call actual function
    glTexCoord3fv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord3iv
void *gltexcoord3iv_lh(args_glTexCoord3iv *argp)
{
    // Get function specific args
     const GLint *v  = argp->v;;

    // Call actual function
    glTexCoord3iv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord3sv
void *gltexcoord3sv_lh(args_glTexCoord3sv *argp)
{
    // Get function specific args
     const GLshort *v  = argp->v;;

    // Call actual function
    glTexCoord3sv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord4dv
void *gltexcoord4dv_lh(args_glTexCoord4dv *argp)
{
    // Get function specific args
     const GLdouble *v  = argp->v;;

    // Call actual function
    glTexCoord4dv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord4fv
void *gltexcoord4fv_lh(args_glTexCoord4fv *argp)
{
    // Get function specific args
     const GLfloat *v  = argp->v;;

    // Call actual function
    glTexCoord4fv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord4iv
void *gltexcoord4iv_lh(args_glTexCoord4iv *argp)
{
    // Get function specific args
     const GLint *v  = argp->v;;

    // Call actual function
    glTexCoord4iv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoord4sv
void *gltexcoord4sv_lh(args_glTexCoord4sv *argp)
{
    // Get function specific args
     const GLshort *v  = argp->v;;

    // Call actual function
    glTexCoord4sv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos2d
void *glrasterpos2d_lh(args_glRasterPos2d *argp)
{
    // Get function specific args
     GLdouble x = argp->x;;
	 GLdouble y  = argp->y;;

    // Call actual function
    glRasterPos2d(x, y);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos2f
void *glrasterpos2f_lh(args_glRasterPos2f *argp)
{
    // Get function specific args
     GLfloat x = argp->x;;
	 GLfloat y  = argp->y;;

    // Call actual function
    glRasterPos2f(x, y);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos2i
void *glrasterpos2i_lh(args_glRasterPos2i *argp)
{
    // Get function specific args
     GLint x = argp->x;;
	 GLint y  = argp->y;;

    // Call actual function
    glRasterPos2i(x, y);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos2s
void *glrasterpos2s_lh(args_glRasterPos2s *argp)
{
    // Get function specific args
     GLshort x = argp->x;;
	 GLshort y  = argp->y;;

    // Call actual function
    glRasterPos2s(x, y);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos3d
void *glrasterpos3d_lh(args_glRasterPos3d *argp)
{
    // Get function specific args
     GLdouble x = argp->x;;
	 GLdouble y = argp->y;;
	 GLdouble z  = argp->z;;

    // Call actual function
    glRasterPos3d(x, y, z);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos3f
void *glrasterpos3f_lh(args_glRasterPos3f *argp)
{
    // Get function specific args
     GLfloat x = argp->x;;
	 GLfloat y = argp->y;;
	 GLfloat z  = argp->z;;

    // Call actual function
    glRasterPos3f(x, y, z);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos3i
void *glrasterpos3i_lh(args_glRasterPos3i *argp)
{
    // Get function specific args
     GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLint z  = argp->z;;

    // Call actual function
    glRasterPos3i(x, y, z);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos3s
void *glrasterpos3s_lh(args_glRasterPos3s *argp)
{
    // Get function specific args
     GLshort x = argp->x;;
	 GLshort y = argp->y;;
	 GLshort z  = argp->z;;

    // Call actual function
    glRasterPos3s(x, y, z);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos4d
void *glrasterpos4d_lh(args_glRasterPos4d *argp)
{
    // Get function specific args
     GLdouble x = argp->x;;
	 GLdouble y = argp->y;;
	 GLdouble z = argp->z;;
	 GLdouble w  = argp->w;;

    // Call actual function
    glRasterPos4d(x, y, z, w);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos4f
void *glrasterpos4f_lh(args_glRasterPos4f *argp)
{
    // Get function specific args
     GLfloat x = argp->x;;
	 GLfloat y = argp->y;;
	 GLfloat z = argp->z;;
	 GLfloat w  = argp->w;;

    // Call actual function
    glRasterPos4f(x, y, z, w);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos4i
void *glrasterpos4i_lh(args_glRasterPos4i *argp)
{
    // Get function specific args
     GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLint z = argp->z;;
	 GLint w  = argp->w;;

    // Call actual function
    glRasterPos4i(x, y, z, w);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos4s
void *glrasterpos4s_lh(args_glRasterPos4s *argp)
{
    // Get function specific args
     GLshort x = argp->x;;
	 GLshort y = argp->y;;
	 GLshort z = argp->z;;
	 GLshort w  = argp->w;;

    // Call actual function
    glRasterPos4s(x, y, z, w);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos2dv
void *glrasterpos2dv_lh(args_glRasterPos2dv *argp)
{
    // Get function specific args
     const GLdouble *v  = argp->v;;

    // Call actual function
    glRasterPos2dv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos2fv
void *glrasterpos2fv_lh(args_glRasterPos2fv *argp)
{
    // Get function specific args
     const GLfloat *v  = argp->v;;

    // Call actual function
    glRasterPos2fv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos2iv
void *glrasterpos2iv_lh(args_glRasterPos2iv *argp)
{
    // Get function specific args
     const GLint *v  = argp->v;;

    // Call actual function
    glRasterPos2iv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos2sv
void *glrasterpos2sv_lh(args_glRasterPos2sv *argp)
{
    // Get function specific args
     const GLshort *v  = argp->v;;

    // Call actual function
    glRasterPos2sv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos3dv
void *glrasterpos3dv_lh(args_glRasterPos3dv *argp)
{
    // Get function specific args
     const GLdouble *v  = argp->v;;

    // Call actual function
    glRasterPos3dv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos3fv
void *glrasterpos3fv_lh(args_glRasterPos3fv *argp)
{
    // Get function specific args
     const GLfloat *v  = argp->v;;

    // Call actual function
    glRasterPos3fv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos3iv
void *glrasterpos3iv_lh(args_glRasterPos3iv *argp)
{
    // Get function specific args
     const GLint *v  = argp->v;;

    // Call actual function
    glRasterPos3iv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos3sv
void *glrasterpos3sv_lh(args_glRasterPos3sv *argp)
{
    // Get function specific args
     const GLshort *v  = argp->v;;

    // Call actual function
    glRasterPos3sv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos4dv
void *glrasterpos4dv_lh(args_glRasterPos4dv *argp)
{
    // Get function specific args
     const GLdouble *v  = argp->v;;

    // Call actual function
    glRasterPos4dv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos4fv
void *glrasterpos4fv_lh(args_glRasterPos4fv *argp)
{
    // Get function specific args
     const GLfloat *v  = argp->v;;

    // Call actual function
    glRasterPos4fv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos4iv
void *glrasterpos4iv_lh(args_glRasterPos4iv *argp)
{
    // Get function specific args
     const GLint *v  = argp->v;;

    // Call actual function
    glRasterPos4iv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRasterPos4sv
void *glrasterpos4sv_lh(args_glRasterPos4sv *argp)
{
    // Get function specific args
     const GLshort *v  = argp->v;;

    // Call actual function
    glRasterPos4sv(v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRectd
void *glrectd_lh(args_glRectd *argp)
{
    // Get function specific args
     GLdouble x1 = argp->x1;;
	 GLdouble y1 = argp->y1;;
	 GLdouble x2 = argp->x2;;
	 GLdouble y2  = argp->y2;;

    // Call actual function
    glRectd(x1, y1, x2, y2);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRectf
void *glrectf_lh(args_glRectf *argp)
{
    // Get function specific args
     GLfloat x1 = argp->x1;;
	 GLfloat y1 = argp->y1;;
	 GLfloat x2 = argp->x2;;
	 GLfloat y2  = argp->y2;;

    // Call actual function
    glRectf(x1, y1, x2, y2);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRecti
void *glrecti_lh(args_glRecti *argp)
{
    // Get function specific args
     GLint x1 = argp->x1;;
	 GLint y1 = argp->y1;;
	 GLint x2 = argp->x2;;
	 GLint y2  = argp->y2;;

    // Call actual function
    glRecti(x1, y1, x2, y2);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRects
void *glrects_lh(args_glRects *argp)
{
    // Get function specific args
     GLshort x1 = argp->x1;;
	 GLshort y1 = argp->y1;;
	 GLshort x2 = argp->x2;;
	 GLshort y2  = argp->y2;;

    // Call actual function
    glRects(x1, y1, x2, y2);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRectdv
void *glrectdv_lh(args_glRectdv *argp)
{
    // Get function specific args
     const GLdouble *v1 = argp->v1;;
	 const GLdouble *v2  = argp->v2;;

    // Call actual function
    glRectdv(v1, v2);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRectfv
void *glrectfv_lh(args_glRectfv *argp)
{
    // Get function specific args
     const GLfloat *v1 = argp->v1;;
	 const GLfloat *v2  = argp->v2;;

    // Call actual function
    glRectfv(v1, v2);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRectiv
void *glrectiv_lh(args_glRectiv *argp)
{
    // Get function specific args
     const GLint *v1 = argp->v1;;
	 const GLint *v2  = argp->v2;;

    // Call actual function
    glRectiv(v1, v2);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glRectsv
void *glrectsv_lh(args_glRectsv *argp)
{
    // Get function specific args
     const GLshort *v1 = argp->v1;;
	 const GLshort *v2  = argp->v2;;

    // Call actual function
    glRectsv(v1, v2);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glVertexPointer
void *glvertexpointer_lh(args_glVertexPointer *argp)
{
    // Get function specific args
     GLint size = argp->size;;
	 GLenum type = argp->type;;
	 GLsizei stride = argp->stride;;
	 const GLvoid *ptr  = argp->ptr;;

    // Call actual function
    glVertexPointer(size, type, stride, ptr);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glNormalPointer
void *glnormalpointer_lh(args_glNormalPointer *argp)
{
    // Get function specific args
     GLenum type = argp->type;;
	 GLsizei stride = argp->stride;;
	 const GLvoid *ptr  = argp->ptr;;

    // Call actual function
    glNormalPointer(type, stride, ptr);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColorPointer
void *glcolorpointer_lh(args_glColorPointer *argp)
{
    // Get function specific args
     GLint size = argp->size;;
	 GLenum type = argp->type;;
	 GLsizei stride = argp->stride;;
	 const GLvoid *ptr  = argp->ptr;;

    // Call actual function
    glColorPointer(size, type, stride, ptr);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIndexPointer
void *glindexpointer_lh(args_glIndexPointer *argp)
{
    // Get function specific args
     GLenum type = argp->type;;
	 GLsizei stride = argp->stride;;
	 const GLvoid *ptr  = argp->ptr;;

    // Call actual function
    glIndexPointer(type, stride, ptr);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexCoordPointer
void *gltexcoordpointer_lh(args_glTexCoordPointer *argp)
{
    // Get function specific args
     GLint size = argp->size;;
	 GLenum type = argp->type;;
	 GLsizei stride = argp->stride;;
	 const GLvoid *ptr  = argp->ptr;;

    // Call actual function
    glTexCoordPointer(size, type, stride, ptr);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEdgeFlagPointer
void *gledgeflagpointer_lh(args_glEdgeFlagPointer *argp)
{
    // Get function specific args
     GLsizei stride = argp->stride;;
	 const GLvoid *ptr  = argp->ptr;;

    // Call actual function
    glEdgeFlagPointer(stride, ptr);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetPointerv
void *glgetpointerv_lh(args_glGetPointerv *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLvoid **params  = argp->*params;;

    // Call actual function
    glGetPointerv(pname, *params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glArrayElement
void *glarrayelement_lh(args_glArrayElement *argp)
{
    // Get function specific args
     GLint i  = argp->i;;

    // Call actual function
    glArrayElement(i);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glDrawArrays
void *gldrawarrays_lh(args_glDrawArrays *argp)
{
    // Get function specific args
     GLenum mode = argp->mode;;
	 GLint first = argp->first;;
	 GLsizei count  = argp->count;;

    // Call actual function
    glDrawArrays(mode, first, count);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glDrawElements
void *gldrawelements_lh(args_glDrawElements *argp)
{
    // Get function specific args
     GLenum mode = argp->mode;;
	 GLsizei count = argp->count;;
	 GLenum type = argp->type;;
	 const GLvoid *indices  = argp->indices;;

    // Call actual function
    glDrawElements(mode, count, type, indices);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glInterleavedArrays
void *glinterleavedarrays_lh(args_glInterleavedArrays *argp)
{
    // Get function specific args
     GLenum format = argp->format;;
	 GLsizei stride = argp->stride;;
	 const GLvoid *pointer  = argp->pointer;;

    // Call actual function
    glInterleavedArrays(format, stride, pointer);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glShadeModel
void *glshademodel_lh(args_glShadeModel *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;;

    // Call actual function
    glShadeModel(mode);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLightf
void *gllightf_lh(args_glLightf *argp)
{
    // Get function specific args
     GLenum light = argp->light;;
	 GLenum pname = argp->pname;;
	 GLfloat param  = argp->param;;

    // Call actual function
    glLightf(light, pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLighti
void *gllighti_lh(args_glLighti *argp)
{
    // Get function specific args
     GLenum light = argp->light;;
	 GLenum pname = argp->pname;;
	 GLint param  = argp->param;;

    // Call actual function
    glLighti(light, pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLightfv
void *gllightfv_lh(args_glLightfv *argp)
{
    // Get function specific args
     GLenum light = argp->light;;
	 GLenum pname = argp->pname;;
	 const GLfloat *params  = argp->params;;

    // Call actual function
    glLightfv(light, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLightiv
void *gllightiv_lh(args_glLightiv *argp)
{
    // Get function specific args
     GLenum light = argp->light;;
	 GLenum pname = argp->pname;;
	 const GLint *params  = argp->params;;

    // Call actual function
    glLightiv(light, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetLightfv
void *glgetlightfv_lh(args_glGetLightfv *argp)
{
    // Get function specific args
     GLenum light = argp->light;;
	 GLenum pname = argp->pname;;
	 GLfloat *params  = argp->params;;

    // Call actual function
    glGetLightfv(light, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetLightiv
void *glgetlightiv_lh(args_glGetLightiv *argp)
{
    // Get function specific args
     GLenum light = argp->light;;
	 GLenum pname = argp->pname;;
	 GLint *params  = argp->params;;

    // Call actual function
    glGetLightiv(light, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLightModelf
void *gllightmodelf_lh(args_glLightModelf *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLfloat param  = argp->param;;

    // Call actual function
    glLightModelf(pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLightModeli
void *gllightmodeli_lh(args_glLightModeli *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLint param  = argp->param;;

    // Call actual function
    glLightModeli(pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLightModelfv
void *gllightmodelfv_lh(args_glLightModelfv *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 const GLfloat *params  = argp->params;;

    // Call actual function
    glLightModelfv(pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLightModeliv
void *gllightmodeliv_lh(args_glLightModeliv *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 const GLint *params  = argp->params;;

    // Call actual function
    glLightModeliv(pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMaterialf
void *glmaterialf_lh(args_glMaterialf *argp)
{
    // Get function specific args
     GLenum face = argp->face;;
	 GLenum pname = argp->pname;;
	 GLfloat param  = argp->param;;

    // Call actual function
    glMaterialf(face, pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMateriali
void *glmateriali_lh(args_glMateriali *argp)
{
    // Get function specific args
     GLenum face = argp->face;;
	 GLenum pname = argp->pname;;
	 GLint param  = argp->param;;

    // Call actual function
    glMateriali(face, pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMaterialfv
void *glmaterialfv_lh(args_glMaterialfv *argp)
{
    // Get function specific args
     GLenum face = argp->face;;
	 GLenum pname = argp->pname;;
	 const GLfloat *params  = argp->params;;

    // Call actual function
    glMaterialfv(face, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMaterialiv
void *glmaterialiv_lh(args_glMaterialiv *argp)
{
    // Get function specific args
     GLenum face = argp->face;;
	 GLenum pname = argp->pname;;
	 const GLint *params  = argp->params;;

    // Call actual function
    glMaterialiv(face, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetMaterialfv
void *glgetmaterialfv_lh(args_glGetMaterialfv *argp)
{
    // Get function specific args
     GLenum face = argp->face;;
	 GLenum pname = argp->pname;;
	 GLfloat *params  = argp->params;;

    // Call actual function
    glGetMaterialfv(face, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetMaterialiv
void *glgetmaterialiv_lh(args_glGetMaterialiv *argp)
{
    // Get function specific args
     GLenum face = argp->face;;
	 GLenum pname = argp->pname;;
	 GLint *params  = argp->params;;

    // Call actual function
    glGetMaterialiv(face, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColorMaterial
void *glcolormaterial_lh(args_glColorMaterial *argp)
{
    // Get function specific args
     GLenum face = argp->face;;
	 GLenum mode  = argp->mode;;

    // Call actual function
    glColorMaterial(face, mode);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPixelZoom
void *glpixelzoom_lh(args_glPixelZoom *argp)
{
    // Get function specific args
     GLfloat xfactor = argp->xfactor;;
	 GLfloat yfactor  = argp->yfactor;;

    // Call actual function
    glPixelZoom(xfactor, yfactor);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPixelStoref
void *glpixelstoref_lh(args_glPixelStoref *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLfloat param  = argp->param;;

    // Call actual function
    glPixelStoref(pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPixelStorei
void *glpixelstorei_lh(args_glPixelStorei *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLint param  = argp->param;;

    // Call actual function
    glPixelStorei(pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPixelTransferf
void *glpixeltransferf_lh(args_glPixelTransferf *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLfloat param  = argp->param;;

    // Call actual function
    glPixelTransferf(pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPixelTransferi
void *glpixeltransferi_lh(args_glPixelTransferi *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLint param  = argp->param;;

    // Call actual function
    glPixelTransferi(pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPixelMapfv
void *glpixelmapfv_lh(args_glPixelMapfv *argp)
{
    // Get function specific args
     GLenum map = argp->map;;
	 GLsizei mapsize = argp->mapsize;;
	 const GLfloat *values  = argp->values;;

    // Call actual function
    glPixelMapfv(map, mapsize, values);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPixelMapuiv
void *glpixelmapuiv_lh(args_glPixelMapuiv *argp)
{
    // Get function specific args
     GLenum map = argp->map;;
	 GLsizei mapsize = argp->mapsize;;
	 const GLuint *values  = argp->values;;

    // Call actual function
    glPixelMapuiv(map, mapsize, values);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPixelMapusv
void *glpixelmapusv_lh(args_glPixelMapusv *argp)
{
    // Get function specific args
     GLenum map = argp->map;;
	 GLsizei mapsize = argp->mapsize;;
	 const GLushort *values  = argp->values;;

    // Call actual function
    glPixelMapusv(map, mapsize, values);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetPixelMapfv
void *glgetpixelmapfv_lh(args_glGetPixelMapfv *argp)
{
    // Get function specific args
     GLenum map = argp->map;;
	 GLfloat *values  = argp->values;;

    // Call actual function
    glGetPixelMapfv(map, values);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetPixelMapuiv
void *glgetpixelmapuiv_lh(args_glGetPixelMapuiv *argp)
{
    // Get function specific args
     GLenum map = argp->map;;
	 GLuint *values  = argp->values;;

    // Call actual function
    glGetPixelMapuiv(map, values);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetPixelMapusv
void *glgetpixelmapusv_lh(args_glGetPixelMapusv *argp)
{
    // Get function specific args
     GLenum map = argp->map;;
	 GLushort *values  = argp->values;;

    // Call actual function
    glGetPixelMapusv(map, values);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glBitmap
void *glbitmap_lh(args_glBitmap *argp)
{
    // Get function specific args
     GLsizei width = argp->width;;
	 GLsizei height = argp->height;;
	 GLfloat xorig = argp->xorig;;
	 GLfloat yorig = argp->yorig;;
	 GLfloat xmove = argp->xmove;;
	 GLfloat ymove = argp->ymove;;
	 const GLubyte *bitmap  = argp->bitmap;;

    // Call actual function
    glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glReadPixels
void *glreadpixels_lh(args_glReadPixels *argp)
{
    // Get function specific args
     GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLsizei width = argp->width;;
	 GLsizei height = argp->height;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 GLvoid *pixels  = argp->pixels;;

    // Call actual function
    glReadPixels(x, y, width, height, format, type, pixels);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glDrawPixels
void *gldrawpixels_lh(args_glDrawPixels *argp)
{
    // Get function specific args
     GLsizei width = argp->width;;
	 GLsizei height = argp->height;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 const GLvoid *pixels  = argp->pixels;;

    // Call actual function
    glDrawPixels(width, height, format, type, pixels);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCopyPixels
void *glcopypixels_lh(args_glCopyPixels *argp)
{
    // Get function specific args
     GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLsizei width = argp->width;;
	 GLsizei height = argp->height;;
	 GLenum type  = argp->type;;

    // Call actual function
    glCopyPixels(x, y, width, height, type);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glStencilFunc
void *glstencilfunc_lh(args_glStencilFunc *argp)
{
    // Get function specific args
     GLenum func = argp->func;;
	 GLint ref = argp->ref;;
	 GLuint mask  = argp->mask;;

    // Call actual function
    glStencilFunc(func, ref, mask);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glStencilMask
void *glstencilmask_lh(args_glStencilMask *argp)
{
    // Get function specific args
     GLuint mask  = argp->mask;;

    // Call actual function
    glStencilMask(mask);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glStencilOp
void *glstencilop_lh(args_glStencilOp *argp)
{
    // Get function specific args
     GLenum fail = argp->fail;;
	 GLenum zfail = argp->zfail;;
	 GLenum zpass  = argp->zpass;;

    // Call actual function
    glStencilOp(fail, zfail, zpass);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glClearStencil
void *glclearstencil_lh(args_glClearStencil *argp)
{
    // Get function specific args
     GLint s  = argp->s;;

    // Call actual function
    glClearStencil(s);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexGend
void *gltexgend_lh(args_glTexGend *argp)
{
    // Get function specific args
     GLenum coord = argp->coord;;
	 GLenum pname = argp->pname;;
	 GLdouble param  = argp->param;;

    // Call actual function
    glTexGend(coord, pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexGenf
void *gltexgenf_lh(args_glTexGenf *argp)
{
    // Get function specific args
     GLenum coord = argp->coord;;
	 GLenum pname = argp->pname;;
	 GLfloat param  = argp->param;;

    // Call actual function
    glTexGenf(coord, pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexGeni
void *gltexgeni_lh(args_glTexGeni *argp)
{
    // Get function specific args
     GLenum coord = argp->coord;;
	 GLenum pname = argp->pname;;
	 GLint param  = argp->param;;

    // Call actual function
    glTexGeni(coord, pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexGendv
void *gltexgendv_lh(args_glTexGendv *argp)
{
    // Get function specific args
     GLenum coord = argp->coord;;
	 GLenum pname = argp->pname;;
	 const GLdouble *params  = argp->params;;

    // Call actual function
    glTexGendv(coord, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexGenfv
void *gltexgenfv_lh(args_glTexGenfv *argp)
{
    // Get function specific args
     GLenum coord = argp->coord;;
	 GLenum pname = argp->pname;;
	 const GLfloat *params  = argp->params;;

    // Call actual function
    glTexGenfv(coord, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexGeniv
void *gltexgeniv_lh(args_glTexGeniv *argp)
{
    // Get function specific args
     GLenum coord = argp->coord;;
	 GLenum pname = argp->pname;;
	 const GLint *params  = argp->params;;

    // Call actual function
    glTexGeniv(coord, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetTexGendv
void *glgettexgendv_lh(args_glGetTexGendv *argp)
{
    // Get function specific args
     GLenum coord = argp->coord;;
	 GLenum pname = argp->pname;;
	 GLdouble *params  = argp->params;;

    // Call actual function
    glGetTexGendv(coord, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetTexGenfv
void *glgettexgenfv_lh(args_glGetTexGenfv *argp)
{
    // Get function specific args
     GLenum coord = argp->coord;;
	 GLenum pname = argp->pname;;
	 GLfloat *params  = argp->params;;

    // Call actual function
    glGetTexGenfv(coord, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetTexGeniv
void *glgettexgeniv_lh(args_glGetTexGeniv *argp)
{
    // Get function specific args
     GLenum coord = argp->coord;;
	 GLenum pname = argp->pname;;
	 GLint *params  = argp->params;;

    // Call actual function
    glGetTexGeniv(coord, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexEnvf
void *gltexenvf_lh(args_glTexEnvf *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLfloat param  = argp->param;;

    // Call actual function
    glTexEnvf(target, pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexEnvi
void *gltexenvi_lh(args_glTexEnvi *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLint param  = argp->param;;

    // Call actual function
    glTexEnvi(target, pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexEnvfv
void *gltexenvfv_lh(args_glTexEnvfv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 const GLfloat *params  = argp->params;;

    // Call actual function
    glTexEnvfv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexEnviv
void *gltexenviv_lh(args_glTexEnviv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 const GLint *params  = argp->params;;

    // Call actual function
    glTexEnviv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetTexEnvfv
void *glgettexenvfv_lh(args_glGetTexEnvfv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLfloat *params  = argp->params;;

    // Call actual function
    glGetTexEnvfv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetTexEnviv
void *glgettexenviv_lh(args_glGetTexEnviv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLint *params  = argp->params;;

    // Call actual function
    glGetTexEnviv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexParameterf
void *gltexparameterf_lh(args_glTexParameterf *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLfloat param  = argp->param;;

    // Call actual function
    glTexParameterf(target, pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexParameteri
void *gltexparameteri_lh(args_glTexParameteri *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLint param  = argp->param;;

    // Call actual function
    glTexParameteri(target, pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexParameterfv
void *gltexparameterfv_lh(args_glTexParameterfv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 const GLfloat *params  = argp->params;;

    // Call actual function
    glTexParameterfv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexParameteriv
void *gltexparameteriv_lh(args_glTexParameteriv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 const GLint *params  = argp->params;;

    // Call actual function
    glTexParameteriv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetTexParameterfv
void *glgettexparameterfv_lh(args_glGetTexParameterfv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLfloat *params = argp->params;;

    // Call actual function
    glGetTexParameterfv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetTexParameteriv
void *glgettexparameteriv_lh(args_glGetTexParameteriv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLint *params  = argp->params;;

    // Call actual function
    glGetTexParameteriv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetTexLevelParameterfv
void *glgettexlevelparameterfv_lh(args_glGetTexLevelParameterfv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLenum pname = argp->pname;;
	 GLfloat *params  = argp->params;;

    // Call actual function
    glGetTexLevelParameterfv(target, level, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetTexLevelParameteriv
void *glgettexlevelparameteriv_lh(args_glGetTexLevelParameteriv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLenum pname = argp->pname;;
	 GLint *params  = argp->params;;

    // Call actual function
    glGetTexLevelParameteriv(target, level, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexImage1D
void *glteximage1d_lh(args_glTexImage1D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLint internalFormat = argp->internalFormat;;
	 GLsizei width = argp->width;;
	 GLint border = argp->border;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 const GLvoid *pixels  = argp->pixels;;

    // Call actual function
    glTexImage1D(target, level, internalFormat, width, border, format, type, pixels);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexImage2D
void *glteximage2d_lh(args_glTexImage2D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLint internalFormat = argp->internalFormat;;
	 GLsizei width = argp->width;;
	 GLsizei height = argp->height;;
	 GLint border = argp->border;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 const GLvoid *pixels  = argp->pixels;;

    // Call actual function
    glTexImage2D(target, level, internalFormat, width, height, border, format, type, pixels);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetTexImage
void *glgetteximage_lh(args_glGetTexImage *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	  GLenum format = argp->format;;
	 GLenum type = argp->type;;
	  GLvoid *pixels  = argp->pixels;;

    // Call actual function
    glGetTexImage(target, level, format, type, pixels);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGenTextures
void *glgentextures_lh(args_glGenTextures *argp)
{
    // Get function specific args
     GLsizei n = argp->n;;
	 GLuint *textures  = argp->textures;;

    // Call actual function
    glGenTextures(n, textures);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glDeleteTextures
void *gldeletetextures_lh(args_glDeleteTextures *argp)
{
    // Get function specific args
     GLsizei n = argp->n;;
	 const GLuint *textures = argp->textures;;

    // Call actual function
    glDeleteTextures(n, textures);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glBindTexture
void *glbindtexture_lh(args_glBindTexture *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLuint texture  = argp->texture;;

    // Call actual function
    glBindTexture(target, texture);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPrioritizeTextures
void *glprioritizetextures_lh(args_glPrioritizeTextures *argp)
{
    // Get function specific args
     GLsizei n = argp->n;;
	 const GLuint *textures = argp->textures;;
	 const GLclampf *priorities  = argp->priorities;;

    // Call actual function
    glPrioritizeTextures(n, textures, priorities);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glAreTexturesResident
GLboolean *glaretexturesresident_lh(args_glAreTexturesResident *argp)
{
    // Get function specific args
     GLsizei n = argp->n;;
	 const GLuint *textures = argp->textures;;
	 GLboolean *residences  = argp->residences;;

    // Call actual function
    GLboolean result = glAreTexturesResident(n, textures, residences);

    // Memcopy in Buffer
    int ret_size = sizeof(GLboolean);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = GLBOOLEAN;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIsTexture
GLboolean *glistexture_lh(args_glIsTexture *argp)
{
    // Get function specific args
     GLuint texture  = argp->texture;;

    // Call actual function
    GLboolean result = glIsTexture(texture);

    // Memcopy in Buffer
    int ret_size = sizeof(GLboolean);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = GLBOOLEAN;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexSubImage1D
void *gltexsubimage1d_lh(args_glTexSubImage1D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLint xoffset = argp->xoffset;;
	 GLsizei width = argp->width;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 const GLvoid *pixels  = argp->pixels;;

    // Call actual function
    glTexSubImage1D(target, level, xoffset, width, format, type, pixels);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexSubImage2D
void *gltexsubimage2d_lh(args_glTexSubImage2D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLint xoffset = argp->xoffset;;
	 GLint yoffset = argp->yoffset;;
	 GLsizei width = argp->width;;
	 GLsizei height = argp->height;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 const GLvoid *pixels  = argp->pixels;;

    // Call actual function
    glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCopyTexImage1D
void *glcopyteximage1d_lh(args_glCopyTexImage1D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLenum internalformat = argp->internalformat;;
	 GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLsizei width = argp->width;;
	 GLint border  = argp->border;;

    // Call actual function
    glCopyTexImage1D(target, level, internalformat, x, y, width, border);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCopyTexImage2D
void *glcopyteximage2d_lh(args_glCopyTexImage2D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLenum internalformat = argp->internalformat;;
	 GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLsizei width = argp->width;;
	 GLsizei height = argp->height;;
	 GLint border  = argp->border;;

    // Call actual function
    glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCopyTexSubImage1D
void *glcopytexsubimage1d_lh(args_glCopyTexSubImage1D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	GLint xoffset = argp->xoffset;;
	 GLint x = argp->x;;
	 GLint y = argp->y;;
	GLsizei width  = argp->width;;

    // Call actual function
    glCopyTexSubImage1D(target, level, xoffset, x, y, width);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCopyTexSubImage2D
void *glcopytexsubimage2d_lh(args_glCopyTexSubImage2D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	GLint xoffset = argp->xoffset;;
	 GLint yoffset = argp->yoffset;;
	GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLsizei width = argp->width;;
	 GLsizei height  = argp->height;;

    // Call actual function
    glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMap1d
void *glmap1d_lh(args_glMap1d *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLdouble u1 = argp->u1;;
	 GLdouble u2 = argp->u2;;
	 GLint stride = argp->stride;;
	 GLint order = argp->order;;
	 const GLdouble *points  = argp->points;;

    // Call actual function
    glMap1d(target, u1, u2, stride, order, points);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMap1f
void *glmap1f_lh(args_glMap1f *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLfloat u1 = argp->u1;;
	 GLfloat u2 = argp->u2;;
	 GLint stride = argp->stride;;
	 GLint order = argp->order;;
	 const GLfloat *points  = argp->points;;

    // Call actual function
    glMap1f(target, u1, u2, stride, order, points);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMap2d
void *glmap2d_lh(args_glMap2d *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLdouble u1 = argp->u1;;
	 GLdouble u2 = argp->u2;;
	 GLint ustride = argp->ustride;;
	 GLint uorder = argp->uorder;;
	 GLdouble v1 = argp->v1;;
	 GLdouble v2 = argp->v2;;
	 GLint vstride = argp->vstride;;
	 GLint vorder = argp->vorder;;
	 const GLdouble *points  = argp->points;;

    // Call actual function
    glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMap2f
void *glmap2f_lh(args_glMap2f *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLfloat u1 = argp->u1;;
	 GLfloat u2 = argp->u2;;
	 GLint ustride = argp->ustride;;
	 GLint uorder = argp->uorder;;
	 GLfloat v1 = argp->v1;;
	 GLfloat v2 = argp->v2;;
	 GLint vstride = argp->vstride;;
	 GLint vorder = argp->vorder;;
	 const GLfloat *points  = argp->points;;

    // Call actual function
    glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetMapdv
void *glgetmapdv_lh(args_glGetMapdv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum query = argp->query;;
	 GLdouble *v  = argp->v;;

    // Call actual function
    glGetMapdv(target, query, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetMapfv
void *glgetmapfv_lh(args_glGetMapfv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum query = argp->query;;
	 GLfloat *v  = argp->v;;

    // Call actual function
    glGetMapfv(target, query, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetMapiv
void *glgetmapiv_lh(args_glGetMapiv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum query = argp->query;;
	 GLint *v  = argp->v;;

    // Call actual function
    glGetMapiv(target, query, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEvalCoord1d
void *glevalcoord1d_lh(args_glEvalCoord1d *argp)
{
    // Get function specific args
     GLdouble u  = argp->u;;

    // Call actual function
    glEvalCoord1d(u);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEvalCoord1f
void *glevalcoord1f_lh(args_glEvalCoord1f *argp)
{
    // Get function specific args
     GLfloat u  = argp->u;;

    // Call actual function
    glEvalCoord1f(u);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEvalCoord1dv
void *glevalcoord1dv_lh(args_glEvalCoord1dv *argp)
{
    // Get function specific args
     const GLdouble *u  = argp->u;;

    // Call actual function
    glEvalCoord1dv(u);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEvalCoord1fv
void *glevalcoord1fv_lh(args_glEvalCoord1fv *argp)
{
    // Get function specific args
     const GLfloat *u  = argp->u;;

    // Call actual function
    glEvalCoord1fv(u);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEvalCoord2d
void *glevalcoord2d_lh(args_glEvalCoord2d *argp)
{
    // Get function specific args
     GLdouble u = argp->u;;
	 GLdouble v  = argp->v;;

    // Call actual function
    glEvalCoord2d(u, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEvalCoord2f
void *glevalcoord2f_lh(args_glEvalCoord2f *argp)
{
    // Get function specific args
     GLfloat u = argp->u;;
	 GLfloat v  = argp->v;;

    // Call actual function
    glEvalCoord2f(u, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEvalCoord2dv
void *glevalcoord2dv_lh(args_glEvalCoord2dv *argp)
{
    // Get function specific args
     const GLdouble *u  = argp->u;;

    // Call actual function
    glEvalCoord2dv(u);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEvalCoord2fv
void *glevalcoord2fv_lh(args_glEvalCoord2fv *argp)
{
    // Get function specific args
     const GLfloat *u  = argp->u;;

    // Call actual function
    glEvalCoord2fv(u);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMapGrid1d
void *glmapgrid1d_lh(args_glMapGrid1d *argp)
{
    // Get function specific args
     GLint un = argp->un;;
	 GLdouble u1 = argp->u1;;
	 GLdouble u2  = argp->u2;;

    // Call actual function
    glMapGrid1d(un, u1, u2);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMapGrid1f
void *glmapgrid1f_lh(args_glMapGrid1f *argp)
{
    // Get function specific args
     GLint un = argp->un;;
	 GLfloat u1 = argp->u1;;
	 GLfloat u2  = argp->u2;;

    // Call actual function
    glMapGrid1f(un, u1, u2);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMapGrid2d
void *glmapgrid2d_lh(args_glMapGrid2d *argp)
{
    // Get function specific args
     GLint un = argp->un;;
	 GLdouble u1 = argp->u1;;
	 GLdouble u2 = argp->u2;;
	 GLint vn = argp->vn;;
	 GLdouble v1 = argp->v1;;
	 GLdouble v2  = argp->v2;;

    // Call actual function
    glMapGrid2d(un, u1, u2, vn, v1, v2);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMapGrid2f
void *glmapgrid2f_lh(args_glMapGrid2f *argp)
{
    // Get function specific args
     GLint un = argp->un;;
	 GLfloat u1 = argp->u1;;
	 GLfloat u2 = argp->u2;;
	 GLint vn = argp->vn;;
	 GLfloat v1 = argp->v1;;
	 GLfloat v2  = argp->v2;;

    // Call actual function
    glMapGrid2f(un, u1, u2, vn, v1, v2);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEvalPoint1
void *glevalpoint1_lh(args_glEvalPoint1 *argp)
{
    // Get function specific args
     GLint i  = argp->i;;

    // Call actual function
    glEvalPoint1(i);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEvalPoint2
void *glevalpoint2_lh(args_glEvalPoint2 *argp)
{
    // Get function specific args
     GLint i = argp->i;;
	 GLint j  = argp->j;;

    // Call actual function
    glEvalPoint2(i, j);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEvalMesh1
void *glevalmesh1_lh(args_glEvalMesh1 *argp)
{
    // Get function specific args
     GLenum mode = argp->mode;;
	 GLint i1 = argp->i1;;
	 GLint i2  = argp->i2;;

    // Call actual function
    glEvalMesh1(mode, i1, i2);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEvalMesh2
void *glevalmesh2_lh(args_glEvalMesh2 *argp)
{
    // Get function specific args
     GLenum mode = argp->mode;;
	 GLint i1 = argp->i1;;
	 GLint i2 = argp->i2;;
	 GLint j1 = argp->j1;;
	 GLint j2  = argp->j2;;

    // Call actual function
    glEvalMesh2(mode, i1, i2, j1, j2);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glFogf
void *glfogf_lh(args_glFogf *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLfloat param  = argp->param;;

    // Call actual function
    glFogf(pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glFogi
void *glfogi_lh(args_glFogi *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLint param  = argp->param;;

    // Call actual function
    glFogi(pname, param);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glFogfv
void *glfogfv_lh(args_glFogfv *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 const GLfloat *params  = argp->params;;

    // Call actual function
    glFogfv(pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glFogiv
void *glfogiv_lh(args_glFogiv *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 const GLint *params  = argp->params;;

    // Call actual function
    glFogiv(pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glFeedbackBuffer
void *glfeedbackbuffer_lh(args_glFeedbackBuffer *argp)
{
    // Get function specific args
     GLsizei size = argp->size;;
	 GLenum type = argp->type;;
	 GLfloat *buffer  = argp->buffer;;

    // Call actual function
    glFeedbackBuffer(size, type, buffer);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPassThrough
void *glpassthrough_lh(args_glPassThrough *argp)
{
    // Get function specific args
     GLfloat token  = argp->token;;

    // Call actual function
    glPassThrough(token);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glSelectBuffer
void *glselectbuffer_lh(args_glSelectBuffer *argp)
{
    // Get function specific args
     GLsizei size = argp->size;;
	 GLuint *buffer  = argp->buffer;;

    // Call actual function
    glSelectBuffer(size, buffer);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glInitNames
void *glinitnames_lh()
{
    // No function specific args

    // Call actual function
    glInitNames();

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLoadName
void *glloadname_lh(args_glLoadName *argp)
{
    // Get function specific args
     GLuint name  = argp->name;;

    // Call actual function
    glLoadName(name);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPushName
void *glpushname_lh(args_glPushName *argp)
{
    // Get function specific args
     GLuint name  = argp->name;;

    // Call actual function
    glPushName(name);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPopName
void *glpopname_lh()
{
    // No function specific args

    // Call actual function
    glPopName();

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glDrawRangeElements
void *gldrawrangeelements_lh(args_glDrawRangeElements *argp)
{
    // Get function specific args
     GLenum mode = argp->mode;;
	 GLuint start = argp->start;;
	 GLuint end = argp->end;;
	 GLsizei count = argp->count;;
	 GLenum type = argp->type;;
	 const GLvoid *indices  = argp->indices;;

    // Call actual function
    glDrawRangeElements(mode, start, end, count, type, indices);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexImage3D
void *glteximage3d_lh(args_glTexImage3D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLint internalFormat = argp->internalFormat;;
	 GLsizei width = argp->width;;
	 GLsizei height = argp->height;;
	 GLsizei depth = argp->depth;;
	 GLint border = argp->border;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 const GLvoid *pixels  = argp->pixels;;

    // Call actual function
    glTexImage3D(target, level, internalFormat, width, height, depth, border, format, type, pixels);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glTexSubImage3D
void *gltexsubimage3d_lh(args_glTexSubImage3D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLint xoffset = argp->xoffset;;
	 GLint yoffset = argp->yoffset;;
	 GLint zoffset = argp->zoffset;;
	 GLsizei width = argp->width;;
	 GLsizei height = argp->height;;
	 GLsizei depth = argp->depth;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 const GLvoid *pixels = argp->pixels;;

    // Call actual function
    glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCopyTexSubImage3D
void *glcopytexsubimage3d_lh(args_glCopyTexSubImage3D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLint xoffset = argp->xoffset;;
	 GLint yoffset = argp->yoffset;;
	 GLint zoffset = argp->zoffset;;
	 GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLsizei width = argp->width;;
	 GLsizei height  = argp->height;;

    // Call actual function
    glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColorTable
void *glcolortable_lh(args_glColorTable *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum internalformat = argp->internalformat;;
	 GLsizei width = argp->width;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 const GLvoid *table  = argp->table;;

    // Call actual function
    glColorTable(target, internalformat, width, format, type, table);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColorSubTable
void *glcolorsubtable_lh(args_glColorSubTable *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLsizei start = argp->start;;
	 GLsizei count = argp->count;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 const GLvoid *data  = argp->data;;

    // Call actual function
    glColorSubTable(target, start, count, format, type, data);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColorTableParameteriv
void *glcolortableparameteriv_lh(args_glColorTableParameteriv *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 const GLint *params = argp->params;;

    // Call actual function
    glColorTableParameteriv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glColorTableParameterfv
void *glcolortableparameterfv_lh(args_glColorTableParameterfv *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 const GLfloat *params = argp->params;;

    // Call actual function
    glColorTableParameterfv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCopyColorSubTable
void *glcopycolorsubtable_lh(args_glCopyColorSubTable *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLsizei start = argp->start;;
	GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLsizei width  = argp->width;;

    // Call actual function
    glCopyColorSubTable(target, start, x, y, width);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCopyColorTable
void *glcopycolortable_lh(args_glCopyColorTable *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum internalformat = argp->internalformat;;
	 GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLsizei width  = argp->width;;

    // Call actual function
    glCopyColorTable(target, internalformat, x, y, width);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetColorTable
void *glgetcolortable_lh(args_glGetColorTable *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 GLvoid *table  = argp->table;;

    // Call actual function
    glGetColorTable(target, format, type, table);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetColorTableParameterfv
void *glgetcolortableparameterfv_lh(args_glGetColorTableParameterfv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLfloat *params  = argp->params;;

    // Call actual function
    glGetColorTableParameterfv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetColorTableParameteriv
void *glgetcolortableparameteriv_lh(args_glGetColorTableParameteriv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLint *params  = argp->params;;

    // Call actual function
    glGetColorTableParameteriv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glBlendEquation
void *glblendequation_lh(args_glBlendEquation *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;;

    // Call actual function
    glBlendEquation(mode);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glBlendColor
void *glblendcolor_lh(args_glBlendColor *argp)
{
    // Get function specific args
     GLclampf red = argp->red;;
	 GLclampf green = argp->green;;
	 GLclampf blue = argp->blue;;
	 GLclampf alpha  = argp->alpha;;

    // Call actual function
    glBlendColor(red, green, blue, alpha);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glHistogram
void *glhistogram_lh(args_glHistogram *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLsizei width = argp->width;;
	 GLenum internalformat = argp->internalformat;;
	 GLboolean sink  = argp->sink;;

    // Call actual function
    glHistogram(target, width, internalformat, sink);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glResetHistogram
void *glresethistogram_lh(args_glResetHistogram *argp)
{
    // Get function specific args
     GLenum target  = argp->target;;

    // Call actual function
    glResetHistogram(target);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetHistogram
void *glgethistogram_lh(args_glGetHistogram *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLboolean reset = argp->reset;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 GLvoid *values  = argp->values;;

    // Call actual function
    glGetHistogram(target, reset, format, type, values);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetHistogramParameterfv
void *glgethistogramparameterfv_lh(args_glGetHistogramParameterfv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLfloat *params  = argp->params;;

    // Call actual function
    glGetHistogramParameterfv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetHistogramParameteriv
void *glgethistogramparameteriv_lh(args_glGetHistogramParameteriv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLint *params  = argp->params;;

    // Call actual function
    glGetHistogramParameteriv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMinmax
void *glminmax_lh(args_glMinmax *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum internalformat = argp->internalformat;;
	 GLboolean sink  = argp->sink;;

    // Call actual function
    glMinmax(target, internalformat, sink);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glResetMinmax
void *glresetminmax_lh(args_glResetMinmax *argp)
{
    // Get function specific args
     GLenum target  = argp->target;;

    // Call actual function
    glResetMinmax(target);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetMinmax
void *glgetminmax_lh(args_glGetMinmax *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLboolean reset = argp->reset;;
	 GLenum format = argp->format;;
	 GLenum types = argp->types;;
	 GLvoid *values  = argp->values;;

    // Call actual function
    glGetMinmax(target, reset, format, types, values);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetMinmaxParameterfv
void *glgetminmaxparameterfv_lh(args_glGetMinmaxParameterfv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLfloat *params  = argp->params;;

    // Call actual function
    glGetMinmaxParameterfv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetMinmaxParameteriv
void *glgetminmaxparameteriv_lh(args_glGetMinmaxParameteriv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLint *params  = argp->params;;

    // Call actual function
    glGetMinmaxParameteriv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glConvolutionFilter1D
void *glconvolutionfilter1d_lh(args_glConvolutionFilter1D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum internalformat = argp->internalformat;;
	 GLsizei width = argp->width;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 const GLvoid *image  = argp->image;;

    // Call actual function
    glConvolutionFilter1D(target, internalformat, width, format, type, image);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glConvolutionFilter2D
void *glconvolutionfilter2d_lh(args_glConvolutionFilter2D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum internalformat = argp->internalformat;;
	 GLsizei width = argp->width;;
	 GLsizei height = argp->height;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 const GLvoid *image  = argp->image;;

    // Call actual function
    glConvolutionFilter2D(target, internalformat, width, height, format, type, image);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glConvolutionParameterf
void *glconvolutionparameterf_lh(args_glConvolutionParameterf *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLfloat params  = argp->params;;

    // Call actual function
    glConvolutionParameterf(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glConvolutionParameterfv
void *glconvolutionparameterfv_lh(args_glConvolutionParameterfv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 const GLfloat *params  = argp->params;;

    // Call actual function
    glConvolutionParameterfv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glConvolutionParameteri
void *glconvolutionparameteri_lh(args_glConvolutionParameteri *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLint params  = argp->params;;

    // Call actual function
    glConvolutionParameteri(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glConvolutionParameteriv
void *glconvolutionparameteriv_lh(args_glConvolutionParameteriv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 const GLint *params  = argp->params;;

    // Call actual function
    glConvolutionParameteriv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCopyConvolutionFilter1D
void *glcopyconvolutionfilter1d_lh(args_glCopyConvolutionFilter1D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum internalformat = argp->internalformat;;
	 GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLsizei width  = argp->width;;

    // Call actual function
    glCopyConvolutionFilter1D(target, internalformat, x, y, width);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCopyConvolutionFilter2D
void *glcopyconvolutionfilter2d_lh(args_glCopyConvolutionFilter2D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum internalformat = argp->internalformat;;
	 GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLsizei width = argp->width;;
	 GLsizei height = argp->height;;

    // Call actual function
    glCopyConvolutionFilter2D(target, internalformat, x, y, width, height);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetConvolutionFilter
void *glgetconvolutionfilter_lh(args_glGetConvolutionFilter *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 GLvoid *image  = argp->image;;

    // Call actual function
    glGetConvolutionFilter(target, format, type, image);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetConvolutionParameterfv
void *glgetconvolutionparameterfv_lh(args_glGetConvolutionParameterfv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLfloat *params  = argp->params;;

    // Call actual function
    glGetConvolutionParameterfv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetConvolutionParameteriv
void *glgetconvolutionparameteriv_lh(args_glGetConvolutionParameteriv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum pname = argp->pname;;
	 GLint *params  = argp->params;;

    // Call actual function
    glGetConvolutionParameteriv(target, pname, params);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glSeparableFilter2D
void *glseparablefilter2d_lh(args_glSeparableFilter2D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum internalformat = argp->internalformat;;
	 GLsizei width = argp->width;;
	 GLsizei height = argp->height;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 const GLvoid *row = argp->row;;
	 const GLvoid *column  = argp->column;;

    // Call actual function
    glSeparableFilter2D(target, internalformat, width, height, format, type, row, column);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetSeparableFilter
void *glgetseparablefilter_lh(args_glGetSeparableFilter *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLenum format = argp->format;;
	 GLenum type = argp->type;;
	 GLvoid *row = argp->row;;
	 GLvoid *column = argp->column;;
	 GLvoid *span  = argp->span;;

    // Call actual function
    glGetSeparableFilter(target, format, type, row, column, span);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glActiveTexture
void *glactivetexture_lh(args_glActiveTexture *argp)
{
    // Get function specific args
     GLenum texture  = argp->texture;;

    // Call actual function
    glActiveTexture(texture);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glClientActiveTexture
void *glclientactivetexture_lh(args_glClientActiveTexture *argp)
{
    // Get function specific args
     GLenum texture  = argp->texture;;

    // Call actual function
    glClientActiveTexture(texture);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCompressedTexImage1D
void *glcompressedteximage1d_lh(args_glCompressedTexImage1D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLenum internalformat = argp->internalformat;;
	 GLsizei width = argp->width;;
	 GLint border = argp->border;;
	 GLsizei imageSize = argp->imageSize;;
	 const GLvoid *data  = argp->data;;

    // Call actual function
    glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCompressedTexImage2D
void *glcompressedteximage2d_lh(args_glCompressedTexImage2D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLenum internalformat = argp->internalformat;;
	 GLsizei width = argp->width;;
	 GLsizei height = argp->height;;
	 GLint border = argp->border;;
	 GLsizei imageSize = argp->imageSize;;
	 const GLvoid *data  = argp->data;;

    // Call actual function
    glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCompressedTexImage3D
void *glcompressedteximage3d_lh(args_glCompressedTexImage3D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLenum internalformat = argp->internalformat;;
	 GLsizei width = argp->width;;
	 GLsizei height = argp->height;;
	 GLsizei depth = argp->depth;;
	 GLint border = argp->border;;
	 GLsizei imageSize = argp->imageSize;;
	 const GLvoid *data  = argp->data;;

    // Call actual function
    glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCompressedTexSubImage1D
void *glcompressedtexsubimage1d_lh(args_glCompressedTexSubImage1D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLint xoffset = argp->xoffset;;
	 GLsizei width = argp->width;;
	 GLenum format = argp->format;;
	 GLsizei imageSize = argp->imageSize;;
	 const GLvoid *data  = argp->data;;

    // Call actual function
    glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCompressedTexSubImage2D
void *glcompressedtexsubimage2d_lh(args_glCompressedTexSubImage2D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLint xoffset = argp->xoffset;;
	 GLint yoffset = argp->yoffset;;
	 GLsizei width = argp->width;;
	 GLsizei height = argp->height;;
	 GLenum format = argp->format;;
	 GLsizei imageSize = argp->imageSize;;
	 const GLvoid *data  = argp->data;;

    // Call actual function
    glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCompressedTexSubImage3D
void *glcompressedtexsubimage3d_lh(args_glCompressedTexSubImage3D *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint level = argp->level;;
	 GLint xoffset = argp->xoffset;;
	 GLint yoffset = argp->yoffset;;
	 GLint zoffset = argp->zoffset;;
	 GLsizei width = argp->width;;
	 GLsizei height = argp->height;;
	 GLsizei depth = argp->depth;;
	 GLenum format = argp->format;;
	 GLsizei imageSize = argp->imageSize;;
	 const GLvoid *data  = argp->data;;

    // Call actual function
    glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetCompressedTexImage
void *glgetcompressedteximage_lh(args_glGetCompressedTexImage *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint lod = argp->lod;;
	 GLvoid *img  = argp->img;;

    // Call actual function
    glGetCompressedTexImage(target, lod, img);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord1d
void *glmultitexcoord1d_lh(args_glMultiTexCoord1d *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLdouble s  = argp->s;;

    // Call actual function
    glMultiTexCoord1d(target, s);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord1dv
void *glmultitexcoord1dv_lh(args_glMultiTexCoord1dv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 const GLdouble *v  = argp->v;;

    // Call actual function
    glMultiTexCoord1dv(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord1f
void *glmultitexcoord1f_lh(args_glMultiTexCoord1f *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLfloat s  = argp->s;;

    // Call actual function
    glMultiTexCoord1f(target, s);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord1fv
void *glmultitexcoord1fv_lh(args_glMultiTexCoord1fv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 const GLfloat *v  = argp->v;;

    // Call actual function
    glMultiTexCoord1fv(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord1i
void *glmultitexcoord1i_lh(args_glMultiTexCoord1i *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint s  = argp->s;;

    // Call actual function
    glMultiTexCoord1i(target, s);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord1iv
void *glmultitexcoord1iv_lh(args_glMultiTexCoord1iv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 const GLint *v  = argp->v;;

    // Call actual function
    glMultiTexCoord1iv(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord1s
void *glmultitexcoord1s_lh(args_glMultiTexCoord1s *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLshort s  = argp->s;;

    // Call actual function
    glMultiTexCoord1s(target, s);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord1sv
void *glmultitexcoord1sv_lh(args_glMultiTexCoord1sv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 const GLshort *v  = argp->v;;

    // Call actual function
    glMultiTexCoord1sv(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord2d
void *glmultitexcoord2d_lh(args_glMultiTexCoord2d *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLdouble s = argp->s;;
	 GLdouble t  = argp->t;;

    // Call actual function
    glMultiTexCoord2d(target, s, t);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord2dv
void *glmultitexcoord2dv_lh(args_glMultiTexCoord2dv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 const GLdouble *v  = argp->v;;

    // Call actual function
    glMultiTexCoord2dv(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord2f
void *glmultitexcoord2f_lh(args_glMultiTexCoord2f *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLfloat s = argp->s;;
	 GLfloat t  = argp->t;;

    // Call actual function
    glMultiTexCoord2f(target, s, t);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord2fv
void *glmultitexcoord2fv_lh(args_glMultiTexCoord2fv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 const GLfloat *v  = argp->v;;

    // Call actual function
    glMultiTexCoord2fv(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord2i
void *glmultitexcoord2i_lh(args_glMultiTexCoord2i *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint s = argp->s;;
	 GLint t  = argp->t;;

    // Call actual function
    glMultiTexCoord2i(target, s, t);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord2iv
void *glmultitexcoord2iv_lh(args_glMultiTexCoord2iv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 const GLint *v  = argp->v;;

    // Call actual function
    glMultiTexCoord2iv(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord2s
void *glmultitexcoord2s_lh(args_glMultiTexCoord2s *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLshort s = argp->s;;
	 GLshort t  = argp->t;;

    // Call actual function
    glMultiTexCoord2s(target, s, t);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord2sv
void *glmultitexcoord2sv_lh(args_glMultiTexCoord2sv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 const GLshort *v  = argp->v;;

    // Call actual function
    glMultiTexCoord2sv(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord3d
void *glmultitexcoord3d_lh(args_glMultiTexCoord3d *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLdouble s = argp->s;;
	 GLdouble t = argp->t;;
	 GLdouble r  = argp->r;;

    // Call actual function
    glMultiTexCoord3d(target, s, t, r);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord3dv
void *glmultitexcoord3dv_lh(args_glMultiTexCoord3dv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 const GLdouble *v  = argp->v;;

    // Call actual function
    glMultiTexCoord3dv(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord3f
void *glmultitexcoord3f_lh(args_glMultiTexCoord3f *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLfloat s = argp->s;;
	 GLfloat t = argp->t;;
	 GLfloat r  = argp->r;;

    // Call actual function
    glMultiTexCoord3f(target, s, t, r);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord3fv
void *glmultitexcoord3fv_lh(args_glMultiTexCoord3fv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 const GLfloat *v  = argp->v;;

    // Call actual function
    glMultiTexCoord3fv(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord3i
void *glmultitexcoord3i_lh(args_glMultiTexCoord3i *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint s = argp->s;;
	 GLint t = argp->t;;
	 GLint r  = argp->r;;

    // Call actual function
    glMultiTexCoord3i(target, s, t, r);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord3iv
void *glmultitexcoord3iv_lh(args_glMultiTexCoord3iv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 const GLint *v  = argp->v;;

    // Call actual function
    glMultiTexCoord3iv(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord3s
void *glmultitexcoord3s_lh(args_glMultiTexCoord3s *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLshort s = argp->s;;
	 GLshort t = argp->t;;
	 GLshort r  = argp->r;;

    // Call actual function
    glMultiTexCoord3s(target, s, t, r);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord3sv
void *glmultitexcoord3sv_lh(args_glMultiTexCoord3sv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 const GLshort *v  = argp->v;;

    // Call actual function
    glMultiTexCoord3sv(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord4d
void *glmultitexcoord4d_lh(args_glMultiTexCoord4d *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLdouble s = argp->s;;
	 GLdouble t = argp->t;;
	 GLdouble r = argp->r;;
	 GLdouble q  = argp->q;;

    // Call actual function
    glMultiTexCoord4d(target, s, t, r, q);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord4dv
void *glmultitexcoord4dv_lh(args_glMultiTexCoord4dv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 const GLdouble *v  = argp->v;;

    // Call actual function
    glMultiTexCoord4dv(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord4f
void *glmultitexcoord4f_lh(args_glMultiTexCoord4f *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLfloat s = argp->s;;
	 GLfloat t = argp->t;;
	 GLfloat r = argp->r;;
	 GLfloat q  = argp->q;;

    // Call actual function
    glMultiTexCoord4f(target, s, t, r, q);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord4fv
void *glmultitexcoord4fv_lh(args_glMultiTexCoord4fv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 const GLfloat *v  = argp->v;;

    // Call actual function
    glMultiTexCoord4fv(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord4i
void *glmultitexcoord4i_lh(args_glMultiTexCoord4i *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLint s = argp->s;;
	 GLint t = argp->t;;
	 GLint r = argp->r;;
	 GLint q  = argp->q;;

    // Call actual function
    glMultiTexCoord4i(target, s, t, r, q);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord4iv
void *glmultitexcoord4iv_lh(args_glMultiTexCoord4iv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 const GLint *v  = argp->v;;

    // Call actual function
    glMultiTexCoord4iv(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord4s
void *glmultitexcoord4s_lh(args_glMultiTexCoord4s *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 GLshort s = argp->s;;
	 GLshort t = argp->t;;
	 GLshort r = argp->r;;
	 GLshort q  = argp->q;;

    // Call actual function
    glMultiTexCoord4s(target, s, t, r, q);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord4sv
void *glmultitexcoord4sv_lh(args_glMultiTexCoord4sv *argp)
{
    // Get function specific args
     GLenum target = argp->target;;
	 const GLshort *v  = argp->v;;

    // Call actual function
    glMultiTexCoord4sv(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glSampleCoverage
void *glsamplecoverage_lh(args_glSampleCoverage *argp)
{
    // Get function specific args
     GLclampf value = argp->value;;
	 GLboolean invert  = argp->invert;;

    // Call actual function
    glSampleCoverage(value, invert);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glActiveTextureARB
void *glactivetexturearb_lh(args_glActiveTextureARB *argp)
{
    // Get function specific args
    GLenum texture = argp->texture;;

    // Call actual function
    glActiveTextureARB(texture);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glClientActiveTextureARB
void *glclientactivetexturearb_lh(args_glClientActiveTextureARB *argp)
{
    // Get function specific args
    GLenum texture = argp->texture;;

    // Call actual function
    glClientActiveTextureARB(texture);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord1dARB
void *glmultitexcoord1darb_lh(args_glMultiTexCoord1dARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLdouble s = argp->s;;

    // Call actual function
    glMultiTexCoord1dARB(target, s);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord1dvARB
void *glmultitexcoord1dvarb_lh(args_glMultiTexCoord1dvARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 const GLdouble *v = argp->v;;

    // Call actual function
    glMultiTexCoord1dvARB(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord1fARB
void *glmultitexcoord1farb_lh(args_glMultiTexCoord1fARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLfloat s = argp->s;;

    // Call actual function
    glMultiTexCoord1fARB(target, s);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord1fvARB
void *glmultitexcoord1fvarb_lh(args_glMultiTexCoord1fvARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 const GLfloat *v = argp->v;;

    // Call actual function
    glMultiTexCoord1fvARB(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord1iARB
void *glmultitexcoord1iarb_lh(args_glMultiTexCoord1iARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLint s = argp->s;;

    // Call actual function
    glMultiTexCoord1iARB(target, s);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord1ivARB
void *glmultitexcoord1ivarb_lh(args_glMultiTexCoord1ivARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 const GLint *v = argp->v;;

    // Call actual function
    glMultiTexCoord1ivARB(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord1sARB
void *glmultitexcoord1sarb_lh(args_glMultiTexCoord1sARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLshort s = argp->s;;

    // Call actual function
    glMultiTexCoord1sARB(target, s);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord1svARB
void *glmultitexcoord1svarb_lh(args_glMultiTexCoord1svARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 const GLshort *v = argp->v;;

    // Call actual function
    glMultiTexCoord1svARB(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord2dARB
void *glmultitexcoord2darb_lh(args_glMultiTexCoord2dARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLdouble s = argp->s;;
	 GLdouble t = argp->t;;

    // Call actual function
    glMultiTexCoord2dARB(target, s, t);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord2dvARB
void *glmultitexcoord2dvarb_lh(args_glMultiTexCoord2dvARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 const GLdouble *v = argp->v;;

    // Call actual function
    glMultiTexCoord2dvARB(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord2fARB
void *glmultitexcoord2farb_lh(args_glMultiTexCoord2fARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLfloat s = argp->s;;
	 GLfloat t = argp->t;;

    // Call actual function
    glMultiTexCoord2fARB(target, s, t);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord2fvARB
void *glmultitexcoord2fvarb_lh(args_glMultiTexCoord2fvARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 const GLfloat *v = argp->v;;

    // Call actual function
    glMultiTexCoord2fvARB(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord2iARB
void *glmultitexcoord2iarb_lh(args_glMultiTexCoord2iARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLint s = argp->s;;
	 GLint t = argp->t;;

    // Call actual function
    glMultiTexCoord2iARB(target, s, t);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord2ivARB
void *glmultitexcoord2ivarb_lh(args_glMultiTexCoord2ivARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 const GLint *v = argp->v;;

    // Call actual function
    glMultiTexCoord2ivARB(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord2sARB
void *glmultitexcoord2sarb_lh(args_glMultiTexCoord2sARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLshort s = argp->s;;
	 GLshort t = argp->t;;

    // Call actual function
    glMultiTexCoord2sARB(target, s, t);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord2svARB
void *glmultitexcoord2svarb_lh(args_glMultiTexCoord2svARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 const GLshort *v = argp->v;;

    // Call actual function
    glMultiTexCoord2svARB(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord3dARB
void *glmultitexcoord3darb_lh(args_glMultiTexCoord3dARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLdouble s = argp->s;;
	 GLdouble t = argp->t;;
	 GLdouble r = argp->r;;

    // Call actual function
    glMultiTexCoord3dARB(target, s, t, r);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord3dvARB
void *glmultitexcoord3dvarb_lh(args_glMultiTexCoord3dvARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 const GLdouble *v = argp->v;;

    // Call actual function
    glMultiTexCoord3dvARB(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord3fARB
void *glmultitexcoord3farb_lh(args_glMultiTexCoord3fARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLfloat s = argp->s;;
	 GLfloat t = argp->t;;
	 GLfloat r = argp->r;;

    // Call actual function
    glMultiTexCoord3fARB(target, s, t, r);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord3fvARB
void *glmultitexcoord3fvarb_lh(args_glMultiTexCoord3fvARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 const GLfloat *v = argp->v;;

    // Call actual function
    glMultiTexCoord3fvARB(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord3iARB
void *glmultitexcoord3iarb_lh(args_glMultiTexCoord3iARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLint s = argp->s;;
	 GLint t = argp->t;;
	 GLint r = argp->r;;

    // Call actual function
    glMultiTexCoord3iARB(target, s, t, r);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord3ivARB
void *glmultitexcoord3ivarb_lh(args_glMultiTexCoord3ivARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 const GLint *v = argp->v;;

    // Call actual function
    glMultiTexCoord3ivARB(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord3sARB
void *glmultitexcoord3sarb_lh(args_glMultiTexCoord3sARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLshort s = argp->s;;
	 GLshort t = argp->t;;
	 GLshort r = argp->r;;

    // Call actual function
    glMultiTexCoord3sARB(target, s, t, r);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord3svARB
void *glmultitexcoord3svarb_lh(args_glMultiTexCoord3svARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 const GLshort *v = argp->v;;

    // Call actual function
    glMultiTexCoord3svARB(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord4dARB
void *glmultitexcoord4darb_lh(args_glMultiTexCoord4dARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLdouble s = argp->s;;
	 GLdouble t = argp->t;;
	 GLdouble r = argp->r;;
	 GLdouble q = argp->q;;

    // Call actual function
    glMultiTexCoord4dARB(target, s, t, r, q);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord4dvARB
void *glmultitexcoord4dvarb_lh(args_glMultiTexCoord4dvARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 const GLdouble *v = argp->v;;

    // Call actual function
    glMultiTexCoord4dvARB(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord4fARB
void *glmultitexcoord4farb_lh(args_glMultiTexCoord4fARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLfloat s = argp->s;;
	 GLfloat t = argp->t;;
	 GLfloat r = argp->r;;
	 GLfloat q = argp->q;;

    // Call actual function
    glMultiTexCoord4fARB(target, s, t, r, q);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord4fvARB
void *glmultitexcoord4fvarb_lh(args_glMultiTexCoord4fvARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 const GLfloat *v = argp->v;;

    // Call actual function
    glMultiTexCoord4fvARB(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord4iARB
void *glmultitexcoord4iarb_lh(args_glMultiTexCoord4iARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLint s = argp->s;;
	 GLint t = argp->t;;
	 GLint r = argp->r;;
	 GLint q = argp->q;;

    // Call actual function
    glMultiTexCoord4iARB(target, s, t, r, q);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord4ivARB
void *glmultitexcoord4ivarb_lh(args_glMultiTexCoord4ivARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 const GLint *v = argp->v;;

    // Call actual function
    glMultiTexCoord4ivARB(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord4sARB
void *glmultitexcoord4sarb_lh(args_glMultiTexCoord4sARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 GLshort s = argp->s;;
	 GLshort t = argp->t;;
	 GLshort r = argp->r;;
	 GLshort q = argp->q;;

    // Call actual function
    glMultiTexCoord4sARB(target, s, t, r, q);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glMultiTexCoord4svARB
void *glmultitexcoord4svarb_lh(args_glMultiTexCoord4svARB *argp)
{
    // Get function specific args
    GLenum target = argp->target;;
	 const GLshort *v = argp->v;;

    // Call actual function
    glMultiTexCoord4svARB(target, v);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glBlendEquationSeparateATI
void *glblendequationseparateati_lh(args_glBlendEquationSeparateATI *argp)
{
    // Get function specific args
     GLenum modeRGB = argp->modeRGB;;
	 GLenum modeA  = argp->modeA;;

    // Call actual function
    glBlendEquationSeparateATI(modeRGB, modeA);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXDestroyContext
void *glxdestroycontext_lh(args_glXDestroyContext *argp)
{
    // Get function specific args
     Display *dpy = argp->dpy;;
	 GLXContext ctx  = argp->ctx;;

    // Call actual function
    glXDestroyContext(dpy, ctx);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXSwapBuffers
void *glxswapbuffers_lh(args_glXSwapBuffers *argp)
{
    // Get function specific args
     Display *dpy = argp->dpy;;
	 GLXDrawable drawable  = argp->drawable;;

    // Call actual function
    glXSwapBuffers(dpy, drawable);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXDestroyGLXPixmap
void *glxdestroyglxpixmap_lh(args_glXDestroyGLXPixmap *argp)
{
    // Get function specific args
     Display *dpy = argp->dpy;;
	 GLXPixmap pixmap  = argp->pixmap;;

    // Call actual function
    glXDestroyGLXPixmap(dpy, pixmap);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXQueryExtension
Bool *glxqueryextension_lh(args_glXQueryExtension *argp)
{
    // Get function specific args
     Display *dpy = argp->dpy;;
	 int *errorb = argp->errorb;;
	 int *event  = argp->event;;

    // Call actual function
    Bool result = glXQueryExtension(dpy, errorb, event);

    // Memcopy in Buffer
    int ret_size = sizeof(Bool);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = BOOL;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXQueryVersion
Bool *glxqueryversion_lh(args_glXQueryVersion *argp)
{
    // Get function specific args
     Display *dpy = argp->dpy;;
	 int *maj = argp->maj;;
	 int *min  = argp->min;;

    // Call actual function
    Bool result = glXQueryVersion(dpy, maj, min);

    // Memcopy in Buffer
    int ret_size = sizeof(Bool);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = BOOL;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXIsDirect
Bool *glxisdirect_lh(args_glXIsDirect *argp)
{
    // Get function specific args
     Display *dpy = argp->dpy;;
	 GLXContext ctx  = argp->ctx;;

    // Call actual function
    Bool result = glXIsDirect(dpy, ctx);

    // Memcopy in Buffer
    int ret_size = sizeof(Bool);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = BOOL;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXGetCurrentContext
GLXContext *glxgetcurrentcontext_lh()
{
    // No function specific args

    // Call actual function
    GLXContext result = glXGetCurrentContext();

    // Memcopy in Buffer
    int ret_size = sizeof(GLXContext);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = GLXCONTEXT;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXGetCurrentDrawable
GLXDrawable *glxgetcurrentdrawable_lh()
{
    // No function specific args

    // Call actual function
    GLXDrawable result = glXGetCurrentDrawable();

    // Memcopy in Buffer
    int ret_size = sizeof(GLXDrawable);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = GLXDRAWABLE;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXWaitGL
void *glxwaitgl_lh()
{
    // No function specific args

    // Call actual function
    glXWaitGL();

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXWaitX
void *glxwaitx_lh()
{
    // No function specific args

    // Call actual function
    glXWaitX();

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXUseXFont
void *glxusexfont_lh(args_glXUseXFont *argp)
{
    // Get function specific args
     Font font = argp->font;;
	 int first = argp->first;;
	 int count = argp->count;;
	 int list  = argp->list;;

    // Call actual function
    glXUseXFont(font, first, count, list);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXQueryExtensionsString
char* *glxqueryextensionsstring_lh(args_glXQueryExtensionsString *argp)
{
    // Get function specific args
     Display *dpy = argp->dpy;;
	 int screen  = argp->screen;;

    // Call actual function
    char* result = glXQueryExtensionsString(dpy, screen);

    // Memcopy in Buffer
    int ret_size = sizeof(char*);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = CHARP;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXQueryServerString
char* *glxqueryserverstring_lh(args_glXQueryServerString *argp)
{
    // Get function specific args
     Display *dpy = argp->dpy;;
	 int screen = argp->screen;;
	 int name  = argp->name;;

    // Call actual function
    char* result = glXQueryServerString(dpy, screen, name);

    // Memcopy in Buffer
    int ret_size = sizeof(char*);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = CHARP;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXGetClientString
char* *glxgetclientstring_lh(args_glXGetClientString *argp)
{
    // Get function specific args
     Display *dpy = argp->dpy;;
	 int name  = argp->name;;

    // Call actual function
    char* result = glXGetClientString(dpy, name);

    // Memcopy in Buffer
    int ret_size = sizeof(char*);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = CHARP;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXGetCurrentDisplay
Display* *glxgetcurrentdisplay_lh()
{
    // No function specific args

    // Call actual function
    Display* result = glXGetCurrentDisplay();

    // Memcopy in Buffer
    int ret_size = sizeof(Display*);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = DISPLAYP;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXDestroyWindow
void *glxdestroywindow_lh(args_glXDestroyWindow *argp)
{
    // Get function specific args
     Display *dpy = argp->dpy;;
	 GLXWindow window  = argp->window;;

    // Call actual function
    glXDestroyWindow(dpy, window);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXDestroyPixmap
void *glxdestroypixmap_lh(args_glXDestroyPixmap *argp)
{
    // Get function specific args
     Display *dpy = argp->dpy;;
	 GLXPixmap pixmap  = argp->pixmap;;

    // Call actual function
    glXDestroyPixmap(dpy, pixmap);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXDestroyPbuffer
void *glxdestroypbuffer_lh(args_glXDestroyPbuffer *argp)
{
    // Get function specific args
     Display *dpy = argp->dpy;;
	 GLXPbuffer pbuf  = argp->pbuf;;

    // Call actual function
    glXDestroyPbuffer(dpy, pbuf);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXGetCurrentReadDrawable
GLXDrawable *glxgetcurrentreaddrawable_lh()
{
    // No function specific args

    // Call actual function
    GLXDrawable result = glXGetCurrentReadDrawable();

    // Memcopy in Buffer
    int ret_size = sizeof(GLXDrawable);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = GLXDRAWABLE;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXGetProcAddressARB
__GLXextFuncPtr *glxgetprocaddressarb_lh(args_glXGetProcAddressARB *argp)
{
    // Get function specific args
    const GLubyte *procname = argp->procname;;

    // Call actual function
    __GLXextFuncPtr result = glXGetProcAddressARB(procname);

    // Memcopy in Buffer
    int ret_size = sizeof(__GLXextFuncPtr);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = __GLXEXTFUNCPTR;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXGetProcAddress
void* *glxgetprocaddress_lh(args_glXGetProcAddress *argp)
{
    // Get function specific args
    const GLubyte *procname = argp->procname;;

    // Call actual function
    void* result = glXGetProcAddress(procname);

    // Memcopy in Buffer
    int ret_size = sizeof(void*);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOIDP;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXAllocateMemoryNV
void* *glxallocatememorynv_lh(args_glXAllocateMemoryNV *argp)
{
    // Get function specific args
    GLsizei size = argp->size;;
	 GLfloat readfreq = argp->readfreq;;
	 GLfloat writefreq = argp->writefreq;;
	 GLfloat priority = argp->priority;;

    // Call actual function
    void* result = glXAllocateMemoryNV(size, readfreq, writefreq, priority);

    // Memcopy in Buffer
    int ret_size = sizeof(void*);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOIDP;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXFreeMemoryNV
void *glxfreememorynv_lh(args_glXFreeMemoryNV *argp)
{
    // Get function specific args
    GLvoid *pointer = argp->pointer;;

    // Call actual function
    glXFreeMemoryNV(pointer);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXBindTexImageARB
Bool *glxbindteximagearb_lh(args_glXBindTexImageARB *argp)
{
    // Get function specific args
    Display *dpy = argp->dpy;;
	 GLXPbuffer pbuffer = argp->pbuffer;;
	 int buffer = argp->buffer;;

    // Call actual function
    Bool result = glXBindTexImageARB(dpy, pbuffer, buffer);

    // Memcopy in Buffer
    int ret_size = sizeof(Bool);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = BOOL;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXReleaseTexImageARB
Bool *glxreleaseteximagearb_lh(args_glXReleaseTexImageARB *argp)
{
    // Get function specific args
    Display *dpy = argp->dpy;;
	 GLXPbuffer pbuffer = argp->pbuffer;;
	 int buffer = argp->buffer;;

    // Call actual function
    Bool result = glXReleaseTexImageARB(dpy, pbuffer, buffer);

    // Memcopy in Buffer
    int ret_size = sizeof(Bool);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = BOOL;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXDrawableAttribARB
Bool *glxdrawableattribarb_lh(args_glXDrawableAttribARB *argp)
{
    // Get function specific args
    Display *dpy = argp->dpy;;
	 GLXDrawable draw = argp->draw;;
	 const int *attribList = argp->attribList;;

    // Call actual function
    Bool result = glXDrawableAttribARB(dpy, draw, attribList);

    // Memcopy in Buffer
    int ret_size = sizeof(Bool);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = BOOL;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXGetFrameUsageMESA
int *glxgetframeusagemesa_lh(args_glXGetFrameUsageMESA *argp)
{
    // Get function specific args
    Display *dpy = argp->dpy;;
	 GLXDrawable drawable = argp->drawable;;
	 float *usage = argp->usage;;

    // Call actual function
    int result = glXGetFrameUsageMESA(dpy, drawable, usage);

    // Memcopy in Buffer
    int ret_size = sizeof(int);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = INT;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXBeginFrameTrackingMESA
int *glxbeginframetrackingmesa_lh(args_glXBeginFrameTrackingMESA *argp)
{
    // Get function specific args
    Display *dpy = argp->dpy;;
	 GLXDrawable drawable = argp->drawable;;

    // Call actual function
    int result = glXBeginFrameTrackingMESA(dpy, drawable);

    // Memcopy in Buffer
    int ret_size = sizeof(int);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = INT;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXEndFrameTrackingMESA
int *glxendframetrackingmesa_lh(args_glXEndFrameTrackingMESA *argp)
{
    // Get function specific args
    Display *dpy = argp->dpy;;
	 GLXDrawable drawable = argp->drawable;;

    // Call actual function
    int result = glXEndFrameTrackingMESA(dpy, drawable);

    // Memcopy in Buffer
    int ret_size = sizeof(int);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = INT;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXQueryFrameTrackingMESA
int *glxqueryframetrackingmesa_lh(args_glXQueryFrameTrackingMESA *argp)
{
    // Get function specific args
    Display *dpy = argp->dpy;;
	 GLXDrawable drawable = argp->drawable;;
	 int64_t *swapCount = argp->swapCount;;
	 int64_t *missedFrames = argp->missedFrames;;
	 float *lastMissedUsage = argp->lastMissedUsage;;

    // Call actual function
    int result = glXQueryFrameTrackingMESA(dpy, drawable, swapCount, missedFrames, lastMissedUsage);

    // Memcopy in Buffer
    int ret_size = sizeof(int);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = INT;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXSwapIntervalMESA
int *glxswapintervalmesa_lh(args_glXSwapIntervalMESA *argp)
{
    // Get function specific args
    unsigned int interval = argp->interval;;

    // Call actual function
    int result = glXSwapIntervalMESA(interval);

    // Memcopy in Buffer
    int ret_size = sizeof(int);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = INT;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXGetSwapIntervalMESA
int *glxgetswapintervalmesa_lh()
{
    // No function specific args

    // Call actual function
    int result = glXGetSwapIntervalMESA();

    // Memcopy in Buffer
    int ret_size = sizeof(int);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = INT;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


void service_listener() {
    // Server loop
    while(1){
        // Wait on request
        printf("Listening...\n");
        while (ShmPTR->status != REQUEST)
            ;

        // assert if FUNC_CALL
        if(ShmPTR->message_type != FUNC_CALL){
            printf("No function call\n");
            ShmPTR->status = LISTEN;
            continue;
        }

        // read function type header
        data_types func_type = ShmPTR->data_type;
        printf("REQUEST: Function type: %d\n", func_type);

        // Call function from desired function type
        switch (func_type)
        {
            
            case XOPENDISPLAY: ;
                args_XOpenDisplay argp_xopendisplay;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XOpenDisplay)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xopendisplay, ShmPTR->buffer, sizeof(args_XOpenDisplay));

                // Execute function call
                xopendisplay_lh(&argp_xopendisplay);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case XMAPWINDOW: ;
                args_XMapWindow argp_xmapwindow;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XMapWindow)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xmapwindow, ShmPTR->buffer, sizeof(args_XMapWindow));

                // Execute function call
                xmapwindow_lh(&argp_xmapwindow);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case XCREATECOLORMAP: ;
                args_XCreateColormap argp_xcreatecolormap;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XCreateColormap)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xcreatecolormap, ShmPTR->buffer, sizeof(args_XCreateColormap));

                // Execute function call
                xcreatecolormap_lh(&argp_xcreatecolormap);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case XCREATEWINDOW: ;
                args_XCreateWindow argp_xcreatewindow;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XCreateWindow)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xcreatewindow, ShmPTR->buffer, sizeof(args_XCreateWindow));

                // Execute function call
                xcreatewindow_lh(&argp_xcreatewindow);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case XFREE: ;
                args_XFree argp_xfree;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XFree)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xfree, ShmPTR->buffer, sizeof(args_XFree));

                // Execute function call
                xfree_lh(&argp_xfree);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case XSETNORMALHINTS: ;
                args_XSetNormalHints argp_xsetnormalhints;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XSetNormalHints)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xsetnormalhints, ShmPTR->buffer, sizeof(args_XSetNormalHints));

                // Execute function call
                xsetnormalhints_lh(&argp_xsetnormalhints);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case XSETSTANDARDPROPERTIES: ;
                args_XSetStandardProperties argp_xsetstandardproperties;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XSetStandardProperties)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xsetstandardproperties, ShmPTR->buffer, sizeof(args_XSetStandardProperties));

                // Execute function call
                xsetstandardproperties_lh(&argp_xsetstandardproperties);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCLEARINDEX: ;
                args_glClearIndex argp_glclearindex;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glClearIndex)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glclearindex, ShmPTR->buffer, sizeof(args_glClearIndex));

                // Execute function call
                glclearindex_lh(&argp_glclearindex);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCLEARCOLOR: ;
                args_glClearColor argp_glclearcolor;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glClearColor)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glclearcolor, ShmPTR->buffer, sizeof(args_glClearColor));

                // Execute function call
                glclearcolor_lh(&argp_glclearcolor);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCLEAR: ;
                args_glClear argp_glclear;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glClear)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glclear, ShmPTR->buffer, sizeof(args_glClear));

                // Execute function call
                glclear_lh(&argp_glclear);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLINDEXMASK: ;
                args_glIndexMask argp_glindexmask;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glIndexMask)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glindexmask, ShmPTR->buffer, sizeof(args_glIndexMask));

                // Execute function call
                glindexmask_lh(&argp_glindexmask);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLORMASK: ;
                args_glColorMask argp_glcolormask;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColorMask)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolormask, ShmPTR->buffer, sizeof(args_glColorMask));

                // Execute function call
                glcolormask_lh(&argp_glcolormask);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLALPHAFUNC: ;
                args_glAlphaFunc argp_glalphafunc;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glAlphaFunc)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glalphafunc, ShmPTR->buffer, sizeof(args_glAlphaFunc));

                // Execute function call
                glalphafunc_lh(&argp_glalphafunc);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLBLENDFUNC: ;
                args_glBlendFunc argp_glblendfunc;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glBlendFunc)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glblendfunc, ShmPTR->buffer, sizeof(args_glBlendFunc));

                // Execute function call
                glblendfunc_lh(&argp_glblendfunc);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLLOGICOP: ;
                args_glLogicOp argp_gllogicop;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glLogicOp)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gllogicop, ShmPTR->buffer, sizeof(args_glLogicOp));

                // Execute function call
                gllogicop_lh(&argp_gllogicop);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCULLFACE: ;
                args_glCullFace argp_glcullface;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCullFace)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcullface, ShmPTR->buffer, sizeof(args_glCullFace));

                // Execute function call
                glcullface_lh(&argp_glcullface);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLFRONTFACE: ;
                args_glFrontFace argp_glfrontface;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glFrontFace)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glfrontface, ShmPTR->buffer, sizeof(args_glFrontFace));

                // Execute function call
                glfrontface_lh(&argp_glfrontface);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPOINTSIZE: ;
                args_glPointSize argp_glpointsize;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPointSize)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glpointsize, ShmPTR->buffer, sizeof(args_glPointSize));

                // Execute function call
                glpointsize_lh(&argp_glpointsize);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLLINEWIDTH: ;
                args_glLineWidth argp_gllinewidth;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glLineWidth)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gllinewidth, ShmPTR->buffer, sizeof(args_glLineWidth));

                // Execute function call
                gllinewidth_lh(&argp_gllinewidth);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLLINESTIPPLE: ;
                args_glLineStipple argp_gllinestipple;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glLineStipple)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gllinestipple, ShmPTR->buffer, sizeof(args_glLineStipple));

                // Execute function call
                gllinestipple_lh(&argp_gllinestipple);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPOLYGONMODE: ;
                args_glPolygonMode argp_glpolygonmode;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPolygonMode)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glpolygonmode, ShmPTR->buffer, sizeof(args_glPolygonMode));

                // Execute function call
                glpolygonmode_lh(&argp_glpolygonmode);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPOLYGONOFFSET: ;
                args_glPolygonOffset argp_glpolygonoffset;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPolygonOffset)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glpolygonoffset, ShmPTR->buffer, sizeof(args_glPolygonOffset));

                // Execute function call
                glpolygonoffset_lh(&argp_glpolygonoffset);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPOLYGONSTIPPLE: ;
                args_glPolygonStipple argp_glpolygonstipple;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPolygonStipple)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glpolygonstipple, ShmPTR->buffer, sizeof(args_glPolygonStipple));

                // Execute function call
                glpolygonstipple_lh(&argp_glpolygonstipple);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETPOLYGONSTIPPLE: ;
                args_glGetPolygonStipple argp_glgetpolygonstipple;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetPolygonStipple)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetpolygonstipple, ShmPTR->buffer, sizeof(args_glGetPolygonStipple));

                // Execute function call
                glgetpolygonstipple_lh(&argp_glgetpolygonstipple);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLEDGEFLAG: ;
                args_glEdgeFlag argp_gledgeflag;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEdgeFlag)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gledgeflag, ShmPTR->buffer, sizeof(args_glEdgeFlag));

                // Execute function call
                gledgeflag_lh(&argp_gledgeflag);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLEDGEFLAGV: ;
                args_glEdgeFlagv argp_gledgeflagv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEdgeFlagv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gledgeflagv, ShmPTR->buffer, sizeof(args_glEdgeFlagv));

                // Execute function call
                gledgeflagv_lh(&argp_gledgeflagv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLSCISSOR: ;
                args_glScissor argp_glscissor;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glScissor)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glscissor, ShmPTR->buffer, sizeof(args_glScissor));

                // Execute function call
                glscissor_lh(&argp_glscissor);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCLIPPLANE: ;
                args_glClipPlane argp_glclipplane;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glClipPlane)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glclipplane, ShmPTR->buffer, sizeof(args_glClipPlane));

                // Execute function call
                glclipplane_lh(&argp_glclipplane);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETCLIPPLANE: ;
                args_glGetClipPlane argp_glgetclipplane;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetClipPlane)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetclipplane, ShmPTR->buffer, sizeof(args_glGetClipPlane));

                // Execute function call
                glgetclipplane_lh(&argp_glgetclipplane);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLDRAWBUFFER: ;
                args_glDrawBuffer argp_gldrawbuffer;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glDrawBuffer)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gldrawbuffer, ShmPTR->buffer, sizeof(args_glDrawBuffer));

                // Execute function call
                gldrawbuffer_lh(&argp_gldrawbuffer);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLREADBUFFER: ;
                args_glReadBuffer argp_glreadbuffer;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glReadBuffer)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glreadbuffer, ShmPTR->buffer, sizeof(args_glReadBuffer));

                // Execute function call
                glreadbuffer_lh(&argp_glreadbuffer);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLENABLE: ;
                args_glEnable argp_glenable;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEnable)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glenable, ShmPTR->buffer, sizeof(args_glEnable));

                // Execute function call
                glenable_lh(&argp_glenable);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLDISABLE: ;
                args_glDisable argp_gldisable;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glDisable)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gldisable, ShmPTR->buffer, sizeof(args_glDisable));

                // Execute function call
                gldisable_lh(&argp_gldisable);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLISENABLED: ;
                args_glIsEnabled argp_glisenabled;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glIsEnabled)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glisenabled, ShmPTR->buffer, sizeof(args_glIsEnabled));

                // Execute function call
                glisenabled_lh(&argp_glisenabled);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLENABLECLIENTSTATE: ;
                args_glEnableClientState argp_glenableclientstate;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEnableClientState)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glenableclientstate, ShmPTR->buffer, sizeof(args_glEnableClientState));

                // Execute function call
                glenableclientstate_lh(&argp_glenableclientstate);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLDISABLECLIENTSTATE: ;
                args_glDisableClientState argp_gldisableclientstate;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glDisableClientState)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gldisableclientstate, ShmPTR->buffer, sizeof(args_glDisableClientState));

                // Execute function call
                gldisableclientstate_lh(&argp_gldisableclientstate);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETBOOLEANV: ;
                args_glGetBooleanv argp_glgetbooleanv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetBooleanv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetbooleanv, ShmPTR->buffer, sizeof(args_glGetBooleanv));

                // Execute function call
                glgetbooleanv_lh(&argp_glgetbooleanv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETDOUBLEV: ;
                args_glGetDoublev argp_glgetdoublev;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetDoublev)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetdoublev, ShmPTR->buffer, sizeof(args_glGetDoublev));

                // Execute function call
                glgetdoublev_lh(&argp_glgetdoublev);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETFLOATV: ;
                args_glGetFloatv argp_glgetfloatv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetFloatv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetfloatv, ShmPTR->buffer, sizeof(args_glGetFloatv));

                // Execute function call
                glgetfloatv_lh(&argp_glgetfloatv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETINTEGERV: ;
                args_glGetIntegerv argp_glgetintegerv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetIntegerv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetintegerv, ShmPTR->buffer, sizeof(args_glGetIntegerv));

                // Execute function call
                glgetintegerv_lh(&argp_glgetintegerv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPUSHATTRIB: ;
                args_glPushAttrib argp_glpushattrib;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPushAttrib)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glpushattrib, ShmPTR->buffer, sizeof(args_glPushAttrib));

                // Execute function call
                glpushattrib_lh(&argp_glpushattrib);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPOPATTRIB: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glpopattrib_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPUSHCLIENTATTRIB: ;
                args_glPushClientAttrib argp_glpushclientattrib;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPushClientAttrib)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glpushclientattrib, ShmPTR->buffer, sizeof(args_glPushClientAttrib));

                // Execute function call
                glpushclientattrib_lh(&argp_glpushclientattrib);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPOPCLIENTATTRIB: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glpopclientattrib_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRENDERMODE: ;
                args_glRenderMode argp_glrendermode;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRenderMode)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrendermode, ShmPTR->buffer, sizeof(args_glRenderMode));

                // Execute function call
                glrendermode_lh(&argp_glrendermode);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLFINISH: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glfinish_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLFLUSH: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glflush_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLHINT: ;
                args_glHint argp_glhint;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glHint)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glhint, ShmPTR->buffer, sizeof(args_glHint));

                // Execute function call
                glhint_lh(&argp_glhint);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCLEARDEPTH: ;
                args_glClearDepth argp_glcleardepth;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glClearDepth)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcleardepth, ShmPTR->buffer, sizeof(args_glClearDepth));

                // Execute function call
                glcleardepth_lh(&argp_glcleardepth);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLDEPTHFUNC: ;
                args_glDepthFunc argp_gldepthfunc;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glDepthFunc)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gldepthfunc, ShmPTR->buffer, sizeof(args_glDepthFunc));

                // Execute function call
                gldepthfunc_lh(&argp_gldepthfunc);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLDEPTHMASK: ;
                args_glDepthMask argp_gldepthmask;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glDepthMask)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gldepthmask, ShmPTR->buffer, sizeof(args_glDepthMask));

                // Execute function call
                gldepthmask_lh(&argp_gldepthmask);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLDEPTHRANGE: ;
                args_glDepthRange argp_gldepthrange;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glDepthRange)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gldepthrange, ShmPTR->buffer, sizeof(args_glDepthRange));

                // Execute function call
                gldepthrange_lh(&argp_gldepthrange);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCLEARACCUM: ;
                args_glClearAccum argp_glclearaccum;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glClearAccum)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glclearaccum, ShmPTR->buffer, sizeof(args_glClearAccum));

                // Execute function call
                glclearaccum_lh(&argp_glclearaccum);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLACCUM: ;
                args_glAccum argp_glaccum;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glAccum)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glaccum, ShmPTR->buffer, sizeof(args_glAccum));

                // Execute function call
                glaccum_lh(&argp_glaccum);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMATRIXMODE: ;
                args_glMatrixMode argp_glmatrixmode;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMatrixMode)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmatrixmode, ShmPTR->buffer, sizeof(args_glMatrixMode));

                // Execute function call
                glmatrixmode_lh(&argp_glmatrixmode);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLORTHO: ;
                args_glOrtho argp_glortho;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glOrtho)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glortho, ShmPTR->buffer, sizeof(args_glOrtho));

                // Execute function call
                glortho_lh(&argp_glortho);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLFRUSTUM: ;
                args_glFrustum argp_glfrustum;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glFrustum)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glfrustum, ShmPTR->buffer, sizeof(args_glFrustum));

                // Execute function call
                glfrustum_lh(&argp_glfrustum);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVIEWPORT: ;
                args_glViewport argp_glviewport;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glViewport)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glviewport, ShmPTR->buffer, sizeof(args_glViewport));

                // Execute function call
                glviewport_lh(&argp_glviewport);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPUSHMATRIX: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glpushmatrix_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPOPMATRIX: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glpopmatrix_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLLOADIDENTITY: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glloadidentity_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLLOADMATRIXD: ;
                args_glLoadMatrixd argp_glloadmatrixd;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glLoadMatrixd)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glloadmatrixd, ShmPTR->buffer, sizeof(args_glLoadMatrixd));

                // Execute function call
                glloadmatrixd_lh(&argp_glloadmatrixd);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLLOADMATRIXF: ;
                args_glLoadMatrixf argp_glloadmatrixf;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glLoadMatrixf)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glloadmatrixf, ShmPTR->buffer, sizeof(args_glLoadMatrixf));

                // Execute function call
                glloadmatrixf_lh(&argp_glloadmatrixf);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTMATRIXD: ;
                args_glMultMatrixd argp_glmultmatrixd;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultMatrixd)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultmatrixd, ShmPTR->buffer, sizeof(args_glMultMatrixd));

                // Execute function call
                glmultmatrixd_lh(&argp_glmultmatrixd);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTMATRIXF: ;
                args_glMultMatrixf argp_glmultmatrixf;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultMatrixf)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultmatrixf, ShmPTR->buffer, sizeof(args_glMultMatrixf));

                // Execute function call
                glmultmatrixf_lh(&argp_glmultmatrixf);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLROTATED: ;
                args_glRotated argp_glrotated;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRotated)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrotated, ShmPTR->buffer, sizeof(args_glRotated));

                // Execute function call
                glrotated_lh(&argp_glrotated);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLROTATEF: ;
                args_glRotatef argp_glrotatef;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRotatef)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrotatef, ShmPTR->buffer, sizeof(args_glRotatef));

                // Execute function call
                glrotatef_lh(&argp_glrotatef);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLSCALED: ;
                args_glScaled argp_glscaled;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glScaled)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glscaled, ShmPTR->buffer, sizeof(args_glScaled));

                // Execute function call
                glscaled_lh(&argp_glscaled);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLSCALEF: ;
                args_glScalef argp_glscalef;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glScalef)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glscalef, ShmPTR->buffer, sizeof(args_glScalef));

                // Execute function call
                glscalef_lh(&argp_glscalef);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTRANSLATED: ;
                args_glTranslated argp_gltranslated;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTranslated)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltranslated, ShmPTR->buffer, sizeof(args_glTranslated));

                // Execute function call
                gltranslated_lh(&argp_gltranslated);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTRANSLATEF: ;
                args_glTranslatef argp_gltranslatef;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTranslatef)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltranslatef, ShmPTR->buffer, sizeof(args_glTranslatef));

                // Execute function call
                gltranslatef_lh(&argp_gltranslatef);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLISLIST: ;
                args_glIsList argp_glislist;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glIsList)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glislist, ShmPTR->buffer, sizeof(args_glIsList));

                // Execute function call
                glislist_lh(&argp_glislist);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLDELETELISTS: ;
                args_glDeleteLists argp_gldeletelists;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glDeleteLists)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gldeletelists, ShmPTR->buffer, sizeof(args_glDeleteLists));

                // Execute function call
                gldeletelists_lh(&argp_gldeletelists);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGENLISTS: ;
                args_glGenLists argp_glgenlists;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGenLists)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgenlists, ShmPTR->buffer, sizeof(args_glGenLists));

                // Execute function call
                glgenlists_lh(&argp_glgenlists);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLNEWLIST: ;
                args_glNewList argp_glnewlist;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glNewList)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glnewlist, ShmPTR->buffer, sizeof(args_glNewList));

                // Execute function call
                glnewlist_lh(&argp_glnewlist);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLENDLIST: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glendlist_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCALLLIST: ;
                args_glCallList argp_glcalllist;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCallList)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcalllist, ShmPTR->buffer, sizeof(args_glCallList));

                // Execute function call
                glcalllist_lh(&argp_glcalllist);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCALLLISTS: ;
                args_glCallLists argp_glcalllists;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCallLists)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcalllists, ShmPTR->buffer, sizeof(args_glCallLists));

                // Execute function call
                glcalllists_lh(&argp_glcalllists);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLLISTBASE: ;
                args_glListBase argp_gllistbase;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glListBase)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gllistbase, ShmPTR->buffer, sizeof(args_glListBase));

                // Execute function call
                gllistbase_lh(&argp_gllistbase);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLBEGIN: ;
                args_glBegin argp_glbegin;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glBegin)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glbegin, ShmPTR->buffer, sizeof(args_glBegin));

                // Execute function call
                glbegin_lh(&argp_glbegin);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLEND: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glend_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX2D: ;
                args_glVertex2d argp_glvertex2d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex2d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex2d, ShmPTR->buffer, sizeof(args_glVertex2d));

                // Execute function call
                glvertex2d_lh(&argp_glvertex2d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX2F: ;
                args_glVertex2f argp_glvertex2f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex2f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex2f, ShmPTR->buffer, sizeof(args_glVertex2f));

                // Execute function call
                glvertex2f_lh(&argp_glvertex2f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX2I: ;
                args_glVertex2i argp_glvertex2i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex2i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex2i, ShmPTR->buffer, sizeof(args_glVertex2i));

                // Execute function call
                glvertex2i_lh(&argp_glvertex2i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX2S: ;
                args_glVertex2s argp_glvertex2s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex2s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex2s, ShmPTR->buffer, sizeof(args_glVertex2s));

                // Execute function call
                glvertex2s_lh(&argp_glvertex2s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX3D: ;
                args_glVertex3d argp_glvertex3d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex3d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex3d, ShmPTR->buffer, sizeof(args_glVertex3d));

                // Execute function call
                glvertex3d_lh(&argp_glvertex3d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX3F: ;
                args_glVertex3f argp_glvertex3f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex3f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex3f, ShmPTR->buffer, sizeof(args_glVertex3f));

                // Execute function call
                glvertex3f_lh(&argp_glvertex3f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX3I: ;
                args_glVertex3i argp_glvertex3i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex3i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex3i, ShmPTR->buffer, sizeof(args_glVertex3i));

                // Execute function call
                glvertex3i_lh(&argp_glvertex3i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX3S: ;
                args_glVertex3s argp_glvertex3s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex3s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex3s, ShmPTR->buffer, sizeof(args_glVertex3s));

                // Execute function call
                glvertex3s_lh(&argp_glvertex3s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX4D: ;
                args_glVertex4d argp_glvertex4d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex4d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex4d, ShmPTR->buffer, sizeof(args_glVertex4d));

                // Execute function call
                glvertex4d_lh(&argp_glvertex4d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX4F: ;
                args_glVertex4f argp_glvertex4f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex4f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex4f, ShmPTR->buffer, sizeof(args_glVertex4f));

                // Execute function call
                glvertex4f_lh(&argp_glvertex4f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX4I: ;
                args_glVertex4i argp_glvertex4i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex4i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex4i, ShmPTR->buffer, sizeof(args_glVertex4i));

                // Execute function call
                glvertex4i_lh(&argp_glvertex4i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX4S: ;
                args_glVertex4s argp_glvertex4s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex4s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex4s, ShmPTR->buffer, sizeof(args_glVertex4s));

                // Execute function call
                glvertex4s_lh(&argp_glvertex4s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX2DV: ;
                args_glVertex2dv argp_glvertex2dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex2dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex2dv, ShmPTR->buffer, sizeof(args_glVertex2dv));

                // Execute function call
                glvertex2dv_lh(&argp_glvertex2dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX2FV: ;
                args_glVertex2fv argp_glvertex2fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex2fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex2fv, ShmPTR->buffer, sizeof(args_glVertex2fv));

                // Execute function call
                glvertex2fv_lh(&argp_glvertex2fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX2IV: ;
                args_glVertex2iv argp_glvertex2iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex2iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex2iv, ShmPTR->buffer, sizeof(args_glVertex2iv));

                // Execute function call
                glvertex2iv_lh(&argp_glvertex2iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX2SV: ;
                args_glVertex2sv argp_glvertex2sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex2sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex2sv, ShmPTR->buffer, sizeof(args_glVertex2sv));

                // Execute function call
                glvertex2sv_lh(&argp_glvertex2sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX3DV: ;
                args_glVertex3dv argp_glvertex3dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex3dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex3dv, ShmPTR->buffer, sizeof(args_glVertex3dv));

                // Execute function call
                glvertex3dv_lh(&argp_glvertex3dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX3FV: ;
                args_glVertex3fv argp_glvertex3fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex3fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex3fv, ShmPTR->buffer, sizeof(args_glVertex3fv));

                // Execute function call
                glvertex3fv_lh(&argp_glvertex3fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX3IV: ;
                args_glVertex3iv argp_glvertex3iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex3iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex3iv, ShmPTR->buffer, sizeof(args_glVertex3iv));

                // Execute function call
                glvertex3iv_lh(&argp_glvertex3iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX3SV: ;
                args_glVertex3sv argp_glvertex3sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex3sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex3sv, ShmPTR->buffer, sizeof(args_glVertex3sv));

                // Execute function call
                glvertex3sv_lh(&argp_glvertex3sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX4DV: ;
                args_glVertex4dv argp_glvertex4dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex4dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex4dv, ShmPTR->buffer, sizeof(args_glVertex4dv));

                // Execute function call
                glvertex4dv_lh(&argp_glvertex4dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX4FV: ;
                args_glVertex4fv argp_glvertex4fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex4fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex4fv, ShmPTR->buffer, sizeof(args_glVertex4fv));

                // Execute function call
                glvertex4fv_lh(&argp_glvertex4fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX4IV: ;
                args_glVertex4iv argp_glvertex4iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex4iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex4iv, ShmPTR->buffer, sizeof(args_glVertex4iv));

                // Execute function call
                glvertex4iv_lh(&argp_glvertex4iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEX4SV: ;
                args_glVertex4sv argp_glvertex4sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertex4sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex4sv, ShmPTR->buffer, sizeof(args_glVertex4sv));

                // Execute function call
                glvertex4sv_lh(&argp_glvertex4sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLNORMAL3B: ;
                args_glNormal3b argp_glnormal3b;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glNormal3b)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glnormal3b, ShmPTR->buffer, sizeof(args_glNormal3b));

                // Execute function call
                glnormal3b_lh(&argp_glnormal3b);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLNORMAL3D: ;
                args_glNormal3d argp_glnormal3d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glNormal3d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glnormal3d, ShmPTR->buffer, sizeof(args_glNormal3d));

                // Execute function call
                glnormal3d_lh(&argp_glnormal3d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLNORMAL3F: ;
                args_glNormal3f argp_glnormal3f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glNormal3f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glnormal3f, ShmPTR->buffer, sizeof(args_glNormal3f));

                // Execute function call
                glnormal3f_lh(&argp_glnormal3f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLNORMAL3I: ;
                args_glNormal3i argp_glnormal3i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glNormal3i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glnormal3i, ShmPTR->buffer, sizeof(args_glNormal3i));

                // Execute function call
                glnormal3i_lh(&argp_glnormal3i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLNORMAL3S: ;
                args_glNormal3s argp_glnormal3s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glNormal3s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glnormal3s, ShmPTR->buffer, sizeof(args_glNormal3s));

                // Execute function call
                glnormal3s_lh(&argp_glnormal3s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLNORMAL3BV: ;
                args_glNormal3bv argp_glnormal3bv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glNormal3bv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glnormal3bv, ShmPTR->buffer, sizeof(args_glNormal3bv));

                // Execute function call
                glnormal3bv_lh(&argp_glnormal3bv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLNORMAL3DV: ;
                args_glNormal3dv argp_glnormal3dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glNormal3dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glnormal3dv, ShmPTR->buffer, sizeof(args_glNormal3dv));

                // Execute function call
                glnormal3dv_lh(&argp_glnormal3dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLNORMAL3FV: ;
                args_glNormal3fv argp_glnormal3fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glNormal3fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glnormal3fv, ShmPTR->buffer, sizeof(args_glNormal3fv));

                // Execute function call
                glnormal3fv_lh(&argp_glnormal3fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLNORMAL3IV: ;
                args_glNormal3iv argp_glnormal3iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glNormal3iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glnormal3iv, ShmPTR->buffer, sizeof(args_glNormal3iv));

                // Execute function call
                glnormal3iv_lh(&argp_glnormal3iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLNORMAL3SV: ;
                args_glNormal3sv argp_glnormal3sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glNormal3sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glnormal3sv, ShmPTR->buffer, sizeof(args_glNormal3sv));

                // Execute function call
                glnormal3sv_lh(&argp_glnormal3sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLINDEXD: ;
                args_glIndexd argp_glindexd;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glIndexd)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glindexd, ShmPTR->buffer, sizeof(args_glIndexd));

                // Execute function call
                glindexd_lh(&argp_glindexd);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLINDEXF: ;
                args_glIndexf argp_glindexf;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glIndexf)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glindexf, ShmPTR->buffer, sizeof(args_glIndexf));

                // Execute function call
                glindexf_lh(&argp_glindexf);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLINDEXI: ;
                args_glIndexi argp_glindexi;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glIndexi)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glindexi, ShmPTR->buffer, sizeof(args_glIndexi));

                // Execute function call
                glindexi_lh(&argp_glindexi);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLINDEXS: ;
                args_glIndexs argp_glindexs;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glIndexs)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glindexs, ShmPTR->buffer, sizeof(args_glIndexs));

                // Execute function call
                glindexs_lh(&argp_glindexs);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLINDEXUB: ;
                args_glIndexub argp_glindexub;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glIndexub)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glindexub, ShmPTR->buffer, sizeof(args_glIndexub));

                // Execute function call
                glindexub_lh(&argp_glindexub);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLINDEXDV: ;
                args_glIndexdv argp_glindexdv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glIndexdv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glindexdv, ShmPTR->buffer, sizeof(args_glIndexdv));

                // Execute function call
                glindexdv_lh(&argp_glindexdv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLINDEXFV: ;
                args_glIndexfv argp_glindexfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glIndexfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glindexfv, ShmPTR->buffer, sizeof(args_glIndexfv));

                // Execute function call
                glindexfv_lh(&argp_glindexfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLINDEXIV: ;
                args_glIndexiv argp_glindexiv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glIndexiv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glindexiv, ShmPTR->buffer, sizeof(args_glIndexiv));

                // Execute function call
                glindexiv_lh(&argp_glindexiv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLINDEXSV: ;
                args_glIndexsv argp_glindexsv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glIndexsv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glindexsv, ShmPTR->buffer, sizeof(args_glIndexsv));

                // Execute function call
                glindexsv_lh(&argp_glindexsv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLINDEXUBV: ;
                args_glIndexubv argp_glindexubv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glIndexubv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glindexubv, ShmPTR->buffer, sizeof(args_glIndexubv));

                // Execute function call
                glindexubv_lh(&argp_glindexubv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR3B: ;
                args_glColor3b argp_glcolor3b;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor3b)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor3b, ShmPTR->buffer, sizeof(args_glColor3b));

                // Execute function call
                glcolor3b_lh(&argp_glcolor3b);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR3D: ;
                args_glColor3d argp_glcolor3d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor3d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor3d, ShmPTR->buffer, sizeof(args_glColor3d));

                // Execute function call
                glcolor3d_lh(&argp_glcolor3d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR3F: ;
                args_glColor3f argp_glcolor3f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor3f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor3f, ShmPTR->buffer, sizeof(args_glColor3f));

                // Execute function call
                glcolor3f_lh(&argp_glcolor3f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR3I: ;
                args_glColor3i argp_glcolor3i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor3i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor3i, ShmPTR->buffer, sizeof(args_glColor3i));

                // Execute function call
                glcolor3i_lh(&argp_glcolor3i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR3S: ;
                args_glColor3s argp_glcolor3s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor3s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor3s, ShmPTR->buffer, sizeof(args_glColor3s));

                // Execute function call
                glcolor3s_lh(&argp_glcolor3s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR3UB: ;
                args_glColor3ub argp_glcolor3ub;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor3ub)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor3ub, ShmPTR->buffer, sizeof(args_glColor3ub));

                // Execute function call
                glcolor3ub_lh(&argp_glcolor3ub);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR3UI: ;
                args_glColor3ui argp_glcolor3ui;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor3ui)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor3ui, ShmPTR->buffer, sizeof(args_glColor3ui));

                // Execute function call
                glcolor3ui_lh(&argp_glcolor3ui);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR3US: ;
                args_glColor3us argp_glcolor3us;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor3us)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor3us, ShmPTR->buffer, sizeof(args_glColor3us));

                // Execute function call
                glcolor3us_lh(&argp_glcolor3us);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR4B: ;
                args_glColor4b argp_glcolor4b;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor4b)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor4b, ShmPTR->buffer, sizeof(args_glColor4b));

                // Execute function call
                glcolor4b_lh(&argp_glcolor4b);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR4D: ;
                args_glColor4d argp_glcolor4d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor4d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor4d, ShmPTR->buffer, sizeof(args_glColor4d));

                // Execute function call
                glcolor4d_lh(&argp_glcolor4d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR4F: ;
                args_glColor4f argp_glcolor4f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor4f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor4f, ShmPTR->buffer, sizeof(args_glColor4f));

                // Execute function call
                glcolor4f_lh(&argp_glcolor4f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR4I: ;
                args_glColor4i argp_glcolor4i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor4i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor4i, ShmPTR->buffer, sizeof(args_glColor4i));

                // Execute function call
                glcolor4i_lh(&argp_glcolor4i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR4S: ;
                args_glColor4s argp_glcolor4s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor4s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor4s, ShmPTR->buffer, sizeof(args_glColor4s));

                // Execute function call
                glcolor4s_lh(&argp_glcolor4s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR4UB: ;
                args_glColor4ub argp_glcolor4ub;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor4ub)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor4ub, ShmPTR->buffer, sizeof(args_glColor4ub));

                // Execute function call
                glcolor4ub_lh(&argp_glcolor4ub);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR4UI: ;
                args_glColor4ui argp_glcolor4ui;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor4ui)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor4ui, ShmPTR->buffer, sizeof(args_glColor4ui));

                // Execute function call
                glcolor4ui_lh(&argp_glcolor4ui);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR4US: ;
                args_glColor4us argp_glcolor4us;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor4us)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor4us, ShmPTR->buffer, sizeof(args_glColor4us));

                // Execute function call
                glcolor4us_lh(&argp_glcolor4us);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR3BV: ;
                args_glColor3bv argp_glcolor3bv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor3bv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor3bv, ShmPTR->buffer, sizeof(args_glColor3bv));

                // Execute function call
                glcolor3bv_lh(&argp_glcolor3bv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR3DV: ;
                args_glColor3dv argp_glcolor3dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor3dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor3dv, ShmPTR->buffer, sizeof(args_glColor3dv));

                // Execute function call
                glcolor3dv_lh(&argp_glcolor3dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR3FV: ;
                args_glColor3fv argp_glcolor3fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor3fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor3fv, ShmPTR->buffer, sizeof(args_glColor3fv));

                // Execute function call
                glcolor3fv_lh(&argp_glcolor3fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR3IV: ;
                args_glColor3iv argp_glcolor3iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor3iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor3iv, ShmPTR->buffer, sizeof(args_glColor3iv));

                // Execute function call
                glcolor3iv_lh(&argp_glcolor3iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR3SV: ;
                args_glColor3sv argp_glcolor3sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor3sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor3sv, ShmPTR->buffer, sizeof(args_glColor3sv));

                // Execute function call
                glcolor3sv_lh(&argp_glcolor3sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR3UBV: ;
                args_glColor3ubv argp_glcolor3ubv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor3ubv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor3ubv, ShmPTR->buffer, sizeof(args_glColor3ubv));

                // Execute function call
                glcolor3ubv_lh(&argp_glcolor3ubv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR3UIV: ;
                args_glColor3uiv argp_glcolor3uiv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor3uiv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor3uiv, ShmPTR->buffer, sizeof(args_glColor3uiv));

                // Execute function call
                glcolor3uiv_lh(&argp_glcolor3uiv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR3USV: ;
                args_glColor3usv argp_glcolor3usv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor3usv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor3usv, ShmPTR->buffer, sizeof(args_glColor3usv));

                // Execute function call
                glcolor3usv_lh(&argp_glcolor3usv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR4BV: ;
                args_glColor4bv argp_glcolor4bv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor4bv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor4bv, ShmPTR->buffer, sizeof(args_glColor4bv));

                // Execute function call
                glcolor4bv_lh(&argp_glcolor4bv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR4DV: ;
                args_glColor4dv argp_glcolor4dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor4dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor4dv, ShmPTR->buffer, sizeof(args_glColor4dv));

                // Execute function call
                glcolor4dv_lh(&argp_glcolor4dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR4FV: ;
                args_glColor4fv argp_glcolor4fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor4fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor4fv, ShmPTR->buffer, sizeof(args_glColor4fv));

                // Execute function call
                glcolor4fv_lh(&argp_glcolor4fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR4IV: ;
                args_glColor4iv argp_glcolor4iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor4iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor4iv, ShmPTR->buffer, sizeof(args_glColor4iv));

                // Execute function call
                glcolor4iv_lh(&argp_glcolor4iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR4SV: ;
                args_glColor4sv argp_glcolor4sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor4sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor4sv, ShmPTR->buffer, sizeof(args_glColor4sv));

                // Execute function call
                glcolor4sv_lh(&argp_glcolor4sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR4UBV: ;
                args_glColor4ubv argp_glcolor4ubv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor4ubv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor4ubv, ShmPTR->buffer, sizeof(args_glColor4ubv));

                // Execute function call
                glcolor4ubv_lh(&argp_glcolor4ubv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR4UIV: ;
                args_glColor4uiv argp_glcolor4uiv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor4uiv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor4uiv, ShmPTR->buffer, sizeof(args_glColor4uiv));

                // Execute function call
                glcolor4uiv_lh(&argp_glcolor4uiv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLOR4USV: ;
                args_glColor4usv argp_glcolor4usv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColor4usv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolor4usv, ShmPTR->buffer, sizeof(args_glColor4usv));

                // Execute function call
                glcolor4usv_lh(&argp_glcolor4usv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD1D: ;
                args_glTexCoord1d argp_gltexcoord1d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord1d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord1d, ShmPTR->buffer, sizeof(args_glTexCoord1d));

                // Execute function call
                gltexcoord1d_lh(&argp_gltexcoord1d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD1F: ;
                args_glTexCoord1f argp_gltexcoord1f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord1f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord1f, ShmPTR->buffer, sizeof(args_glTexCoord1f));

                // Execute function call
                gltexcoord1f_lh(&argp_gltexcoord1f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD1I: ;
                args_glTexCoord1i argp_gltexcoord1i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord1i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord1i, ShmPTR->buffer, sizeof(args_glTexCoord1i));

                // Execute function call
                gltexcoord1i_lh(&argp_gltexcoord1i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD1S: ;
                args_glTexCoord1s argp_gltexcoord1s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord1s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord1s, ShmPTR->buffer, sizeof(args_glTexCoord1s));

                // Execute function call
                gltexcoord1s_lh(&argp_gltexcoord1s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD2D: ;
                args_glTexCoord2d argp_gltexcoord2d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord2d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord2d, ShmPTR->buffer, sizeof(args_glTexCoord2d));

                // Execute function call
                gltexcoord2d_lh(&argp_gltexcoord2d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD2F: ;
                args_glTexCoord2f argp_gltexcoord2f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord2f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord2f, ShmPTR->buffer, sizeof(args_glTexCoord2f));

                // Execute function call
                gltexcoord2f_lh(&argp_gltexcoord2f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD2I: ;
                args_glTexCoord2i argp_gltexcoord2i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord2i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord2i, ShmPTR->buffer, sizeof(args_glTexCoord2i));

                // Execute function call
                gltexcoord2i_lh(&argp_gltexcoord2i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD2S: ;
                args_glTexCoord2s argp_gltexcoord2s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord2s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord2s, ShmPTR->buffer, sizeof(args_glTexCoord2s));

                // Execute function call
                gltexcoord2s_lh(&argp_gltexcoord2s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD3D: ;
                args_glTexCoord3d argp_gltexcoord3d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord3d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord3d, ShmPTR->buffer, sizeof(args_glTexCoord3d));

                // Execute function call
                gltexcoord3d_lh(&argp_gltexcoord3d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD3F: ;
                args_glTexCoord3f argp_gltexcoord3f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord3f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord3f, ShmPTR->buffer, sizeof(args_glTexCoord3f));

                // Execute function call
                gltexcoord3f_lh(&argp_gltexcoord3f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD3I: ;
                args_glTexCoord3i argp_gltexcoord3i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord3i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord3i, ShmPTR->buffer, sizeof(args_glTexCoord3i));

                // Execute function call
                gltexcoord3i_lh(&argp_gltexcoord3i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD3S: ;
                args_glTexCoord3s argp_gltexcoord3s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord3s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord3s, ShmPTR->buffer, sizeof(args_glTexCoord3s));

                // Execute function call
                gltexcoord3s_lh(&argp_gltexcoord3s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD4D: ;
                args_glTexCoord4d argp_gltexcoord4d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord4d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord4d, ShmPTR->buffer, sizeof(args_glTexCoord4d));

                // Execute function call
                gltexcoord4d_lh(&argp_gltexcoord4d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD4F: ;
                args_glTexCoord4f argp_gltexcoord4f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord4f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord4f, ShmPTR->buffer, sizeof(args_glTexCoord4f));

                // Execute function call
                gltexcoord4f_lh(&argp_gltexcoord4f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD4I: ;
                args_glTexCoord4i argp_gltexcoord4i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord4i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord4i, ShmPTR->buffer, sizeof(args_glTexCoord4i));

                // Execute function call
                gltexcoord4i_lh(&argp_gltexcoord4i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD4S: ;
                args_glTexCoord4s argp_gltexcoord4s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord4s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord4s, ShmPTR->buffer, sizeof(args_glTexCoord4s));

                // Execute function call
                gltexcoord4s_lh(&argp_gltexcoord4s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD1DV: ;
                args_glTexCoord1dv argp_gltexcoord1dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord1dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord1dv, ShmPTR->buffer, sizeof(args_glTexCoord1dv));

                // Execute function call
                gltexcoord1dv_lh(&argp_gltexcoord1dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD1FV: ;
                args_glTexCoord1fv argp_gltexcoord1fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord1fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord1fv, ShmPTR->buffer, sizeof(args_glTexCoord1fv));

                // Execute function call
                gltexcoord1fv_lh(&argp_gltexcoord1fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD1IV: ;
                args_glTexCoord1iv argp_gltexcoord1iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord1iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord1iv, ShmPTR->buffer, sizeof(args_glTexCoord1iv));

                // Execute function call
                gltexcoord1iv_lh(&argp_gltexcoord1iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD1SV: ;
                args_glTexCoord1sv argp_gltexcoord1sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord1sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord1sv, ShmPTR->buffer, sizeof(args_glTexCoord1sv));

                // Execute function call
                gltexcoord1sv_lh(&argp_gltexcoord1sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD2DV: ;
                args_glTexCoord2dv argp_gltexcoord2dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord2dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord2dv, ShmPTR->buffer, sizeof(args_glTexCoord2dv));

                // Execute function call
                gltexcoord2dv_lh(&argp_gltexcoord2dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD2FV: ;
                args_glTexCoord2fv argp_gltexcoord2fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord2fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord2fv, ShmPTR->buffer, sizeof(args_glTexCoord2fv));

                // Execute function call
                gltexcoord2fv_lh(&argp_gltexcoord2fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD2IV: ;
                args_glTexCoord2iv argp_gltexcoord2iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord2iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord2iv, ShmPTR->buffer, sizeof(args_glTexCoord2iv));

                // Execute function call
                gltexcoord2iv_lh(&argp_gltexcoord2iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD2SV: ;
                args_glTexCoord2sv argp_gltexcoord2sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord2sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord2sv, ShmPTR->buffer, sizeof(args_glTexCoord2sv));

                // Execute function call
                gltexcoord2sv_lh(&argp_gltexcoord2sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD3DV: ;
                args_glTexCoord3dv argp_gltexcoord3dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord3dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord3dv, ShmPTR->buffer, sizeof(args_glTexCoord3dv));

                // Execute function call
                gltexcoord3dv_lh(&argp_gltexcoord3dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD3FV: ;
                args_glTexCoord3fv argp_gltexcoord3fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord3fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord3fv, ShmPTR->buffer, sizeof(args_glTexCoord3fv));

                // Execute function call
                gltexcoord3fv_lh(&argp_gltexcoord3fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD3IV: ;
                args_glTexCoord3iv argp_gltexcoord3iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord3iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord3iv, ShmPTR->buffer, sizeof(args_glTexCoord3iv));

                // Execute function call
                gltexcoord3iv_lh(&argp_gltexcoord3iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD3SV: ;
                args_glTexCoord3sv argp_gltexcoord3sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord3sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord3sv, ShmPTR->buffer, sizeof(args_glTexCoord3sv));

                // Execute function call
                gltexcoord3sv_lh(&argp_gltexcoord3sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD4DV: ;
                args_glTexCoord4dv argp_gltexcoord4dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord4dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord4dv, ShmPTR->buffer, sizeof(args_glTexCoord4dv));

                // Execute function call
                gltexcoord4dv_lh(&argp_gltexcoord4dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD4FV: ;
                args_glTexCoord4fv argp_gltexcoord4fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord4fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord4fv, ShmPTR->buffer, sizeof(args_glTexCoord4fv));

                // Execute function call
                gltexcoord4fv_lh(&argp_gltexcoord4fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD4IV: ;
                args_glTexCoord4iv argp_gltexcoord4iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord4iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord4iv, ShmPTR->buffer, sizeof(args_glTexCoord4iv));

                // Execute function call
                gltexcoord4iv_lh(&argp_gltexcoord4iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORD4SV: ;
                args_glTexCoord4sv argp_gltexcoord4sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoord4sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoord4sv, ShmPTR->buffer, sizeof(args_glTexCoord4sv));

                // Execute function call
                gltexcoord4sv_lh(&argp_gltexcoord4sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS2D: ;
                args_glRasterPos2d argp_glrasterpos2d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos2d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos2d, ShmPTR->buffer, sizeof(args_glRasterPos2d));

                // Execute function call
                glrasterpos2d_lh(&argp_glrasterpos2d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS2F: ;
                args_glRasterPos2f argp_glrasterpos2f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos2f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos2f, ShmPTR->buffer, sizeof(args_glRasterPos2f));

                // Execute function call
                glrasterpos2f_lh(&argp_glrasterpos2f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS2I: ;
                args_glRasterPos2i argp_glrasterpos2i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos2i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos2i, ShmPTR->buffer, sizeof(args_glRasterPos2i));

                // Execute function call
                glrasterpos2i_lh(&argp_glrasterpos2i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS2S: ;
                args_glRasterPos2s argp_glrasterpos2s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos2s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos2s, ShmPTR->buffer, sizeof(args_glRasterPos2s));

                // Execute function call
                glrasterpos2s_lh(&argp_glrasterpos2s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS3D: ;
                args_glRasterPos3d argp_glrasterpos3d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos3d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos3d, ShmPTR->buffer, sizeof(args_glRasterPos3d));

                // Execute function call
                glrasterpos3d_lh(&argp_glrasterpos3d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS3F: ;
                args_glRasterPos3f argp_glrasterpos3f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos3f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos3f, ShmPTR->buffer, sizeof(args_glRasterPos3f));

                // Execute function call
                glrasterpos3f_lh(&argp_glrasterpos3f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS3I: ;
                args_glRasterPos3i argp_glrasterpos3i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos3i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos3i, ShmPTR->buffer, sizeof(args_glRasterPos3i));

                // Execute function call
                glrasterpos3i_lh(&argp_glrasterpos3i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS3S: ;
                args_glRasterPos3s argp_glrasterpos3s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos3s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos3s, ShmPTR->buffer, sizeof(args_glRasterPos3s));

                // Execute function call
                glrasterpos3s_lh(&argp_glrasterpos3s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS4D: ;
                args_glRasterPos4d argp_glrasterpos4d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos4d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos4d, ShmPTR->buffer, sizeof(args_glRasterPos4d));

                // Execute function call
                glrasterpos4d_lh(&argp_glrasterpos4d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS4F: ;
                args_glRasterPos4f argp_glrasterpos4f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos4f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos4f, ShmPTR->buffer, sizeof(args_glRasterPos4f));

                // Execute function call
                glrasterpos4f_lh(&argp_glrasterpos4f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS4I: ;
                args_glRasterPos4i argp_glrasterpos4i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos4i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos4i, ShmPTR->buffer, sizeof(args_glRasterPos4i));

                // Execute function call
                glrasterpos4i_lh(&argp_glrasterpos4i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS4S: ;
                args_glRasterPos4s argp_glrasterpos4s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos4s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos4s, ShmPTR->buffer, sizeof(args_glRasterPos4s));

                // Execute function call
                glrasterpos4s_lh(&argp_glrasterpos4s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS2DV: ;
                args_glRasterPos2dv argp_glrasterpos2dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos2dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos2dv, ShmPTR->buffer, sizeof(args_glRasterPos2dv));

                // Execute function call
                glrasterpos2dv_lh(&argp_glrasterpos2dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS2FV: ;
                args_glRasterPos2fv argp_glrasterpos2fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos2fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos2fv, ShmPTR->buffer, sizeof(args_glRasterPos2fv));

                // Execute function call
                glrasterpos2fv_lh(&argp_glrasterpos2fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS2IV: ;
                args_glRasterPos2iv argp_glrasterpos2iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos2iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos2iv, ShmPTR->buffer, sizeof(args_glRasterPos2iv));

                // Execute function call
                glrasterpos2iv_lh(&argp_glrasterpos2iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS2SV: ;
                args_glRasterPos2sv argp_glrasterpos2sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos2sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos2sv, ShmPTR->buffer, sizeof(args_glRasterPos2sv));

                // Execute function call
                glrasterpos2sv_lh(&argp_glrasterpos2sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS3DV: ;
                args_glRasterPos3dv argp_glrasterpos3dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos3dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos3dv, ShmPTR->buffer, sizeof(args_glRasterPos3dv));

                // Execute function call
                glrasterpos3dv_lh(&argp_glrasterpos3dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS3FV: ;
                args_glRasterPos3fv argp_glrasterpos3fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos3fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos3fv, ShmPTR->buffer, sizeof(args_glRasterPos3fv));

                // Execute function call
                glrasterpos3fv_lh(&argp_glrasterpos3fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS3IV: ;
                args_glRasterPos3iv argp_glrasterpos3iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos3iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos3iv, ShmPTR->buffer, sizeof(args_glRasterPos3iv));

                // Execute function call
                glrasterpos3iv_lh(&argp_glrasterpos3iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS3SV: ;
                args_glRasterPos3sv argp_glrasterpos3sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos3sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos3sv, ShmPTR->buffer, sizeof(args_glRasterPos3sv));

                // Execute function call
                glrasterpos3sv_lh(&argp_glrasterpos3sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS4DV: ;
                args_glRasterPos4dv argp_glrasterpos4dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos4dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos4dv, ShmPTR->buffer, sizeof(args_glRasterPos4dv));

                // Execute function call
                glrasterpos4dv_lh(&argp_glrasterpos4dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS4FV: ;
                args_glRasterPos4fv argp_glrasterpos4fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos4fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos4fv, ShmPTR->buffer, sizeof(args_glRasterPos4fv));

                // Execute function call
                glrasterpos4fv_lh(&argp_glrasterpos4fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS4IV: ;
                args_glRasterPos4iv argp_glrasterpos4iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos4iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos4iv, ShmPTR->buffer, sizeof(args_glRasterPos4iv));

                // Execute function call
                glrasterpos4iv_lh(&argp_glrasterpos4iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRASTERPOS4SV: ;
                args_glRasterPos4sv argp_glrasterpos4sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRasterPos4sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrasterpos4sv, ShmPTR->buffer, sizeof(args_glRasterPos4sv));

                // Execute function call
                glrasterpos4sv_lh(&argp_glrasterpos4sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRECTD: ;
                args_glRectd argp_glrectd;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRectd)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrectd, ShmPTR->buffer, sizeof(args_glRectd));

                // Execute function call
                glrectd_lh(&argp_glrectd);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRECTF: ;
                args_glRectf argp_glrectf;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRectf)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrectf, ShmPTR->buffer, sizeof(args_glRectf));

                // Execute function call
                glrectf_lh(&argp_glrectf);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRECTI: ;
                args_glRecti argp_glrecti;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRecti)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrecti, ShmPTR->buffer, sizeof(args_glRecti));

                // Execute function call
                glrecti_lh(&argp_glrecti);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRECTS: ;
                args_glRects argp_glrects;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRects)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrects, ShmPTR->buffer, sizeof(args_glRects));

                // Execute function call
                glrects_lh(&argp_glrects);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRECTDV: ;
                args_glRectdv argp_glrectdv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRectdv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrectdv, ShmPTR->buffer, sizeof(args_glRectdv));

                // Execute function call
                glrectdv_lh(&argp_glrectdv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRECTFV: ;
                args_glRectfv argp_glrectfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRectfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrectfv, ShmPTR->buffer, sizeof(args_glRectfv));

                // Execute function call
                glrectfv_lh(&argp_glrectfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRECTIV: ;
                args_glRectiv argp_glrectiv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRectiv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrectiv, ShmPTR->buffer, sizeof(args_glRectiv));

                // Execute function call
                glrectiv_lh(&argp_glrectiv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRECTSV: ;
                args_glRectsv argp_glrectsv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glRectsv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrectsv, ShmPTR->buffer, sizeof(args_glRectsv));

                // Execute function call
                glrectsv_lh(&argp_glrectsv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLVERTEXPOINTER: ;
                args_glVertexPointer argp_glvertexpointer;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glVertexPointer)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertexpointer, ShmPTR->buffer, sizeof(args_glVertexPointer));

                // Execute function call
                glvertexpointer_lh(&argp_glvertexpointer);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLNORMALPOINTER: ;
                args_glNormalPointer argp_glnormalpointer;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glNormalPointer)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glnormalpointer, ShmPTR->buffer, sizeof(args_glNormalPointer));

                // Execute function call
                glnormalpointer_lh(&argp_glnormalpointer);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLORPOINTER: ;
                args_glColorPointer argp_glcolorpointer;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColorPointer)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolorpointer, ShmPTR->buffer, sizeof(args_glColorPointer));

                // Execute function call
                glcolorpointer_lh(&argp_glcolorpointer);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLINDEXPOINTER: ;
                args_glIndexPointer argp_glindexpointer;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glIndexPointer)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glindexpointer, ShmPTR->buffer, sizeof(args_glIndexPointer));

                // Execute function call
                glindexpointer_lh(&argp_glindexpointer);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXCOORDPOINTER: ;
                args_glTexCoordPointer argp_gltexcoordpointer;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexCoordPointer)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexcoordpointer, ShmPTR->buffer, sizeof(args_glTexCoordPointer));

                // Execute function call
                gltexcoordpointer_lh(&argp_gltexcoordpointer);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLEDGEFLAGPOINTER: ;
                args_glEdgeFlagPointer argp_gledgeflagpointer;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEdgeFlagPointer)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gledgeflagpointer, ShmPTR->buffer, sizeof(args_glEdgeFlagPointer));

                // Execute function call
                gledgeflagpointer_lh(&argp_gledgeflagpointer);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETPOINTERV: ;
                args_glGetPointerv argp_glgetpointerv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetPointerv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetpointerv, ShmPTR->buffer, sizeof(args_glGetPointerv));

                // Execute function call
                glgetpointerv_lh(&argp_glgetpointerv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLARRAYELEMENT: ;
                args_glArrayElement argp_glarrayelement;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glArrayElement)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glarrayelement, ShmPTR->buffer, sizeof(args_glArrayElement));

                // Execute function call
                glarrayelement_lh(&argp_glarrayelement);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLDRAWARRAYS: ;
                args_glDrawArrays argp_gldrawarrays;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glDrawArrays)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gldrawarrays, ShmPTR->buffer, sizeof(args_glDrawArrays));

                // Execute function call
                gldrawarrays_lh(&argp_gldrawarrays);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLDRAWELEMENTS: ;
                args_glDrawElements argp_gldrawelements;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glDrawElements)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gldrawelements, ShmPTR->buffer, sizeof(args_glDrawElements));

                // Execute function call
                gldrawelements_lh(&argp_gldrawelements);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLINTERLEAVEDARRAYS: ;
                args_glInterleavedArrays argp_glinterleavedarrays;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glInterleavedArrays)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glinterleavedarrays, ShmPTR->buffer, sizeof(args_glInterleavedArrays));

                // Execute function call
                glinterleavedarrays_lh(&argp_glinterleavedarrays);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLSHADEMODEL: ;
                args_glShadeModel argp_glshademodel;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glShadeModel)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glshademodel, ShmPTR->buffer, sizeof(args_glShadeModel));

                // Execute function call
                glshademodel_lh(&argp_glshademodel);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLLIGHTF: ;
                args_glLightf argp_gllightf;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glLightf)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gllightf, ShmPTR->buffer, sizeof(args_glLightf));

                // Execute function call
                gllightf_lh(&argp_gllightf);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLLIGHTI: ;
                args_glLighti argp_gllighti;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glLighti)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gllighti, ShmPTR->buffer, sizeof(args_glLighti));

                // Execute function call
                gllighti_lh(&argp_gllighti);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLLIGHTFV: ;
                args_glLightfv argp_gllightfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glLightfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gllightfv, ShmPTR->buffer, sizeof(args_glLightfv));

                // Execute function call
                gllightfv_lh(&argp_gllightfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLLIGHTIV: ;
                args_glLightiv argp_gllightiv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glLightiv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gllightiv, ShmPTR->buffer, sizeof(args_glLightiv));

                // Execute function call
                gllightiv_lh(&argp_gllightiv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETLIGHTFV: ;
                args_glGetLightfv argp_glgetlightfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetLightfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetlightfv, ShmPTR->buffer, sizeof(args_glGetLightfv));

                // Execute function call
                glgetlightfv_lh(&argp_glgetlightfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETLIGHTIV: ;
                args_glGetLightiv argp_glgetlightiv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetLightiv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetlightiv, ShmPTR->buffer, sizeof(args_glGetLightiv));

                // Execute function call
                glgetlightiv_lh(&argp_glgetlightiv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLLIGHTMODELF: ;
                args_glLightModelf argp_gllightmodelf;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glLightModelf)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gllightmodelf, ShmPTR->buffer, sizeof(args_glLightModelf));

                // Execute function call
                gllightmodelf_lh(&argp_gllightmodelf);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLLIGHTMODELI: ;
                args_glLightModeli argp_gllightmodeli;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glLightModeli)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gllightmodeli, ShmPTR->buffer, sizeof(args_glLightModeli));

                // Execute function call
                gllightmodeli_lh(&argp_gllightmodeli);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLLIGHTMODELFV: ;
                args_glLightModelfv argp_gllightmodelfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glLightModelfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gllightmodelfv, ShmPTR->buffer, sizeof(args_glLightModelfv));

                // Execute function call
                gllightmodelfv_lh(&argp_gllightmodelfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLLIGHTMODELIV: ;
                args_glLightModeliv argp_gllightmodeliv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glLightModeliv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gllightmodeliv, ShmPTR->buffer, sizeof(args_glLightModeliv));

                // Execute function call
                gllightmodeliv_lh(&argp_gllightmodeliv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMATERIALF: ;
                args_glMaterialf argp_glmaterialf;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMaterialf)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmaterialf, ShmPTR->buffer, sizeof(args_glMaterialf));

                // Execute function call
                glmaterialf_lh(&argp_glmaterialf);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMATERIALI: ;
                args_glMateriali argp_glmateriali;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMateriali)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmateriali, ShmPTR->buffer, sizeof(args_glMateriali));

                // Execute function call
                glmateriali_lh(&argp_glmateriali);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMATERIALFV: ;
                args_glMaterialfv argp_glmaterialfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMaterialfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmaterialfv, ShmPTR->buffer, sizeof(args_glMaterialfv));

                // Execute function call
                glmaterialfv_lh(&argp_glmaterialfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMATERIALIV: ;
                args_glMaterialiv argp_glmaterialiv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMaterialiv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmaterialiv, ShmPTR->buffer, sizeof(args_glMaterialiv));

                // Execute function call
                glmaterialiv_lh(&argp_glmaterialiv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETMATERIALFV: ;
                args_glGetMaterialfv argp_glgetmaterialfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetMaterialfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetmaterialfv, ShmPTR->buffer, sizeof(args_glGetMaterialfv));

                // Execute function call
                glgetmaterialfv_lh(&argp_glgetmaterialfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETMATERIALIV: ;
                args_glGetMaterialiv argp_glgetmaterialiv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetMaterialiv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetmaterialiv, ShmPTR->buffer, sizeof(args_glGetMaterialiv));

                // Execute function call
                glgetmaterialiv_lh(&argp_glgetmaterialiv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLORMATERIAL: ;
                args_glColorMaterial argp_glcolormaterial;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColorMaterial)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolormaterial, ShmPTR->buffer, sizeof(args_glColorMaterial));

                // Execute function call
                glcolormaterial_lh(&argp_glcolormaterial);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPIXELZOOM: ;
                args_glPixelZoom argp_glpixelzoom;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPixelZoom)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glpixelzoom, ShmPTR->buffer, sizeof(args_glPixelZoom));

                // Execute function call
                glpixelzoom_lh(&argp_glpixelzoom);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPIXELSTOREF: ;
                args_glPixelStoref argp_glpixelstoref;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPixelStoref)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glpixelstoref, ShmPTR->buffer, sizeof(args_glPixelStoref));

                // Execute function call
                glpixelstoref_lh(&argp_glpixelstoref);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPIXELSTOREI: ;
                args_glPixelStorei argp_glpixelstorei;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPixelStorei)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glpixelstorei, ShmPTR->buffer, sizeof(args_glPixelStorei));

                // Execute function call
                glpixelstorei_lh(&argp_glpixelstorei);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPIXELTRANSFERF: ;
                args_glPixelTransferf argp_glpixeltransferf;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPixelTransferf)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glpixeltransferf, ShmPTR->buffer, sizeof(args_glPixelTransferf));

                // Execute function call
                glpixeltransferf_lh(&argp_glpixeltransferf);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPIXELTRANSFERI: ;
                args_glPixelTransferi argp_glpixeltransferi;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPixelTransferi)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glpixeltransferi, ShmPTR->buffer, sizeof(args_glPixelTransferi));

                // Execute function call
                glpixeltransferi_lh(&argp_glpixeltransferi);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPIXELMAPFV: ;
                args_glPixelMapfv argp_glpixelmapfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPixelMapfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glpixelmapfv, ShmPTR->buffer, sizeof(args_glPixelMapfv));

                // Execute function call
                glpixelmapfv_lh(&argp_glpixelmapfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPIXELMAPUIV: ;
                args_glPixelMapuiv argp_glpixelmapuiv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPixelMapuiv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glpixelmapuiv, ShmPTR->buffer, sizeof(args_glPixelMapuiv));

                // Execute function call
                glpixelmapuiv_lh(&argp_glpixelmapuiv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPIXELMAPUSV: ;
                args_glPixelMapusv argp_glpixelmapusv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPixelMapusv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glpixelmapusv, ShmPTR->buffer, sizeof(args_glPixelMapusv));

                // Execute function call
                glpixelmapusv_lh(&argp_glpixelmapusv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETPIXELMAPFV: ;
                args_glGetPixelMapfv argp_glgetpixelmapfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetPixelMapfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetpixelmapfv, ShmPTR->buffer, sizeof(args_glGetPixelMapfv));

                // Execute function call
                glgetpixelmapfv_lh(&argp_glgetpixelmapfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETPIXELMAPUIV: ;
                args_glGetPixelMapuiv argp_glgetpixelmapuiv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetPixelMapuiv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetpixelmapuiv, ShmPTR->buffer, sizeof(args_glGetPixelMapuiv));

                // Execute function call
                glgetpixelmapuiv_lh(&argp_glgetpixelmapuiv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETPIXELMAPUSV: ;
                args_glGetPixelMapusv argp_glgetpixelmapusv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetPixelMapusv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetpixelmapusv, ShmPTR->buffer, sizeof(args_glGetPixelMapusv));

                // Execute function call
                glgetpixelmapusv_lh(&argp_glgetpixelmapusv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLBITMAP: ;
                args_glBitmap argp_glbitmap;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glBitmap)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glbitmap, ShmPTR->buffer, sizeof(args_glBitmap));

                // Execute function call
                glbitmap_lh(&argp_glbitmap);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLREADPIXELS: ;
                args_glReadPixels argp_glreadpixels;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glReadPixels)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glreadpixels, ShmPTR->buffer, sizeof(args_glReadPixels));

                // Execute function call
                glreadpixels_lh(&argp_glreadpixels);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLDRAWPIXELS: ;
                args_glDrawPixels argp_gldrawpixels;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glDrawPixels)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gldrawpixels, ShmPTR->buffer, sizeof(args_glDrawPixels));

                // Execute function call
                gldrawpixels_lh(&argp_gldrawpixels);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOPYPIXELS: ;
                args_glCopyPixels argp_glcopypixels;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCopyPixels)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcopypixels, ShmPTR->buffer, sizeof(args_glCopyPixels));

                // Execute function call
                glcopypixels_lh(&argp_glcopypixels);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLSTENCILFUNC: ;
                args_glStencilFunc argp_glstencilfunc;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glStencilFunc)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glstencilfunc, ShmPTR->buffer, sizeof(args_glStencilFunc));

                // Execute function call
                glstencilfunc_lh(&argp_glstencilfunc);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLSTENCILMASK: ;
                args_glStencilMask argp_glstencilmask;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glStencilMask)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glstencilmask, ShmPTR->buffer, sizeof(args_glStencilMask));

                // Execute function call
                glstencilmask_lh(&argp_glstencilmask);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLSTENCILOP: ;
                args_glStencilOp argp_glstencilop;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glStencilOp)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glstencilop, ShmPTR->buffer, sizeof(args_glStencilOp));

                // Execute function call
                glstencilop_lh(&argp_glstencilop);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCLEARSTENCIL: ;
                args_glClearStencil argp_glclearstencil;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glClearStencil)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glclearstencil, ShmPTR->buffer, sizeof(args_glClearStencil));

                // Execute function call
                glclearstencil_lh(&argp_glclearstencil);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXGEND: ;
                args_glTexGend argp_gltexgend;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexGend)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexgend, ShmPTR->buffer, sizeof(args_glTexGend));

                // Execute function call
                gltexgend_lh(&argp_gltexgend);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXGENF: ;
                args_glTexGenf argp_gltexgenf;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexGenf)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexgenf, ShmPTR->buffer, sizeof(args_glTexGenf));

                // Execute function call
                gltexgenf_lh(&argp_gltexgenf);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXGENI: ;
                args_glTexGeni argp_gltexgeni;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexGeni)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexgeni, ShmPTR->buffer, sizeof(args_glTexGeni));

                // Execute function call
                gltexgeni_lh(&argp_gltexgeni);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXGENDV: ;
                args_glTexGendv argp_gltexgendv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexGendv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexgendv, ShmPTR->buffer, sizeof(args_glTexGendv));

                // Execute function call
                gltexgendv_lh(&argp_gltexgendv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXGENFV: ;
                args_glTexGenfv argp_gltexgenfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexGenfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexgenfv, ShmPTR->buffer, sizeof(args_glTexGenfv));

                // Execute function call
                gltexgenfv_lh(&argp_gltexgenfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXGENIV: ;
                args_glTexGeniv argp_gltexgeniv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexGeniv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexgeniv, ShmPTR->buffer, sizeof(args_glTexGeniv));

                // Execute function call
                gltexgeniv_lh(&argp_gltexgeniv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETTEXGENDV: ;
                args_glGetTexGendv argp_glgettexgendv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetTexGendv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgettexgendv, ShmPTR->buffer, sizeof(args_glGetTexGendv));

                // Execute function call
                glgettexgendv_lh(&argp_glgettexgendv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETTEXGENFV: ;
                args_glGetTexGenfv argp_glgettexgenfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetTexGenfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgettexgenfv, ShmPTR->buffer, sizeof(args_glGetTexGenfv));

                // Execute function call
                glgettexgenfv_lh(&argp_glgettexgenfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETTEXGENIV: ;
                args_glGetTexGeniv argp_glgettexgeniv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetTexGeniv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgettexgeniv, ShmPTR->buffer, sizeof(args_glGetTexGeniv));

                // Execute function call
                glgettexgeniv_lh(&argp_glgettexgeniv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXENVF: ;
                args_glTexEnvf argp_gltexenvf;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexEnvf)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexenvf, ShmPTR->buffer, sizeof(args_glTexEnvf));

                // Execute function call
                gltexenvf_lh(&argp_gltexenvf);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXENVI: ;
                args_glTexEnvi argp_gltexenvi;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexEnvi)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexenvi, ShmPTR->buffer, sizeof(args_glTexEnvi));

                // Execute function call
                gltexenvi_lh(&argp_gltexenvi);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXENVFV: ;
                args_glTexEnvfv argp_gltexenvfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexEnvfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexenvfv, ShmPTR->buffer, sizeof(args_glTexEnvfv));

                // Execute function call
                gltexenvfv_lh(&argp_gltexenvfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXENVIV: ;
                args_glTexEnviv argp_gltexenviv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexEnviv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexenviv, ShmPTR->buffer, sizeof(args_glTexEnviv));

                // Execute function call
                gltexenviv_lh(&argp_gltexenviv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETTEXENVFV: ;
                args_glGetTexEnvfv argp_glgettexenvfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetTexEnvfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgettexenvfv, ShmPTR->buffer, sizeof(args_glGetTexEnvfv));

                // Execute function call
                glgettexenvfv_lh(&argp_glgettexenvfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETTEXENVIV: ;
                args_glGetTexEnviv argp_glgettexenviv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetTexEnviv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgettexenviv, ShmPTR->buffer, sizeof(args_glGetTexEnviv));

                // Execute function call
                glgettexenviv_lh(&argp_glgettexenviv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXPARAMETERF: ;
                args_glTexParameterf argp_gltexparameterf;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexParameterf)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexparameterf, ShmPTR->buffer, sizeof(args_glTexParameterf));

                // Execute function call
                gltexparameterf_lh(&argp_gltexparameterf);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXPARAMETERI: ;
                args_glTexParameteri argp_gltexparameteri;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexParameteri)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexparameteri, ShmPTR->buffer, sizeof(args_glTexParameteri));

                // Execute function call
                gltexparameteri_lh(&argp_gltexparameteri);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXPARAMETERFV: ;
                args_glTexParameterfv argp_gltexparameterfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexParameterfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexparameterfv, ShmPTR->buffer, sizeof(args_glTexParameterfv));

                // Execute function call
                gltexparameterfv_lh(&argp_gltexparameterfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXPARAMETERIV: ;
                args_glTexParameteriv argp_gltexparameteriv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexParameteriv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexparameteriv, ShmPTR->buffer, sizeof(args_glTexParameteriv));

                // Execute function call
                gltexparameteriv_lh(&argp_gltexparameteriv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETTEXPARAMETERFV: ;
                args_glGetTexParameterfv argp_glgettexparameterfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetTexParameterfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgettexparameterfv, ShmPTR->buffer, sizeof(args_glGetTexParameterfv));

                // Execute function call
                glgettexparameterfv_lh(&argp_glgettexparameterfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETTEXPARAMETERIV: ;
                args_glGetTexParameteriv argp_glgettexparameteriv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetTexParameteriv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgettexparameteriv, ShmPTR->buffer, sizeof(args_glGetTexParameteriv));

                // Execute function call
                glgettexparameteriv_lh(&argp_glgettexparameteriv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETTEXLEVELPARAMETERFV: ;
                args_glGetTexLevelParameterfv argp_glgettexlevelparameterfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetTexLevelParameterfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgettexlevelparameterfv, ShmPTR->buffer, sizeof(args_glGetTexLevelParameterfv));

                // Execute function call
                glgettexlevelparameterfv_lh(&argp_glgettexlevelparameterfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETTEXLEVELPARAMETERIV: ;
                args_glGetTexLevelParameteriv argp_glgettexlevelparameteriv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetTexLevelParameteriv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgettexlevelparameteriv, ShmPTR->buffer, sizeof(args_glGetTexLevelParameteriv));

                // Execute function call
                glgettexlevelparameteriv_lh(&argp_glgettexlevelparameteriv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXIMAGE1D: ;
                args_glTexImage1D argp_glteximage1d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexImage1D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glteximage1d, ShmPTR->buffer, sizeof(args_glTexImage1D));

                // Execute function call
                glteximage1d_lh(&argp_glteximage1d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXIMAGE2D: ;
                args_glTexImage2D argp_glteximage2d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexImage2D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glteximage2d, ShmPTR->buffer, sizeof(args_glTexImage2D));

                // Execute function call
                glteximage2d_lh(&argp_glteximage2d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETTEXIMAGE: ;
                args_glGetTexImage argp_glgetteximage;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetTexImage)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetteximage, ShmPTR->buffer, sizeof(args_glGetTexImage));

                // Execute function call
                glgetteximage_lh(&argp_glgetteximage);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGENTEXTURES: ;
                args_glGenTextures argp_glgentextures;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGenTextures)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgentextures, ShmPTR->buffer, sizeof(args_glGenTextures));

                // Execute function call
                glgentextures_lh(&argp_glgentextures);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLDELETETEXTURES: ;
                args_glDeleteTextures argp_gldeletetextures;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glDeleteTextures)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gldeletetextures, ShmPTR->buffer, sizeof(args_glDeleteTextures));

                // Execute function call
                gldeletetextures_lh(&argp_gldeletetextures);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLBINDTEXTURE: ;
                args_glBindTexture argp_glbindtexture;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glBindTexture)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glbindtexture, ShmPTR->buffer, sizeof(args_glBindTexture));

                // Execute function call
                glbindtexture_lh(&argp_glbindtexture);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPRIORITIZETEXTURES: ;
                args_glPrioritizeTextures argp_glprioritizetextures;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPrioritizeTextures)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glprioritizetextures, ShmPTR->buffer, sizeof(args_glPrioritizeTextures));

                // Execute function call
                glprioritizetextures_lh(&argp_glprioritizetextures);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLARETEXTURESRESIDENT: ;
                args_glAreTexturesResident argp_glaretexturesresident;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glAreTexturesResident)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glaretexturesresident, ShmPTR->buffer, sizeof(args_glAreTexturesResident));

                // Execute function call
                glaretexturesresident_lh(&argp_glaretexturesresident);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLISTEXTURE: ;
                args_glIsTexture argp_glistexture;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glIsTexture)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glistexture, ShmPTR->buffer, sizeof(args_glIsTexture));

                // Execute function call
                glistexture_lh(&argp_glistexture);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXSUBIMAGE1D: ;
                args_glTexSubImage1D argp_gltexsubimage1d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexSubImage1D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexsubimage1d, ShmPTR->buffer, sizeof(args_glTexSubImage1D));

                // Execute function call
                gltexsubimage1d_lh(&argp_gltexsubimage1d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXSUBIMAGE2D: ;
                args_glTexSubImage2D argp_gltexsubimage2d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexSubImage2D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexsubimage2d, ShmPTR->buffer, sizeof(args_glTexSubImage2D));

                // Execute function call
                gltexsubimage2d_lh(&argp_gltexsubimage2d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOPYTEXIMAGE1D: ;
                args_glCopyTexImage1D argp_glcopyteximage1d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCopyTexImage1D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcopyteximage1d, ShmPTR->buffer, sizeof(args_glCopyTexImage1D));

                // Execute function call
                glcopyteximage1d_lh(&argp_glcopyteximage1d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOPYTEXIMAGE2D: ;
                args_glCopyTexImage2D argp_glcopyteximage2d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCopyTexImage2D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcopyteximage2d, ShmPTR->buffer, sizeof(args_glCopyTexImage2D));

                // Execute function call
                glcopyteximage2d_lh(&argp_glcopyteximage2d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOPYTEXSUBIMAGE1D: ;
                args_glCopyTexSubImage1D argp_glcopytexsubimage1d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCopyTexSubImage1D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcopytexsubimage1d, ShmPTR->buffer, sizeof(args_glCopyTexSubImage1D));

                // Execute function call
                glcopytexsubimage1d_lh(&argp_glcopytexsubimage1d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOPYTEXSUBIMAGE2D: ;
                args_glCopyTexSubImage2D argp_glcopytexsubimage2d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCopyTexSubImage2D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcopytexsubimage2d, ShmPTR->buffer, sizeof(args_glCopyTexSubImage2D));

                // Execute function call
                glcopytexsubimage2d_lh(&argp_glcopytexsubimage2d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMAP1D: ;
                args_glMap1d argp_glmap1d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMap1d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmap1d, ShmPTR->buffer, sizeof(args_glMap1d));

                // Execute function call
                glmap1d_lh(&argp_glmap1d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMAP1F: ;
                args_glMap1f argp_glmap1f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMap1f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmap1f, ShmPTR->buffer, sizeof(args_glMap1f));

                // Execute function call
                glmap1f_lh(&argp_glmap1f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMAP2D: ;
                args_glMap2d argp_glmap2d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMap2d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmap2d, ShmPTR->buffer, sizeof(args_glMap2d));

                // Execute function call
                glmap2d_lh(&argp_glmap2d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMAP2F: ;
                args_glMap2f argp_glmap2f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMap2f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmap2f, ShmPTR->buffer, sizeof(args_glMap2f));

                // Execute function call
                glmap2f_lh(&argp_glmap2f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETMAPDV: ;
                args_glGetMapdv argp_glgetmapdv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetMapdv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetmapdv, ShmPTR->buffer, sizeof(args_glGetMapdv));

                // Execute function call
                glgetmapdv_lh(&argp_glgetmapdv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETMAPFV: ;
                args_glGetMapfv argp_glgetmapfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetMapfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetmapfv, ShmPTR->buffer, sizeof(args_glGetMapfv));

                // Execute function call
                glgetmapfv_lh(&argp_glgetmapfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETMAPIV: ;
                args_glGetMapiv argp_glgetmapiv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetMapiv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetmapiv, ShmPTR->buffer, sizeof(args_glGetMapiv));

                // Execute function call
                glgetmapiv_lh(&argp_glgetmapiv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLEVALCOORD1D: ;
                args_glEvalCoord1d argp_glevalcoord1d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEvalCoord1d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glevalcoord1d, ShmPTR->buffer, sizeof(args_glEvalCoord1d));

                // Execute function call
                glevalcoord1d_lh(&argp_glevalcoord1d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLEVALCOORD1F: ;
                args_glEvalCoord1f argp_glevalcoord1f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEvalCoord1f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glevalcoord1f, ShmPTR->buffer, sizeof(args_glEvalCoord1f));

                // Execute function call
                glevalcoord1f_lh(&argp_glevalcoord1f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLEVALCOORD1DV: ;
                args_glEvalCoord1dv argp_glevalcoord1dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEvalCoord1dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glevalcoord1dv, ShmPTR->buffer, sizeof(args_glEvalCoord1dv));

                // Execute function call
                glevalcoord1dv_lh(&argp_glevalcoord1dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLEVALCOORD1FV: ;
                args_glEvalCoord1fv argp_glevalcoord1fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEvalCoord1fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glevalcoord1fv, ShmPTR->buffer, sizeof(args_glEvalCoord1fv));

                // Execute function call
                glevalcoord1fv_lh(&argp_glevalcoord1fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLEVALCOORD2D: ;
                args_glEvalCoord2d argp_glevalcoord2d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEvalCoord2d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glevalcoord2d, ShmPTR->buffer, sizeof(args_glEvalCoord2d));

                // Execute function call
                glevalcoord2d_lh(&argp_glevalcoord2d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLEVALCOORD2F: ;
                args_glEvalCoord2f argp_glevalcoord2f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEvalCoord2f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glevalcoord2f, ShmPTR->buffer, sizeof(args_glEvalCoord2f));

                // Execute function call
                glevalcoord2f_lh(&argp_glevalcoord2f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLEVALCOORD2DV: ;
                args_glEvalCoord2dv argp_glevalcoord2dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEvalCoord2dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glevalcoord2dv, ShmPTR->buffer, sizeof(args_glEvalCoord2dv));

                // Execute function call
                glevalcoord2dv_lh(&argp_glevalcoord2dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLEVALCOORD2FV: ;
                args_glEvalCoord2fv argp_glevalcoord2fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEvalCoord2fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glevalcoord2fv, ShmPTR->buffer, sizeof(args_glEvalCoord2fv));

                // Execute function call
                glevalcoord2fv_lh(&argp_glevalcoord2fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMAPGRID1D: ;
                args_glMapGrid1d argp_glmapgrid1d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMapGrid1d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmapgrid1d, ShmPTR->buffer, sizeof(args_glMapGrid1d));

                // Execute function call
                glmapgrid1d_lh(&argp_glmapgrid1d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMAPGRID1F: ;
                args_glMapGrid1f argp_glmapgrid1f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMapGrid1f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmapgrid1f, ShmPTR->buffer, sizeof(args_glMapGrid1f));

                // Execute function call
                glmapgrid1f_lh(&argp_glmapgrid1f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMAPGRID2D: ;
                args_glMapGrid2d argp_glmapgrid2d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMapGrid2d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmapgrid2d, ShmPTR->buffer, sizeof(args_glMapGrid2d));

                // Execute function call
                glmapgrid2d_lh(&argp_glmapgrid2d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMAPGRID2F: ;
                args_glMapGrid2f argp_glmapgrid2f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMapGrid2f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmapgrid2f, ShmPTR->buffer, sizeof(args_glMapGrid2f));

                // Execute function call
                glmapgrid2f_lh(&argp_glmapgrid2f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLEVALPOINT1: ;
                args_glEvalPoint1 argp_glevalpoint1;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEvalPoint1)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glevalpoint1, ShmPTR->buffer, sizeof(args_glEvalPoint1));

                // Execute function call
                glevalpoint1_lh(&argp_glevalpoint1);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLEVALPOINT2: ;
                args_glEvalPoint2 argp_glevalpoint2;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEvalPoint2)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glevalpoint2, ShmPTR->buffer, sizeof(args_glEvalPoint2));

                // Execute function call
                glevalpoint2_lh(&argp_glevalpoint2);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLEVALMESH1: ;
                args_glEvalMesh1 argp_glevalmesh1;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEvalMesh1)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glevalmesh1, ShmPTR->buffer, sizeof(args_glEvalMesh1));

                // Execute function call
                glevalmesh1_lh(&argp_glevalmesh1);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLEVALMESH2: ;
                args_glEvalMesh2 argp_glevalmesh2;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glEvalMesh2)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glevalmesh2, ShmPTR->buffer, sizeof(args_glEvalMesh2));

                // Execute function call
                glevalmesh2_lh(&argp_glevalmesh2);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLFOGF: ;
                args_glFogf argp_glfogf;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glFogf)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glfogf, ShmPTR->buffer, sizeof(args_glFogf));

                // Execute function call
                glfogf_lh(&argp_glfogf);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLFOGI: ;
                args_glFogi argp_glfogi;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glFogi)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glfogi, ShmPTR->buffer, sizeof(args_glFogi));

                // Execute function call
                glfogi_lh(&argp_glfogi);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLFOGFV: ;
                args_glFogfv argp_glfogfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glFogfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glfogfv, ShmPTR->buffer, sizeof(args_glFogfv));

                // Execute function call
                glfogfv_lh(&argp_glfogfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLFOGIV: ;
                args_glFogiv argp_glfogiv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glFogiv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glfogiv, ShmPTR->buffer, sizeof(args_glFogiv));

                // Execute function call
                glfogiv_lh(&argp_glfogiv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLFEEDBACKBUFFER: ;
                args_glFeedbackBuffer argp_glfeedbackbuffer;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glFeedbackBuffer)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glfeedbackbuffer, ShmPTR->buffer, sizeof(args_glFeedbackBuffer));

                // Execute function call
                glfeedbackbuffer_lh(&argp_glfeedbackbuffer);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPASSTHROUGH: ;
                args_glPassThrough argp_glpassthrough;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPassThrough)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glpassthrough, ShmPTR->buffer, sizeof(args_glPassThrough));

                // Execute function call
                glpassthrough_lh(&argp_glpassthrough);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLSELECTBUFFER: ;
                args_glSelectBuffer argp_glselectbuffer;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glSelectBuffer)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glselectbuffer, ShmPTR->buffer, sizeof(args_glSelectBuffer));

                // Execute function call
                glselectbuffer_lh(&argp_glselectbuffer);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLINITNAMES: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glinitnames_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLLOADNAME: ;
                args_glLoadName argp_glloadname;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glLoadName)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glloadname, ShmPTR->buffer, sizeof(args_glLoadName));

                // Execute function call
                glloadname_lh(&argp_glloadname);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPUSHNAME: ;
                args_glPushName argp_glpushname;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glPushName)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glpushname, ShmPTR->buffer, sizeof(args_glPushName));

                // Execute function call
                glpushname_lh(&argp_glpushname);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLPOPNAME: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glpopname_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLDRAWRANGEELEMENTS: ;
                args_glDrawRangeElements argp_gldrawrangeelements;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glDrawRangeElements)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gldrawrangeelements, ShmPTR->buffer, sizeof(args_glDrawRangeElements));

                // Execute function call
                gldrawrangeelements_lh(&argp_gldrawrangeelements);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXIMAGE3D: ;
                args_glTexImage3D argp_glteximage3d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexImage3D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glteximage3d, ShmPTR->buffer, sizeof(args_glTexImage3D));

                // Execute function call
                glteximage3d_lh(&argp_glteximage3d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLTEXSUBIMAGE3D: ;
                args_glTexSubImage3D argp_gltexsubimage3d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glTexSubImage3D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltexsubimage3d, ShmPTR->buffer, sizeof(args_glTexSubImage3D));

                // Execute function call
                gltexsubimage3d_lh(&argp_gltexsubimage3d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOPYTEXSUBIMAGE3D: ;
                args_glCopyTexSubImage3D argp_glcopytexsubimage3d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCopyTexSubImage3D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcopytexsubimage3d, ShmPTR->buffer, sizeof(args_glCopyTexSubImage3D));

                // Execute function call
                glcopytexsubimage3d_lh(&argp_glcopytexsubimage3d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLORTABLE: ;
                args_glColorTable argp_glcolortable;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColorTable)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolortable, ShmPTR->buffer, sizeof(args_glColorTable));

                // Execute function call
                glcolortable_lh(&argp_glcolortable);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLORSUBTABLE: ;
                args_glColorSubTable argp_glcolorsubtable;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColorSubTable)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolorsubtable, ShmPTR->buffer, sizeof(args_glColorSubTable));

                // Execute function call
                glcolorsubtable_lh(&argp_glcolorsubtable);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLORTABLEPARAMETERIV: ;
                args_glColorTableParameteriv argp_glcolortableparameteriv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColorTableParameteriv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolortableparameteriv, ShmPTR->buffer, sizeof(args_glColorTableParameteriv));

                // Execute function call
                glcolortableparameteriv_lh(&argp_glcolortableparameteriv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOLORTABLEPARAMETERFV: ;
                args_glColorTableParameterfv argp_glcolortableparameterfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glColorTableParameterfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcolortableparameterfv, ShmPTR->buffer, sizeof(args_glColorTableParameterfv));

                // Execute function call
                glcolortableparameterfv_lh(&argp_glcolortableparameterfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOPYCOLORSUBTABLE: ;
                args_glCopyColorSubTable argp_glcopycolorsubtable;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCopyColorSubTable)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcopycolorsubtable, ShmPTR->buffer, sizeof(args_glCopyColorSubTable));

                // Execute function call
                glcopycolorsubtable_lh(&argp_glcopycolorsubtable);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOPYCOLORTABLE: ;
                args_glCopyColorTable argp_glcopycolortable;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCopyColorTable)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcopycolortable, ShmPTR->buffer, sizeof(args_glCopyColorTable));

                // Execute function call
                glcopycolortable_lh(&argp_glcopycolortable);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETCOLORTABLE: ;
                args_glGetColorTable argp_glgetcolortable;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetColorTable)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetcolortable, ShmPTR->buffer, sizeof(args_glGetColorTable));

                // Execute function call
                glgetcolortable_lh(&argp_glgetcolortable);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETCOLORTABLEPARAMETERFV: ;
                args_glGetColorTableParameterfv argp_glgetcolortableparameterfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetColorTableParameterfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetcolortableparameterfv, ShmPTR->buffer, sizeof(args_glGetColorTableParameterfv));

                // Execute function call
                glgetcolortableparameterfv_lh(&argp_glgetcolortableparameterfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETCOLORTABLEPARAMETERIV: ;
                args_glGetColorTableParameteriv argp_glgetcolortableparameteriv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetColorTableParameteriv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetcolortableparameteriv, ShmPTR->buffer, sizeof(args_glGetColorTableParameteriv));

                // Execute function call
                glgetcolortableparameteriv_lh(&argp_glgetcolortableparameteriv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLBLENDEQUATION: ;
                args_glBlendEquation argp_glblendequation;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glBlendEquation)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glblendequation, ShmPTR->buffer, sizeof(args_glBlendEquation));

                // Execute function call
                glblendequation_lh(&argp_glblendequation);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLBLENDCOLOR: ;
                args_glBlendColor argp_glblendcolor;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glBlendColor)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glblendcolor, ShmPTR->buffer, sizeof(args_glBlendColor));

                // Execute function call
                glblendcolor_lh(&argp_glblendcolor);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLHISTOGRAM: ;
                args_glHistogram argp_glhistogram;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glHistogram)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glhistogram, ShmPTR->buffer, sizeof(args_glHistogram));

                // Execute function call
                glhistogram_lh(&argp_glhistogram);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRESETHISTOGRAM: ;
                args_glResetHistogram argp_glresethistogram;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glResetHistogram)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glresethistogram, ShmPTR->buffer, sizeof(args_glResetHistogram));

                // Execute function call
                glresethistogram_lh(&argp_glresethistogram);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETHISTOGRAM: ;
                args_glGetHistogram argp_glgethistogram;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetHistogram)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgethistogram, ShmPTR->buffer, sizeof(args_glGetHistogram));

                // Execute function call
                glgethistogram_lh(&argp_glgethistogram);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETHISTOGRAMPARAMETERFV: ;
                args_glGetHistogramParameterfv argp_glgethistogramparameterfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetHistogramParameterfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgethistogramparameterfv, ShmPTR->buffer, sizeof(args_glGetHistogramParameterfv));

                // Execute function call
                glgethistogramparameterfv_lh(&argp_glgethistogramparameterfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETHISTOGRAMPARAMETERIV: ;
                args_glGetHistogramParameteriv argp_glgethistogramparameteriv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetHistogramParameteriv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgethistogramparameteriv, ShmPTR->buffer, sizeof(args_glGetHistogramParameteriv));

                // Execute function call
                glgethistogramparameteriv_lh(&argp_glgethistogramparameteriv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMINMAX: ;
                args_glMinmax argp_glminmax;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMinmax)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glminmax, ShmPTR->buffer, sizeof(args_glMinmax));

                // Execute function call
                glminmax_lh(&argp_glminmax);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLRESETMINMAX: ;
                args_glResetMinmax argp_glresetminmax;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glResetMinmax)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glresetminmax, ShmPTR->buffer, sizeof(args_glResetMinmax));

                // Execute function call
                glresetminmax_lh(&argp_glresetminmax);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETMINMAX: ;
                args_glGetMinmax argp_glgetminmax;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetMinmax)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetminmax, ShmPTR->buffer, sizeof(args_glGetMinmax));

                // Execute function call
                glgetminmax_lh(&argp_glgetminmax);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETMINMAXPARAMETERFV: ;
                args_glGetMinmaxParameterfv argp_glgetminmaxparameterfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetMinmaxParameterfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetminmaxparameterfv, ShmPTR->buffer, sizeof(args_glGetMinmaxParameterfv));

                // Execute function call
                glgetminmaxparameterfv_lh(&argp_glgetminmaxparameterfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETMINMAXPARAMETERIV: ;
                args_glGetMinmaxParameteriv argp_glgetminmaxparameteriv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetMinmaxParameteriv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetminmaxparameteriv, ShmPTR->buffer, sizeof(args_glGetMinmaxParameteriv));

                // Execute function call
                glgetminmaxparameteriv_lh(&argp_glgetminmaxparameteriv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCONVOLUTIONFILTER1D: ;
                args_glConvolutionFilter1D argp_glconvolutionfilter1d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glConvolutionFilter1D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glconvolutionfilter1d, ShmPTR->buffer, sizeof(args_glConvolutionFilter1D));

                // Execute function call
                glconvolutionfilter1d_lh(&argp_glconvolutionfilter1d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCONVOLUTIONFILTER2D: ;
                args_glConvolutionFilter2D argp_glconvolutionfilter2d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glConvolutionFilter2D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glconvolutionfilter2d, ShmPTR->buffer, sizeof(args_glConvolutionFilter2D));

                // Execute function call
                glconvolutionfilter2d_lh(&argp_glconvolutionfilter2d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCONVOLUTIONPARAMETERF: ;
                args_glConvolutionParameterf argp_glconvolutionparameterf;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glConvolutionParameterf)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glconvolutionparameterf, ShmPTR->buffer, sizeof(args_glConvolutionParameterf));

                // Execute function call
                glconvolutionparameterf_lh(&argp_glconvolutionparameterf);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCONVOLUTIONPARAMETERFV: ;
                args_glConvolutionParameterfv argp_glconvolutionparameterfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glConvolutionParameterfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glconvolutionparameterfv, ShmPTR->buffer, sizeof(args_glConvolutionParameterfv));

                // Execute function call
                glconvolutionparameterfv_lh(&argp_glconvolutionparameterfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCONVOLUTIONPARAMETERI: ;
                args_glConvolutionParameteri argp_glconvolutionparameteri;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glConvolutionParameteri)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glconvolutionparameteri, ShmPTR->buffer, sizeof(args_glConvolutionParameteri));

                // Execute function call
                glconvolutionparameteri_lh(&argp_glconvolutionparameteri);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCONVOLUTIONPARAMETERIV: ;
                args_glConvolutionParameteriv argp_glconvolutionparameteriv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glConvolutionParameteriv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glconvolutionparameteriv, ShmPTR->buffer, sizeof(args_glConvolutionParameteriv));

                // Execute function call
                glconvolutionparameteriv_lh(&argp_glconvolutionparameteriv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOPYCONVOLUTIONFILTER1D: ;
                args_glCopyConvolutionFilter1D argp_glcopyconvolutionfilter1d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCopyConvolutionFilter1D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcopyconvolutionfilter1d, ShmPTR->buffer, sizeof(args_glCopyConvolutionFilter1D));

                // Execute function call
                glcopyconvolutionfilter1d_lh(&argp_glcopyconvolutionfilter1d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOPYCONVOLUTIONFILTER2D: ;
                args_glCopyConvolutionFilter2D argp_glcopyconvolutionfilter2d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCopyConvolutionFilter2D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcopyconvolutionfilter2d, ShmPTR->buffer, sizeof(args_glCopyConvolutionFilter2D));

                // Execute function call
                glcopyconvolutionfilter2d_lh(&argp_glcopyconvolutionfilter2d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETCONVOLUTIONFILTER: ;
                args_glGetConvolutionFilter argp_glgetconvolutionfilter;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetConvolutionFilter)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetconvolutionfilter, ShmPTR->buffer, sizeof(args_glGetConvolutionFilter));

                // Execute function call
                glgetconvolutionfilter_lh(&argp_glgetconvolutionfilter);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETCONVOLUTIONPARAMETERFV: ;
                args_glGetConvolutionParameterfv argp_glgetconvolutionparameterfv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetConvolutionParameterfv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetconvolutionparameterfv, ShmPTR->buffer, sizeof(args_glGetConvolutionParameterfv));

                // Execute function call
                glgetconvolutionparameterfv_lh(&argp_glgetconvolutionparameterfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETCONVOLUTIONPARAMETERIV: ;
                args_glGetConvolutionParameteriv argp_glgetconvolutionparameteriv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetConvolutionParameteriv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetconvolutionparameteriv, ShmPTR->buffer, sizeof(args_glGetConvolutionParameteriv));

                // Execute function call
                glgetconvolutionparameteriv_lh(&argp_glgetconvolutionparameteriv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLSEPARABLEFILTER2D: ;
                args_glSeparableFilter2D argp_glseparablefilter2d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glSeparableFilter2D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glseparablefilter2d, ShmPTR->buffer, sizeof(args_glSeparableFilter2D));

                // Execute function call
                glseparablefilter2d_lh(&argp_glseparablefilter2d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETSEPARABLEFILTER: ;
                args_glGetSeparableFilter argp_glgetseparablefilter;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetSeparableFilter)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetseparablefilter, ShmPTR->buffer, sizeof(args_glGetSeparableFilter));

                // Execute function call
                glgetseparablefilter_lh(&argp_glgetseparablefilter);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLACTIVETEXTURE: ;
                args_glActiveTexture argp_glactivetexture;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glActiveTexture)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glactivetexture, ShmPTR->buffer, sizeof(args_glActiveTexture));

                // Execute function call
                glactivetexture_lh(&argp_glactivetexture);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCLIENTACTIVETEXTURE: ;
                args_glClientActiveTexture argp_glclientactivetexture;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glClientActiveTexture)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glclientactivetexture, ShmPTR->buffer, sizeof(args_glClientActiveTexture));

                // Execute function call
                glclientactivetexture_lh(&argp_glclientactivetexture);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOMPRESSEDTEXIMAGE1D: ;
                args_glCompressedTexImage1D argp_glcompressedteximage1d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCompressedTexImage1D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcompressedteximage1d, ShmPTR->buffer, sizeof(args_glCompressedTexImage1D));

                // Execute function call
                glcompressedteximage1d_lh(&argp_glcompressedteximage1d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOMPRESSEDTEXIMAGE2D: ;
                args_glCompressedTexImage2D argp_glcompressedteximage2d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCompressedTexImage2D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcompressedteximage2d, ShmPTR->buffer, sizeof(args_glCompressedTexImage2D));

                // Execute function call
                glcompressedteximage2d_lh(&argp_glcompressedteximage2d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOMPRESSEDTEXIMAGE3D: ;
                args_glCompressedTexImage3D argp_glcompressedteximage3d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCompressedTexImage3D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcompressedteximage3d, ShmPTR->buffer, sizeof(args_glCompressedTexImage3D));

                // Execute function call
                glcompressedteximage3d_lh(&argp_glcompressedteximage3d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOMPRESSEDTEXSUBIMAGE1D: ;
                args_glCompressedTexSubImage1D argp_glcompressedtexsubimage1d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCompressedTexSubImage1D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcompressedtexsubimage1d, ShmPTR->buffer, sizeof(args_glCompressedTexSubImage1D));

                // Execute function call
                glcompressedtexsubimage1d_lh(&argp_glcompressedtexsubimage1d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOMPRESSEDTEXSUBIMAGE2D: ;
                args_glCompressedTexSubImage2D argp_glcompressedtexsubimage2d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCompressedTexSubImage2D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcompressedtexsubimage2d, ShmPTR->buffer, sizeof(args_glCompressedTexSubImage2D));

                // Execute function call
                glcompressedtexsubimage2d_lh(&argp_glcompressedtexsubimage2d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCOMPRESSEDTEXSUBIMAGE3D: ;
                args_glCompressedTexSubImage3D argp_glcompressedtexsubimage3d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glCompressedTexSubImage3D)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcompressedtexsubimage3d, ShmPTR->buffer, sizeof(args_glCompressedTexSubImage3D));

                // Execute function call
                glcompressedtexsubimage3d_lh(&argp_glcompressedtexsubimage3d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETCOMPRESSEDTEXIMAGE: ;
                args_glGetCompressedTexImage argp_glgetcompressedteximage;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetCompressedTexImage)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetcompressedteximage, ShmPTR->buffer, sizeof(args_glGetCompressedTexImage));

                // Execute function call
                glgetcompressedteximage_lh(&argp_glgetcompressedteximage);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD1D: ;
                args_glMultiTexCoord1d argp_glmultitexcoord1d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord1d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord1d, ShmPTR->buffer, sizeof(args_glMultiTexCoord1d));

                // Execute function call
                glmultitexcoord1d_lh(&argp_glmultitexcoord1d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD1DV: ;
                args_glMultiTexCoord1dv argp_glmultitexcoord1dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord1dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord1dv, ShmPTR->buffer, sizeof(args_glMultiTexCoord1dv));

                // Execute function call
                glmultitexcoord1dv_lh(&argp_glmultitexcoord1dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD1F: ;
                args_glMultiTexCoord1f argp_glmultitexcoord1f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord1f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord1f, ShmPTR->buffer, sizeof(args_glMultiTexCoord1f));

                // Execute function call
                glmultitexcoord1f_lh(&argp_glmultitexcoord1f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD1FV: ;
                args_glMultiTexCoord1fv argp_glmultitexcoord1fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord1fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord1fv, ShmPTR->buffer, sizeof(args_glMultiTexCoord1fv));

                // Execute function call
                glmultitexcoord1fv_lh(&argp_glmultitexcoord1fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD1I: ;
                args_glMultiTexCoord1i argp_glmultitexcoord1i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord1i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord1i, ShmPTR->buffer, sizeof(args_glMultiTexCoord1i));

                // Execute function call
                glmultitexcoord1i_lh(&argp_glmultitexcoord1i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD1IV: ;
                args_glMultiTexCoord1iv argp_glmultitexcoord1iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord1iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord1iv, ShmPTR->buffer, sizeof(args_glMultiTexCoord1iv));

                // Execute function call
                glmultitexcoord1iv_lh(&argp_glmultitexcoord1iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD1S: ;
                args_glMultiTexCoord1s argp_glmultitexcoord1s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord1s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord1s, ShmPTR->buffer, sizeof(args_glMultiTexCoord1s));

                // Execute function call
                glmultitexcoord1s_lh(&argp_glmultitexcoord1s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD1SV: ;
                args_glMultiTexCoord1sv argp_glmultitexcoord1sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord1sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord1sv, ShmPTR->buffer, sizeof(args_glMultiTexCoord1sv));

                // Execute function call
                glmultitexcoord1sv_lh(&argp_glmultitexcoord1sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD2D: ;
                args_glMultiTexCoord2d argp_glmultitexcoord2d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord2d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord2d, ShmPTR->buffer, sizeof(args_glMultiTexCoord2d));

                // Execute function call
                glmultitexcoord2d_lh(&argp_glmultitexcoord2d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD2DV: ;
                args_glMultiTexCoord2dv argp_glmultitexcoord2dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord2dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord2dv, ShmPTR->buffer, sizeof(args_glMultiTexCoord2dv));

                // Execute function call
                glmultitexcoord2dv_lh(&argp_glmultitexcoord2dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD2F: ;
                args_glMultiTexCoord2f argp_glmultitexcoord2f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord2f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord2f, ShmPTR->buffer, sizeof(args_glMultiTexCoord2f));

                // Execute function call
                glmultitexcoord2f_lh(&argp_glmultitexcoord2f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD2FV: ;
                args_glMultiTexCoord2fv argp_glmultitexcoord2fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord2fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord2fv, ShmPTR->buffer, sizeof(args_glMultiTexCoord2fv));

                // Execute function call
                glmultitexcoord2fv_lh(&argp_glmultitexcoord2fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD2I: ;
                args_glMultiTexCoord2i argp_glmultitexcoord2i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord2i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord2i, ShmPTR->buffer, sizeof(args_glMultiTexCoord2i));

                // Execute function call
                glmultitexcoord2i_lh(&argp_glmultitexcoord2i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD2IV: ;
                args_glMultiTexCoord2iv argp_glmultitexcoord2iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord2iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord2iv, ShmPTR->buffer, sizeof(args_glMultiTexCoord2iv));

                // Execute function call
                glmultitexcoord2iv_lh(&argp_glmultitexcoord2iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD2S: ;
                args_glMultiTexCoord2s argp_glmultitexcoord2s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord2s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord2s, ShmPTR->buffer, sizeof(args_glMultiTexCoord2s));

                // Execute function call
                glmultitexcoord2s_lh(&argp_glmultitexcoord2s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD2SV: ;
                args_glMultiTexCoord2sv argp_glmultitexcoord2sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord2sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord2sv, ShmPTR->buffer, sizeof(args_glMultiTexCoord2sv));

                // Execute function call
                glmultitexcoord2sv_lh(&argp_glmultitexcoord2sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD3D: ;
                args_glMultiTexCoord3d argp_glmultitexcoord3d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord3d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord3d, ShmPTR->buffer, sizeof(args_glMultiTexCoord3d));

                // Execute function call
                glmultitexcoord3d_lh(&argp_glmultitexcoord3d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD3DV: ;
                args_glMultiTexCoord3dv argp_glmultitexcoord3dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord3dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord3dv, ShmPTR->buffer, sizeof(args_glMultiTexCoord3dv));

                // Execute function call
                glmultitexcoord3dv_lh(&argp_glmultitexcoord3dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD3F: ;
                args_glMultiTexCoord3f argp_glmultitexcoord3f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord3f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord3f, ShmPTR->buffer, sizeof(args_glMultiTexCoord3f));

                // Execute function call
                glmultitexcoord3f_lh(&argp_glmultitexcoord3f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD3FV: ;
                args_glMultiTexCoord3fv argp_glmultitexcoord3fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord3fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord3fv, ShmPTR->buffer, sizeof(args_glMultiTexCoord3fv));

                // Execute function call
                glmultitexcoord3fv_lh(&argp_glmultitexcoord3fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD3I: ;
                args_glMultiTexCoord3i argp_glmultitexcoord3i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord3i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord3i, ShmPTR->buffer, sizeof(args_glMultiTexCoord3i));

                // Execute function call
                glmultitexcoord3i_lh(&argp_glmultitexcoord3i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD3IV: ;
                args_glMultiTexCoord3iv argp_glmultitexcoord3iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord3iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord3iv, ShmPTR->buffer, sizeof(args_glMultiTexCoord3iv));

                // Execute function call
                glmultitexcoord3iv_lh(&argp_glmultitexcoord3iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD3S: ;
                args_glMultiTexCoord3s argp_glmultitexcoord3s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord3s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord3s, ShmPTR->buffer, sizeof(args_glMultiTexCoord3s));

                // Execute function call
                glmultitexcoord3s_lh(&argp_glmultitexcoord3s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD3SV: ;
                args_glMultiTexCoord3sv argp_glmultitexcoord3sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord3sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord3sv, ShmPTR->buffer, sizeof(args_glMultiTexCoord3sv));

                // Execute function call
                glmultitexcoord3sv_lh(&argp_glmultitexcoord3sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD4D: ;
                args_glMultiTexCoord4d argp_glmultitexcoord4d;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord4d)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord4d, ShmPTR->buffer, sizeof(args_glMultiTexCoord4d));

                // Execute function call
                glmultitexcoord4d_lh(&argp_glmultitexcoord4d);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD4DV: ;
                args_glMultiTexCoord4dv argp_glmultitexcoord4dv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord4dv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord4dv, ShmPTR->buffer, sizeof(args_glMultiTexCoord4dv));

                // Execute function call
                glmultitexcoord4dv_lh(&argp_glmultitexcoord4dv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD4F: ;
                args_glMultiTexCoord4f argp_glmultitexcoord4f;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord4f)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord4f, ShmPTR->buffer, sizeof(args_glMultiTexCoord4f));

                // Execute function call
                glmultitexcoord4f_lh(&argp_glmultitexcoord4f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD4FV: ;
                args_glMultiTexCoord4fv argp_glmultitexcoord4fv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord4fv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord4fv, ShmPTR->buffer, sizeof(args_glMultiTexCoord4fv));

                // Execute function call
                glmultitexcoord4fv_lh(&argp_glmultitexcoord4fv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD4I: ;
                args_glMultiTexCoord4i argp_glmultitexcoord4i;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord4i)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord4i, ShmPTR->buffer, sizeof(args_glMultiTexCoord4i));

                // Execute function call
                glmultitexcoord4i_lh(&argp_glmultitexcoord4i);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD4IV: ;
                args_glMultiTexCoord4iv argp_glmultitexcoord4iv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord4iv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord4iv, ShmPTR->buffer, sizeof(args_glMultiTexCoord4iv));

                // Execute function call
                glmultitexcoord4iv_lh(&argp_glmultitexcoord4iv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD4S: ;
                args_glMultiTexCoord4s argp_glmultitexcoord4s;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord4s)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord4s, ShmPTR->buffer, sizeof(args_glMultiTexCoord4s));

                // Execute function call
                glmultitexcoord4s_lh(&argp_glmultitexcoord4s);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD4SV: ;
                args_glMultiTexCoord4sv argp_glmultitexcoord4sv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord4sv)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord4sv, ShmPTR->buffer, sizeof(args_glMultiTexCoord4sv));

                // Execute function call
                glmultitexcoord4sv_lh(&argp_glmultitexcoord4sv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLSAMPLECOVERAGE: ;
                args_glSampleCoverage argp_glsamplecoverage;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glSampleCoverage)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glsamplecoverage, ShmPTR->buffer, sizeof(args_glSampleCoverage));

                // Execute function call
                glsamplecoverage_lh(&argp_glsamplecoverage);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLACTIVETEXTUREARB: ;
                args_glActiveTextureARB argp_glactivetexturearb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glActiveTextureARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glactivetexturearb, ShmPTR->buffer, sizeof(args_glActiveTextureARB));

                // Execute function call
                glactivetexturearb_lh(&argp_glactivetexturearb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLCLIENTACTIVETEXTUREARB: ;
                args_glClientActiveTextureARB argp_glclientactivetexturearb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glClientActiveTextureARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glclientactivetexturearb, ShmPTR->buffer, sizeof(args_glClientActiveTextureARB));

                // Execute function call
                glclientactivetexturearb_lh(&argp_glclientactivetexturearb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD1DARB: ;
                args_glMultiTexCoord1dARB argp_glmultitexcoord1darb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord1dARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord1darb, ShmPTR->buffer, sizeof(args_glMultiTexCoord1dARB));

                // Execute function call
                glmultitexcoord1darb_lh(&argp_glmultitexcoord1darb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD1DVARB: ;
                args_glMultiTexCoord1dvARB argp_glmultitexcoord1dvarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord1dvARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord1dvarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord1dvARB));

                // Execute function call
                glmultitexcoord1dvarb_lh(&argp_glmultitexcoord1dvarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD1FARB: ;
                args_glMultiTexCoord1fARB argp_glmultitexcoord1farb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord1fARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord1farb, ShmPTR->buffer, sizeof(args_glMultiTexCoord1fARB));

                // Execute function call
                glmultitexcoord1farb_lh(&argp_glmultitexcoord1farb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD1FVARB: ;
                args_glMultiTexCoord1fvARB argp_glmultitexcoord1fvarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord1fvARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord1fvarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord1fvARB));

                // Execute function call
                glmultitexcoord1fvarb_lh(&argp_glmultitexcoord1fvarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD1IARB: ;
                args_glMultiTexCoord1iARB argp_glmultitexcoord1iarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord1iARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord1iarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord1iARB));

                // Execute function call
                glmultitexcoord1iarb_lh(&argp_glmultitexcoord1iarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD1IVARB: ;
                args_glMultiTexCoord1ivARB argp_glmultitexcoord1ivarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord1ivARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord1ivarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord1ivARB));

                // Execute function call
                glmultitexcoord1ivarb_lh(&argp_glmultitexcoord1ivarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD1SARB: ;
                args_glMultiTexCoord1sARB argp_glmultitexcoord1sarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord1sARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord1sarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord1sARB));

                // Execute function call
                glmultitexcoord1sarb_lh(&argp_glmultitexcoord1sarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD1SVARB: ;
                args_glMultiTexCoord1svARB argp_glmultitexcoord1svarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord1svARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord1svarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord1svARB));

                // Execute function call
                glmultitexcoord1svarb_lh(&argp_glmultitexcoord1svarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD2DARB: ;
                args_glMultiTexCoord2dARB argp_glmultitexcoord2darb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord2dARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord2darb, ShmPTR->buffer, sizeof(args_glMultiTexCoord2dARB));

                // Execute function call
                glmultitexcoord2darb_lh(&argp_glmultitexcoord2darb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD2DVARB: ;
                args_glMultiTexCoord2dvARB argp_glmultitexcoord2dvarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord2dvARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord2dvarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord2dvARB));

                // Execute function call
                glmultitexcoord2dvarb_lh(&argp_glmultitexcoord2dvarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD2FARB: ;
                args_glMultiTexCoord2fARB argp_glmultitexcoord2farb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord2fARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord2farb, ShmPTR->buffer, sizeof(args_glMultiTexCoord2fARB));

                // Execute function call
                glmultitexcoord2farb_lh(&argp_glmultitexcoord2farb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD2FVARB: ;
                args_glMultiTexCoord2fvARB argp_glmultitexcoord2fvarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord2fvARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord2fvarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord2fvARB));

                // Execute function call
                glmultitexcoord2fvarb_lh(&argp_glmultitexcoord2fvarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD2IARB: ;
                args_glMultiTexCoord2iARB argp_glmultitexcoord2iarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord2iARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord2iarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord2iARB));

                // Execute function call
                glmultitexcoord2iarb_lh(&argp_glmultitexcoord2iarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD2IVARB: ;
                args_glMultiTexCoord2ivARB argp_glmultitexcoord2ivarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord2ivARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord2ivarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord2ivARB));

                // Execute function call
                glmultitexcoord2ivarb_lh(&argp_glmultitexcoord2ivarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD2SARB: ;
                args_glMultiTexCoord2sARB argp_glmultitexcoord2sarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord2sARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord2sarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord2sARB));

                // Execute function call
                glmultitexcoord2sarb_lh(&argp_glmultitexcoord2sarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD2SVARB: ;
                args_glMultiTexCoord2svARB argp_glmultitexcoord2svarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord2svARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord2svarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord2svARB));

                // Execute function call
                glmultitexcoord2svarb_lh(&argp_glmultitexcoord2svarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD3DARB: ;
                args_glMultiTexCoord3dARB argp_glmultitexcoord3darb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord3dARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord3darb, ShmPTR->buffer, sizeof(args_glMultiTexCoord3dARB));

                // Execute function call
                glmultitexcoord3darb_lh(&argp_glmultitexcoord3darb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD3DVARB: ;
                args_glMultiTexCoord3dvARB argp_glmultitexcoord3dvarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord3dvARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord3dvarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord3dvARB));

                // Execute function call
                glmultitexcoord3dvarb_lh(&argp_glmultitexcoord3dvarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD3FARB: ;
                args_glMultiTexCoord3fARB argp_glmultitexcoord3farb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord3fARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord3farb, ShmPTR->buffer, sizeof(args_glMultiTexCoord3fARB));

                // Execute function call
                glmultitexcoord3farb_lh(&argp_glmultitexcoord3farb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD3FVARB: ;
                args_glMultiTexCoord3fvARB argp_glmultitexcoord3fvarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord3fvARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord3fvarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord3fvARB));

                // Execute function call
                glmultitexcoord3fvarb_lh(&argp_glmultitexcoord3fvarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD3IARB: ;
                args_glMultiTexCoord3iARB argp_glmultitexcoord3iarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord3iARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord3iarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord3iARB));

                // Execute function call
                glmultitexcoord3iarb_lh(&argp_glmultitexcoord3iarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD3IVARB: ;
                args_glMultiTexCoord3ivARB argp_glmultitexcoord3ivarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord3ivARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord3ivarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord3ivARB));

                // Execute function call
                glmultitexcoord3ivarb_lh(&argp_glmultitexcoord3ivarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD3SARB: ;
                args_glMultiTexCoord3sARB argp_glmultitexcoord3sarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord3sARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord3sarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord3sARB));

                // Execute function call
                glmultitexcoord3sarb_lh(&argp_glmultitexcoord3sarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD3SVARB: ;
                args_glMultiTexCoord3svARB argp_glmultitexcoord3svarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord3svARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord3svarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord3svARB));

                // Execute function call
                glmultitexcoord3svarb_lh(&argp_glmultitexcoord3svarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD4DARB: ;
                args_glMultiTexCoord4dARB argp_glmultitexcoord4darb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord4dARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord4darb, ShmPTR->buffer, sizeof(args_glMultiTexCoord4dARB));

                // Execute function call
                glmultitexcoord4darb_lh(&argp_glmultitexcoord4darb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD4DVARB: ;
                args_glMultiTexCoord4dvARB argp_glmultitexcoord4dvarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord4dvARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord4dvarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord4dvARB));

                // Execute function call
                glmultitexcoord4dvarb_lh(&argp_glmultitexcoord4dvarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD4FARB: ;
                args_glMultiTexCoord4fARB argp_glmultitexcoord4farb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord4fARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord4farb, ShmPTR->buffer, sizeof(args_glMultiTexCoord4fARB));

                // Execute function call
                glmultitexcoord4farb_lh(&argp_glmultitexcoord4farb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD4FVARB: ;
                args_glMultiTexCoord4fvARB argp_glmultitexcoord4fvarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord4fvARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord4fvarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord4fvARB));

                // Execute function call
                glmultitexcoord4fvarb_lh(&argp_glmultitexcoord4fvarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD4IARB: ;
                args_glMultiTexCoord4iARB argp_glmultitexcoord4iarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord4iARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord4iarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord4iARB));

                // Execute function call
                glmultitexcoord4iarb_lh(&argp_glmultitexcoord4iarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD4IVARB: ;
                args_glMultiTexCoord4ivARB argp_glmultitexcoord4ivarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord4ivARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord4ivarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord4ivARB));

                // Execute function call
                glmultitexcoord4ivarb_lh(&argp_glmultitexcoord4ivarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD4SARB: ;
                args_glMultiTexCoord4sARB argp_glmultitexcoord4sarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord4sARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord4sarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord4sARB));

                // Execute function call
                glmultitexcoord4sarb_lh(&argp_glmultitexcoord4sarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLMULTITEXCOORD4SVARB: ;
                args_glMultiTexCoord4svARB argp_glmultitexcoord4svarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glMultiTexCoord4svARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmultitexcoord4svarb, ShmPTR->buffer, sizeof(args_glMultiTexCoord4svARB));

                // Execute function call
                glmultitexcoord4svarb_lh(&argp_glmultitexcoord4svarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLBLENDEQUATIONSEPARATEATI: ;
                args_glBlendEquationSeparateATI argp_glblendequationseparateati;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glBlendEquationSeparateATI)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glblendequationseparateati, ShmPTR->buffer, sizeof(args_glBlendEquationSeparateATI));

                // Execute function call
                glblendequationseparateati_lh(&argp_glblendequationseparateati);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXDESTROYCONTEXT: ;
                args_glXDestroyContext argp_glxdestroycontext;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXDestroyContext)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxdestroycontext, ShmPTR->buffer, sizeof(args_glXDestroyContext));

                // Execute function call
                glxdestroycontext_lh(&argp_glxdestroycontext);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXSWAPBUFFERS: ;
                args_glXSwapBuffers argp_glxswapbuffers;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXSwapBuffers)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxswapbuffers, ShmPTR->buffer, sizeof(args_glXSwapBuffers));

                // Execute function call
                glxswapbuffers_lh(&argp_glxswapbuffers);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXDESTROYGLXPIXMAP: ;
                args_glXDestroyGLXPixmap argp_glxdestroyglxpixmap;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXDestroyGLXPixmap)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxdestroyglxpixmap, ShmPTR->buffer, sizeof(args_glXDestroyGLXPixmap));

                // Execute function call
                glxdestroyglxpixmap_lh(&argp_glxdestroyglxpixmap);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXQUERYEXTENSION: ;
                args_glXQueryExtension argp_glxqueryextension;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXQueryExtension)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxqueryextension, ShmPTR->buffer, sizeof(args_glXQueryExtension));

                // Execute function call
                glxqueryextension_lh(&argp_glxqueryextension);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXQUERYVERSION: ;
                args_glXQueryVersion argp_glxqueryversion;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXQueryVersion)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxqueryversion, ShmPTR->buffer, sizeof(args_glXQueryVersion));

                // Execute function call
                glxqueryversion_lh(&argp_glxqueryversion);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXISDIRECT: ;
                args_glXIsDirect argp_glxisdirect;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXIsDirect)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxisdirect, ShmPTR->buffer, sizeof(args_glXIsDirect));

                // Execute function call
                glxisdirect_lh(&argp_glxisdirect);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXGETCURRENTCONTEXT: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glxgetcurrentcontext_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXGETCURRENTDRAWABLE: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glxgetcurrentdrawable_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXWAITGL: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glxwaitgl_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXWAITX: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glxwaitx_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXUSEXFONT: ;
                args_glXUseXFont argp_glxusexfont;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXUseXFont)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxusexfont, ShmPTR->buffer, sizeof(args_glXUseXFont));

                // Execute function call
                glxusexfont_lh(&argp_glxusexfont);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXQUERYEXTENSIONSSTRING: ;
                args_glXQueryExtensionsString argp_glxqueryextensionsstring;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXQueryExtensionsString)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxqueryextensionsstring, ShmPTR->buffer, sizeof(args_glXQueryExtensionsString));

                // Execute function call
                glxqueryextensionsstring_lh(&argp_glxqueryextensionsstring);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXQUERYSERVERSTRING: ;
                args_glXQueryServerString argp_glxqueryserverstring;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXQueryServerString)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxqueryserverstring, ShmPTR->buffer, sizeof(args_glXQueryServerString));

                // Execute function call
                glxqueryserverstring_lh(&argp_glxqueryserverstring);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXGETCLIENTSTRING: ;
                args_glXGetClientString argp_glxgetclientstring;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXGetClientString)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxgetclientstring, ShmPTR->buffer, sizeof(args_glXGetClientString));

                // Execute function call
                glxgetclientstring_lh(&argp_glxgetclientstring);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXGETCURRENTDISPLAY: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glxgetcurrentdisplay_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXDESTROYWINDOW: ;
                args_glXDestroyWindow argp_glxdestroywindow;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXDestroyWindow)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxdestroywindow, ShmPTR->buffer, sizeof(args_glXDestroyWindow));

                // Execute function call
                glxdestroywindow_lh(&argp_glxdestroywindow);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXDESTROYPIXMAP: ;
                args_glXDestroyPixmap argp_glxdestroypixmap;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXDestroyPixmap)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxdestroypixmap, ShmPTR->buffer, sizeof(args_glXDestroyPixmap));

                // Execute function call
                glxdestroypixmap_lh(&argp_glxdestroypixmap);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXDESTROYPBUFFER: ;
                args_glXDestroyPbuffer argp_glxdestroypbuffer;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXDestroyPbuffer)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxdestroypbuffer, ShmPTR->buffer, sizeof(args_glXDestroyPbuffer));

                // Execute function call
                glxdestroypbuffer_lh(&argp_glxdestroypbuffer);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXGETCURRENTREADDRAWABLE: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glxgetcurrentreaddrawable_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXGETPROCADDRESSARB: ;
                args_glXGetProcAddressARB argp_glxgetprocaddressarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXGetProcAddressARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxgetprocaddressarb, ShmPTR->buffer, sizeof(args_glXGetProcAddressARB));

                // Execute function call
                glxgetprocaddressarb_lh(&argp_glxgetprocaddressarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXGETPROCADDRESS: ;
                args_glXGetProcAddress argp_glxgetprocaddress;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXGetProcAddress)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxgetprocaddress, ShmPTR->buffer, sizeof(args_glXGetProcAddress));

                // Execute function call
                glxgetprocaddress_lh(&argp_glxgetprocaddress);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXALLOCATEMEMORYNV: ;
                args_glXAllocateMemoryNV argp_glxallocatememorynv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXAllocateMemoryNV)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxallocatememorynv, ShmPTR->buffer, sizeof(args_glXAllocateMemoryNV));

                // Execute function call
                glxallocatememorynv_lh(&argp_glxallocatememorynv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXFREEMEMORYNV: ;
                args_glXFreeMemoryNV argp_glxfreememorynv;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXFreeMemoryNV)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxfreememorynv, ShmPTR->buffer, sizeof(args_glXFreeMemoryNV));

                // Execute function call
                glxfreememorynv_lh(&argp_glxfreememorynv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXBINDTEXIMAGEARB: ;
                args_glXBindTexImageARB argp_glxbindteximagearb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXBindTexImageARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxbindteximagearb, ShmPTR->buffer, sizeof(args_glXBindTexImageARB));

                // Execute function call
                glxbindteximagearb_lh(&argp_glxbindteximagearb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXRELEASETEXIMAGEARB: ;
                args_glXReleaseTexImageARB argp_glxreleaseteximagearb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXReleaseTexImageARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxreleaseteximagearb, ShmPTR->buffer, sizeof(args_glXReleaseTexImageARB));

                // Execute function call
                glxreleaseteximagearb_lh(&argp_glxreleaseteximagearb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXDRAWABLEATTRIBARB: ;
                args_glXDrawableAttribARB argp_glxdrawableattribarb;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXDrawableAttribARB)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxdrawableattribarb, ShmPTR->buffer, sizeof(args_glXDrawableAttribARB));

                // Execute function call
                glxdrawableattribarb_lh(&argp_glxdrawableattribarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXGETFRAMEUSAGEMESA: ;
                args_glXGetFrameUsageMESA argp_glxgetframeusagemesa;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXGetFrameUsageMESA)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxgetframeusagemesa, ShmPTR->buffer, sizeof(args_glXGetFrameUsageMESA));

                // Execute function call
                glxgetframeusagemesa_lh(&argp_glxgetframeusagemesa);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXBEGINFRAMETRACKINGMESA: ;
                args_glXBeginFrameTrackingMESA argp_glxbeginframetrackingmesa;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXBeginFrameTrackingMESA)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxbeginframetrackingmesa, ShmPTR->buffer, sizeof(args_glXBeginFrameTrackingMESA));

                // Execute function call
                glxbeginframetrackingmesa_lh(&argp_glxbeginframetrackingmesa);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXENDFRAMETRACKINGMESA: ;
                args_glXEndFrameTrackingMESA argp_glxendframetrackingmesa;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXEndFrameTrackingMESA)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxendframetrackingmesa, ShmPTR->buffer, sizeof(args_glXEndFrameTrackingMESA));

                // Execute function call
                glxendframetrackingmesa_lh(&argp_glxendframetrackingmesa);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXQUERYFRAMETRACKINGMESA: ;
                args_glXQueryFrameTrackingMESA argp_glxqueryframetrackingmesa;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXQueryFrameTrackingMESA)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxqueryframetrackingmesa, ShmPTR->buffer, sizeof(args_glXQueryFrameTrackingMESA));

                // Execute function call
                glxqueryframetrackingmesa_lh(&argp_glxqueryframetrackingmesa);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXSWAPINTERVALMESA: ;
                args_glXSwapIntervalMESA argp_glxswapintervalmesa;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXSwapIntervalMESA)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxswapintervalmesa, ShmPTR->buffer, sizeof(args_glXSwapIntervalMESA));

                // Execute function call
                glxswapintervalmesa_lh(&argp_glxswapintervalmesa);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXGETSWAPINTERVALMESA: ;
                // assert payload size
                if(ShmPTR->payload_size != 0){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glxgetswapintervalmesa_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;


            default:
                // Change this print error so we know what happens
                printf("Message data type unrecognized\n\n");
                ShmPTR->status = LISTEN;
                break;
        }
    }
}

int main(int  argc, char *argv[]){
    init();
    service_listener();
    return 0;
}
