#ifndef ATLAS_STUB_HEADER_H
#define ATLAS_STUB_HEADER_H

#endif //ATLAS_STUB_HEADER_H

#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glx.h>

// Dynamic mem buffer, buffer size in ints
#define SHMEM_BUFF 1024

// Status flags -> should be enum?
#define  REQUEST       1
#define  RESPONSE      2
#define  LISTEN        0

typedef enum {
    FUNC_CALL,
    FUNC_RETURN
} message_types;

typedef enum {
    XOPENDISPLAY,
	DISPLAYP,
	XPENDING,
	INT,
	XMAPWINDOW,
	XCREATECOLORMAP,
	COLORMAP,
	XCREATEWINDOW,
	WINDOW,
	XFREE,
	XSETNORMALHINTS,
	XSETSTANDARDPROPERTIES,
	GLCLEARINDEX,
	VOID,
	GLCLEARCOLOR,
	GLCLEAR,
	GLINDEXMASK,
	GLCOLORMASK,
	GLALPHAFUNC,
	GLBLENDFUNC,
	GLLOGICOP,
	GLCULLFACE,
	GLFRONTFACE,
	GLPOINTSIZE,
	GLLINEWIDTH,
	GLLINESTIPPLE,
	GLPOLYGONMODE,
	GLPOLYGONOFFSET,
	GLPOLYGONSTIPPLE,
	GLGETPOLYGONSTIPPLE,
	GLEDGEFLAG,
	GLEDGEFLAGV,
	GLSCISSOR,
	GLCLIPPLANE,
	GLGETCLIPPLANE,
	GLDRAWBUFFER,
	GLREADBUFFER,
	GLENABLE,
	GLDISABLE,
	GLISENABLED,
	GLBOOLEAN,
	GLENABLECLIENTSTATE,
	GLDISABLECLIENTSTATE,
	GLGETBOOLEANV,
	GLGETDOUBLEV,
	GLGETFLOATV,
	GLGETINTEGERV,
	GLPUSHATTRIB,
	GLPOPATTRIB,
	GLPUSHCLIENTATTRIB,
	GLPOPCLIENTATTRIB,
	GLRENDERMODE,
	GLINT,
	GLFINISH,
	GLFLUSH,
	GLHINT,
	GLCLEARDEPTH,
	GLDEPTHFUNC,
	GLDEPTHMASK,
	GLDEPTHRANGE,
	GLCLEARACCUM,
	GLACCUM,
	GLMATRIXMODE,
	GLORTHO,
	GLFRUSTUM,
	GLVIEWPORT,
	GLPUSHMATRIX,
	GLPOPMATRIX,
	GLLOADIDENTITY,
	GLLOADMATRIXD,
	GLLOADMATRIXF,
	GLMULTMATRIXD,
	GLMULTMATRIXF,
	GLROTATED,
	GLROTATEF,
	GLSCALED,
	GLSCALEF,
	GLTRANSLATED,
	GLTRANSLATEF,
	GLISLIST,
	GLDELETELISTS,
	GLGENLISTS,
	GLUINT,
	GLNEWLIST,
	GLENDLIST,
	GLCALLLIST,
	GLCALLLISTS,
	GLLISTBASE,
	GLBEGIN,
	GLEND,
	GLVERTEX2D,
	GLVERTEX2F,
	GLVERTEX2I,
	GLVERTEX2S,
	GLVERTEX3D,
	GLVERTEX3F,
	GLVERTEX3I,
	GLVERTEX3S,
	GLVERTEX4D,
	GLVERTEX4F,
	GLVERTEX4I,
	GLVERTEX4S,
	GLVERTEX2DV,
	GLVERTEX2FV,
	GLVERTEX2IV,
	GLVERTEX2SV,
	GLVERTEX3DV,
	GLVERTEX3FV,
	GLVERTEX3IV,
	GLVERTEX3SV,
	GLVERTEX4DV,
	GLVERTEX4FV,
	GLVERTEX4IV,
	GLVERTEX4SV,
	GLNORMAL3B,
	GLNORMAL3D,
	GLNORMAL3F,
	GLNORMAL3I,
	GLNORMAL3S,
	GLNORMAL3BV,
	GLNORMAL3DV,
	GLNORMAL3FV,
	GLNORMAL3IV,
	GLNORMAL3SV,
	GLINDEXD,
	GLINDEXF,
	GLINDEXI,
	GLINDEXS,
	GLINDEXUB,
	GLINDEXDV,
	GLINDEXFV,
	GLINDEXIV,
	GLINDEXSV,
	GLINDEXUBV,
	GLCOLOR3B,
	GLCOLOR3D,
	GLCOLOR3F,
	GLCOLOR3I,
	GLCOLOR3S,
	GLCOLOR3UB,
	GLCOLOR3UI,
	GLCOLOR3US,
	GLCOLOR4B,
	GLCOLOR4D,
	GLCOLOR4F,
	GLCOLOR4I,
	GLCOLOR4S,
	GLCOLOR4UB,
	GLCOLOR4UI,
	GLCOLOR4US,
	GLCOLOR3BV,
	GLCOLOR3DV,
	GLCOLOR3FV,
	GLCOLOR3IV,
	GLCOLOR3SV,
	GLCOLOR3UBV,
	GLCOLOR3UIV,
	GLCOLOR3USV,
	GLCOLOR4BV,
	GLCOLOR4DV,
	GLCOLOR4FV,
	GLCOLOR4IV,
	GLCOLOR4SV,
	GLCOLOR4UBV,
	GLCOLOR4UIV,
	GLCOLOR4USV,
	GLTEXCOORD1D,
	GLTEXCOORD1F,
	GLTEXCOORD1I,
	GLTEXCOORD1S,
	GLTEXCOORD2D,
	GLTEXCOORD2F,
	GLTEXCOORD2I,
	GLTEXCOORD2S,
	GLTEXCOORD3D,
	GLTEXCOORD3F,
	GLTEXCOORD3I,
	GLTEXCOORD3S,
	GLTEXCOORD4D,
	GLTEXCOORD4F,
	GLTEXCOORD4I,
	GLTEXCOORD4S,
	GLTEXCOORD1DV,
	GLTEXCOORD1FV,
	GLTEXCOORD1IV,
	GLTEXCOORD1SV,
	GLTEXCOORD2DV,
	GLTEXCOORD2FV,
	GLTEXCOORD2IV,
	GLTEXCOORD2SV,
	GLTEXCOORD3DV,
	GLTEXCOORD3FV,
	GLTEXCOORD3IV,
	GLTEXCOORD3SV,
	GLTEXCOORD4DV,
	GLTEXCOORD4FV,
	GLTEXCOORD4IV,
	GLTEXCOORD4SV,
	GLRASTERPOS2D,
	GLRASTERPOS2F,
	GLRASTERPOS2I,
	GLRASTERPOS2S,
	GLRASTERPOS3D,
	GLRASTERPOS3F,
	GLRASTERPOS3I,
	GLRASTERPOS3S,
	GLRASTERPOS4D,
	GLRASTERPOS4F,
	GLRASTERPOS4I,
	GLRASTERPOS4S,
	GLRASTERPOS2DV,
	GLRASTERPOS2FV,
	GLRASTERPOS2IV,
	GLRASTERPOS2SV,
	GLRASTERPOS3DV,
	GLRASTERPOS3FV,
	GLRASTERPOS3IV,
	GLRASTERPOS3SV,
	GLRASTERPOS4DV,
	GLRASTERPOS4FV,
	GLRASTERPOS4IV,
	GLRASTERPOS4SV,
	GLRECTD,
	GLRECTF,
	GLRECTI,
	GLRECTS,
	GLRECTDV,
	GLRECTFV,
	GLRECTIV,
	GLRECTSV,
	GLVERTEXPOINTER,
	GLNORMALPOINTER,
	GLCOLORPOINTER,
	GLINDEXPOINTER,
	GLTEXCOORDPOINTER,
	GLEDGEFLAGPOINTER,
	GLGETPOINTERV,
	GLARRAYELEMENT,
	GLDRAWARRAYS,
	GLDRAWELEMENTS,
	GLINTERLEAVEDARRAYS,
	GLSHADEMODEL,
	GLLIGHTF,
	GLLIGHTI,
	GLLIGHTFV,
	GLLIGHTIV,
	GLGETLIGHTFV,
	GLGETLIGHTIV,
	GLLIGHTMODELF,
	GLLIGHTMODELI,
	GLLIGHTMODELFV,
	GLLIGHTMODELIV,
	GLMATERIALF,
	GLMATERIALI,
	GLMATERIALFV,
	GLMATERIALIV,
	GLGETMATERIALFV,
	GLGETMATERIALIV,
	GLCOLORMATERIAL,
	GLPIXELZOOM,
	GLPIXELSTOREF,
	GLPIXELSTOREI,
	GLPIXELTRANSFERF,
	GLPIXELTRANSFERI,
	GLPIXELMAPFV,
	GLPIXELMAPUIV,
	GLPIXELMAPUSV,
	GLGETPIXELMAPFV,
	GLGETPIXELMAPUIV,
	GLGETPIXELMAPUSV,
	GLBITMAP,
	GLREADPIXELS,
	GLDRAWPIXELS,
	GLCOPYPIXELS,
	GLSTENCILFUNC,
	GLSTENCILMASK,
	GLSTENCILOP,
	GLCLEARSTENCIL,
	GLTEXGEND,
	GLTEXGENF,
	GLTEXGENI,
	GLTEXGENDV,
	GLTEXGENFV,
	GLTEXGENIV,
	GLGETTEXGENDV,
	GLGETTEXGENFV,
	GLGETTEXGENIV,
	GLTEXENVF,
	GLTEXENVI,
	GLTEXENVFV,
	GLTEXENVIV,
	GLGETTEXENVFV,
	GLGETTEXENVIV,
	GLTEXPARAMETERF,
	GLTEXPARAMETERI,
	GLTEXPARAMETERFV,
	GLTEXPARAMETERIV,
	GLGETTEXPARAMETERFV,
	GLGETTEXPARAMETERIV,
	GLGETTEXLEVELPARAMETERFV,
	GLGETTEXLEVELPARAMETERIV,
	GLTEXIMAGE1D,
	GLTEXIMAGE2D,
	GLGETTEXIMAGE,
	GLGENTEXTURES,
	GLDELETETEXTURES,
	GLBINDTEXTURE,
	GLPRIORITIZETEXTURES,
	GLARETEXTURESRESIDENT,
	GLISTEXTURE,
	GLTEXSUBIMAGE1D,
	GLTEXSUBIMAGE2D,
	GLCOPYTEXIMAGE1D,
	GLCOPYTEXIMAGE2D,
	GLCOPYTEXSUBIMAGE1D,
	GLCOPYTEXSUBIMAGE2D,
	GLMAP1D,
	GLMAP1F,
	GLMAP2D,
	GLMAP2F,
	GLGETMAPDV,
	GLGETMAPFV,
	GLGETMAPIV,
	GLEVALCOORD1D,
	GLEVALCOORD1F,
	GLEVALCOORD1DV,
	GLEVALCOORD1FV,
	GLEVALCOORD2D,
	GLEVALCOORD2F,
	GLEVALCOORD2DV,
	GLEVALCOORD2FV,
	GLMAPGRID1D,
	GLMAPGRID1F,
	GLMAPGRID2D,
	GLMAPGRID2F,
	GLEVALPOINT1,
	GLEVALPOINT2,
	GLEVALMESH1,
	GLEVALMESH2,
	GLFOGF,
	GLFOGI,
	GLFOGFV,
	GLFOGIV,
	GLFEEDBACKBUFFER,
	GLPASSTHROUGH,
	GLSELECTBUFFER,
	GLINITNAMES,
	GLLOADNAME,
	GLPUSHNAME,
	GLPOPNAME,
	GLDRAWRANGEELEMENTS,
	GLTEXIMAGE3D,
	GLTEXSUBIMAGE3D,
	GLCOPYTEXSUBIMAGE3D,
	GLCOLORTABLE,
	GLCOLORSUBTABLE,
	GLCOLORTABLEPARAMETERIV,
	GLCOLORTABLEPARAMETERFV,
	GLCOPYCOLORSUBTABLE,
	GLCOPYCOLORTABLE,
	GLGETCOLORTABLE,
	GLGETCOLORTABLEPARAMETERFV,
	GLGETCOLORTABLEPARAMETERIV,
	GLBLENDEQUATION,
	GLBLENDCOLOR,
	GLHISTOGRAM,
	GLRESETHISTOGRAM,
	GLGETHISTOGRAM,
	GLGETHISTOGRAMPARAMETERFV,
	GLGETHISTOGRAMPARAMETERIV,
	GLMINMAX,
	GLRESETMINMAX,
	GLGETMINMAX,
	GLGETMINMAXPARAMETERFV,
	GLGETMINMAXPARAMETERIV,
	GLCONVOLUTIONFILTER1D,
	GLCONVOLUTIONFILTER2D,
	GLCONVOLUTIONPARAMETERF,
	GLCONVOLUTIONPARAMETERFV,
	GLCONVOLUTIONPARAMETERI,
	GLCONVOLUTIONPARAMETERIV,
	GLCOPYCONVOLUTIONFILTER1D,
	GLCOPYCONVOLUTIONFILTER2D,
	GLGETCONVOLUTIONFILTER,
	GLGETCONVOLUTIONPARAMETERFV,
	GLGETCONVOLUTIONPARAMETERIV,
	GLSEPARABLEFILTER2D,
	GLGETSEPARABLEFILTER,
	GLACTIVETEXTURE,
	GLCLIENTACTIVETEXTURE,
	GLCOMPRESSEDTEXIMAGE1D,
	GLCOMPRESSEDTEXIMAGE2D,
	GLCOMPRESSEDTEXIMAGE3D,
	GLCOMPRESSEDTEXSUBIMAGE1D,
	GLCOMPRESSEDTEXSUBIMAGE2D,
	GLCOMPRESSEDTEXSUBIMAGE3D,
	GLGETCOMPRESSEDTEXIMAGE,
	GLMULTITEXCOORD1D,
	GLMULTITEXCOORD1DV,
	GLMULTITEXCOORD1F,
	GLMULTITEXCOORD1FV,
	GLMULTITEXCOORD1I,
	GLMULTITEXCOORD1IV,
	GLMULTITEXCOORD1S,
	GLMULTITEXCOORD1SV,
	GLMULTITEXCOORD2D,
	GLMULTITEXCOORD2DV,
	GLMULTITEXCOORD2F,
	GLMULTITEXCOORD2FV,
	GLMULTITEXCOORD2I,
	GLMULTITEXCOORD2IV,
	GLMULTITEXCOORD2S,
	GLMULTITEXCOORD2SV,
	GLMULTITEXCOORD3D,
	GLMULTITEXCOORD3DV,
	GLMULTITEXCOORD3F,
	GLMULTITEXCOORD3FV,
	GLMULTITEXCOORD3I,
	GLMULTITEXCOORD3IV,
	GLMULTITEXCOORD3S,
	GLMULTITEXCOORD3SV,
	GLMULTITEXCOORD4D,
	GLMULTITEXCOORD4DV,
	GLMULTITEXCOORD4F,
	GLMULTITEXCOORD4FV,
	GLMULTITEXCOORD4I,
	GLMULTITEXCOORD4IV,
	GLMULTITEXCOORD4S,
	GLMULTITEXCOORD4SV,
	GLSAMPLECOVERAGE,
	GLACTIVETEXTUREARB,
	GLCLIENTACTIVETEXTUREARB,
	GLMULTITEXCOORD1DARB,
	GLMULTITEXCOORD1DVARB,
	GLMULTITEXCOORD1FARB,
	GLMULTITEXCOORD1FVARB,
	GLMULTITEXCOORD1IARB,
	GLMULTITEXCOORD1IVARB,
	GLMULTITEXCOORD1SARB,
	GLMULTITEXCOORD1SVARB,
	GLMULTITEXCOORD2DARB,
	GLMULTITEXCOORD2DVARB,
	GLMULTITEXCOORD2FARB,
	GLMULTITEXCOORD2FVARB,
	GLMULTITEXCOORD2IARB,
	GLMULTITEXCOORD2IVARB,
	GLMULTITEXCOORD2SARB,
	GLMULTITEXCOORD2SVARB,
	GLMULTITEXCOORD3DARB,
	GLMULTITEXCOORD3DVARB,
	GLMULTITEXCOORD3FARB,
	GLMULTITEXCOORD3FVARB,
	GLMULTITEXCOORD3IARB,
	GLMULTITEXCOORD3IVARB,
	GLMULTITEXCOORD3SARB,
	GLMULTITEXCOORD3SVARB,
	GLMULTITEXCOORD4DARB,
	GLMULTITEXCOORD4DVARB,
	GLMULTITEXCOORD4FARB,
	GLMULTITEXCOORD4FVARB,
	GLMULTITEXCOORD4IARB,
	GLMULTITEXCOORD4IVARB,
	GLMULTITEXCOORD4SARB,
	GLMULTITEXCOORD4SVARB,
	GLXCHOOSEVISUAL,
	XVISUALINFOP,
	GLXQUERYDRAWABLE,
	GLXCREATECONTEXT,
	GLXCONTEXT,
	GLXCREATECONTEXT,
	GLXDESTROYCONTEXT,
	GLXSWAPBUFFERS,
	GLXDESTROYGLXPIXMAP,
	GLXQUERYEXTENSION,
	BOOL,
	GLXQUERYVERSION,
	GLXISDIRECT,
	GLXGETCURRENTCONTEXT,
	GLXGETCURRENTDRAWABLE,
	GLXDRAWABLE,
	GLXWAITGL,
	GLXWAITX,
	GLXUSEXFONT,
	GLXQUERYEXTENSIONSSTRING,
	CHARP,
	GLXGETCURRENTDISPLAY,
	GLXDESTROYWINDOW,
	GLXDESTROYPIXMAP,
	GLXDESTROYPBUFFER,
	GLXGETCURRENTREADDRAWABLE,
	GLXGETPROCADDRESSARB,
	__GLXEXTFUNCPTR,
	GLXGETPROCADDRESS,
	VOIDP,
	GLXALLOCATEMEMORYNV,
	GLXFREEMEMORYNV
} data_types;

