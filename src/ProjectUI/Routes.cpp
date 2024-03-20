#include "ProjectUI/Pages.h"

void initializeRoutes() {
    Router& router = Router::getInstance();

    // Create pages
    HomePage* homePage = new HomePage();
    PIDPage* pidPage = new PIDPage();
    SensorsPage* sensorsPage = new SensorsPage();
    SequencesPage* sequencesPage = new SequencesPage();

    // Add routes to the router
    router.addRoute("/", new Route(homePage));
    router.addRoute("/pid", new Route(pidPage));
    router.addRoute("/sensors", new Route(sensorsPage));
    router.addRoute("/sequences", new Route(sequencesPage));

    // Set default route
    router.setDefaultRoute(router.getRoute("/"));
}
