#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->gamepadmonitor = new GamepadMonitor(this);
    this->button_class = new ButtonsClass(this, ui);
    this->gpkey = new GamepadKeyClass(this, ui);
    this->screen_init = new ScreenInitialization(this, ui, button_class, gpkey);
    this->settings = new SettingsClass(this, ui, button_class, gpkey);
    this->screen_manipulation = new ScreenManipulation(this, ui, settings);
    this->robotError = new ErrorClass(this, ui, settings);
    this->vibrator = new Vibrator(this);

    this->screen_init->setSettings(this->settings);
    this->screen_init->initButtons();
    this->settings->loadDefSetts();
    this->settings->confirmSettings();

    this->controls_transmission = new WebSocketClient(this, Control);
    this->camera1 = new WebSocketClient(this, Camera_1);
    camera2 = new WebSocketClient(this, Camera_2);

    connect(gamepadmonitor, SIGNAL(gamepadKeyPressed(int, double)), gpkey, SLOT(gamepadKeyGrabber(int, double)));
    connect(gpkey, SIGNAL(playKeyPressed(int,double)), this, SLOT(onPlayKeyPressed(int,double)));
    connect(button_class, SIGNAL(previewRequest()), screen_manipulation, SLOT(preview()));
    connect(button_class, SIGNAL(connessionRequest()), this, SLOT(playGame()));
    connect(button_class, SIGNAL(disconnessionRequest()), this, SLOT(stopGame()));
#ifdef Q_OS_WIN
    connect(button_class, SIGNAL(windowsError()), this, SLOT(showWindowsError()));
#endif

    connect(controls_transmission, SIGNAL(connectionStatusChanged(State)), this, SLOT(onControlConnessionSwitch(State)));
    connect(controls_transmission, SIGNAL(newError(QAbstractSocket::SocketError,QString)), robotError, SLOT(onNewError(QAbstractSocket::SocketError,QString)));
    connect(controls_transmission, SIGNAL(newEvent(int)), this, SLOT(onNewEvent(int)));
    connect(camera1, SIGNAL(connectionStatusChanged(State)), this, SLOT(onCamera1ConnessionSwitch(State)));
    connect(camera1, SIGNAL(newError(QAbstractSocket::SocketError,QString)), robotError, SLOT(onNewError(QAbstractSocket::SocketError,QString)));
    connect(camera2, SIGNAL(connectionStatusChanged(State)), this, SLOT(onCamera2ConnessionSwitch(State)));
    connect(camera2, SIGNAL(newError(QAbstractSocket::SocketError,QString)), robotError, SLOT(onNewError(QAbstractSocket::SocketError,QString)));

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::onPlayKeyPressed(int key_id, double value){
    int action=settings->action_button[key_id];
    if(value<0.10 && value>-0.10){
        if(action)
            controls_transmission->sendControls(action, 0);
        return;
    }
    if(action){
        controls_transmission->sendControls(action, value);
    }
    return;
}

void MainWindow::playGame()
{
    //this->vibrator->vibrate(2000);

    this->startControl();
    this->startCamera1();
    this->startCamera2();
    screen_manipulation->setStreamingScreen();
    robotError->hideError();
    button_class->toGame();
}

void MainWindow::stopGame()
{
    this->stopControl();
    this->stopCamera1();
    this->stopCamera2();

    button_class->toMainMenu();
    ui->canvas1->update();
    ui->canvas2->update();

}

void MainWindow::onCamera1ConnessionSwitch(State status)
{
    if(status == Connected){
        std::cout << "Camera 1 connected\n";
        camera1->sendSettings(settings->getVidSett());
    }
    else if(status == Disconnected){
        robotError->showError("Camera 1 disconnected");
    }
}

void MainWindow::onCamera2ConnessionSwitch(State status)
{
    if(status == Connected){
        std::cout << "Camera 2 connected\n";
        camera2->sendSettings(settings->getVidSett());
    }
    else if(status == Disconnected){
        robotError->showError("Camera 2 disconnected");
    }
}

void MainWindow::onControlConnessionSwitch(State status)
{
    if(status == Connected){
        std::cout << "Control connected\n";
    }
    else if(status == Disconnected){
        robotError->showError("Controls disconnected");
    }
}

void MainWindow::showWindowsError()
{
    robotError->showError("You are using a buggy os (Windows): please press CTRL+ALT+DEL and then Cancel to update screen.\nTo fix this bug (Windows) permanently, please visit https://www.ubuntu.com/download");
    ui->X_pushButton->setVisible(false);
}

void MainWindow::onNewEvent(int eventType)
{
    switch(eventType){
    case 0: //NULL
        break;

    case 1: //TURBO_ON
        this->vibrator->vibrate(500);
        break;

    case 2: //TURBO_OFF
        this->vibrator->vibrate(500);
        break;

    case 3: //OBSTACLE
        this->vibrator->setVibrationStatus(true);
        break;

    case 4: //OBSTACLE_OFF
        this->vibrator->setVibrationStatus(false);
        break;
    }
}

void MainWindow::startCamera1(){
    if(!settings->sett.lcam)
        return;

    if(!this->settings->sett.invcanv)
        connect(camera1, SIGNAL(newFrame(QByteArray*)), screen_manipulation, SLOT(printImageOnCanvas1(QByteArray*)));
    else
        connect(camera1, SIGNAL(newFrame(QByteArray*)), screen_manipulation, SLOT(printImageOnCanvas2(QByteArray*)));

    camera1->connectSocket();
}

void MainWindow::startCamera2(){
    if(!settings->sett.rcam)
        return;

    if(this->settings->sett.invcanv)
        connect(camera2, SIGNAL(newFrame(QByteArray*)), screen_manipulation, SLOT(printImageOnCanvas1(QByteArray*)));
    else
        connect(camera2, SIGNAL(newFrame(QByteArray*)), screen_manipulation, SLOT(printImageOnCanvas2(QByteArray*)));

    camera2->connectSocket();
}

void MainWindow::startControl()
{
    if(!settings->sett.gamepad)
        return;

    controls_transmission->connectSocket();
}

void MainWindow::stopCamera1()
{
    if(!settings->sett.lcam)
        return;

    if(!this->settings->sett.invcanv)
        disconnect(camera1, SIGNAL(newFrame(QByteArray*)), screen_manipulation, SLOT(printImageOnCanvas1(QByteArray*)));
    else
        disconnect(camera1, SIGNAL(newFrame(QByteArray*)), screen_manipulation, SLOT(printImageOnCanvas2(QByteArray*)));

    this->camera1->disconnectSocket();

}

void MainWindow::stopCamera2(){
    if(!settings->sett.rcam)
        return;

    if(this->settings->sett.invcanv)
        disconnect(camera2, SIGNAL(newFrame(QByteArray*)), screen_manipulation, SLOT(printImageOnCanvas1(QByteArray*)));
    else
        disconnect(camera2, SIGNAL(newFrame(QByteArray*)), screen_manipulation, SLOT(printImageOnCanvas2(QByteArray*)));

    camera2->disconnectSocket();
}

void MainWindow::stopControl()
{
    if(!settings->sett.gamepad)
        return;

    controls_transmission->disconnectSocket();
}
