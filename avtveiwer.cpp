#include "avtveiwer.h"
#include "./ui_avtveiwer.h"

AVTveiwer::AVTveiwer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AVTveiwer)
{
    ui->setupUi(this);
    player = new QMediaPlayer();
    sound = new QAudioOutput();
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

    QUrl path = QFileDialog::getOpenFileUrl(this);
    if(path.isEmpty())
        return;


    currFile = path.fileName();

    player->setSource(path);
    player->setVideoOutput(ui->video);
    player->setAudioOutput(sound);
    sound->setVolume(75);
    player->play();
}




void AVTveiwer::on_actionImport_Audio_triggered()
{
    QUrl path = QFileDialog::getOpenFileUrl(this);
    if(path.isEmpty())
        return;


    currFile = path.fileName();

    player->setSource(path);
    player->setVideoOutput(ui->video);
    player->setAudioOutput(sound);
    sound->setVolume(75);
    player->play();
}

