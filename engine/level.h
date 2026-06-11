#include "headers/headers.h"

class level
{
    public:
    void load_level(std::string level_name)
    {
        // load the level
    }
    void unload()
    {
        // unload the level
    }
    void draw()
    {
        // draw the level
    }
    private:
    Image m_map;
    Model m_model;
    Texture2D m_texture;
};