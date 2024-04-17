#ifndef MyBigChars
#define MyBigChars

#include "myTerm.h"
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// acs chars
#define CKBOARD ("a")  // ▒
#define HLINE ("q")    // ─
#define VLINE ("x")    // │
#define LUCORNER ("l") // ┌
#define LDCORNER ("m") // └
#define RDCORNER ("j") // ┘
#define RUCORNER ("k") // ┐

int bc_printA (char *str);

int bc_box (int x1, int y1, int x2, int y2, enum colors box_fg,
            enum colors box_bg, char *header, enum colors header_fg,
            enum colors header_bg);

int bc_printbigchar (int bigchar[], int x, int y, enum colors frontcolor,
                     enum colors backcolor);

int bc_setbigcharpos (int *big, int x, int y, int value);

int bc_getbigcharpos (int *big, int x, int y, int *value);

int bc_bigcharwrite (int fd, int *big, int count);

int bc_bigcharread (int fd, int *big, int need_count, int *count);

int bc_strlen (char *str);

#endif