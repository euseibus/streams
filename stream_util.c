#include "stream_util.h"
#include "stream_locale.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
/******************************************************************************/

int stream_parse_arguments(struct stream_opts *strm, int argc, char **argv)
{
    static struct option longopts[] =
    {
        {"array_size", required_argument, NULL, 's'},
        {"iterations", required_argument, NULL, 'i'},
        {"verbose", no_argument, NULL, 'v'},
        {"machine", no_argument, NULL, 'm'},
        {"debug", no_argument, NULL, 'd'},
        {"help", no_argument, NULL, 'h'},
        {NULL, 0, NULL, 0}
    };
    int flag;

    /**
     Defaults
     */
    strm->verbosity=0;
    strm->array_size=10000000;
    strm->iterations=10;
    
    
    while ((flag = getopt_long(argc, argv, "s:i:vmdh", longopts, NULL)) != -1) {
        switch (flag) {
            case 's':
                strm->array_size = strtoull(optarg,0,10);
                break;
            case 'i':
                strm->iterations = strtoull(optarg,0,10);
                break;
            case 'v':
                strm->verbosity=1;
                break;
            case 'd':
                strm->verbosity=2;
                break;
            case 'm':
                strm->verbosity=-1;
                break;
            case 'h':
                fprintf(stderr, help_string);
                exit(1);
                break;
            default:
                //no options no problem 
                break;
        }
    }
    return 0;
}
