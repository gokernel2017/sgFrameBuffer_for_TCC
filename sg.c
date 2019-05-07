//--------------------------------------------------------------------
//
// SUMMER GRAPHIC FB: Linux Frame Buffer Library
//
// <<<<<<<<<<<<<  FOR TCC COMPILER  >>>>>>>>>>>>
//
// FILE:
//   sg.c
//
// COMPILE:
//   tcc sg.c -o sg /usr/lib64/libc.so -Wall
//
// START DATE: 05/05/2019 - 07:00
//
// BY: Francisco - gokernel@hotmail.com
//
//--------------------------------------------------------------------
//
#include <tcclib.h>
#include "sg.h"

static const unsigned char fixed_font[14][764] = {
  "                                   xx                                                                                                                                                                                                                                                                                                                                                                                                                                                                              xx             xxx                                                                                                                                                                                                                                                      ",
  "                                   xx    xxx                                                                                                                                                                                                                                                                                                                                                                                                                                                                      xxxx             xx                                                                      xx       xx                                                                                                                                                                     ",
  "           xx    xx  xx   xx xx   xxxx  xx xx     xxx      xx       xx    xx                                                 xx    xxxx     xx    xxxx    xxxx    xx     xxxxxx    xxx   xxxxxx   xxxx    xxxx                       xx          xx       xxxx   xxxxxx    xx    xxxxx    xxxx   xxxx    xxxxxx  xxxxxx   xxxx   xx  xx   xxxx       xx  xx  xx  xx      xx   xx xx   xx  xxxx   xxxxx    xxxx   xxxxx    xxxx   xxxxxx  xx  xx  xx  xx  xx   xx xx  xx  xx  xx  xxxxxx   xxxx   xx       xxxx   xx  xx             xx           xx                  xx            xxxx          xx        xx       xx   xx      xxxx                                                             xx                                                        xx     xx     xx     xxx   x   ",
  "          xxxx   xx  xx   xx xx  xx  xx xx xx x  xx xx     xx      xx      xx                                                xx   xx  xx   xxx   xx  xx  xx  xx   xx     xx        xx        xx  xx  xx  xx  xx                     xx            xx     xx  xx xx    xx  xxxx   xx  xx  xx  xx  xx xx   xx      xx      xx  xx  xx  xx    xx        xx  xx  xx  xx      xx   xx xx   xx xx  xx  xx  xx  xx  xx  xx  xx  xx  xx    xx    xx  xx  xx  xx  xx   xx xx  xx  xx  xx      xx   xx     xx         xx                                   xx                  xx           xx             xx                      xx        xx                                                             xx                                                       xx      xx      xx   xx xx xx   ",
  "          xxxx   xx  xx  xxxxxxx xx      xxx xx  xx xx     xx      xx      xx     xx xx    xx                               xx    xx xxx xxxxx   xx  xx  xx  xx   xx xx  xx       xx        xx   xx  xx  xx  xx    xxx     xxx     xx              xx    xx  xx xx    xx xx  xx  xx  xx  xx  xx  xx  xx  xx      xx      xx  xx  xx  xx    xx        xx  xx xx   xx      xxx xxx xxx  xx xx  xx  xx  xx  xx  xx  xx  xx  xx        xx    xx  xx  xx  xx  xx   xx  xx x   xx  xx      xx   xx      xx        xx                            xxxx   xxxxx    xxxx    xxxxx   xxxx    xx      xxxxx  xxxxx   xxxx     xxxx   xx  xx    xx    xxxxxx  xxxxx    xxxx   xxxxx    xxxxx  xx  xx   xxxxx  xxxxxx  xx  xx  xx  xx  xx   xx xx  xx  xx  xx  xxxxxx    xx      xx      xx   x   xxx    ",
  "          xxxx            xx xx   xx        xx    xxx             xx        xx     xxx     xx                               xx    xx xxx    xx       xx      xx   xx xx  xx      xxxxx      xx   xxx xx  xx  xx    xxx     xxx    xx     xxxxxx     xx      xx  xx  xxxx xx  xx  xx  xx  xx      xx  xx  xx      xx      xx      xx  xx    xx        xx  xx xx   xx      xx x xx xxxx xx xx  xx  xx  xx  xx  xx  xx  xx   xx       xx    xx  xx  xx  xx  xx x xx   xx    xx  xx     xx    xx      xx        xx                               xx  xx  xx  xx  xx  xx  xx  xx  xx   xx     xx  xx  xx  xx    xx       xx   xx  xx    xx    xx x xx xx  xx  xx  xx  xx  xx  xx  xx  xx xxx  xx       xx     xx  xx  xx  xx  xx x xx xx  xx  xx  xx      xx    xx      xx      xx              ",
  "           xx             xx xx    xx      xx    xx               xx        xx   xxxxxxx xxxxxx          xxxxxx            xx     xx  xx    xx      xx     xxx    xx xx  xxxxx   xx  xx    xx     xxxx   xx  xx                  xx                  xx    xx   xx xx xx xx  xx  xxxxx   xx      xx  xx  xxxxx   xxxxx   xx      xxxxxx    xx        xx  xxxx    xx      xx x xx xx xxxx xx  xx  xxxxx   xx  xx  xxxxx     xx      xx    xx  xx  xx  xx  xx x xx   xx     xxxx     xx     xx       xx       xx                               xx  xx  xx  xx      xx  xx  xx  xx  xxxxxx  xx  xx  xx  xx    xx       xx   xx xx     xx    xx x xx xx  xx  xx  xx  xx  xx  xx  xx  xxx     xx       xx     xx  xx  xx  xx  xx x xx  xxxx   xx  xx     xx    xx       xx       xx             ",
  "           xx             xx xx     xx    xx     xx xxxx          xx        xx     xxx     xx                              xx     xxx xx    xx     xx        xx  xx  xx      xx  xx  xx    xx    xx xxx   xxxxx                   xx     xxxxxx     xx     xx   xx xx xx xxxxxx  xx  xx  xx      xx  xx  xx      xx      xx xxx  xx  xx    xx        xx  xx xx   xx      xx x xx xx  xxx xx  xx  xx      xx  xx  xx xx      xx     xx    xx  xx  xx  xx  xx x xx  x xx     xx     xx      xx       xx       xx                            xxxxx  xx  xx  xx      xx  xx  xxxxxx   xx     xx  xx  xx  xx    xx       xx   xxxx      xx    xx x xx xx  xx  xx  xx  xx  xx  xx  xx  xx       xxxx    xx     xx  xx  xx  xx  xx x xx   xx    xx  xx    xx    xx        xx        xx            ",
  "                         xxxxxxx     xx  xx xxx  xx  xx           xx        xx    xx xx    xx                             xx      xxx xx    xx    xx     xx  xx  xxxxxxx     xx  xx  xx   xx     xx  xx     xx                     xx              xx           xx  xxxx xx  xx  xx  xx  xx  xx  xx  xx  xx      xx      xx  xx  xx  xx    xx    xx  xx  xx xx   xx      xx   xx xx   xx xx  xx  xx      xx  xx  xx  xx      xx    xx    xx  xx  xx  xx   xx xx  xx  xx    xx    xx       xx        xx      xx                           xx  xx  xx  xx  xx      xx  xx  xx       xx     xx  xx  xx  xx    xx       xx   xx xx     xx    xx x xx xx  xx  xx  xx  xx  xx  xx  xx  xx          xx   xx     xx  xx  xx  xx  xx x xx  xxxx   xx  xx   xx      xx       xx       xx             ",
  "           xx             xx xx  xx  xx  x xx xx xx  xx           xx        xx                     xxx             xxx    xx      xx  xx    xx   xx      xx  xx      xx     xx   xx  xx   xx     xx  xx    xx      xxx     xxx      xx            xx       xx   xx       xx  xx  xx  xx  xx  xx  xx xx   xx      xx      xx  xx  xx  xx    xx    xx  xx  xx  xx  xx      xx   xx xx   xx xx  xx  xx      xx  xx  xx  xx  xx  xx    xx    xx  xx   xxxx    xx xx  xx  xx    xx    xx       xx        xx      xx                           xx  xx  xx  xx  xx  xx  xx  xx  xx       xx     xx  xx  xx  xx    xx       xx   xx  xx    xx    xx x xx xx  xx  xx  xx  xx  xx  xx  xx  xx          xx   xx     xx  xx   xxxx    xx xx  xx  xx  xx  xx  xx        xx      xx      xx              ",
  "           xx             xx xx   xxxx     xx xx  xxx xx           xx      xx                      xxx             xxx   xx        xxxx     xx   xxxxxx   xxxx       xx  xxxx     xxxx    xx      xxxx    xxx      xxx     xxx       xx          xx        xx    xxxxxxx xx  xx  xxxxx    xxxx   xxxx    xxxxxx  xx       xxxxx  xx  xx   xxxx    xxxx   xx  xx  xxxxxx  xx   xx xx   xx  xxxx   xx       xxxx   xx  xx   xxxx     xx     xxxx     xx     xx xx  xx  xx    xx    xxxxxx   xx         xx     xx                            xxxxx  xxxxx    xxxx    xxxxx   xxxx    xx      xxxxx  xx  xx  xxxxxx     xx   xx  xx  xxxxxx  xx   xx xx  xx   xxxx   xxxxx    xxxxx  xx      xxxxx     xxxx   xxxxx    xx     xx xx  xx  xx   xxxx   xxxxxx    xx      xx      xx              ",
  "                                   xx       xxx                    xx      xx                       xx                   xx                                                                                                 xx                                                                                                                                                                              xx                                                                            xx         xx     xx                                                                               xx                     xx                                           xx          xx                                                             xx             xx      xx      xx              ",
  "                                   xx                               xx    xx                       xx                                                                                                                      xx                                                                                                                                                                                xx                                                                           xx                xx                                                                               xx                     xx                                           xx          xx                                                            xx               xx     xx     xx               ",
  "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          xxxx            xxxx          xxxxxxxx                                                         xxxxx                   xxxx                                            xx          xx                                                         xxxx                       xx                      ",
};