// Create messageblock after declaration of data_types
struct MsgBlock {
    int  status;
    message_types message_type;
    data_types data_type;
    int payload_size;
    char buffer[SHMEM_BUFF];
};

// Function arg structs


// -- XOpenDisplay
struct args_XOpenDisplay{
    _Xconst char *display_name;
};

typedef struct args_XOpenDisplay args_XOpenDisplay;


// -- XPending
struct args_XPending{
    Display *display;
};

typedef struct args_XPending args_XPending;


// -- XMapWindow
struct args_XMapWindow{
    Display *display;
	 Window w;
};

typedef struct args_XMapWindow args_XMapWindow;


// -- XCreateColormap
struct args_XCreateColormap{
    Display* display;
	 Window w;
	 Visual*	visual;
	 int	alloc ;
};

typedef struct args_XCreateColormap args_XCreateColormap;


// -- XCreateWindow
struct args_XCreateWindow{
    Display* display;
	 Window parent;
	 int x;
	 int y;
	 unsigned int width;
	 unsigned int height;
	 unsigned int border_width;
	 int	depth;
	 unsigned int class;
	 Visual* visual;
	 unsigned long valuemask;
	 XSetWindowAttributes* attributes;
};

typedef struct args_XCreateWindow args_XCreateWindow;


// -- XFree
struct args_XFree{
    void* data;
};

typedef struct args_XFree args_XFree;


// -- XSetNormalHints
struct args_XSetNormalHints{
    Display *display;
	 Window w;
	 XSizeHints *hints;
};

typedef struct args_XSetNormalHints args_XSetNormalHints;


// -- XSetStandardProperties
struct args_XSetStandardProperties{
    Display *display;
	 Window w;
	 _Xconst char *window_name;
	 _Xconst char *icon_name;
	 Pixmap icon_pixmap;
	 char **argv;
	 int argc;
	 XSizeHints *hints;
};

typedef struct args_XSetStandardProperties args_XSetStandardProperties;


// -- glClearIndex
struct args_glClearIndex{
     GLfloat c ;
};

typedef struct args_glClearIndex args_glClearIndex;


// -- glClearColor
struct args_glClearColor{
     GLclampf red;
	 GLclampf green;
	 GLclampf blue;
	 GLclampf alpha ;
};

typedef struct args_glClearColor args_glClearColor;


// -- glClear
struct args_glClear{
     GLbitfield mask ;
};

typedef struct args_glClear args_glClear;


// -- glIndexMask
struct args_glIndexMask{
     GLuint mask ;
};

typedef struct args_glIndexMask args_glIndexMask;


// -- glColorMask
struct args_glColorMask{
     GLboolean red;
	 GLboolean green;
	 GLboolean blue;
	 GLboolean alpha ;
};

typedef struct args_glColorMask args_glColorMask;


// -- glAlphaFunc
struct args_glAlphaFunc{
     GLenum func;
	 GLclampf ref ;
};

typedef struct args_glAlphaFunc args_glAlphaFunc;


// -- glBlendFunc
struct args_glBlendFunc{
     GLenum sfactor;
	 GLenum dfactor ;
};

typedef struct args_glBlendFunc args_glBlendFunc;


// -- glLogicOp
struct args_glLogicOp{
     GLenum opcode ;
};

typedef struct args_glLogicOp args_glLogicOp;


// -- glCullFace
struct args_glCullFace{
     GLenum mode ;
};

typedef struct args_glCullFace args_glCullFace;


// -- glFrontFace
struct args_glFrontFace{
     GLenum mode ;
};

typedef struct args_glFrontFace args_glFrontFace;


// -- glPointSize
struct args_glPointSize{
     GLfloat size ;
};

typedef struct args_glPointSize args_glPointSize;


// -- glLineWidth
struct args_glLineWidth{
     GLfloat width ;
};

typedef struct args_glLineWidth args_glLineWidth;


// -- glLineStipple
struct args_glLineStipple{
     GLint factor;
	 GLushort pattern ;
};

typedef struct args_glLineStipple args_glLineStipple;


// -- glPolygonMode
struct args_glPolygonMode{
     GLenum face;
	 GLenum mode ;
};

typedef struct args_glPolygonMode args_glPolygonMode;


// -- glPolygonOffset
struct args_glPolygonOffset{
     GLfloat factor;
	 GLfloat units ;
};

typedef struct args_glPolygonOffset args_glPolygonOffset;


// -- glPolygonStipple
struct args_glPolygonStipple{
     const GLubyte *mask ;
};

typedef struct args_glPolygonStipple args_glPolygonStipple;


// -- glGetPolygonStipple
struct args_glGetPolygonStipple{
     GLubyte *mask ;
};

typedef struct args_glGetPolygonStipple args_glGetPolygonStipple;


// -- glEdgeFlag
struct args_glEdgeFlag{
     GLboolean flag ;
};

typedef struct args_glEdgeFlag args_glEdgeFlag;


// -- glEdgeFlagv
struct args_glEdgeFlagv{
     const GLboolean *flag ;
};

typedef struct args_glEdgeFlagv args_glEdgeFlagv;


// -- glScissor
struct args_glScissor{
     GLint x;
	 GLint y;
	 GLsizei width;
	 GLsizei height;
};

typedef struct args_glScissor args_glScissor;


// -- glClipPlane
struct args_glClipPlane{
     GLenum plane;
	 const GLdouble *equation ;
};

typedef struct args_glClipPlane args_glClipPlane;


// -- glGetClipPlane
struct args_glGetClipPlane{
     GLenum plane;
	 GLdouble *equation ;
};

typedef struct args_glGetClipPlane args_glGetClipPlane;


// -- glDrawBuffer
struct args_glDrawBuffer{
     GLenum mode ;
};

typedef struct args_glDrawBuffer args_glDrawBuffer;


// -- glReadBuffer
struct args_glReadBuffer{
     GLenum mode ;
};

typedef struct args_glReadBuffer args_glReadBuffer;


// -- glEnable
struct args_glEnable{
     GLenum cap ;
};

typedef struct args_glEnable args_glEnable;


// -- glDisable
struct args_glDisable{
     GLenum cap ;
};

typedef struct args_glDisable args_glDisable;


// -- glIsEnabled
struct args_glIsEnabled{
     GLenum cap ;
};

typedef struct args_glIsEnabled args_glIsEnabled;


// -- glEnableClientState
struct args_glEnableClientState{
     GLenum cap ;
};

typedef struct args_glEnableClientState args_glEnableClientState;


// -- glDisableClientState
struct args_glDisableClientState{
     GLenum cap ;
};

typedef struct args_glDisableClientState args_glDisableClientState;


// -- glGetBooleanv
struct args_glGetBooleanv{
     GLenum pname;
	 GLboolean *params ;
};

typedef struct args_glGetBooleanv args_glGetBooleanv;


// -- glGetDoublev
struct args_glGetDoublev{
     GLenum pname;
	 GLdouble *params ;
};

typedef struct args_glGetDoublev args_glGetDoublev;


// -- glGetFloatv
struct args_glGetFloatv{
     GLenum pname;
	 GLfloat *params ;
};

typedef struct args_glGetFloatv args_glGetFloatv;


// -- glGetIntegerv
struct args_glGetIntegerv{
     GLenum pname;
	 GLint *params ;
};

typedef struct args_glGetIntegerv args_glGetIntegerv;


// -- glPushAttrib
struct args_glPushAttrib{
     GLbitfield mask ;
};

typedef struct args_glPushAttrib args_glPushAttrib;


// -- glPushClientAttrib
struct args_glPushClientAttrib{
     GLbitfield mask ;
};

typedef struct args_glPushClientAttrib args_glPushClientAttrib;


// -- glRenderMode
struct args_glRenderMode{
     GLenum mode ;
};

typedef struct args_glRenderMode args_glRenderMode;


// -- glHint
struct args_glHint{
     GLenum target;
	 GLenum mode ;
};

typedef struct args_glHint args_glHint;


// -- glClearDepth
struct args_glClearDepth{
     GLclampd depth ;
};

typedef struct args_glClearDepth args_glClearDepth;


// -- glDepthFunc
struct args_glDepthFunc{
     GLenum func ;
};

typedef struct args_glDepthFunc args_glDepthFunc;


// -- glDepthMask
struct args_glDepthMask{
     GLboolean flag ;
};

typedef struct args_glDepthMask args_glDepthMask;


// -- glDepthRange
struct args_glDepthRange{
     GLclampd near_val;
	 GLclampd far_val ;
};

typedef struct args_glDepthRange args_glDepthRange;


// -- glClearAccum
struct args_glClearAccum{
     GLfloat red;
	 GLfloat green;
	 GLfloat blue;
	 GLfloat alpha ;
};

typedef struct args_glClearAccum args_glClearAccum;


// -- glAccum
struct args_glAccum{
     GLenum op;
	 GLfloat value ;
};

typedef struct args_glAccum args_glAccum;


// -- glMatrixMode
struct args_glMatrixMode{
     GLenum mode ;
};

typedef struct args_glMatrixMode args_glMatrixMode;


// -- glOrtho
struct args_glOrtho{
     GLdouble left;
	 GLdouble right;
	 GLdouble bottom;
	 GLdouble top;
	 GLdouble near_val;
	 GLdouble far_val ;
};

typedef struct args_glOrtho args_glOrtho;


// -- glFrustum
struct args_glFrustum{
     GLdouble left;
	 GLdouble right;
	 GLdouble bottom;
	 GLdouble top;
	 GLdouble near_val;
	 GLdouble far_val ;
};

typedef struct args_glFrustum args_glFrustum;


// -- glViewport
struct args_glViewport{
     GLint x;
	 GLint y;
	 GLsizei width;
	 GLsizei height ;
};

typedef struct args_glViewport args_glViewport;


// -- glLoadMatrixd
struct args_glLoadMatrixd{
     const GLdouble *m ;
};

typedef struct args_glLoadMatrixd args_glLoadMatrixd;


