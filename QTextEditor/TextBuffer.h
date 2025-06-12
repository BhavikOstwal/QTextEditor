//
//  TextBuffer.h
//  QTextEditor
//
//  Created by Bhavik Ostwal on 09/06/25.
//

#ifndef TEXTBUFFER_H
#define TEXTBUFFER_H
#include <string>

class TextBuffer {
public:
    TextBuffer();
    explicit TextBuffer(const std::string& initialText);

    void insertChar(size_t pos, char c);
    void deleteChar(size_t pos);
    char getChar(size_t pos) const;
    size_t length() const;
    std::string getContent() const;

    void loadFromFile(const std::string& path);
    void saveToFile(const std::string& path) const;

private:
    std::string buffer; // will later be replaced with GapBuffer logic
};

#endif
