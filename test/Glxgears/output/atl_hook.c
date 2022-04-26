#include "atl_header.h"
#include "atl_uh.h"

// -- XOpenDisplay
extern Display *XOpenDisplay(_Xconst char *display_name)
{
    args_XOpenDisplay argp;
    
    // Set function specific args
    argp.display_name = display_name;
    
    return xopendisplay_uh(argp);
}

// -- XPending
int XPending(Display *display)
{
    args_XPending argp;
    
    // Set function specific args
    argp.display = display;
    
    return xpending_uh(argp);
}

// -- XMapWindow
int XMapWindow(Display *display, Window w)
{
    args_XMapWindow argp;
    
    // Set function specific args
    argp.display = display;
	argp.w = w;
    
    return xmapwindow_uh(argp);
}

// -- XCreateColormap
extern Colormap XCreateColormap(Display* display, Window w, Visual*	visual, int	alloc )
{
    args_XCreateColormap argp;
    
    // Set function specific args
    argp.display = display;
	argp.w = w;
	argp.visual = visual;
	argp.alloc = alloc;
    
    return xcreatecolormap_uh(argp);
}

// -- XCreateWindow
extern Window XCreateWindow(Display* display, Window parent, int x, int y, unsigned int width, unsigned int height, unsigned int border_width, int	depth, unsigned int class, Visual* visual, unsigned long valuemask, XSetWindowAttributes* attributes)
{
    args_XCreateWindow argp;
    
    // Set function specific args
    argp.display = display;
	argp.parent = parent;
	argp.x = x;
	argp.y = y;
	argp.width = width;
	argp.height = height;
	argp.border_width = border_width;
	argp.depth = depth;
	argp.class = class;
	argp.visual = visual;
	argp.valuemask = valuemask;
	argp.attributes = attributes;
    
    return xcreatewindow_uh(argp);
}

// -- XFree
extern int XFree(void* data)
{
    args_XFree argp;
    
    // Set function specific args
    argp.data = data;
    
    return xfree_uh(argp);
}

// -- XSetNormalHints
extern int XSetNormalHints(Display *display, Window w, XSizeHints *hints)
{
    args_XSetNormalHints argp;
    
    // Set function specific args
    argp.display = display;
	argp.w = w;
	argp.hints = hints;
    
    return xsetnormalhints_uh(argp);
}

// -- XSetStandardProperties
extern int XSetStandardProperties(Display *display, Window w, _Xconst char *window_name, _Xconst char *icon_name, Pixmap icon_pixmap, char **argv, int argc, XSizeHints *hints)
{
    args_XSetStandardProperties argp;
    
    // Set function specific args
    argp.display = display;
	argp.w = w;
	argp.window_name = window_name;
	argp.icon_name = icon_name;
	argp.icon_pixmap = icon_pixmap;
	argp.*argv = *argv;
	argp.argc = argc;
	argp.hints = hints;
    
    return xsetstandardproperties_uh(argp);
}

// -- glClearIndex
void glClearIndex( GLfloat c )
{
    args_glClearIndex argp;

    // Set function specific args
    argp.c = c;

    glclearindex_uh(argp);
}

// -- glClearColor
void glClearColor( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha )
{
    args_glClearColor argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;
	argp.alpha = alpha;

    glclearcolor_uh(argp);
}

// -- glClear
void glClear( GLbitfield mask )
{
    args_glClear argp;

    // Set function specific args
    argp.mask = mask;

    glclear_uh(argp);
}

// -- glIndexMask
void glIndexMask( GLuint mask )
{
    args_glIndexMask argp;

    // Set function specific args
    argp.mask = mask;

    glindexmask_uh(argp);
}

// -- glColorMask
void glColorMask( GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha )
{
    args_glColorMask argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;
	argp.alpha = alpha;

    glcolormask_uh(argp);
}

// -- glAlphaFunc
void glAlphaFunc( GLenum func, GLclampf ref )
{
    args_glAlphaFunc argp;

    // Set function specific args
    argp.func = func;
	argp.ref = ref;

    glalphafunc_uh(argp);
}

// -- glBlendFunc
void glBlendFunc( GLenum sfactor, GLenum dfactor )
{
    args_glBlendFunc argp;

    // Set function specific args
    argp.sfactor = sfactor;
	argp.dfactor = dfactor;

    glblendfunc_uh(argp);
}

// -- glLogicOp
void glLogicOp( GLenum opcode )
{
    args_glLogicOp argp;

    // Set function specific args
    argp.opcode = opcode;

    gllogicop_uh(argp);
}

// -- glCullFace
void glCullFace( GLenum mode )
{
    args_glCullFace argp;

    // Set function specific args
    argp.mode = mode;

    glcullface_uh(argp);
}

// -- glFrontFace
void glFrontFace( GLenum mode )
{
    args_glFrontFace argp;

    // Set function specific args
    argp.mode = mode;

    glfrontface_uh(argp);
}

// -- glPointSize
void glPointSize( GLfloat size )
{
    args_glPointSize argp;

    // Set function specific args
    argp.size = size;

    glpointsize_uh(argp);
}

// -- glLineWidth
void glLineWidth( GLfloat width )
{
    args_glLineWidth argp;

    // Set function specific args
    argp.width = width;

    gllinewidth_uh(argp);
}

// -- glLineStipple
void glLineStipple( GLint factor, GLushort pattern )
{
    args_glLineStipple argp;

    // Set function specific args
    argp.factor = factor;
	argp.pattern = pattern;

    gllinestipple_uh(argp);
}

// -- glPolygonMode
void glPolygonMode( GLenum face, GLenum mode )
{
    args_glPolygonMode argp;

    // Set function specific args
    argp.face = face;
	argp.mode = mode;

    glpolygonmode_uh(argp);
}

// -- glPolygonOffset
void glPolygonOffset( GLfloat factor, GLfloat units )
{
    args_glPolygonOffset argp;

    // Set function specific args
    argp.factor = factor;
	argp.units = units;

    glpolygonoffset_uh(argp);
}

// -- glPolygonStipple
void glPolygonStipple( const GLubyte *mask )
{
    args_glPolygonStipple argp;

    // Set function specific args
    argp.mask = mask;

    glpolygonstipple_uh(argp);
}

// -- glGetPolygonStipple
void glGetPolygonStipple( GLubyte *mask )
{
    args_glGetPolygonStipple argp;

    // Set function specific args
    argp.mask = mask;

    glgetpolygonstipple_uh(argp);
}

// -- glEdgeFlag
void glEdgeFlag( GLboolean flag )
{
    args_glEdgeFlag argp;

    // Set function specific args
    argp.flag = flag;

    gledgeflag_uh(argp);
}

// -- glEdgeFlagv
void glEdgeFlagv( const GLboolean *flag )
{
    args_glEdgeFlagv argp;

    // Set function specific args
    argp.flag = flag;

    gledgeflagv_uh(argp);
}

// -- glScissor
void glScissor( GLint x, GLint y, GLsizei width, GLsizei height)
{
    args_glScissor argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.width = width;
	argp.height = height;

    glscissor_uh(argp);
}

// -- glClipPlane
void glClipPlane( GLenum plane, const GLdouble *equation )
{
    args_glClipPlane argp;

    // Set function specific args
    argp.plane = plane;
	argp.equation = equation;

    glclipplane_uh(argp);
}

// -- glGetClipPlane
void glGetClipPlane( GLenum plane, GLdouble *equation )
{
    args_glGetClipPlane argp;

    // Set function specific args
    argp.plane = plane;
	argp.equation = equation;

    glgetclipplane_uh(argp);
}

// -- glDrawBuffer
void glDrawBuffer( GLenum mode )
{
    args_glDrawBuffer argp;

    // Set function specific args
    argp.mode = mode;

    gldrawbuffer_uh(argp);
}

// -- glReadBuffer
void glReadBuffer( GLenum mode )
{
    args_glReadBuffer argp;

    // Set function specific args
    argp.mode = mode;

    glreadbuffer_uh(argp);
}

// -- glEnable
void glEnable( GLenum cap )
{
    args_glEnable argp;

    // Set function specific args
    argp.cap = cap;

    glenable_uh(argp);
}

// -- glDisable
void glDisable( GLenum cap )
{
    args_glDisable argp;

    // Set function specific args
    argp.cap = cap;

    gldisable_uh(argp);
}

// -- glIsEnabled
GLboolean glIsEnabled( GLenum cap )
{
    args_glIsEnabled argp;
    
    // Set function specific args
    argp.cap = cap;
    
    return glisenabled_uh(argp);
}

// -- glEnableClientState
void glEnableClientState( GLenum cap )
{
    args_glEnableClientState argp;

    // Set function specific args
    argp.cap = cap;

    glenableclientstate_uh(argp);
}

// -- glDisableClientState
void glDisableClientState( GLenum cap )
{
    args_glDisableClientState argp;

    // Set function specific args
    argp.cap = cap;

    gldisableclientstate_uh(argp);
}

// -- glGetBooleanv
void glGetBooleanv( GLenum pname, GLboolean *params )
{
    args_glGetBooleanv argp;

    // Set function specific args
    argp.pname = pname;
	argp.params = params;

    glgetbooleanv_uh(argp);
}

// -- glGetDoublev
void glGetDoublev( GLenum pname, GLdouble *params )
{
    args_glGetDoublev argp;

    // Set function specific args
    argp.pname = pname;
	argp.params = params;

    glgetdoublev_uh(argp);
}

// -- glGetFloatv
void glGetFloatv( GLenum pname, GLfloat *params )
{
    args_glGetFloatv argp;

    // Set function specific args
    argp.pname = pname;
	argp.params = params;

    glgetfloatv_uh(argp);
}

// -- glGetIntegerv
void glGetIntegerv( GLenum pname, GLint *params )
{
    args_glGetIntegerv argp;

    // Set function specific args
    argp.pname = pname;
	argp.params = params;

    glgetintegerv_uh(argp);
}

// -- glPushAttrib
void glPushAttrib( GLbitfield mask )
{
    args_glPushAttrib argp;

    // Set function specific args
    argp.mask = mask;

    glpushattrib_uh(argp);
}

// -- glPopAttrib
void glPopAttrib()
{
    glpopattrib_uh();
}

// -- glPushClientAttrib
void glPushClientAttrib( GLbitfield mask )
{
    args_glPushClientAttrib argp;

    // Set function specific args
    argp.mask = mask;

    glpushclientattrib_uh(argp);
}

// -- glPopClientAttrib
void glPopClientAttrib()
{
    glpopclientattrib_uh();
}

// -- glRenderMode
GLint glRenderMode( GLenum mode )
{
    args_glRenderMode argp;
    
    // Set function specific args
    argp.mode = mode;
    
    return glrendermode_uh(argp);
}

// -- glFinish
void glFinish()
{
    glfinish_uh();
}

// -- glFlush
void glFlush()
{
    glflush_uh();
}

// -- glHint
void glHint( GLenum target, GLenum mode )
{
    args_glHint argp;

    // Set function specific args
    argp.target = target;
	argp.mode = mode;

    glhint_uh(argp);
}

// -- glClearDepth
void glClearDepth( GLclampd depth )
{
    args_glClearDepth argp;

    // Set function specific args
    argp.depth = depth;

    glcleardepth_uh(argp);
}

// -- glDepthFunc
void glDepthFunc( GLenum func )
{
    args_glDepthFunc argp;

    // Set function specific args
    argp.func = func;

    gldepthfunc_uh(argp);
}

// -- glDepthMask
void glDepthMask( GLboolean flag )
{
    args_glDepthMask argp;

    // Set function specific args
    argp.flag = flag;

    gldepthmask_uh(argp);
}

// -- glDepthRange
void glDepthRange( GLclampd near_val, GLclampd far_val )
{
    args_glDepthRange argp;

    // Set function specific args
    argp.near_val = near_val;
	argp.far_val = far_val;

    gldepthrange_uh(argp);
}

// -- glClearAccum
void glClearAccum( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha )
{
    args_glClearAccum argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;
	argp.alpha = alpha;

    glclearaccum_uh(argp);
}

// -- glAccum
void glAccum( GLenum op, GLfloat value )
{
    args_glAccum argp;

    // Set function specific args
    argp.op = op;
	argp.value = value;

    glaccum_uh(argp);
}

// -- glMatrixMode
void glMatrixMode( GLenum mode )
{
    args_glMatrixMode argp;

    // Set function specific args
    argp.mode = mode;

    glmatrixmode_uh(argp);
}

// -- glOrtho
void glOrtho( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val )
{
    args_glOrtho argp;

    // Set function specific args
    argp.left = left;
	argp.right = right;
	argp.bottom = bottom;
	argp.top = top;
	argp.near_val = near_val;
	argp.far_val = far_val;

    glortho_uh(argp);
}

// -- glFrustum
void glFrustum( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near_val, GLdouble far_val )
{
    args_glFrustum argp;

    // Set function specific args
    argp.left = left;
	argp.right = right;
	argp.bottom = bottom;
	argp.top = top;
	argp.near_val = near_val;
	argp.far_val = far_val;

    glfrustum_uh(argp);
}

// -- glViewport
void glViewport( GLint x, GLint y, GLsizei width, GLsizei height )
{
    args_glViewport argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.width = width;
	argp.height = height;

    glviewport_uh(argp);
}

// -- glPushMatrix
void glPushMatrix()
{
    glpushmatrix_uh();
}

// -- glPopMatrix
void glPopMatrix()
{
    glpopmatrix_uh();
}

// -- glLoadIdentity
void glLoadIdentity()
{
    glloadidentity_uh();
}

// -- glLoadMatrixd
void glLoadMatrixd( const GLdouble *m )
{
    args_glLoadMatrixd argp;

    // Set function specific args
    argp.m = m;

    glloadmatrixd_uh(argp);
}

// -- glLoadMatrixf
void glLoadMatrixf( const GLfloat *m )
{
    args_glLoadMatrixf argp;

    // Set function specific args
    argp.m = m;

    glloadmatrixf_uh(argp);
}

// -- glMultMatrixd
void glMultMatrixd( const GLdouble *m )
{
    args_glMultMatrixd argp;

    // Set function specific args
    argp.m = m;

    glmultmatrixd_uh(argp);
}

