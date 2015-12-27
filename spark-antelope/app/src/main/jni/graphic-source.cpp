
/* Fill true-color graphic buffer */
void void fill_truecolor_rgba_buffer(int w, int h, void *out)
{

	unsigned int *p = (unsigned int *)out;

	int i, j;
	for(j=0; j<h; j++) {
		for(i=0; i<w; i++) {
			p[j * w + i] = 0xA080C000;
		}
	}
}
	