//--------------------------------------------------------------------
//#########################  ENUM / DEFINE  ##########################
//--------------------------------------------------------------------
//
#define UCHAR unsigned char
#define CHAR_SPACE 32

//--------------------------------------------------------------------
//#############################  STRUCT  #############################
//--------------------------------------------------------------------
//
typedef struct {
    UCHAR   *screen;
    int     smem_len; // fb_fix_info.smem_len
    int     w;        // fb_var_info.xres
    int     h;        // fb_var_info.yres
    int     bpp;      // 8 | 16 | 32
    int     line_length;
    int     accel_flags;
    char    drive_name [20];
    int     fd;       // file id
}FB_DRIVE;

typedef struct {
    UCHAR   *data; // pixels
    int     w;
    int     h;
    int     line_length;
}BMP;

static FB_DRIVE FB;

int sgInit (void) {
    static int init = 0;
    struct sg_var_screeninfo fb_var_info;
    struct sg_fix_screeninfo fb_fix_info;

    if (init == 0) {
        init = 1;
        FB.fd = open ("/dev/fb0", O_RDWR);
        if (FB.fd < 0) {
            printf ("Frame Buffer Not Found ( /dev/fb0 )\n");
            return 0;
        }
        ioctl (FB.fd, FBIOGET_FSCREENINFO, &fb_fix_info);
        ioctl (FB.fd, FBIOGET_VSCREENINFO, &fb_var_info);

        FB.smem_len = fb_fix_info.smem_len;
        FB.w        = fb_var_info.xres;
        FB.h        = fb_var_info.yres;
        FB.bpp      = fb_var_info.bits_per_pixel;
        FB.line_length = fb_fix_info.line_length;
        FB.accel_flags = fb_var_info.accel_flags;

        sprintf (FB.drive_name, "%s", fb_fix_info.id);

        FB.screen = (UCHAR*) mmap (NULL, FB.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, FB.fd, 0);

        printf ("... Starting LIBFB ...\n");
        printf ("    Dive: %s\n", FB.drive_name);
        printf ("       w: %d\n", FB.w);
        printf ("       h: %d\n", FB.h);
        printf ("     bpp: %d\n", FB.bpp);
        printf ("smem_len: %d\n", FB.smem_len);
        printf ("      fd: %d\n", FB.fd);
        printf ("line_length = %d\n", FB.line_length);
        printf (" WIDTH  * 4 = %d\n", (FB.w * 4));
        printf (" HEIGHT * 4 = %d\n", FB.h * 4);
        printf ("accel_flags = %d\n", FB.accel_flags);

        return 1;
    }
    return 0;
}

