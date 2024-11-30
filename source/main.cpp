#include "cmd.h"

#include <string.h>

#include <codecvt>
#include <locale>
#include <string>

#ifdef _WIN32

int wmain(int argc, wchar_t **argv, wchar_t **envp) {
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;

    char *nargv[argc];
    for(int i = 0; i < argc; i++) {
        nargv[i] = strdup(converter.to_bytes((char16_t *)(argv[i])).c_str());
    }

    return cmd_process_command(argc, nargv);
}

#else

int main(int argc, char* argv[]) {
    return cmd_process_command(argc, argv);
}

#endif
