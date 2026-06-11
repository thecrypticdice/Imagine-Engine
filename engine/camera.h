#include "headers/headers.h"
enum CameraMode
{
    CAMERA_CUSTOM = 0,
    CAMERA_FREE = 1,
    CAMERA_ORBITAL = 2,
    CAMERA_FIRST_PERSON = 3,
    CAMERA_THIRD_PERSON = 4
};
enum CameraProjection
{
    CAMERA_PERSPECTIVE = 0,
    CAMERA_ISOMETRIC = 1
};

class 3D_camera
{
    public:
    3D_camera()
    {
        m_camera.position = { 0.0f, 10.0f, 10.0f };
        m_camera.target = { 0.0f, 0.0f, 1.0f };
        m_camera.up = { 0.0f, 1.0f, 0.0f };
        m_camera.fovy = m_fov;
        m_camera.projection = m_projection;
    }
    void set_mode(CameraMode mode)
    {
        m_mode = mode;
    }
    void set_projection(CameraProjection projection)
    {        
        m_projection = projection;
    }
    void set_position(Vector3 position)
    {        m_position = position;
    }
    void set_fov(float fov)
    {        m_fov = fov;
        m_camera.fovy = m_fov;
    }
    Camera get_camera()
    {        return m_camera;
    }
    void update()
    {
        m_camera.position = m_position;
        m_camera.target = m_target;
        UpdateCamera(&m_camera, m_mode);
    }
    private:
    Camera m_camera = { 0 };
    Vector3 m_position;
    Vector3 m_rotation;
    Vector3 m_target;
    CameraMode m_mode = CAMERA_FREE;
    CameraProjection m_projection = CAMERA_PERSPECTIVE;
    float m_fov = 45.0f;
};