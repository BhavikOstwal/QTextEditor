//
//  main.cpp
//  QTextEditor
//
//  Created by Bhavik Ostwal on 09/06/25.
//

//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

#include <QApplication>
#include "EditorUI.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    EditorWidget window;
    window.setWindowTitle("Basic Text Editor");
    window.show();

    return app.exec();
}

