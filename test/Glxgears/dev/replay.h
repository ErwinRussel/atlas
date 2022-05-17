//
// Created by erwinrussel on 5/17/22.
//

#ifndef ATLAS_REPLAY_H
#define ATLAS_REPLAY_H

#endif //ATLAS_REPLAY_H

// Translation vars
Display* cur_display_p;
Window cur_window;
Window cur_root_window;
XVisualInfo* cur_vis_info_p;
int cur_default_screen;
Colormap cur_colormap;
GLXContext cur_context;

// Expose replay function
int replay_log();

// StrgBlock
struct StrgBlock {
    message_types message_type;
    data_types data_type;
    int payload_size;
    char buffer[SHMEM_BUFF];
};