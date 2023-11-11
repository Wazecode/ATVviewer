#ifndef AVTVEIWER_H
#define AVTVEIWER_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class AVTveiwer; }
QT_END_NAMESPACE

class AVTveiwer : public QMainWindow
{
    Q_OBJECT

public:
    AVTveiwer(QWidget *parent = nullptr);
    ~AVTveiwer();

private slots:
    void on_actionImport_Text_triggered();

    void on_actionImport_Video_triggered();

private:
    Ui::AVTveiwer *ui;
    QString currFile;
};
#endif // AVTVEIWER_H