// -- glLoadMatrixf
struct args_glLoadMatrixf{
     const GLfloat *m ;
};

typedef struct args_glLoadMatrixf args_glLoadMatrixf;


// -- glMultMatrixd
struct args_glMultMatrixd{
     const GLdouble *m ;
};

typedef struct args_glMultMatrixd args_glMultMatrixd;


// -- glMultMatrixf
struct args_glMultMatrixf{
     const GLfloat *m ;
};

typedef struct args_glMultMatrixf args_glMultMatrixf;


// -- glRotated
struct args_glRotated{
     GLdouble angle;
	 GLdouble x;
	 GLdouble y;
	 GLdouble z ;
};

typedef struct args_glRotated args_glRotated;


// -- glRotatef
struct args_glRotatef{
     GLfloat angle;
	 GLfloat x;
	 GLfloat y;
	 GLfloat z ;
};

typedef struct args_glRotatef args_glRotatef;


// -- glScaled
struct args_glScaled{
     GLdouble x;
	 GLdouble y;
	 GLdouble z ;
};

typedef struct args_glScaled args_glScaled;


// -- glScalef
struct args_glScalef{
     GLfloat x;
	 GLfloat y;
	 GLfloat z ;
};

typedef struct args_glScalef args_glScalef;


// -- glTranslated
struct args_glTranslated{
     GLdouble x;
	 GLdouble y;
	 GLdouble z ;
};

typedef struct args_glTranslated args_glTranslated;


// -- glTranslatef
struct args_glTranslatef{
     GLfloat x;
	 GLfloat y;
	 GLfloat z ;
};

typedef struct args_glTranslatef args_glTranslatef;


// -- glIsList
struct args_glIsList{
     GLuint list ;
};

typedef struct args_glIsList args_glIsList;


// -- glDeleteLists
struct args_glDeleteLists{
     GLuint list;
	 GLsizei range ;
};

typedef struct args_glDeleteLists args_glDeleteLists;


// -- glGenLists
struct args_glGenLists{
     GLsizei range ;
};

typedef struct args_glGenLists args_glGenLists;


// -- glNewList
struct args_glNewList{
     GLuint list;
	 GLenum mode ;
};

typedef struct args_glNewList args_glNewList;


// -- glCallList
struct args_glCallList{
     GLuint list ;
};

typedef struct args_glCallList args_glCallList;


// -- glCallLists
struct args_glCallLists{
     GLsizei n;
	 GLenum type;
	 const GLvoid *lists ;
};

typedef struct args_glCallLists args_glCallLists;


// -- glListBase
struct args_glListBase{
     GLuint base ;
};

typedef struct args_glListBase args_glListBase;


// -- glBegin
struct args_glBegin{
     GLenum mode ;
};

typedef struct args_glBegin args_glBegin;


// -- glVertex2d
struct args_glVertex2d{
     GLdouble x;
	 GLdouble y ;
};

typedef struct args_glVertex2d args_glVertex2d;


// -- glVertex2f
struct args_glVertex2f{
     GLfloat x;
	 GLfloat y ;
};

typedef struct args_glVertex2f args_glVertex2f;


// -- glVertex2i
struct args_glVertex2i{
     GLint x;
	 GLint y ;
};

typedef struct args_glVertex2i args_glVertex2i;


// -- glVertex2s
struct args_glVertex2s{
     GLshort x;
	 GLshort y ;
};

typedef struct args_glVertex2s args_glVertex2s;


// -- glVertex3d
struct args_glVertex3d{
     GLdouble x;
	 GLdouble y;
	 GLdouble z ;
};

typedef struct args_glVertex3d args_glVertex3d;


// -- glVertex3f
struct args_glVertex3f{
     GLfloat x;
	 GLfloat y;
	 GLfloat z ;
};

typedef struct args_glVertex3f args_glVertex3f;


// -- glVertex3i
struct args_glVertex3i{
     GLint x;
	 GLint y;
	 GLint z ;
};

typedef struct args_glVertex3i args_glVertex3i;


// -- glVertex3s
struct args_glVertex3s{
     GLshort x;
	 GLshort y;
	 GLshort z ;
};

typedef struct args_glVertex3s args_glVertex3s;


// -- glVertex4d
struct args_glVertex4d{
     GLdouble x;
	 GLdouble y;
	 GLdouble z;
	 GLdouble w ;
};

typedef struct args_glVertex4d args_glVertex4d;


// -- glVertex4f
struct args_glVertex4f{
     GLfloat x;
	 GLfloat y;
	 GLfloat z;
	 GLfloat w ;
};

typedef struct args_glVertex4f args_glVertex4f;


// -- glVertex4i
struct args_glVertex4i{
     GLint x;
	 GLint y;
	 GLint z;
	 GLint w ;
};

typedef struct args_glVertex4i args_glVertex4i;


// -- glVertex4s
struct args_glVertex4s{
     GLshort x;
	 GLshort y;
	 GLshort z;
	 GLshort w ;
};

typedef struct args_glVertex4s args_glVertex4s;


// -- glVertex2dv
struct args_glVertex2dv{
     const GLdouble *v ;
};

typedef struct args_glVertex2dv args_glVertex2dv;


// -- glVertex2fv
struct args_glVertex2fv{
     const GLfloat *v ;
};

typedef struct args_glVertex2fv args_glVertex2fv;


// -- glVertex2iv
struct args_glVertex2iv{
     const GLint *v ;
};

typedef struct args_glVertex2iv args_glVertex2iv;


// -- glVertex2sv
struct args_glVertex2sv{
     const GLshort *v ;
};

typedef struct args_glVertex2sv args_glVertex2sv;


// -- glVertex3dv
struct args_glVertex3dv{
     const GLdouble *v ;
};

typedef struct args_glVertex3dv args_glVertex3dv;


// -- glVertex3fv
struct args_glVertex3fv{
     const GLfloat *v ;
};

typedef struct args_glVertex3fv args_glVertex3fv;


// -- glVertex3iv
struct args_glVertex3iv{
     const GLint *v ;
};

typedef struct args_glVertex3iv args_glVertex3iv;


// -- glVertex3sv
struct args_glVertex3sv{
     const GLshort *v ;
};

typedef struct args_glVertex3sv args_glVertex3sv;


// -- glVertex4dv
struct args_glVertex4dv{
     const GLdouble *v ;
};

typedef struct args_glVertex4dv args_glVertex4dv;


// -- glVertex4fv
struct args_glVertex4fv{
     const GLfloat *v ;
};

typedef struct args_glVertex4fv args_glVertex4fv;


// -- glVertex4iv
struct args_glVertex4iv{
     const GLint *v ;
};

typedef struct args_glVertex4iv args_glVertex4iv;


// -- glVertex4sv
struct args_glVertex4sv{
     const GLshort *v ;
};

typedef struct args_glVertex4sv args_glVertex4sv;


// -- glNormal3b
struct args_glNormal3b{
     GLbyte nx;
	 GLbyte ny;
	 GLbyte nz ;
};

typedef struct args_glNormal3b args_glNormal3b;


// -- glNormal3d
struct args_glNormal3d{
     GLdouble nx;
	 GLdouble ny;
	 GLdouble nz ;
};

typedef struct args_glNormal3d args_glNormal3d;


// -- glNormal3f
struct args_glNormal3f{
     GLfloat nx;
	 GLfloat ny;
	 GLfloat nz ;
};

typedef struct args_glNormal3f args_glNormal3f;


// -- glNormal3i
struct args_glNormal3i{
     GLint nx;
	 GLint ny;
	 GLint nz ;
};

typedef struct args_glNormal3i args_glNormal3i;


// -- glNormal3s
struct args_glNormal3s{
     GLshort nx;
	 GLshort ny;
	 GLshort nz ;
};

typedef struct args_glNormal3s args_glNormal3s;


// -- glNormal3bv
struct args_glNormal3bv{
     const GLbyte *v ;
};

typedef struct args_glNormal3bv args_glNormal3bv;


// -- glNormal3dv
struct args_glNormal3dv{
     const GLdouble *v ;
};

typedef struct args_glNormal3dv args_glNormal3dv;


// -- glNormal3fv
struct args_glNormal3fv{
     const GLfloat *v ;
};

typedef struct args_glNormal3fv args_glNormal3fv;


// -- glNormal3iv
struct args_glNormal3iv{
     const GLint *v ;
};

typedef struct args_glNormal3iv args_glNormal3iv;


// -- glNormal3sv
struct args_glNormal3sv{
     const GLshort *v ;
};

typedef struct args_glNormal3sv args_glNormal3sv;


// -- glIndexd
struct args_glIndexd{
     GLdouble c ;
};

typedef struct args_glIndexd args_glIndexd;


// -- glIndexf
struct args_glIndexf{
     GLfloat c ;
};

typedef struct args_glIndexf args_glIndexf;


// -- glIndexi
struct args_glIndexi{
     GLint c ;
};

typedef struct args_glIndexi args_glIndexi;


// -- glIndexs
struct args_glIndexs{
     GLshort c ;
};

typedef struct args_glIndexs args_glIndexs;


// -- glIndexub
struct args_glIndexub{
     GLubyte c ;
};

typedef struct args_glIndexub args_glIndexub;


// -- glIndexdv
struct args_glIndexdv{
     const GLdouble *c ;
};

typedef struct args_glIndexdv args_glIndexdv;


// -- glIndexfv
struct args_glIndexfv{
     const GLfloat *c ;
};

typedef struct args_glIndexfv args_glIndexfv;


// -- glIndexiv
struct args_glIndexiv{
     const GLint *c ;
};

typedef struct args_glIndexiv args_glIndexiv;


// -- glIndexsv
struct args_glIndexsv{
     const GLshort *c ;
};

typedef struct args_glIndexsv args_glIndexsv;


// -- glIndexubv
struct args_glIndexubv{
     const GLubyte *c ;
};

typedef struct args_glIndexubv args_glIndexubv;


// -- glColor3b
struct args_glColor3b{
     GLbyte red;
	 GLbyte green;
	 GLbyte blue ;
};

typedef struct args_glColor3b args_glColor3b;


// -- glColor3d
struct args_glColor3d{
     GLdouble red;
	 GLdouble green;
	 GLdouble blue ;
};

typedef struct args_glColor3d args_glColor3d;


// -- glColor3f
struct args_glColor3f{
     GLfloat red;
	 GLfloat green;
	 GLfloat blue ;
};

typedef struct args_glColor3f args_glColor3f;


// -- glColor3i
struct args_glColor3i{
     GLint red;
	 GLint green;
	 GLint blue ;
};

typedef struct args_glColor3i args_glColor3i;


// -- glColor3s
struct args_glColor3s{
     GLshort red;
	 GLshort green;
	 GLshort blue ;
};

typedef struct args_glColor3s args_glColor3s;


// -- glColor3ub
struct args_glColor3ub{
     GLubyte red;
	 GLubyte green;
	 GLubyte blue ;
};

typedef struct args_glColor3ub args_glColor3ub;


// -- glColor3ui
struct args_glColor3ui{
     GLuint red;
	 GLuint green;
	 GLuint blue ;
};

typedef struct args_glColor3ui args_glColor3ui;


// -- glColor3us
struct args_glColor3us{
     GLushort red;
	 GLushort green;
	 GLushort blue ;
};

typedef struct args_glColor3us args_glColor3us;


// -- glColor4b
struct args_glColor4b{
     GLbyte red;
	 GLbyte green;
	 GLbyte blue;
	 GLbyte alpha ;
};

typedef struct args_glColor4b args_glColor4b;


// -- glColor4d
struct args_glColor4d{
     GLdouble red;
	 GLdouble green;
	 GLdouble blue;
	 GLdouble alpha ;
};

typedef struct args_glColor4d args_glColor4d;


// -- glColor4f
struct args_glColor4f{
     GLfloat red;
	 GLfloat green;
	 GLfloat blue;
	 GLfloat alpha ;
};

typedef struct args_glColor4f args_glColor4f;


// -- glColor4i
struct args_glColor4i{
     GLint red;
	 GLint green;
	 GLint blue;
	 GLint alpha ;
};

typedef struct args_glColor4i args_glColor4i;


// -- glColor4s
struct args_glColor4s{
     GLshort red;
	 GLshort green;
	 GLshort blue;
	 GLshort alpha ;
};

typedef struct args_glColor4s args_glColor4s;


// -- glColor4ub
struct args_glColor4ub{
     GLubyte red;
	 GLubyte green;
	 GLubyte blue;
	 GLubyte alpha ;
};

typedef struct args_glColor4ub args_glColor4ub;


// -- glColor4ui
struct args_glColor4ui{
     GLuint red;
	 GLuint green;
	 GLuint blue;
	 GLuint alpha ;
};

typedef struct args_glColor4ui args_glColor4ui;


// -- glColor4us
struct args_glColor4us{
     GLushort red;
	 GLushort green;
	 GLushort blue;
	 GLushort alpha ;
};

typedef struct args_glColor4us args_glColor4us;


// -- glColor3bv
struct args_glColor3bv{
     const GLbyte *v ;
};

typedef struct args_glColor3bv args_glColor3bv;


// -- glColor3dv
struct args_glColor3dv{
     const GLdouble *v ;
};

typedef struct args_glColor3dv args_glColor3dv;


// -- glColor3fv
struct args_glColor3fv{
     const GLfloat *v ;
};

typedef struct args_glColor3fv args_glColor3fv;


// -- glColor3iv
struct args_glColor3iv{
     const GLint *v ;
};

typedef struct args_glColor3iv args_glColor3iv;


// -- glColor3sv
struct args_glColor3sv{
     const GLshort *v ;
};

typedef struct args_glColor3sv args_glColor3sv;


// -- glColor3ubv
struct args_glColor3ubv{
     const GLubyte *v ;
};

typedef struct args_glColor3ubv args_glColor3ubv;


// -- glColor3uiv
struct args_glColor3uiv{
     const GLuint *v ;
};

typedef struct args_glColor3uiv args_glColor3uiv;


// -- glColor3usv
struct args_glColor3usv{
     const GLushort *v ;
};

typedef struct args_glColor3usv args_glColor3usv;