// -- glMultMatrixf
void glMultMatrixf( const GLfloat *m )
{
    args_glMultMatrixf argp;

    // Set function specific args
    argp.m = m;

    glmultmatrixf_uh(argp);
}

// -- glRotated
void glRotated( GLdouble angle, GLdouble x, GLdouble y, GLdouble z )
{
    args_glRotated argp;

    // Set function specific args
    argp.angle = angle;
	argp.x = x;
	argp.y = y;
	argp.z = z;

    glrotated_uh(argp);
}

// -- glRotatef
void glRotatef( GLfloat angle, GLfloat x, GLfloat y, GLfloat z )
{
    args_glRotatef argp;

    // Set function specific args
    argp.angle = angle;
	argp.x = x;
	argp.y = y;
	argp.z = z;

    glrotatef_uh(argp);
}

// -- glScaled
void glScaled( GLdouble x, GLdouble y, GLdouble z )
{
    args_glScaled argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;

    glscaled_uh(argp);
}

// -- glScalef
void glScalef( GLfloat x, GLfloat y, GLfloat z )
{
    args_glScalef argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;

    glscalef_uh(argp);
}

// -- glTranslated
void glTranslated( GLdouble x, GLdouble y, GLdouble z )
{
    args_glTranslated argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;

    gltranslated_uh(argp);
}

// -- glTranslatef
void glTranslatef( GLfloat x, GLfloat y, GLfloat z )
{
    args_glTranslatef argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;

    gltranslatef_uh(argp);
}

// -- glIsList
GLboolean glIsList( GLuint list )
{
    args_glIsList argp;
    
    // Set function specific args
    argp.list = list;
    
    return glislist_uh(argp);
}

// -- glDeleteLists
void glDeleteLists( GLuint list, GLsizei range )
{
    args_glDeleteLists argp;

    // Set function specific args
    argp.list = list;
	argp.range = range;

    gldeletelists_uh(argp);
}

// -- glGenLists
GLuint glGenLists( GLsizei range )
{
    args_glGenLists argp;
    
    // Set function specific args
    argp.range = range;
    
    return glgenlists_uh(argp);
}

// -- glNewList
void glNewList( GLuint list, GLenum mode )
{
    args_glNewList argp;

    // Set function specific args
    argp.list = list;
	argp.mode = mode;

    glnewlist_uh(argp);
}

// -- glEndList
void glEndList()
{
    glendlist_uh();
}

// -- glCallList
void glCallList( GLuint list )
{
    args_glCallList argp;

    // Set function specific args
    argp.list = list;

    glcalllist_uh(argp);
}

// -- glCallLists
void glCallLists( GLsizei n, GLenum type, const GLvoid *lists )
{
    args_glCallLists argp;

    // Set function specific args
    argp.n = n;
	argp.type = type;
	argp.lists = lists;

    glcalllists_uh(argp);
}

// -- glListBase
void glListBase( GLuint base )
{
    args_glListBase argp;

    // Set function specific args
    argp.base = base;

    gllistbase_uh(argp);
}

// -- glBegin
void glBegin( GLenum mode )
{
    args_glBegin argp;

    // Set function specific args
    argp.mode = mode;

    glbegin_uh(argp);
}

// -- glEnd
void glEnd()
{
    glend_uh();
}

// -- glVertex2d
void glVertex2d( GLdouble x, GLdouble y )
{
    args_glVertex2d argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;

    glvertex2d_uh(argp);
}

// -- glVertex2f
void glVertex2f( GLfloat x, GLfloat y )
{
    args_glVertex2f argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;

    glvertex2f_uh(argp);
}

// -- glVertex2i
void glVertex2i( GLint x, GLint y )
{
    args_glVertex2i argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;

    glvertex2i_uh(argp);
}

// -- glVertex2s
void glVertex2s( GLshort x, GLshort y )
{
    args_glVertex2s argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;

    glvertex2s_uh(argp);
}

// -- glVertex3d
void glVertex3d( GLdouble x, GLdouble y, GLdouble z )
{
    args_glVertex3d argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;

    glvertex3d_uh(argp);
}

// -- glVertex3f
void glVertex3f( GLfloat x, GLfloat y, GLfloat z )
{
    args_glVertex3f argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;

    glvertex3f_uh(argp);
}

// -- glVertex3i
void glVertex3i( GLint x, GLint y, GLint z )
{
    args_glVertex3i argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;

    glvertex3i_uh(argp);
}

// -- glVertex3s
void glVertex3s( GLshort x, GLshort y, GLshort z )
{
    args_glVertex3s argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;

    glvertex3s_uh(argp);
}

// -- glVertex4d
void glVertex4d( GLdouble x, GLdouble y, GLdouble z, GLdouble w )
{
    args_glVertex4d argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;
	argp.w = w;

    glvertex4d_uh(argp);
}

// -- glVertex4f
void glVertex4f( GLfloat x, GLfloat y, GLfloat z, GLfloat w )
{
    args_glVertex4f argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;
	argp.w = w;

    glvertex4f_uh(argp);
}

// -- glVertex4i
void glVertex4i( GLint x, GLint y, GLint z, GLint w )
{
    args_glVertex4i argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;
	argp.w = w;

    glvertex4i_uh(argp);
}

// -- glVertex4s
void glVertex4s( GLshort x, GLshort y, GLshort z, GLshort w )
{
    args_glVertex4s argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;
	argp.w = w;

    glvertex4s_uh(argp);
}

// -- glVertex2dv
void glVertex2dv( const GLdouble *v )
{
    args_glVertex2dv argp;

    // Set function specific args
    argp.v = v;

    glvertex2dv_uh(argp);
}

// -- glVertex2fv
void glVertex2fv( const GLfloat *v )
{
    args_glVertex2fv argp;

    // Set function specific args
    argp.v = v;

    glvertex2fv_uh(argp);
}

// -- glVertex2iv
void glVertex2iv( const GLint *v )
{
    args_glVertex2iv argp;

    // Set function specific args
    argp.v = v;

    glvertex2iv_uh(argp);
}

// -- glVertex2sv
void glVertex2sv( const GLshort *v )
{
    args_glVertex2sv argp;

    // Set function specific args
    argp.v = v;

    glvertex2sv_uh(argp);
}

// -- glVertex3dv
void glVertex3dv( const GLdouble *v )
{
    args_glVertex3dv argp;

    // Set function specific args
    argp.v = v;

    glvertex3dv_uh(argp);
}

// -- glVertex3fv
void glVertex3fv( const GLfloat *v )
{
    args_glVertex3fv argp;

    // Set function specific args
    argp.v = v;

    glvertex3fv_uh(argp);
}

// -- glVertex3iv
void glVertex3iv( const GLint *v )
{
    args_glVertex3iv argp;

    // Set function specific args
    argp.v = v;

    glvertex3iv_uh(argp);
}

// -- glVertex3sv
void glVertex3sv( const GLshort *v )
{
    args_glVertex3sv argp;

    // Set function specific args
    argp.v = v;

    glvertex3sv_uh(argp);
}

// -- glVertex4dv
void glVertex4dv( const GLdouble *v )
{
    args_glVertex4dv argp;

    // Set function specific args
    argp.v = v;

    glvertex4dv_uh(argp);
}

// -- glVertex4fv
void glVertex4fv( const GLfloat *v )
{
    args_glVertex4fv argp;

    // Set function specific args
    argp.v = v;

    glvertex4fv_uh(argp);
}

// -- glVertex4iv
void glVertex4iv( const GLint *v )
{
    args_glVertex4iv argp;

    // Set function specific args
    argp.v = v;

    glvertex4iv_uh(argp);
}

// -- glVertex4sv
void glVertex4sv( const GLshort *v )
{
    args_glVertex4sv argp;

    // Set function specific args
    argp.v = v;

    glvertex4sv_uh(argp);
}

// -- glNormal3b
void glNormal3b( GLbyte nx, GLbyte ny, GLbyte nz )
{
    args_glNormal3b argp;

    // Set function specific args
    argp.nx = nx;
	argp.ny = ny;
	argp.nz = nz;

    glnormal3b_uh(argp);
}

// -- glNormal3d
void glNormal3d( GLdouble nx, GLdouble ny, GLdouble nz )
{
    args_glNormal3d argp;

    // Set function specific args
    argp.nx = nx;
	argp.ny = ny;
	argp.nz = nz;

    glnormal3d_uh(argp);
}

// -- glNormal3f
void glNormal3f( GLfloat nx, GLfloat ny, GLfloat nz )
{
    args_glNormal3f argp;

    // Set function specific args
    argp.nx = nx;
	argp.ny = ny;
	argp.nz = nz;

    glnormal3f_uh(argp);
}

// -- glNormal3i
void glNormal3i( GLint nx, GLint ny, GLint nz )
{
    args_glNormal3i argp;

    // Set function specific args
    argp.nx = nx;
	argp.ny = ny;
	argp.nz = nz;

    glnormal3i_uh(argp);
}

// -- glNormal3s
void glNormal3s( GLshort nx, GLshort ny, GLshort nz )
{
    args_glNormal3s argp;

    // Set function specific args
    argp.nx = nx;
	argp.ny = ny;
	argp.nz = nz;

    glnormal3s_uh(argp);
}

// -- glNormal3bv
void glNormal3bv( const GLbyte *v )
{
    args_glNormal3bv argp;

    // Set function specific args
    argp.v = v;

    glnormal3bv_uh(argp);
}

// -- glNormal3dv
void glNormal3dv( const GLdouble *v )
{
    args_glNormal3dv argp;

    // Set function specific args
    argp.v = v;

    glnormal3dv_uh(argp);
}

// -- glNormal3fv
void glNormal3fv( const GLfloat *v )
{
    args_glNormal3fv argp;

    // Set function specific args
    argp.v = v;

    glnormal3fv_uh(argp);
}

// -- glNormal3iv
void glNormal3iv( const GLint *v )
{
    args_glNormal3iv argp;

    // Set function specific args
    argp.v = v;

    glnormal3iv_uh(argp);
}

// -- glNormal3sv
void glNormal3sv( const GLshort *v )
{
    args_glNormal3sv argp;

    // Set function specific args
    argp.v = v;

    glnormal3sv_uh(argp);
}

// -- glIndexd
void glIndexd( GLdouble c )
{
    args_glIndexd argp;

    // Set function specific args
    argp.c = c;

    glindexd_uh(argp);
}

// -- glIndexf
void glIndexf( GLfloat c )
{
    args_glIndexf argp;

    // Set function specific args
    argp.c = c;

    glindexf_uh(argp);
}

// -- glIndexi
void glIndexi( GLint c )
{
    args_glIndexi argp;

    // Set function specific args
    argp.c = c;

    glindexi_uh(argp);
}

// -- glIndexs
void glIndexs( GLshort c )
{
    args_glIndexs argp;

    // Set function specific args
    argp.c = c;

    glindexs_uh(argp);
}

// -- glIndexub
void glIndexub( GLubyte c )
{
    args_glIndexub argp;

    // Set function specific args
    argp.c = c;

    glindexub_uh(argp);
}

// -- glIndexdv
void glIndexdv( const GLdouble *c )
{
    args_glIndexdv argp;

    // Set function specific args
    argp.c = c;

    glindexdv_uh(argp);
}

// -- glIndexfv
void glIndexfv( const GLfloat *c )
{
    args_glIndexfv argp;

    // Set function specific args
    argp.c = c;

    glindexfv_uh(argp);
}

// -- glIndexiv
void glIndexiv( const GLint *c )
{
    args_glIndexiv argp;

    // Set function specific args
    argp.c = c;

    glindexiv_uh(argp);
}

// -- glIndexsv
void glIndexsv( const GLshort *c )
{
    args_glIndexsv argp;

    // Set function specific args
    argp.c = c;

    glindexsv_uh(argp);
}

// -- glIndexubv
void glIndexubv( const GLubyte *c )
{
    args_glIndexubv argp;

    // Set function specific args
    argp.c = c;

    glindexubv_uh(argp);
}

// -- glColor3b
void glColor3b( GLbyte red, GLbyte green, GLbyte blue )
{
    args_glColor3b argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;

    glcolor3b_uh(argp);
}

// -- glColor3d
void glColor3d( GLdouble red, GLdouble green, GLdouble blue )
{
    args_glColor3d argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;

    glcolor3d_uh(argp);
}

// -- glColor3f
void glColor3f( GLfloat red, GLfloat green, GLfloat blue )
{
    args_glColor3f argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;

    glcolor3f_uh(argp);
}

// -- glColor3i
void glColor3i( GLint red, GLint green, GLint blue )
{
    args_glColor3i argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;

    glcolor3i_uh(argp);
}

// -- glColor3s
void glColor3s( GLshort red, GLshort green, GLshort blue )
{
    args_glColor3s argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;

    glcolor3s_uh(argp);
}

// -- glColor3ub
void glColor3ub( GLubyte red, GLubyte green, GLubyte blue )
{
    args_glColor3ub argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;

    glcolor3ub_uh(argp);
}

// -- glColor3ui
void glColor3ui( GLuint red, GLuint green, GLuint blue )
{
    args_glColor3ui argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;

    glcolor3ui_uh(argp);
}

// -- glColor3us
void glColor3us( GLushort red, GLushort green, GLushort blue )
{
    args_glColor3us argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;

    glcolor3us_uh(argp);
}

// -- glColor4b
void glColor4b( GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha )
{
    args_glColor4b argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;
	argp.alpha = alpha;

    glcolor4b_uh(argp);
}

// -- glColor4d
void glColor4d( GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha )
{
    args_glColor4d argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;
	argp.alpha = alpha;

    glcolor4d_uh(argp);
}

// -- glColor4f
void glColor4f( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha )
{
    args_glColor4f argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;
	argp.alpha = alpha;

    glcolor4f_uh(argp);
}

// -- glColor4i
void glColor4i( GLint red, GLint green, GLint blue, GLint alpha )
{
    args_glColor4i argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;
	argp.alpha = alpha;

    glcolor4i_uh(argp);
}

