
#ifndef ATLAS_ATL_UH_H
#define ATLAS_ATL_UH_H

#endif //ATLAS_ATL_UH_H
Display* xopendisplay_uh(args_XOpenDisplay argp);
Window xcreatewindow_uh(args_XCreateWindow argp);
int xmapwindow_uh(args_XMapWindow argp);
int xifevent_uh(args_XIfEvent argp);
int xdefaultscreen_uh(args_XDefaultScreen argp);
Window xrootwindow_uh(args_XRootWindow argp);
void glclearcolor_uh(args_glClearColor argp);
void glclear_uh(args_glClear argp);
void glflush_uh();
GLXFBConfig glxchoosefbconfig_uh(args_glXChooseFBConfig argp);
XVisualInfo glxgetvisualfromfbconfig_uh(args_glXGetVisualFromFBConfig argp);
GLXContext glxcreatenewcontext_uh(args_glXCreateNewContext argp);
GLXWindow glxcreatewindow_uh(args_glXCreateWindow argp);
Bool glxmakecontextcurrent_uh(args_glXMakeContextCurrent argp);
void glxswapbuffers_uh(args_glXSwapBuffers argp);
Colormap xcreatecolormap_uh(args_XCreateColormap argp);
