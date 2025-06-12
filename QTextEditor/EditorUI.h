//
//  EditorUI.h
//  QTextEditor
//
//  Created by Bhavik Ostwal on 12/06/25.
//

#ifndef EDITORWIDGET_H
#define EDITORWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include "Editor.h"

class EditorWidget : public QWidget {
public:
    EditorWidget(QWidget* parent = nullptr);
    void switchCursorState();

protected:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

private:
    TextEditor editor;
    QTimer* timer;
    bool showCursor;
    bool newLine;
};

#endif
