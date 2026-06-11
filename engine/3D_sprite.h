#include "headers/headers.h"


class sprite_3d
{
public:
    Vector3 position = { 0.0f, 0.0f, 0.0f };
    Vector2 scale = { 1.0f, 1.0f };          // Scale modifies width and height in 3D units
    float rotation = 0.0f;                   // Rotation around the billboard's face axis
    Color color = WHITE;

    ~sprite_3d()
    {
        unload_textures();
    }

    // --- MODE 1: Sprite Sheet ---
    void set_texture(const char* path, int frames_width, int frames_height)
    {
        unload_textures();
        m_is_sprite_sheet = true;

        Texture2D tex = LoadTexture(path);
        m_textures.push_back(tex);

        m_frames_max_width = frames_width;
        m_frames_max_height = frames_height;
        m_total_frames = frames_height * frames_width;
        m_frameWidth = tex.width / frames_width;
        m_frameHeight = tex.height / frames_height;

        set_frame(1);
    }

    // --- MODE 2: Separated Individual Images ---
    void set_textures(const std::vector<std::string>& paths)
    {
        unload_textures();
        m_is_sprite_sheet = false;

        for (const auto& path : paths)
        {
            m_textures.push_back(LoadTexture(path.c_str()));
        }

        m_total_frames = m_textures.size();
        
        if (m_total_frames > 0)
        {
            m_frameWidth = m_textures[0].width;
            m_frameHeight = m_textures[0].height;
        }

        set_frame(1);
    }

    void play_animation(int start_frame, int end_frame, float speed, float delta)
    {
        int start = start_frame - 1;
        int end = end_frame - 1;

        if (m_current_frame < start || m_current_frame > end)
        {
            m_current_frame = start;
        }

        m_time_line += delta;
        if (m_time_line >= speed)
        {
            m_time_line = 0;
            m_current_frame++;

            if (m_current_frame > end)
            {
                m_current_frame = start;
            }
        }

        update_frame_rectangle();
    }

    void set_frame(int frame_index)
    {
        m_current_frame = frame_index - 1;
        
        if (m_current_frame < 0) m_current_frame = 0;
        if (m_current_frame >= m_total_frames) m_current_frame = m_total_frames - 1;

        update_frame_rectangle();
    }

    // Crucial change: The draw method now requires the active 3D camera context
    void draw(Camera camera)
    {
        if (m_textures.empty()) return;

        // Billboards use world size dimensions rather than screen pixel dimensions.
        // We use a baseline normalization factor (e.g., dividing by 100.0f) 
        // so that pixel ratios translate into predictable 3D meter sizes.
        float size_normalization = 100.0f;
        Vector2 size = {
            (m_frameWidth / size_normalization) * scale.x,
            (m_frameHeight / size_normalization) * scale.y
        };

        // Origin point relative to the billboard size (0.5f centered, 1.0f top/bottom)
        Vector2 origin = { size.x / 2.0f, size.y / 2.0f };

        Texture2D target_texture = m_is_sprite_sheet ? m_textures[0] : m_textures[m_current_frame];

        // Raylib's 3D billboard system handles screen orientation automatically
        DrawBillboardPro(
            camera, 
            target_texture, 
            m_selected_frame, 
            position, 
            camera.up,        // Up vector defining standard billboard vertical direction
            size, 
            origin, 
            rotation, 
            color
        );
    }

    Rectangle get_rectangle() const
    {
        return m_selected_frame;
    }

    void unload_textures()
    {
        for (auto& tex : m_textures)
        {
            UnloadTexture(tex);
        }
        m_textures.clear();
    }

private:
    std::vector<Texture2D> m_textures;
    bool m_is_sprite_sheet = true;
    
    float m_time_line = 0.0f;
    int m_frames_max_width = 1;
    int m_frames_max_height = 1;
    int m_current_frame = 0;
    int m_total_frames = 1;
    int m_frameWidth = 0;
    int m_frameHeight = 0;
    Rectangle m_selected_frame = {0, 0, 0, 0};

    void update_frame_rectangle()
    {
        if (m_textures.empty()) return;

        if (m_is_sprite_sheet)
        {
            int row = m_current_frame / m_frames_max_width;
            int col = m_current_frame % m_frames_max_width;

            m_selected_frame =
            {
                (float)(col * m_frameWidth),
                (float)(row * m_frameHeight),
                (float)m_frameWidth,
                (float)m_frameHeight
            };
        }
        else
        {
            m_selected_frame = 
            {
                0.0f, 
                0.0f, 
                (float)m_textures[m_current_frame].width, 
                (float)m_textures[m_current_frame].height
            };
        }
    }
};