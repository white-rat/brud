/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>



/* DEFINES */
#define NAME    "Brutforce dictionary creator"
#define VERSION "v1.0.0 beta"

#define ERROR   "\x1b[9m"
#define RED     "\x1b[1;31m"
#define GREEN   "\x1b[1;32m"
#define BLUE    "\x1b[1;34m"
#define YELLOW  "\x1b[1;33m"
#define CYAN    "\x1b[1;36m"
#define RESET   "\x1b[0m"



/* PROTOTYPE OF FUNCTIONS */
void print_help(void);
void print_version(void);
void validate_flags(const int, const char**);
void generate_dictionary(void);



/* DECLARATION ARRAYS */
const char lower_case[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

const char capital_case[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

const char numbers[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

const char special[] = {
    '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.',
    '/', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`',
    '{', '|', '}', '~'
};

const char* allow_flags[] = {
    "--lower", "--capital", "--numbers", "--special", "--version", "--help",
    "-l", "-c", "-n", "-s", "-v", "-h"
};



/* MAIN FUNCTION */
int main(const int argc, const char **argv)
{
    if (argc < 2) {
        printf(GREEN "\nUse --help or -h\n\n" RESET);
        exit(EXIT_SUCCESS);
    } else {
        validate_flags(argc, argv);
        generate_dictionary();
    }

    return EXIT_SUCCESS;
}



/* FUNCTIONS */
void print_version(void)
{
    printf(GREEN "%s\n" RESET, VERSION);
}

void print_help(void)
{
    printf("\n");
    printf(GREEN "%s\n" RESET, NAME);
    printf(GREEN "%s\n" RESET, VERSION);
    printf("\n");

    printf(GREEN "--lower -l\tlower case letters a-z\n" RESET);
    printf(GREEN "--capital -c\tcapital case letters A-Z\n" RESET);
    printf(GREEN "--numbers -n\tnumbers 0-9\n");
    printf(GREEN "--special -s\tspecial characters\n" RESET);
    printf(GREEN "--version -v\tprint version\n" RESET);
    printf(GREEN "--help -h\tprint help\n" RESET);
    printf("\n");
}

void validate_flags(const int argc, const char **argv)
{
    for (size_t i = 1; i < argc; ++i) {
        for (size_t j = 0; j < argc; ++j) {
            if (argv[i] != allow_flags[j]) {
                printf("[!] Error: invalid flag" RED " \"%s\"\n\n" RESET,
                        argv[i]);
                exit(EXIT_FAILURE);
            }
        }
    }
}

void generate_dictionary(void)
{
}
