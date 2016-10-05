#include <GLEW/glew.h>
#include "select.h"

namespace SelectLine{
void calc_select_line(float height, int mouse_x, int mouse_y, vec3& p1, vec3& p2)
{
  GLint    viewport[4];
  GLdouble projection[16];
  GLdouble modelview[16];
  GLdouble vx,vy,vz;
  GLdouble wx,wy,wz;

  glGetIntegerv(GL_VIEWPORT,viewport);
  glGetDoublev(GL_PROJECTION_MATRIX,projection);
  glGetDoublev(GL_MODELVIEW_MATRIX,modelview);

  vx = mouse_x;
  vy = height - mouse_y - 1;

  vz = -1;
  gluUnProject(vx, vy, vz, modelview, projection, viewport, &wx, &wy, &wz);
  p1 = vec3(wx,wy,wz);

  vz = 1;
  gluUnProject(vx, vy, vz, modelview, projection, viewport, &wx, &wy, &wz);
  p2 = vec3(wx,wy,wz);
}

int f1_sgn(const float& k) // - функция, вычисляющая знак числа.
{
  if( k > 0 ) return 1;
  if( k < 0 ) return -1;
  return 0;
}

bool intersect_triangle_line(vec3  v1, // вершины треугольника.
                             vec3  v2,
                             vec3  v3,
                             vec3  n,  // нормаль треугольника.
                             vec3  p1, // первый конец отрезка.
                             vec3  p2, // второй конец отрезка.
                             vec3& pc) // возвращаемая точка пересечения.
{
  float r1 = dot(n,(p1 - v1));
  float r2 = dot(n,(p2 - v1));

  if( f1_sgn(r1) == f1_sgn(r2) ) return false;

  vec3 ip = (p1 + ((p2 - p1) * (-r1 / (r2 - r1))));

  if( dot(cross((v2 - v1),(ip - v1)),n) <= 0) return false;
  if( dot(cross((v3 - v2),(ip - v2)),n) <= 0) return false;
  if( dot(cross((v1 - v3),(ip - v3)),n) <= 0) return false;
  pc = ip; return true;
}
}
