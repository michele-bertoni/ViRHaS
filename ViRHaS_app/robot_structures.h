#ifndef ROBOT_STRUCTURES_H
#define ROBOT_STRUCTURES_H


typedef struct control_s{
    int action;
    float value;
} control_t;

typedef struct vidsett_s{
    int res_w, res_h, fps;
    bool lcam, rcam;

} vidsett_t;


#endif // ROBOT_STRUCTURES_H
