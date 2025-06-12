//
//  main.cpp
//  QTextEditor
//
//  Created by Bhavik Ostwal on 09/06/25.
//

#include <QApplication>
#include "EditorUI.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    EditorWidget window;
    window.setWindowTitle("QTextEditor - Basic Text Editor");
    window.show();

    return app.exec();
}

