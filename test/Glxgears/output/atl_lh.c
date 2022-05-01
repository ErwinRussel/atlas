
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

// -- XDefaultScreen
int *xdefaultscreen_lh(args_XDefaultScreen *argp)
{
    // Get function specific args
    Display* display = argp->display;;

    // Call actual function
    int result = XDefaultScreen(display);

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


// -- XDisplayWidth
int *xdisplaywidth_lh(args_XDisplayWidth *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 int screen_number = argp->screen_number;;

    // Call actual function
    int result = XDisplayWidth(display, screen_number);

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


// -- XDisplayHeight
int *xdisplayheight_lh(args_XDisplayHeight *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 int screen_number = argp->screen_number;;

    // Call actual function
    int result = XDisplayHeight(display, screen_number);

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


// -- XRootWindow
Window *xrootwindow_lh(args_XRootWindow *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 int screen_number = argp->screen_number;;

    // Call actual function
    Window result = XRootWindow(display, screen_number);

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
	 XSetWindowAttributes* attributes = &argp->attributes;;

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


// -- XInternAtom
Atom *xinternatom_lh(args_XInternAtom *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 _Xconst char *atom_name = argp->atom_name;;
	 Bool only_if_exists = argp->only_if_exists;;

    // Call actual function
    Atom result = XInternAtom(display, atom_name, only_if_exists);

    // Memcopy in Buffer
    int ret_size = sizeof(Atom);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = ATOM;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- XChangeProperty
int *xchangeproperty_lh(args_XChangeProperty *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 Window w = argp->w;;
	 Atom property = argp->property;;
	 Atom type = argp->type;;
	 int format = argp->format;;
	 int mode = argp->mode;;
	 _Xconst unsigned char *data = argp->data;;
	 int nelements = argp->nelements;;

    // Call actual function
    int result = XChangeProperty(display, w, property, type, format, mode, data, nelements);

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
int *xsetnormalhints_lh(args_XSetNormalHints *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 Window w = argp->w;;
	 XSizeHints hints = argp->hints;;

    // Call actual function
    int result = XSetNormalHints(display, w, &hints);

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


// -- XSetStandardProperties
int *xsetstandardproperties_lh(args_XSetStandardProperties *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 Window w = argp->w;;
	 _Xconst char window_name = argp->window_name;;
	 _Xconst char icon_name = argp->icon_name;;
	 Pixmap icon_pixmap = argp->icon_pixmap;;
	 char** argv = argp->argv;;
	 int argc = argp->argc;;
	 XSizeHints hints = argp->hints;;
    // Call actual function
    int result = XSetStandardProperties(display, w, &window_name, &icon_name, icon_pixmap, (char **)NULL, argc, &hints);

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


// -- XFree
int *xfree_lh(args_XFree *argp)
{
//    // Get function specific args
//    void* data = argp->data;;
//
//    // Call actual function
//    int result = XFree(data);
//
//    // Memcopy in Buffer
//    int ret_size = sizeof(int);
//    memcpy(ShmPTR->buffer, &result, ret_size);
//
//    // Set function specific headers
//    ShmPTR->message_type = FUNC_RETURN;
//    ShmPTR->data_type = INT;
//    ShmPTR->payload_size = ret_size;
//
//    // Set status
//    ShmPTR->status = RESPONSE;
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


// -- XPending
int *xpending_lh(args_XPending *argp)
{
    // Get function specific args
    Display *display = argp->display;;

    // Call actual function
    int result = XPending(display);

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
XEvent *xnextevent_lh(args_XNextEvent *argp)
{
    // Get function specific args
    Display *display = argp->display;;
    XEvent *event_return;

    // Call actual function
    XNextEvent(display, event_return);

    // Memcopy in Buffer
    int ret_size = sizeof(XEvent);
    memcpy(ShmPTR->buffer, event_return, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = XEVENT;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- XLookupKeysym
KeySym *xlookupkeysym_lh(args_XLookupKeysym *argp)
{
    // Get function specific args
    XKeyEvent *key_event = argp->key_event;;
	 int index = argp->index;;

    // Call actual function
    KeySym result = XLookupKeysym(key_event, index);

    // Memcopy in Buffer
    int ret_size = sizeof(KeySym);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = KEYSYM;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- XLookupString
int *xlookupstring_lh(args_XLookupString *argp)
{
    // Get function specific args
    XKeyEvent *event_struct = argp->event_struct;;
	 char *buffer_return = argp->buffer_return;;
	 int bytes_buffer = argp->bytes_buffer;;
	 KeySym *keysym_return = argp->keysym_return;;
	 XComposeStatus *status_in_out = argp->status_in_out;;

    // Call actual function
    int result = XLookupString(event_struct, buffer_return, bytes_buffer, keysym_return, status_in_out);

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


// -- XDestroyWindow
int *xdestroywindow_lh(args_XDestroyWindow *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 Window w = argp->w;;

    // Call actual function
    int result = XDestroyWindow(display, w);

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


// -- glGetString
GLubyte* *glgetstring_lh(args_glGetString *argp)
{
    // Get function specific args
    	GLenum name = argp->name;;

    // Call actual function
    const GLubyte* result = glGetString(name);

    // Memcopy in Buffer
    int ret_size = sizeof(GLubyte*);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = GLUBYTEP;
    ShmPTR->payload_size = ret_size;

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


// -- glXChooseVisual
XVisualInfo* *glxchoosevisual_lh(args_glXChooseVisual *argp)
{
    // Get function specific args
    Display *dpy = argp->dpy;;
	 int screen = argp->screen;;
	 int *attribList = argp->attribList;;

    // Call actual function
    XVisualInfo result = *glXChooseVisual(dpy, screen, attribList);

    // Memcopy in Buffer
    int ret_size = sizeof(XVisualInfo);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = XVISUALINFO;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXCreateContext
GLXContext *glxcreatecontext_lh(args_glXCreateContext *argp)
{
    // Get function specific args
    Display *dpy = argp->dpy;;
	 XVisualInfo vis = argp->vis;;
	 GLXContext shareList = argp->shareList;;
	 Bool direct = argp->direct;;

    // Call actual function
    GLXContext result = glXCreateContext(dpy, &vis, shareList, direct);

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


// -- glXMakeCurrent
Bool *glxmakecurrent_lh(args_glXMakeCurrent *argp)
{
    // Get function specific args
    Display * dpy = argp->dpy;;
	 GLXDrawable drawable = argp->drawable;;
	 GLXContext ctx = argp->ctx;;

    // Call actual function
    Bool result = glXMakeCurrent(dpy, drawable, ctx);

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


// -- glXQueryExtensionsString
char* *glxqueryextensionsstring_lh(args_glXQueryExtensionsString *argp)
{
    // Get function specific args
     Display *dpy = argp->dpy;;
	 int screen  = argp->screen;;

    // Call actual function - strcpy because string return
    char dest[1024];
    const char* result = glXQueryExtensionsString(dpy, screen);
    strcpy(dest, result);

    // Memcopy in Buffer
    int ret_size = sizeof(char[1024]);
    memcpy(ShmPTR->buffer, &dest, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = CHARARR;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXQueryDrawable
void *glxquerydrawable_lh(args_glXQueryDrawable *argp)
{
    // Get function specific args
    Display *dpy = argp->dpy;;
	 GLXDrawable draw = argp->draw;;
	 int attribute = argp->attribute;;
	 unsigned int value = argp->value;;

    // Call actual function
    glXQueryDrawable(dpy, draw, attribute, &value);

    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

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
            
            case XDEFAULTSCREEN: ;
                args_XDefaultScreen argp_xdefaultscreen;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XDefaultScreen)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xdefaultscreen, ShmPTR->buffer, sizeof(args_XDefaultScreen));

                // Execute function call
                xdefaultscreen_lh(&argp_xdefaultscreen);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case XDISPLAYWIDTH: ;
                args_XDisplayWidth argp_xdisplaywidth;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XDisplayWidth)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xdisplaywidth, ShmPTR->buffer, sizeof(args_XDisplayWidth));

                // Execute function call
                xdisplaywidth_lh(&argp_xdisplaywidth);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case XDISPLAYHEIGHT: ;
                args_XDisplayHeight argp_xdisplayheight;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XDisplayHeight)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xdisplayheight, ShmPTR->buffer, sizeof(args_XDisplayHeight));

                // Execute function call
                xdisplayheight_lh(&argp_xdisplayheight);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case XROOTWINDOW: ;
                args_XRootWindow argp_xrootwindow;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XRootWindow)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xrootwindow, ShmPTR->buffer, sizeof(args_XRootWindow));

                // Execute function call
                xrootwindow_lh(&argp_xrootwindow);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

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

            case XINTERNATOM: ;
                args_XInternAtom argp_xinternatom;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XInternAtom)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xinternatom, ShmPTR->buffer, sizeof(args_XInternAtom));

                // Execute function call
                xinternatom_lh(&argp_xinternatom);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case XCHANGEPROPERTY: ;
                args_XChangeProperty argp_xchangeproperty;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XChangeProperty)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xchangeproperty, ShmPTR->buffer, sizeof(args_XChangeProperty));

                // Execute function call
                xchangeproperty_lh(&argp_xchangeproperty);

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

            case XPENDING: ;
                args_XPending argp_xpending;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XPending)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xpending, ShmPTR->buffer, sizeof(args_XPending));

                // Execute function call
                xpending_lh(&argp_xpending);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case XNEXTEVENT: ;
                args_XNextEvent argp_xnextevent;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XNextEvent)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xnextevent, ShmPTR->buffer, sizeof(args_XNextEvent));

                // Execute function call
                xnextevent_lh(&argp_xnextevent);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case XLOOKUPKEYSYM: ;
                args_XLookupKeysym argp_xlookupkeysym;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XLookupKeysym)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xlookupkeysym, ShmPTR->buffer, sizeof(args_XLookupKeysym));

                // Execute function call
                xlookupkeysym_lh(&argp_xlookupkeysym);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case XLOOKUPSTRING: ;
                args_XLookupString argp_xlookupstring;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XLookupString)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xlookupstring, ShmPTR->buffer, sizeof(args_XLookupString));

                // Execute function call
                xlookupstring_lh(&argp_xlookupstring);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case XDESTROYWINDOW: ;
                args_XDestroyWindow argp_xdestroywindow;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XDestroyWindow)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xdestroywindow, ShmPTR->buffer, sizeof(args_XDestroyWindow));

                // Execute function call
                xdestroywindow_lh(&argp_xdestroywindow);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLGETSTRING: ;
                args_glGetString argp_glgetstring;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glGetString)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetstring, ShmPTR->buffer, sizeof(args_glGetString));

                // Execute function call
                glgetstring_lh(&argp_glgetstring);

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

            case GLXCHOOSEVISUAL: ;
                args_glXChooseVisual argp_glxchoosevisual;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXChooseVisual)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxchoosevisual, ShmPTR->buffer, sizeof(args_glXChooseVisual));

                // Execute function call
                glxchoosevisual_lh(&argp_glxchoosevisual);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXCREATECONTEXT: ;
                args_glXCreateContext argp_glxcreatecontext;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXCreateContext)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxcreatecontext, ShmPTR->buffer, sizeof(args_glXCreateContext));

                // Execute function call
                glxcreatecontext_lh(&argp_glxcreatecontext);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXMAKECURRENT: ;
                args_glXMakeCurrent argp_glxmakecurrent;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXMakeCurrent)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxmakecurrent, ShmPTR->buffer, sizeof(args_glXMakeCurrent));

                // Execute function call
                glxmakecurrent_lh(&argp_glxmakecurrent);

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

            case GLXQUERYDRAWABLE: ;
                args_glXQueryDrawable argp_glxquerydrawable;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXQueryDrawable)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxquerydrawable, ShmPTR->buffer, sizeof(args_glXQueryDrawable));

                // Execute function call
                glxquerydrawable_lh(&argp_glxquerydrawable);

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
