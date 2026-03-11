#include<iostream>
#include <string>


enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR

};

class Logger{

    private:
        LogLevel minLevel;//minmum gösterilecek seveiye

    public:
        Logger(LogLevel level)
        {
            minLevel = level;
        }
        
        void log(LogLevel level, const std::string& message)
        {
            //eger mesaj seviyesi min den küçükse gösterme
            if(level<minLevel)
            {
                return;
            }
            std::cout<<"["<<levelToString(level)<<"]"<<message<<std::endl;
        }

    private:
        std::string levelToString(LogLevel level)
        {
            switch(level){
                case DEBUG:     return "DEBUG";
                case INFO:      return "INFO";
                case WARNING:   return "WARNING";
                case ERROR:     return "ERROR";
                default: return "UNKNOWN";
            }
        } 
};

int main()
{
    Logger logger(INFO);  // INFO ve üstünü göster

    logger.log(DEBUG, "Bu debug mesaji");   // Gösterilmez
    logger.log(INFO, "Program basladi");
    logger.log(WARNING, "Dusuk bellek!");
    logger.log(ERROR, "Sistem hatasi!");

    return 0;
}