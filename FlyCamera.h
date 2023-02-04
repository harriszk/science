/**
 * @file FlyCamera.h
 * Created on 02/02/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _FLY_CAMERA_H_
#define _FLY_CAMERA_H_

#include "Camera.h"

class FlyCamera : public Camera {
    public:
    /**
     * Constructor.
     * 
     * @param[in] position The initial position of the camera.
     * @param[in] direction The initial direction the camera is facing.
     */
    FlyCamera(const glm::vec3 &position, const glm::vec3 &direction);

    /**
     * Destructor.
     */
    virtual ~FlyCamera();

    glm::vec3 getPosition() const override;

    glm::mat4 getViewMatrix() const override;

    glm::mat4 getProjectionMatrix() const override;

    void update() override;

    void processKeyboard(Movement direction, float dt) override;

    void processMouseMovement(float dx, float dy) override;

    void processMouseScroll(float dy) override;
}; // end FlyCamera class

#endif