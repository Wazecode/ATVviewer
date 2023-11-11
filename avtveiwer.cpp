#include "avtveiwer.h"
#include "./ui_avtveiwer.h"

AVTveiwer::AVTveiwer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AVTveiwer)
{
    ui->setupUi(this);
}

AVTveiwer::~AVTveiwer()
{
    delete ui;
}



void AVTveiwer::on_actionImport_Text_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the file");
    if(filename.isEmpty())
        return;

    QFile file(filename);
    currFile = filename;

    if(!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();

}


void AVTveiwer::on_actionImport_Video_triggered()
{

    QString filename = QFileDialog::getOpenFileName(this, "Open the file");
    if(filename.isEmpty())
        return;

    QUrl path = QFileDialog::getOpenFileUrl(this);

    currFile = filename;

    QMediaPlayer* player = new QMediaPlayer;
    player->setSource(path);
    player->setVideoOutput(ui->video);
    player->play();
}

