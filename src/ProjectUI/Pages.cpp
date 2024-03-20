#include "ProjectUI/Pages.h"

// HomePage Constructor
HomePage::HomePage(WidgetProperties prop) : WidgetWithChildren({}, prop) {
    auto* col = new Column();

    col->children.push_back(
        new Text("Page 1",
                 WidgetProperties{
                     .borderWidth = 1,
                     .onPress =
                         [](Widget*, InputEvent) {
                             Router::getInstance().redirect("/page1");
                         },
                 }, ), );

    col->children.push_back(
        new Text("Page 2",
                 WidgetProperties{
                     .borderWidth = 1,
                     .onPress =
                         [](Widget*, InputEvent) {
                             Router::getInstance().redirect("/page2");
                         },
                 }, ), );

    children.push_back(col);
}

// Page1 Constructor
Page1::Page1(WidgetProperties prop) : WidgetWithChildren({}, prop) {
    auto* row = new Row();

    row->children.push_back(
        new Text("Home",
                 WidgetProperties{
                     .borderWidth = 1,
                     .onPress =
                         [](Widget*, InputEvent) {
                             Router::getInstance().redirect("/");
                         },
                 }, ), );

    row->children.push_back(new Text("/page1"));

    children.push_back(row);
}

// Page2 Constructor
Page2::Page2(WidgetProperties prop) : WidgetWithChildren({}, prop) {
    auto* row = new Row();

    row->children.push_back(
        new Text("Home",
                 WidgetProperties{
                     .borderWidth = 1,
                     .onPress =
                         [](Widget*, InputEvent) {
                             Router::getInstance().redirect("/");
                         },
                 }, ), );

    row->children.push_back(new Text("/page2"));

    children.push_back(row);
}

void initializeRoutes() {
    Router& router = Router::getInstance();

    // Create pages
    HomePage* homePage = new HomePage();
    Page1* page1 = new Page1();
    Page2* page2 = new Page2();

    // Add routes to the router
    router.addRoute("/", new Route(homePage));
    router.addRoute("/page1", new Route(page1));
    router.addRoute("/page2", new Route(page2));

    // Set default route
    router.setDefaultRoute(router.getRoute("/"));
}
