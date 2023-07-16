#include "application.h"
#include "logger.h"

int main(int argc, char * argv[])
{
//    Application app = Application();
//    app.Run(); 

  Logger::Initialize();

  LOG_WARN("Initialized logger!");
  LOG_ERROR("This is an error message!");

  return 0;
} // end main