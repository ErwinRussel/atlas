#include  "atl_header.h"
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <unistd.h>
#include  "replay.h"

// Global pointers to use from init
key_t           ShmKEY;
int             ShmID;
struct MsgBlock *ShmPTR;
FILE *file;
int swapbufferpos;

// Set replay
int replay = 0; // todo: make this boolean
int restored = 0;
char* filename;

// Constructor
void initmem(){
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

    ShmPTR->status = LISTEN;
}

void initlog(){
    // Open file for logging
    if(restored){
        file = fopen(filename, "r+b");
        fseek(file, 0, SEEK_END);
        if(file == NULL){
            printf("Could not open file: %s", filename);
            exit(1);
        }
    } else {
        file = fopen("calllog.bin", "wb");
    }

    if(file == NULL) printf("Could not open file for logging\n");
}

// Logging
int logblock(){
    struct StrgBlock strgblock;
    strgblock.message_type = ShmPTR->message_type;
    strgblock.data_type = ShmPTR->data_type;
    if(strgblock.data_type == GLXSWAPBUFFERS){
        if(swapbufferpos == NULL){
            swapbufferpos = ftell(file);
        } else {
            fseek(file, swapbufferpos, SEEK_SET);
        }
    }

    strgblock.payload_size = ShmPTR->payload_size;
    // memcpy because of array
    memcpy(&strgblock.buffer, ShmPTR->buffer, strgblock.payload_size);
    if(fwrite(&strgblock, sizeof(struct StrgBlock), 1, file) != 1){
        printf("Logging function failed, closing log\n");
        fclose(file);
        return 1;
    }

    return 0;
}

// -- General Response
int send_response(int data_type, int ret_size, int log){
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = data_type;
    ShmPTR->payload_size = ret_size;

    // Log response
    if(log) logblock();

    // Set status
    ShmPTR->status = RESPONSE;

    return 0;
}

int send_void(int log) {
    // Nothing to memcopy in Buffer

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = VOID;
    ShmPTR->payload_size = 0;

    // Log response
    if (log) logblock();

    // Set status
    ShmPTR->status = RESPONSE;

    return 0;
}

// -- XDefaultScreen
int xdefaultscreen_lh(args_XDefaultScreen *argp)
{
    // Get function specific args
    Display* display = argp->display;;

    // Call actual function
    int result = XDefaultScreen(display);

//    if(!replay){
    // Memcopy in Buffer
    int ret_size = sizeof(int);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Send response
    send_response(INT, ret_size, !replay);
//    }

    // Return
    return result;
}


// -- XDisplayWidth
int xdisplaywidth_lh(args_XDisplayWidth *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 int screen_number = argp->screen_number;;

    // Call actual function
    int result = XDisplayWidth(display, screen_number);

//    if(!replay){
	// Memcopy in Buffer
	int ret_size = sizeof(int);
	memcpy(ShmPTR->buffer, &result, ret_size);

	// Send response
	send_response(INT, ret_size, !replay);
//    }

    // Return
    return result;
}


// -- XDisplayHeight
int xdisplayheight_lh(args_XDisplayHeight *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 int screen_number = argp->screen_number;;

    // Call actual function
    int result = XDisplayHeight(display, screen_number);

//    if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(int);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(INT, ret_size, !replay);
//    }

    // Return
    return result;
}


