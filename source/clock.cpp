#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "rectangle.hpp"
#include "color.hpp"
#include "vec2.hpp"
#include "circle.hpp"
#include "mat2.hpp"
#include <array>


int main(int argc, char* argv[])
{
  Window umrandung{std::make_pair(800, 800)};
  Circ rahmen{{0.1f,0.1f,0.1f}, {400.0f,400.0f}, 300};
  Mat2 rotation{make_rotation_mat2(M_PI/30)};
  Vec2 sec{0.0f, 100.0f};

  while (!umrandung.should_close()) {
    if (umrandung.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      umrandung.close();
    }
    
    auto t = umrandung.get_time();
    int nsec{1};
    int nmin{1};
    int nhour{1};
    float time{0.0f};

    if (t - time > 1)
    {
      sec = rotation * sec;
      time = t;
          
    }
    


    rahmen.draw({umrandung}, 8);

    //umrandung.draw_line(sec);

    umrandung.update();
  }

  return 0;
}
