#include "headers/headers.h"

class game_memory
{
    public:
    void add_level(const level& new_level)
    {
        m_levels.push_back(new_level);
    }
    void add_sprite_2d(const sprite_2d& new_sprite)
    {
        m_sprites_2d.push_back(new_sprite);
    }
    void add_sprite_3d(const sprite_3d& new_sprite)
    {
        m_sprites_3d.push_back(new_sprite);
    }
    void add_camera(const 3D_camera& new_camera)
    {
        m_cameras.push_back(new_camera);
    }
    level get_level(int index)
    {
        if (index >= 0 && index < m_levels.size())
        {
            return m_levels[index];
        }
        return nullptr; // or throw an exception
    }
    sprite_2d get_sprite_2d(int index)
    {
        if (index >= 0 && index < m_sprites_2d.size())
        {
            return m_sprites_2d[index];
        }
        return nullptr; // or throw an exception
    }
    sprite_3d get_sprite_3d(int index)
    {   
        if (index >= 0 && index < m_sprites_3d.size())
        {
            return m_sprites_3d[index];
        }
        return nullptr; // or throw an exception
    }
    3D_camera get_camera(int index)
    {
        if (index >= 0 && index < m_cameras.size())
        {
            return m_cameras[index];
        }
        return nullptr; // or throw an exception
    }
    void clear_memory()
    {
        m_levels.clear();
        m_sprites_2d.clear();
        m_sprites_3d.clear();
        m_cameras.clear();
    }
    private:
    std::vector<level> m_levels;
    std::vector<sprite_2d> m_sprites_2d;
    std::vector<sprite_3d> m_sprites_3d;
    fps_player m_player;
};