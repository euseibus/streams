#ifndef         STREAM_UTIL_H
#define         STREAM_UTIL_H



/** Verbosity levels */
#define VERBOSE 1
#define NORMAL 0
#define DEBUG 2
#define MACHINE -1
/*********************/

struct stream_opts
{
    unsigned long long array_size;
    unsigned long long iterations;
    int verbosity;
};

int stream_parse_arguments(struct stream_opts *strm, int argc, char **argv);

#endif