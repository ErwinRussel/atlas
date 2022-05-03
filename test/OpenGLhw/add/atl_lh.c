
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
