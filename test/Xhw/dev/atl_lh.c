#include  "atl_header.h"
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  "replay.h"

// Global pointers to use from init
key_t           ShmKEY;
int             ShmID;
struct MsgBlock *ShmPTR;
FILE *file;

// Set replay
int replay = 0; // todo: make this boolean
int restored = 0;
char* filename;

// Destructor
__attribute__((destructor)) void loginevent (void);

// Constructor
void init_shmem(){
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
}

void setstatus(){
    // Open file for logging todo: if replay we append to the file
    if(restored){
        file = fopen(filename, "ab");
        if(file == NULL){
            printf("Could not open file: %s", filename);
            exit(1);
        }
    } else {
        file = fopen("calllog.bin", "wb");
    }

    if(file == NULL) printf("Could not open file for logging\n");

    // Set status to LISTEN
    if(ShmPTR->status != RESPONSE)
        ShmPTR->status = LISTEN;
}

// Logging
int logblock(){
    struct StrgBlock strgblock;
    strgblock.message_type = ShmPTR->message_type;
    strgblock.data_type = ShmPTR->data_type;
    strgblock.payload_size = ShmPTR->payload_size;
    // memcpy because of array
    memcpy(&strgblock.buffer, ShmPTR->buffer, strgblock.payload_size);
    if(fwrite(&strgblock, sizeof(struct StrgBlock), 1, file) != 1){
        printf("Logging function failed, closing log\n");
        fclose(file);
    }
}

// Specialized function to log the last Xevent if it is called.
void loginevent(){
    if(ShmPTR->message_type == FUNC_CALL && ShmPTR->data_type == XNEXTEVENT)
        logblock();
}
// Sets of functions

// -- General Response
int send_response(int data_type, int ret_size, int log){
    ShmPTR->message_type = FUNC_RETURN;
    ShmPTR->data_type = data_type;
    ShmPTR->payload_size = ret_size;

    // Log response
    if(log) logblock();

    // Set status
    ShmPTR->status = RESPONSE;
}

// -- XOpenDisplay
Display* xopendisplay_lh(args_XOpenDisplay *argp)
{
    // Get function specific args
    _Xconst char *display_name = argp->display_name;;

    // Call actual function
    Display* result = XOpenDisplay(display_name);

    if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(Display*);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(DISPLAYP, ret_size, 1);
    }

    return result;
}


// -- XCreateSimpleWindow
Window xcreatesimplewindow_lh(args_XCreateSimpleWindow *argp)
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

    if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(Window);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(WINDOW, ret_size, 1);
    }

    return result;
}


// -- XMapWindow
int xmapwindow_lh(args_XMapWindow *argp)
{
    // Get function specific args
    Display *display = argp->display;;
    Window w = argp->w;;

    // Call actual function
    int result = XMapWindow(display, w);

    if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(int);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(INT, ret_size, 1);
    }

    return result;
}


// -- XSelectInput
int xselectinput_lh(args_XSelectInput *argp)
{
    // Get function specific args
    Display *display = argp->display;;
    Window w = argp->w;;
    long event_mask = argp->event_mask;;

    // Call actual function
    int result = XSelectInput(display, w, event_mask);

    if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(int);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(INT, ret_size, 1);
    }

    return result;
}


// -- XNextEvent
XEvent xnextevent_lh(args_XNextEvent *argp)
{
    // Get function specific args
    Display *display = argp->display;
    XEvent *result = malloc(sizeof(XEvent));

    // Call actual function
    XNextEvent(display, result);

    // We always do nextevent, because last in line
    int ret_size = sizeof(XEvent);
    memcpy(ShmPTR->buffer, result, ret_size);

    // Send response
    send_response(XEVENT, ret_size, 0);

    return *result;
}


// -- XDefaultRootWindow
Window xdefaultrootwindow_lh(args_XDefaultRootWindow *argp)
{
    // Get function specific args
    Display *display = argp->display;;

    // Call actual function
    Window result = XDefaultRootWindow(display);

    if(!replay){
        // Memcopy in Buffer
        int ret_size = sizeof(Window);
        memcpy(ShmPTR->buffer, &result, ret_size);

        // Send response
        send_response(WINDOW, ret_size, 1);
    }

    return result;
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
                logblock();

                cur_display = xopendisplay_lh(&argp_xopendisplay);

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
                if(restored){
                    argp_xcreatesimplewindow.display = cur_display;
                }

                logblock();

                cur_window = xcreatesimplewindow_lh(&argp_xcreatesimplewindow);

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
                if(restored){
                    argp_xmapwindow.display = cur_display;
                    argp_xmapwindow.w = cur_window;
                }

                logblock();

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
                if(restored){
                    argp_xmapwindow.display = cur_display;
                    argp_xmapwindow.w = cur_window;
                }

                logblock();

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
                if(restored){
                    argp_xnextevent.display = cur_display;
                }

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
                if(restored){
                    argp_xdefaultrootwindow.display = cur_display;
                }

                logblock();

                cur_root_window = xdefaultrootwindow_lh(&argp_xdefaultrootwindow);

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
    init_shmem();
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

    if(replay){
        restored = 1;
        printf("RESTORE: Replaying log\n");
        replay_log(argv[2]);
        printf("RESTORE: Done\n");
        replay = 0;
    }

    // Init if the ptr does not exits, small thing because of sync
    setstatus();
    service_listener();
    fclose(file);
    return 0;
}
