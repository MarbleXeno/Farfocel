#include "Farfocel/Common/Console.hpp"

bool fr::Console::show = false;
bool fr::Console::mCreate = true;
std::vector<fru::Log> fr::Console::mLogs;

void fr::Console::AddLog(const std::string &message, const fr::LogLevel& level) {
    mLogs.push_back(fru::Log(mLogs.size() + 1, message, level, GetTimestamp()));
}

void fr::Console::Draw() {
    if(!mCreate){
        show = false;
        mCreate = true;
    }

    if(show)
    {
        ImGui::Begin("Console [~]", &mCreate, ImGuiWindowFlags_MenuBar);
        if(ImGui::BeginMenuBar()){
            if(ImGui::BeginMenu("Clear")){
                mLogs.clear();
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }

        ImGui::BeginChild("Scrolling");
        for(auto& log : mLogs)
        {
            ImGui::TextWrapped("%s", log.GetIndexTime().c_str());
            ImGui::PushStyleColor(ImGuiCol_Text, log.GetImGuiColor());
            ImGui::TextWrapped("%s", log.GetLogMessage().c_str());
            ImGui::PopStyleColor();
        }
        ImGui::EndChild();

        ImGui::End();
    }
}

const std::string fr::Console::GetTimestamp() {
    std::time_t current = std::time(0);
    char* currentC = ctime(&current);
    return currentC;
}
