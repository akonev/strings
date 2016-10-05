#pragma once

#include <vector>
#include <memory>
#include <map>

#include "math/vec3.h"

#include "phys_src/oscillating_string_cont.h"
#include "phys_src/oscillating_string_discr.h"
#include "phys_src/harm_ph_string.h"
#include "phys_src/lim_harm_ph_string.h"
#include "phys_src/harm_ph_env_border.h"

#include "FreeType.h"

struct StringVertex {
    vec3 pos;
    vec3 normal;
};

enum StringType {
    kUndefined = -1,
    _str = 0,
    _dstr = 1,
    _harmc = 2,
    _harmd = 3,
    _hlc = 4,
    _hld = 5,
    _henv = 6
};

enum ContextType {
    kString3dView = 0,
    kStrEnergy    = 1,
    kStrHarm      = 2,
    kDstrEnergy   = 3,
    kHlcEnergy    = 4
};

struct ContextData {
    freetype::font_data font;
    int                 width;
    int                 height;
    //vec3                zoom; // TODO

    ContextData() {
        width  = 640;
        height = 480;
    }
};

class ppStringController {
public:
    ppStringController();
    ~ppStringController();

    void initString(StringType string_type, int k, ...);

    void enableAntiAliasing(bool enable);
    bool isAntiAliasingEnabled();

    void initContext(ContextType type);
    void render(ContextType type);
    void setContextSize(ContextType type, int width, int height);

    float getStringLength();
    StringType getCurStringType();

    vec3 p1_, p2_, pc_;

    int lastX, lastY, coordX, coordY;
    bool jump, cube_move, is_pause;
    float rot, tilt;
    float zoom;
    float transX, transY;
    float exp_speed;
    float cur_t;

    osc_string_cont  test_str;
    osc_string_discr test_dstr;

    int cur_dstr_graphic_wheight;
    int cur_str_harm_graphic_num;

    float _str_harm_graphic_zoom_x;
    float _str_harm_graphic_zoom_y;
    float _str_energy_graphic_zoom_x;
    float _str_energy_graphic_zoom_y;
    float _dstr_energy_graphic_zoom_x;
    float _dstr_energy_graphic_zoom_y;
    float _hlc_energy_graphic_zoom_x;
    float _hlc_energy_graphic_zoom_y;

private:
    StringType cur_string_type_;

    std::map<ContextType, ContextData> graphic_data_;

    harm_ph_string_cont     test_harmc;
    harm_ph_string_discr    test_harmd;
    lhps_discr              test_hld;
    lhps_cont               test_hlc;
    str_in_two_envs         test_henv;

    int energy_graphic_step;
    int Harm_graphic_step;

    size_t aa_level_;

    float string_lenght_;

    std::vector<StringVertex> string_vertex_;

    bool is_string_init_;
    float r_step_;

    vec3 block_color_;

    ///**!GRAPHICS!**///
    void renderString3dView();
    void initString3dViewContext();

    void renderHlcEnergyGraphic();

    void renderDstrEnergyGraphic();

    void renderStrEnergyGraphic();

    void renderStrHarmGraphic();
    ///**~GRAPHICS~**///

    std::vector<StringVertex> InitStringVertex(const std::vector<string_point>& str_p, bool discr);
    unsigned long GetTickCount();
    float GetElapsedTime();
    void UpDatePhys();

    void RenderString(const std::vector<StringVertex>& vert, vec3 color);
    void renderStringScene();
    void renderGridScene();

    void setOrtho(int WidthWindow, int HeightWindow);
    void RenderCube(vec3 pos, vec3 size, vec3 color);
    void Draw3DSGrid(float from_x, float to_x, float from_y, float to_y);
};

extern std::auto_ptr<ppStringController> pp_string_t;
