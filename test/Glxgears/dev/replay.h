//
// Created by erwinrussel on 5/17/22.
//
#ifndef ATLAS_REPLAY_H
#define ATLAS_REPLAY_H

#endif //ATLAS_REPLAY_H

// Translation vars
extern Display* cur_display_p;
extern Window cur_window;
extern Window cur_root_window;
extern XVisualInfo* cur_vis_info_p;
extern int cur_default_screen;
extern Colormap cur_colormap;
extern GLXContext cur_context;
extern XSizeHints cur_hints;

// Expose replay function
int replay_log();

// StrgBlock
//struct StrgBlock {
//    message_types message_type;
//    data_types data_type;
//    int payload_size;
//    char buffer[SHMEM_BUFF];
//};