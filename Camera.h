/**
 * @file Camera.h
 * Created on 01/29/2023
 * 
 * This class represents a virtual camera in 3D space. It determines the view and projection 
 * matrices used to render the scene. The view matrix transforms world space to camera space 
 * and the projection matrix transforms camera space to clip space. See: https://learnopengl.com/Getting-started/Camera
 * for more info. It also provides methods for manipulating the camera's position and orientation, 
 * such as moving forward, backward, strafing, etc.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _CAMERA_H_
#define _CAMERA_H_

class Camera {
    public:
        Camera();

        ~Camera();
    private:

}; // end Camera class

#endif