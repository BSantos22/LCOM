#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xpm.h"

char **get_xpm(unsigned short xpm) {
	char **images[N_IMAGES];

	images[0] = shot;
	images[1] = crosshair;
	images[2] = platform;
    images[3] = arrow;
    images[4] = blue_tropper;
    images[5] = red_tropper;
    images[6] = hearth;
    images[7] = pewpew;
    images[8] = start;
    images[9] = player;
    images[10] = player1;
    images[11] = player2;
    images[12] = wins;
    images[13] = exclamation;
    images[14] = time_bar;
    images[15] = time_bar_other;

	if (xpm < 0 || xpm >= N_IMAGES) {
		return NULL;
	}
	else {
		return images[xpm];
	}
}


// DEFAULTED TO VBE 0x105 MODE
char *read_xpm(char *map[], int *wd, int *ht)
{
  int width, height, colors;
  char sym[256];
  int  col;
  int i, j;
  char *pix, *pixtmp, *tmp, *line;
  char symbol;

  /* read width, height, colors */
  if (sscanf(map[0],"%d %d %d", &width, &height, &colors) != 3) {
    printf("read_xpm: incorrect width, height, colors\n");
    return NULL;
  }

#ifdef DEBUG
  printf("%d %d %d\n", width, height, colors);
#endif
  if (width > H_RES || height > V_RES || colors > 256) { // mode 0x105
    printf("read_xpm: incorrect width, height, colors\n");
    return NULL;
  }

  *wd = width;
  *ht = height;

  for (i=0; i<256; i++)
    sym[i] = 0;

  /* read symbols <-> colors */
  for (i=0; i<colors; i++) {
    if (sscanf(map[i+1], "%c %d", &symbol, &col) != 2) {
      printf("read_xpm: incorrect symbol, color at line %d\n", i+1);
      return NULL;
    }
#ifdef DEBUG
    printf("%c %d\n", symbol, col);
#endif
    if (col > 256) {
      printf("read_xpm: incorrect color at line %d\n", i+1);
      return NULL;
    }
    sym[col] = symbol;
  }

  /* allocate pixmap memory */
  pix = pixtmp = malloc(width*height);

  /* parse each pixmap symbol line */
  for (i=0; i<height; i++) {
    line = map[colors+1+i];
#ifdef DEBUG
    printf("\nparsing %s\n", line);
#endif
    for (j=0; j<width; j++) {
      tmp = memchr(sym, line[j], 256);  /* find color of each symbol */
      if (tmp == NULL) {
    	  printf("read_xpm: incorrect symbol at line %d, col %d\n", colors+i+1, j);
    	  return NULL;
      }
      *pixtmp++ = tmp - sym; /* pointer arithmetic! back to books :-) */
#ifdef DEBUG
      printf("%c:%d ", line[j], tmp-sym);
#endif
    }
  }

  return pix;
}
