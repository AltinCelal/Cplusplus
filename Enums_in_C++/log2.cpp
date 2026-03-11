#include<iostream>
#include<string>

enum LogLevel
{
    debug,
    info,
    warning,
    error
};

class Logger
{
    private:
    LogLevel minlevel;
    
    public:
    Logger (LogLevel level)
    {
        minlevel = level;
    }

    void log(LogLevel log, std::string message)
    {
        if(log<minlevel)
        {return;}
        
        std::cout<<"["<<levelToString(log)<<"]"<<message<<std::endl;

    }

    private:
    std::string levelToString(LogLevel level)
    {
        switch(level){
            case debug: return "DEBUG";
            case info: return "INFO";
            case warning: return "WARNING";
            case error: return "ERROR";
            default : return"UNKNOW";
        }

    }


};

int main()
{   
    Logger log(debug);
    
    log.log(warning,"sistem anormal sıcaklık degerinde");
    return 0;
}