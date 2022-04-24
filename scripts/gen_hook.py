h1 = '''#include "atl_header.h"
'''
hook_func = '''
// -- {name}
{hook}{{
    argp_{name} argp;
    
    // Set function specific args
    {argp_set}
    
    return {name_lower}_uh(&argp)
}}
'''

def get_argp_set(function_args):
    argp_set = []
    for arg in function_args:
        var_name = arg.split()[-1]
        if var_name[0] == '*':
            var_name = var_name[1:]
        set_line = "argp.{var_name} = {var_name}".format(arg=arg, var_name=var_name)
        argp_set.append(set_line)

    return ";\n\t".join(argp_set)

def gen_hook_lib(functions):
    with open("output/atl_hook.c", 'w') as f:
        # h1
        f.write(h1)

        # hook functions
        for function in functions:
            hook = function['hook']
            name = function['name']
            name_lower = name.lower()
            argp_set = get_argp_set(function['args'])
            f.write(hook_func.format(hook=hook, name=name, name_lower=name_lower, argp_set=argp_set))
