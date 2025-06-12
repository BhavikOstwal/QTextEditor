//
//  Editor.h
//  QTextEditor
//
//  Created by Bhavik Ostwal on 09/06/25.
//

#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

class TextEditor {
public:
    TextEditor();

    void insertChar(char c);
    void deleteChar();
    void moveLeft();
    void moveRight();

    const char* getBuffer() const;
    int getCursor() const;

private:
    static const int MAX = 1000;
    char buffer[MAX];
    int length;
    int cursor;
};

#endif
