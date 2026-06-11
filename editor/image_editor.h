#include "headers/headers.h"

class imagine_editor
{
    public:

    void load_image(std::string image_path)
    {
        m_image = LoadImage(image_path.c_str());
    }
    void create_image(int width, int height)
    {
        m_image = GenImageColor(width, height, BLANK);
    }
    void unload_image()
    {
        UnloadImage(m_image);
    }
    void save_image(std::string image_path)
    {
        if(image_path.empty())
        {
            if (image_path.substr(image_path.size() - 4) != ".png")
            {
                image_path += ".png";
            }
            bool success = ExportImage(m_image, image_path.c_str());
            if (success)
            {
                std::cout << "Image saved successfully: " << image_path << std::endl;
            }
            else
            {
                std::cout << "Failed to save image: " << image_path << std::endl;
            }
        }
    }
    void update()
    {
        if (m_is_editing and m_image.data != nullptr)
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {

                m_mouse_position = GetMousePosition();
                ImageDrawPixel(&m_image, m_mouse_position.x, m_mouse_position.y, m_drawing_color);
                m_image_changed = true;
            }
        }
    }
    void draw()
    {
        // draw the editor
        if (m_image.data != nullptr)
        {
            m_texture = LoadTextureFromImage(GenImageColor(m_size.x, m_size.y, SKYBLUE));
            DrawTexture(m_texture, m_position.x, m_position.y, WHITE);
            DrawText("No image", m_position.x + (m_size.x/2) - (8*20), m_position.y - (m_size.y/2), 20, BLACK);
        }
        if (m_texture.id != 0)
        {
            UnloadTexture(m_texture);
            m_image_changed = false;
        }
        m_texture = LoadTextureFromImage(m_image);
        DrawTexture(m_texture, m_position.x, m_position.y, WHITE);
    }
    void set_editing(bool is_editing)
    {
        m_is_editing = is_editing;
    }
    void set_position(Vector2 position)
    {
        m_position = position;
    }
    void set_size(Vector2 size)
    {
        m_size = size;
    }
    private:
    Color m_drawing_color = GRAY;
    Image m_image;
    Texture2D m_texture;
    Vector2 m_mouse_position;
    Vector2 m_position;
    Vector2 m_size = (Vector2){512,512};
    bool m_is_editing = false;
    bool m_image_changed = false;
};