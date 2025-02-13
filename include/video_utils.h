#ifndef VIDEO_UTILS_H
#define VIDEO_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

/**
 * @brief Retrieves the video path from the program arguments.
 *
 * This function extracts the video file path passed as an argument during the program launch.
 *
 * @param argc Number of arguments.
 * @param argv Array of arguments.
 * @return char* String containing the video path (dynamically allocated, must be freed by the caller)
 *         or NULL in case of error or missing argument.
*/
char * get_video_path(int argc, char *argv[]);

/**
 * @brief Checks if the video file exists and is accessible.
 *
 * @param video_path Path to the video file.
 * @return int 0 if the file is accessible, otherwise a different value (e.g., 1).
*/
int check_video_file(const char * video_path);

/**
 * @brief Displays the correct usage of the program.
 *
 * @param program_name Name of the program (argv[0]).
*/
void print_usage(const char * program_name);


#endif
