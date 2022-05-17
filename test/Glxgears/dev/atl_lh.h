//
// Created by erwinrussel on 5/15/22.
//

#ifndef ATLAS_ATL_LH_H
#define ATLAS_ATL_LH_H

#endif //ATLAS_ATL_LH_H

// Function spec
int xdefaultscreen_lh(args_XDefaultScreen *argp);
int xdisplaywidth_lh(args_XDisplayWidth *argp);
int xdisplayheight_lh(args_XDisplayHeight *argp);
Window xrootwindow_lh(args_XRootWindow *argp);
Display* xopendisplay_lh(args_XOpenDisplay *argp);
Colormap xcreatecolormap_lh(args_XCreateColormap *argp);
Window xcreatewindow_lh(args_XCreateWindow *argp);
Atom xinternatom_lh(args_XInternAtom *argp);
int xchangeproperty_lh(args_XChangeProperty *argp);
int xsetnormalhints_lh(args_XSetNormalHints *argp);
int xsetstandardproperties_lh(args_XSetStandardProperties *argp);
int xfree_lh(args_XFree *argp);
int xmapwindow_lh(args_XMapWindow *argp);
int xpending_lh(args_XPending *argp);
XEvent *xnextevent_lh(args_XNextEvent *argp);
KeySym xlookupkeysym_lh(args_XLookupKeysym *argp);
int xlookupstring_lh(args_XLookupString *argp);
int xdestroywindow_lh(args_XDestroyWindow *argp);
GLubyte* glgetstring_lh(args_glGetString *argp);
void gllightfv_lh(args_glLightfv *argp);
void glenable_lh(args_glEnable *argp);
GLuint glgenlists_lh(args_glGenLists *argp);
void glnewlist_lh(args_glNewList *argp);
void glmaterialfv_lh(args_glMaterialfv *argp);
void glendlist_lh();
void glshademodel_lh(args_glShadeModel *argp);
void glnormal3f_lh(args_glNormal3f *argp);
void glbegin_lh(args_glBegin *argp);
void glvertex3f_lh(args_glVertex3f *argp);
void glend_lh();
void glviewport_lh(args_glViewport *argp);
void glmatrixmode_lh(args_glMatrixMode *argp);
void glloadidentity_lh();
void glfrustum_lh(args_glFrustum *argp);
void gltranslatef_lh(args_glTranslatef *argp);
void gldrawbuffer_lh(args_glDrawBuffer *argp);
void glpushmatrix_lh();
void glpopmatrix_lh();
void gltranslated_lh(args_glTranslated *argp);
void glclear_lh(args_glClear *argp);
void glrotatef_lh(args_glRotatef *argp);
void glcalllist_lh(args_glCallList *argp);
void gldeletelists_lh(args_glDeleteLists *argp);
void glxdestroycontext_lh(args_glXDestroyContext *argp);
XVisualInfo glxchoosevisual_lh(args_glXChooseVisual *argp);
GLXContext glxcreatecontext_lh(args_glXCreateContext *argp);
Bool glxmakecurrent_lh(args_glXMakeCurrent *argp);
char* glxqueryextensionsstring_lh(args_glXQueryExtensionsString *argp);
void glxquerydrawable_lh(args_glXQueryDrawable *argp);
__GLXextFuncPtr glxgetprocaddressarb_lh(args_glXGetProcAddressARB *argp);
void glxswapbuffers_lh(args_glXSwapBuffers *argp);
