#ifndef ROUTER_H
#define ROUTER_H

#include <string>
#include <unordered_map>

#include "GUI/Routing/Route.h"

class Router {
   private:
    std::unordered_map<std::string, Route*> routes;
    std::string currentPath;

    // Default route
    Route* defaultRoute = nullptr;

    // Private constructor to prevent instantiation
    Router() {}

    // Private copy constructor and assignment operator to prevent copying
    Router(const Router&) = delete;
    Router& operator=(const Router&) = delete;

   public:
    bool hasUpdate = true;

    // Public static function to get the instance of the class
    static Router& getInstance();

    // Destructor to clean up routes
    ~Router();

    void addRoute(const std::string& path, Route* route);
    void setDefaultRoute(Route* route);
    Route* getRoute(const std::string& path);
    Route* getCurrentRoute();
    void redirect(const std::string& path);
};

#endif  // ROUTER_H
