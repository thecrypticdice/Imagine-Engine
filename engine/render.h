#include "headers/headers.h"

void render(game_object *object,int size)
{
    for(int i=0;i<size;i++)
    {
        object[i].draw();
    }
}
void render(std::vector<game_object> object)
{
    for(int i=0;i<object.size();i++)
    {
        object[i].draw();
    }
}