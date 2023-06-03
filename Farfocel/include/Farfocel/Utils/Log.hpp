#pragma once
#include <iostream>
#include <string>
#include <imgui.h>

namespace fr{
    enum class LogLevel{
        MESSAGE = 1,
        SUCCESS = 2,
        WARNING = 3,
        ERROR = 4
    };
}

namespace fru {
    class Log {
    public:
        Log(){}
        Log(const std::uint32_t& index, const std::string& message, const fr::LogLevel& level, const std::string& timestamp)
            : mLevel(level), mLogMessage(message)
        {
            mTimeIndex = std::to_string(index)+". "+timestamp;

            switch (mLevel) {
                case fr::LogLevel::MESSAGE:
                    mImGuiColor = ImVec4(sf::Color(100.f,100.f,100.f,255.f));
                    break;
                case fr::LogLevel::SUCCESS:
                    mImGuiColor = ImVec4(ImColor(0.159f, 1.f, 0.115f,1.f));
                    break;
                case fr::LogLevel::WARNING:
                    mImGuiColor = ImVec4(ImColor(1.f, 0.85f, 0.35f,1.f));
                    break;
                case fr::LogLevel::ERROR:
                    mImGuiColor = ImVec4(ImColor(1.f, 0.35f, 0.35f,1.f));
                    break;
            }
        }

        ~Log(){

        }

        const ImVec4& GetImGuiColor(){
            return mImGuiColor;
        }

        const std::string& GetIndexTime(){
            return mTimeIndex;
        }

        const std::string& GetLogMessage(){
            return mLogMessage;
        }


    private:
        fr::LogLevel mLevel;
        ImVec4 mImGuiColor;

        std::string mTimeIndex;
        std::string mLogMessage;


    };

} // fru