// -- glColor4s
void glColor4s( GLshort red, GLshort green, GLshort blue, GLshort alpha )
{
    args_glColor4s argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;
	argp.alpha = alpha;

    glcolor4s_uh(argp);
}

// -- glColor4ub
void glColor4ub( GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha )
{
    args_glColor4ub argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;
	argp.alpha = alpha;

    glcolor4ub_uh(argp);
}

// -- glColor4ui
void glColor4ui( GLuint red, GLuint green, GLuint blue, GLuint alpha )
{
    args_glColor4ui argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;
	argp.alpha = alpha;

    glcolor4ui_uh(argp);
}

// -- glColor4us
void glColor4us( GLushort red, GLushort green, GLushort blue, GLushort alpha )
{
    args_glColor4us argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;
	argp.alpha = alpha;

    glcolor4us_uh(argp);
}

// -- glColor3bv
void glColor3bv( const GLbyte *v )
{
    args_glColor3bv argp;

    // Set function specific args
    argp.v = v;

    glcolor3bv_uh(argp);
}

// -- glColor3dv
void glColor3dv( const GLdouble *v )
{
    args_glColor3dv argp;

    // Set function specific args
    argp.v = v;

    glcolor3dv_uh(argp);
}

// -- glColor3fv
void glColor3fv( const GLfloat *v )
{
    args_glColor3fv argp;

    // Set function specific args
    argp.v = v;

    glcolor3fv_uh(argp);
}

// -- glColor3iv
void glColor3iv( const GLint *v )
{
    args_glColor3iv argp;

    // Set function specific args
    argp.v = v;

    glcolor3iv_uh(argp);
}

// -- glColor3sv
void glColor3sv( const GLshort *v )
{
    args_glColor3sv argp;

    // Set function specific args
    argp.v = v;

    glcolor3sv_uh(argp);
}

// -- glColor3ubv
void glColor3ubv( const GLubyte *v )
{
    args_glColor3ubv argp;

    // Set function specific args
    argp.v = v;

    glcolor3ubv_uh(argp);
}

// -- glColor3uiv
void glColor3uiv( const GLuint *v )
{
    args_glColor3uiv argp;

    // Set function specific args
    argp.v = v;

    glcolor3uiv_uh(argp);
}

// -- glColor3usv
void glColor3usv( const GLushort *v )
{
    args_glColor3usv argp;

    // Set function specific args
    argp.v = v;

    glcolor3usv_uh(argp);
}

// -- glColor4bv
void glColor4bv( const GLbyte *v )
{
    args_glColor4bv argp;

    // Set function specific args
    argp.v = v;

    glcolor4bv_uh(argp);
}

// -- glColor4dv
void glColor4dv( const GLdouble *v )
{
    args_glColor4dv argp;

    // Set function specific args
    argp.v = v;

    glcolor4dv_uh(argp);
}

// -- glColor4fv
void glColor4fv( const GLfloat *v )
{
    args_glColor4fv argp;

    // Set function specific args
    argp.v = v;

    glcolor4fv_uh(argp);
}

// -- glColor4iv
void glColor4iv( const GLint *v )
{
    args_glColor4iv argp;

    // Set function specific args
    argp.v = v;

    glcolor4iv_uh(argp);
}

// -- glColor4sv
void glColor4sv( const GLshort *v )
{
    args_glColor4sv argp;

    // Set function specific args
    argp.v = v;

    glcolor4sv_uh(argp);
}

// -- glColor4ubv
void glColor4ubv( const GLubyte *v )
{
    args_glColor4ubv argp;

    // Set function specific args
    argp.v = v;

    glcolor4ubv_uh(argp);
}

// -- glColor4uiv
void glColor4uiv( const GLuint *v )
{
    args_glColor4uiv argp;

    // Set function specific args
    argp.v = v;

    glcolor4uiv_uh(argp);
}

// -- glColor4usv
void glColor4usv( const GLushort *v )
{
    args_glColor4usv argp;

    // Set function specific args
    argp.v = v;

    glcolor4usv_uh(argp);
}

// -- glTexCoord1d
void glTexCoord1d( GLdouble s )
{
    args_glTexCoord1d argp;

    // Set function specific args
    argp.s = s;

    gltexcoord1d_uh(argp);
}

// -- glTexCoord1f
void glTexCoord1f( GLfloat s )
{
    args_glTexCoord1f argp;

    // Set function specific args
    argp.s = s;

    gltexcoord1f_uh(argp);
}

// -- glTexCoord1i
void glTexCoord1i( GLint s )
{
    args_glTexCoord1i argp;

    // Set function specific args
    argp.s = s;

    gltexcoord1i_uh(argp);
}

// -- glTexCoord1s
void glTexCoord1s( GLshort s )
{
    args_glTexCoord1s argp;

    // Set function specific args
    argp.s = s;

    gltexcoord1s_uh(argp);
}

// -- glTexCoord2d
void glTexCoord2d( GLdouble s, GLdouble t )
{
    args_glTexCoord2d argp;

    // Set function specific args
    argp.s = s;
	argp.t = t;

    gltexcoord2d_uh(argp);
}

// -- glTexCoord2f
void glTexCoord2f( GLfloat s, GLfloat t )
{
    args_glTexCoord2f argp;

    // Set function specific args
    argp.s = s;
	argp.t = t;

    gltexcoord2f_uh(argp);
}

// -- glTexCoord2i
void glTexCoord2i( GLint s, GLint t )
{
    args_glTexCoord2i argp;

    // Set function specific args
    argp.s = s;
	argp.t = t;

    gltexcoord2i_uh(argp);
}

// -- glTexCoord2s
void glTexCoord2s( GLshort s, GLshort t )
{
    args_glTexCoord2s argp;

    // Set function specific args
    argp.s = s;
	argp.t = t;

    gltexcoord2s_uh(argp);
}

// -- glTexCoord3d
void glTexCoord3d( GLdouble s, GLdouble t, GLdouble r )
{
    args_glTexCoord3d argp;

    // Set function specific args
    argp.s = s;
	argp.t = t;
	argp.r = r;

    gltexcoord3d_uh(argp);
}

// -- glTexCoord3f
void glTexCoord3f( GLfloat s, GLfloat t, GLfloat r )
{
    args_glTexCoord3f argp;

    // Set function specific args
    argp.s = s;
	argp.t = t;
	argp.r = r;

    gltexcoord3f_uh(argp);
}

// -- glTexCoord3i
void glTexCoord3i( GLint s, GLint t, GLint r )
{
    args_glTexCoord3i argp;

    // Set function specific args
    argp.s = s;
	argp.t = t;
	argp.r = r;

    gltexcoord3i_uh(argp);
}

// -- glTexCoord3s
void glTexCoord3s( GLshort s, GLshort t, GLshort r )
{
    args_glTexCoord3s argp;

    // Set function specific args
    argp.s = s;
	argp.t = t;
	argp.r = r;

    gltexcoord3s_uh(argp);
}

// -- glTexCoord4d
void glTexCoord4d( GLdouble s, GLdouble t, GLdouble r, GLdouble q )
{
    args_glTexCoord4d argp;

    // Set function specific args
    argp.s = s;
	argp.t = t;
	argp.r = r;
	argp.q = q;

    gltexcoord4d_uh(argp);
}

// -- glTexCoord4f
void glTexCoord4f( GLfloat s, GLfloat t, GLfloat r, GLfloat q )
{
    args_glTexCoord4f argp;

    // Set function specific args
    argp.s = s;
	argp.t = t;
	argp.r = r;
	argp.q = q;

    gltexcoord4f_uh(argp);
}

// -- glTexCoord4i
void glTexCoord4i( GLint s, GLint t, GLint r, GLint q )
{
    args_glTexCoord4i argp;

    // Set function specific args
    argp.s = s;
	argp.t = t;
	argp.r = r;
	argp.q = q;

    gltexcoord4i_uh(argp);
}

// -- glTexCoord4s
void glTexCoord4s( GLshort s, GLshort t, GLshort r, GLshort q )
{
    args_glTexCoord4s argp;

    // Set function specific args
    argp.s = s;
	argp.t = t;
	argp.r = r;
	argp.q = q;

    gltexcoord4s_uh(argp);
}

// -- glTexCoord1dv
void glTexCoord1dv( const GLdouble *v )
{
    args_glTexCoord1dv argp;

    // Set function specific args
    argp.v = v;

    gltexcoord1dv_uh(argp);
}

// -- glTexCoord1fv
void glTexCoord1fv( const GLfloat *v )
{
    args_glTexCoord1fv argp;

    // Set function specific args
    argp.v = v;

    gltexcoord1fv_uh(argp);
}

// -- glTexCoord1iv
void glTexCoord1iv( const GLint *v )
{
    args_glTexCoord1iv argp;

    // Set function specific args
    argp.v = v;

    gltexcoord1iv_uh(argp);
}

// -- glTexCoord1sv
void glTexCoord1sv( const GLshort *v )
{
    args_glTexCoord1sv argp;

    // Set function specific args
    argp.v = v;

    gltexcoord1sv_uh(argp);
}

// -- glTexCoord2dv
void glTexCoord2dv( const GLdouble *v )
{
    args_glTexCoord2dv argp;

    // Set function specific args
    argp.v = v;

    gltexcoord2dv_uh(argp);
}

// -- glTexCoord2fv
void glTexCoord2fv( const GLfloat *v )
{
    args_glTexCoord2fv argp;

    // Set function specific args
    argp.v = v;

    gltexcoord2fv_uh(argp);
}

// -- glTexCoord2iv
void glTexCoord2iv( const GLint *v )
{
    args_glTexCoord2iv argp;

    // Set function specific args
    argp.v = v;

    gltexcoord2iv_uh(argp);
}

// -- glTexCoord2sv
void glTexCoord2sv( const GLshort *v )
{
    args_glTexCoord2sv argp;

    // Set function specific args
    argp.v = v;

    gltexcoord2sv_uh(argp);
}

// -- glTexCoord3dv
void glTexCoord3dv( const GLdouble *v )
{
    args_glTexCoord3dv argp;

    // Set function specific args
    argp.v = v;

    gltexcoord3dv_uh(argp);
}

// -- glTexCoord3fv
void glTexCoord3fv( const GLfloat *v )
{
    args_glTexCoord3fv argp;

    // Set function specific args
    argp.v = v;

    gltexcoord3fv_uh(argp);
}

// -- glTexCoord3iv
void glTexCoord3iv( const GLint *v )
{
    args_glTexCoord3iv argp;

    // Set function specific args
    argp.v = v;

    gltexcoord3iv_uh(argp);
}

// -- glTexCoord3sv
void glTexCoord3sv( const GLshort *v )
{
    args_glTexCoord3sv argp;

    // Set function specific args
    argp.v = v;

    gltexcoord3sv_uh(argp);
}

// -- glTexCoord4dv
void glTexCoord4dv( const GLdouble *v )
{
    args_glTexCoord4dv argp;

    // Set function specific args
    argp.v = v;

    gltexcoord4dv_uh(argp);
}

// -- glTexCoord4fv
void glTexCoord4fv( const GLfloat *v )
{
    args_glTexCoord4fv argp;

    // Set function specific args
    argp.v = v;

    gltexcoord4fv_uh(argp);
}

// -- glTexCoord4iv
void glTexCoord4iv( const GLint *v )
{
    args_glTexCoord4iv argp;

    // Set function specific args
    argp.v = v;

    gltexcoord4iv_uh(argp);
}

// -- glTexCoord4sv
void glTexCoord4sv( const GLshort *v )
{
    args_glTexCoord4sv argp;

    // Set function specific args
    argp.v = v;

    gltexcoord4sv_uh(argp);
}

// -- glRasterPos2d
void glRasterPos2d( GLdouble x, GLdouble y )
{
    args_glRasterPos2d argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;

    glrasterpos2d_uh(argp);
}

// -- glRasterPos2f
void glRasterPos2f( GLfloat x, GLfloat y )
{
    args_glRasterPos2f argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;

    glrasterpos2f_uh(argp);
}

// -- glRasterPos2i
void glRasterPos2i( GLint x, GLint y )
{
    args_glRasterPos2i argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;

    glrasterpos2i_uh(argp);
}

// -- glRasterPos2s
void glRasterPos2s( GLshort x, GLshort y )
{
    args_glRasterPos2s argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;

    glrasterpos2s_uh(argp);
}

// -- glRasterPos3d
void glRasterPos3d( GLdouble x, GLdouble y, GLdouble z )
{
    args_glRasterPos3d argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;

    glrasterpos3d_uh(argp);
}

// -- glRasterPos3f
void glRasterPos3f( GLfloat x, GLfloat y, GLfloat z )
{
    args_glRasterPos3f argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;

    glrasterpos3f_uh(argp);
}

// -- glRasterPos3i
void glRasterPos3i( GLint x, GLint y, GLint z )
{
    args_glRasterPos3i argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;

    glrasterpos3i_uh(argp);
}

// -- glRasterPos3s
void glRasterPos3s( GLshort x, GLshort y, GLshort z )
{
    args_glRasterPos3s argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;

    glrasterpos3s_uh(argp);
}

// -- glRasterPos4d
void glRasterPos4d( GLdouble x, GLdouble y, GLdouble z, GLdouble w )
{
    args_glRasterPos4d argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;
	argp.w = w;

    glrasterpos4d_uh(argp);
}

// -- glRasterPos4f
void glRasterPos4f( GLfloat x, GLfloat y, GLfloat z, GLfloat w )
{
    args_glRasterPos4f argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;
	argp.w = w;

    glrasterpos4f_uh(argp);
}

// -- glRasterPos4i
void glRasterPos4i( GLint x, GLint y, GLint z, GLint w )
{
    args_glRasterPos4i argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;
	argp.w = w;

    glrasterpos4i_uh(argp);
}

// -- glRasterPos4s
void glRasterPos4s( GLshort x, GLshort y, GLshort z, GLshort w )
{
    args_glRasterPos4s argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.z = z;
	argp.w = w;

    glrasterpos4s_uh(argp);
}

