/**
 * @file 2DCamera.h
 * Created on 03/15/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _2D_CAMERA_H_
#define _2D_CAMERA_H_

#include "Camera.h"

class Camera2D : public Camera {
    public:
        /**
         * Constructor.
         */
        Camera2D();

        /**
         * Destructor.
         */
        virtual ~Camera2D();

        glm::vec3 getPosition() const override;

        glm::mat4 getViewMatrix() const override;

        glm::mat4 getProjectionMatrix() const override;

        void update() override;

        void processKeyboard(Movement direction, float dt) override;

        void processMouseMovement(float dx, float dy) override;

        void processMouseScroll(float dy) override;
}; // end Camera2D class

#endif