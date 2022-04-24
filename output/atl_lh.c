
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
    _Xconst char *display_name = argp->display_name;

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


// -- XCreateSimpleWindow
Window *xcreatesimplewindow_lh(args_XCreateSimpleWindow *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 Window parent = argp->parent;;
	 int x = argp->x;;
	 int y = argp->y;;
	 unsigned int width = argp->width;;
	 unsigned int height = argp->height;;
	 unsigned int border_width = argp->border_width;;
	 unsigned long border = argp->border;;
	 unsigned long background = argp->background;

    // Call actual function
    Window result = XCreateSimpleWindow(display, parent, x, y, width, height, border_width, border, background);

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


// -- XMapWindow
int *xmapwindow_lh(args_XMapWindow *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 Window w = argp->w;

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


// -- XSelectInput
int *xselectinput_lh(args_XSelectInput *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 Window w = argp->w;;
	 long event_mask = argp->event_mask;

    // Call actual function
    int result = XSelectInput(display, w, event_mask);

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


// -- XNextEvent
int *xnextevent_lh(args_XNextEvent *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 XEvent *event_return = argp->event_return;

    // Call actual function
    int result = XNextEvent(display, event_return);

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


// -- XDefaultRootWindow
Window *xdefaultrootwindow_lh(args_XDefaultRootWindow *argp)
{
    // Get function specific args
    Display *display = argp->display;

    // Call actual function
    Window result = XDefaultRootWindow(display);

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


// -- glClearIndex
void *glclearindex_lh(args_glClearIndex *argp)
{
    // Get function specific args
     GLfloat c  = argp->c;

    // Call actual function
    void result = glClearIndex(c);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

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
	 GLclampf alpha  = argp->alpha;

    // Call actual function
    void result = glClearColor(red, green, blue, alpha);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glClear
void *glclear_lh(args_glClear *argp)
{
    // Get function specific args
     GLbitfield mask  = argp->mask;

    // Call actual function
    void result = glClear(mask);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIndexMask
void *glindexmask_lh(args_glIndexMask *argp)
{
    // Get function specific args
     GLuint mask  = argp->mask;

    // Call actual function
    void result = glIndexMask(mask);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

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
	 GLboolean alpha  = argp->alpha;

    // Call actual function
    void result = glColorMask(red, green, blue, alpha);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glAlphaFunc
void *glalphafunc_lh(args_glAlphaFunc *argp)
{
    // Get function specific args
     GLenum func = argp->func;;
	 GLclampf ref  = argp->ref;

    // Call actual function
    void result = glAlphaFunc(func, ref);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glBlendFunc
void *glblendfunc_lh(args_glBlendFunc *argp)
{
    // Get function specific args
     GLenum sfactor = argp->sfactor;;
	 GLenum dfactor  = argp->dfactor;

    // Call actual function
    void result = glBlendFunc(sfactor, dfactor);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLogicOp
void *gllogicop_lh(args_glLogicOp *argp)
{
    // Get function specific args
     GLenum opcode  = argp->opcode;

    // Call actual function
    void result = glLogicOp(opcode);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glCullFace
void *glcullface_lh(args_glCullFace *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;

    // Call actual function
    void result = glCullFace(mode);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glFrontFace
void *glfrontface_lh(args_glFrontFace *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;

    // Call actual function
    void result = glFrontFace(mode);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPointSize
void *glpointsize_lh(args_glPointSize *argp)
{
    // Get function specific args
     GLfloat size  = argp->size;

    // Call actual function
    void result = glPointSize(size);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLineWidth
void *gllinewidth_lh(args_glLineWidth *argp)
{
    // Get function specific args
     GLfloat width  = argp->width;

    // Call actual function
    void result = glLineWidth(width);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glLineStipple
void *gllinestipple_lh(args_glLineStipple *argp)
{
    // Get function specific args
     GLint factor = argp->factor;;
	 GLushort pattern  = argp->pattern;

    // Call actual function
    void result = glLineStipple(factor, pattern);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPolygonMode
void *glpolygonmode_lh(args_glPolygonMode *argp)
{
    // Get function specific args
     GLenum face = argp->face;;
	 GLenum mode  = argp->mode;

    // Call actual function
    void result = glPolygonMode(face, mode);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPolygonOffset
void *glpolygonoffset_lh(args_glPolygonOffset *argp)
{
    // Get function specific args
     GLfloat factor = argp->factor;;
	 GLfloat units  = argp->units;

    // Call actual function
    void result = glPolygonOffset(factor, units);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPolygonStipple
void *glpolygonstipple_lh(args_glPolygonStipple *argp)
{
    // Get function specific args
     const GLubyte *mask  = argp->mask;

    // Call actual function
    void result = glPolygonStipple(mask);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetPolygonStipple
void *glgetpolygonstipple_lh(args_glGetPolygonStipple *argp)
{
    // Get function specific args
     GLubyte *mask  = argp->mask;

    // Call actual function
    void result = glGetPolygonStipple(mask);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEdgeFlag
void *gledgeflag_lh(args_glEdgeFlag *argp)
{
    // Get function specific args
     GLboolean flag  = argp->flag;

    // Call actual function
    void result = glEdgeFlag(flag);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEdgeFlagv
void *gledgeflagv_lh(args_glEdgeFlagv *argp)
{
    // Get function specific args
     const GLboolean *flag  = argp->flag;

    // Call actual function
    void result = glEdgeFlagv(flag);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

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
	 GLsizei height = argp->height;

    // Call actual function
    void result = glScissor(x, y, width, height);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glClipPlane
void *glclipplane_lh(args_glClipPlane *argp)
{
    // Get function specific args
     GLenum plane = argp->plane;;
	 const GLdouble *equation  = argp->equation;

    // Call actual function
    void result = glClipPlane(plane, equation);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetClipPlane
void *glgetclipplane_lh(args_glGetClipPlane *argp)
{
    // Get function specific args
     GLenum plane = argp->plane;;
	 GLdouble *equation  = argp->equation;

    // Call actual function
    void result = glGetClipPlane(plane, equation);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glDrawBuffer
void *gldrawbuffer_lh(args_glDrawBuffer *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;

    // Call actual function
    void result = glDrawBuffer(mode);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glReadBuffer
void *glreadbuffer_lh(args_glReadBuffer *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;

    // Call actual function
    void result = glReadBuffer(mode);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glEnable
void *glenable_lh(args_glEnable *argp)
{
    // Get function specific args
     GLenum cap  = argp->cap;

    // Call actual function
    void result = glEnable(cap);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glDisable
void *gldisable_lh(args_glDisable *argp)
{
    // Get function specific args
     GLenum cap  = argp->cap;

    // Call actual function
    void result = glDisable(cap);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glIsEnabled
GLboolean *glisenabled_lh(args_glIsEnabled *argp)
{
    // Get function specific args
     GLenum cap  = argp->cap;

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
     GLenum cap  = argp->cap;

    // Call actual function
    void result = glEnableClientState(cap);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glDisableClientState
void *gldisableclientstate_lh(args_glDisableClientState *argp)
{
    // Get function specific args
     GLenum cap  = argp->cap;

    // Call actual function
    void result = glDisableClientState(cap);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetBooleanv
void *glgetbooleanv_lh(args_glGetBooleanv *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLboolean *params  = argp->params;

    // Call actual function
    void result = glGetBooleanv(pname, params);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetDoublev
void *glgetdoublev_lh(args_glGetDoublev *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLdouble *params  = argp->params;

    // Call actual function
    void result = glGetDoublev(pname, params);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetFloatv
void *glgetfloatv_lh(args_glGetFloatv *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLfloat *params  = argp->params;

    // Call actual function
    void result = glGetFloatv(pname, params);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glGetIntegerv
void *glgetintegerv_lh(args_glGetIntegerv *argp)
{
    // Get function specific args
     GLenum pname = argp->pname;;
	 GLint *params  = argp->params;

    // Call actual function
    void result = glGetIntegerv(pname, params);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glPushAttrib
void *glpushattrib_lh(args_glPushAttrib *argp)
{
    // Get function specific args
     GLbitfield mask  = argp->mask;

    // Call actual function
    void result = glPushAttrib(mask);

    // Memcopy in Buffer
    int ret_size = sizeof(void);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}

