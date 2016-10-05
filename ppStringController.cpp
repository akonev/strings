#include <GLEW/glew.h>
#include <string.h>
#include <stdarg.h>

#include <sys/time.h>
#include <iostream>
#include <math.h>

#include "ppStringController.h"
#include "select.h"
#include "math/math3d.h"
#include "math/mathgl.h"

ppStringController::ppStringController() {
    cur_t = 0.0;
    cur_string_type_ = kUndefined;

    cur_dstr_graphic_wheight = 0;
    cur_str_harm_graphic_num = 1;

    _str_harm_graphic_zoom_x = 1.0f;
    _str_harm_graphic_zoom_y = 1.0f;
    _str_energy_graphic_zoom_x = 1.0f;
    _str_energy_graphic_zoom_y = 1.0f;
    _dstr_energy_graphic_zoom_x = 1.0f;
    _dstr_energy_graphic_zoom_y = 1.0f;
    _hlc_energy_graphic_zoom_x = 1.0f;
    _hlc_energy_graphic_zoom_y = 1.0f;

    string_lenght_ = 0;

    lastX=-1, lastY=-1, coordX=0, coordY=0;
    jump = false, cube_move = false, is_pause = true;
    rot = 90, tilt = -15;
    zoom = 1.0f;
    transX = 0, transY = 0;
    exp_speed = 1.0;

    is_string_init_ = false;

    r_step_ = 30;

    energy_graphic_step = 20;
    Harm_graphic_step = 20;

    aa_level_ = 0;

    block_color_ = vec3(0.3f,0.8f,0.3f);
}

ppStringController::~ppStringController() {

}

unsigned long ppStringController::GetTickCount() {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return (tv.tv_sec*1000+tv.tv_usec/1000);
}
float ppStringController::GetElapsedTime() {
    static int oldTime = GetTickCount();
    int newTime = GetTickCount();
    float result = (newTime - oldTime);
    oldTime = newTime;
    return result;
}
//********************************************************************************************************************
void ppStringController::setOrtho(int WidthWindow, int HeightWindow) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, WidthWindow, HeightWindow);
    glOrtho(0, WidthWindow, HeightWindow, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
}
//********************************************************************************************************************
float ppStringController::getStringLength() {
    return string_lenght_;
}

StringType ppStringController::getCurStringType() {
    return cur_string_type_;
}

void ppStringController::initContext(ContextType type) {
    if(type == kString3dView) {
        initString3dViewContext();
    } else {
        glClearColor(1.0,1.0,1.0,1.0);
        glHint(GL_LINE_SMOOTH_HINT,GL_NICEST);

        graphic_data_[type].font.init("data/calibrib.ttf", 8);
    }
}

void ppStringController::render(ContextType type) {
    switch(type) {
    case kString3dView:
        renderString3dView();
        break;

    case kStrEnergy:
        renderStrEnergyGraphic();
        break;

    case kStrHarm:
        renderStrHarmGraphic();
        break;

    case kDstrEnergy:
        renderDstrEnergyGraphic();
        break;

    case kHlcEnergy:
        renderHlcEnergyGraphic();
        break;
    }
}

void ppStringController::setContextSize(ContextType type, int width, int height) {
    graphic_data_[type].width  = width;
    graphic_data_[type].height = height;
}

void ppStringController::RenderCube(vec3 pos, vec3 size, vec3 color) {
    float length = size.x / 2.0f;
    float width = size.y / 2.0f;
    float height = size.z / 2.0f;

    const float wireframe[] = {
        -length, -width,  -height,
        -length, -width,  height,

        -length, -width,  -height,
        -length, width,  -height,

        -length, -width,  -height,
        length, -width,  -height,

        -length, width,  -height,
        -length, width,  height,

        -length, width,  -height,
        length, width,  -height,

        length, -width,  -height,
        length, width,  -height,

        length, -width,  -height,
        length, -width,  height,

        length, width,  -height,
        length, width,  height,

        length, width,  height,
        length, -width,  height,

        length, width,  height,
        -length, width,  height,

        -length, width,  height,
        -length, -width,  height,

        -length, -width,  height,
        length, -width,  height,
    };

    const float triangleVertices[] = {
        -length, -width,  height,
        length, -width,  height,
        length,  width,  height,
        -length, -width,  height,
        length,  width,  height,
        -length,  width,  height,

        length, -width,  height,
        length, -width, -height,
        length,  width, -height,
        length, -width,  height,
        length,  width, -height,
        length,  width,  height,

        length, -width, -height,
        -length, -width, -height,
        -length,  width, -height,
        length, -width, -height,
        -length,  width, -height,
        length,  width, -height,

        -length, -width, -height,
        -length, -width,  height,
        -length,  width,  height,
        -length, -width, -height,
        -length,  width,  height,
        -length,  width, -height,

        -length,  width,  height,
        length,  width,  height,
        length,  width, -height,
        -length,  width,  height,
        length,  width, -height,
        -length,  width, -height,

        length, -width,  height,
        -length, -width,  height,
        -length, -width, -height,
        length, -width,  height,
        -length, -width, -height,
        length, -width, -height
    };


    const float triangleNormals[] = {
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f,

        -1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,

        0.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
    };

    glNormalPointer( GL_FLOAT, 0, triangleNormals );
    glEnableClientState(GL_NORMAL_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, triangleVertices);
    glEnableClientState(GL_VERTEX_ARRAY);

    glPushMatrix();

    //glTranslatef(pos.x, pos.y, pos.z);
    glMultMatrixf(transpose(GLTranslation(pos)).m);

    glColor3f(color.x, color.y, color.z);
    glEnable(GL_CULL_FACE);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glDisable(GL_CULL_FACE);

    glDisableClientState(GL_NORMAL_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, wireframe);

    /*glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glColor3f(0.0,0.0,0.0);
    glDrawArrays(GL_LINES, 0, 24);
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );*/
    glPopMatrix();

    glDisableClientState(GL_VERTEX_ARRAY);
}

