//
//  EditorUI.cpp
//  QTextEditor
//
//  Created by Bhavik Ostwal on 12/06/25.
//

#include "EditorUI.h"
#include <QFontMetrics>
#include <QTimer>

EditorWidget::EditorWidget(QWidget* parent) : QWidget(parent) {
    showCursor = true;
    newLine = false;
    setFocusPolicy(Qt::StrongFocus); // To receive key events
    setMinimumSize(600, 400);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &EditorWidget::switchCursorState);
    timer->start(500);
}

void EditorWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    // QFont font("Monaco", 16);
    // QFont font("JetBrains Mono", 14);
    // QFont font("Menlo", 16);
    QFont font("Fira Code", 16);
    painter.setFont(font);
    
    // Displaying Text Correctly for multi-line text
    QString text = QString::fromUtf8(editor.getBuffer());
    QStringList lines = text.split('\n');
    int y = 50;
    for (const QString& line : lines) {
        painter.drawText(10, y, line);
        y += painter.fontMetrics().height(); // Move down for next line
    }



//------------------ Ignore this Cursor position part -----------------------------------
//    int cursorPosX = editor.getCursor();
//    int cursorPosY = 0;
//
//    int i = 0;
//    bool stoppedAtEnd = false;
//    qDebug() << "Cursor position Before: " << cursorPosX;
//    for(const QChar& c : text) {
//        if (c == '\n') {
//            stoppedAtEnd = true;
//            cursorPosX -= lines[i].size()+1;
//            cursorPosY += painter.fontMetrics().height();
//            i++;
//        }
//        stoppedAtEnd = false;
//    }
//    qDebug() << "Cursor position After: " << cursorPosX;
//
//    if (text.back() == '\n') {
//        cursorPosX--;
//    }
//    QFontMetrics fm(font);
//    int cursorX = 10 + fm.horizontalAdvance(text.left(cursorPosX));
//    if (showCursor) painter.drawLine(cursorX, 30+y, cursorX, 55+y);
//    if (showCursor) painter.drawLine(cursorX, 30+cursorPosY, cursorX, 55+cursorPosY);
//------------------ Ignore this Cursor position part -----------------------------------
    
    
    // Displaying Cursor Correctly for multi-line text
    int cursorIndex = editor.getCursor();
    int x = 10;
    int yc = 50;
    QFontMetrics fm(font);
    int index = 0;
    for (const QString& line : lines)
    {
        if (cursorIndex <= index + line.length()) {
            // Cursor is within this line
            int column = cursorIndex - index;
            int cursorX = x + fm.horizontalAdvance(line.left(column));
            int cursorY = yc;

            if (showCursor) {
                painter.drawLine(cursorX, cursorY - fm.ascent(), cursorX, cursorY + fm.descent());
            }
            break;
        }

        index += line.length() + 1; // +1 for '\n'
        yc += fm.height();
    }
}

void EditorWidget::keyPressEvent(QKeyEvent* event) {
    qDebug() << "Key:" << char(event->key()) << "Modifiers:" << event->modifiers();
    
    if (event->key() == Qt::Key_Left) {
        editor.moveLeft();
    }
    else if (event->key() == Qt::Key_Right) {
        editor.moveRight();
    }
    else if (event->key() == Qt::Key_Backspace) {
        editor.deleteChar();
    }
    else if ((event->modifiers() & Qt::ControlModifier) && event->key() == Qt::Key_Z) {
        
        qDebug() << "CMD+Z Working!";
//        for (char& i : tmp) editor.insertChar(i);
    }
    else if (event->key() == Qt::Key_Return)
    {
        newLine = true;
        qDebug() << "I came here";
        editor.insertChar('\n');
        update();
    }

    else {
        QString text = event->text();
        if (!text.isEmpty() && text[0].isPrint()) {
            editor.insertChar(text[0].toLatin1());
        }
    }
    update(); // Repaint
}


void EditorWidget::switchCursorState() {
    showCursor = !showCursor;
    update();
}
