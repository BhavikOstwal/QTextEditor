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
    QFont font("Monaco", 16);
    painter.setFont(font);
    
    QString text = QString::fromUtf8(editor.getBuffer());
    QStringList lines = text.split('\n');
    int y = 50;
    for (const QString& line : lines) {
        painter.drawText(10, y, line);
        y += painter.fontMetrics().height(); // Move down for next line
    }
    painter.drawText(10, 50, text);

    // Draw cursor
//    if (newLine) {
        
//    }
    QFontMetrics fm(font);
    int cursorX = 10 + fm.horizontalAdvance(text.left(editor.getCursor()));
    if (showCursor) painter.drawLine(cursorX, 30, cursorX, 55);
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
