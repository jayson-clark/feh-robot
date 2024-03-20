#include "ProjectUI/Pages.h"

HomePage::HomePage() : WidgetWithChildren({}, {}) {
    Column* col = new Column();

    auto btnProp = [](std::string path) -> WidgetProperties {
        return {
            .width = 160,
            .height = 120,
            .borderWidth = 1,
            .onPress =
                [path](Widget*, InputEvent) {
                    Router::getInstance().redirect(path);
                },
        };
    };

    Text* pidBtn = new Text("PID", btnProp("/pid"));
    Text* sensorsBtn = new Text("Sensors", btnProp("/sensors"));
    Text* sequencesBtn = new Text("Sequences", btnProp("/sequences"));

    col->children = {new Row({pidBtn, sensorsBtn}), new Row({sequencesBtn})};
    col->layout();

    children = {col};
}