void ppStringController::Draw3DSGrid(float from_x, float to_x, float from_y, float to_y) {
    glShadeModel(GL_SMOOTH);

    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPushMatrix();

    float spec_n = 0.5;

    glColor4f(0.7, 0.7, 0.7, 1.0);
    for(float i = from_y; i < 0; i+=spec_n) {
        glBegin(GL_LINES);
        glVertex3f(from_x, i, 0);
        glVertex3f(to_x, i, 0);
        glEnd();
    }
    for(float i = spec_n; i <= to_y; i+=spec_n) {
        glBegin(GL_LINES);
        glVertex3f(from_x, i, 0);
        glVertex3f(to_x, i, 0);
        glEnd();
    }

    for(float i = from_x; i < 0; i+=spec_n) {
        glBegin(GL_LINES);
        glVertex3f(i, from_y, 0);
        glVertex3f(i, to_y, 0);
        glEnd();
    }
    for(float i = spec_n; i <= to_x; i+=spec_n) {
        glBegin(GL_LINES);
        glVertex3f(i, from_y, 0);
        glVertex3f(i, to_y, 0);
        glEnd();
    }

    glColor4f(0.0, 0.0, 0.0, 1.0);

    glLineWidth(2);

    glBegin(GL_LINES);
    glVertex3f(from_x, 0, 0);
    glVertex3f(to_x, 0, 0);
    glVertex3f(0, from_y, 0);
    glVertex3f(0, to_y, 0);
    glEnd();

    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 0.005f);

    for(float i = from_y+1; i <= to_y-1; i+=1) {
        glBegin(GL_LINES);
        glVertex3f(-0.1f, i, 0.0f);
        glVertex3f(0.1f, i, 0.0f);
        glEnd();
    }

    for(float i = from_x; i <= to_x-1; i+=1) {
        glBegin(GL_LINES);
        glVertex3f(i, -0.1f, 0.0f);
        glVertex3f(i, 0.1f, 0.0f);
        glEnd();
    }

    glLineWidth(1);

    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_BLEND);

    freetype::font_data& font = graphic_data_[kString3dView].font;

    freetype::print(font, to_x-0.8, 0+0.15, "X, m.");
    freetype::print(font, 0+0.1, to_y-0.2, "Y, mm.");

    for(float i = from_y+1; i <= to_y-1; i+=1)
        if(int(i)!=0) {
            freetype::print(font, 0+0.1, i-0.2, "%i", int(i));
        }

    for(float i = from_x; i <= to_x-1; i+=1) {
        freetype::print(font, i+0.1, -0.2, "%i", int(i));
    }

    glPopMatrix();

    glPopMatrix();
}

