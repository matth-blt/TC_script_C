#ifndef FFMPEG_EXEC_H
#define FFMPEG_EXEC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

typedef struct {
    int numerateur;
    int denominateur;
} Fraction;

/**
 * @brief Check the framerate of the video and retrieve it.
 *
 * The ffprobe command should be configured to retrieve the framerate of the video.
 *
 * @param video_path Path to the input video file.
 * @return Fraction representing the framerate of the video.
*/
Fraction get_framerate(const char * video_path);

/**
 * @brief Multiplies the framerate fraction by two.
 *
 * This function takes a fraction representing a framerate and multiplies its numerator by two,
 * effectively doubling the framerate while keeping the denominator unchanged.
 *
 * @param frac The fraction representing the original framerate.
 * @return Fraction representing the doubled framerate.
*/
Fraction multiplicateur_framerate(Fraction frac);

/**
 * @brief Constructs and executes the ffmpeg command to duplicate (interpolate) the frames of the video.
 *
 * The ffmpeg command should be configured to double the number of frames (for example, using a filter such as minterpolate).
 *
 * @param video_path Path to the input video file.
 * @return int 0 if the execution was successful, otherwise a different value.
*/
int duplicate_frames(const char * video_path);

#endif
