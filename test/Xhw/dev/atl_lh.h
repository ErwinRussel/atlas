//
// Created by erwinrussel on 5/13/22.
//

#ifndef ATLAS_ATL_LH_H
#define ATLAS_ATL_LH_H

#endif //ATLAS_ATL_LH_H

Display* xopendisplay_lh(args_XOpenDisplay *argp);
Window xcreatesimplewindow_lh(args_XCreateSimpleWindow *argp);
int xmapwindow_lh(args_XMapWindow *argp);
int xselectinput_lh(args_XSelectInput *argp);
XEvent xnextevent_lh(args_XNextEvent *argp);
Window xdefaultrootwindow_lh(args_XDefaultRootWindow *argp);