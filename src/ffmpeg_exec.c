#include "../include/ffmpeg_exec.h"

Fraction get_framerate(const char * video_path)
{
    char cmd[512];
    char buffer[64];
    Fraction framerate = {0, 1};

    snprintf(cmd, sizeof(cmd),
             "ffprobe -v error -select_streams v:0 -show_entries stream=avg_frame_rate -of default=noprint_wrappers=1:nokey=1 \"%s\"",
             video_path);

    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("popen");
        return framerate;
    }

    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (sscanf(buffer, "%d/%d", &framerate.numerateur, &framerate.denominateur) == 2 && framerate.denominateur != 0) {
        }
    }

    pclose(fp);
    return framerate;
}

Fraction multiplicateur_framerate(Fraction frac)
{
    Fraction result = {frac.numerateur * 2, frac.denominateur};
    return result;
}

int duplicate_frames(const char * video_path)
{
    char fps[32];
    
    Fraction framerate = get_framerate(video_path);
    framerate = multiplicateur_framerate(framerate);
    sprintf(fps, "fps=%d/%d", framerate.numerateur, framerate.denominateur);
    char output_path[] = "./output/%08d.jpg";

    char ffmpeg_command[512];
    sprintf(ffmpeg_command, "ffmpeg -i %s -vf %s -s 256x256 -sws_flags spline+accurate_rnd+full_chroma_int -color_trc 2 -colorspace 2 -color_primaries 2 -map 0:v -c:v mjpeg -pix_fmt yuvj420p -q:v 1 -start_number 0 %s", video_path, fps, output_path);
    
    system(ffmpeg_command);

    return 0;
}