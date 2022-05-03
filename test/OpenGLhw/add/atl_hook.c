#include "atl_header.h"
#include "atl_uh.h"

// -- XCreateColormap
Colormap XCreateColormap(Display *display, Window w, Visual *visual, int alloc){
    args_XCreateColormap argp;
    
    // Set function specific args
    argp.display = display;
	argp.w = w;
	argp.visual = visual;
	argp.alloc = alloc;
    
    return xcreatecolormap_uh(argp);
}
