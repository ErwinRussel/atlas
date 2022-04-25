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
hook_func_ni = '''
// -- {name}
{hook}{{
    return {name_lower}_uh()
}}
'''
hook_func_void = '''
// -- {name}
{hook}{{
    argp_{name} argp;

    // Set function specific args
    {argp_set}

    {name_lower}_uh(&argp)
}}
'''
hook_func_ni_void = '''
// -- {name}
{hook}{{
    {name_lower}_uh()
}}
'''

def get_argp_set(function_args):
    argp_set = []
    # The args must be nonempty
    if function_args[0] != '':
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
            args = function['args']
            ret_type = function['ret_type']
            # If void function, no return type
            if ret_type == "void":
                # Make sure we use no input func if there are no inputs
                if len(args) == 1 and args[0] == '':
                    f.write(hook_func_ni_void.format(hook=hook, name=name, name_lower=name_lower))
                    continue

                argp_set = get_argp_set(args)
                f.write(hook_func_void.format(hook=hook, name=name, name_lower=name_lower, argp_set=argp_set))

            else:
                # Make sure we use no input func if there are no inputs
                if len(args) == 1 and args[0] == '':
                    f.write(hook_func_ni.format(hook=hook, name=name, name_lower=name_lower))
                    continue

                argp_set = get_argp_set(args)
                f.write(hook_func.format(hook=hook, name=name, name_lower=name_lower, argp_set=argp_set))