// -- glColor4bv
struct args_glColor4bv{
     const GLbyte *v ;
};

typedef struct args_glColor4bv args_glColor4bv;


// -- glColor4dv
struct args_glColor4dv{
     const GLdouble *v ;
};

typedef struct args_glColor4dv args_glColor4dv;


// -- glColor4fv
struct args_glColor4fv{
     const GLfloat *v ;
};

typedef struct args_glColor4fv args_glColor4fv;


// -- glColor4iv
struct args_glColor4iv{
     const GLint *v ;
};

typedef struct args_glColor4iv args_glColor4iv;


// -- glColor4sv
struct args_glColor4sv{
     const GLshort *v ;
};

typedef struct args_glColor4sv args_glColor4sv;


// -- glColor4ubv
struct args_glColor4ubv{
     const GLubyte *v ;
};

typedef struct args_glColor4ubv args_glColor4ubv;


// -- glColor4uiv
struct args_glColor4uiv{
     const GLuint *v ;
};

typedef struct args_glColor4uiv args_glColor4uiv;


// -- glColor4usv
struct args_glColor4usv{
     const GLushort *v ;
};

typedef struct args_glColor4usv args_glColor4usv;


// -- glTexCoord1d
struct args_glTexCoord1d{
     GLdouble s ;
};

typedef struct args_glTexCoord1d args_glTexCoord1d;


// -- glTexCoord1f
struct args_glTexCoord1f{
     GLfloat s ;
};

typedef struct args_glTexCoord1f args_glTexCoord1f;


// -- glTexCoord1i
struct args_glTexCoord1i{
     GLint s ;
};

typedef struct args_glTexCoord1i args_glTexCoord1i;


// -- glTexCoord1s
struct args_glTexCoord1s{
     GLshort s ;
};

typedef struct args_glTexCoord1s args_glTexCoord1s;


// -- glTexCoord2d
struct args_glTexCoord2d{
     GLdouble s;
	 GLdouble t ;
};

typedef struct args_glTexCoord2d args_glTexCoord2d;


// -- glTexCoord2f
struct args_glTexCoord2f{
     GLfloat s;
	 GLfloat t ;
};

typedef struct args_glTexCoord2f args_glTexCoord2f;


// -- glTexCoord2i
struct args_glTexCoord2i{
     GLint s;
	 GLint t ;
};

typedef struct args_glTexCoord2i args_glTexCoord2i;


// -- glTexCoord2s
struct args_glTexCoord2s{
     GLshort s;
	 GLshort t ;
};

typedef struct args_glTexCoord2s args_glTexCoord2s;


// -- glTexCoord3d
struct args_glTexCoord3d{
     GLdouble s;
	 GLdouble t;
	 GLdouble r ;
};

typedef struct args_glTexCoord3d args_glTexCoord3d;


// -- glTexCoord3f
struct args_glTexCoord3f{
     GLfloat s;
	 GLfloat t;
	 GLfloat r ;
};

typedef struct args_glTexCoord3f args_glTexCoord3f;


// -- glTexCoord3i
struct args_glTexCoord3i{
     GLint s;
	 GLint t;
	 GLint r ;
};

typedef struct args_glTexCoord3i args_glTexCoord3i;


// -- glTexCoord3s
struct args_glTexCoord3s{
     GLshort s;
	 GLshort t;
	 GLshort r ;
};

typedef struct args_glTexCoord3s args_glTexCoord3s;


// -- glTexCoord4d
struct args_glTexCoord4d{
     GLdouble s;
	 GLdouble t;
	 GLdouble r;
	 GLdouble q ;
};

typedef struct args_glTexCoord4d args_glTexCoord4d;


// -- glTexCoord4f
struct args_glTexCoord4f{
     GLfloat s;
	 GLfloat t;
	 GLfloat r;
	 GLfloat q ;
};

typedef struct args_glTexCoord4f args_glTexCoord4f;


// -- glTexCoord4i
struct args_glTexCoord4i{
     GLint s;
	 GLint t;
	 GLint r;
	 GLint q ;
};

typedef struct args_glTexCoord4i args_glTexCoord4i;


// -- glTexCoord4s
struct args_glTexCoord4s{
     GLshort s;
	 GLshort t;
	 GLshort r;
	 GLshort q ;
};

typedef struct args_glTexCoord4s args_glTexCoord4s;


// -- glTexCoord1dv
struct args_glTexCoord1dv{
     const GLdouble *v ;
};

typedef struct args_glTexCoord1dv args_glTexCoord1dv;


// -- glTexCoord1fv
struct args_glTexCoord1fv{
     const GLfloat *v ;
};

typedef struct args_glTexCoord1fv args_glTexCoord1fv;


// -- glTexCoord1iv
struct args_glTexCoord1iv{
     const GLint *v ;
};

typedef struct args_glTexCoord1iv args_glTexCoord1iv;


// -- glTexCoord1sv
struct args_glTexCoord1sv{
     const GLshort *v ;
};

typedef struct args_glTexCoord1sv args_glTexCoord1sv;


// -- glTexCoord2dv
struct args_glTexCoord2dv{
     const GLdouble *v ;
};

typedef struct args_glTexCoord2dv args_glTexCoord2dv;


// -- glTexCoord2fv
struct args_glTexCoord2fv{
     const GLfloat *v ;
};

typedef struct args_glTexCoord2fv args_glTexCoord2fv;


// -- glTexCoord2iv
struct args_glTexCoord2iv{
     const GLint *v ;
};

typedef struct args_glTexCoord2iv args_glTexCoord2iv;


// -- glTexCoord2sv
struct args_glTexCoord2sv{
     const GLshort *v ;
};

typedef struct args_glTexCoord2sv args_glTexCoord2sv;


// -- glTexCoord3dv
struct args_glTexCoord3dv{
     const GLdouble *v ;
};

typedef struct args_glTexCoord3dv args_glTexCoord3dv;


// -- glTexCoord3fv
struct args_glTexCoord3fv{
     const GLfloat *v ;
};

typedef struct args_glTexCoord3fv args_glTexCoord3fv;


// -- glTexCoord3iv
struct args_glTexCoord3iv{
     const GLint *v ;
};

typedef struct args_glTexCoord3iv args_glTexCoord3iv;


// -- glTexCoord3sv
struct args_glTexCoord3sv{
     const GLshort *v ;
};

typedef struct args_glTexCoord3sv args_glTexCoord3sv;


// -- glTexCoord4dv
struct args_glTexCoord4dv{
     const GLdouble *v ;
};

typedef struct args_glTexCoord4dv args_glTexCoord4dv;


// -- glTexCoord4fv
struct args_glTexCoord4fv{
     const GLfloat *v ;
};

typedef struct args_glTexCoord4fv args_glTexCoord4fv;


// -- glTexCoord4iv
struct args_glTexCoord4iv{
     const GLint *v ;
};

typedef struct args_glTexCoord4iv args_glTexCoord4iv;


// -- glTexCoord4sv
struct args_glTexCoord4sv{
     const GLshort *v ;
};

typedef struct args_glTexCoord4sv args_glTexCoord4sv;


// -- glRasterPos2d
struct args_glRasterPos2d{
     GLdouble x;
	 GLdouble y ;
};

typedef struct args_glRasterPos2d args_glRasterPos2d;


// -- glRasterPos2f
struct args_glRasterPos2f{
     GLfloat x;
	 GLfloat y ;
};

typedef struct args_glRasterPos2f args_glRasterPos2f;


// -- glRasterPos2i
struct args_glRasterPos2i{
     GLint x;
	 GLint y ;
};

typedef struct args_glRasterPos2i args_glRasterPos2i;


// -- glRasterPos2s
struct args_glRasterPos2s{
     GLshort x;
	 GLshort y ;
};

typedef struct args_glRasterPos2s args_glRasterPos2s;


// -- glRasterPos3d
struct args_glRasterPos3d{
     GLdouble x;
	 GLdouble y;
	 GLdouble z ;
};

typedef struct args_glRasterPos3d args_glRasterPos3d;


// -- glRasterPos3f
struct args_glRasterPos3f{
     GLfloat x;
	 GLfloat y;
	 GLfloat z ;
};

typedef struct args_glRasterPos3f args_glRasterPos3f;


// -- glRasterPos3i
struct args_glRasterPos3i{
     GLint x;
	 GLint y;
	 GLint z ;
};

typedef struct args_glRasterPos3i args_glRasterPos3i;


// -- glRasterPos3s
struct args_glRasterPos3s{
     GLshort x;
	 GLshort y;
	 GLshort z ;
};

typedef struct args_glRasterPos3s args_glRasterPos3s;


// -- glRasterPos4d
struct args_glRasterPos4d{
     GLdouble x;
	 GLdouble y;
	 GLdouble z;
	 GLdouble w ;
};

typedef struct args_glRasterPos4d args_glRasterPos4d;


// -- glRasterPos4f
struct args_glRasterPos4f{
     GLfloat x;
	 GLfloat y;
	 GLfloat z;
	 GLfloat w ;
};

typedef struct args_glRasterPos4f args_glRasterPos4f;


// -- glRasterPos4i
struct args_glRasterPos4i{
     GLint x;
	 GLint y;
	 GLint z;
	 GLint w ;
};

typedef struct args_glRasterPos4i args_glRasterPos4i;


// -- glRasterPos4s
struct args_glRasterPos4s{
     GLshort x;
	 GLshort y;
	 GLshort z;
	 GLshort w ;
};

typedef struct args_glRasterPos4s args_glRasterPos4s;


// -- glRasterPos2dv
struct args_glRasterPos2dv{
     const GLdouble *v ;
};

typedef struct args_glRasterPos2dv args_glRasterPos2dv;


// -- glRasterPos2fv
struct args_glRasterPos2fv{
     const GLfloat *v ;
};

typedef struct args_glRasterPos2fv args_glRasterPos2fv;


// -- glRasterPos2iv
struct args_glRasterPos2iv{
     const GLint *v ;
};

typedef struct args_glRasterPos2iv args_glRasterPos2iv;


// -- glRasterPos2sv
struct args_glRasterPos2sv{
     const GLshort *v ;
};

typedef struct args_glRasterPos2sv args_glRasterPos2sv;


// -- glRasterPos3dv
struct args_glRasterPos3dv{
     const GLdouble *v ;
};

typedef struct args_glRasterPos3dv args_glRasterPos3dv;


// -- glRasterPos3fv
struct args_glRasterPos3fv{
     const GLfloat *v ;
};

typedef struct args_glRasterPos3fv args_glRasterPos3fv;


// -- glRasterPos3iv
struct args_glRasterPos3iv{
     const GLint *v ;
};

typedef struct args_glRasterPos3iv args_glRasterPos3iv;


// -- glRasterPos3sv
struct args_glRasterPos3sv{
     const GLshort *v ;
};

typedef struct args_glRasterPos3sv args_glRasterPos3sv;


// -- glRasterPos4dv
struct args_glRasterPos4dv{
     const GLdouble *v ;
};

typedef struct args_glRasterPos4dv args_glRasterPos4dv;


// -- glRasterPos4fv
struct args_glRasterPos4fv{
     const GLfloat *v ;
};

typedef struct args_glRasterPos4fv args_glRasterPos4fv;


// -- glRasterPos4iv
struct args_glRasterPos4iv{
     const GLint *v ;
};

typedef struct args_glRasterPos4iv args_glRasterPos4iv;


// -- glRasterPos4sv
struct args_glRasterPos4sv{
     const GLshort *v ;
};

typedef struct args_glRasterPos4sv args_glRasterPos4sv;


// -- glRectd
struct args_glRectd{
     GLdouble x1;
	 GLdouble y1;
	 GLdouble x2;
	 GLdouble y2 ;
};

typedef struct args_glRectd args_glRectd;


// -- glRectf
struct args_glRectf{
     GLfloat x1;
	 GLfloat y1;
	 GLfloat x2;
	 GLfloat y2 ;
};

typedef struct args_glRectf args_glRectf;


// -- glRecti
struct args_glRecti{
     GLint x1;
	 GLint y1;
	 GLint x2;
	 GLint y2 ;
};

typedef struct args_glRecti args_glRecti;


// -- glRects
struct args_glRects{
     GLshort x1;
	 GLshort y1;
	 GLshort x2;
	 GLshort y2 ;
};

typedef struct args_glRects args_glRects;


// -- glRectdv
struct args_glRectdv{
     const GLdouble *v1;
	 const GLdouble *v2 ;
};

typedef struct args_glRectdv args_glRectdv;


// -- glRectfv
struct args_glRectfv{
     const GLfloat *v1;
	 const GLfloat *v2 ;
};

typedef struct args_glRectfv args_glRectfv;


// -- glRectiv
struct args_glRectiv{
     const GLint *v1;
	 const GLint *v2 ;
};

typedef struct args_glRectiv args_glRectiv;


// -- glRectsv
struct args_glRectsv{
     const GLshort *v1;
	 const GLshort *v2 ;
};

typedef struct args_glRectsv args_glRectsv;


// -- glVertexPointer
struct args_glVertexPointer{
     GLint size;
	 GLenum type;
	 GLsizei stride;
	 const GLvoid *ptr ;
};

typedef struct args_glVertexPointer args_glVertexPointer;


// -- glNormalPointer
struct args_glNormalPointer{
     GLenum type;
	 GLsizei stride;
	 const GLvoid *ptr ;
};

typedef struct args_glNormalPointer args_glNormalPointer;


// -- glColorPointer
struct args_glColorPointer{
     GLint size;
	 GLenum type;
	 GLsizei stride;
	 const GLvoid *ptr ;
};

typedef struct args_glColorPointer args_glColorPointer;


// -- glIndexPointer
struct args_glIndexPointer{
     GLenum type;
	 GLsizei stride;
	 const GLvoid *ptr ;
};

typedef struct args_glIndexPointer args_glIndexPointer;


// -- glTexCoordPointer
struct args_glTexCoordPointer{
     GLint size;
	 GLenum type;
	 GLsizei stride;
	 const GLvoid *ptr ;
};

typedef struct args_glTexCoordPointer args_glTexCoordPointer;