std::vector<StringVertex> ppStringController::InitStringVertex(const std::vector<string_point>& str_p, bool discr) {
    size_t count = str_p.size();

    float r = 0.03;

    size_t quad_num = 360/r_step_;
    size_t vert_num = quad_num*4;

    std::vector<StringVertex> out(vert_num*(count-1));

    float st;
    float ct;

    size_t k = 0;
    for(size_t i=0; i<vert_num*(count-1); i+=vert_num) {
        float t = 0;
        st = 0;
        ct = r;

        vec2 spec_f1 = vec2(0.0,0.0);
        vec2 spec_f2 = vec2(0.0,0.0);

        if(discr) {
            vec2 perp = vec2(str_p[k+1].x,str_p[k+1].y) - vec2(str_p[k].x,str_p[k].y);
            spec_f1 = normalize(cross(perp));
            spec_f2 = spec_f1;
        } else if( k == count-2) {
            vec2 perp1 = vec2(str_p[k].x,str_p[k].y) - vec2(str_p[k-1].x,str_p[k-1].y);
            vec2 perp2 = vec2(str_p[k+1].x,str_p[k+1].y) - vec2(str_p[k].x,str_p[k].y);
            spec_f1 = normalize(cross(perp1+perp2));
            spec_f2 = spec_f1;
        } else if ( k == 0) {
            vec2 perp2 = vec2(str_p[k+1].x,str_p[k+1].y) - vec2(str_p[k].x,str_p[k].y);
            vec2 perp3 = vec2(str_p[k+2].x,str_p[k+2].y) - vec2(str_p[k+1].x,str_p[k+1].y);

            spec_f2 = normalize(cross(perp2+perp3));
            spec_f1 = spec_f2;
        } else {
            vec2 perp1 = vec2(str_p[k].x,str_p[k].y) - vec2(str_p[k-1].x,str_p[k-1].y);
            vec2 perp2 = vec2(str_p[k+1].x,str_p[k+1].y) - vec2(str_p[k].x,str_p[k].y);
            vec2 perp3 = vec2(str_p[k+2].x,str_p[k+2].y) - vec2(str_p[k+1].x,str_p[k+1].y);

            spec_f1 = normalize(cross(perp1+perp2));
            spec_f2 = normalize(cross(perp2+perp3));
        }

        for(size_t j=0; j<quad_num; j++) {
            out[i+j*4+0].pos = vec3(str_p[k].x  + st*spec_f1.x, str_p[k].y + st*spec_f1.y, ct);
            out[i+j*4+1].pos = vec3(str_p[k+1].x  + st*spec_f2.x, str_p[k+1].y + st*spec_f2.y, ct);

            t += calc::deg_rad(r_step_);
            st = sin(t)*r;
            ct = cos(t)*r;
            out[i+j*4+2].pos = vec3(str_p[k+1].x + st*spec_f2.x, str_p[k+1].y + st*spec_f2.y, ct);
            out[i+j*4+3].pos = vec3(str_p[k].x  + st*spec_f1.x, str_p[k].y + st*spec_f1.y, ct);
        }
        k++;
    }

    vec3 face_normals[vert_num*(count-1)];

    for(size_t i=0; i<vert_num*(count-1); i+=vert_num) {
        for(size_t j=0; j<quad_num; j++) {
            face_normals[i+j*4+0] = normal(out[i+j*4+0].pos,out[i+j*4+1].pos,out[i+j*4+2].pos);
            face_normals[i+j*4+1] = face_normals[i+j*4+0];
            face_normals[i+j*4+2] = face_normals[i+j*4+0];
            face_normals[i+j*4+3] = face_normals[i+j*4+0];
        }
    }

    if(discr) { //someshit
        for(size_t i=0; i<vert_num*(count-1); i+=vert_num) {
            {
                size_t j = 0;
                out[i+j*4+0].normal = (face_normals[i+j*4+0]+face_normals[i+(quad_num-1)*4+3])/2;
                out[i+j*4+1].normal = (face_normals[i+j*4+1]+face_normals[i+(quad_num-1)*4+2])/2;
                out[i+j*4+2].normal = (face_normals[i+j*4+2]+face_normals[i+(j+1)*4+1])/2;
                out[i+j*4+3].normal = (face_normals[i+j*4+3]+face_normals[i+(j+1)*4+0])/2;
            }

            for(size_t j=1; j<quad_num-1; j++) {
                out[i+j*4+0].normal = (face_normals[i+j*4+0]+face_normals[i+(j-1)*4+3])/2;
                out[i+j*4+1].normal = (face_normals[i+j*4+1]+face_normals[i+(j-1)*4+2])/2;
                out[i+j*4+2].normal = (face_normals[i+j*4+2]+face_normals[i+(j+1)*4+1])/2;
                out[i+j*4+3].normal = (face_normals[i+j*4+3]+face_normals[i+(j+1)*4+0])/2;
            }

            {
                size_t j = quad_num-1;
                out[i+j*4+0].normal = (face_normals[i+j*4+0]+face_normals[i+(j-1)*4+3])/2;
                out[i+j*4+1].normal = (face_normals[i+j*4+1]+face_normals[i+(j-1)*4+2])/2;
                out[i+j*4+2].normal = (face_normals[i+j*4+2]+face_normals[i+1])/2;
                out[i+j*4+3].normal = (face_normals[i+j*4+3]+face_normals[i+0])/2;
            }
        }
    } else {
        {
            size_t i = 0;

            {
                size_t j = 0;
                out[i+j*4+0].normal = (face_normals[i+j*4+0]+face_normals[i+(quad_num-1)*4+3])/2;
                out[i+j*4+1].normal = (face_normals[i+j*4+1]+face_normals[i+(quad_num-1)*4+2]+face_normals[(i+vert_num)+j*4+0]+face_normals[(i+vert_num)+(quad_num-1)*4+3])/4;
                out[i+j*4+2].normal = (face_normals[i+j*4+2]+face_normals[i+(j+1)*4+1]+face_normals[(i+vert_num)+j*4+3]+face_normals[(i+vert_num)+(j+1)*4+0])/4;
                out[i+j*4+3].normal = (face_normals[i+j*4+3]+face_normals[i+(j+1)*4+0])/2;
            }

            for(size_t j=1; j<quad_num-1; j++) {
                out[i+j*4+0].normal = (face_normals[i+j*4+0]+face_normals[i+(j-1)*4+3])/2;
                out[i+j*4+1].normal = (face_normals[i+j*4+1]+face_normals[i+(j-1)*4+2]+face_normals[(i+vert_num)+j*4+0]+face_normals[(i+vert_num)+(j-1)*4+3])/4;
                out[i+j*4+2].normal = (face_normals[i+j*4+2]+face_normals[i+(j+1)*4+1]+face_normals[(i+vert_num)+j*4+3]+face_normals[(i+vert_num)+(j+1)*4+0])/4;
                out[i+j*4+3].normal = (face_normals[i+j*4+3]+face_normals[i+(j+1)*4+0])/2;
            }

            {
                size_t j = quad_num-1;
                out[i+j*4+0].normal = (face_normals[i+j*4+0]+face_normals[i+(j-1)*4+3])/2;
                out[i+j*4+1].normal = (face_normals[i+j*4+1]+face_normals[i+(j-1)*4+2]+face_normals[(i+vert_num)+j*4+0]+face_normals[(i+vert_num)+(j-1)*4+3])/4;
                out[i+j*4+2].normal = (face_normals[i+j*4+2]+face_normals[i+1]+face_normals[(i+vert_num)+j*4+3]+face_normals[(i+vert_num)+0])/4;
                out[i+j*4+3].normal = (face_normals[i+j*4+3]+face_normals[i+0])/2;
            }
        }

        {
            size_t i = vert_num*(count-1)-vert_num;

            {
                size_t j = 0;
                out[i+j*4+0].normal = (face_normals[i+j*4+0]+face_normals[i+(quad_num-1)*4+3]+face_normals[(i-vert_num)+j*4+1]+face_normals[(i-vert_num)+(quad_num-1)*4+2])/4;
                out[i+j*4+1].normal = (face_normals[i+j*4+1]+face_normals[i+(quad_num-1)*4+2])/2;
                out[i+j*4+2].normal = (face_normals[i+j*4+2]+face_normals[i+(j+1)*4+1])/2;
                out[i+j*4+3].normal = (face_normals[i+j*4+3]+face_normals[i+(j+1)*4+0]+face_normals[(i-vert_num)+j*4+3]+face_normals[(i-vert_num)+(j+1)*4+1])/4;
            }

            for(size_t j=1; j<quad_num-1; j++) {
                out[i+j*4+0].normal = (face_normals[i+j*4+0]+face_normals[i+(j-1)*4+3]+face_normals[(i-vert_num)+j*4+1]+face_normals[(i-vert_num)+(j-1)*4+2])/4;
                out[i+j*4+1].normal = (face_normals[i+j*4+1]+face_normals[i+(j-1)*4+2])/2;
                out[i+j*4+2].normal = (face_normals[i+j*4+2]+face_normals[i+(j+1)*4+1])/2;
                out[i+j*4+3].normal = (face_normals[i+j*4+3]+face_normals[i+(j+1)*4+0]+face_normals[(i-vert_num)+j*4+3]+face_normals[(i-vert_num)+(j+1)*4+1])/4;
            }

            {
                size_t j = quad_num-1;
                out[i+j*4+0].normal = (face_normals[i+j*4+0]+face_normals[i+(j-1)*4+3]+face_normals[(i-vert_num)+j*4+1]+face_normals[(i-vert_num)+(j-1)*4+2])/4;
                out[i+j*4+1].normal = (face_normals[i+j*4+1]+face_normals[i+(j-1)*4+2])/2;
                out[i+j*4+2].normal = (face_normals[i+j*4+2]+face_normals[i+1])/2;
                out[i+j*4+3].normal = (face_normals[i+j*4+3]+face_normals[i+0]+face_normals[(i-vert_num)+j*4+3]+face_normals[(i-vert_num)+1])/4;
            }
        }

        for(size_t i=vert_num; i<vert_num*(count-1)-vert_num; i+=vert_num) {
            {
                size_t j = 0;
                out[i+j*4+0].normal = (face_normals[i+j*4+0]+face_normals[i+(quad_num-1)*4+3]+face_normals[(i-vert_num)+j*4+1]+face_normals[(i-vert_num)+(quad_num-1)*4+2])/4;
                out[i+j*4+1].normal = (face_normals[i+j*4+1]+face_normals[i+(quad_num-1)*4+2]+face_normals[(i+vert_num)+j*4+0]+face_normals[(i+vert_num)+(quad_num-1)*4+3])/4;
                out[i+j*4+2].normal = (face_normals[i+j*4+2]+face_normals[i+(j+1)*4+1]+face_normals[(i+vert_num)+j*4+3]+face_normals[(i+vert_num)+(j+1)*4+0])/4;
                out[i+j*4+3].normal = (face_normals[i+j*4+3]+face_normals[i+(j+1)*4+0]+face_normals[(i-vert_num)+j*4+3]+face_normals[(i-vert_num)+(j+1)*4+1])/4;
            }

            for(size_t j=1; j<quad_num-1; j++) {
                out[i+j*4+0].normal = (face_normals[i+j*4+0]+face_normals[i+(j-1)*4+3]+face_normals[(i-vert_num)+j*4+1]+face_normals[(i-vert_num)+(j-1)*4+2])/4;
                out[i+j*4+1].normal = (face_normals[i+j*4+1]+face_normals[i+(j-1)*4+2]+face_normals[(i+vert_num)+j*4+0]+face_normals[(i+vert_num)+(j-1)*4+3])/4;
                out[i+j*4+2].normal = (face_normals[i+j*4+2]+face_normals[i+(j+1)*4+1]+face_normals[(i+vert_num)+j*4+3]+face_normals[(i+vert_num)+(j+1)*4+0])/4;
                out[i+j*4+3].normal = (face_normals[i+j*4+3]+face_normals[i+(j+1)*4+0]+face_normals[(i-vert_num)+j*4+3]+face_normals[(i-vert_num)+(j+1)*4+1])/4;
            }

            {
                size_t j = quad_num-1;
                out[i+j*4+0].normal = (face_normals[i+j*4+0]+face_normals[i+(j-1)*4+3]+face_normals[(i-vert_num)+j*4+1]+face_normals[(i-vert_num)+(j-1)*4+2])/4;
                out[i+j*4+1].normal = (face_normals[i+j*4+1]+face_normals[i+(j-1)*4+2]+face_normals[(i+vert_num)+j*4+0]+face_normals[(i+vert_num)+(j-1)*4+3])/4;
                out[i+j*4+2].normal = (face_normals[i+j*4+2]+face_normals[i+1]+face_normals[(i+vert_num)+j*4+3]+face_normals[(i+vert_num)+0])/4;
                out[i+j*4+3].normal = (face_normals[i+j*4+3]+face_normals[i+0]+face_normals[(i-vert_num)+j*4+3]+face_normals[(i-vert_num)+1])/4;
            }
        }
    }

    return out;
}