// -- glRasterPos2dv
void glRasterPos2dv( const GLdouble *v )
{
    args_glRasterPos2dv argp;

    // Set function specific args
    argp.v = v;

    glrasterpos2dv_uh(argp);
}

// -- glRasterPos2fv
void glRasterPos2fv( const GLfloat *v )
{
    args_glRasterPos2fv argp;

    // Set function specific args
    argp.v = v;

    glrasterpos2fv_uh(argp);
}

// -- glRasterPos2iv
void glRasterPos2iv( const GLint *v )
{
    args_glRasterPos2iv argp;

    // Set function specific args
    argp.v = v;

    glrasterpos2iv_uh(argp);
}

// -- glRasterPos2sv
void glRasterPos2sv( const GLshort *v )
{
    args_glRasterPos2sv argp;

    // Set function specific args
    argp.v = v;

    glrasterpos2sv_uh(argp);
}

// -- glRasterPos3dv
void glRasterPos3dv( const GLdouble *v )
{
    args_glRasterPos3dv argp;

    // Set function specific args
    argp.v = v;

    glrasterpos3dv_uh(argp);
}

// -- glRasterPos3fv
void glRasterPos3fv( const GLfloat *v )
{
    args_glRasterPos3fv argp;

    // Set function specific args
    argp.v = v;

    glrasterpos3fv_uh(argp);
}

// -- glRasterPos3iv
void glRasterPos3iv( const GLint *v )
{
    args_glRasterPos3iv argp;

    // Set function specific args
    argp.v = v;

    glrasterpos3iv_uh(argp);
}

// -- glRasterPos3sv
void glRasterPos3sv( const GLshort *v )
{
    args_glRasterPos3sv argp;

    // Set function specific args
    argp.v = v;

    glrasterpos3sv_uh(argp);
}

// -- glRasterPos4dv
void glRasterPos4dv( const GLdouble *v )
{
    args_glRasterPos4dv argp;

    // Set function specific args
    argp.v = v;

    glrasterpos4dv_uh(argp);
}

// -- glRasterPos4fv
void glRasterPos4fv( const GLfloat *v )
{
    args_glRasterPos4fv argp;

    // Set function specific args
    argp.v = v;

    glrasterpos4fv_uh(argp);
}

// -- glRasterPos4iv
void glRasterPos4iv( const GLint *v )
{
    args_glRasterPos4iv argp;

    // Set function specific args
    argp.v = v;

    glrasterpos4iv_uh(argp);
}

// -- glRasterPos4sv
void glRasterPos4sv( const GLshort *v )
{
    args_glRasterPos4sv argp;

    // Set function specific args
    argp.v = v;

    glrasterpos4sv_uh(argp);
}

// -- glRectd
void glRectd( GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2 )
{
    args_glRectd argp;

    // Set function specific args
    argp.x1 = x1;
	argp.y1 = y1;
	argp.x2 = x2;
	argp.y2 = y2;

    glrectd_uh(argp);
}

// -- glRectf
void glRectf( GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2 )
{
    args_glRectf argp;

    // Set function specific args
    argp.x1 = x1;
	argp.y1 = y1;
	argp.x2 = x2;
	argp.y2 = y2;

    glrectf_uh(argp);
}

// -- glRecti
void glRecti( GLint x1, GLint y1, GLint x2, GLint y2 )
{
    args_glRecti argp;

    // Set function specific args
    argp.x1 = x1;
	argp.y1 = y1;
	argp.x2 = x2;
	argp.y2 = y2;

    glrecti_uh(argp);
}

// -- glRects
void glRects( GLshort x1, GLshort y1, GLshort x2, GLshort y2 )
{
    args_glRects argp;

    // Set function specific args
    argp.x1 = x1;
	argp.y1 = y1;
	argp.x2 = x2;
	argp.y2 = y2;

    glrects_uh(argp);
}

// -- glRectdv
void glRectdv( const GLdouble *v1, const GLdouble *v2 )
{
    args_glRectdv argp;

    // Set function specific args
    argp.v1 = v1;
	argp.v2 = v2;

    glrectdv_uh(argp);
}

// -- glRectfv
void glRectfv( const GLfloat *v1, const GLfloat *v2 )
{
    args_glRectfv argp;

    // Set function specific args
    argp.v1 = v1;
	argp.v2 = v2;

    glrectfv_uh(argp);
}

// -- glRectiv
void glRectiv( const GLint *v1, const GLint *v2 )
{
    args_glRectiv argp;

    // Set function specific args
    argp.v1 = v1;
	argp.v2 = v2;

    glrectiv_uh(argp);
}

// -- glRectsv
void glRectsv( const GLshort *v1, const GLshort *v2 )
{
    args_glRectsv argp;

    // Set function specific args
    argp.v1 = v1;
	argp.v2 = v2;

    glrectsv_uh(argp);
}

// -- glVertexPointer
void glVertexPointer( GLint size, GLenum type, GLsizei stride, const GLvoid *ptr )
{
    args_glVertexPointer argp;

    // Set function specific args
    argp.size = size;
	argp.type = type;
	argp.stride = stride;
	argp.ptr = ptr;

    glvertexpointer_uh(argp);
}

// -- glNormalPointer
void glNormalPointer( GLenum type, GLsizei stride, const GLvoid *ptr )
{
    args_glNormalPointer argp;

    // Set function specific args
    argp.type = type;
	argp.stride = stride;
	argp.ptr = ptr;

    glnormalpointer_uh(argp);
}

// -- glColorPointer
void glColorPointer( GLint size, GLenum type, GLsizei stride, const GLvoid *ptr )
{
    args_glColorPointer argp;

    // Set function specific args
    argp.size = size;
	argp.type = type;
	argp.stride = stride;
	argp.ptr = ptr;

    glcolorpointer_uh(argp);
}

// -- glIndexPointer
void glIndexPointer( GLenum type, GLsizei stride, const GLvoid *ptr )
{
    args_glIndexPointer argp;

    // Set function specific args
    argp.type = type;
	argp.stride = stride;
	argp.ptr = ptr;

    glindexpointer_uh(argp);
}

// -- glTexCoordPointer
void glTexCoordPointer( GLint size, GLenum type, GLsizei stride, const GLvoid *ptr )
{
    args_glTexCoordPointer argp;

    // Set function specific args
    argp.size = size;
	argp.type = type;
	argp.stride = stride;
	argp.ptr = ptr;

    gltexcoordpointer_uh(argp);
}

// -- glEdgeFlagPointer
void glEdgeFlagPointer( GLsizei stride, const GLvoid *ptr )
{
    args_glEdgeFlagPointer argp;

    // Set function specific args
    argp.stride = stride;
	argp.ptr = ptr;

    gledgeflagpointer_uh(argp);
}

// -- glGetPointerv
void glGetPointerv( GLenum pname, GLvoid **params )
{
    args_glGetPointerv argp;

    // Set function specific args
    argp.pname = pname;
	argp.*params = *params;

    glgetpointerv_uh(argp);
}

// -- glArrayElement
void glArrayElement( GLint i )
{
    args_glArrayElement argp;

    // Set function specific args
    argp.i = i;

    glarrayelement_uh(argp);
}

// -- glDrawArrays
void glDrawArrays( GLenum mode, GLint first, GLsizei count )
{
    args_glDrawArrays argp;

    // Set function specific args
    argp.mode = mode;
	argp.first = first;
	argp.count = count;

    gldrawarrays_uh(argp);
}

// -- glDrawElements
void glDrawElements( GLenum mode, GLsizei count, GLenum type, const GLvoid *indices )
{
    args_glDrawElements argp;

    // Set function specific args
    argp.mode = mode;
	argp.count = count;
	argp.type = type;
	argp.indices = indices;

    gldrawelements_uh(argp);
}

// -- glInterleavedArrays
void glInterleavedArrays( GLenum format, GLsizei stride, const GLvoid *pointer )
{
    args_glInterleavedArrays argp;

    // Set function specific args
    argp.format = format;
	argp.stride = stride;
	argp.pointer = pointer;

    glinterleavedarrays_uh(argp);
}

// -- glShadeModel
void glShadeModel( GLenum mode )
{
    args_glShadeModel argp;

    // Set function specific args
    argp.mode = mode;

    glshademodel_uh(argp);
}

// -- glLightf
void glLightf( GLenum light, GLenum pname, GLfloat param )
{
    args_glLightf argp;

    // Set function specific args
    argp.light = light;
	argp.pname = pname;
	argp.param = param;

    gllightf_uh(argp);
}

// -- glLighti
void glLighti( GLenum light, GLenum pname, GLint param )
{
    args_glLighti argp;

    // Set function specific args
    argp.light = light;
	argp.pname = pname;
	argp.param = param;

    gllighti_uh(argp);
}

// -- glLightfv
void glLightfv( GLenum light, GLenum pname, const GLfloat *params )
{
    args_glLightfv argp;

    // Set function specific args
    argp.light = light;
	argp.pname = pname;
	argp.params = params;

    gllightfv_uh(argp);
}

// -- glLightiv
void glLightiv( GLenum light, GLenum pname, const GLint *params )
{
    args_glLightiv argp;

    // Set function specific args
    argp.light = light;
	argp.pname = pname;
	argp.params = params;

    gllightiv_uh(argp);
}

// -- glGetLightfv
void glGetLightfv( GLenum light, GLenum pname, GLfloat *params )
{
    args_glGetLightfv argp;

    // Set function specific args
    argp.light = light;
	argp.pname = pname;
	argp.params = params;

    glgetlightfv_uh(argp);
}

// -- glGetLightiv
void glGetLightiv( GLenum light, GLenum pname, GLint *params )
{
    args_glGetLightiv argp;

    // Set function specific args
    argp.light = light;
	argp.pname = pname;
	argp.params = params;

    glgetlightiv_uh(argp);
}

// -- glLightModelf
void glLightModelf( GLenum pname, GLfloat param )
{
    args_glLightModelf argp;

    // Set function specific args
    argp.pname = pname;
	argp.param = param;

    gllightmodelf_uh(argp);
}

// -- glLightModeli
void glLightModeli( GLenum pname, GLint param )
{
    args_glLightModeli argp;

    // Set function specific args
    argp.pname = pname;
	argp.param = param;

    gllightmodeli_uh(argp);
}

// -- glLightModelfv
void glLightModelfv( GLenum pname, const GLfloat *params )
{
    args_glLightModelfv argp;

    // Set function specific args
    argp.pname = pname;
	argp.params = params;

    gllightmodelfv_uh(argp);
}

// -- glLightModeliv
void glLightModeliv( GLenum pname, const GLint *params )
{
    args_glLightModeliv argp;

    // Set function specific args
    argp.pname = pname;
	argp.params = params;

    gllightmodeliv_uh(argp);
}

// -- glMaterialf
void glMaterialf( GLenum face, GLenum pname, GLfloat param )
{
    args_glMaterialf argp;

    // Set function specific args
    argp.face = face;
	argp.pname = pname;
	argp.param = param;

    glmaterialf_uh(argp);
}

// -- glMateriali
void glMateriali( GLenum face, GLenum pname, GLint param )
{
    args_glMateriali argp;

    // Set function specific args
    argp.face = face;
	argp.pname = pname;
	argp.param = param;

    glmateriali_uh(argp);
}

// -- glMaterialfv
void glMaterialfv( GLenum face, GLenum pname, const GLfloat *params )
{
    args_glMaterialfv argp;

    // Set function specific args
    argp.face = face;
	argp.pname = pname;
	argp.params = params;

    glmaterialfv_uh(argp);
}

// -- glMaterialiv
void glMaterialiv( GLenum face, GLenum pname, const GLint *params )
{
    args_glMaterialiv argp;

    // Set function specific args
    argp.face = face;
	argp.pname = pname;
	argp.params = params;

    glmaterialiv_uh(argp);
}

// -- glGetMaterialfv
void glGetMaterialfv( GLenum face, GLenum pname, GLfloat *params )
{
    args_glGetMaterialfv argp;

    // Set function specific args
    argp.face = face;
	argp.pname = pname;
	argp.params = params;

    glgetmaterialfv_uh(argp);
}

// -- glGetMaterialiv
void glGetMaterialiv( GLenum face, GLenum pname, GLint *params )
{
    args_glGetMaterialiv argp;

    // Set function specific args
    argp.face = face;
	argp.pname = pname;
	argp.params = params;

    glgetmaterialiv_uh(argp);
}

// -- glColorMaterial
void glColorMaterial( GLenum face, GLenum mode )
{
    args_glColorMaterial argp;

    // Set function specific args
    argp.face = face;
	argp.mode = mode;

    glcolormaterial_uh(argp);
}

// -- glPixelZoom
void glPixelZoom( GLfloat xfactor, GLfloat yfactor )
{
    args_glPixelZoom argp;

    // Set function specific args
    argp.xfactor = xfactor;
	argp.yfactor = yfactor;

    glpixelzoom_uh(argp);
}

// -- glPixelStoref
void glPixelStoref( GLenum pname, GLfloat param )
{
    args_glPixelStoref argp;

    // Set function specific args
    argp.pname = pname;
	argp.param = param;

    glpixelstoref_uh(argp);
}

// -- glPixelStorei
void glPixelStorei( GLenum pname, GLint param )
{
    args_glPixelStorei argp;

    // Set function specific args
    argp.pname = pname;
	argp.param = param;

    glpixelstorei_uh(argp);
}

// -- glPixelTransferf
void glPixelTransferf( GLenum pname, GLfloat param )
{
    args_glPixelTransferf argp;

    // Set function specific args
    argp.pname = pname;
	argp.param = param;

    glpixeltransferf_uh(argp);
}

// -- glPixelTransferi
void glPixelTransferi( GLenum pname, GLint param )
{
    args_glPixelTransferi argp;

    // Set function specific args
    argp.pname = pname;
	argp.param = param;

    glpixeltransferi_uh(argp);
}

// -- glPixelMapfv
void glPixelMapfv( GLenum map, GLsizei mapsize, const GLfloat *values )
{
    args_glPixelMapfv argp;

    // Set function specific args
    argp.map = map;
	argp.mapsize = mapsize;
	argp.values = values;

    glpixelmapfv_uh(argp);
}

