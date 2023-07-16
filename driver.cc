#include "entry_point.h"

class Driver : public Application {
  public:
    Driver() : Application() {

    }

    ~Driver() {

    }
};

Application* CreateApplication() {
  return new Driver();
}