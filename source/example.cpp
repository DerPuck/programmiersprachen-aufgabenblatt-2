#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "rectangle.hpp"
#include "color.hpp"
#include "vec2.hpp"
#include "circle.hpp"
#include <array>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  Rect rect1_ {};
  Rect rect2_ {{0.6f,0.1f,0.1f}, {100.0f, 100.0f}, {400.0f, 400.0f}};
  Rect rect3_ {{0.6f,0.1f,0.1f}, {400.0f, 400.0f}, {400.0f, 400.0f}};

  std::array<Rect, 3> nrectangles = {rect1_, rect2_, rect3_};

  Circ circ1_ {};
  Circ circ2_ {{0.6f,0.1f,0.1f}, {600.0f,300.0f}, 100};
  Circ circ3_ {{0.6f,0.9f,0.1f}, {400.0f,400.0f}, 150};

  std::array<Circ, 3> ncric = {circ1_, circ2_, circ3_};


  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }
    //first rect test
    Rect rect1_ {};
      rect1_.draw(win, 1.0);
    Rect rect2_ {{0.6f,0.1f,0.1f}, {100.0f, 100.0f}, {400.0f, 400.0f}};
      rect2_.draw(win, 1.0);
    Rect rect3_ {{0.6f,0.1f,0.1f}, {400.0f, 400.0f}, {400.0f, 400.0f}};
      rect3_.draw(win,1.0);

    //first circ test
    Circ circ1_ {};
      circ1_.draw(win, 1.0);
    Circ circ2_ {{0.6f,0.1f,0.1f}, {600.0f,300.0f}, 100};
      circ2_.draw(win, 1.0);
    Circ circ3_ {{0.6f,0.9f,0.1f}, {400.0f,400.0f}, 150};
      circ3_.draw(win,1.0);

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    float nThickness{3.0};
    Vec2 Pos{mouse_position.first, mouse_position.second};
    for (int i = 0; i < nrectangles.size(); ++i)
    {
      if (nrectangles[i].is_inside(Pos)){
        nrectangles[i].draw(win, nThickness);
      }
    }

    for (int i = 0; i < ncric.size(); ++i)
    {
      if (ncric[i].is_inside(Pos)){
        ncric[i].draw(win, nThickness);
      }
    }
    

    win.update();
  }

  return 0;
}
