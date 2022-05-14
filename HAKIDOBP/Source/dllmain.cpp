#include "Includes.h"
#include "..//jellomedium.h"
#include "../bool.h"
#include "../xorstr.hpp"
#include "../scan.h"
#include <TlHelp32.h>
using namespace std;

twglSwapBuffers oSwapBuffers = NULL;
tglCallList oglCallList;
WNDPROC oWndProc;
/// 
///  Pozdrawiam Swider <3
///  Nie Sprzedawajcie bo cringe 
///  SOURCE UZYWAJCIE DO WLASNEGO UZYTKU 
///  
/// 

static HWND Window = NULL;

POINT p;
int init = false;
bool show = false;
void style211() {
    ImGui::GetIO().WantCaptureMouse = show;
    ImGui::GetIO().MouseDrawCursor = show;
    ImGuiStyle& style = ImGui::GetStyle();
    style.Alpha = 1.0f;
    style.WindowPadding = ImVec2(0, 8);
    style.WindowMinSize = ImVec2(32, 32);
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    style.ItemSpacing = ImVec2(4, 9);
    style.ItemInnerSpacing = ImVec2(8, 8);
    style.TouchExtraPadding = ImVec2(0, 0);
    style.IndentSpacing = 21.0f;
    style.ColumnsMinSpacing = 3.0f;
    style.ScrollbarSize = 14.0f;
    style.GrabMinSize = 5.0f;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.DisplayWindowPadding = ImVec2(22, 22);
    style.DisplaySafeAreaPadding = ImVec2(4, 4);
    style.FramePadding = ImVec2(0, 0);
    style.AntiAliasedLines = true;
    style.WindowRounding = 0;
    style.ChildRounding = 0;
    style.CurveTessellationTol = 1.25f;
    style.Colors[ImGuiCol_TitleBg] = ImColor(35, 35, 35, 255);
    style.Colors[ImGuiCol_TitleBgActive] = ImColor(35, 35, 35, 255);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(35, 35, 35, 255);
    style.Colors[ImGuiCol_FrameBg] = ImColor(54, 54, 54, 255);
    style.Colors[ImGuiCol_FrameBgActive] = ImColor(72, 76, 77, 255);
    style.Colors[ImGuiCol_FrameBgHovered] = ImColor(72, 76, 77, 255);
    style.Colors[ImGuiCol_CheckMark] = ImColor(255, 255, 255, 255);
    style.Colors[ImGuiCol_SliderGrab] = ImColor(108, 186, 248, 255);
    style.Colors[ImGuiCol_SliderGrabActive] = ImColor(48, 116, 170, 255);
    style.Colors[ImGuiCol_Button] = ImColor(23, 23, 23, 255);
    style.Colors[ImGuiCol_ButtonActive] = ImColor(23, 23, 23, 255);
    style.Colors[ImGuiCol_ButtonHovered] = ImColor(53, 53, 53, 255);
    style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
    style.Colors[ImGuiCol_WindowBg] = ImColor(17, 17, 17, 255);
    style.Colors[ImGuiCol_ChildBg] = ImColor(31, 31, 31, 255);
    style.Colors[ImGuiCol_TabActive] = ImColor(23, 23, 23, 255);
    style.Colors[ImGuiCol_TabHovered] = ImColor(23, 23, 23, 255);
    style.Colors[ImGuiCol_TabUnfocused] = ImColor(28, 28, 39, 255);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImColor(23, 23, 23, 255);
    style.Colors[ImGuiCol_Tab] = ImColor(23, 23, 23, 255);
}
static ImVec4 active = ImVec4(0.423, 0.729, 0.972, 255);
static ImVec4 inactive = ImVec4(255, 255, 255, 255);
static const ImWchar ranges[] =
{
    0x0020, 0x00FF,
    0x0400, 0x044F,
    0
};
BOOL __stdcall hkSwapBuffers(_In_ HDC hDc)
{
    if (init == FALSE)
    {
        glewExperimental = GL_TRUE;
        if (glewInit() == GLEW_OK)
        {
            ImGui::CreateContext();
            ImGuiIO& io = ImGui::GetIO();
            ImFontConfig m_config;
            m_config.OversampleH = m_config.OversampleV = 3;
            m_config.PixelSnapH = false;
            io.Fonts->AddFontFromMemoryTTF((void*)jellomedium, sizeof(jellomedium), 15.0f, &m_config, ranges);


            ImGui_ImplWin32_Init(Window);
            ImGui_ImplOpenGL3_Init();
            init = TRUE;
        }
    }
    ImGuiIO& io = ImGui::GetIO();
    ImFontConfig m_config;
    if (GetAsyncKeyState(VK_INSERT) & 1)
    {
        show = !show;
    }
    if (GetAsyncKeyState(bindy::xraybind) & 1) {
        opcje::xray = !opcje::xray;
    }
    if (GetAsyncKeyState(bindy::wirefrimebind) & 1) {
        opcje::wirefrime = !opcje::wirefrime;
    }


    if (GetAsyncKeyState(bindy::chamsbind) & 1) {
        opcje::flatchams = !opcje::flatchams;
    }
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowMinSize = ImVec2(480, 295);
    style211();
    ImGui::SetNextWindowSize({ 2000, 2000 });
    ImGui::Begin("xd", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus);
    ImGui::GetWindowDrawList()->AddText(ImVec2(100, 60), IM_COL32(98, 115, 252, 255), xorstr_("Wifi Clan"));
    ImGui::End();

    if (show)
    {
#pragma region  menu



        ImGui::SetNextWindowSize({ 650, 500 });
        ImGui::Begin("SwiderBP", &show, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse  | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
        ImGui::SetColorEditOptions(ImGuiColorEditFlags_RGB | ImGuiColorEditFlags_NoOptions | ImGuiColorEditFlags_NoInputs);
        ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("BlazingHack - Swider").x) * 0.5f);
        ImGui::Text(xorstr_("BlazingPack -"));
        ImGui::SameLine();
        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(108, 186, 248, 255));
        ImGui::Text(xorstr_("Swider"));
        ImGui::PopStyleColor(1);
        ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(21, 21, 21, 255));
        ImGui::BeginChild("##pasekwybierania", ImVec2(ImGui::GetContentRegionAvail().x, 40), true);
        ImGui::PushStyleColor(ImGuiCol_Text, opcje::tab == 1 ? active : inactive);
        ImGui::SetCursorPosX(200);
        ImGui::SetCursorPosY(10);
        ImGui::Text("ESP");
        if (ImGui::IsItemClicked()) {
            opcje::tab = 1;
        }
        ImGui::SameLine(0, 80);
        ImGui::PushStyleColor(ImGuiCol_Text, opcje::tab == 2 ? active : inactive);
        ImGui::Text("Misc");
        if (ImGui::IsItemClicked()) {
            opcje::tab = 2;
        }
        ImGui::SameLine(0, 80);
        ImGui::PushStyleColor(ImGuiCol_Text, opcje::tab == 3 ? active : inactive);
        ImGui::Text("Settings");
        if (ImGui::IsItemClicked()) {
            opcje::tab = 3;
        }

        ImGui::PopStyleColor(4);
        ImGui::EndChild();
        if (opcje::tab == 1){
        ImGui::SetCursorPosX(17);
        ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(21, 21, 21, 255));
        ImGui::BeginChild("##General", ImVec2(300, 370), true);
        ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(25, 25, 25, 255));
        ImGui::SetCursorPosY(0);
        ImGui::BeginChild("##TextGeneral", ImVec2(300, 30), true);
        ImGui::SetCursorPosX(5);
        ImGui::SetCursorPosY(5);

        ImGui::Text("General");

        ImGui::PopStyleColor(2);
        ImGui::EndChild();
        ImGui::SetCursorPosX(5);
        ImGui::Checkbox("XRAY", &opcje::xray);
        ImGui::SameLine(0, 5);
        ImGui::Bind("##Xray Bind", &bindy::xraybind, ImVec2(45, 25));
        ImGui::SetCursorPosX(5);
        ImGui::Checkbox("Wirefrime", &opcje::wirefrime);
        ImGui::SameLine(0, 5);
        ImGui::Bind("##Wirefrime Bind", &bindy::wirefrimebind, ImVec2(45, 25));
        ImGui::SetCursorPosX(5);
        ImGui::Checkbox("Chams", &opcje::flatchams);;
        ImGui::SameLine(0, 5);
        ImGui::Bind("##chamsbind Bind", &bindy::chamsbind, ImVec2(45, 25));
        ImGui::EndChild();
        ImGui::SameLine(0, 17);
        ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(21, 21, 21, 255));
        ImGui::BeginChild("##Visuals", ImVec2(300, 370), true);
        ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(25, 25, 25, 255));
        ImGui::SetCursorPosY(0);
        ImGui::BeginChild("##TextVisuals", ImVec2(300, 30), true);
        ImGui::SetCursorPosX(5);
        ImGui::SetCursorPosY(5);

        ImGui::Text("Visuals");

        ImGui::PopStyleColor(2);
        ImGui::EndChild();




        ImGui::EndChild();
        }
        if (opcje::tab == 2) {
            ImGui::SetCursorPosX(17);
            ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(21, 21, 21, 255));
            ImGui::BeginChild("##General", ImVec2(300, 370), true);
            ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(25, 25, 25, 255));
            ImGui::SetCursorPosY(0);
            ImGui::BeginChild("##TextGeneral", ImVec2(300, 30), true);
            ImGui::SetCursorPosX(5);
            ImGui::SetCursorPosY(5);

            ImGui::Text("General");

            ImGui::PopStyleColor(2);
            ImGui::EndChild();

            ImGui::EndChild();
            ImGui::SameLine(0, 17);
            ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(21, 21, 21, 255));
            ImGui::BeginChild("##Misc", ImVec2(300, 370), true);
            ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(25, 25, 25, 255));
            ImGui::SetCursorPosY(0);
            ImGui::BeginChild("##TextMisc", ImVec2(300, 30), true);
            ImGui::SetCursorPosX(5);
            ImGui::SetCursorPosY(5);

            ImGui::Text("Misc");
            ImGui::PopStyleColor(2);
            ImGui::EndChild();
            ImGui::SetCursorPosX(5);



            ImGui::EndChild();
        }
        ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(21, 21, 21, 255));
        ImGui::SetCursorPosY(465);
        ImGui::BeginChild("##DOL", ImVec2(ImGui::GetContentRegionAvail().x, 35), true);


        ImGui::SetCursorPosX(5);
        ImGui::Text(xorstr_("Made By Swider <3"));
        ImGui::SameLine(0, 380);
        ImGui::Text("Build Date: 14.05.2022");


        ImGui::EndChild();
        ImGui::PopStyleColor(1);
    }