// -- glEdgeFlagPointer
struct args_glEdgeFlagPointer{
     GLsizei stride;
	 const GLvoid *ptr ;
};

typedef struct args_glEdgeFlagPointer args_glEdgeFlagPointer;


// -- glGetPointerv
struct args_glGetPointerv{
     GLenum pname;
	 GLvoid **params ;
};

typedef struct args_glGetPointerv args_glGetPointerv;


// -- glArrayElement
struct args_glArrayElement{
     GLint i ;
};

typedef struct args_glArrayElement args_glArrayElement;


// -- glDrawArrays
struct args_glDrawArrays{
     GLenum mode;
	 GLint first;
	 GLsizei count ;
};

typedef struct args_glDrawArrays args_glDrawArrays;


// -- glDrawElements
struct args_glDrawElements{
     GLenum mode;
	 GLsizei count;
	 GLenum type;
	 const GLvoid *indices ;
};

typedef struct args_glDrawElements args_glDrawElements;


// -- glInterleavedArrays
struct args_glInterleavedArrays{
     GLenum format;
	 GLsizei stride;
	 const GLvoid *pointer ;
};

typedef struct args_glInterleavedArrays args_glInterleavedArrays;


// -- glShadeModel
struct args_glShadeModel{
     GLenum mode ;
};

typedef struct args_glShadeModel args_glShadeModel;


// -- glLightf
struct args_glLightf{
     GLenum light;
	 GLenum pname;
	 GLfloat param ;
};

typedef struct args_glLightf args_glLightf;


// -- glLighti
struct args_glLighti{
     GLenum light;
	 GLenum pname;
	 GLint param ;
};

typedef struct args_glLighti args_glLighti;


// -- glLightfv
struct args_glLightfv{
     GLenum light;
	 GLenum pname;
	 const GLfloat *params ;
};

typedef struct args_glLightfv args_glLightfv;


// -- glLightiv
struct args_glLightiv{
     GLenum light;
	 GLenum pname;
	 const GLint *params ;
};

typedef struct args_glLightiv args_glLightiv;


// -- glGetLightfv
struct args_glGetLightfv{
     GLenum light;
	 GLenum pname;
	 GLfloat *params ;
};

typedef struct args_glGetLightfv args_glGetLightfv;


// -- glGetLightiv
struct args_glGetLightiv{
     GLenum light;
	 GLenum pname;
	 GLint *params ;
};

typedef struct args_glGetLightiv args_glGetLightiv;


// -- glLightModelf
struct args_glLightModelf{
     GLenum pname;
	 GLfloat param ;
};

typedef struct args_glLightModelf args_glLightModelf;


// -- glLightModeli
struct args_glLightModeli{
     GLenum pname;
	 GLint param ;
};

typedef struct args_glLightModeli args_glLightModeli;


// -- glLightModelfv
struct args_glLightModelfv{
     GLenum pname;
	 const GLfloat *params ;
};

typedef struct args_glLightModelfv args_glLightModelfv;


// -- glLightModeliv
struct args_glLightModeliv{
     GLenum pname;
	 const GLint *params ;
};

typedef struct args_glLightModeliv args_glLightModeliv;


// -- glMaterialf
struct args_glMaterialf{
     GLenum face;
	 GLenum pname;
	 GLfloat param ;
};

typedef struct args_glMaterialf args_glMaterialf;


// -- glMateriali
struct args_glMateriali{
     GLenum face;
	 GLenum pname;
	 GLint param ;
};

typedef struct args_glMateriali args_glMateriali;


// -- glMaterialfv
struct args_glMaterialfv{
     GLenum face;
	 GLenum pname;
	 const GLfloat *params ;
};

typedef struct args_glMaterialfv args_glMaterialfv;


// -- glMaterialiv
struct args_glMaterialiv{
     GLenum face;
	 GLenum pname;
	 const GLint *params ;
};

typedef struct args_glMaterialiv args_glMaterialiv;


// -- glGetMaterialfv
struct args_glGetMaterialfv{
     GLenum face;
	 GLenum pname;
	 GLfloat *params ;
};

typedef struct args_glGetMaterialfv args_glGetMaterialfv;


// -- glGetMaterialiv
struct args_glGetMaterialiv{
     GLenum face;
	 GLenum pname;
	 GLint *params ;
};

typedef struct args_glGetMaterialiv args_glGetMaterialiv;


// -- glColorMaterial
struct args_glColorMaterial{
     GLenum face;
	 GLenum mode ;
};

typedef struct args_glColorMaterial args_glColorMaterial;


// -- glPixelZoom
struct args_glPixelZoom{
     GLfloat xfactor;
	 GLfloat yfactor ;
};

typedef struct args_glPixelZoom args_glPixelZoom;


// -- glPixelStoref
struct args_glPixelStoref{
     GLenum pname;
	 GLfloat param ;
};

typedef struct args_glPixelStoref args_glPixelStoref;


// -- glPixelStorei
struct args_glPixelStorei{
     GLenum pname;
	 GLint param ;
};

typedef struct args_glPixelStorei args_glPixelStorei;


// -- glPixelTransferf
struct args_glPixelTransferf{
     GLenum pname;
	 GLfloat param ;
};

typedef struct args_glPixelTransferf args_glPixelTransferf;


// -- glPixelTransferi
struct args_glPixelTransferi{
     GLenum pname;
	 GLint param ;
};

typedef struct args_glPixelTransferi args_glPixelTransferi;


// -- glPixelMapfv
struct args_glPixelMapfv{
     GLenum map;
	 GLsizei mapsize;
	 const GLfloat *values ;
};

typedef struct args_glPixelMapfv args_glPixelMapfv;


// -- glPixelMapuiv
struct args_glPixelMapuiv{
     GLenum map;
	 GLsizei mapsize;
	 const GLuint *values ;
};

typedef struct args_glPixelMapuiv args_glPixelMapuiv;


// -- glPixelMapusv
struct args_glPixelMapusv{
     GLenum map;
	 GLsizei mapsize;
	 const GLushort *values ;
};

typedef struct args_glPixelMapusv args_glPixelMapusv;


// -- glGetPixelMapfv
struct args_glGetPixelMapfv{
     GLenum map;
	 GLfloat *values ;
};

typedef struct args_glGetPixelMapfv args_glGetPixelMapfv;


// -- glGetPixelMapuiv
struct args_glGetPixelMapuiv{
     GLenum map;
	 GLuint *values ;
};

typedef struct args_glGetPixelMapuiv args_glGetPixelMapuiv;


// -- glGetPixelMapusv
struct args_glGetPixelMapusv{
     GLenum map;
	 GLushort *values ;
};

typedef struct args_glGetPixelMapusv args_glGetPixelMapusv;


// -- glBitmap
struct args_glBitmap{
     GLsizei width;
	 GLsizei height;
	 GLfloat xorig;
	 GLfloat yorig;
	 GLfloat xmove;
	 GLfloat ymove;
	 const GLubyte *bitmap ;
};

typedef struct args_glBitmap args_glBitmap;


// -- glReadPixels
struct args_glReadPixels{
     GLint x;
	 GLint y;
	 GLsizei width;
	 GLsizei height;
	 GLenum format;
	 GLenum type;
	 GLvoid *pixels ;
};

typedef struct args_glReadPixels args_glReadPixels;


// -- glDrawPixels
struct args_glDrawPixels{
     GLsizei width;
	 GLsizei height;
	 GLenum format;
	 GLenum type;
	 const GLvoid *pixels ;
};

typedef struct args_glDrawPixels args_glDrawPixels;


// -- glCopyPixels
struct args_glCopyPixels{
     GLint x;
	 GLint y;
	 GLsizei width;
	 GLsizei height;
	 GLenum type ;
};

typedef struct args_glCopyPixels args_glCopyPixels;


// -- glStencilFunc
struct args_glStencilFunc{
     GLenum func;
	 GLint ref;
	 GLuint mask ;
};

typedef struct args_glStencilFunc args_glStencilFunc;


// -- glStencilMask
struct args_glStencilMask{
     GLuint mask ;
};

typedef struct args_glStencilMask args_glStencilMask;


// -- glStencilOp
struct args_glStencilOp{
     GLenum fail;
	 GLenum zfail;
	 GLenum zpass ;
};

typedef struct args_glStencilOp args_glStencilOp;


// -- glClearStencil
struct args_glClearStencil{
     GLint s ;
};

typedef struct args_glClearStencil args_glClearStencil;


// -- glTexGend
struct args_glTexGend{
     GLenum coord;
	 GLenum pname;
	 GLdouble param ;
};

typedef struct args_glTexGend args_glTexGend;


// -- glTexGenf
struct args_glTexGenf{
     GLenum coord;
	 GLenum pname;
	 GLfloat param ;
};

typedef struct args_glTexGenf args_glTexGenf;


// -- glTexGeni
struct args_glTexGeni{
     GLenum coord;
	 GLenum pname;
	 GLint param ;
};

typedef struct args_glTexGeni args_glTexGeni;


// -- glTexGendv
struct args_glTexGendv{
     GLenum coord;
	 GLenum pname;
	 const GLdouble *params ;
};

typedef struct args_glTexGendv args_glTexGendv;


// -- glTexGenfv
struct args_glTexGenfv{
     GLenum coord;
	 GLenum pname;
	 const GLfloat *params ;
};

typedef struct args_glTexGenfv args_glTexGenfv;


// -- glTexGeniv
struct args_glTexGeniv{
     GLenum coord;
	 GLenum pname;
	 const GLint *params ;
};

typedef struct args_glTexGeniv args_glTexGeniv;


// -- glGetTexGendv
struct args_glGetTexGendv{
     GLenum coord;
	 GLenum pname;
	 GLdouble *params ;
};

typedef struct args_glGetTexGendv args_glGetTexGendv;


// -- glGetTexGenfv
struct args_glGetTexGenfv{
     GLenum coord;
	 GLenum pname;
	 GLfloat *params ;
};

typedef struct args_glGetTexGenfv args_glGetTexGenfv;


// -- glGetTexGeniv
struct args_glGetTexGeniv{
     GLenum coord;
	 GLenum pname;
	 GLint *params ;
};

typedef struct args_glGetTexGeniv args_glGetTexGeniv;


// -- glTexEnvf
struct args_glTexEnvf{
     GLenum target;
	 GLenum pname;
	 GLfloat param ;
};

typedef struct args_glTexEnvf args_glTexEnvf;


// -- glTexEnvi
struct args_glTexEnvi{
     GLenum target;
	 GLenum pname;
	 GLint param ;
};

typedef struct args_glTexEnvi args_glTexEnvi;


// -- glTexEnvfv
struct args_glTexEnvfv{
     GLenum target;
	 GLenum pname;
	 const GLfloat *params ;
};

typedef struct args_glTexEnvfv args_glTexEnvfv;


// -- glTexEnviv
struct args_glTexEnviv{
     GLenum target;
	 GLenum pname;
	 const GLint *params ;
};

typedef struct args_glTexEnviv args_glTexEnviv;


// -- glGetTexEnvfv
struct args_glGetTexEnvfv{
     GLenum target;
	 GLenum pname;
	 GLfloat *params ;
};

typedef struct args_glGetTexEnvfv args_glGetTexEnvfv;


// -- glGetTexEnviv
struct args_glGetTexEnviv{
     GLenum target;
	 GLenum pname;
	 GLint *params ;
};

typedef struct args_glGetTexEnviv args_glGetTexEnviv;


// -- glTexParameterf
struct args_glTexParameterf{
     GLenum target;
	 GLenum pname;
	 GLfloat param ;
};

typedef struct args_glTexParameterf args_glTexParameterf;


// -- glTexParameteri
struct args_glTexParameteri{
     GLenum target;
	 GLenum pname;
	 GLint param ;
};

typedef struct args_glTexParameteri args_glTexParameteri;


// -- glTexParameterfv
struct args_glTexParameterfv{
     GLenum target;
	 GLenum pname;
	 const GLfloat *params ;
};

typedef struct args_glTexParameterfv args_glTexParameterfv;


// -- glTexParameteriv
struct args_glTexParameteriv{
     GLenum target;
	 GLenum pname;
	 const GLint *params ;
};

typedef struct args_glTexParameteriv args_glTexParameteriv;


// -- glGetTexParameterfv
struct args_glGetTexParameterfv{
     GLenum target;
	 GLenum pname;
	 GLfloat *params;
};

typedef struct args_glGetTexParameterfv args_glGetTexParameterfv;


// -- glGetTexParameteriv
struct args_glGetTexParameteriv{
     GLenum target;
	 GLenum pname;
	 GLint *params ;
};

typedef struct args_glGetTexParameteriv args_glGetTexParameteriv;


// -- glGetTexLevelParameterfv
struct args_glGetTexLevelParameterfv{
     GLenum target;
	 GLint level;
	 GLenum pname;
	 GLfloat *params ;
};

typedef struct args_glGetTexLevelParameterfv args_glGetTexLevelParameterfv;


// -- glGetTexLevelParameteriv
struct args_glGetTexLevelParameteriv{
     GLenum target;
	 GLint level;
	 GLenum pname;
	 GLint *params ;
};

typedef struct args_glGetTexLevelParameteriv args_glGetTexLevelParameteriv;


// -- glTexImage1D
struct args_glTexImage1D{
     GLenum target;
	 GLint level;
	 GLint internalFormat;
	 GLsizei width;
	 GLint border;
	 GLenum format;
	 GLenum type;
	 const GLvoid *pixels ;
};

typedef struct args_glTexImage1D args_glTexImage1D;


// -- glTexImage2D
struct args_glTexImage2D{
     GLenum target;
	 GLint level;
	 GLint internalFormat;
	 GLsizei width;
	 GLsizei height;
	 GLint border;
	 GLenum format;
	 GLenum type;
	 const GLvoid *pixels ;
};

typedef struct args_glTexImage2D args_glTexImage2D;


// -- glGetTexImage
struct args_glGetTexImage{
     GLenum target;
	 GLint level;
	  GLenum format;
	 GLenum type;
	  GLvoid *pixels ;
};

typedef struct args_glGetTexImage args_glGetTexImage;


// -- glGenTextures
struct args_glGenTextures{
     GLsizei n;
	 GLuint *textures ;
};

