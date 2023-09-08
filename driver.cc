#include "entry_point.h"

#include "imgui_system.h"
#include "editor/menu_bar_panel.h"
#include "editor/scene_panel.h"
#include "editor/asset_panel.h"

class Driver : public Application {
  public:
    Driver() : Application() {
      imgui_system_.AddPanel(new MenuBarPanel());
      imgui_system_.AddPanel(new AssetPanel());
      imgui_system_.AddPanel(new ScenePanel());

      AddSystem(&imgui_system_);
    }

    ~Driver() {

    }
  private:
    ImGuiSystem imgui_system_;
};

Application* CreateApplication() {
  return new Driver();
}