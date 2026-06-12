

#include "headers/headers.h"

class 3D_view_port
{
    public:
        3D_view_port()
        {
            m_camera.position = { 0.0f, 10.0f, 10.0f };
            m_camera.target = { 0.0f, 0.0f, 0.0f };
            m_camera.up = { 0.0f, 1.0f, 0.0f };
            m_camera.fovy = 45.0f;
            m_camera.type = CAMERA_PERSPECTIVE;
        }
        ~3D_view_port()
        {
        }
        void left_bar()
        {
            GuiGroupBox(m_left_bar_area, "Scene");
            GuiLabel((Rectangle){m_left_bar_area.x + 8, m_left_bar_area.y + 24, m_left_bar_area.width - 16, 20}, "Tools");
            GuiLabel((Rectangle){m_left_bar_area.x + 8, m_left_bar_area.y + 48, m_left_bar_area.width - 16, 20}, "Assets");
            GuiButton((Rectangle){m_left_bar_area.x + 8, m_left_bar_area.y + 72, m_left_bar_area.width - 16, 24}, "Add Object");
        }
        void right_bar()
        {
            GuiGroupBox(m_right_bar_area, "Properties");
            GuiLabel((Rectangle){m_right_bar_area.x + 8, m_right_bar_area.y + 24, m_right_bar_area.width - 16, 20}, "Inspector");
            GuiLabel((Rectangle){m_right_bar_area.x + 8, m_right_bar_area.y + 48, m_right_bar_area.width - 16, 20}, "Details");
            if(m_selected_object != nullptr)
            {   
                GuiValueBoxFloat((Rectangle){m_right_bar_area.x + 8, m_right_bar_area.y + 72, m_right_bar_area.width - 16, 24}, "Position X", std::to_string(m_selected_object->position.x).c_str(), &m_selected_object->position.x, true);
                GuiValueBoxFloat((Rectangle){m_right_bar_area.x + 8, m_right_bar_area.y + 104, m_right_bar_area.width - 16, 24}, "Position Y", std::to_string(m_selected_object->position.y).c_str(), &m_selected_object->position.y, true);
                GuiValueBoxFloat((Rectangle){m_right_bar_area.x + 8, m_right_bar_area.y + 136, m_right_bar_area.width - 16, 24}, "Position Z", std::to_string(m_selected_object->position.z).c_str(), &m_selected_object->position.z, true);
                GuiValueBoxFloat((Rectangle){m_right_bar_area.x + 8, m_right_bar_area.y + 168, m_right_bar_area.width - 16, 24}, "Rotation X", std::to_string(m_selected_object->rotation.x).c_str(), &m_selected_object->rotation.x, true);
                GuiValueBoxFloat((Rectangle){m_right_bar_area.x + 8, m_right_bar_area.y + 200, m_right_bar_area.width - 16, 24}, "Rotation Y", std::to_string(m_selected_object->rotation.y).c_str(), &m_selected_object->rotation.y, true);
                GuiValueBoxFloat((Rectangle){m_right_bar_area.x + 8, m_right_bar_area.y + 232, m_right_bar_area.width - 16, 24}, "Rotation Z", std::to_string(m_selected_object->rotation.z).c_str(), &m_selected_object->rotation.z, true);
                GuiValueBoxFloat((Rectangle){m_right_bar_area.x + 8, m_right_bar_area.y + 264, m_right_bar_area.width - 16, 24}, "Scale X", std::to_string(m_selected_object->scale.x).c_str(), &m_selected_object->scale.x, true);
                GuiValueBoxFloat((Rectangle){m_right_bar_area.x + 8, m_right_bar_area.y + 296, m_right_bar_area.width - 16, 24}, "Scale Y", std::to_string(m_selected_object->scale.y).c_str(), &m_selected_object->scale.y, true);
                GuiValueBoxFloat((Rectangle){m_right_bar_area.x + 8, m_right_bar_area.y + 328, m_right_bar_area.width - 16, 24}, "Scale Z", std::to_string(m_selected_object->scale.z).c_str(), &m_selected_object->scale.z, true);
            }
        }
        void top_bar()
        {
            GuiGroupBox(m_top_bar_area, "Workspace");
            GuiButton((Rectangle){m_top_bar_area.x + 8, m_top_bar_area.y + 24, 80, 24}, "Save");
            GuiButton((Rectangle){m_top_bar_area.x + 96, m_top_bar_area.y + 24, 80, 24}, "Load");
        }
        void bottom_bar()
        {
            GuiGroupBox(m_bottom_bar_area, "Status");
            GuiStatusBar((Rectangle){m_bottom_bar_area.x + 8, m_bottom_bar_area.y + 10, m_bottom_bar_area.width - 16, 24}, "Ready");
        }
        void render_area()
        {
            GuiGroupBox(m_draw_area, "3D Viewport");
            GuiLabel((Rectangle){m_draw_area.x + 10, m_draw_area.y + 28, m_draw_area.width - 20, 20}, "Render area");
            BeginScissorMode(m_draw_area.x, m_draw_area.y, m_draw_area.width, m_draw_area.height);
            ClearBackground(RAYWHITE);
            BeginMode3D(m_camera);
            DrawGrid(10, 1.0f);
            EndMode3D();
            EndScissorMode();
        }
        void update()
        {
            if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
            {
                UpdateCamera(&m_camera, CAMERA_FREE);
            }
            else
            {
                UpdateCamera(&m_camera, CAMERA_ORBITAL);
            }

            float leftWidth = 200.0f;
            float rightWidth = 200.0f;
            float topHeight = 60.0f;
            float bottomHeight = 60.0f;
            float screenWidth = (float)GetScreenWidth();
            float screenHeight = (float)GetScreenHeight();

            m_left_bar_area = { 0.0f, 0.0f, leftWidth, screenHeight };
            m_right_bar_area = { screenWidth - rightWidth, 0.0f, rightWidth, screenHeight };
            m_top_bar_area = { leftWidth, 0.0f, screenWidth - leftWidth - rightWidth, topHeight };
            m_bottom_bar_area = { leftWidth, screenHeight - bottomHeight, screenWidth - leftWidth - rightWidth, bottomHeight };
            m_draw_area = { leftWidth, topHeight, screenWidth - leftWidth - rightWidth, screenHeight - topHeight - bottomHeight };

            m_pick_ray = GetScreenToWorldRayEx(GetMousePosition(), m_camera, m_draw_area.width, m_draw_area.height);
            if(IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                m_collision = GetRayCollisionBox(m_pick_ray, m_game_memory.scene_box);
                m_collision = GetRayCollisionSphere(m_pick_ray, m_game_memory.scene_sphere);
                m_collision = GetRayCollisionTriangle(m_pick_ray, m_game_memory.scene_triangle.v1, m_game_memory.scene_triangle.v2, m_game_memory.scene_triangle.v3);
                m_collision = GetRayCollisionQuad(m_pick_ray, m_game_memory.scene_quad.v1, m_game_memory.scene_quad.v2, m_game_memory.scene_quad.v3, m_game_memory.scene_quad.v4);
                m_collision = GetRayCollisionMesh(m_pick_ray, m_game_memory.scene_mesh);
                if (m_collision.hit)
                {
                    // Handle object selection or interaction here
                }
            }
        }
    private:
        Rectangle m_left_bar_area;
        Rectangle m_right_bar_area;
        Rectangle m_top_bar_area;
        Rectangle m_bottom_bar_area;
        Rectangle m_draw_area;
        game_object* m_selected_object = nullptr;
        Ray m_pick_ray;
        RayCollision m_collision = { 0 };
        Camera3D m_camera;
        game_memory m_game_memory;
};