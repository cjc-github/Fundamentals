#include <stdio.h>
#include <unistd.h>
int main(int argc, char * const argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, "a:b:c:d:")) != -1) {
        switch (opt) {
            case 'a':
                printf("Option -a with value '%s'\n", optarg);
                break;
            case 'b':
                printf("Option -b with value '%s'\n", optarg);
                break;
            case 'c':
                printf("Option -c with value '%s'\n", optarg);
                break;
            case 'd':
                printf("Option -d with value '%s'\n", optarg);
                break;
            case '?':
                printf("Unknown option: %c\n", optopt);
                break;
            case ':':
                printf("Option -%c requires an argument\n", optopt);
                break;
        }
    }
    return 0;
}