void ppStringController::RenderString(const std::vector<StringVertex>& vert, vec3 color) {
    glNormalPointer( GL_FLOAT, sizeof(StringVertex), &vert[0].normal );
    glEnableClientState(GL_NORMAL_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(StringVertex), &vert[0].pos);
    glEnableClientState(GL_VERTEX_ARRAY);

    glMaterialfv(GL_FRONT,GL_SPECULAR,vec4(0.8f,0.8f,0.8f,1.0f).v);
    glColor3f(color.x,color.y,color.z);
    glPushMatrix();
    glEnable(GL_CULL_FACE);
    glDrawArrays(GL_QUADS, 0, vert.size());
    glDisable(GL_CULL_FACE);
    glPopMatrix();
    glColor3f(1.0,1.0,1.0);
    glMaterialfv(GL_FRONT,GL_SPECULAR,vec4(0.0f,0.0f,0.0f,1.0f).v);

    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void ppStringController::UpDatePhys() {
    std::vector<string_point> draw_p;

    switch (cur_string_type_) {
    case _str:
        if(test_str.four_yes) {
            test_str.points_place(cur_t);
            test_str.calc_engraph(cur_t);
            test_str.harm_numb = cur_str_harm_graphic_num;
            test_str.point_place_harm(cur_t);
        }

        draw_p.assign(test_str.draw_p, test_str.draw_p+test_str.draw_number);
        string_vertex_ = InitStringVertex(draw_p, false);
        break;

    case _dstr:
        test_dstr.points_place(cur_t);

        draw_p.reserve(test_dstr.draw_number+2);
        draw_p.push_back(string_point(0.0f, 0.0f));
        draw_p.insert(draw_p.end(), test_dstr.draw_p, test_dstr.draw_p+test_dstr.draw_number);
        draw_p.push_back(string_point(test_dstr.l, 0.0f));

        string_vertex_ = InitStringVertex(draw_p, true);
        break;

    case _harmc:
        test_harmc.calc_points(cur_t);

        draw_p.assign(test_harmc.draw_p, test_harmc.draw_p+test_harmc.draw_number);
        string_vertex_ = InitStringVertex(draw_p, false);
        break;

    case _harmd:
        test_harmd.calc_points(cur_t);

        draw_p.assign(test_harmd.draw_p, test_harmd.draw_p+test_harmd.draw_number);
        string_vertex_ = InitStringVertex(draw_p, true);
        break;

    case _hlc:
        test_hlc.calc_points(cur_t);
        test_hlc.calc_engraph(cur_t);

        draw_p.assign(test_hlc.draw_p, test_hlc.draw_p+test_hlc.draw_number);
        string_vertex_ = InitStringVertex(draw_p, false);
        break;

    case _hld:
        test_hld.calc_points(cur_t);

        draw_p.reserve(test_hld.draw_number+2);
        draw_p.push_back(string_point(0.0f, 0.0f));
        draw_p.insert(draw_p.end(), test_hld.draw_p, test_hld.draw_p+test_hld.draw_number);
        draw_p.push_back(string_point(test_hld.l, 0.0f));

        string_vertex_ = InitStringVertex(draw_p, true);
        break;

    case _henv:
        test_henv.calc_points(cur_t);

        draw_p.assign(test_henv.draw_p, test_henv.draw_p+test_henv.draw_number);
        string_vertex_ = InitStringVertex(draw_p, false);
        break;

    default:
        break;
    }

    is_string_init_ = true;
}

void ppStringController::enableAntiAliasing(bool enable) {
    if(enable) {
        aa_level_ = 9; //best?
    } else {
        aa_level_ = 0;
    }
}

bool ppStringController::isAntiAliasingEnabled() {
    return aa_level_ > 0;
}

void ppStringController::renderString3dView() {
    if(!is_pause) {
        cur_t+=GetElapsedTime()*exp_speed/1000.0;
    } else {
        GetElapsedTime();
    }

    int width   = graphic_data_[kString3dView].width;
    int height  = graphic_data_[kString3dView].height;
    freetype::font_data& font = graphic_data_[kString3dView].font;

    UpDatePhys();

    if(isAntiAliasingEnabled()) {
        glClear(GL_ACCUM_BUFFER_BIT);

        size_t in_line = 3;
        size_t shift = 1;

        for(size_t i = 0; i < aa_level_; i++) {
            int x = i % in_line - shift;
            int y = i / in_line - shift;

            vec3 shift(x * 0.5f / width, y * 0.5f / height, 0);
            mat4 aa = GLTranslation(shift);

            glViewport(0, 0, width, height);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();

            //gluPerspective(30.0f, float(WidthWindow)/float(HeightWindow), 1.0f, ViewDistanse);
            mat4 proj = aa * GLPerspective(30.0f, float(width)/float(height), 1.0f, 128.0f);
            glMultMatrixf(transpose(proj).m);

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glEnable(GL_DEPTH_TEST);

            renderStringScene();

            glAccum(i ? GL_ACCUM : GL_LOAD, 1.0f/aa_level_);
        }

        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glAccum(GL_RETURN, 1);
    } else {
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        //gluPerspective(30.0f, float(WidthWindow)/float(HeightWindow), 1.0f, ViewDistanse);
        mat4 proj = GLPerspective(30.0f, float(width)/float(height), 1.0f, 128.0f);
        glMultMatrixf(transpose(proj).m);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glEnable(GL_DEPTH_TEST);

        renderStringScene();
    }

    renderGridScene();

    setOrtho(width, height);

    glPushMatrix();

    glScalef(0.25,0.25,0.25);
    freetype::print2D(font, 2.5, 2.5, "t = %.3f c.", cur_t);

    glPopMatrix();

}

void ppStringController::renderStringScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glLoadIdentity();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    //setPerspective(_string_3dview_width, height, 128);

    glPushMatrix();

    gluLookAt(0, 0, 10,   0, 0, 0,   0, 1, 0);

    glScalef(zoom,zoom,zoom);

    glRotatef(-90+rot, 0,1,0);
    glRotatef(cos((-270+rot)*3.14/180)*tilt, 1,0,0);
    glRotatef(sin((-270+rot)*3.14/180)*tilt, 0,0,1);

    glTranslatef(transX,transY,0);

    float light_pos[4] = {string_lenght_/2.0f,25.0f,2.0f,1.0};
    glLightfv(GL_LIGHT0,GL_POSITION,light_pos);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    //int width   = graphic_data_[kString3dView].width; //unused
    int height  = graphic_data_[kString3dView].height;

    SelectLine::calc_select_line(height, coordX, coordY, p1_, p2_);
    if( is_string_init_ ) {
        switch (cur_string_type_) {
        case _str:
            RenderString(string_vertex_, vec3(1.0,0.0,0.0));
            RenderCube(vec3(0-0.05,0,0),vec3(0.1,1.0,1.0),block_color_);
            RenderCube(vec3(test_str.l+0.05,0,0),vec3(0.1,1.0,1.0),block_color_);

            if(SelectLine::intersect_triangle_line(vec3(test_str.x_c-0.1,test_str.A-0.1,0),
                                                   vec3(test_str.x_c+0.1,test_str.A-0.1,0),
                                                   vec3(test_str.x_c+0.1,test_str.A+0.1,0),
                                                   vec3(0,0,1),
                                                   p1_, p2_, pc_) ||
                    SelectLine::intersect_triangle_line(vec3(test_str.x_c-0.1,test_str.A-0.1,0),
                            vec3(test_str.x_c-0.1,test_str.A+0.1,0),
                            vec3(test_str.x_c+0.1,test_str.A+0.1,0),
                            vec3(0,0,-1),
                            p1_, p2_, pc_))
                RenderCube(vec3(test_str.x_c,test_str.A,0),vec3(0.1,0.1,0.1),vec3(0.7,0.0,0.0));
            else
                RenderCube(vec3(test_str.x_c,test_str.A,0),vec3(0.1,0.1,0.1),vec3(0.0,0.0,0.7));

            break;

        case _dstr:
            RenderString(string_vertex_, vec3(1.0,0.0,0.0));
            RenderCube(vec3(0-0.05,0,0),vec3(0.1,1.0,1.0),block_color_);
            RenderCube(vec3(test_dstr.l+0.05,0,0),vec3(0.1,1.0,1.0),block_color_);

            for(int i=0; i<test_dstr.draw_number; i++) {
                if(SelectLine::intersect_triangle_line(vec3(test_dstr.draw_p[i].x-0.1,test_dstr.draw_p[i].y-0.1,0),
                                                       vec3(test_dstr.draw_p[i].x+0.1,test_dstr.draw_p[i].y-0.1,0),
                                                       vec3(test_dstr.draw_p[i].x+0.1,test_dstr.draw_p[i].y+0.1,0),
                                                       vec3(0,0,1),
                                                       p1_, p2_, pc_) ||
                        SelectLine::intersect_triangle_line(vec3(test_dstr.draw_p[i].x-0.1,test_dstr.draw_p[i].y-0.1,0),
                                vec3(test_dstr.draw_p[i].x-0.1,test_dstr.draw_p[i].y+0.1,0),
                                vec3(test_dstr.draw_p[i].x+0.1,test_dstr.draw_p[i].y+0.1,0),
                                vec3(0,0,-1),
                                p1_, p2_, pc_))
                    RenderCube(vec3(test_dstr.draw_p[i].x,test_dstr.draw_p[i].y,0),vec3(0.1,0.1,0.1),vec3(0.7,0.0,0.0));
                else
                    RenderCube(vec3(test_dstr.draw_p[i].x,test_dstr.draw_p[i].y,0),vec3(0.1,0.1,0.1),vec3(0.0,0.0,0.7));
            }
            break;

        case _harmc:
            RenderString(string_vertex_, vec3(1.0,0.0,0.0));
            break;

        case _harmd:
            RenderString(string_vertex_, vec3(1.0,0.0,0.0));

            for(int i=0; i<test_harmd.draw_number; i++)
                RenderCube(vec3(test_harmd.draw_p[i].x,test_harmd.draw_p[i].y,0),vec3(0.1,0.1,0.1),vec3(0.0,0.0,0.7));
            break;

        case _hlc:
            RenderString(string_vertex_, vec3(1.0,0.0,0.0));
            RenderCube(vec3(0-0.05,0,0),vec3(0.1,1.0,1.0),block_color_);
            RenderCube(vec3(test_hlc.l+0.05,0,0),vec3(0.1,1.0,1.0),block_color_);
            break;

        case _hld:
            RenderString(string_vertex_, vec3(1.0,0.0,0.0));
            RenderCube(vec3(0-0.05,0,0),vec3(0.1,1.0,1.0),block_color_);
            RenderCube(vec3(test_hld.l+0.05,0,0),vec3(0.1,1.0,1.0),block_color_);

            for(int i=0; i<test_hld.draw_number; i++) {
                RenderCube(vec3(test_hld.draw_p[i].x,test_hld.draw_p[i].y,0),vec3(0.1,0.1,0.1),vec3(0.0,0.0,0.7));
            }
            break;

        case _henv:
                RenderString(std::vector<StringVertex>(string_vertex_.begin(), string_vertex_.begin()+string_vertex_.size()/2+360/r_step_*4/2), vec3(0.7 + log(test_henv.p2_)/4.0f,0.0,0.0));
                RenderString(std::vector<StringVertex>(string_vertex_.begin()+string_vertex_.size()/2+360/r_step_*4/2, string_vertex_.end()), vec3(0.7 + log(test_henv.p1_)/4.0f,0.0,0.0));
            break;

        default:
            break;
        }
    }

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glPopMatrix();
}

