#include "atl_header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "atl_lh.h"

Display* cur_display;
Window cur_window;
Window cur_root_window;

FILE *file;

int open_file(char *filename){
    file = fopen("calllog.bin", "rb");

    if(file == NULL){
        printf("Cannot read file\n");
        return 1;
    }

    return 0;
}

int replay_log(char *filename) {
    open_file(filename);
    // Loop
    while(1){
        // We read in pairs this also determines what we should do next
        struct StrgBlock call;
        struct StrgBlock resp;

        // CALL
        if(fread(&call, sizeof(struct StrgBlock), 1, file) != 1) {
            fclose(file);
            return 1;
        }

        // assert if FUNC_CALL
        if(call.message_type != FUNC_CALL){
            printf("No function call\n");
            return 1;
        }

        // RESPONSE
        if(fread(&resp, sizeof(struct StrgBlock), 1, file) != 1) {
            printf("No function response, checking if waiting for Event..\n");
            if(call.data_type == XNEXTEVENT){
                printf("Waiting for event..\n");
            } else {
                fclose(file);
                return 1;
            }
        }

        // assert if FUNC_CALL
        if(resp.message_type != FUNC_RETURN){
            printf("No function response\n");
            return 1;
        }

        // read function type header
        data_types func_type = call.data_type;
        printf("REPLAY: Function type: %d\n", func_type);

        // Call function from desired function type
        switch (func_type)
        {
            case XOPENDISPLAY: ;
                args_XOpenDisplay argp_xopendisplay;

                // assert payload size
                if(call.payload_size != sizeof(args_XOpenDisplay)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xopendisplay, call.buffer, sizeof(args_XOpenDisplay));

                // Execute function call and replace
                cur_display = xopendisplay_lh(&argp_xopendisplay);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XCREATESIMPLEWINDOW: ;
                args_XCreateSimpleWindow argp_xcreatesimplewindow;

                // assert payload size
                if(call.payload_size != sizeof(args_XCreateSimpleWindow)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xcreatesimplewindow, call.buffer, sizeof(args_XCreateSimpleWindow));

                // Execute function call and replace
                argp_xcreatesimplewindow.display = cur_display;
                cur_window = xcreatesimplewindow_lh(&argp_xcreatesimplewindow);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XMAPWINDOW: ;
                args_XMapWindow argp_xmapwindow;

                // assert payload size
                if(call.payload_size != sizeof(args_XMapWindow)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xmapwindow, call.buffer, sizeof(args_XMapWindow));
                argp_xmapwindow.display = cur_display;
                argp_xmapwindow.w = cur_window;

                // Execute function call
                xmapwindow_lh(&argp_xmapwindow);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XSELECTINPUT: ;
                args_XSelectInput argp_xselectinput;

                // assert payload size
                if(call.payload_size != sizeof(args_XSelectInput)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xselectinput, call.buffer, sizeof(args_XSelectInput));
                argp_xselectinput.display = cur_display;
                argp_xselectinput.w = cur_window;

                // Execute function call
                xselectinput_lh(&argp_xselectinput);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XNEXTEVENT: ;
                args_XNextEvent argp_xnextevent;

                // assert payload size
                if(call.payload_size != sizeof(args_XNextEvent)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xnextevent, call.buffer, sizeof(args_XNextEvent));

                // Execute function call
                argp_xnextevent.display = cur_display;
                xnextevent_lh(&argp_xnextevent);

                // Print
                printf("RESPONSE: Data type: %d\n\n", XEVENT);
                break;

            case XDEFAULTROOTWINDOW: ;
                args_XDefaultRootWindow argp_xdefaultrootwindow;

                // assert payload size
                if(call.payload_size != sizeof(args_XDefaultRootWindow)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xdefaultrootwindow, call.buffer, sizeof(args_XDefaultRootWindow));
                argp_xdefaultrootwindow.display = cur_display;

                // Execute function call
                cur_root_window = xdefaultrootwindow_lh(&argp_xdefaultrootwindow);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;


            default:
                // Change this print error so we know what happens
                printf("Message data type unrecognized\n\n");
                break;
        }
    }
}

//int main(){
//    if(open_file()) return 1;
//    replay_log();
//    XEvent event;
//    while (True) {
//        XNextEvent(cur_display, &event);
//        printf("%d\n", event.type);
//    }
//    return 0;
//}

