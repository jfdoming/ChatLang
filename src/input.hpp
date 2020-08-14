#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Input {
    public:
        Input(int argc, char **argv) {
            if (argc == 1) {
                stream = &std::cin;
                destroy = false;
            } else if (argc == 2) {
                stream = new std::fstream(argv[1]);
                destroy = true;
            }
        }
        ~Input() {
            if (destroy) {
                delete stream;
            }
        }

        bool next(std::string &line) {
            if (!stream) {
                return false;
            }
            return !!getline(*stream, line);
        }

        operator bool() {
            return stream && *stream;
        }
    private:
        bool destroy = false;
        std::istream *stream = nullptr;
};