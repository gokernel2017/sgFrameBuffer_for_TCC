
//-----------------------------------------------
#define FBIOGET_FSCREENINFO	0x4602
#define FBIOGET_VSCREENINFO	0x4600
int open (const char *path, int oflag, ...);
int close (int fd);
int ioctl (int fd, unsigned long request, ...);
void *mmap (void *addr, size_t length, int prot, int flags, int fd, int offset);
int munmap (void *addr, size_t len);

#define O_RDWR      2
#define PROT_READ   1
#define PROT_WRITE  2
#define MAP_SHARED  1
//-----------------------------------------------

struct sg_fix_screeninfo {
    char id[16];			// identification string eg "TT Builtin"
    unsigned long smem_start;	// Start of frame buffer mem
					// (physical address)
    uint32_t smem_len;			// Length of frame buffer mem
    uint32_t type;			// see FB_TYPE_*	
    uint32_t type_aux;			// Interleave for interleaved Planes
    uint32_t visual;			// see FB_VISUAL_*		
    uint16_t xpanstep;			// zero if no hardware panning
    uint16_t ypanstep;			// zero if no hardware panning 
    uint16_t ywrapstep;		// zero if no hardware ywrap   
    uint32_t line_length;		// length of a line in bytes  
    unsigned long mmio_start;	// Start of Memory Mapped I/O  
					// (physical address)
    uint32_t mmio_len;			// Length of Memory Mapped I/O 
    uint32_t accel;			// Indicate to driver which
					//  specific chip/card we have
    uint16_t reserved[3];		// Reserved for future compatibility
};
struct sg_bitfield {
    uint32_t offset;                // beginning of bitfield 
    uint32_t length;                // length of bitfield
    uint32_t msb_right;             // !=0: Most significant bit is right
};
struct sg_var_screeninfo {
    uint32_t xres;                  // visible resolution
    uint32_t yres;
    uint32_t xres_virtual;          // virtual resolution
    uint32_t yres_virtual;
    uint32_t xoffset;               // offset from virtual to visible
    uint32_t yoffset;               // resolution

    uint32_t bits_per_pixel;
    uint32_t grayscale;             // !=0 Graylevels instead of colors

    struct sg_bitfield red;         // bitfield in fb mem if true color,
    struct sg_bitfield green;       // else only length is significant
    struct sg_bitfield blue;
    struct sg_bitfield transp;      // transparency

    uint32_t nonstd;                // !=0 Non standard pixel format

    uint32_t activate;              // see FB_ACTIVATE_x

    uint32_t height;                // height of picture in mm
    uint32_t width;                 // width of picture in mm

    uint32_t accel_flags;           // acceleration flags (hints)

    // Timing: All values in pixclocks, except pixclock (of course)
    uint32_t pixclock;              // pixel clock in ps (pico seconds)
    uint32_t left_margin;           // time from sync to picture
    uint32_t right_margin;          // time from picture to sync
    uint32_t upper_margin;          // time from sync to picture
    uint32_t lower_margin;
    uint32_t hsync_len;             // length of horizontal sync
    uint32_t vsync_len;             // length of vertical sync
    uint32_t sync;                  // see FB_SYNC_x
    uint32_t vmode;                 // see FB_VMODE_x
    uint32_t reserved[6];           // Reserved for future compatibility
};