typedef struct args_glGenTextures args_glGenTextures;


// -- glDeleteTextures
struct args_glDeleteTextures{
     GLsizei n;
	 const GLuint *textures;
};

typedef struct args_glDeleteTextures args_glDeleteTextures;


// -- glBindTexture
struct args_glBindTexture{
     GLenum target;
	 GLuint texture ;
};

typedef struct args_glBindTexture args_glBindTexture;


// -- glPrioritizeTextures
struct args_glPrioritizeTextures{
     GLsizei n;
	 const GLuint *textures;
	 const GLclampf *priorities ;
};

typedef struct args_glPrioritizeTextures args_glPrioritizeTextures;


// -- glAreTexturesResident
struct args_glAreTexturesResident{
     GLsizei n;
	 const GLuint *textures;
	 GLboolean *residences ;
};

typedef struct args_glAreTexturesResident args_glAreTexturesResident;


// -- glIsTexture
struct args_glIsTexture{
     GLuint texture ;
};

typedef struct args_glIsTexture args_glIsTexture;


// -- glTexSubImage1D
struct args_glTexSubImage1D{
     GLenum target;
	 GLint level;
	 GLint xoffset;
	 GLsizei width;
	 GLenum format;
	 GLenum type;
	 const GLvoid *pixels ;
};

typedef struct args_glTexSubImage1D args_glTexSubImage1D;


// -- glTexSubImage2D
struct args_glTexSubImage2D{
     GLenum target;
	 GLint level;
	 GLint xoffset;
	 GLint yoffset;
	 GLsizei width;
	 GLsizei height;
	 GLenum format;
	 GLenum type;
	 const GLvoid *pixels ;
};

typedef struct args_glTexSubImage2D args_glTexSubImage2D;


// -- glCopyTexImage1D
struct args_glCopyTexImage1D{
     GLenum target;
	 GLint level;
	 GLenum internalformat;
	 GLint x;
	 GLint y;
	 GLsizei width;
	 GLint border ;
};

typedef struct args_glCopyTexImage1D args_glCopyTexImage1D;


// -- glCopyTexImage2D
struct args_glCopyTexImage2D{
     GLenum target;
	 GLint level;
	 GLenum internalformat;
	 GLint x;
	 GLint y;
	 GLsizei width;
	 GLsizei height;
	 GLint border ;
};

typedef struct args_glCopyTexImage2D args_glCopyTexImage2D;


// -- glCopyTexSubImage1D
struct args_glCopyTexSubImage1D{
     GLenum target;
	 GLint level;
	GLint xoffset;
	 GLint x;
	 GLint y;
	GLsizei width ;
};

typedef struct args_glCopyTexSubImage1D args_glCopyTexSubImage1D;


// -- glCopyTexSubImage2D
struct args_glCopyTexSubImage2D{
     GLenum target;
	 GLint level;
	GLint xoffset;
	 GLint yoffset;
	GLint x;
	 GLint y;
	 GLsizei width;
	 GLsizei height ;
};

typedef struct args_glCopyTexSubImage2D args_glCopyTexSubImage2D;


// -- glMap1d
struct args_glMap1d{
     GLenum target;
	 GLdouble u1;
	 GLdouble u2;
	 GLint stride;
	 GLint order;
	 const GLdouble *points ;
};

typedef struct args_glMap1d args_glMap1d;


// -- glMap1f
struct args_glMap1f{
     GLenum target;
	 GLfloat u1;
	 GLfloat u2;
	 GLint stride;
	 GLint order;
	 const GLfloat *points ;
};

typedef struct args_glMap1f args_glMap1f;


// -- glMap2d
struct args_glMap2d{
     GLenum target;
	 GLdouble u1;
	 GLdouble u2;
	 GLint ustride;
	 GLint uorder;
	 GLdouble v1;
	 GLdouble v2;
	 GLint vstride;
	 GLint vorder;
	 const GLdouble *points ;
};

typedef struct args_glMap2d args_glMap2d;


// -- glMap2f
struct args_glMap2f{
     GLenum target;
	 GLfloat u1;
	 GLfloat u2;
	 GLint ustride;
	 GLint uorder;
	 GLfloat v1;
	 GLfloat v2;
	 GLint vstride;
	 GLint vorder;
	 const GLfloat *points ;
};

typedef struct args_glMap2f args_glMap2f;


// -- glGetMapdv
struct args_glGetMapdv{
     GLenum target;
	 GLenum query;
	 GLdouble *v ;
};

typedef struct args_glGetMapdv args_glGetMapdv;


// -- glGetMapfv
struct args_glGetMapfv{
     GLenum target;
	 GLenum query;
	 GLfloat *v ;
};

typedef struct args_glGetMapfv args_glGetMapfv;


// -- glGetMapiv
struct args_glGetMapiv{
     GLenum target;
	 GLenum query;
	 GLint *v ;
};

typedef struct args_glGetMapiv args_glGetMapiv;


// -- glEvalCoord1d
struct args_glEvalCoord1d{
     GLdouble u ;
};

typedef struct args_glEvalCoord1d args_glEvalCoord1d;


// -- glEvalCoord1f
struct args_glEvalCoord1f{
     GLfloat u ;
};

typedef struct args_glEvalCoord1f args_glEvalCoord1f;


// -- glEvalCoord1dv
struct args_glEvalCoord1dv{
     const GLdouble *u ;
};

typedef struct args_glEvalCoord1dv args_glEvalCoord1dv;


// -- glEvalCoord1fv
struct args_glEvalCoord1fv{
     const GLfloat *u ;
};

typedef struct args_glEvalCoord1fv args_glEvalCoord1fv;


// -- glEvalCoord2d
struct args_glEvalCoord2d{
     GLdouble u;
	 GLdouble v ;
};

typedef struct args_glEvalCoord2d args_glEvalCoord2d;


// -- glEvalCoord2f
struct args_glEvalCoord2f{
     GLfloat u;
	 GLfloat v ;
};

typedef struct args_glEvalCoord2f args_glEvalCoord2f;


// -- glEvalCoord2dv
struct args_glEvalCoord2dv{
     const GLdouble *u ;
};

typedef struct args_glEvalCoord2dv args_glEvalCoord2dv;


// -- glEvalCoord2fv
struct args_glEvalCoord2fv{
     const GLfloat *u ;
};

typedef struct args_glEvalCoord2fv args_glEvalCoord2fv;


// -- glMapGrid1d
struct args_glMapGrid1d{
     GLint un;
	 GLdouble u1;
	 GLdouble u2 ;
};

typedef struct args_glMapGrid1d args_glMapGrid1d;


// -- glMapGrid1f
struct args_glMapGrid1f{
     GLint un;
	 GLfloat u1;
	 GLfloat u2 ;
};

typedef struct args_glMapGrid1f args_glMapGrid1f;


// -- glMapGrid2d
struct args_glMapGrid2d{
     GLint un;
	 GLdouble u1;
	 GLdouble u2;
	 GLint vn;
	 GLdouble v1;
	 GLdouble v2 ;
};

typedef struct args_glMapGrid2d args_glMapGrid2d;


// -- glMapGrid2f
struct args_glMapGrid2f{
     GLint un;
	 GLfloat u1;
	 GLfloat u2;
	 GLint vn;
	 GLfloat v1;
	 GLfloat v2 ;
};

typedef struct args_glMapGrid2f args_glMapGrid2f;


// -- glEvalPoint1
struct args_glEvalPoint1{
     GLint i ;
};

typedef struct args_glEvalPoint1 args_glEvalPoint1;


// -- glEvalPoint2
struct args_glEvalPoint2{
     GLint i;
	 GLint j ;
};

typedef struct args_glEvalPoint2 args_glEvalPoint2;


// -- glEvalMesh1
struct args_glEvalMesh1{
     GLenum mode;
	 GLint i1;
	 GLint i2 ;
};

typedef struct args_glEvalMesh1 args_glEvalMesh1;


// -- glEvalMesh2
struct args_glEvalMesh2{
     GLenum mode;
	 GLint i1;
	 GLint i2;
	 GLint j1;
	 GLint j2 ;
};

typedef struct args_glEvalMesh2 args_glEvalMesh2;


// -- glFogf
struct args_glFogf{
     GLenum pname;
	 GLfloat param ;
};

typedef struct args_glFogf args_glFogf;


// -- glFogi
struct args_glFogi{
     GLenum pname;
	 GLint param ;
};

typedef struct args_glFogi args_glFogi;


// -- glFogfv
struct args_glFogfv{
     GLenum pname;
	 const GLfloat *params ;
};

typedef struct args_glFogfv args_glFogfv;


// -- glFogiv
struct args_glFogiv{
     GLenum pname;
	 const GLint *params ;
};

typedef struct args_glFogiv args_glFogiv;


// -- glFeedbackBuffer
struct args_glFeedbackBuffer{
     GLsizei size;
	 GLenum type;
	 GLfloat *buffer ;
};

typedef struct args_glFeedbackBuffer args_glFeedbackBuffer;


// -- glPassThrough
struct args_glPassThrough{
     GLfloat token ;
};

typedef struct args_glPassThrough args_glPassThrough;


// -- glSelectBuffer
struct args_glSelectBuffer{
     GLsizei size;
	 GLuint *buffer ;
};

typedef struct args_glSelectBuffer args_glSelectBuffer;


// -- glLoadName
struct args_glLoadName{
     GLuint name ;
};

typedef struct args_glLoadName args_glLoadName;


// -- glPushName
struct args_glPushName{
     GLuint name ;
};

typedef struct args_glPushName args_glPushName;


// -- glDrawRangeElements
struct args_glDrawRangeElements{
     GLenum mode;
	 GLuint start;
	 GLuint end;
	 GLsizei count;
	 GLenum type;
	 const GLvoid *indices ;
};

typedef struct args_glDrawRangeElements args_glDrawRangeElements;


// -- glTexImage3D
struct args_glTexImage3D{
     GLenum target;
	 GLint level;
	 GLint internalFormat;
	 GLsizei width;
	 GLsizei height;
	 GLsizei depth;
	 GLint border;
	 GLenum format;
	 GLenum type;
	 const GLvoid *pixels ;
};

typedef struct args_glTexImage3D args_glTexImage3D;


// -- glTexSubImage3D
struct args_glTexSubImage3D{
     GLenum target;
	 GLint level;
	 GLint xoffset;
	 GLint yoffset;
	 GLint zoffset;
	 GLsizei width;
	 GLsizei height;
	 GLsizei depth;
	 GLenum format;
	 GLenum type;
	 const GLvoid *pixels;
};

typedef struct args_glTexSubImage3D args_glTexSubImage3D;


// -- glCopyTexSubImage3D
struct args_glCopyTexSubImage3D{
     GLenum target;
	 GLint level;
	 GLint xoffset;
	 GLint yoffset;
	 GLint zoffset;
	 GLint x;
	 GLint y;
	 GLsizei width;
	 GLsizei height ;
};

typedef struct args_glCopyTexSubImage3D args_glCopyTexSubImage3D;


// -- glColorTable
struct args_glColorTable{
     GLenum target;
	 GLenum internalformat;
	 GLsizei width;
	 GLenum format;
	 GLenum type;
	 const GLvoid *table ;
};

typedef struct args_glColorTable args_glColorTable;


// -- glColorSubTable
struct args_glColorSubTable{
     GLenum target;
	 GLsizei start;
	 GLsizei count;
	 GLenum format;
	 GLenum type;
	 const GLvoid *data ;
};

typedef struct args_glColorSubTable args_glColorSubTable;


// -- glColorTableParameteriv
struct args_glColorTableParameteriv{
    GLenum target;
	 GLenum pname;
	 const GLint *params;
};

typedef struct args_glColorTableParameteriv args_glColorTableParameteriv;


// -- glColorTableParameterfv
struct args_glColorTableParameterfv{
    GLenum target;
	 GLenum pname;
	 const GLfloat *params;
};

typedef struct args_glColorTableParameterfv args_glColorTableParameterfv;


// -- glCopyColorSubTable
struct args_glCopyColorSubTable{
     GLenum target;
	 GLsizei start;
	GLint x;
	 GLint y;
	 GLsizei width ;
};

typedef struct args_glCopyColorSubTable args_glCopyColorSubTable;


// -- glCopyColorTable
struct args_glCopyColorTable{
     GLenum target;
	 GLenum internalformat;
	 GLint x;
	 GLint y;
	 GLsizei width ;
};

typedef struct args_glCopyColorTable args_glCopyColorTable;


// -- glGetColorTable
struct args_glGetColorTable{
     GLenum target;
	 GLenum format;
	 GLenum type;
	 GLvoid *table ;
};

typedef struct args_glGetColorTable args_glGetColorTable;


// -- glGetColorTableParameterfv
struct args_glGetColorTableParameterfv{
     GLenum target;
	 GLenum pname;
	 GLfloat *params ;
};

typedef struct args_glGetColorTableParameterfv args_glGetColorTableParameterfv;


// -- glGetColorTableParameteriv
struct args_glGetColorTableParameteriv{
     GLenum target;
	 GLenum pname;
	 GLint *params ;
};

typedef struct args_glGetColorTableParameteriv args_glGetColorTableParameteriv;


// -- glBlendEquation
struct args_glBlendEquation{
     GLenum mode ;
};

typedef struct args_glBlendEquation args_glBlendEquation;


// -- glBlendColor
struct args_glBlendColor{
     GLclampf red;
	 GLclampf green;
	 GLclampf blue;
	 GLclampf alpha ;
};

typedef struct args_glBlendColor args_glBlendColor;


// -- glHistogram
struct args_glHistogram{
     GLenum target;
	 GLsizei width;
	 GLenum internalformat;
	 GLboolean sink ;
};

typedef struct args_glHistogram args_glHistogram;


// -- glResetHistogram
struct args_glResetHistogram{
     GLenum target ;
};

typedef struct args_glResetHistogram args_glResetHistogram;


// -- glGetHistogram
struct args_glGetHistogram{
     GLenum target;
	 GLboolean reset;
	 GLenum format;
	 GLenum type;
	 GLvoid *values ;
};