void ppStringController::renderGridScene() {
    glPushMatrix();

    gluLookAt(0, 0, 10,   0, 0, 0,   0, 1, 0);

    glScalef(zoom,zoom,zoom);

    glRotatef(-90+rot, 0,1,0);
    glRotatef(cos((-270+rot)*3.14/180)*tilt, 1,0,0);
    glRotatef(sin((-270+rot)*3.14/180)*tilt, 0,0,1);

    glTranslatef(transX,transY,0);

    switch (cur_string_type_) {
    case _str:
        Draw3DSGrid(0,test_str.l,-int(test_str.A)-1,int(test_str.A)+1);
        break;

    case _dstr:
        Draw3DSGrid(0,test_dstr.l,-int(test_dstr.A)-1,int(test_dstr.A)+1);
        break;

    case _harmc:
        Draw3DSGrid(test_harmc.sl,test_harmc.fl,-int(test_harmc.A)-1,int(test_harmc.A)+1);
        break;

    case _harmd:
        Draw3DSGrid(test_harmd.sl,test_harmd.fl,-int(test_harmd.A)-1,int(test_harmd.A)+1);
        break;

    case _hlc:
        Draw3DSGrid(0,test_hlc.l,-int(test_hlc.A*2)-1,int(test_hlc.A*2)+1);
        break;

    case _hld:
        Draw3DSGrid(0,test_hld.l,-int(test_hld.A*2)-1,int(test_hld.A*2)+1);
        break;

    case _henv:
        Draw3DSGrid(test_henv.sl,test_henv.fl,-int(test_henv.A)-1,int(test_henv.A)+1);
        break;

    default:
        Draw3DSGrid(-50,50,-50,50);
        break;
    }

    glPopMatrix();
}

