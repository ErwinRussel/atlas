
#ifndef ATLAS_ATL_UH_H
#define ATLAS_ATL_UH_H

#endif //ATLAS_ATL_UH_H
int xdefaultscreen_uh(args_XDefaultScreen argp);
int xdisplaywidth_uh(args_XDisplayWidth argp);
int xdisplayheight_uh(args_XDisplayHeight argp);
Window xrootwindow_uh(args_XRootWindow argp);
Display* xopendisplay_uh(args_XOpenDisplay argp);
Colormap xcreatecolormap_uh(args_XCreateColormap argp);
Window xcreatewindow_uh(args_XCreateWindow argp);
Atom xinternatom_uh(args_XInternAtom argp);
int xchangeproperty_uh(args_XChangeProperty argp);
int xsetnormalhints_uh(args_XSetNormalHints argp);
int xsetstandardproperties_uh(args_XSetStandardProperties argp);
int xfree_uh(args_XFree argp);
int xmapwindow_uh(args_XMapWindow argp);
int xpending_uh(args_XPending argp);
XEvent xnextevent_uh(args_XNextEvent argp);
KeySym xlookupkeysym_uh(args_XLookupKeysym argp);
int xlookupstring_uh(args_XLookupString argp);
int xdestroywindow_uh(args_XDestroyWindow argp);
GLubyte* glgetstring_uh(args_glGetString argp);
void gllightfv_uh(args_glLightfv argp);
void glenable_uh(args_glEnable argp);
GLuint glgenlists_uh(args_glGenLists argp);
void glnewlist_uh(args_glNewList argp);
void glmaterialfv_uh(args_glMaterialfv argp);
void glendlist_uh();
void glshademodel_uh(args_glShadeModel argp);
void glnormal3f_uh(args_glNormal3f argp);
void glbegin_uh(args_glBegin argp);
void glvertex3f_uh(args_glVertex3f argp);
void glend_uh();
void glviewport_uh(args_glViewport argp);
void glmatrixmode_uh(args_glMatrixMode argp);
void glloadidentity_uh();
void glfrustum_uh(args_glFrustum argp);
void gltranslatef_uh(args_glTranslatef argp);
void gldrawbuffer_uh(args_glDrawBuffer argp);
void glpushmatrix_uh();
void glpopmatrix_uh();
void gltranslated_uh(args_glTranslated argp);
void glclear_uh(args_glClear argp);
void glrotatef_uh(args_glRotatef argp);
void glcalllist_uh(args_glCallList argp);
void gldeletelists_uh(args_glDeleteLists argp);
void glxdestroycontext_uh(args_glXDestroyContext argp);
XVisualInfo glxchoosevisual_uh(args_glXChooseVisual argp);
GLXContext glxcreatecontext_uh(args_glXCreateContext argp);
Bool glxmakecurrent_uh(args_glXMakeCurrent argp);
char* glxqueryextensionsstring_uh(args_glXQueryExtensionsString argp);
void glxquerydrawable_uh(args_glXQueryDrawable argp);
__GLXextFuncPtr glxgetprocaddressarb_uh(args_glXGetProcAddressARB argp);
void glxswapbuffers_uh(args_glXSwapBuffers argp);
