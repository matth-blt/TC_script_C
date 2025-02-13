# TC SCRIPT C

This project contains a C script that uses `ffmpeg` and `ffprobe` to duplicate video frames, effectively doubling the framerate of a video.

## Prerequisites

- `gcc` to compile the C code
- `ffmpeg` and `ffprobe` to process the videos

## Installation

1. Clone this repository:
    ```sh
    git clone https://github.com/matth-blt/TC_script_C.git
    cd TC_script_C
    ```

2. Create an [`output`](output ) directory in the main directory:
    ```sh
    mkdir output
    ```

3. Compile the project:
    ```sh
    make
    ```

## Usage

To use the script, run the following command:

```sh
./bop --path /path/to/your/video

