#pragma once

#include <QApplication>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QWidget>

QGroupBox* createSection(const QString& title);
QGridLayout* initLayout(QWidget& window);
void initWindowSettings(QWidget& window);
