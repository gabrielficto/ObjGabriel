class FileHandler {
    std::string filename = "";
    public:
        FileHandler(std::string filename) {
            this -> filename = filename;
        }
    void write(std::string content) {
        std::ofstream File(this -> filename);
        File << content;
        File.close();
    }
    std::string readFirstLine() {
        std::ifstream File(this -> filename);
        std::string content = "";
        getline(File, content);
        File.close();
        return content;
    }
    std::string read() {
        std::ifstream file(this -> filename.c_str());
        std::string line = "", content;
        while (getline(file, line))
            content += line + "\n";
        file.close();
        return content;
    }
};