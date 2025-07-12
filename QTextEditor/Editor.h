//
//  Editor.h
//  QTextEditor
//
//  Created by Bhavik Ostwal on 09/06/25.
//

#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <string>

class TextEditor {
public:
    TextEditor();
    ~TextEditor();

    void insertChar(char c);
    void deleteChar();
    void moveLeft();
    void moveRight();
    void grow();

    std::string getBuffer() const;
    int getCursor() const;

private:
    static const int MAX = 4096;
    char* buffer;
    int K;
    int left;
    int right;
    int length;
    int cursor;
};

#endif