// -- XRootWindow
Window xrootwindow_lh(args_XRootWindow *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 int screen_number = argp->screen_number;;

    // Call actual function
    Window result = XRootWindow(display, screen_number);

    // if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(Window);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(WINDOW, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- XOpenDisplay
Display* xopendisplay_lh(args_XOpenDisplay *argp)
{
    // Get function specific args
    _Xconst char *display_name = argp->display_name;;

    // Call actual function
    Display* result = XOpenDisplay(display_name);

    // if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(Display*);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(DISPLAYP, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- XCreateColormap
Colormap xcreatecolormap_lh(args_XCreateColormap *argp)
{
    // Get function specific args
    Display* display = argp->display;;
	 Window w = argp->w;;
	 Visual*	visual = argp->visual;;
	 int	alloc  = argp->alloc;;

    // Call actual function
    Colormap result = XCreateColormap(display, w, visual, alloc);

    // if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(Colormap);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(COLORMAP, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- XCreateWindow
Window xcreatewindow_lh(args_XCreateWindow *argp)
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

    // if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(Window);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(WINDOW, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- XInternAtom
Atom xinternatom_lh(args_XInternAtom *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 _Xconst char *atom_name = argp->atom_name;;
	 Bool only_if_exists = argp->only_if_exists;;

    // Call actual function
    Atom result = XInternAtom(display, atom_name, only_if_exists);

    // if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(Atom);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(ATOM, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- XChangeProperty
int xchangeproperty_lh(args_XChangeProperty *argp)
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

    // if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(int);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(INT, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- XSetNormalHints
int xsetnormalhints_lh(args_XSetNormalHints *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 Window w = argp->w;;
	 XSizeHints hints = argp->hints;;

    // Call actual function
    int result = XSetNormalHints(display, w, &hints);

    //  if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(int);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(INT, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- XSetStandardProperties
int xsetstandardproperties_lh(args_XSetStandardProperties *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 Window w = argp->w;;
	 _Xconst char window_name = argp->window_name;;
	 _Xconst char icon_name = argp->icon_name;;
	 Pixmap icon_pixmap = argp->icon_pixmap;;
//	 char** argv = argp->argv;;
	 int argc = argp->argc;;
	 XSizeHints hints = argp->hints;;
    // Call actual function
    int result = XSetStandardProperties(display, w, &window_name, &icon_name, icon_pixmap, (char **)NULL, argc, &hints);

    //  if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(int);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(INT, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- XFree
int xfree_lh(args_XFree *argp)
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

    // Return
    return 0;
}


// -- XMapWindow
int xmapwindow_lh(args_XMapWindow *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 Window w = argp->w;;

    // Call actual function
    printf("Next call should fail\n");
    int result = XMapWindow(display, w);

    //  if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(int);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(INT, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- XPending
int xpending_lh(args_XPending *argp)
{
    // Get function specific args
    Display *display = argp->display;;

    // Call actual function
    int result = XPending(display);
    printf("Back from XPending\n");
    //  if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(int);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(INT, ret_size, 0);
    // }
    printf("Sent Response\n");
    // Return
    return result;
}


// -- XNextEvent
XEvent *xnextevent_lh(args_XNextEvent *argp)
{
    // Get function specific args
    Display *display = argp->display;;
    XEvent *result = malloc(sizeof(XEvent));

    // Call actual function
    XNextEvent(display, result);

    //  if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(XEvent);
        memcpy(ShmPTR->buffer, result, ret_size);

        // Send response
        send_response(XEVENT, ret_size, 0);
    // }

    // Return
    return result;
}


// -- XLookupKeysym
KeySym xlookupkeysym_lh(args_XLookupKeysym *argp)
{
    // Get function specific args
    XKeyEvent *key_event = argp->key_event;;
	 int index = argp->index;;

    // Call actual function
    KeySym result = XLookupKeysym(key_event, index);

    //  if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(KeySym);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(KEYSYM, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- XLookupString
int xlookupstring_lh(args_XLookupString *argp)
{
    // Get function specific args
    XKeyEvent *event_struct = argp->event_struct;;
	 char *buffer_return = argp->buffer_return;;
	 int bytes_buffer = argp->bytes_buffer;;
	 KeySym *keysym_return = argp->keysym_return;;
	 XComposeStatus *status_in_out = argp->status_in_out;;

    // Call actual function
    int result = XLookupString(event_struct, buffer_return, bytes_buffer, keysym_return, status_in_out);

    //  if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(int);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(INT, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- XDestroyWindow
int xdestroywindow_lh(args_XDestroyWindow *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 Window w = argp->w;;

    // Call actual function
    int result = XDestroyWindow(display, w);

    //  if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(int);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(INT, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- glGetString
GLubyte* glgetstring_lh(args_glGetString *argp)
{
    // Get function specific args
    GLenum name = argp->name;;

    // Call actual function
    const GLubyte* result = glGetString(name);

    //  if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(GLubyte*);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(GLUBYTEP, ret_size, !replay);
    // }

    // Return
    return (GLubyte*) result;
}


// -- glLightfv
void gllightfv_lh(args_glLightfv *argp)
{
    // Get function specific args
     GLenum light = argp->light;;
	 GLenum pname = argp->pname;;
	 const GLfloat *params  = argp->params;;

    // Call actual function
    glLightfv(light, pname, params);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glEnable
void glenable_lh(args_glEnable *argp)
{
    // Get function specific args
     GLenum cap  = argp->cap;;

    // Call actual function
    glEnable(cap);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glGenLists
GLuint glgenlists_lh(args_glGenLists *argp)
{
    // Get function specific args
     GLsizei range  = argp->range;;

    // Call actual function
    GLuint result = glGenLists(range);

    //  if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(GLuint);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(GLUINT, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- glNewList
void glnewlist_lh(args_glNewList *argp)
{
    // Get function specific args
     GLuint list = argp->list;;
	 GLenum mode  = argp->mode;;

    // Call actual function
    glNewList(list, mode);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glMaterialfv
void glmaterialfv_lh(args_glMaterialfv *argp)
{
    // Get function specific args
     GLenum face = argp->face;;
	 GLenum pname = argp->pname;;
	 const GLfloat *params  = argp->params;;

    // Call actual function
    glMaterialfv(face, pname, params);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glEndList
void glendlist_lh()
{
    // No function specific args

    // Call actual function
    glEndList();

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glShadeModel
void glshademodel_lh(args_glShadeModel *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;;

    // Call actual function
    glShadeModel(mode);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glNormal3f
void glnormal3f_lh(args_glNormal3f *argp)
{
    // Get function specific args
     GLfloat nx = argp->nx;;
	 GLfloat ny = argp->ny;;
	 GLfloat nz  = argp->nz;;

    // Call actual function
    glNormal3f(nx, ny, nz);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glBegin
void glbegin_lh(args_glBegin *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;;

    // Call actual function
    glBegin(mode);

    //    if(!replay){
    send_void(!replay);
//    }
}


// -- glVertex3f
void glvertex3f_lh(args_glVertex3f *argp)
{
    // Get function specific args
     GLfloat x = argp->x;;
	 GLfloat y = argp->y;;
	 GLfloat z  = argp->z;;

    // Call actual function
    glVertex3f(x, y, z);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glEnd
void glend_lh()
{
    // No function specific args

    // Call actual function
    glEnd();

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glViewport
void glviewport_lh(args_glViewport *argp)
{
    // Get function specific args
     GLint x = argp->x;;
	 GLint y = argp->y;;
	 GLsizei width = argp->width;;
	 GLsizei height  = argp->height;;

    // Call actual function
    glViewport(x, y, width, height);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glMatrixMode
void glmatrixmode_lh(args_glMatrixMode *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;;

    // Call actual function
    glMatrixMode(mode);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glLoadIdentity
void glloadidentity_lh()
{
    // No function specific args

    // Call actual function
    glLoadIdentity();

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glFrustum
void glfrustum_lh(args_glFrustum *argp)
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

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glTranslatef
void gltranslatef_lh(args_glTranslatef *argp)
{
    // Get function specific args
     GLfloat x = argp->x;;
	 GLfloat y = argp->y;;
	 GLfloat z  = argp->z;;

    // Call actual function
    glTranslatef(x, y, z);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glDrawBuffer
void gldrawbuffer_lh(args_glDrawBuffer *argp)
{
    // Get function specific args
     GLenum mode  = argp->mode;;

    // Call actual function
    glDrawBuffer(mode);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glPushMatrix
void glpushmatrix_lh()
{
    // No function specific args

    // Call actual function
    glPushMatrix();

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glPopMatrix
void glpopmatrix_lh()
{
    // No function specific args

    // Call actual function
    glPopMatrix();

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glTranslated
void gltranslated_lh(args_glTranslated *argp)
{
    // Get function specific args
     GLdouble x = argp->x;;
	 GLdouble y = argp->y;;
	 GLdouble z  = argp->z;;

    // Call actual function
    glTranslated(x, y, z);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glClear
void glclear_lh(args_glClear *argp)
{
    // Get function specific args
     GLbitfield mask  = argp->mask;

    // Call actual function
     glClear(mask);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glRotatef
void glrotatef_lh(args_glRotatef *argp)
{
    // Get function specific args
     GLfloat angle = argp->angle;;
	 GLfloat x = argp->x;;
	 GLfloat y = argp->y;;
	 GLfloat z  = argp->z;;

    // Call actual function
    glRotatef(angle, x, y, z);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glCallList
void glcalllist_lh(args_glCallList *argp)
{
    // Get function specific args
     GLuint list  = argp->list;;

    // Call actual function
    glCallList(list);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glDeleteLists
void gldeletelists_lh(args_glDeleteLists *argp)
{
    // Get function specific args
     GLuint list = argp->list;;
	 GLsizei range  = argp->range;;

    // Call actual function
    glDeleteLists(list, range);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glXDestroyContext
void glxdestroycontext_lh(args_glXDestroyContext *argp)
{
    // Get function specific args
     Display *dpy = argp->dpy;;
	 GLXContext ctx  = argp->ctx;;

    // Call actual function
    glXDestroyContext(dpy, ctx);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glXChooseVisual
XVisualInfo glxchoosevisual_lh(args_glXChooseVisual *argp)
{
    // Get function specific args
    Display *dpy = argp->dpy;;
	 int screen = argp->screen;;
	 int *attribList = argp->attribList;;
    // Call actual function
    XVisualInfo result = *glXChooseVisual(dpy, screen, attribList);

    //  if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(XVisualInfo);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(XVISUALINFO, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- glXCreateContext
GLXContext glxcreatecontext_lh(args_glXCreateContext *argp)
{
    // Get function specific args
    Display *dpy = argp->dpy;;
	 XVisualInfo vis = argp->vis;;
	 GLXContext shareList = argp->shareList;;
	 Bool direct = argp->direct;;

    // Call actual function
    GLXContext result = glXCreateContext(dpy, &vis, shareList, direct);

    //  if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(GLXContext);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(GLXCONTEXT, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- glXMakeCurrent
Bool glxmakecurrent_lh(args_glXMakeCurrent *argp)
{
    // Get function specific args
    Display* dpy = argp->dpy;;
	 GLXDrawable drawable = argp->drawable;;
	 GLXContext ctx = argp->ctx;;

     // todo: make this global for calls like glclear()
//     curdisplay = dpy;
//     curdrawable = drawable;
//     curctx = ctx;

    // Call actual function
    Bool result = glXMakeCurrent(dpy, drawable, ctx);

    //  if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(Bool);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(BOOL, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- glXQueryExtensionsString
char* glxqueryextensionsstring_lh(args_glXQueryExtensionsString *argp)
{
    // Get function specific args
     Display *dpy = argp->dpy;;
	 int screen  = argp->screen;;

    // Call actual function - strcpy because string return
    char dest[1024];
    const char* result = glXQueryExtensionsString(dpy, screen);
    strcpy(dest, result);

    // if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(char[1024]);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(CHARARR, ret_size, !replay);
    // }

    // Return
    return (char*) result;
}


// -- glXQueryDrawable
void glxquerydrawable_lh(args_glXQueryDrawable *argp)
{
    // Get function specific args
    Display *dpy = argp->dpy;;
	 GLXDrawable draw = argp->draw;;
	 int attribute = argp->attribute;;
	 unsigned int value = argp->value;;

    // Call actual function
    glXQueryDrawable(dpy, draw, attribute, &value);

//    if(!replay){
    send_void(!replay);
//    }
}


// -- glXGetProcAddressARB
__GLXextFuncPtr glxgetprocaddressarb_lh(args_glXGetProcAddressARB *argp)
{
    // Get function specific args
    const GLubyte *procname = argp->procname;;

    // Call actual function
    __GLXextFuncPtr result = glXGetProcAddressARB(procname);

    // if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(__GLXextFuncPtr);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(__GLXEXTFUNCPTR, ret_size, !replay);
    // }

    // Return
    return result;
}


// -- glXSwapBuffers
void glxswapbuffers_lh(args_glXSwapBuffers *argp)
{
    // Get function specific args
     Display *dpy = argp->dpy;;
	 GLXDrawable drawable  = argp->drawable;;

    // Call actual function
    glXSwapBuffers(dpy, drawable);

//    if(!replay){
    send_void(!replay);
//    }
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
                logblock();
                if(restored){
                    argp_xdefaultscreen.display = cur_display_p;
                }
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
                logblock();
                if(restored){
                    argp_xdisplaywidth.display = cur_display_p;
                    argp_xdisplaywidth.screen_number = cur_default_screen;
                }
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
                logblock();
                if(restored){
                    argp_xdisplayheight.display = cur_display_p;
                    argp_xdisplayheight.screen_number = cur_default_screen;
                }
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
                logblock();
                if(restored){
                    argp_xrootwindow.display = cur_display_p;
                    argp_xrootwindow.screen_number = cur_default_screen;
                }
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
                logblock();
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
                logblock();
                if(restored){
                    argp_xcreatecolormap.display = cur_display_p;
                    argp_xcreatecolormap.w = cur_root_window;
                    argp_xcreatecolormap.visual = cur_vis_info_p->visual;
                }
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
                logblock();
                if(restored){
                    argp_xcreatewindow.display = cur_display_p;
                    argp_xcreatewindow.visual = cur_vis_info_p->visual;
                    argp_xcreatewindow.attributes.colormap = cur_colormap;
                    argp_xcreatewindow.parent = cur_root_window;
                }
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
                logblock();
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
                logblock();
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
                logblock();
                if(restored){
                    argp_xsetnormalhints.display = cur_display_p;
                    argp_xsetnormalhints.w = cur_window;
                }
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
                logblock();
                if(restored){
                    argp_xsetstandardproperties.display = cur_display_p;
                    argp_xsetstandardproperties.w = cur_window;
                    argp_xsetstandardproperties.hints = cur_hints;
                }
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
                logblock();
                if(restored){
                    argp_xfree.visinfo = *cur_vis_info_p;
                }
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
                logblock();
                if(restored){
                    argp_xmapwindow.display = cur_display_p;
                    argp_xmapwindow.w = cur_window;
                }
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
                // logblock();
                if(restored){
                    argp_xpending.display = cur_display_p;
                }
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
                // logblock();
                if(restored){
                    argp_xnextevent.display = cur_display_p;
                }
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
                logblock();
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
                logblock();
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
                logblock();
                if(restored){
                    argp_xdestroywindow.display = cur_display_p;
                    argp_xdestroywindow.w = cur_window;
                }
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
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
                logblock();
                if(restored){
                    argp_glxdestroycontext.dpy = cur_display_p;
                    argp_glxdestroycontext.ctx = cur_context;
                }
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
                logblock();
                if(restored){
                    argp_glxchoosevisual.dpy = cur_display_p;
                    argp_glxchoosevisual.screen = cur_default_screen;
                }
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
                logblock();
                if(restored){
                    argp_glxcreatecontext.dpy = cur_display_p;
                    argp_glxcreatecontext.vis = *cur_vis_info_p;
                }
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
                logblock();
                if(restored){
                    argp_glxmakecurrent.dpy = cur_display_p;
                    argp_glxmakecurrent.drawable = cur_window;
                    argp_glxmakecurrent.ctx = cur_context;
                }
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
                logblock();
                if(restored){
                    argp_glxqueryextensionsstring.dpy = cur_display_p;
                    argp_glxqueryextensionsstring.screen = cur_default_screen;
                }
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
                logblock();
                if(restored){
                    argp_glxquerydrawable.dpy = cur_display_p;
                    argp_glxquerydrawable.draw = cur_window;
                }
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
                logblock();
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
                logblock();
                if(restored){
                    argp_glxswapbuffers.dpy = cur_display_p;
                    argp_glxswapbuffers.drawable = cur_window;
                }
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
    if( argc == 3 ) {
      if(!strcmp(argv[1],"replay")){
          filename = argv[2];
          replay = 1;
      } else {
          printf("Unknown command %s\n", argv[1]);
          exit(1);
      }
    } else if( argc == 2) {
        if(!strcmp(argv[1],"replay")){
            printf("usage: atl_lh replay <filepath>\n");
            exit(1);
        } else {
            printf("Unknown command %s\n", argv[1]);
            exit(1);
        }
    }

    initmem();

    if(replay){
        restored = 1;
        printf("RESTORE: Replaying log\n");
        replay_log(argv[2]);
        printf("Flushing all X events\n");
        XEvent event;
        for(int i = 0; i < XEventsQueued(cur_display_p, QueuedAlready); i++){
            XNextEvent(cur_display_p, &event);
            printf("%d\n", event.type);
        }
        printf("RESTORE: Done\n");
        replay = 0;
    }

    initlog();
    service_listener();
    fclose(file);
    return 0;
}
