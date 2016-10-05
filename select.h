#include "math/vec3.h"

namespace SelectLine{
void calc_select_line(float height, int mouse_x, int mouse_y, vec3& p1, vec3& p2);
bool intersect_triangle_line(vec3 v1, vec3 v2, vec3 v3, vec3 n, vec3 p1, vec3 p2, vec3& pc);
}
