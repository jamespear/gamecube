#include "file.h"
#include <stdlib.h>
#include <string>

File::File() {}

File::File(char const *filename) : filename(filename) {
    get_file_size();
    parse_mapping();
}

File::~File() {}

void File::get_file_size() {
    FILE *fp = fopen(this->filename, "r");
    if (!fp) {
        printf("Mappings not loaded!\n");
        this->file_size = -1;
    } else {
        fseek(fp, 0, SEEK_END);
        this->file_size = ftell(fp);
    }
    fclose(fp);
}

void File::parse_mapping() {
    FILE *fp = fopen(this->filename, "r");
    char buffer[this->file_size];
    while (!feof(fp)) {
        fread(buffer, sizeof(buffer), 1, fp);
    }
    fclose(fp);
    this->file_contents = buffer;
}
