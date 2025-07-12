//
//  Editor.cpp
//  QTextEditor
//
//  Created by Bhavik Ostwal on 09/06/25.
//

#include "Editor.h"

TextEditor::TextEditor() : K(128), left(0), right(10), length(0), cursor(0) {
    buffer = new char[MAX];
}

TextEditor::~TextEditor() {
    delete [] buffer;
}

void TextEditor::insertChar(char c) {
    if (length >= MAX || cursor > length) return;
    
    if (left == right) {
        grow(); // Gap needs growth :)
    }
    
    if (cursor == length) {
        right++;
    }
    buffer[cursor] = c;
    cursor++;
    left++;
    length++;

}

void TextEditor::deleteChar() {
    if (cursor == 0) return;
    
    left--;
    cursor--;
    length--;
}

void TextEditor::moveLeft() {
    if (cursor > 0) {
        left--;
        right--;
        buffer[right] = buffer[left];
        cursor--;
    }
}

void TextEditor::moveRight() {
    if (cursor < length) {
        buffer[left] = buffer[right];
        left++;
        right++;
        cursor++;
    }
}

void TextEditor::grow() {
    char* grownBuffer = new char[length + K];
    
    for(int i = 0; i < left; i++) {
        grownBuffer[i] = buffer[i];
    }
    
    for(int j = right; j < length; j++) {
        grownBuffer[j+K] = buffer[j];
    }
    
    right += K;
    buffer = grownBuffer;
}

std::string TextEditor::getBuffer() const {
    std::string displayText;
    displayText.reserve(length);
    
    displayText.append(buffer, buffer+left);
    displayText.append(buffer+right, buffer+length+right-left);
    
    return displayText;
}

int TextEditor::getCursor() const {
    return cursor;
}
