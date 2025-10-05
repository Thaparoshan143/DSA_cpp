#ifdef LOG_ENABLE_DEF

#include<Types.hpp>

#define LOG_PREFIX "# "
#define ERROR_PREFIX "=> "

#define END_LINE_CMD std::endl // cpp style (buffer flushed)
// #define END_LINE_CMD "\n" // c style

// static log prefix for different logtype
static String s_log_prefix[] = {
    "=> INFO: ",
    "$ MESSAGE: ",
    "# WARNING: ",
    "** ERROR: "
};

namespace Utils
{
    template<typename T = uint>
    void Log(const String& title, const T& val, const String& sep = ": ")
    {
        std::cout << LOG_PREFIX << title << sep << val << END_LINE_CMD;
    }

    void Error(const String& msg)
    {
        std::cout << ERROR_PREFIX << msg << END_LINE_CMD;
    }

    void Seperator(const String& sepSymb = "-", const uint count = 60)
    {
        for(uint i=0;i<count;++i)
        {
            std::cout << sepSymb;
        }
        std::cout << END_LINE_CMD;
    }

    template<typename T>
    void VecLog(const String& title, Vec<T>& vec, const String& vecSep = ", ")
    {
        std::cout << title << "(size: " << vec.size() << "): ";
        for(const T& item : vec)
        {
            std::cout << item << vecSep;
        }
        std::cout << END_LINE_CMD;
    }

    enum LogLevel
    {
        INFO = 0,
        MESSAGE = 1, // info and message same?
        WARNING = 2,
        ERROR = 3
    };

    void LogMsg(const String& msg, const LogLevel& ll)
    {
        std::cout << END_LINE_CMD << s_log_prefix[ll] << msg << END_LINE_CMD << std::endl;
    }
}

#endif