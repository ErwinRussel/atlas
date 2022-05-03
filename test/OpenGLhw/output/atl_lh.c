
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


// -- XCreateWindow
Window *xcreatewindow_lh(args_XCreateWindow *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 Window parent = argp->parent;;
	 int x = argp->x;;
	 int y = argp->y;;
	 unsigned int width = argp->width;;
	 unsigned int height = argp->height;;
	 unsigned int border_width = argp->border_width;;
	 int	depth = argp->depth;;
	 unsigned int class = argp->class;;
	 Visual *visual = argp->visual;;
	 unsigned long valuemask = argp->valuemask;;
	 XSetWindowAttributes *attributes = &argp->attributes;;

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

// -- Waitfornotify is the predicate
static Bool WaitForNotify( Display *dpy, XEvent *event, XPointer arg ) {
    return (event->type == MapNotify) && (event->xmap.window == (Window) arg);
}

// -- XIfEvent
int *xifevent_lh(args_XIfEvent *argp)
{
    // Get function specific args
     Display *display = argp->display;;
	 XEvent *event_return = argp->event_return;;
//    Bool (*predicate)() = argp->predicate;;
	 XPointer arg  = argp->arg;;

     XEvent event;

    // Call actual function
    int result = XIfEvent(display, &event, WaitForNotify, arg);

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


// -- glXChooseFBConfig
GLXFBConfig* *glxchoosefbconfig_lh(args_glXChooseFBConfig *argp)
{
    // Get function specific args
    	Display *dpy = argp->dpy;;
	 int screen = argp->screen;;
	 const int *attrib_list = argp->attrib_list;;
	 int nelements = argp->nelements;;

    // Call actual function
    GLXFBConfig* result = glXChooseFBConfig(dpy, screen, attrib_list, &nelements);

    // Memcopy in Buffer
    int ret_size = sizeof(GLXFBConfig);
    memcpy(ShmPTR->buffer, result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = GLXFBCONFIG;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXGetVisualFromFBConfig
XVisualInfo* *glxgetvisualfromfbconfig_lh(args_glXGetVisualFromFBConfig *argp)
{
    // Get function specific args
    	Display *dpy = argp->dpy;;
	 GLXFBConfig config = argp->config;;

    // Call actual function
    XVisualInfo result = *glXGetVisualFromFBConfig(dpy, config);

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


// -- glXCreateNewContext
GLXContext *glxcreatenewcontext_lh(args_glXCreateNewContext *argp)
{
    // Get function specific args
    	Display *dpy = argp->dpy;;
	 GLXFBConfig config = argp->config;;
	 int render_type = argp->render_type;;
	 GLXContext share_list = argp->share_list;;
	 Bool direct = argp->direct;;

    // Call actual function
    GLXContext result = glXCreateNewContext(dpy, config, render_type, share_list, direct);

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


// -- glXCreateWindow
GLXWindow *glxcreatewindow_lh(args_glXCreateWindow *argp)
{
    // Get function specific args
    	Display *dpy = argp->dpy;;
	 GLXFBConfig config = argp->config;;
	 Window win = argp->win;;
	 const int *attrib_list = argp->attrib_list;;

    // Call actual function
    GLXWindow result = glXCreateWindow(dpy, config, win, attrib_list);

    // Memcopy in Buffer
    int ret_size = sizeof(GLXWindow);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = GLXWINDOW;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- glXMakeContextCurrent
Bool *glxmakecontextcurrent_lh(args_glXMakeContextCurrent *argp)
{
    // Get function specific args
    	Display *display = argp->display;;
	 GLXDrawable draw = argp->draw;;
	 GLXDrawable read = argp->read;;
	 GLXContext ctx = argp->ctx;;

    // Call actual function
    Bool result = glXMakeContextCurrent(display, draw, read, ctx);

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

// -- XCreateColormap
Colormap *xcreatecolormap_lh(args_XCreateColormap *argp)
{
    // Get function specific args
    Display *display = argp->display;;
    Window w = argp->w;;
    Visual *visual = argp->visual;;
    int alloc = argp->alloc;;

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

            case XIFEVENT: ;
                args_XIfEvent argp_xifevent;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XIfEvent)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xifevent, ShmPTR->buffer, sizeof(args_XIfEvent));

                // Execute function call
                xifevent_lh(&argp_xifevent);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

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

            case GLXCHOOSEFBCONFIG: ;
                args_glXChooseFBConfig argp_glxchoosefbconfig;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXChooseFBConfig)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxchoosefbconfig, ShmPTR->buffer, sizeof(args_glXChooseFBConfig));

                // Execute function call
                glxchoosefbconfig_lh(&argp_glxchoosefbconfig);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXGETVISUALFROMFBCONFIG: ;
                args_glXGetVisualFromFBConfig argp_glxgetvisualfromfbconfig;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXGetVisualFromFBConfig)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxgetvisualfromfbconfig, ShmPTR->buffer, sizeof(args_glXGetVisualFromFBConfig));

                // Execute function call
                glxgetvisualfromfbconfig_lh(&argp_glxgetvisualfromfbconfig);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXCREATENEWCONTEXT: ;
                args_glXCreateNewContext argp_glxcreatenewcontext;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXCreateNewContext)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxcreatenewcontext, ShmPTR->buffer, sizeof(args_glXCreateNewContext));

                // Execute function call
                glxcreatenewcontext_lh(&argp_glxcreatenewcontext);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXCREATEWINDOW: ;
                args_glXCreateWindow argp_glxcreatewindow;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXCreateWindow)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxcreatewindow, ShmPTR->buffer, sizeof(args_glXCreateWindow));

                // Execute function call
                glxcreatewindow_lh(&argp_glxcreatewindow);

                // Print
                printf("RESPONSE: Data type: %d\n\n", ShmPTR->data_type);
                break;

            case GLXMAKECONTEXTCURRENT: ;
                args_glXMakeContextCurrent argp_glxmakecontextcurrent;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_glXMakeContextCurrent)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxmakecontextcurrent, ShmPTR->buffer, sizeof(args_glXMakeContextCurrent));

                // Execute function call
                glxmakecontextcurrent_lh(&argp_glxmakecontextcurrent);

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