// -- glPixelMapuiv
void glPixelMapuiv( GLenum map, GLsizei mapsize, const GLuint *values )
{
    args_glPixelMapuiv argp;

    // Set function specific args
    argp.map = map;
	argp.mapsize = mapsize;
	argp.values = values;

    glpixelmapuiv_uh(argp);
}

// -- glPixelMapusv
void glPixelMapusv( GLenum map, GLsizei mapsize, const GLushort *values )
{
    args_glPixelMapusv argp;

    // Set function specific args
    argp.map = map;
	argp.mapsize = mapsize;
	argp.values = values;

    glpixelmapusv_uh(argp);
}

// -- glGetPixelMapfv
void glGetPixelMapfv( GLenum map, GLfloat *values )
{
    args_glGetPixelMapfv argp;

    // Set function specific args
    argp.map = map;
	argp.values = values;

    glgetpixelmapfv_uh(argp);
}

// -- glGetPixelMapuiv
void glGetPixelMapuiv( GLenum map, GLuint *values )
{
    args_glGetPixelMapuiv argp;

    // Set function specific args
    argp.map = map;
	argp.values = values;

    glgetpixelmapuiv_uh(argp);
}

// -- glGetPixelMapusv
void glGetPixelMapusv( GLenum map, GLushort *values )
{
    args_glGetPixelMapusv argp;

    // Set function specific args
    argp.map = map;
	argp.values = values;

    glgetpixelmapusv_uh(argp);
}

// -- glBitmap
void glBitmap( GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap )
{
    args_glBitmap argp;

    // Set function specific args
    argp.width = width;
	argp.height = height;
	argp.xorig = xorig;
	argp.yorig = yorig;
	argp.xmove = xmove;
	argp.ymove = ymove;
	argp.bitmap = bitmap;

    glbitmap_uh(argp);
}

// -- glReadPixels
void glReadPixels( GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels )
{
    args_glReadPixels argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.width = width;
	argp.height = height;
	argp.format = format;
	argp.type = type;
	argp.pixels = pixels;

    glreadpixels_uh(argp);
}

// -- glDrawPixels
void glDrawPixels( GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels )
{
    args_glDrawPixels argp;

    // Set function specific args
    argp.width = width;
	argp.height = height;
	argp.format = format;
	argp.type = type;
	argp.pixels = pixels;

    gldrawpixels_uh(argp);
}

// -- glCopyPixels
void glCopyPixels( GLint x, GLint y, GLsizei width, GLsizei height, GLenum type )
{
    args_glCopyPixels argp;

    // Set function specific args
    argp.x = x;
	argp.y = y;
	argp.width = width;
	argp.height = height;
	argp.type = type;

    glcopypixels_uh(argp);
}

// -- glStencilFunc
void glStencilFunc( GLenum func, GLint ref, GLuint mask )
{
    args_glStencilFunc argp;

    // Set function specific args
    argp.func = func;
	argp.ref = ref;
	argp.mask = mask;

    glstencilfunc_uh(argp);
}

// -- glStencilMask
void glStencilMask( GLuint mask )
{
    args_glStencilMask argp;

    // Set function specific args
    argp.mask = mask;

    glstencilmask_uh(argp);
}

// -- glStencilOp
void glStencilOp( GLenum fail, GLenum zfail, GLenum zpass )
{
    args_glStencilOp argp;

    // Set function specific args
    argp.fail = fail;
	argp.zfail = zfail;
	argp.zpass = zpass;

    glstencilop_uh(argp);
}

// -- glClearStencil
void glClearStencil( GLint s )
{
    args_glClearStencil argp;

    // Set function specific args
    argp.s = s;

    glclearstencil_uh(argp);
}

// -- glTexGend
void glTexGend( GLenum coord, GLenum pname, GLdouble param )
{
    args_glTexGend argp;

    // Set function specific args
    argp.coord = coord;
	argp.pname = pname;
	argp.param = param;

    gltexgend_uh(argp);
}

// -- glTexGenf
void glTexGenf( GLenum coord, GLenum pname, GLfloat param )
{
    args_glTexGenf argp;

    // Set function specific args
    argp.coord = coord;
	argp.pname = pname;
	argp.param = param;

    gltexgenf_uh(argp);
}

// -- glTexGeni
void glTexGeni( GLenum coord, GLenum pname, GLint param )
{
    args_glTexGeni argp;

    // Set function specific args
    argp.coord = coord;
	argp.pname = pname;
	argp.param = param;

    gltexgeni_uh(argp);
}

// -- glTexGendv
void glTexGendv( GLenum coord, GLenum pname, const GLdouble *params )
{
    args_glTexGendv argp;

    // Set function specific args
    argp.coord = coord;
	argp.pname = pname;
	argp.params = params;

    gltexgendv_uh(argp);
}

// -- glTexGenfv
void glTexGenfv( GLenum coord, GLenum pname, const GLfloat *params )
{
    args_glTexGenfv argp;

    // Set function specific args
    argp.coord = coord;
	argp.pname = pname;
	argp.params = params;

    gltexgenfv_uh(argp);
}

// -- glTexGeniv
void glTexGeniv( GLenum coord, GLenum pname, const GLint *params )
{
    args_glTexGeniv argp;

    // Set function specific args
    argp.coord = coord;
	argp.pname = pname;
	argp.params = params;

    gltexgeniv_uh(argp);
}

// -- glGetTexGendv
void glGetTexGendv( GLenum coord, GLenum pname, GLdouble *params )
{
    args_glGetTexGendv argp;

    // Set function specific args
    argp.coord = coord;
	argp.pname = pname;
	argp.params = params;

    glgettexgendv_uh(argp);
}

// -- glGetTexGenfv
void glGetTexGenfv( GLenum coord, GLenum pname, GLfloat *params )
{
    args_glGetTexGenfv argp;

    // Set function specific args
    argp.coord = coord;
	argp.pname = pname;
	argp.params = params;

    glgettexgenfv_uh(argp);
}

// -- glGetTexGeniv
void glGetTexGeniv( GLenum coord, GLenum pname, GLint *params )
{
    args_glGetTexGeniv argp;

    // Set function specific args
    argp.coord = coord;
	argp.pname = pname;
	argp.params = params;

    glgettexgeniv_uh(argp);
}

// -- glTexEnvf
void glTexEnvf( GLenum target, GLenum pname, GLfloat param )
{
    args_glTexEnvf argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.param = param;

    gltexenvf_uh(argp);
}

// -- glTexEnvi
void glTexEnvi( GLenum target, GLenum pname, GLint param )
{
    args_glTexEnvi argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.param = param;

    gltexenvi_uh(argp);
}

// -- glTexEnvfv
void glTexEnvfv( GLenum target, GLenum pname, const GLfloat *params )
{
    args_glTexEnvfv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    gltexenvfv_uh(argp);
}

// -- glTexEnviv
void glTexEnviv( GLenum target, GLenum pname, const GLint *params )
{
    args_glTexEnviv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    gltexenviv_uh(argp);
}

// -- glGetTexEnvfv
void glGetTexEnvfv( GLenum target, GLenum pname, GLfloat *params )
{
    args_glGetTexEnvfv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glgettexenvfv_uh(argp);
}

// -- glGetTexEnviv
void glGetTexEnviv( GLenum target, GLenum pname, GLint *params )
{
    args_glGetTexEnviv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glgettexenviv_uh(argp);
}

// -- glTexParameterf
void glTexParameterf( GLenum target, GLenum pname, GLfloat param )
{
    args_glTexParameterf argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.param = param;

    gltexparameterf_uh(argp);
}

// -- glTexParameteri
void glTexParameteri( GLenum target, GLenum pname, GLint param )
{
    args_glTexParameteri argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.param = param;

    gltexparameteri_uh(argp);
}

// -- glTexParameterfv
void glTexParameterfv( GLenum target, GLenum pname, const GLfloat *params )
{
    args_glTexParameterfv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    gltexparameterfv_uh(argp);
}

// -- glTexParameteriv
void glTexParameteriv( GLenum target, GLenum pname, const GLint *params )
{
    args_glTexParameteriv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    gltexparameteriv_uh(argp);
}

// -- glGetTexParameterfv
void glGetTexParameterfv( GLenum target, GLenum pname, GLfloat *params)
{
    args_glGetTexParameterfv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glgettexparameterfv_uh(argp);
}

// -- glGetTexParameteriv
void glGetTexParameteriv( GLenum target, GLenum pname, GLint *params )
{
    args_glGetTexParameteriv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glgettexparameteriv_uh(argp);
}

// -- glGetTexLevelParameterfv
void glGetTexLevelParameterfv( GLenum target, GLint level, GLenum pname, GLfloat *params )
{
    args_glGetTexLevelParameterfv argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.pname = pname;
	argp.params = params;

    glgettexlevelparameterfv_uh(argp);
}

// -- glGetTexLevelParameteriv
void glGetTexLevelParameteriv( GLenum target, GLint level, GLenum pname, GLint *params )
{
    args_glGetTexLevelParameteriv argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.pname = pname;
	argp.params = params;

    glgettexlevelparameteriv_uh(argp);
}

// -- glTexImage1D
void glTexImage1D( GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels )
{
    args_glTexImage1D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.internalFormat = internalFormat;
	argp.width = width;
	argp.border = border;
	argp.format = format;
	argp.type = type;
	argp.pixels = pixels;

    glteximage1d_uh(argp);
}

// -- glTexImage2D
void glTexImage2D( GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels )
{
    args_glTexImage2D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.internalFormat = internalFormat;
	argp.width = width;
	argp.height = height;
	argp.border = border;
	argp.format = format;
	argp.type = type;
	argp.pixels = pixels;

    glteximage2d_uh(argp);
}

// -- glGetTexImage
void glGetTexImage( GLenum target, GLint level,  GLenum format, GLenum type,  GLvoid *pixels )
{
    args_glGetTexImage argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.format = format;
	argp.type = type;
	argp.pixels = pixels;

    glgetteximage_uh(argp);
}

// -- glGenTextures
void glGenTextures( GLsizei n, GLuint *textures )
{
    args_glGenTextures argp;

    // Set function specific args
    argp.n = n;
	argp.textures = textures;

    glgentextures_uh(argp);
}

// -- glDeleteTextures
void glDeleteTextures( GLsizei n, const GLuint *textures)
{
    args_glDeleteTextures argp;

    // Set function specific args
    argp.n = n;
	argp.textures = textures;

    gldeletetextures_uh(argp);
}

// -- glBindTexture
void glBindTexture( GLenum target, GLuint texture )
{
    args_glBindTexture argp;

    // Set function specific args
    argp.target = target;
	argp.texture = texture;

    glbindtexture_uh(argp);
}

// -- glPrioritizeTextures
void glPrioritizeTextures( GLsizei n, const GLuint *textures, const GLclampf *priorities )
{
    args_glPrioritizeTextures argp;

    // Set function specific args
    argp.n = n;
	argp.textures = textures;
	argp.priorities = priorities;

    glprioritizetextures_uh(argp);
}

// -- glAreTexturesResident
GLboolean glAreTexturesResident( GLsizei n, const GLuint *textures, GLboolean *residences )
{
    args_glAreTexturesResident argp;
    
    // Set function specific args
    argp.n = n;
	argp.textures = textures;
	argp.residences = residences;
    
    return glaretexturesresident_uh(argp);
}

// -- glIsTexture
GLboolean glIsTexture( GLuint texture )
{
    args_glIsTexture argp;
    
    // Set function specific args
    argp.texture = texture;
    
    return glistexture_uh(argp);
}

// -- glTexSubImage1D
void glTexSubImage1D( GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels )
{
    args_glTexSubImage1D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.xoffset = xoffset;
	argp.width = width;
	argp.format = format;
	argp.type = type;
	argp.pixels = pixels;

    gltexsubimage1d_uh(argp);
}

// -- glTexSubImage2D
void glTexSubImage2D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels )
{
    args_glTexSubImage2D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.xoffset = xoffset;
	argp.yoffset = yoffset;
	argp.width = width;
	argp.height = height;
	argp.format = format;
	argp.type = type;
	argp.pixels = pixels;

    gltexsubimage2d_uh(argp);
}

// -- glCopyTexImage1D
void glCopyTexImage1D( GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border )
{
    args_glCopyTexImage1D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.internalformat = internalformat;
	argp.x = x;
	argp.y = y;
	argp.width = width;
	argp.border = border;

    glcopyteximage1d_uh(argp);
}

// -- glCopyTexImage2D
void glCopyTexImage2D( GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border )
{
    args_glCopyTexImage2D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.internalformat = internalformat;
	argp.x = x;
	argp.y = y;
	argp.width = width;
	argp.height = height;
	argp.border = border;

    glcopyteximage2d_uh(argp);
}

// -- glCopyTexSubImage1D
void glCopyTexSubImage1D( GLenum target, GLint level,GLint xoffset, GLint x, GLint y,GLsizei width )
{
    args_glCopyTexSubImage1D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.xoffset = xoffset;
	argp.x = x;
	argp.y = y;
	argp.width = width;

    glcopytexsubimage1d_uh(argp);
}

// -- glCopyTexSubImage2D
void glCopyTexSubImage2D( GLenum target, GLint level,GLint xoffset, GLint yoffset,GLint x, GLint y, GLsizei width, GLsizei height )
{
    args_glCopyTexSubImage2D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.xoffset = xoffset;
	argp.yoffset = yoffset;
	argp.x = x;
	argp.y = y;
	argp.width = width;
	argp.height = height;

    glcopytexsubimage2d_uh(argp);
}

// -- glMap1d
void glMap1d( GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points )
{
    args_glMap1d argp;

    // Set function specific args
    argp.target = target;
	argp.u1 = u1;
	argp.u2 = u2;
	argp.stride = stride;
	argp.order = order;
	argp.points = points;

    glmap1d_uh(argp);
}

// -- glMap1f
void glMap1f( GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points )
{
    args_glMap1f argp;

    // Set function specific args
    argp.target = target;
	argp.u1 = u1;
	argp.u2 = u2;
	argp.stride = stride;
	argp.order = order;
	argp.points = points;

    glmap1f_uh(argp);
}