typedef struct args_glGetHistogram args_glGetHistogram;


// -- glGetHistogramParameterfv
struct args_glGetHistogramParameterfv{
     GLenum target;
	 GLenum pname;
	 GLfloat *params ;
};

typedef struct args_glGetHistogramParameterfv args_glGetHistogramParameterfv;


// -- glGetHistogramParameteriv
struct args_glGetHistogramParameteriv{
     GLenum target;
	 GLenum pname;
	 GLint *params ;
};

typedef struct args_glGetHistogramParameteriv args_glGetHistogramParameteriv;


// -- glMinmax
struct args_glMinmax{
     GLenum target;
	 GLenum internalformat;
	 GLboolean sink ;
};

typedef struct args_glMinmax args_glMinmax;


// -- glResetMinmax
struct args_glResetMinmax{
     GLenum target ;
};

typedef struct args_glResetMinmax args_glResetMinmax;


// -- glGetMinmax
struct args_glGetMinmax{
     GLenum target;
	 GLboolean reset;
	 GLenum format;
	 GLenum types;
	 GLvoid *values ;
};

typedef struct args_glGetMinmax args_glGetMinmax;


// -- glGetMinmaxParameterfv
struct args_glGetMinmaxParameterfv{
     GLenum target;
	 GLenum pname;
	 GLfloat *params ;
};

typedef struct args_glGetMinmaxParameterfv args_glGetMinmaxParameterfv;


// -- glGetMinmaxParameteriv
struct args_glGetMinmaxParameteriv{
     GLenum target;
	 GLenum pname;
	 GLint *params ;
};

typedef struct args_glGetMinmaxParameteriv args_glGetMinmaxParameteriv;


// -- glConvolutionFilter1D
struct args_glConvolutionFilter1D{
     GLenum target;
	 GLenum internalformat;
	 GLsizei width;
	 GLenum format;
	 GLenum type;
	 const GLvoid *image ;
};

typedef struct args_glConvolutionFilter1D args_glConvolutionFilter1D;


// -- glConvolutionFilter2D
struct args_glConvolutionFilter2D{
     GLenum target;
	 GLenum internalformat;
	 GLsizei width;
	 GLsizei height;
	 GLenum format;
	 GLenum type;
	 const GLvoid *image ;
};

typedef struct args_glConvolutionFilter2D args_glConvolutionFilter2D;


// -- glConvolutionParameterf
struct args_glConvolutionParameterf{
     GLenum target;
	 GLenum pname;
	 GLfloat params ;
};

typedef struct args_glConvolutionParameterf args_glConvolutionParameterf;


// -- glConvolutionParameterfv
struct args_glConvolutionParameterfv{
     GLenum target;
	 GLenum pname;
	 const GLfloat *params ;
};

typedef struct args_glConvolutionParameterfv args_glConvolutionParameterfv;


// -- glConvolutionParameteri
struct args_glConvolutionParameteri{
     GLenum target;
	 GLenum pname;
	 GLint params ;
};

typedef struct args_glConvolutionParameteri args_glConvolutionParameteri;


// -- glConvolutionParameteriv
struct args_glConvolutionParameteriv{
     GLenum target;
	 GLenum pname;
	 const GLint *params ;
};

typedef struct args_glConvolutionParameteriv args_glConvolutionParameteriv;


// -- glCopyConvolutionFilter1D
struct args_glCopyConvolutionFilter1D{
     GLenum target;
	 GLenum internalformat;
	 GLint x;
	 GLint y;
	 GLsizei width ;
};

typedef struct args_glCopyConvolutionFilter1D args_glCopyConvolutionFilter1D;


// -- glCopyConvolutionFilter2D
struct args_glCopyConvolutionFilter2D{
     GLenum target;
	 GLenum internalformat;
	 GLint x;
	 GLint y;
	 GLsizei width;
	 GLsizei height;
};

typedef struct args_glCopyConvolutionFilter2D args_glCopyConvolutionFilter2D;


// -- glGetConvolutionFilter
struct args_glGetConvolutionFilter{
     GLenum target;
	 GLenum format;
	 GLenum type;
	 GLvoid *image ;
};

typedef struct args_glGetConvolutionFilter args_glGetConvolutionFilter;


// -- glGetConvolutionParameterfv
struct args_glGetConvolutionParameterfv{
     GLenum target;
	 GLenum pname;
	 GLfloat *params ;
};

typedef struct args_glGetConvolutionParameterfv args_glGetConvolutionParameterfv;


// -- glGetConvolutionParameteriv
struct args_glGetConvolutionParameteriv{
     GLenum target;
	 GLenum pname;
	 GLint *params ;
};

typedef struct args_glGetConvolutionParameteriv args_glGetConvolutionParameteriv;


// -- glSeparableFilter2D
struct args_glSeparableFilter2D{
     GLenum target;
	 GLenum internalformat;
	 GLsizei width;
	 GLsizei height;
	 GLenum format;
	 GLenum type;
	 const GLvoid *row;
	 const GLvoid *column ;
};

typedef struct args_glSeparableFilter2D args_glSeparableFilter2D;


// -- glGetSeparableFilter
struct args_glGetSeparableFilter{
     GLenum target;
	 GLenum format;
	 GLenum type;
	 GLvoid *row;
	 GLvoid *column;
	 GLvoid *span ;
};

typedef struct args_glGetSeparableFilter args_glGetSeparableFilter;


// -- glActiveTexture
struct args_glActiveTexture{
     GLenum texture ;
};

typedef struct args_glActiveTexture args_glActiveTexture;


// -- glClientActiveTexture
struct args_glClientActiveTexture{
     GLenum texture ;
};

typedef struct args_glClientActiveTexture args_glClientActiveTexture;


// -- glCompressedTexImage1D
struct args_glCompressedTexImage1D{
     GLenum target;
	 GLint level;
	 GLenum internalformat;
	 GLsizei width;
	 GLint border;
	 GLsizei imageSize;
	 const GLvoid *data ;
};

typedef struct args_glCompressedTexImage1D args_glCompressedTexImage1D;


// -- glCompressedTexImage2D
struct args_glCompressedTexImage2D{
     GLenum target;
	 GLint level;
	 GLenum internalformat;
	 GLsizei width;
	 GLsizei height;
	 GLint border;
	 GLsizei imageSize;
	 const GLvoid *data ;
};

typedef struct args_glCompressedTexImage2D args_glCompressedTexImage2D;


// -- glCompressedTexImage3D
struct args_glCompressedTexImage3D{
     GLenum target;
	 GLint level;
	 GLenum internalformat;
	 GLsizei width;
	 GLsizei height;
	 GLsizei depth;
	 GLint border;
	 GLsizei imageSize;
	 const GLvoid *data ;
};

typedef struct args_glCompressedTexImage3D args_glCompressedTexImage3D;


// -- glCompressedTexSubImage1D
struct args_glCompressedTexSubImage1D{
     GLenum target;
	 GLint level;
	 GLint xoffset;
	 GLsizei width;
	 GLenum format;
	 GLsizei imageSize;
	 const GLvoid *data ;
};

typedef struct args_glCompressedTexSubImage1D args_glCompressedTexSubImage1D;


// -- glCompressedTexSubImage2D
struct args_glCompressedTexSubImage2D{
     GLenum target;
	 GLint level;
	 GLint xoffset;
	 GLint yoffset;
	 GLsizei width;
	 GLsizei height;
	 GLenum format;
	 GLsizei imageSize;
	 const GLvoid *data ;
};

typedef struct args_glCompressedTexSubImage2D args_glCompressedTexSubImage2D;


// -- glCompressedTexSubImage3D
struct args_glCompressedTexSubImage3D{
     GLenum target;
	 GLint level;
	 GLint xoffset;
	 GLint yoffset;
	 GLint zoffset;
	 GLsizei width;
	 GLsizei height;
	 GLsizei depth;
	 GLenum format;
	 GLsizei imageSize;
	 const GLvoid *data ;
};

typedef struct args_glCompressedTexSubImage3D args_glCompressedTexSubImage3D;


// -- glGetCompressedTexImage
struct args_glGetCompressedTexImage{
     GLenum target;
	 GLint lod;
	 GLvoid *img ;
};

typedef struct args_glGetCompressedTexImage args_glGetCompressedTexImage;


// -- glMultiTexCoord1d
struct args_glMultiTexCoord1d{
     GLenum target;
	 GLdouble s ;
};

typedef struct args_glMultiTexCoord1d args_glMultiTexCoord1d;


// -- glMultiTexCoord1dv
struct args_glMultiTexCoord1dv{
     GLenum target;
	 const GLdouble *v ;
};

typedef struct args_glMultiTexCoord1dv args_glMultiTexCoord1dv;


// -- glMultiTexCoord1f
struct args_glMultiTexCoord1f{
     GLenum target;
	 GLfloat s ;
};

typedef struct args_glMultiTexCoord1f args_glMultiTexCoord1f;


// -- glMultiTexCoord1fv
struct args_glMultiTexCoord1fv{
     GLenum target;
	 const GLfloat *v ;
};

typedef struct args_glMultiTexCoord1fv args_glMultiTexCoord1fv;


// -- glMultiTexCoord1i
struct args_glMultiTexCoord1i{
     GLenum target;
	 GLint s ;
};

typedef struct args_glMultiTexCoord1i args_glMultiTexCoord1i;


// -- glMultiTexCoord1iv
struct args_glMultiTexCoord1iv{
     GLenum target;
	 const GLint *v ;
};

typedef struct args_glMultiTexCoord1iv args_glMultiTexCoord1iv;


// -- glMultiTexCoord1s
struct args_glMultiTexCoord1s{
     GLenum target;
	 GLshort s ;
};

typedef struct args_glMultiTexCoord1s args_glMultiTexCoord1s;


// -- glMultiTexCoord1sv
struct args_glMultiTexCoord1sv{
     GLenum target;
	 const GLshort *v ;
};

typedef struct args_glMultiTexCoord1sv args_glMultiTexCoord1sv;


// -- glMultiTexCoord2d
struct args_glMultiTexCoord2d{
     GLenum target;
	 GLdouble s;
	 GLdouble t ;
};

typedef struct args_glMultiTexCoord2d args_glMultiTexCoord2d;


// -- glMultiTexCoord2dv
struct args_glMultiTexCoord2dv{
     GLenum target;
	 const GLdouble *v ;
};

typedef struct args_glMultiTexCoord2dv args_glMultiTexCoord2dv;


// -- glMultiTexCoord2f
struct args_glMultiTexCoord2f{
     GLenum target;
	 GLfloat s;
	 GLfloat t ;
};

typedef struct args_glMultiTexCoord2f args_glMultiTexCoord2f;


// -- glMultiTexCoord2fv
struct args_glMultiTexCoord2fv{
     GLenum target;
	 const GLfloat *v ;
};

typedef struct args_glMultiTexCoord2fv args_glMultiTexCoord2fv;


// -- glMultiTexCoord2i
struct args_glMultiTexCoord2i{
     GLenum target;
	 GLint s;
	 GLint t ;
};

typedef struct args_glMultiTexCoord2i args_glMultiTexCoord2i;


// -- glMultiTexCoord2iv
struct args_glMultiTexCoord2iv{
     GLenum target;
	 const GLint *v ;
};

typedef struct args_glMultiTexCoord2iv args_glMultiTexCoord2iv;


// -- glMultiTexCoord2s
struct args_glMultiTexCoord2s{
     GLenum target;
	 GLshort s;
	 GLshort t ;
};

typedef struct args_glMultiTexCoord2s args_glMultiTexCoord2s;


// -- glMultiTexCoord2sv
struct args_glMultiTexCoord2sv{
     GLenum target;
	 const GLshort *v ;
};

typedef struct args_glMultiTexCoord2sv args_glMultiTexCoord2sv;


// -- glMultiTexCoord3d
struct args_glMultiTexCoord3d{
     GLenum target;
	 GLdouble s;
	 GLdouble t;
	 GLdouble r ;
};

typedef struct args_glMultiTexCoord3d args_glMultiTexCoord3d;


// -- glMultiTexCoord3dv
struct args_glMultiTexCoord3dv{
     GLenum target;
	 const GLdouble *v ;
};

typedef struct args_glMultiTexCoord3dv args_glMultiTexCoord3dv;


// -- glMultiTexCoord3f
struct args_glMultiTexCoord3f{
     GLenum target;
	 GLfloat s;
	 GLfloat t;
	 GLfloat r ;
};

typedef struct args_glMultiTexCoord3f args_glMultiTexCoord3f;


// -- glMultiTexCoord3fv
struct args_glMultiTexCoord3fv{
     GLenum target;
	 const GLfloat *v ;
};

typedef struct args_glMultiTexCoord3fv args_glMultiTexCoord3fv;


// -- glMultiTexCoord3i
struct args_glMultiTexCoord3i{
     GLenum target;
	 GLint s;
	 GLint t;
	 GLint r ;
};

typedef struct args_glMultiTexCoord3i args_glMultiTexCoord3i;


// -- glMultiTexCoord3iv
struct args_glMultiTexCoord3iv{
     GLenum target;
	 const GLint *v ;
};

typedef struct args_glMultiTexCoord3iv args_glMultiTexCoord3iv;


// -- glMultiTexCoord3s
struct args_glMultiTexCoord3s{
     GLenum target;
	 GLshort s;
	 GLshort t;
	 GLshort r ;
};

typedef struct args_glMultiTexCoord3s args_glMultiTexCoord3s;


// -- glMultiTexCoord3sv
struct args_glMultiTexCoord3sv{
     GLenum target;
	 const GLshort *v ;
};

typedef struct args_glMultiTexCoord3sv args_glMultiTexCoord3sv;


// -- glMultiTexCoord4d
struct args_glMultiTexCoord4d{
     GLenum target;
	 GLdouble s;
	 GLdouble t;
	 GLdouble r;
	 GLdouble q ;
};

typedef struct args_glMultiTexCoord4d args_glMultiTexCoord4d;


// -- glMultiTexCoord4dv
struct args_glMultiTexCoord4dv{
     GLenum target;
	 const GLdouble *v ;
};

