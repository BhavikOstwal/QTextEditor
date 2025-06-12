//
//  Editor.cpp
//  QTextEditor
//
//  Created by Bhavik Ostwal on 09/06/25.
//

#include "Editor.h"

TextEditor::TextEditor() : length(0), cursor(0) {
    for (int i = 0; i < MAX; ++i)
        buffer[i] = '\0';
}

void TextEditor::insertChar(char c) {
    if (length >= MAX || cursor > length) return;

    for (int i = length; i > cursor; --i)
        buffer[i] = buffer[i - 1];

    buffer[cursor++] = c;
    ++length;
}

void TextEditor::deleteChar() {
    if (cursor == 0) return;

    for (int i = cursor - 1; i < length - 1; ++i)
        buffer[i] = buffer[i + 1];

    buffer[--length] = '\0';
    --cursor;
}

void TextEditor::moveLeft() {
    if (cursor > 0) --cursor;
}

void TextEditor::moveRight() {
    if (cursor < length) ++cursor;
}

const char* TextEditor::getBuffer() const {
    return buffer;
}

int TextEditor::getCursor() const {
    return cursor;
}