void sgQuit (void) {
    munmap (FB.screen, FB.smem_len);
    close (FB.fd);
}


//
// draw direct in the screen ... SLOW
//
void hline32 (int x1, int y, int x2, int color) {
    UCHAR *p = (UCHAR*)(FB.screen + (y * FB.line_length + x1 * 4));
    int i;
    for (i = x1; i <= x2; i++) {
        *(unsigned int*)p = color; // Set color
        p += 4;
    }
}
//
// draw direct in the screen ... SLOW
//
void vline32 (int x, int y1, int y2, int color) {
    UCHAR *p = (UCHAR*)(FB.screen + (y1 * FB.line_length + x * 4));
    int i;
    for (i = y1; i <= y2; i++) {
        *(unsigned int *)p = color; // Set color
        p += FB.line_length;
    }
}
//
// draw direct in the screen ... SLOW
//
void hline16 (int x1, int y, int x2, int color) {
    UCHAR *p = (UCHAR*)(FB.screen + (y * FB.line_length + x1 * 2));
    int i;
    for (i = x1; i <= x2; i++) {
        *(unsigned short *)p = color; // Set color
        p += 2;
    }
}
//
// draw direct in the screen ... SLOW
//
void vline16 (int x, int y1, int y2, int color) {
    UCHAR *p = (UCHAR*)(FB.screen + (y1 * FB.line_length + x * 2));
    int i;
    for (i = y1; i <= y2; i++) {
        *(unsigned short *)p = color; // Set color
        p += FB.line_length;
    }
}

