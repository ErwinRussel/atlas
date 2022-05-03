from scripts.gen_header import *
from scripts.gen_lh import *
from scripts.gen_uh import *
from scripts.gen_hook import *

class AtlasGenerator:
    def __init__(self) -> None:
        super().__init__()

        self.functions = []
        self.output_folder = ""

    # todo; what should we do with "extern"???
    def parse_function(self, line):
        func_name = line[:line.find('(')].split()[-1]
        # todo: is this a good idea or nah?
        ptr_type = False
        if func_name[0] == '*':
            func_name = func_name[1:]
            ptr_type = True
        func_args = line[line.find('(') + 1:line.find(')')].split(",")
        return_type_list = line[:line.find('(')].split()[:-1]
        if "extern" in return_type_list:
            return_type_list.remove("extern")
        if "const" in return_type_list:
            return_type_list.remove("const")
        func_return_type = " ".join(return_type_list)
        if ptr_type:
            func_return_type = func_return_type + "*"
        # Add function to list of functions.
        function = {}
        function['hook'] = line
        function['name'] = func_name
        function['args'] = func_args
        function['ret_type'] = func_return_type
        self.functions.append(function)

    def read_functions(self, func_list_filename):
        with open(func_list_filename, "r") as f:
            lines = f.readlines()
            for line in lines:
                # Skip comment
                if "//" in line:
                    continue
                # Header file to be included
                if "#" in line:
                    header_file = line.split()[1]
                    continue

                # Make sure we have some parentheses in the line
                if "(" in line and ")" in line:
                    self.parse_function(line)

    def gen_shared_header(self):
        gen_shared_header(self.functions, self.output_folder)

    def gen_lower_half(self):
        gen_lower_half(self.functions, self.output_folder)

    def gen_upper_half(self):
        gen_upper_half(self.functions, self.output_folder)

    def gen_hook_lib(self):
        gen_hook_lib(self.functions, self.output_folder)

if __name__ == '__main__':
    # Parse all of the functions.
    ag = AtlasGenerator()
    ag.output_folder = "test/OpenGLhw/add/"
    ag.read_functions("test/OpenGLhw/addfunction.txt")
    # Create header file from parsed functions.
    ag.gen_lower_half()
    # Create lower half/server side
    ag.gen_shared_header()
    # Create upper half/client side
    ag.gen_upper_half()
    # Create hook library
    ag.gen_hook_lib()

