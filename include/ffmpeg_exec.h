#ifndef FFMPEG_EXEC_H
#define FFMPEG_EXEC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

/**
 * @brief Construit et exécute la commande ffmpeg pour dupliquer (interpoler) les frames de la vidéo.
 *
 * La commande ffmpeg devra être configurée pour doubler le nombre de frames (par exemple en utilisant un filtre tel que minterpolate).
 *
 * @param video_path Chemin vers le fichier vidéo d'entrée.
 * @return int 0 si l'exécution s'est déroulée correctement, sinon une valeur différente.
 */
int duplicate_frames(const char * video_path, float framerate);

/**
 * @brief Check le framerate de la vidéo et le recupère.
 *
 * La commande ffprobe devra être configurée pour récupérer le framerate de la video
 *
 * @param video_path Chemin vers le fichier vidéo d'entrée.
 * @return float de la valeur du framerate de la vidéo.
 */
float get_framerate(const char * video_path);

#endif