int makecol16 (UCHAR r, UCHAR g, UCHAR b) {
    r >>= 3; // 5-bit red
    g >>= 2; // 6-bit green
    b >>= 3; // 5-bit blue
    return b + (g << 5) + (r << (5+6));
}

int makecol32 (UCHAR r, UCHAR g, UCHAR b) {
    return b + (g << 8) + (r << 16);
}

void sgBlit32 (BMP *bmp) {
    int i, y;
    register UCHAR *data = bmp->data;
    for (y = 0; y < bmp->h; y++) {
        UCHAR *p = (UCHAR*)(FB.screen + (y * FB.line_length + 0 * 4));
        for (i = 0; i < bmp->w; i++) {
            //
            // ... copy 4 bytes ... ;)
            //
            *(unsigned int *)( p ) = *(unsigned int *)( data );
            p += 4;
            data += 4;
        }
    }
}

BMP *sgNewBmp32 (int w, int h) {
    BMP *bmp;
    if ((bmp = (BMP*)malloc(sizeof(BMP))) != NULL) {
        int len = w * h * 4;
        if ((bmp->data = (UCHAR*)malloc(len)) != NULL) {
            bmp->w = w;
            bmp->h = h;
            bmp->line_length = w * 4;
            memset (bmp->data, 32, len);
            return bmp;
        }
    }
    return NULL;
}

void hlineBMP32 (BMP *bmp, int x1, int y, int x2, int color) {
    UCHAR *p = (UCHAR*)(bmp->data + (y * bmp->line_length + x1 * 4));
    int i;
    for (i = x1; i <= x2; i++) {
        *(unsigned int *)p = color; // Set color
        p += 4;
    }
}

void vlineBMP32 (BMP *bmp, int x, int y1, int y2, int color) {
    UCHAR *p = (UCHAR*)(bmp->data + (y1 * bmp->line_length + x * 4));
    int i;
    for (i = y1; i <= y2; i++) {
        *(unsigned int *)p = color; // Set color
        p += bmp->line_length;
    }
}

void DrawPixel32 (BMP *bmp, int x, int y, int color) {
//    int location = (x+fb_var_info.xoffset) * (fb_var_info.bits_per_pixel/8) +
//                       (y+fb_var_info.yoffset) * fb_fix_info.line_length;

//    char *pix_pointer = (char *)(fbg->back_buffer + (y * fbg->line_length + x * fbg->components));

//    if (fb_var_info.bits_per_pixel == 32)
//        *((unsigned int*)(FB.screen + location)) = color;
//    *(Uint32 *)(bmp->data + (y * bmp->line_length + x * 4)) = color;
    *(unsigned int *)(bmp->data + y * bmp->line_length + x * 4) = color;
}

