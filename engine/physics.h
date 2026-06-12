#include "headers/headers.h"


class player_map_collition
{
    public:
    player_map_collition(Image cubicmap)
    {
        m_cubicmap = cubicmap;
    }
    ~player_map_collition()
    {
        UnloadImage(m_cubicmap);
    }
    void set_old_position(Vector3 position)
    {
        m_old_position = position;
    }
    void set_collision_threshold(float threshold)
    {
        m_collision_threshold = threshold;
    }
    void check_collision(Vector3 position)
    {
        m_new_position = position;
        process_collision();
    }
    private:
    Image m_cubicmap;
    Vector3 m_old_position;
    Vector3 m_new_position;
    float m_collision_threshold = 0.1f;
    void process_collision()
    {
        Vector2 playerPos = {m_new_position.x,m_new_position.z};
        Color pixelColor = GetImageColor(m_cubicmap, (int)playerPos.x, (int)playerPos.y);
        if (pixelColor.r > 0)
        {
            m_new_position = m_old_position; // Revert to old position on collision
        }
        else
        {
            m_old_position = m_new_position; // Update old position if no collision
        }
    }
};

void player_object_collision(player &player, std::vector<game_object> &objects)
{
    for (auto &obj : objects)
    {
        if (CheckCollisionSpheres(player.position, player.radius, obj.position, obj.radius))
        {
            // Simple collision response: move player back to previous position
            player.position = player.old_position;
            break; // Exit loop after handling collision
        }
    }
}
