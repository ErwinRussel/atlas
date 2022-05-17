#include "atl_header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "atl_lh.h"
#include "replay.h"



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
            case XDEFAULTSCREEN: ;
                args_XDefaultScreen argp_xdefaultscreen;

                // assert payload size
                if(call.payload_size != sizeof(args_XDefaultScreen)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xdefaultscreen, call.buffer, sizeof(args_XDefaultScreen));

                // Execute function call
                argp_xdefaultscreen.display = cur_display_p;
                cur_default_screen = xdefaultscreen_lh(&argp_xdefaultscreen);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XDISPLAYWIDTH: ;
                args_XDisplayWidth argp_xdisplaywidth;

                // assert payload size
                if(call.payload_size != sizeof(args_XDisplayWidth)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xdisplaywidth, call.buffer, sizeof(args_XDisplayWidth));

                // Execute function call
                argp_xdisplaywidth.display = cur_display_p;
                argp_xdisplaywidth.screen_number = cur_default_screen;
                xdisplaywidth_lh(&argp_xdisplaywidth);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XDISPLAYHEIGHT: ;
                args_XDisplayHeight argp_xdisplayheight;

                // assert payload size
                if(call.payload_size != sizeof(args_XDisplayHeight)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                argp_xdisplayheight.display = cur_display_p;
                argp_xdisplayheight.screen_number = cur_default_screen;
                memcpy(&argp_xdisplayheight, call.buffer, sizeof(args_XDisplayHeight));

                // Execute function call
                xdisplayheight_lh(&argp_xdisplayheight);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XROOTWINDOW: ;
                args_XRootWindow argp_xrootwindow;

                // assert payload size
                if(call.payload_size != sizeof(args_XRootWindow)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xrootwindow, call.buffer, sizeof(args_XRootWindow));

                // Execute function call
                argp_xrootwindow.display = cur_display_p;
                argp_xrootwindow.screen_number = cur_default_screen;
                cur_root_window = xrootwindow_lh(&argp_xrootwindow);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XOPENDISPLAY: ;
                args_XOpenDisplay argp_xopendisplay;

                // assert payload size
                if(call.payload_size != sizeof(args_XOpenDisplay)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xopendisplay, call.buffer, sizeof(args_XOpenDisplay));

                // Execute function call
                cur_display_p = xopendisplay_lh(&argp_xopendisplay);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XCREATECOLORMAP: ;
                args_XCreateColormap argp_xcreatecolormap;

                // assert payload size
                if(call.payload_size != sizeof(args_XCreateColormap)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xcreatecolormap, call.buffer, sizeof(args_XCreateColormap));

                // Execute function call
                argp_xcreatecolormap.display = cur_display_p;
                argp_xcreatecolormap.w = cur_window;
                argp_xcreatecolormap.visual = cur_vis_info_p->visual;
                xcreatecolormap_lh(&argp_xcreatecolormap);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XCREATEWINDOW: ;
                args_XCreateWindow argp_xcreatewindow;

                // assert payload size
                if(call.payload_size != sizeof(args_XCreateWindow)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xcreatewindow, call.buffer, sizeof(args_XCreateWindow));

                // Execute function call todo: is this enough
                argp_xcreatewindow.display = cur_display_p;
                argp_xcreatewindow.visual = cur_vis_info_p->visual;
                argp_xcreatewindow.attributes.colormap = cur_colormap;
                cur_window = xcreatewindow_lh(&argp_xcreatewindow);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XINTERNATOM: ; // we skip for replay
                args_XInternAtom argp_xinternatom;

                // assert payload size
                if(call.payload_size != sizeof(args_XInternAtom)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xinternatom, call.buffer, sizeof(args_XInternAtom));

                // Execute function call
                xinternatom_lh(&argp_xinternatom);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XCHANGEPROPERTY: ; // todo: xchangepropery skipped
                args_XChangeProperty argp_xchangeproperty;

                // assert payload size
                if(call.payload_size != sizeof(args_XChangeProperty)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xchangeproperty, call.buffer, sizeof(args_XChangeProperty));

                // Execute function call
                xchangeproperty_lh(&argp_xchangeproperty);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XSETNORMALHINTS: ;
                args_XSetNormalHints argp_xsetnormalhints;

                // assert payload size
                if(call.payload_size != sizeof(args_XSetNormalHints)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xsetnormalhints, call.buffer, sizeof(args_XSetNormalHints));

                // Execute function call
                xsetnormalhints_lh(&argp_xsetnormalhints);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XSETSTANDARDPROPERTIES: ;
                argp_xsetnormalhints.display = cur_display_p;
                argp_xsetnormalhints.w = cur_window;
                args_XSetStandardProperties argp_xsetstandardproperties;

                // assert payload size
                if(call.payload_size != sizeof(args_XSetStandardProperties)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xsetstandardproperties, call.buffer, sizeof(args_XSetStandardProperties));

                // Execute function call
                xsetstandardproperties_lh(&argp_xsetstandardproperties);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XFREE: ;
                args_XFree argp_xfree;

                // assert payload size
                if(call.payload_size != sizeof(args_XFree)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xfree, call.buffer, sizeof(args_XFree));

                // Execute function call
                argp_xfree.visinfo = *cur_vis_info_p;
                xfree_lh(&argp_xfree);

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

                // Execute function call
                argp_xmapwindow.display = cur_display_p;
                argp_xmapwindow.w = cur_window;
                xmapwindow_lh(&argp_xmapwindow);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XPENDING: ; // todo: we do not log this because external events
                args_XPending argp_xpending;

                // assert payload size
                if(call.payload_size != sizeof(args_XPending)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xpending, call.buffer, sizeof(args_XPending));

                // Execute function call
                xpending_lh(&argp_xpending);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XNEXTEVENT: ; // todo: we do not log this because external events
                args_XNextEvent argp_xnextevent;

                // assert payload size
                if(call.payload_size != sizeof(args_XNextEvent)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xnextevent, call.buffer, sizeof(args_XNextEvent));

                // Execute function call
                xnextevent_lh(&argp_xnextevent);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XLOOKUPKEYSYM: ; // todo: we do not log this because external events
                args_XLookupKeysym argp_xlookupkeysym;

                // assert payload size
                if(call.payload_size != sizeof(args_XLookupKeysym)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xlookupkeysym, call.buffer, sizeof(args_XLookupKeysym));

                // Execute function call
                xlookupkeysym_lh(&argp_xlookupkeysym);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XLOOKUPSTRING: ; // todo: we do not log this because external events
                args_XLookupString argp_xlookupstring;

                // assert payload size
                if(call.payload_size != sizeof(args_XLookupString)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xlookupstring, call.buffer, sizeof(args_XLookupString));

                // Execute function call
                xlookupstring_lh(&argp_xlookupstring);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case XDESTROYWINDOW: ; // todo: this is never logged as app is running
                args_XDestroyWindow argp_xdestroywindow;

                // assert payload size
                if(call.payload_size != sizeof(args_XDestroyWindow)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_xdestroywindow, call.buffer, sizeof(args_XDestroyWindow));

                // Execute function call
                xdestroywindow_lh(&argp_xdestroywindow);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLGETSTRING: ;
                args_glGetString argp_glgetstring;

                // assert payload size
                if(call.payload_size != sizeof(args_glGetString)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgetstring, call.buffer, sizeof(args_glGetString));

                // Execute function call
                glgetstring_lh(&argp_glgetstring);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLLIGHTFV: ;
                args_glLightfv argp_gllightfv;

                // assert payload size
                if(call.payload_size != sizeof(args_glLightfv)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gllightfv, call.buffer, sizeof(args_glLightfv));

                // Execute function call
                gllightfv_lh(&argp_gllightfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLENABLE: ;
                args_glEnable argp_glenable;

                // assert payload size
                if(call.payload_size != sizeof(args_glEnable)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glenable, call.buffer, sizeof(args_glEnable));

                // Execute function call
                glenable_lh(&argp_glenable);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLGENLISTS: ;
                args_glGenLists argp_glgenlists;

                // assert payload size
                if(call.payload_size != sizeof(args_glGenLists)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glgenlists, call.buffer, sizeof(args_glGenLists));

                // Execute function call
                glgenlists_lh(&argp_glgenlists);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLNEWLIST: ;
                args_glNewList argp_glnewlist;

                // assert payload size
                if(call.payload_size != sizeof(args_glNewList)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glnewlist, call.buffer, sizeof(args_glNewList));

                // Execute function call
                glnewlist_lh(&argp_glnewlist);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLMATERIALFV: ;
                args_glMaterialfv argp_glmaterialfv;

                // assert payload size
                if(call.payload_size != sizeof(args_glMaterialfv)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmaterialfv, call.buffer, sizeof(args_glMaterialfv));

                // Execute function call
                glmaterialfv_lh(&argp_glmaterialfv);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLENDLIST: ;
                // assert payload size
                if(call.payload_size != 0){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glendlist_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLSHADEMODEL: ;
                args_glShadeModel argp_glshademodel;

                // assert payload size
                if(call.payload_size != sizeof(args_glShadeModel)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glshademodel, call.buffer, sizeof(args_glShadeModel));

                // Execute function call
                glshademodel_lh(&argp_glshademodel);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLNORMAL3F: ;
                args_glNormal3f argp_glnormal3f;

                // assert payload size
                if(call.payload_size != sizeof(args_glNormal3f)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glnormal3f, call.buffer, sizeof(args_glNormal3f));

                // Execute function call
                glnormal3f_lh(&argp_glnormal3f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLBEGIN: ;
                args_glBegin argp_glbegin;

                // assert payload size
                if(call.payload_size != sizeof(args_glBegin)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glbegin, call.buffer, sizeof(args_glBegin));

                // Execute function call
                glbegin_lh(&argp_glbegin);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLVERTEX3F: ;
                args_glVertex3f argp_glvertex3f;

                // assert payload size
                if(call.payload_size != sizeof(args_glVertex3f)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glvertex3f, call.buffer, sizeof(args_glVertex3f));

                // Execute function call
                glvertex3f_lh(&argp_glvertex3f);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLEND: ;
                // assert payload size
                if(call.payload_size != 0){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glend_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLVIEWPORT: ;
                args_glViewport argp_glviewport;

                // assert payload size
                if(call.payload_size != sizeof(args_glViewport)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glviewport, call.buffer, sizeof(args_glViewport));

                // Execute function call
                glviewport_lh(&argp_glviewport);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLMATRIXMODE: ;
                args_glMatrixMode argp_glmatrixmode;

                // assert payload size
                if(call.payload_size != sizeof(args_glMatrixMode)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glmatrixmode, call.buffer, sizeof(args_glMatrixMode));

                // Execute function call
                glmatrixmode_lh(&argp_glmatrixmode);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLLOADIDENTITY: ;
                // assert payload size
                if(call.payload_size != 0){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glloadidentity_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLFRUSTUM: ;
                args_glFrustum argp_glfrustum;

                // assert payload size
                if(call.payload_size != sizeof(args_glFrustum)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glfrustum, call.buffer, sizeof(args_glFrustum));

                // Execute function call
                glfrustum_lh(&argp_glfrustum);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLTRANSLATEF: ;
                args_glTranslatef argp_gltranslatef;

                // assert payload size
                if(call.payload_size != sizeof(args_glTranslatef)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltranslatef, call.buffer, sizeof(args_glTranslatef));

                // Execute function call
                gltranslatef_lh(&argp_gltranslatef);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLDRAWBUFFER: ;
                args_glDrawBuffer argp_gldrawbuffer;

                // assert payload size
                if(call.payload_size != sizeof(args_glDrawBuffer)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gldrawbuffer, call.buffer, sizeof(args_glDrawBuffer));

                // Execute function call
                gldrawbuffer_lh(&argp_gldrawbuffer);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLPUSHMATRIX: ;
                // assert payload size
                if(call.payload_size != 0){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glpushmatrix_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLPOPMATRIX: ;
                // assert payload size
                if(call.payload_size != 0){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Nothing to copy from Buffer

                // Execute function call
                glpopmatrix_lh();

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLTRANSLATED: ;
                args_glTranslated argp_gltranslated;

                // assert payload size
                if(call.payload_size != sizeof(args_glTranslated)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gltranslated, call.buffer, sizeof(args_glTranslated));

                // Execute function call
                gltranslated_lh(&argp_gltranslated);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLCLEAR: ;
                args_glClear argp_glclear;

                // assert payload size
                if(call.payload_size != sizeof(args_glClear)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glclear, call.buffer, sizeof(args_glClear));

                // Execute function call
                glclear_lh(&argp_glclear);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLROTATEF: ;
                args_glRotatef argp_glrotatef;

                // assert payload size
                if(call.payload_size != sizeof(args_glRotatef)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glrotatef, call.buffer, sizeof(args_glRotatef));

                // Execute function call
                glrotatef_lh(&argp_glrotatef);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLCALLLIST: ;
                args_glCallList argp_glcalllist;

                // assert payload size
                if(call.payload_size != sizeof(args_glCallList)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glcalllist, call.buffer, sizeof(args_glCallList));

                // Execute function call
                glcalllist_lh(&argp_glcalllist);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLDELETELISTS: ;
                args_glDeleteLists argp_gldeletelists;

                // assert payload size
                if(call.payload_size != sizeof(args_glDeleteLists)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_gldeletelists, call.buffer, sizeof(args_glDeleteLists));

                // Execute function call
                gldeletelists_lh(&argp_gldeletelists);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLXDESTROYCONTEXT: ;
                args_glXDestroyContext argp_glxdestroycontext;

                // assert payload size
                if(call.payload_size != sizeof(args_glXDestroyContext)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                argp_glxdestroycontext.dpy = cur_display_p;
                argp_glxdestroycontext.ctx = cur_context;
                memcpy(&argp_glxdestroycontext, call.buffer, sizeof(args_glXDestroyContext));

                // Execute function call
                glxdestroycontext_lh(&argp_glxdestroycontext);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLXCHOOSEVISUAL: ;
                args_glXChooseVisual argp_glxchoosevisual;

                // assert payload size
                if(call.payload_size != sizeof(args_glXChooseVisual)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxchoosevisual, call.buffer, sizeof(args_glXChooseVisual));

                // Execute function call
                argp_glxchoosevisual.dpy = cur_display_p;
                argp_glxchoosevisual.screen = cur_default_screen;
                *cur_vis_info_p = glxchoosevisual_lh(&argp_glxchoosevisual);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLXCREATECONTEXT: ;
                args_glXCreateContext argp_glxcreatecontext;

                // assert payload size
                if(call.payload_size != sizeof(args_glXCreateContext)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxcreatecontext, call.buffer, sizeof(args_glXCreateContext));

                // Execute function call
                argp_glxcreatecontext.dpy = cur_display_p;
                argp_glxcreatecontext.vis = *cur_vis_info_p;
                cur_context = glxcreatecontext_lh(&argp_glxcreatecontext);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLXMAKECURRENT: ;
                args_glXMakeCurrent argp_glxmakecurrent;

                // assert payload size
                if(call.payload_size != sizeof(args_glXMakeCurrent)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxmakecurrent, call.buffer, sizeof(args_glXMakeCurrent));

                // Execute function call
                argp_glxmakecurrent.dpy = cur_display_p;
                argp_glxmakecurrent.drawable = cur_window;
                argp_glxmakecurrent.ctx = cur_context;
                glxmakecurrent_lh(&argp_glxmakecurrent);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLXQUERYEXTENSIONSSTRING: ;
                args_glXQueryExtensionsString argp_glxqueryextensionsstring;

                // assert payload size
                if(call.payload_size != sizeof(args_glXQueryExtensionsString)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxqueryextensionsstring, call.buffer, sizeof(args_glXQueryExtensionsString));

                // Execute function call
                argp_glxqueryextensionsstring.dpy = cur_display_p;
                argp_glxqueryextensionsstring.screen = cur_default_screen;
                glxqueryextensionsstring_lh(&argp_glxqueryextensionsstring);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLXQUERYDRAWABLE: ;
                args_glXQueryDrawable argp_glxquerydrawable;

                // assert payload size
                if(call.payload_size != sizeof(args_glXQueryDrawable)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxquerydrawable, call.buffer, sizeof(args_glXQueryDrawable));

                // Execute function call
                argp_glxquerydrawable.dpy = cur_display_p;
                argp_glxquerydrawable.draw = cur_window;
                glxquerydrawable_lh(&argp_glxquerydrawable);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLXGETPROCADDRESSARB: ;
                args_glXGetProcAddressARB argp_glxgetprocaddressarb;

                // assert payload size
                if(call.payload_size != sizeof(args_glXGetProcAddressARB)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxgetprocaddressarb, call.buffer, sizeof(args_glXGetProcAddressARB));

                // Execute function call
                glxgetprocaddressarb_lh(&argp_glxgetprocaddressarb);

                // Print
                printf("RESPONSE: Data type: %d\n\n", resp.data_type);
                break;

            case GLXSWAPBUFFERS: ;
                args_glXSwapBuffers argp_glxswapbuffers;

                // assert payload size
                if(call.payload_size != sizeof(args_glXSwapBuffers)){
                    printf("Wrong payload size\n\n");
                    break;
                }

                // Memcopy from Buffer
                memcpy(&argp_glxswapbuffers, call.buffer, sizeof(args_glXSwapBuffers));

                // Execute function call
                argp_glxswapbuffers.dpy = cur_display_p;
                argp_glxswapbuffers.drawable = cur_window;
                glxswapbuffers_lh(&argp_glxswapbuffers);

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
