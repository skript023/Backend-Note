#include "common.hpp"

int main() 
{
    //Set HTTP listener address and port
    
    server.addListener("0.0.0.0", 8080);
    LOG_DEBUG << "Server is running";
    //Load config file
    server.loadConfigFile("./config.json");
    //drogon::app().loadConfigFile("../config.yaml");
    //Run HTTP framework,the method will block in the internal event loop
    server.run();

    LOG_DEBUG << "Server is stopped";
    return 0;
}