#pragma endregion
    ImGui::End();
    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    return oSwapBuffers(hDc);
}

DWORD WINAPI unload(HMODULE hModule)
{



#pragma region  unlaod dllki
    while (true)
    {

        if (GetAsyncKeyState(VK_END) & 1)
        {
            MH_DisableHook(MH_ALL_HOOKS);
            MH_DisableHook(MH_QueueEnableHook);
            SetWindowLongPtr(Window, GWL_WNDPROC, (LONG_PTR)oWndProc);    //unlodowanie dll
            FreeLibraryAndExitThread(hModule, 0);
        }
        Sleep(5);
    }
    FreeConsole();
    return 0;
#pragma endregion
}
BOOL __stdcall hglCallList(GLuint list) {




    if (opcje::xray) {

        glDepthRange(1, 0);
        oglCallList(list);
        glDepthRange(0, 1);
    }
    else {
        glDepthRange(0, 1);
    }

    if (opcje::flatchams) {
        glColor3f(0.6, 0.317, 0.882);
        glDepthRange(1, 0);
        glDisable(GL_TEXTURE_2D);
        oglCallList(list);
        glDepthRange(0, 1);
        glEnable(GL_TEXTURE_2D);
    }
    else {
        glDepthRange(0, 1);
        glEnable(GL_TEXTURE_2D);
    }
    if (opcje::wirefrime) {

        glDisable(GL_DEPTH_TEST);
 
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        oglCallList(list);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);;


        glEnable(GL_DEPTH_TEST);
 
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }


    return oglCallList(list);
}







LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (show) {
        ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
            return true;
    }

    return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}


bool menuShown = false;
uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName)
{
    uintptr_t modBaseAddr = 0;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
    if (hSnap != INVALID_HANDLE_VALUE)
    {
        MODULEENTRY32 modEntry;
        modEntry.dwSize = sizeof(modEntry);
        if (Module32First(hSnap, &modEntry))
        {
            do
            {
                if (!_wcsicmp(modEntry.szModule, modName))
                {
                    modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
                    break;
                }
            } while (Module32Next(hSnap, &modEntry));
        }
    }
    CloseHandle(hSnap);
    return modBaseAddr;
}








DWORD WINAPI Initalization(__in  LPVOID lpParameter)
{
    while (GetModuleHandle(L"opengl32.dll") == NULL) { Sleep(100); }
    Sleep(100);

    HMODULE hMod = GetModuleHandle(L"opengl32.dll");
    if (hMod)
    {
        void* ptr = GetProcAddress(hMod, "wglSwapBuffers");
        void* call = GetProcAddress(hMod, "glCallList");


        MH_Initialize();
        MH_CreateHook(ptr, hkSwapBuffers, reinterpret_cast<void**>(&oSwapBuffers));
        MH_CreateHook(call, hglCallList, reinterpret_cast<void**>(&oglCallList));



        MH_QueueEnableHook(ptr);
        MH_QueueEnableHook(call);
        MH_ApplyQueued();

        do
            Window = GetProcessWindow();
        while (Window == NULL);
        oWndProc = (WNDPROC)SetWindowLongPtr(Window, GWL_WNDPROC, (LONG_PTR)WndProc);
        return true;
    }
    else
        return false;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)unload, hModule, 0, nullptr));
        CreateThread(0, 0, Initalization, 0, 0, 0);
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

