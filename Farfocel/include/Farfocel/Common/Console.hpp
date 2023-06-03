// bania bania bania bania bania bania bania bania bania
// dyczi dyczi dyczi dyczi dyczi dyczi dyczi dyczi dyczi
// wazaa wazaa wazaa wazaa wazza wazaa wazza wazza wazza

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <SFML/Graphics.hpp>

#include <imgui.h>

#include "Farfocel/Utils/Log.hpp"

namespace fr {
    class Console {
    public:
        static void AddLog(const std::string &message, const fr::LogLevel& level);
        static void Draw();
        static const std::string GetTimestamp();

        static bool show;
    private:
        static bool mCreate;
        static std::vector<fru::Log> mLogs;
    };
}
