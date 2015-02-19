#include "stream_locale.h"

const char s_version[]=
"1.0";

const char HLINE[]=
"-------------------------------------------------------------\n";

const char *label[4] = 
{"Copy:      ","Scale:     ","Add:       ","Triad:     "};

const char s_version_str[]=
"EuSTREAM version %s \n";

const char info_bytes_array[]=
"This system uses %d bytes per array element.\n"
"-------------------------------------------------------------\n"
"Array size = %llu (elements), Offset = %d (elements)\n"
"Memory per array = %.1f MiB (= %.1f GiB).\n"
"Total memory required = %.1f MiB (= %.1f GiB).\n"
"Each kernel will be executed %d times.\n"
" The *best* time for each kernel (excluding the first iteration)\n"
" will be used to compute the reported bandwidth.\n"
"-------------------------------------------------------------\n";

const char guidelines[]=
"Each test below will take on the order of %d microseconds.\n"
"   (= %d clock ticks)\n"
"Increase the size of the arrays if this shows that\n"
"you are not getting at least 20 clock ticks per test.\n"
"-------------------------------------------------------------\n"
"WARNING -- The above is only a rough guideline.\n"
"For best results, please be sure you know the\n"
"precision of your system timer.\n"
"-------------------------------------------------------------\n";

const char help_string[]=
"\nEuStreams V0.1 forked from Stream V5.10\n"
",----------------------------------------------------------------------------------,\n"
"| Usage: stream [-s|--array_size <longlong> -i|--iterations <longlong> ] [options] |\n"
"|       stream [-h|--help] [-v|--version]                                          |\n"
"|                                                                                  |\n"
"|  -s, --array_size <longlong>      Specify array size - default is 1000000        |\n"
"|  -i, --iterations <longlong>      Specify # iterations - default is 10           |\n"
"|  -v, --verbose                    Print info                                     |\n"                                
"|  -d, --debug  #                   Print more info                                |\n" 
"|  -m, --machine                    Print only data                                |\n"
"'----------------------------------------------------------------------------------'\n\n";
