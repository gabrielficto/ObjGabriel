class FileHandler   {
    std::string filename = "";

    public:
        FileHandler(std::string filename){ 
            this->filename = filename; 
        }

        void write( std::string content ) { 
            std::ofstream File(this->filename); 
            File << content; 
            File.close(); 
        } 

        std::string readLine() { 
            std::ifstream File(this->filename); 
            std::string content = "";
            getline(File, content); 
            File.close(); 
            return content; 
        } 
}; 
