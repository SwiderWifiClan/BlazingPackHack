#include <Windows.h>
#include <iostream>
#include <cassert>
#include <cstdint>
#include "Utils.h"
#include "Hook/Minhook/include/MinHook.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_opengl3.h"
#include "ImGui/imgui_impl_win32.h"
#pragma region OpenGL
#ifdef _WIN64
#define GWL_WNDPROC GWLP_WNDPROC
#endif

#define GLEW_STATIC
#include "Hook/GLx64/glew.h"
#pragma comment(lib, "Source/Hook/GLx64/glew32s.lib")
#include <gl/gl.h> 
#pragma comment(lib,"opengl32.lib")
#pragma endregion
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef BOOL(__stdcall* twglSwapBuffers) (_In_ HDC hDc);
typedef BOOL(__stdcall* tglCallList) (GLuint list);