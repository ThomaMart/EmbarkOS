#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>
#include <unistd.h>

#define VERSION "0.1.0"
#define BOARD   "Raspberry Pi 3"

static void show_help(void)
{
    printf("EmbarkOS System Information\n\n");
    printf("Usage:\n");
    printf("    embark-info [OPTION]\n\n");
    printf("Options:\n");
    printf("    --version\n");
    printf("    --hostname\n");
    printf("    --kernel\n");
    printf("    --board\n");
    printf("    --help\n");
}

static void show_info(void)
{
    struct utsname u;

    uname(&u);

    char hostname[64];
    gethostname(hostname, sizeof(hostname));

    printf("=========================================\n");
    printf("            EmbarkOS\n");
    printf("=========================================\n\n");

    printf("Version      : %s\n", VERSION);
    printf("Hostname     : %s\n", hostname);
    printf("Kernel       : %s\n", u.release);
    printf("Architecture : %s\n", u.machine);
    printf("Board        : %s\n", BOARD);
}

int main(int argc, char *argv[])
{
    struct utsname u;
    uname(&u);

    char hostname[64];
    gethostname(hostname, sizeof(hostname));

    if (argc == 1) {
        show_info();
        return 0;
    }

    if (!strcmp(argv[1], "--version")) {
        printf("%s\n", VERSION);
    } else if (!strcmp(argv[1], "--hostname")) {
        printf("%s\n", hostname);
    } else if (!strcmp(argv[1], "--kernel")) {
        printf("%s\n", u.release);
    } else if (!strcmp(argv[1], "--board")) {
        printf("%s\n", BOARD);
    } else if (!strcmp(argv[1], "--help")) {
        show_help();
    } else {
        fprintf(stderr, "Unknown option: %s\n", argv[1]);
        return 1;
    }

    return 0;
}