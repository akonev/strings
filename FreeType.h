#ifndef FREE_NEHE_H
#define FREE_NEHE_H

#include <ft2build.h>
#include <freetype/freetype.h>
#include <freetype/ftglyph.h>
#include <freetype/ftoutln.h>
#include <freetype/fttrigon.h>
#include <freetype/ttnameid.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include <vector>
#include <string>

#include <stdexcept>

namespace freetype {

using std::vector;
using std::string;

struct font_data {
	float h;
	GLuint * textures;
	GLuint list_base;

	void init(const char * fname, unsigned int h);

	void clean();
};

void print(const font_data &ft_font, float x, float y, const char *fmt, ...) ;
void print2D(const font_data &ft_font, float x, float y, const char *fmt, ...) ;

}

#endif
