#include "../include/video_utils.h"
#include "../include/ffmpeg_exec.h"

/**
 * @brief Point d'entrée du programme.
 *
 * @param argc Nombre d'arguments.
 * @param argv Tableau des arguments.
 * @return int Code de retour du programme.
 */
int main(int argc, char *argv[])
{
    char * video_path = get_video_path(argc, argv);
    
    if (argc > 3) {
        printf("Trop d'arguments !");
        print_usage(argv[0]);
        exit(1);
    }
    
    if (argc < 3) {
        if (argc < 2 || strcmp(argv[1], "--path") != 0) {
            printf("Manque la Commande !\n");
        } else {
            printf("Manque le Path !\n");
        }
        print_usage(argv[0]);
        exit(1);
    } else {
        if (check_video_file(video_path) != 0) {
            printf("Erreur : le fichier vidéo '%s' n'existe pas ou n'est pas accessible.\n", video_path);
            print_usage(argv[0]);
            free(video_path);
            exit(1);
        } else {
            printf("Video Check --> OK\n");
        }
    }

    float framerate = get_framerate(video_path);

    //duplicate_frames(video_path, framerate);

    free(video_path);
    return EXIT_SUCCESS;
}