// -- glMap2d
void glMap2d( GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points )
{
    args_glMap2d argp;

    // Set function specific args
    argp.target = target;
	argp.u1 = u1;
	argp.u2 = u2;
	argp.ustride = ustride;
	argp.uorder = uorder;
	argp.v1 = v1;
	argp.v2 = v2;
	argp.vstride = vstride;
	argp.vorder = vorder;
	argp.points = points;

    glmap2d_uh(argp);
}

// -- glMap2f
void glMap2f( GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points )
{
    args_glMap2f argp;

    // Set function specific args
    argp.target = target;
	argp.u1 = u1;
	argp.u2 = u2;
	argp.ustride = ustride;
	argp.uorder = uorder;
	argp.v1 = v1;
	argp.v2 = v2;
	argp.vstride = vstride;
	argp.vorder = vorder;
	argp.points = points;

    glmap2f_uh(argp);
}

// -- glGetMapdv
void glGetMapdv( GLenum target, GLenum query, GLdouble *v )
{
    args_glGetMapdv argp;

    // Set function specific args
    argp.target = target;
	argp.query = query;
	argp.v = v;

    glgetmapdv_uh(argp);
}

// -- glGetMapfv
void glGetMapfv( GLenum target, GLenum query, GLfloat *v )
{
    args_glGetMapfv argp;

    // Set function specific args
    argp.target = target;
	argp.query = query;
	argp.v = v;

    glgetmapfv_uh(argp);
}

// -- glGetMapiv
void glGetMapiv( GLenum target, GLenum query, GLint *v )
{
    args_glGetMapiv argp;

    // Set function specific args
    argp.target = target;
	argp.query = query;
	argp.v = v;

    glgetmapiv_uh(argp);
}

// -- glEvalCoord1d
void glEvalCoord1d( GLdouble u )
{
    args_glEvalCoord1d argp;

    // Set function specific args
    argp.u = u;

    glevalcoord1d_uh(argp);
}

// -- glEvalCoord1f
void glEvalCoord1f( GLfloat u )
{
    args_glEvalCoord1f argp;

    // Set function specific args
    argp.u = u;

    glevalcoord1f_uh(argp);
}

// -- glEvalCoord1dv
void glEvalCoord1dv( const GLdouble *u )
{
    args_glEvalCoord1dv argp;

    // Set function specific args
    argp.u = u;

    glevalcoord1dv_uh(argp);
}

// -- glEvalCoord1fv
void glEvalCoord1fv( const GLfloat *u )
{
    args_glEvalCoord1fv argp;

    // Set function specific args
    argp.u = u;

    glevalcoord1fv_uh(argp);
}

// -- glEvalCoord2d
void glEvalCoord2d( GLdouble u, GLdouble v )
{
    args_glEvalCoord2d argp;

    // Set function specific args
    argp.u = u;
	argp.v = v;

    glevalcoord2d_uh(argp);
}

// -- glEvalCoord2f
void glEvalCoord2f( GLfloat u, GLfloat v )
{
    args_glEvalCoord2f argp;

    // Set function specific args
    argp.u = u;
	argp.v = v;

    glevalcoord2f_uh(argp);
}

// -- glEvalCoord2dv
void glEvalCoord2dv( const GLdouble *u )
{
    args_glEvalCoord2dv argp;

    // Set function specific args
    argp.u = u;

    glevalcoord2dv_uh(argp);
}

// -- glEvalCoord2fv
void glEvalCoord2fv( const GLfloat *u )
{
    args_glEvalCoord2fv argp;

    // Set function specific args
    argp.u = u;

    glevalcoord2fv_uh(argp);
}

// -- glMapGrid1d
void glMapGrid1d( GLint un, GLdouble u1, GLdouble u2 )
{
    args_glMapGrid1d argp;

    // Set function specific args
    argp.un = un;
	argp.u1 = u1;
	argp.u2 = u2;

    glmapgrid1d_uh(argp);
}

// -- glMapGrid1f
void glMapGrid1f( GLint un, GLfloat u1, GLfloat u2 )
{
    args_glMapGrid1f argp;

    // Set function specific args
    argp.un = un;
	argp.u1 = u1;
	argp.u2 = u2;

    glmapgrid1f_uh(argp);
}

// -- glMapGrid2d
void glMapGrid2d( GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2 )
{
    args_glMapGrid2d argp;

    // Set function specific args
    argp.un = un;
	argp.u1 = u1;
	argp.u2 = u2;
	argp.vn = vn;
	argp.v1 = v1;
	argp.v2 = v2;

    glmapgrid2d_uh(argp);
}

// -- glMapGrid2f
void glMapGrid2f( GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2 )
{
    args_glMapGrid2f argp;

    // Set function specific args
    argp.un = un;
	argp.u1 = u1;
	argp.u2 = u2;
	argp.vn = vn;
	argp.v1 = v1;
	argp.v2 = v2;

    glmapgrid2f_uh(argp);
}

// -- glEvalPoint1
void glEvalPoint1( GLint i )
{
    args_glEvalPoint1 argp;

    // Set function specific args
    argp.i = i;

    glevalpoint1_uh(argp);
}

// -- glEvalPoint2
void glEvalPoint2( GLint i, GLint j )
{
    args_glEvalPoint2 argp;

    // Set function specific args
    argp.i = i;
	argp.j = j;

    glevalpoint2_uh(argp);
}

// -- glEvalMesh1
void glEvalMesh1( GLenum mode, GLint i1, GLint i2 )
{
    args_glEvalMesh1 argp;

    // Set function specific args
    argp.mode = mode;
	argp.i1 = i1;
	argp.i2 = i2;

    glevalmesh1_uh(argp);
}

// -- glEvalMesh2
void glEvalMesh2( GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2 )
{
    args_glEvalMesh2 argp;

    // Set function specific args
    argp.mode = mode;
	argp.i1 = i1;
	argp.i2 = i2;
	argp.j1 = j1;
	argp.j2 = j2;

    glevalmesh2_uh(argp);
}

// -- glFogf
void glFogf( GLenum pname, GLfloat param )
{
    args_glFogf argp;

    // Set function specific args
    argp.pname = pname;
	argp.param = param;

    glfogf_uh(argp);
}

// -- glFogi
void glFogi( GLenum pname, GLint param )
{
    args_glFogi argp;

    // Set function specific args
    argp.pname = pname;
	argp.param = param;

    glfogi_uh(argp);
}

// -- glFogfv
void glFogfv( GLenum pname, const GLfloat *params )
{
    args_glFogfv argp;

    // Set function specific args
    argp.pname = pname;
	argp.params = params;

    glfogfv_uh(argp);
}

// -- glFogiv
void glFogiv( GLenum pname, const GLint *params )
{
    args_glFogiv argp;

    // Set function specific args
    argp.pname = pname;
	argp.params = params;

    glfogiv_uh(argp);
}

// -- glFeedbackBuffer
void glFeedbackBuffer( GLsizei size, GLenum type, GLfloat *buffer )
{
    args_glFeedbackBuffer argp;

    // Set function specific args
    argp.size = size;
	argp.type = type;
	argp.buffer = buffer;

    glfeedbackbuffer_uh(argp);
}

// -- glPassThrough
void glPassThrough( GLfloat token )
{
    args_glPassThrough argp;

    // Set function specific args
    argp.token = token;

    glpassthrough_uh(argp);
}

// -- glSelectBuffer
void glSelectBuffer( GLsizei size, GLuint *buffer )
{
    args_glSelectBuffer argp;

    // Set function specific args
    argp.size = size;
	argp.buffer = buffer;

    glselectbuffer_uh(argp);
}

// -- glInitNames
void glInitNames()
{
    glinitnames_uh();
}

// -- glLoadName
void glLoadName( GLuint name )
{
    args_glLoadName argp;

    // Set function specific args
    argp.name = name;

    glloadname_uh(argp);
}

// -- glPushName
void glPushName( GLuint name )
{
    args_glPushName argp;

    // Set function specific args
    argp.name = name;

    glpushname_uh(argp);
}

// -- glPopName
void glPopName()
{
    glpopname_uh();
}

// -- glDrawRangeElements
void glDrawRangeElements( GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices )
{
    args_glDrawRangeElements argp;

    // Set function specific args
    argp.mode = mode;
	argp.start = start;
	argp.end = end;
	argp.count = count;
	argp.type = type;
	argp.indices = indices;

    gldrawrangeelements_uh(argp);
}

// -- glTexImage3D
void glTexImage3D( GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels )
{
    args_glTexImage3D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.internalFormat = internalFormat;
	argp.width = width;
	argp.height = height;
	argp.depth = depth;
	argp.border = border;
	argp.format = format;
	argp.type = type;
	argp.pixels = pixels;

    glteximage3d_uh(argp);
}

// -- glTexSubImage3D
void glTexSubImage3D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels)
{
    args_glTexSubImage3D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.xoffset = xoffset;
	argp.yoffset = yoffset;
	argp.zoffset = zoffset;
	argp.width = width;
	argp.height = height;
	argp.depth = depth;
	argp.format = format;
	argp.type = type;
	argp.pixels = pixels;

    gltexsubimage3d_uh(argp);
}

// -- glCopyTexSubImage3D
void glCopyTexSubImage3D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height )
{
    args_glCopyTexSubImage3D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.xoffset = xoffset;
	argp.yoffset = yoffset;
	argp.zoffset = zoffset;
	argp.x = x;
	argp.y = y;
	argp.width = width;
	argp.height = height;

    glcopytexsubimage3d_uh(argp);
}

// -- glColorTable
void glColorTable( GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table )
{
    args_glColorTable argp;

    // Set function specific args
    argp.target = target;
	argp.internalformat = internalformat;
	argp.width = width;
	argp.format = format;
	argp.type = type;
	argp.table = table;

    glcolortable_uh(argp);
}

// -- glColorSubTable
void glColorSubTable( GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data )
{
    args_glColorSubTable argp;

    // Set function specific args
    argp.target = target;
	argp.start = start;
	argp.count = count;
	argp.format = format;
	argp.type = type;
	argp.data = data;

    glcolorsubtable_uh(argp);
}

// -- glColorTableParameteriv
void glColorTableParameteriv(GLenum target, GLenum pname, const GLint *params)
{
    args_glColorTableParameteriv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glcolortableparameteriv_uh(argp);
}

// -- glColorTableParameterfv
void glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat *params)
{
    args_glColorTableParameterfv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glcolortableparameterfv_uh(argp);
}

// -- glCopyColorSubTable
void glCopyColorSubTable( GLenum target, GLsizei start,GLint x, GLint y, GLsizei width )
{
    args_glCopyColorSubTable argp;

    // Set function specific args
    argp.target = target;
	argp.start = start;
	argp.x = x;
	argp.y = y;
	argp.width = width;

    glcopycolorsubtable_uh(argp);
}

// -- glCopyColorTable
void glCopyColorTable( GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width )
{
    args_glCopyColorTable argp;

    // Set function specific args
    argp.target = target;
	argp.internalformat = internalformat;
	argp.x = x;
	argp.y = y;
	argp.width = width;

    glcopycolortable_uh(argp);
}

// -- glGetColorTable
void glGetColorTable( GLenum target, GLenum format, GLenum type, GLvoid *table )
{
    args_glGetColorTable argp;

    // Set function specific args
    argp.target = target;
	argp.format = format;
	argp.type = type;
	argp.table = table;

    glgetcolortable_uh(argp);
}

// -- glGetColorTableParameterfv
void glGetColorTableParameterfv( GLenum target, GLenum pname, GLfloat *params )
{
    args_glGetColorTableParameterfv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glgetcolortableparameterfv_uh(argp);
}

// -- glGetColorTableParameteriv
void glGetColorTableParameteriv( GLenum target, GLenum pname, GLint *params )
{
    args_glGetColorTableParameteriv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glgetcolortableparameteriv_uh(argp);
}

// -- glBlendEquation
void glBlendEquation( GLenum mode )
{
    args_glBlendEquation argp;

    // Set function specific args
    argp.mode = mode;

    glblendequation_uh(argp);
}

// -- glBlendColor
void glBlendColor( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha )
{
    args_glBlendColor argp;

    // Set function specific args
    argp.red = red;
	argp.green = green;
	argp.blue = blue;
	argp.alpha = alpha;

    glblendcolor_uh(argp);
}

// -- glHistogram
void glHistogram( GLenum target, GLsizei width, GLenum internalformat, GLboolean sink )
{
    args_glHistogram argp;

    // Set function specific args
    argp.target = target;
	argp.width = width;
	argp.internalformat = internalformat;
	argp.sink = sink;

    glhistogram_uh(argp);
}

// -- glResetHistogram
void glResetHistogram( GLenum target )
{
    args_glResetHistogram argp;

    // Set function specific args
    argp.target = target;

    glresethistogram_uh(argp);
}

// -- glGetHistogram
void glGetHistogram( GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values )
{
    args_glGetHistogram argp;

    // Set function specific args
    argp.target = target;
	argp.reset = reset;
	argp.format = format;
	argp.type = type;
	argp.values = values;

    glgethistogram_uh(argp);
}

// -- glGetHistogramParameterfv
void glGetHistogramParameterfv( GLenum target, GLenum pname, GLfloat *params )
{
    args_glGetHistogramParameterfv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glgethistogramparameterfv_uh(argp);
}

// -- glGetHistogramParameteriv
void glGetHistogramParameteriv( GLenum target, GLenum pname, GLint *params )
{
    args_glGetHistogramParameteriv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glgethistogramparameteriv_uh(argp);
}

// -- glMinmax
void glMinmax( GLenum target, GLenum internalformat, GLboolean sink )
{
    args_glMinmax argp;

    // Set function specific args
    argp.target = target;
	argp.internalformat = internalformat;
	argp.sink = sink;

    glminmax_uh(argp);
}

// -- glResetMinmax
void glResetMinmax( GLenum target )
{
    args_glResetMinmax argp;

    // Set function specific args
    argp.target = target;

    glresetminmax_uh(argp);
}

