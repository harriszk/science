#include "entry_point.h"

//#include "imgui_system.h"
//#include "editor/menu_bar_panel.h"

class Driver : public Application {
  public:
    Driver() : Application() {
      //imgui_system_.AddPanel(&menu_);

      //AddSystem(&imgui_system_);
    }

    ~Driver() {

    }
  private:
    //ImGuiSystem imgui_system_;
    //MenuBarPanel menu_;
};

Application* CreateApplication() {
  return new Driver();
}