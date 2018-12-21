/* �ɲο�������� */
#include <Windows.h> 

#define TITLE_NAME "����"
#define WIN_WIDTH   800
#define WIN_HEIGHT  400

// ���ڹ��̺���ԭ��  
//      HWND hwnd,              handle to window  
//      UINT uMsg,              message identifier  
//      WPARAM wParam,          first message parameter  
//      LPARAM lParam           second message parameter  
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// �ҵĻ�ͼ������
//      hdc                     �����hdc����
void MY_PAINT_MISSION(HDC hdc);

// �������������൱�� DOS �µ�main����  
//      HINSTANCE hInstance,        handle to current instance  
//      HINSTANCE hPrevInstance,    handle to previous instance  
//      LPSTR lpCmdLine,            pointer to command line  
//      int nCmdShow                show state of window  
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    HWND hWnd;
    hWnd = CreateWindow(TITLE_NAME, TITLE_NAME, WS_OVERLAPPEDWINDOW, 0, 0, WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    MSG msg;

    // hdc init
    HDC hdc = GetDC(hWnd);

    // ��ͼ
    MY_PAINT_MISSION(hdc);

    // ��Ϣѭ��  
    while (GetMessage(&msg, 0, NULL, NULL)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // release
    ReleaseDC(hWnd, hdc);
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
        break;
    }
    return 0;
}

// �˴�Ϊ��ͼ��������
void MY_PAINT_MISSION(HDC hdc) {
    for(int i=1;i<=200;++i)
        for(int j=1;j<=200;++j)
            SetPixel(hdc, i, j, RGB(1, 1, 1));

    SetPixel(hdc, 400, 400, RGB(1, 1, 1));
    SetPixel(hdc, 200, 200, RGB(255, 0, 0));
}