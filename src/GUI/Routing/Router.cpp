#include "GUI/Routing/Router.h"

Router& Router::getInstance() {
    static Router instance;
    return instance;
}

Router::~Router() {
    for (auto& pair : routes) {
        delete pair.second;
    }

    // Also delete the default route if it's not already in the routes map
    if (defaultRoute && routes.find(currentPath) == routes.end())
        delete defaultRoute;
}

void Router::addRoute(const std::string& path, Route* route) {
    routes[path] = route;
}

void Router::setDefaultRoute(Route* route) { defaultRoute = route; }

Route* Router::getRoute(const std::string& path) {
    auto it = routes.find(path);
    if (it != routes.end()) return it->second;

    return defaultRoute;  // Return the default route if the path is not found
}

Route* Router::getCurrentRoute() { return getRoute(currentPath); }

void Router::redirect(const std::string& path) {
    if (routes.find(path) != routes.end() || path.empty()) {
        currentPath = path;
    } else {
        // Redirect to the default route if the specified path does not exist
        for (const auto& route : routes) {
            if (route.second == defaultRoute) {
                currentPath = route.first;
                break;
            }
        }
    }

    hasUpdate = true;
}
