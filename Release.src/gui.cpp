#ifndef UNICODE // UNICODE
#define UNICODE // UNICODE
#endif // UNICODE


// Windows

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>



// Custom individual page code.
#define GUI 0x10201090


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
  const wchar_t CLASS_NAME[] = L"TaskForceClass";

  WNDCLASS wc;

  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = CLASS_NAME;

  RegisterClass(&wc);

  HWND hwnd = CreateWindowEx(
    0,                              // Optional window styles.
    CLASS_NAME,                     // Window class
    L"TaskForce",                   // Window text
    WS_OVERLAPPEDWINDOW,            // Window style

    // Size and position
    CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

    NULL,       // Parent window
    NULL,       // Menu
    hInstance,  // Instance handle
    NULL        // Additional application data
  );

  if (hwnd == NULL)
  {
    return 0;
  }

  ShowWindow(hwnd, nCmdShow);


  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0) > 0)
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
  case WM_DESTROY:
    PostQuitMessage(0);
    return 0;

  case WM_PAINT:
  {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);

    FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

    EndPaint(hwnd, &ps);
  }
  return 0;

  }
  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
