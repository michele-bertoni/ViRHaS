#include "controlclass.h"

ControlClass::ControlClass(QObject *parent) : QObject(parent)
{
    cserver = new WebSocketServer(this, Control);
    connect(cserver, SIGNAL(controlEdited(control_t)), this, SLOT(actionSlot(control_t)));

    this->turbo=false;

    this->speedVector = new SpeedVector(this);
    this->arduinoComm = new ArduinoCommunication(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(100);
}


void ControlClass::actionSlot(control_t control){
    //actions:  0 NULL, 1 ACCELERATOR, 2 BRAKE, 3 Ym_MOVEMENT, 4 Yp_MOVEMENT, 5 Xm_MOVEMENT, 6 Xp_MOVEMENT, 7 L_ROTATION, 8 R_ROTATION, 9 TURBO

    Action action;
    action = (Action)control.action;

    float value = control.value;

    switch (action) {
    case Accelerator:
        this->acceleration = value;
        if(this->turbo)
            this->module = this->acceleration+this->deceleration;
        else
            this->module = TURBOMULTIPLIER*(this->acceleration+this->deceleration);
        this->speedVector->setStrafeForward(this->module, this->xDir, this->yDir);
        break;

    case Brake:
        this->deceleration = -value;
        if(this->turbo)
            this->module = this->acceleration+this->deceleration;
        else
            this->module = TURBOMULTIPLIER*(this->acceleration+this->deceleration);
        this->speedVector->setStrafeForward(this->module, this->xDir, this->yDir);
        break;

    case Ym_movement:
        this->ymmovement = value;
        this->yDir = this->ymmovement+this->ypmovement;
        this->speedVector->setStrafeForward(this->module, this->xDir, this->yDir);
        break;

    case Yp_movement:
        this->ypmovement = -value;
        this->yDir = this->ymmovement+this->ypmovement;
        this->speedVector->setStrafeForward(this->module, this->xDir, this->yDir);
        break;

    case Xm_movement:
        this->xmmovement = -value;
        this->xDir = this->xmmovement+this->xpmovement;
        this->speedVector->setStrafeForward(this->module, this->xDir, this->yDir);
        break;

    case Xp_movement:
        this->xpmovement = value;
        this->xDir = this->xmmovement+this->xpmovement;
        this->speedVector->setStrafeForward(this->module, this->xDir, this->yDir);
        break;

    case L_rotation:
        this->mrotation = -value;
        if(!this->turbo){
            this->wRot = TURBOMULTIPLIER*(this->mrotation+this->protation);
        }
        else{
            this->wRot = (this->mrotation+this->protation);
        }
        this->speedVector->setAngular(this->wRot);
        break;

    case R_rotation:
        this->protation = value;
        if(!this->turbo){
            this->wRot = TURBOMULTIPLIER*(this->mrotation+this->protation);
        }
        else{
            this->wRot = (this->mrotation+this->protation);
        }
        this->speedVector->setAngular(this->wRot);
        break;

    case Turbo:
        if((this->turbo==true && value>=0.5) || (this->turbo==false && value < 0.5))
            return;
        if(value>=0.5){
            this->turbo=true;
            this->module/=TURBOMULTIPLIER;
            this->wRot/=TURBOMULTIPLIER;
        }
        else{
            this->turbo=false;
            this->module*=TURBOMULTIPLIER;
            this->wRot*=TURBOMULTIPLIER;
        }

        this->speedVector->setStrafeForward(this->module, this->xDir, this->yDir);
        this->speedVector->setAngular(this->wRot);
        break;

    default:
        break;
    }
    /*std::cout << "Strafe: " << this->speedVector->strafe
              << ", Forward: " << this->speedVector->forward
              << ", Angular: " << this->speedVector->angular
              << "\n";*/
}

void ControlClass::update(){
    arduinoComm->sendToArduino(this->speedVector->toByteArray());
}
