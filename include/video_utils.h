#ifndef VIDEO_UTILS_H
#define VIDEO_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

/**
 * @brief Récupère le chemin de la vidéo à partir des arguments du programme.
 *
 * Cette fonction extrait le chemin du fichier vidéo passé en argument lors du lancement.
 *
 * @param argc Nombre d'arguments.
 * @param argv Tableau des arguments.
 * @return char* Chaîne contenant le chemin de la vidéo (allouée dynamiquement, à libérer par l'appelant)
 *         ou NULL en cas d'erreur ou d'argument manquant.
 */
char * get_video_path(int argc, char *argv[]);

/**
 * @brief Vérifie si le fichier vidéo existe et est accessible.
 *
 * @param video_path Chemin vers le fichier vidéo.
 * @return int 0 si le fichier est accessible, sinon une valeur différente (ex : 1).
 */
int check_video_file(const char * video_path);

/**
 * @brief Affiche l'utilisation correcte du programme.
 *
 * @param program_name Nom du programme (argv[0]).
 */
void print_usage(const char * program_name);

#endif