// -- glGetMinmax
void glGetMinmax( GLenum target, GLboolean reset, GLenum format, GLenum types, GLvoid *values )
{
    args_glGetMinmax argp;

    // Set function specific args
    argp.target = target;
	argp.reset = reset;
	argp.format = format;
	argp.types = types;
	argp.values = values;

    glgetminmax_uh(argp);
}

// -- glGetMinmaxParameterfv
void glGetMinmaxParameterfv( GLenum target, GLenum pname, GLfloat *params )
{
    args_glGetMinmaxParameterfv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glgetminmaxparameterfv_uh(argp);
}

// -- glGetMinmaxParameteriv
void glGetMinmaxParameteriv( GLenum target, GLenum pname, GLint *params )
{
    args_glGetMinmaxParameteriv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glgetminmaxparameteriv_uh(argp);
}

// -- glConvolutionFilter1D
void glConvolutionFilter1D( GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image )
{
    args_glConvolutionFilter1D argp;

    // Set function specific args
    argp.target = target;
	argp.internalformat = internalformat;
	argp.width = width;
	argp.format = format;
	argp.type = type;
	argp.image = image;

    glconvolutionfilter1d_uh(argp);
}

// -- glConvolutionFilter2D
void glConvolutionFilter2D( GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image )
{
    args_glConvolutionFilter2D argp;

    // Set function specific args
    argp.target = target;
	argp.internalformat = internalformat;
	argp.width = width;
	argp.height = height;
	argp.format = format;
	argp.type = type;
	argp.image = image;

    glconvolutionfilter2d_uh(argp);
}

// -- glConvolutionParameterf
void glConvolutionParameterf( GLenum target, GLenum pname, GLfloat params )
{
    args_glConvolutionParameterf argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glconvolutionparameterf_uh(argp);
}

// -- glConvolutionParameterfv
void glConvolutionParameterfv( GLenum target, GLenum pname, const GLfloat *params )
{
    args_glConvolutionParameterfv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glconvolutionparameterfv_uh(argp);
}

// -- glConvolutionParameteri
void glConvolutionParameteri( GLenum target, GLenum pname, GLint params )
{
    args_glConvolutionParameteri argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glconvolutionparameteri_uh(argp);
}

// -- glConvolutionParameteriv
void glConvolutionParameteriv( GLenum target, GLenum pname, const GLint *params )
{
    args_glConvolutionParameteriv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glconvolutionparameteriv_uh(argp);
}

// -- glCopyConvolutionFilter1D
void glCopyConvolutionFilter1D( GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width )
{
    args_glCopyConvolutionFilter1D argp;

    // Set function specific args
    argp.target = target;
	argp.internalformat = internalformat;
	argp.x = x;
	argp.y = y;
	argp.width = width;

    glcopyconvolutionfilter1d_uh(argp);
}

// -- glCopyConvolutionFilter2D
void glCopyConvolutionFilter2D( GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height)
{
    args_glCopyConvolutionFilter2D argp;

    // Set function specific args
    argp.target = target;
	argp.internalformat = internalformat;
	argp.x = x;
	argp.y = y;
	argp.width = width;
	argp.height = height;

    glcopyconvolutionfilter2d_uh(argp);
}

// -- glGetConvolutionFilter
void glGetConvolutionFilter( GLenum target, GLenum format, GLenum type, GLvoid *image )
{
    args_glGetConvolutionFilter argp;

    // Set function specific args
    argp.target = target;
	argp.format = format;
	argp.type = type;
	argp.image = image;

    glgetconvolutionfilter_uh(argp);
}

// -- glGetConvolutionParameterfv
void glGetConvolutionParameterfv( GLenum target, GLenum pname, GLfloat *params )
{
    args_glGetConvolutionParameterfv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glgetconvolutionparameterfv_uh(argp);
}

// -- glGetConvolutionParameteriv
void glGetConvolutionParameteriv( GLenum target, GLenum pname, GLint *params )
{
    args_glGetConvolutionParameteriv argp;

    // Set function specific args
    argp.target = target;
	argp.pname = pname;
	argp.params = params;

    glgetconvolutionparameteriv_uh(argp);
}

// -- glSeparableFilter2D
void glSeparableFilter2D( GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column )
{
    args_glSeparableFilter2D argp;

    // Set function specific args
    argp.target = target;
	argp.internalformat = internalformat;
	argp.width = width;
	argp.height = height;
	argp.format = format;
	argp.type = type;
	argp.row = row;
	argp.column = column;

    glseparablefilter2d_uh(argp);
}

// -- glGetSeparableFilter
void glGetSeparableFilter( GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span )
{
    args_glGetSeparableFilter argp;

    // Set function specific args
    argp.target = target;
	argp.format = format;
	argp.type = type;
	argp.row = row;
	argp.column = column;
	argp.span = span;

    glgetseparablefilter_uh(argp);
}

// -- glActiveTexture
void glActiveTexture( GLenum texture )
{
    args_glActiveTexture argp;

    // Set function specific args
    argp.texture = texture;

    glactivetexture_uh(argp);
}

// -- glClientActiveTexture
void glClientActiveTexture( GLenum texture )
{
    args_glClientActiveTexture argp;

    // Set function specific args
    argp.texture = texture;

    glclientactivetexture_uh(argp);
}

// -- glCompressedTexImage1D
void glCompressedTexImage1D( GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data )
{
    args_glCompressedTexImage1D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.internalformat = internalformat;
	argp.width = width;
	argp.border = border;
	argp.imageSize = imageSize;
	argp.data = data;

    glcompressedteximage1d_uh(argp);
}

// -- glCompressedTexImage2D
void glCompressedTexImage2D( GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data )
{
    args_glCompressedTexImage2D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.internalformat = internalformat;
	argp.width = width;
	argp.height = height;
	argp.border = border;
	argp.imageSize = imageSize;
	argp.data = data;

    glcompressedteximage2d_uh(argp);
}

// -- glCompressedTexImage3D
void glCompressedTexImage3D( GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data )
{
    args_glCompressedTexImage3D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.internalformat = internalformat;
	argp.width = width;
	argp.height = height;
	argp.depth = depth;
	argp.border = border;
	argp.imageSize = imageSize;
	argp.data = data;

    glcompressedteximage3d_uh(argp);
}

// -- glCompressedTexSubImage1D
void glCompressedTexSubImage1D( GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data )
{
    args_glCompressedTexSubImage1D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.xoffset = xoffset;
	argp.width = width;
	argp.format = format;
	argp.imageSize = imageSize;
	argp.data = data;

    glcompressedtexsubimage1d_uh(argp);
}

// -- glCompressedTexSubImage2D
void glCompressedTexSubImage2D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data )
{
    args_glCompressedTexSubImage2D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.xoffset = xoffset;
	argp.yoffset = yoffset;
	argp.width = width;
	argp.height = height;
	argp.format = format;
	argp.imageSize = imageSize;
	argp.data = data;

    glcompressedtexsubimage2d_uh(argp);
}

// -- glCompressedTexSubImage3D
void glCompressedTexSubImage3D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data )
{
    args_glCompressedTexSubImage3D argp;

    // Set function specific args
    argp.target = target;
	argp.level = level;
	argp.xoffset = xoffset;
	argp.yoffset = yoffset;
	argp.zoffset = zoffset;
	argp.width = width;
	argp.height = height;
	argp.depth = depth;
	argp.format = format;
	argp.imageSize = imageSize;
	argp.data = data;

    glcompressedtexsubimage3d_uh(argp);
}

// -- glGetCompressedTexImage
void glGetCompressedTexImage( GLenum target, GLint lod, GLvoid *img )
{
    args_glGetCompressedTexImage argp;

    // Set function specific args
    argp.target = target;
	argp.lod = lod;
	argp.img = img;

    glgetcompressedteximage_uh(argp);
}

// -- glMultiTexCoord1d
void glMultiTexCoord1d( GLenum target, GLdouble s )
{
    args_glMultiTexCoord1d argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;

    glmultitexcoord1d_uh(argp);
}

// -- glMultiTexCoord1dv
void glMultiTexCoord1dv( GLenum target, const GLdouble *v )
{
    args_glMultiTexCoord1dv argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord1dv_uh(argp);
}

// -- glMultiTexCoord1f
void glMultiTexCoord1f( GLenum target, GLfloat s )
{
    args_glMultiTexCoord1f argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;

    glmultitexcoord1f_uh(argp);
}

// -- glMultiTexCoord1fv
void glMultiTexCoord1fv( GLenum target, const GLfloat *v )
{
    args_glMultiTexCoord1fv argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord1fv_uh(argp);
}

// -- glMultiTexCoord1i
void glMultiTexCoord1i( GLenum target, GLint s )
{
    args_glMultiTexCoord1i argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;

    glmultitexcoord1i_uh(argp);
}

// -- glMultiTexCoord1iv
void glMultiTexCoord1iv( GLenum target, const GLint *v )
{
    args_glMultiTexCoord1iv argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord1iv_uh(argp);
}

// -- glMultiTexCoord1s
void glMultiTexCoord1s( GLenum target, GLshort s )
{
    args_glMultiTexCoord1s argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;

    glmultitexcoord1s_uh(argp);
}

// -- glMultiTexCoord1sv
void glMultiTexCoord1sv( GLenum target, const GLshort *v )
{
    args_glMultiTexCoord1sv argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord1sv_uh(argp);
}

// -- glMultiTexCoord2d
void glMultiTexCoord2d( GLenum target, GLdouble s, GLdouble t )
{
    args_glMultiTexCoord2d argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;

    glmultitexcoord2d_uh(argp);
}

// -- glMultiTexCoord2dv
void glMultiTexCoord2dv( GLenum target, const GLdouble *v )
{
    args_glMultiTexCoord2dv argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord2dv_uh(argp);
}

// -- glMultiTexCoord2f
void glMultiTexCoord2f( GLenum target, GLfloat s, GLfloat t )
{
    args_glMultiTexCoord2f argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;

    glmultitexcoord2f_uh(argp);
}

// -- glMultiTexCoord2fv
void glMultiTexCoord2fv( GLenum target, const GLfloat *v )
{
    args_glMultiTexCoord2fv argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord2fv_uh(argp);
}

// -- glMultiTexCoord2i
void glMultiTexCoord2i( GLenum target, GLint s, GLint t )
{
    args_glMultiTexCoord2i argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;

    glmultitexcoord2i_uh(argp);
}

// -- glMultiTexCoord2iv
void glMultiTexCoord2iv( GLenum target, const GLint *v )
{
    args_glMultiTexCoord2iv argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord2iv_uh(argp);
}

// -- glMultiTexCoord2s
void glMultiTexCoord2s( GLenum target, GLshort s, GLshort t )
{
    args_glMultiTexCoord2s argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;

    glmultitexcoord2s_uh(argp);
}

// -- glMultiTexCoord2sv
void glMultiTexCoord2sv( GLenum target, const GLshort *v )
{
    args_glMultiTexCoord2sv argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord2sv_uh(argp);
}

// -- glMultiTexCoord3d
void glMultiTexCoord3d( GLenum target, GLdouble s, GLdouble t, GLdouble r )
{
    args_glMultiTexCoord3d argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;
	argp.r = r;

    glmultitexcoord3d_uh(argp);
}

// -- glMultiTexCoord3dv
void glMultiTexCoord3dv( GLenum target, const GLdouble *v )
{
    args_glMultiTexCoord3dv argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord3dv_uh(argp);
}

// -- glMultiTexCoord3f
void glMultiTexCoord3f( GLenum target, GLfloat s, GLfloat t, GLfloat r )
{
    args_glMultiTexCoord3f argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;
	argp.r = r;

    glmultitexcoord3f_uh(argp);
}

// -- glMultiTexCoord3fv
void glMultiTexCoord3fv( GLenum target, const GLfloat *v )
{
    args_glMultiTexCoord3fv argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord3fv_uh(argp);
}

// -- glMultiTexCoord3i
void glMultiTexCoord3i( GLenum target, GLint s, GLint t, GLint r )
{
    args_glMultiTexCoord3i argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;
	argp.r = r;

    glmultitexcoord3i_uh(argp);
}

// -- glMultiTexCoord3iv
void glMultiTexCoord3iv( GLenum target, const GLint *v )
{
    args_glMultiTexCoord3iv argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord3iv_uh(argp);
}

// -- glMultiTexCoord3s
void glMultiTexCoord3s( GLenum target, GLshort s, GLshort t, GLshort r )
{
    args_glMultiTexCoord3s argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;
	argp.r = r;

    glmultitexcoord3s_uh(argp);
}

// -- glMultiTexCoord3sv
void glMultiTexCoord3sv( GLenum target, const GLshort *v )
{
    args_glMultiTexCoord3sv argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord3sv_uh(argp);
}

// -- glMultiTexCoord4d
void glMultiTexCoord4d( GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q )
{
    args_glMultiTexCoord4d argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;
	argp.r = r;
	argp.q = q;

    glmultitexcoord4d_uh(argp);
}

// -- glMultiTexCoord4dv
void glMultiTexCoord4dv( GLenum target, const GLdouble *v )
{
    args_glMultiTexCoord4dv argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord4dv_uh(argp);
}

// -- glMultiTexCoord4f
void glMultiTexCoord4f( GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q )
{
    args_glMultiTexCoord4f argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;
	argp.r = r;
	argp.q = q;

    glmultitexcoord4f_uh(argp);
}

// -- glMultiTexCoord4fv
void glMultiTexCoord4fv( GLenum target, const GLfloat *v )
{
    args_glMultiTexCoord4fv argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord4fv_uh(argp);
}

// -- glMultiTexCoord4i
void glMultiTexCoord4i( GLenum target, GLint s, GLint t, GLint r, GLint q )
{
    args_glMultiTexCoord4i argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;
	argp.r = r;
	argp.q = q;

    glmultitexcoord4i_uh(argp);
}

// -- glMultiTexCoord4iv
void glMultiTexCoord4iv( GLenum target, const GLint *v )
{
    args_glMultiTexCoord4iv argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord4iv_uh(argp);
}

