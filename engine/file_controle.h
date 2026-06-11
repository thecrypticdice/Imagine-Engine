
class file_controle
{
    public:
    void save_file(std::string file_name, std::string data)
    {
        std::ofstream file(file_name);
        if (file.is_open())
        {
            file << data;
            file.close();
        }
    }
    std::string load_file(std::string file_name)
    {
        std::ifstream file(file_name);
        std::string data;
        if (file.is_open())
        {
            std::stringstream buffer;
            buffer << file.rdbuf();
            data = buffer.str();
            file.close();
        }
        return data;
    }
};