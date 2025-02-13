#include "../include/video_utils.h"

char * get_video_path(int argc, char *argv[])
{
    int taille = 0;
    char * path = NULL;

    if (strcmp(argv[1], "--path") == 0) {
        if (argc == 3) {
            taille = strlen(argv[2]) + 1;
            path = malloc(sizeof(char) * taille);
            strcpy(path, argv[2]);
        }
    }

    for(int i = 0 ; i < taille ; i++) {
        if (path[i] == '\\') {
            path[i] = '/';
        }
    }

    return path;
}

int check_video_file(const char * video_path)
{
    if (access(video_path, F_OK) == 0) {
        return 0;
    } else {
        return 1;
    }
}

void print_usage(const char * program_name)
{
    printf("-------GUIDE-UTILISATION-------\n");
    printf("COMMANDE\n");
    printf("--> %s --path {ton-path}\n", program_name);
}