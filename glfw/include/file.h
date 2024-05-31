#pragma once

class File {
public:
    File();
    File(char const *filename);

    ~File();

    void get_file_size();
    void parse_mapping();

    char const *filename;
    char const *file_contents;
    long file_size;
};
