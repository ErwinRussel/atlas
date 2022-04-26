
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
	 unsigned long background = argp->background;;

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


// -- XSelectInput
int *xselectinput_lh(args_XSelectInput *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 Window w = argp->w;;
	 long event_mask = argp->event_mask;;

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
XEvent *xnextevent_lh(args_XNextEvent *argp)
{
    // Get function specific args
    Display *display = argp->display;;
	 XEvent *event_return = argp->event_return;;

    // Call actual function
    XEvent result = XNextEvent(display, event_return);

    // Memcopy in Buffer
    int ret_size = sizeof(XEvent);
    memcpy(ShmPTR->buffer, &result, ret_size);

    // Set function specific headers
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = XEVENT;
    ShmPTR->payload_size = ret_size;

    // Set status
    ShmPTR->status = RESPONSE;
}


// -- XDefaultRootWindow
Window *xdefaultrootwindow_lh(args_XDefaultRootWindow *argp)
{
    // Get function specific args
    Display *display = argp->display;;

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

            case XCREATESIMPLEWINDOW: ;
                args_XCreateSimpleWindow argp_xcreatesimplewindow;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XCreateSimpleWindow)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xcreatesimplewindow, ShmPTR->buffer, sizeof(args_XCreateSimpleWindow));

                // Execute function call
                xcreatesimplewindow_lh(&argp_xcreatesimplewindow);

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

            case XSELECTINPUT: ;
                args_XSelectInput argp_xselectinput;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XSelectInput)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xselectinput, ShmPTR->buffer, sizeof(args_XSelectInput));

                // Execute function call
                xselectinput_lh(&argp_xselectinput);

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

            case XDEFAULTROOTWINDOW: ;
                args_XDefaultRootWindow argp_xdefaultrootwindow;

                // assert payload size
                if(ShmPTR->payload_size != sizeof(args_XDefaultRootWindow)){
                    printf("Wrong payload size\n\n");
                    ShmPTR->status = LISTEN;
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xdefaultrootwindow, ShmPTR->buffer, sizeof(args_XDefaultRootWindow));

                // Execute function call
                xdefaultrootwindow_lh(&argp_xdefaultrootwindow);

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