// 8 x 13
void DrawChar (BMP *bmp, char ch, int x, int y, int color) {
  if (ch > 32) {
    register unsigned char count;
    register int xx;

    xx = (ch - CHAR_SPACE) * 8;

    if (FB.bpp==32) {
      // insert color
      for (count=0; count < 8; count++) {
        if (fixed_font[ 0][xx] == 'x') { DrawPixel32(bmp, x, y+0,  color); }
        if (fixed_font[ 1][xx] == 'x') { DrawPixel32(bmp, x, y+1,  color); }
        if (fixed_font[ 2][xx] == 'x') { DrawPixel32(bmp, x, y+2,  color); }
        if (fixed_font[ 3][xx] == 'x') { DrawPixel32(bmp, x, y+3,  color); }
        if (fixed_font[ 4][xx] == 'x') { DrawPixel32(bmp, x, y+4,  color); }
        if (fixed_font[ 5][xx] == 'x') { DrawPixel32(bmp, x, y+5,  color); }
        if (fixed_font[ 6][xx] == 'x') { DrawPixel32(bmp, x, y+6,  color); }
        if (fixed_font[ 7][xx] == 'x') { DrawPixel32(bmp, x, y+7,  color); }
        if (fixed_font[ 8][xx] == 'x') { DrawPixel32(bmp, x, y+8,  color); }
        if (fixed_font[ 9][xx] == 'x') { DrawPixel32(bmp, x, y+9,  color); }
        if (fixed_font[10][xx] == 'x') { DrawPixel32(bmp, x, y+10, color); }
        if (fixed_font[11][xx] == 'x') { DrawPixel32(bmp, x, y+11, color); }
        if (fixed_font[12][xx] == 'x') { DrawPixel32(bmp, x, y+12, color); }
        if (fixed_font[13][xx] == 'x') { DrawPixel32(bmp, x, y+13, color); }
        xx++; x++;
      }
      return;
    }
  }
}

void DrawText (BMP *bmp, char *text, int x, int y, int color) {
  while (*text) {
    if (*text > 32)
      DrawChar (bmp, *text, x, y, color);
    text++;
    x += 8;
  }
}

char buf[100];
int fps, count = 15;
long now;

int main (void) {
    int color;
    BMP *b = NULL;

    printf ("Sizeof sg_fix_screeninfo = %d\n", (int)sizeof(struct sg_fix_screeninfo));
    printf ("Sizeof sg_var_screeninfo = %d\n", (int)sizeof(struct sg_var_screeninfo));

    if (sgInit()) {

        if ((b = sgNewBmp32(800,600))) {
            printf ("BITMAP CRIADO 800 X 600\n");
        }

        if (FB.bpp == 16)
            color = makecol16(255,130,30); // orange
        if (FB.bpp == 32)
            color = makecol32(255,130,30);

        if (FB.bpp == 32 && b) {
            sprintf (buf, "%s", "FPS: %d", fps);
            hlineBMP32 (b, 50, 50, 450, color);  // -
            hlineBMP32 (b, 50, 150, 450, color); // -
            vlineBMP32 (b, 50, 50, 150, color);  // |
            vlineBMP32 (b, 450, 50, 150, color); // |
            DrawText (b, "Please Wait 15 SECONDS: ...", 100, 75, color);
            DrawText (b, buf, 100, 100, color);

            for (;;) {

                //
                // each SECOND:
                //
                long t = time (NULL);
                if (t != now) {
                    now = t;
                    if (count < 0)
                        break;
                    sprintf (buf, "FPS: %d | wait %d", fps, count--);
                    fps = 0;

                    // bg: FPS test
                    //---------------------------------------
                    hlineBMP32 (b, 100, 100, 300, 0);  // -
                    hlineBMP32 (b, 100, 101, 300, 0);  // -
                    hlineBMP32 (b, 100, 102, 300, 0);  // -
                    hlineBMP32 (b, 100, 103, 300, 0);  // -
                    hlineBMP32 (b, 100, 104, 300, 0);  // -
                    hlineBMP32 (b, 100, 105, 300, 0);  // -
                    hlineBMP32 (b, 100, 106, 300, 0);  // -
                    hlineBMP32 (b, 100, 107, 300, 0);  // -
                    hlineBMP32 (b, 100, 108, 300, 0);  // -
                    hlineBMP32 (b, 100, 109, 300, 0);  // -
                    hlineBMP32 (b, 100, 110, 300, 0);  // -
                    hlineBMP32 (b, 100, 111, 300, 0);  // -
                    hlineBMP32 (b, 100, 112, 300, 0);  // -
                    hlineBMP32 (b, 100, 113, 300, 0);  // -
                    hlineBMP32 (b, 100, 114, 300, 0);  // -
                    //---------------------------------------

                    DrawText (b, buf, 100, 100, color);

                }// if (t != now)

                fps++;

                //
                // Update/display the BMP
                //
                sgBlit32 (b);

            }// for (;;)

        }// if (FB.bpp == 32 && b)

        sgQuit();
    }

    printf ("Exiting With Sucess:\n");

    return 0;
}