void ppStringController::initString(StringType string_type, int k, ...) {
    cur_string_type_ = string_type;

    is_string_init_ = false;

    double param[8];

    va_list p;
    va_start(p,k);
    for(int i=0; i<k; i++) {
        param[i] = va_arg(p,double);
    }
    va_end(p);

    switch(cur_string_type_) {
    case _str:
        test_str.deinit();
        test_str.init(param[0], param[1], param[2], param[3], param[4], param[5]);
        if(param[6] > 0.0) {
            test_str.calc_func(param[5]);
        }
        string_lenght_ = test_str.draw_p[test_str.draw_number-1].x;
        break;

    case _dstr:
        test_dstr.deinit();
        test_dstr.init(param[0], param[1], param[2], param[3], param[4], param[5]);
        string_lenght_ = test_dstr.draw_p[test_dstr.draw_number-1].x;
        break;

    case _harmc:
        test_harmc.deinit();
        test_harmc.init(param[0], param[1], param[2], param[3], param[4], param[5], param[6]);
        string_lenght_ = test_harmc.draw_p[test_harmc.draw_number-1].x;
        break;

    case _harmd:
        test_harmd.deinit();
        test_harmd.init(param[0], param[1], param[2], param[3], param[4], param[5], param[6]);
        string_lenght_ = test_harmd.draw_p[test_harmd.draw_number-1].x;
        break;

    case _hlc:
        test_hlc.deinit();
        test_hlc.init(param[0], param[1], param[2], param[3], param[4], param[5]);
        string_lenght_ = test_hlc.draw_p[test_hlc.draw_number-1].x;
        break;

    case _hld:
        test_hld.deinit();
        test_hld.init(param[0], param[1], param[2], param[3], param[4], param[5]);
        string_lenght_ = test_hld.draw_p[test_hld.draw_number-1].x;
        break;

    case _henv:
        test_henv.deinit();
        test_henv.init(param[0], param[1], param[2], param[3], param[4], param[5], param[6], param[7]);
        string_lenght_ = test_henv.draw_p[test_henv.draw_number-1].x;
        break;

    default:
        break;
    }
    cur_t = 0.0;
}

