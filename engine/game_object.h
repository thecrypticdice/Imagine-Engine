

class game_object
{
    public:
    game_object();
    virtual ~game_object() = default;
    virtual void init()=0;
    virtual void update(float delta_time)=0;
    virtual void draw()=0;
    
};