// -- glMultiTexCoord4s
void glMultiTexCoord4s( GLenum target, GLshort s, GLshort t, GLshort r, GLshort q )
{
    args_glMultiTexCoord4s argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;
	argp.r = r;
	argp.q = q;

    glmultitexcoord4s_uh(argp);
}

// -- glMultiTexCoord4sv
void glMultiTexCoord4sv( GLenum target, const GLshort *v )
{
    args_glMultiTexCoord4sv argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord4sv_uh(argp);
}

// -- glSampleCoverage
void glSampleCoverage( GLclampf value, GLboolean invert )
{
    args_glSampleCoverage argp;

    // Set function specific args
    argp.value = value;
	argp.invert = invert;

    glsamplecoverage_uh(argp);
}

// -- glActiveTextureARB
void glActiveTextureARB(GLenum texture)
{
    args_glActiveTextureARB argp;

    // Set function specific args
    argp.texture = texture;

    glactivetexturearb_uh(argp);
}

// -- glClientActiveTextureARB
void glClientActiveTextureARB(GLenum texture)
{
    args_glClientActiveTextureARB argp;

    // Set function specific args
    argp.texture = texture;

    glclientactivetexturearb_uh(argp);
}

// -- glMultiTexCoord1dARB
void glMultiTexCoord1dARB(GLenum target, GLdouble s)
{
    args_glMultiTexCoord1dARB argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;

    glmultitexcoord1darb_uh(argp);
}

// -- glMultiTexCoord1dvARB
void glMultiTexCoord1dvARB(GLenum target, const GLdouble *v)
{
    args_glMultiTexCoord1dvARB argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord1dvarb_uh(argp);
}

// -- glMultiTexCoord1fARB
void glMultiTexCoord1fARB(GLenum target, GLfloat s)
{
    args_glMultiTexCoord1fARB argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;

    glmultitexcoord1farb_uh(argp);
}

// -- glMultiTexCoord1fvARB
void glMultiTexCoord1fvARB(GLenum target, const GLfloat *v)
{
    args_glMultiTexCoord1fvARB argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord1fvarb_uh(argp);
}

// -- glMultiTexCoord1iARB
void glMultiTexCoord1iARB(GLenum target, GLint s)
{
    args_glMultiTexCoord1iARB argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;

    glmultitexcoord1iarb_uh(argp);
}

// -- glMultiTexCoord1ivARB
void glMultiTexCoord1ivARB(GLenum target, const GLint *v)
{
    args_glMultiTexCoord1ivARB argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord1ivarb_uh(argp);
}

// -- glMultiTexCoord1sARB
void glMultiTexCoord1sARB(GLenum target, GLshort s)
{
    args_glMultiTexCoord1sARB argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;

    glmultitexcoord1sarb_uh(argp);
}

// -- glMultiTexCoord1svARB
void glMultiTexCoord1svARB(GLenum target, const GLshort *v)
{
    args_glMultiTexCoord1svARB argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord1svarb_uh(argp);
}

// -- glMultiTexCoord2dARB
void glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t)
{
    args_glMultiTexCoord2dARB argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;

    glmultitexcoord2darb_uh(argp);
}

// -- glMultiTexCoord2dvARB
void glMultiTexCoord2dvARB(GLenum target, const GLdouble *v)
{
    args_glMultiTexCoord2dvARB argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord2dvarb_uh(argp);
}

// -- glMultiTexCoord2fARB
void glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t)
{
    args_glMultiTexCoord2fARB argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;

    glmultitexcoord2farb_uh(argp);
}

// -- glMultiTexCoord2fvARB
void glMultiTexCoord2fvARB(GLenum target, const GLfloat *v)
{
    args_glMultiTexCoord2fvARB argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord2fvarb_uh(argp);
}

// -- glMultiTexCoord2iARB
void glMultiTexCoord2iARB(GLenum target, GLint s, GLint t)
{
    args_glMultiTexCoord2iARB argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;

    glmultitexcoord2iarb_uh(argp);
}

// -- glMultiTexCoord2ivARB
void glMultiTexCoord2ivARB(GLenum target, const GLint *v)
{
    args_glMultiTexCoord2ivARB argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord2ivarb_uh(argp);
}

// -- glMultiTexCoord2sARB
void glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t)
{
    args_glMultiTexCoord2sARB argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;

    glmultitexcoord2sarb_uh(argp);
}

// -- glMultiTexCoord2svARB
void glMultiTexCoord2svARB(GLenum target, const GLshort *v)
{
    args_glMultiTexCoord2svARB argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord2svarb_uh(argp);
}

// -- glMultiTexCoord3dARB
void glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r)
{
    args_glMultiTexCoord3dARB argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;
	argp.r = r;

    glmultitexcoord3darb_uh(argp);
}

// -- glMultiTexCoord3dvARB
void glMultiTexCoord3dvARB(GLenum target, const GLdouble *v)
{
    args_glMultiTexCoord3dvARB argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord3dvarb_uh(argp);
}

// -- glMultiTexCoord3fARB
void glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r)
{
    args_glMultiTexCoord3fARB argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;
	argp.r = r;

    glmultitexcoord3farb_uh(argp);
}

// -- glMultiTexCoord3fvARB
void glMultiTexCoord3fvARB(GLenum target, const GLfloat *v)
{
    args_glMultiTexCoord3fvARB argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord3fvarb_uh(argp);
}

// -- glMultiTexCoord3iARB
void glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r)
{
    args_glMultiTexCoord3iARB argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;
	argp.r = r;

    glmultitexcoord3iarb_uh(argp);
}

// -- glMultiTexCoord3ivARB
void glMultiTexCoord3ivARB(GLenum target, const GLint *v)
{
    args_glMultiTexCoord3ivARB argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord3ivarb_uh(argp);
}

// -- glMultiTexCoord3sARB
void glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r)
{
    args_glMultiTexCoord3sARB argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;
	argp.r = r;

    glmultitexcoord3sarb_uh(argp);
}

// -- glMultiTexCoord3svARB
void glMultiTexCoord3svARB(GLenum target, const GLshort *v)
{
    args_glMultiTexCoord3svARB argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord3svarb_uh(argp);
}

// -- glMultiTexCoord4dARB
void glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q)
{
    args_glMultiTexCoord4dARB argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;
	argp.r = r;
	argp.q = q;

    glmultitexcoord4darb_uh(argp);
}

// -- glMultiTexCoord4dvARB
void glMultiTexCoord4dvARB(GLenum target, const GLdouble *v)
{
    args_glMultiTexCoord4dvARB argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord4dvarb_uh(argp);
}

// -- glMultiTexCoord4fARB
void glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
    args_glMultiTexCoord4fARB argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;
	argp.r = r;
	argp.q = q;

    glmultitexcoord4farb_uh(argp);
}

// -- glMultiTexCoord4fvARB
void glMultiTexCoord4fvARB(GLenum target, const GLfloat *v)
{
    args_glMultiTexCoord4fvARB argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord4fvarb_uh(argp);
}

// -- glMultiTexCoord4iARB
void glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q)
{
    args_glMultiTexCoord4iARB argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;
	argp.r = r;
	argp.q = q;

    glmultitexcoord4iarb_uh(argp);
}

// -- glMultiTexCoord4ivARB
void glMultiTexCoord4ivARB(GLenum target, const GLint *v)
{
    args_glMultiTexCoord4ivARB argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord4ivarb_uh(argp);
}

// -- glMultiTexCoord4sARB
void glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q)
{
    args_glMultiTexCoord4sARB argp;

    // Set function specific args
    argp.target = target;
	argp.s = s;
	argp.t = t;
	argp.r = r;
	argp.q = q;

    glmultitexcoord4sarb_uh(argp);
}

// -- glMultiTexCoord4svARB
void glMultiTexCoord4svARB(GLenum target, const GLshort *v)
{
    args_glMultiTexCoord4svARB argp;

    // Set function specific args
    argp.target = target;
	argp.v = v;

    glmultitexcoord4svarb_uh(argp);
}

// -- glXChooseVisual
XVisualInfo* glXChooseVisual(Display *dpy, int screen, int *attribList)
{
    args_glXChooseVisual argp;
    
    // Set function specific args
    argp.dpy = dpy;
	argp.screen = screen;
	argp.attribList = attribList;
    
    return glxchoosevisual_uh(argp);
}

// -- glXQueryDrawable
extern void glXQueryDrawable(Display *dpy, GLXDrawable draw, int attribute, unsigned int *value)
{
    args_glXQueryDrawable argp;

    // Set function specific args
    argp.dpy = dpy;
	argp.draw = draw;
	argp.attribute = attribute;
	argp.value = value;

    glxquerydrawable_uh(argp);
}

// -- glXCreateContext
GLXContext glXCreateContext(Display *dpy, XVisualInfo *vis, GLXContext shareList, Bool direct)
{
    args_glXCreateContext argp;
    
    // Set function specific args
    argp.dpy = dpy;
	argp.vis = vis;
	argp.shareList = shareList;
	argp.direct = direct;
    
    return glxcreatecontext_uh(argp);
}

// -- glXDestroyContext
void glXDestroyContext( Display *dpy, GLXContext ctx )
{
    args_glXDestroyContext argp;

    // Set function specific args
    argp.dpy = dpy;
	argp.ctx = ctx;

    glxdestroycontext_uh(argp);
}

// -- glXSwapBuffers
void glXSwapBuffers( Display *dpy, GLXDrawable drawable )
{
    args_glXSwapBuffers argp;

    // Set function specific args
    argp.dpy = dpy;
	argp.drawable = drawable;

    glxswapbuffers_uh(argp);
}

// -- glXDestroyGLXPixmap
void glXDestroyGLXPixmap( Display *dpy, GLXPixmap pixmap )
{
    args_glXDestroyGLXPixmap argp;

    // Set function specific args
    argp.dpy = dpy;
	argp.pixmap = pixmap;

    glxdestroyglxpixmap_uh(argp);
}

// -- glXQueryExtension
Bool glXQueryExtension( Display *dpy, int *errorb, int *event )
{
    args_glXQueryExtension argp;
    
    // Set function specific args
    argp.dpy = dpy;
	argp.errorb = errorb;
	argp.event = event;
    
    return glxqueryextension_uh(argp);
}

// -- glXQueryVersion
Bool glXQueryVersion( Display *dpy, int *maj, int *min )
{
    args_glXQueryVersion argp;
    
    // Set function specific args
    argp.dpy = dpy;
	argp.maj = maj;
	argp.min = min;
    
    return glxqueryversion_uh(argp);
}

// -- glXIsDirect
Bool glXIsDirect( Display *dpy, GLXContext ctx )
{
    args_glXIsDirect argp;
    
    // Set function specific args
    argp.dpy = dpy;
	argp.ctx = ctx;
    
    return glxisdirect_uh(argp);
}

// -- glXGetCurrentContext
GLXContext glXGetCurrentContext()
{
    return glxgetcurrentcontext_uh();
}

// -- glXGetCurrentDrawable
GLXDrawable glXGetCurrentDrawable()
{
    return glxgetcurrentdrawable_uh();
}

// -- glXWaitGL
void glXWaitGL()
{
    glxwaitgl_uh();
}

// -- glXWaitX
void glXWaitX()
{
    glxwaitx_uh();
}

// -- glXUseXFont
void glXUseXFont( Font font, int first, int count, int list )
{
    args_glXUseXFont argp;

    // Set function specific args
    argp.font = font;
	argp.first = first;
	argp.count = count;
	argp.list = list;

    glxusexfont_uh(argp);
}

// -- glXQueryExtensionsString
const char *glXQueryExtensionsString( Display *dpy, int screen )
{
    args_glXQueryExtensionsString argp;
    
    // Set function specific args
    argp.dpy = dpy;
	argp.screen = screen;
    
    return glxqueryextensionsstring_uh(argp);
}

// -- glXGetCurrentDisplay
Display *glXGetCurrentDisplay()
{
    return glxgetcurrentdisplay_uh();
}

// -- glXDestroyWindow
void glXDestroyWindow( Display *dpy, GLXWindow window )
{
    args_glXDestroyWindow argp;

    // Set function specific args
    argp.dpy = dpy;
	argp.window = window;

    glxdestroywindow_uh(argp);
}

// -- glXDestroyPixmap
void glXDestroyPixmap( Display *dpy, GLXPixmap pixmap )
{
    args_glXDestroyPixmap argp;

    // Set function specific args
    argp.dpy = dpy;
	argp.pixmap = pixmap;

    glxdestroypixmap_uh(argp);
}

// -- glXDestroyPbuffer
void glXDestroyPbuffer( Display *dpy, GLXPbuffer pbuf )
{
    args_glXDestroyPbuffer argp;

    // Set function specific args
    argp.dpy = dpy;
	argp.pbuf = pbuf;

    glxdestroypbuffer_uh(argp);
}

// -- glXGetCurrentReadDrawable
GLXDrawable glXGetCurrentReadDrawable()
{
    return glxgetcurrentreaddrawable_uh();
}

// -- glXGetProcAddressARB
extern __GLXextFuncPtr glXGetProcAddressARB (const GLubyte *procname)
{
    args_glXGetProcAddressARB argp;
    
    // Set function specific args
    argp.procname = procname;
    
    return glxgetprocaddressarb_uh(argp);
}

// -- glXGetProcAddress
extern void *glXGetProcAddress(const GLubyte *procname)
{
    args_glXGetProcAddress argp;
    
    // Set function specific args
    argp.procname = procname;
    
    return glxgetprocaddress_uh(argp);
}

// -- glXAllocateMemoryNV
void *glXAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority)
{
    args_glXAllocateMemoryNV argp;
    
    // Set function specific args
    argp.size = size;
	argp.readfreq = readfreq;
	argp.writefreq = writefreq;
	argp.priority = priority;
    
    return glxallocatememorynv_uh(argp);
}

// -- glXFreeMemoryNV
void glXFreeMemoryNV(GLvoid *pointer)
{
    args_glXFreeMemoryNV argp;

    // Set function specific args
    argp.pointer = pointer;

    glxfreememorynv_uh(argp);
}