void ppStringController::initString3dViewContext() {
    glClearColor(0.95f,0.95f,0.95f,0.0f);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_RESCALE_NORMAL);
    glShadeModel(GL_SMOOTH);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    float light_ambient[4] = {0.2, 0.2, 0.2, 1.0};
    float light_diffuse[4] = {1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0,GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE, light_diffuse);

    vec4 specular = vec4(0.8f, 0.8f, 0.8f, 1.0f);
    glLightfv(GL_LIGHT0,GL_SPECULAR,specular.v);
    glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL , GL_SEPARATE_SPECULAR_COLOR);

    glMaterialf(GL_FRONT,GL_SHININESS,16.0f);

    graphic_data_[kString3dView].font.init("data/calibrib.ttf", 64);
}

void ppStringController::renderHlcEnergyGraphic() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    int width  = graphic_data_[kHlcEnergy].width;
    int height = graphic_data_[kHlcEnergy].height;

    freetype::font_data& font = graphic_data_[kHlcEnergy].font;

    setOrtho(width, height);

    float zoom_x = _hlc_energy_graphic_zoom_x*10;
    float zoom_y = _hlc_energy_graphic_zoom_y*1000000;

    enlist_el* tmp_el = test_hlc.energy.begin;

    int k = 0;
    for(int i=10; i<width; i+=energy_graphic_step) {
        glColor3f(0.5,0.5,0.5);
        glBegin(GL_LINES);
        glVertex2f(i,0);
        glVertex2f(i, height);
        glEnd();
        glColor3f(0.0,0.0,0.0);
        if(k==0) {
            freetype::print2D(font, i+2, 1, "%-2.1f", (i-10)/zoom_x);
            k++;
        } else k=0;
    }
    k=0;
    glPushMatrix();
    //glTranslatef(0.0f, _hlc_EnergyGraphic_height-10, 0.0f);
    for(int i=10; i<height; i+=energy_graphic_step) {
        glColor3f(0.5,0.5,0.5);
        glBegin(GL_LINES);
        glVertex2f(0, height-i);
        glVertex2f(width, height-i);
        glEnd();
        glColor3f(0.0,0.0,0.0);
        if(k==0 && i>10) {
            freetype::print2D(font, 11, i-10, "%-2.1e", (i-10)/zoom_y);
            k++;
        } else k=0;
    }
    glPopMatrix();

    glLineWidth(2);
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(0.0,height-10.0);
    glVertex2f(width,height-10.0);

    glVertex2f(10.0,0.0);
    glVertex2f(10.0,height);
    glEnd();
    glPopMatrix();
    glLineWidth(1);

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glLineWidth(2);
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(/*-cur_t*10000/_hlc_EnergyGraphic_width+_hlc_EnergyGraphic_width*/10.0,height-10,0.0);
    while(tmp_el && tmp_el->next) {
        glBegin(GL_LINES);
        glColor3f(1.0,0.0,0.0);
        if(tmp_el)glVertex2f(tmp_el->t*zoom_x,-tmp_el->kin*zoom_y);
        if(tmp_el && tmp_el->next)glVertex2f(tmp_el->next->t*zoom_x,-tmp_el->next->kin*zoom_y);

        glColor3f(0.0,0.0,1.0);
        if(tmp_el)glVertex2f(tmp_el->t*zoom_x,-tmp_el->pot*zoom_y);
        if(tmp_el && tmp_el->next)glVertex2f(tmp_el->next->t*zoom_x,-tmp_el->next->pot*zoom_y);

        glColor3f(0.0,0.7,0.0);
        if(tmp_el)glVertex2f(tmp_el->t*zoom_x,-tmp_el->pot*zoom_y-tmp_el->kin*zoom_y);
        if(tmp_el && tmp_el->next)glVertex2f(tmp_el->next->t*zoom_x,-tmp_el->next->pot*zoom_y-tmp_el->next->kin*zoom_y);

        tmp_el = tmp_el->next;
        glEnd();
    }
    glPopMatrix();
    glLineWidth(1);
    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_BLEND);
}

void ppStringController::renderDstrEnergyGraphic() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    int width  = graphic_data_[kDstrEnergy].width;
    int height = graphic_data_[kDstrEnergy].height;

    freetype::font_data& font = graphic_data_[kDstrEnergy].font;

    setOrtho(width, height);

    float zoom_x = _dstr_energy_graphic_zoom_x*100;
    float zoom_y = _dstr_energy_graphic_zoom_y*10000000.0;

    enlist_el* tmp_el = test_dstr.energy[cur_dstr_graphic_wheight].begin;

    int k = 0;
    for(int i=10; i<width; i+=energy_graphic_step) {
        glColor3f(0.5,0.5,0.5);
        glBegin(GL_LINES);
        glVertex2f(i,0);
        glVertex2f(i,height);
        glEnd();
        glColor3f(0.0,0.0,0.0);
        if(k==0) {
            freetype::print2D(font, i+2, 1, "%-2.1f", (i-10)/zoom_x);
            k++;
        } else k=0;
    }
    k = 0;
    for(int i=10; i<height; i+=energy_graphic_step) {
        glColor3f(0.5,0.5,0.5);
        glBegin(GL_LINES);
        glVertex2f(0,height-i);
        glVertex2f(width,height-i);
        glEnd();
        glColor3f(0.0,0.0,0.0);
        if(k==0 && i>10) {
            freetype::print2D(font, 11, i-10, "%-2.1e", i/zoom_y);
            k++;
        } else k=0;
    }

    glLineWidth(2);
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(0.0,height-10.0);
    glVertex2f(width,height-10.0);

    glVertex2f(10.0,0.0);
    glVertex2f(10.0,height);
    glEnd();
    glPopMatrix();
    glLineWidth(1);

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glLineWidth(2);
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(/*-cur_t*10000/_dstr_EnergyGraphic_width+_dstr_EnergyGraphic_width*/10.0,height-10,0.0);
    while(tmp_el && tmp_el->next) {
        glBegin(GL_LINES);
        glColor3f(1.0,0.0,0.0);
        if(tmp_el)glVertex2f(tmp_el->t*zoom_x,-tmp_el->kin*zoom_y);
        if(tmp_el && tmp_el->next)glVertex2f(tmp_el->next->t*zoom_x,-tmp_el->next->kin*zoom_y);
        glColor3f(0.0,0.0,1.0);
        if(tmp_el)glVertex2f(tmp_el->t*zoom_x,-tmp_el->pot*zoom_y);
        if(tmp_el && tmp_el->next)glVertex2f(tmp_el->next->t*zoom_x,-tmp_el->next->pot*zoom_y);
        tmp_el = tmp_el->next;
        glEnd();
    }
    glPopMatrix();
    glLineWidth(1);
    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_BLEND);
}

