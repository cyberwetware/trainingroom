
void set_graphic_buffer(int w, int h, void *out)
{
	unsigned char r = 30;
	unsigned char g = 30;
	unsigned char b = 30;
	unsigned char a = 0;

	unsigned int *p = (unsigned int *)out;

	int i, j;
	for(j=0; j<h; j++) {
		for(i=0; i<w; i++) {
			p[j * w + i] = 0xA080C060;
//			*p = 0x88888888;
//			p++;
//			p[j * w + i] = (r + 8) << 24
//				|| (g + 12) << 16
//				|| (b + 16) << 8
//				|| a;
		}
	}
}
	