typedef struct args_glMultiTexCoord4dv args_glMultiTexCoord4dv;


// -- glMultiTexCoord4f
struct args_glMultiTexCoord4f{
     GLenum target;
	 GLfloat s;
	 GLfloat t;
	 GLfloat r;
	 GLfloat q ;
};

typedef struct args_glMultiTexCoord4f args_glMultiTexCoord4f;


// -- glMultiTexCoord4fv
struct args_glMultiTexCoord4fv{
     GLenum target;
	 const GLfloat *v ;
};

typedef struct args_glMultiTexCoord4fv args_glMultiTexCoord4fv;


// -- glMultiTexCoord4i
struct args_glMultiTexCoord4i{
     GLenum target;
	 GLint s;
	 GLint t;
	 GLint r;
	 GLint q ;
};

typedef struct args_glMultiTexCoord4i args_glMultiTexCoord4i;


// -- glMultiTexCoord4iv
struct args_glMultiTexCoord4iv{
     GLenum target;
	 const GLint *v ;
};

typedef struct args_glMultiTexCoord4iv args_glMultiTexCoord4iv;


// -- glMultiTexCoord4s
struct args_glMultiTexCoord4s{
     GLenum target;
	 GLshort s;
	 GLshort t;
	 GLshort r;
	 GLshort q ;
};

typedef struct args_glMultiTexCoord4s args_glMultiTexCoord4s;


// -- glMultiTexCoord4sv
struct args_glMultiTexCoord4sv{
     GLenum target;
	 const GLshort *v ;
};

typedef struct args_glMultiTexCoord4sv args_glMultiTexCoord4sv;


// -- glSampleCoverage
struct args_glSampleCoverage{
     GLclampf value;
	 GLboolean invert ;
};

typedef struct args_glSampleCoverage args_glSampleCoverage;


// -- glActiveTextureARB
struct args_glActiveTextureARB{
    GLenum texture;
};

typedef struct args_glActiveTextureARB args_glActiveTextureARB;


// -- glClientActiveTextureARB
struct args_glClientActiveTextureARB{
    GLenum texture;
};

typedef struct args_glClientActiveTextureARB args_glClientActiveTextureARB;


// -- glMultiTexCoord1dARB
struct args_glMultiTexCoord1dARB{
    GLenum target;
	 GLdouble s;
};

typedef struct args_glMultiTexCoord1dARB args_glMultiTexCoord1dARB;


// -- glMultiTexCoord1dvARB
struct args_glMultiTexCoord1dvARB{
    GLenum target;
	 const GLdouble *v;
};

typedef struct args_glMultiTexCoord1dvARB args_glMultiTexCoord1dvARB;


// -- glMultiTexCoord1fARB
struct args_glMultiTexCoord1fARB{
    GLenum target;
	 GLfloat s;
};

typedef struct args_glMultiTexCoord1fARB args_glMultiTexCoord1fARB;


// -- glMultiTexCoord1fvARB
struct args_glMultiTexCoord1fvARB{
    GLenum target;
	 const GLfloat *v;
};

typedef struct args_glMultiTexCoord1fvARB args_glMultiTexCoord1fvARB;


// -- glMultiTexCoord1iARB
struct args_glMultiTexCoord1iARB{
    GLenum target;
	 GLint s;
};

typedef struct args_glMultiTexCoord1iARB args_glMultiTexCoord1iARB;


// -- glMultiTexCoord1ivARB
struct args_glMultiTexCoord1ivARB{
    GLenum target;
	 const GLint *v;
};

typedef struct args_glMultiTexCoord1ivARB args_glMultiTexCoord1ivARB;


// -- glMultiTexCoord1sARB
struct args_glMultiTexCoord1sARB{
    GLenum target;
	 GLshort s;
};

typedef struct args_glMultiTexCoord1sARB args_glMultiTexCoord1sARB;


// -- glMultiTexCoord1svARB
struct args_glMultiTexCoord1svARB{
    GLenum target;
	 const GLshort *v;
};

typedef struct args_glMultiTexCoord1svARB args_glMultiTexCoord1svARB;


// -- glMultiTexCoord2dARB
struct args_glMultiTexCoord2dARB{
    GLenum target;
	 GLdouble s;
	 GLdouble t;
};

typedef struct args_glMultiTexCoord2dARB args_glMultiTexCoord2dARB;


// -- glMultiTexCoord2dvARB
struct args_glMultiTexCoord2dvARB{
    GLenum target;
	 const GLdouble *v;
};

typedef struct args_glMultiTexCoord2dvARB args_glMultiTexCoord2dvARB;


// -- glMultiTexCoord2fARB
struct args_glMultiTexCoord2fARB{
    GLenum target;
	 GLfloat s;
	 GLfloat t;
};

typedef struct args_glMultiTexCoord2fARB args_glMultiTexCoord2fARB;


// -- glMultiTexCoord2fvARB
struct args_glMultiTexCoord2fvARB{
    GLenum target;
	 const GLfloat *v;
};

typedef struct args_glMultiTexCoord2fvARB args_glMultiTexCoord2fvARB;


// -- glMultiTexCoord2iARB
struct args_glMultiTexCoord2iARB{
    GLenum target;
	 GLint s;
	 GLint t;
};

typedef struct args_glMultiTexCoord2iARB args_glMultiTexCoord2iARB;


// -- glMultiTexCoord2ivARB
struct args_glMultiTexCoord2ivARB{
    GLenum target;
	 const GLint *v;
};

typedef struct args_glMultiTexCoord2ivARB args_glMultiTexCoord2ivARB;


// -- glMultiTexCoord2sARB
struct args_glMultiTexCoord2sARB{
    GLenum target;
	 GLshort s;
	 GLshort t;
};

typedef struct args_glMultiTexCoord2sARB args_glMultiTexCoord2sARB;


// -- glMultiTexCoord2svARB
struct args_glMultiTexCoord2svARB{
    GLenum target;
	 const GLshort *v;
};

typedef struct args_glMultiTexCoord2svARB args_glMultiTexCoord2svARB;


// -- glMultiTexCoord3dARB
struct args_glMultiTexCoord3dARB{
    GLenum target;
	 GLdouble s;
	 GLdouble t;
	 GLdouble r;
};

typedef struct args_glMultiTexCoord3dARB args_glMultiTexCoord3dARB;


// -- glMultiTexCoord3dvARB
struct args_glMultiTexCoord3dvARB{
    GLenum target;
	 const GLdouble *v;
};

typedef struct args_glMultiTexCoord3dvARB args_glMultiTexCoord3dvARB;


// -- glMultiTexCoord3fARB
struct args_glMultiTexCoord3fARB{
    GLenum target;
	 GLfloat s;
	 GLfloat t;
	 GLfloat r;
};

typedef struct args_glMultiTexCoord3fARB args_glMultiTexCoord3fARB;


// -- glMultiTexCoord3fvARB
struct args_glMultiTexCoord3fvARB{
    GLenum target;
	 const GLfloat *v;
};

typedef struct args_glMultiTexCoord3fvARB args_glMultiTexCoord3fvARB;


// -- glMultiTexCoord3iARB
struct args_glMultiTexCoord3iARB{
    GLenum target;
	 GLint s;
	 GLint t;
	 GLint r;
};

typedef struct args_glMultiTexCoord3iARB args_glMultiTexCoord3iARB;


// -- glMultiTexCoord3ivARB
struct args_glMultiTexCoord3ivARB{
    GLenum target;
	 const GLint *v;
};

typedef struct args_glMultiTexCoord3ivARB args_glMultiTexCoord3ivARB;


// -- glMultiTexCoord3sARB
struct args_glMultiTexCoord3sARB{
    GLenum target;
	 GLshort s;
	 GLshort t;
	 GLshort r;
};

typedef struct args_glMultiTexCoord3sARB args_glMultiTexCoord3sARB;


// -- glMultiTexCoord3svARB
struct args_glMultiTexCoord3svARB{
    GLenum target;
	 const GLshort *v;
};

typedef struct args_glMultiTexCoord3svARB args_glMultiTexCoord3svARB;


// -- glMultiTexCoord4dARB
struct args_glMultiTexCoord4dARB{
    GLenum target;
	 GLdouble s;
	 GLdouble t;
	 GLdouble r;
	 GLdouble q;
};

typedef struct args_glMultiTexCoord4dARB args_glMultiTexCoord4dARB;


// -- glMultiTexCoord4dvARB
struct args_glMultiTexCoord4dvARB{
    GLenum target;
	 const GLdouble *v;
};

typedef struct args_glMultiTexCoord4dvARB args_glMultiTexCoord4dvARB;


// -- glMultiTexCoord4fARB
struct args_glMultiTexCoord4fARB{
    GLenum target;
	 GLfloat s;
	 GLfloat t;
	 GLfloat r;
	 GLfloat q;
};

typedef struct args_glMultiTexCoord4fARB args_glMultiTexCoord4fARB;


// -- glMultiTexCoord4fvARB
struct args_glMultiTexCoord4fvARB{
    GLenum target;
	 const GLfloat *v;
};

typedef struct args_glMultiTexCoord4fvARB args_glMultiTexCoord4fvARB;


// -- glMultiTexCoord4iARB
struct args_glMultiTexCoord4iARB{
    GLenum target;
	 GLint s;
	 GLint t;
	 GLint r;
	 GLint q;
};

typedef struct args_glMultiTexCoord4iARB args_glMultiTexCoord4iARB;


// -- glMultiTexCoord4ivARB
struct args_glMultiTexCoord4ivARB{
    GLenum target;
	 const GLint *v;
};

typedef struct args_glMultiTexCoord4ivARB args_glMultiTexCoord4ivARB;


// -- glMultiTexCoord4sARB
struct args_glMultiTexCoord4sARB{
    GLenum target;
	 GLshort s;
	 GLshort t;
	 GLshort r;
	 GLshort q;
};

typedef struct args_glMultiTexCoord4sARB args_glMultiTexCoord4sARB;


// -- glMultiTexCoord4svARB
struct args_glMultiTexCoord4svARB{
    GLenum target;
	 const GLshort *v;
};

typedef struct args_glMultiTexCoord4svARB args_glMultiTexCoord4svARB;


// -- glXChooseVisual
struct args_glXChooseVisual{
    Display *dpy;
	 int screen;
	 int *attribList;
};

typedef struct args_glXChooseVisual args_glXChooseVisual;


// -- glXQueryDrawable
struct args_glXQueryDrawable{
    Display *dpy;
	 GLXDrawable draw;
	 int attribute;
	 unsigned int *value;
};

typedef struct args_glXQueryDrawable args_glXQueryDrawable;


// -- glXCreateContext
struct args_glXCreateContext{
    Display *dpy;
	 XVisualInfo * vis;
	 GLXContext shareList;
	 Bool direct;
};

typedef struct args_glXCreateContext args_glXCreateContext;


// -- glXCreateContext
struct args_glXCreateContext{
    Display *dpy;
	 XVisualInfo *vis;
	 GLXContext shareList;
	 Bool direct;
};

typedef struct args_glXCreateContext args_glXCreateContext;


// -- glXDestroyContext
struct args_glXDestroyContext{
     Display *dpy;
	 GLXContext ctx ;
};

typedef struct args_glXDestroyContext args_glXDestroyContext;


// -- glXSwapBuffers
struct args_glXSwapBuffers{
     Display *dpy;
	 GLXDrawable drawable ;
};

typedef struct args_glXSwapBuffers args_glXSwapBuffers;


// -- glXDestroyGLXPixmap
struct args_glXDestroyGLXPixmap{
     Display *dpy;
	 GLXPixmap pixmap ;
};

typedef struct args_glXDestroyGLXPixmap args_glXDestroyGLXPixmap;


// -- glXQueryExtension
struct args_glXQueryExtension{
     Display *dpy;
	 int *errorb;
	 int *event ;
};

typedef struct args_glXQueryExtension args_glXQueryExtension;


// -- glXQueryVersion
struct args_glXQueryVersion{
     Display *dpy;
	 int *maj;
	 int *min ;
};

typedef struct args_glXQueryVersion args_glXQueryVersion;


// -- glXIsDirect
struct args_glXIsDirect{
     Display *dpy;
	 GLXContext ctx ;
};

typedef struct args_glXIsDirect args_glXIsDirect;


// -- glXUseXFont
struct args_glXUseXFont{
     Font font;
	 int first;
	 int count;
	 int list ;
};

typedef struct args_glXUseXFont args_glXUseXFont;


// -- glXQueryExtensionsString
struct args_glXQueryExtensionsString{
     Display *dpy;
	 int screen ;
};

typedef struct args_glXQueryExtensionsString args_glXQueryExtensionsString;


// -- glXDestroyWindow
struct args_glXDestroyWindow{
     Display *dpy;
	 GLXWindow window ;
};

typedef struct args_glXDestroyWindow args_glXDestroyWindow;


// -- glXDestroyPixmap
struct args_glXDestroyPixmap{
     Display *dpy;
	 GLXPixmap pixmap ;
};

typedef struct args_glXDestroyPixmap args_glXDestroyPixmap;


// -- glXDestroyPbuffer
struct args_glXDestroyPbuffer{
     Display *dpy;
	 GLXPbuffer pbuf ;
};

typedef struct args_glXDestroyPbuffer args_glXDestroyPbuffer;


// -- glXGetProcAddressARB
struct args_glXGetProcAddressARB{
    const GLubyte *procname;
};

typedef struct args_glXGetProcAddressARB args_glXGetProcAddressARB;


// -- glXGetProcAddress
struct args_glXGetProcAddress{
    const GLubyte *procname;
};

typedef struct args_glXGetProcAddress args_glXGetProcAddress;


// -- glXAllocateMemoryNV
struct args_glXAllocateMemoryNV{
    GLsizei size;
	 GLfloat readfreq;
	 GLfloat writefreq;
	 GLfloat priority;
};

typedef struct args_glXAllocateMemoryNV args_glXAllocateMemoryNV;


// -- glXFreeMemoryNV
struct args_glXFreeMemoryNV{
    GLvoid *pointer;
};

typedef struct args_glXFreeMemoryNV args_glXFreeMemoryNV;