void ppStringController::renderStrEnergyGraphic() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    int width  = graphic_data_[kStrEnergy].width;
    int height = graphic_data_[kStrEnergy].height;

    freetype::font_data& font = graphic_data_[kStrEnergy].font;

    setOrtho(width, height);

    float zoom_x = _str_energy_graphic_zoom_x*100;
    float zoom_y = _str_energy_graphic_zoom_y*10000000;

    enlist_el* tmp_el = test_str.energy.begin;

    int k = 0;
    for(int i=10; i<width; i+=energy_graphic_step) {
        glColor3f(0.5,0.5,0.5);
        glBegin(GL_LINES);
        glVertex2f(i,0);
        glVertex2f(i,height);
        glEnd();
        glColor3f(0.0,0.0,0.0);
        if(k==0) {
            freetype::print2D(font, i+2, 1, "%-2.1f", (i-10)/zoom_x);
            k++;
        } else k=0;
    }
    k = 0;
    for(int i=10; i<height; i+=energy_graphic_step) {
        glColor3f(0.5,0.5,0.5);
        glBegin(GL_LINES);
        glVertex2f(0,height-i);
        glVertex2f(width,height-i);
        glEnd();
        glColor3f(0.0,0.0,0.0);
        if(k==0 && i>10) {
            freetype::print2D(font, 11, i-10, "%-2.1e", i/zoom_y);
            k++;
        } else k=0;
    }

    glLineWidth(2);
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(0.0,height-10.0);
    glVertex2f(width,height-10.0);

    glVertex2f(10.0,0.0);
    glVertex2f(10.0,height);
    glEnd();
    glPopMatrix();
    glLineWidth(1);

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glLineWidth(2);
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(/*-cur_t*10000/_str_EnergyGraphic_width+_str_EnergyGraphic_width*/10.0,height-10,0.0);
    while(tmp_el && tmp_el->next) {
        glBegin(GL_LINES);
        glColor3f(1.0,0.0,0.0);
        if(tmp_el)glVertex2f(tmp_el->t*zoom_x,-tmp_el->kin*zoom_y);
        if(tmp_el && tmp_el->next)glVertex2f(tmp_el->next->t*zoom_x,-tmp_el->next->kin*zoom_y);

        glColor3f(0.0,0.0,1.0);
        if(tmp_el)glVertex2f(tmp_el->t*zoom_x,-tmp_el->pot*zoom_y);
        if(tmp_el && tmp_el->next)glVertex2f(tmp_el->next->t*zoom_x,-tmp_el->next->pot*zoom_y);

        glColor3f(0.0,0.7,0.0);
        if(tmp_el)glVertex2f(tmp_el->t*zoom_x,-tmp_el->pot*zoom_y-tmp_el->kin*zoom_y);
        if(tmp_el && tmp_el->next)glVertex2f(tmp_el->next->t*zoom_x,-tmp_el->next->pot*zoom_y-tmp_el->next->kin*zoom_y);

        tmp_el = tmp_el->next;
        glEnd();
    }
    glPopMatrix();
    glLineWidth(1);
    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_BLEND);
}

void ppStringController::renderStrHarmGraphic() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    int width  = graphic_data_[kStrHarm].width;
    int height = graphic_data_[kStrHarm].height;

    freetype::font_data& font = graphic_data_[kStrHarm].font;

    setOrtho(width, height);

    float zoom_x = _str_harm_graphic_zoom_x*10;
    float zoom_y = _str_harm_graphic_zoom_y*100000.0;

    int k=0;
    for(int i=0; i<width; i+=Harm_graphic_step) {
        glColor3f(0.5,0.5,0.5);
        glBegin(GL_LINES);
        glVertex2f(i,0);
        glVertex2f(i,height);
        glEnd();
        glColor3f(0.0,0.0,0.0);
        if(k==0) {
            freetype::print2D(font, i+2, (height>>1) - 10, "%-2.1f", i/zoom_x);
            k++;
        } else k=0;
    }

    glPushMatrix();
    glTranslatef(0.0f, height>>1, 0.0f);
    for(int i=0; i<height>>1; i+=Harm_graphic_step) {
        glColor3f(0.5,0.5,0.5);
        glBegin(GL_LINES);
        glVertex2f(0,i);
        glVertex2f(width,i);
        glVertex2f(0,-i);
        glVertex2f(width,-i);
        glEnd();
    }
    glPopMatrix();

    k=0;
    glPushMatrix();
    glTranslatef(0.0f, height>>1, 0.0f);
    for(int i=Harm_graphic_step*2; i<height; i+=Harm_graphic_step) {
        glColor3f(0.0,0.0,0.0);
        if(k==0) {
            freetype::print2D(font, 2, i-10, "%2.1e", i/zoom_y);
            freetype::print2D(font, 2, -i-10, "-%2.1e", i/zoom_y);
            k++;
        } else k=0;
    }
    glPopMatrix();

    glLineWidth(2);
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f,height>>1);
    glVertex2f(width,height>>1);

    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,height);
    glEnd();
    glPopMatrix();
    glLineWidth(1);

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glLineWidth(2);
    glPushMatrix();
    glTranslatef(0.0f, height>>1, 0.0f);
    glColor3f(1.0f,0.0f,0.0f);
    for(int i=0; i<test_str.harmn-1; i++) {
        glBegin(GL_LINES);
        glVertex2f(test_str.harm[i].x*zoom_x,-test_str.harm[i].y*zoom_y);
        glVertex2f(test_str.harm[i+1].x*zoom_x,-test_str.harm[i+1].y*zoom_y);
        glEnd();
    }
    glPopMatrix();
    glLineWidth(1);
    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_BLEND);
}
