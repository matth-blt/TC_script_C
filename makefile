CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/video_utils.c src/ffmpeg_exec.c
OBJ = $(SRC:.c=.o)
EXEC = bop

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
