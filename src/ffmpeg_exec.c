#include "../include/ffmpeg_exec.h"

// int duplicate_frames(const char *video_path, float framerate)
// {
//     char output_file[512];
//     // Crée le nom de fichier de sortie en remplaçant l'extension par ".mjpeg"
//     strncpy(output_file, video_path, sizeof(output_file));
//     output_file[sizeof(output_file) - 1] = '\0';

//     char *dot = strrchr(output_file, '.');
//     if (dot) {
//         strcpy(dot, ".mjpeg");
//     } else {
//         strcat(output_file, ".mjpeg");
//     }

//     char command[1024];
//     snprintf(command, sizeof(command),
//              "ffmpeg -y -i \"%s\" -vf \"fps=%f\" -s 256x256 -c:v mjpeg -q:v 5 \"%s\"",
//              video_path, framerate, output_file);

//     printf("Exécution de la commande : %s\n", command);

//     // Exécution bloquante de la commande ffmpeg
//     int status = system(command);
//     return (status == 0) ? 0 : 1;
// }

int duplicate_frames(const char * video_path, float framerate)
{
    char fps[32];
    sprintf(fps, "fps=%f", framerate);
    char ffmpeg_command[512];
    sprintf(ffmpeg_command, "ffmpeg -i %s -vf %s -c:v libx264 -crf 18 -preset fast -c:a copy C:/Users/matth/Videos/timelens/VSCode_C/project/output/output.mp4", video_path, fps);
    
    printf("%s\n", fps);
    printf("%s\n", ffmpeg_command);

    return 0;
}

float get_framerate(const char * video_path)
{
    char ffprobe_command[512];
    sprintf(ffprobe_command, "ffprobe -v error -select_streams v:0 -show_entries stream=r_frame_rate -of default=noprint_wrappers=1:nokey=1 \"%s\""" > framerate.txt", video_path);
    
    //printf("%s\n", ffprobe_command);
    system(ffprobe_command);

    FILE *pipe = popen(ffprobe_command, "r");
    if (pipe == NULL) {
        fprintf(stderr, "Erreur lors de l'exécution de la commande.\n");
        return 1;
    }

    // Ouvrir le fichier de sortie en écriture
    FILE *output_file = fopen("C:/Users/matth/Videos/timelens/VSCode_C/project/framerate.txt", "w");
    if (output_file == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier de sortie.\n");
        pclose(pipe);
        return 1;
    }

    // Buffer pour lire la sortie de la commande
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        // Écrire chaque ligne lue dans le fichier
        fputs(buffer, output_file);
    }

    // Fermer le fichier et le pipe
    fclose(output_file);
    pclose(pipe);
}

// float get_framerate(const char *video_path)
// {
//     char cmd[512];
//     char buffer[64];
//     float num, den, framerate = 0.0;

//     snprintf(cmd, sizeof(cmd),
//              "ffprobe -v error -select_streams v:0 -show_entries stream=avg_frame_rate "
//              "-of default=noprint_wrappers=1:nokey=1 \"%s\"",
//              video_path);

//     FILE *fp = popen(cmd, "r");
//     if (fp == NULL) {
//         perror("popen");
//         return -1;
//     }

//     if (fgets(buffer, sizeof(buffer), fp) != NULL) {
//         if (sscanf(buffer, "%f/%f", &num, &den) == 2 && den != 0)
//             framerate = num / den;
//     }

//     pclose(fp);
//     return framerate * 2;
// }
