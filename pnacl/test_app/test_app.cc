#include <map>
#include <stdio.h>

#include "ppapi/cpp/instance.h"
#include "ppapi/cpp/module.h"
#include "ppapi/cpp/var.h"

class TestAppInstance : public pp::Instance {
    private:
        std::map<char, char> code_dict;

    public:
        explicit TestAppInstance(PP_Instance instance) : pp::Instance(instance) {
            code_dict['a'] = 'a';
            code_dict['b'] = 'd';
            code_dict['c'] = 'x';
            code_dict['d'] = 'b';
            code_dict['e'] = 'e';
            code_dict['f'] = 'p';
            code_dict['g'] = 'j';
            code_dict['h'] = 'k';
            code_dict['i'] = 'i';
            code_dict['j'] = 'g';
            code_dict['k'] = 'h';
            code_dict['l'] = 't';
            code_dict['m'] = 'n';
            code_dict['n'] = 'm';
            code_dict['o'] = 'o';
            code_dict['p'] = 'f';
            code_dict['q'] = 'q';
            code_dict['r'] = 'v';
            code_dict['s'] = 'z';
            code_dict['t'] = 'l';
            code_dict['u'] = 'u';
            code_dict['v'] = 'r';
            code_dict['w'] = 'y';
            code_dict['x'] = 'c';
            code_dict['y'] = 'w';
            code_dict['z'] = 's';
        }

        virtual ~TestAppInstance() {}

        virtual void HandleMessage(const pp::Var& var_msg) {
            if (!var_msg.is_string()) {
                return;
            }

            std::string input = var_msg.AsString();
            std::string output = "";

            int i;
            for (i = 0; i < input.length(); i++) {
                char c = input[i];
                bool is_upper = false;

                if (isupper(c)) {
                    is_upper = true;
                    c = tolower(c);
                }

                if (code_dict.find(c) != code_dict.end()) {
                    output += is_upper? toupper(code_dict[c]) : code_dict[c];
                } else {
                    output += c;
                }
            }

            PostMessage(output);
        }
};

class TestAppModule : public pp::Module {
    public:
        TestAppModule() : pp::Module() {}
        virtual ~TestAppModule() {}

        virtual pp::Instance* CreateInstance(PP_Instance instance) {
            return new TestAppInstance(instance);
        }
};

namespace pp {
    Module* CreateModule() {
        return new TestAppModule();
    }
}
