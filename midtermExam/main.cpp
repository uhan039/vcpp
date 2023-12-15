#include <windows.h>

// ���� ����
HINSTANCE hInst;
HWND hMainWnd;
const int windowWidth = 800;
const int windowHeight = 480;
const int margin = 8;
const int padding = 8;
const int numButtons = 5;
const int buttonSize = (windowWidth - 2 * margin - (numButtons + 1) * padding) / numButtons;

POINT startPoint = { 0 }; //������
POINT endPoint = { 0 }; //����
POINT moveStartPoint = { 0 }; //�̵�������
POINT moveEndPoint = { 0 }; //�̵�����
INT disx =  0 ;
INT disy =  0 ;


int isMouseLButtonPressed = 0;
int isMouseRButtonPressed = 0;
int isKeyPressed = 0;


// �ڽ��� ��Ÿ���� ����
bool isBoxVisible = false;

void DrawBox(HWND hWnd, HDC hdc) {
    RECT rect;
    GetClientRect(hWnd, &rect);

    if (isBoxVisible) {
        // �ڽ� �׸���
        HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0)); // ������ �ڽ�
        SelectObject(hdc, hBrush);
        Rectangle(hdc, startPoint.x, startPoint.y, endPoint.x, endPoint.y);
        DeleteObject(hBrush);
    }
}

// ���� ��Ÿ���� ����
bool isCircleVisible = false;

// �� �׸��� �Լ�
void DrawCircle(HWND hWnd, HDC hdc) {
    RECT rect;
    GetClientRect(hWnd, &rect);

    if (isCircleVisible) {
        // �� �׸���
        HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0)); // ������ ��
        SelectObject(hdc, hBrush);
        Ellipse(hdc, startPoint.x, startPoint.y, endPoint.x, endPoint.y);
        DeleteObject(hBrush);
    }
}

bool blink = false;
//���뺸�� ��Ÿ���� ����
bool isBonobonoVisible = false;

// ���뺸�� �׸��� �Լ�
void DrawBonobono(HWND hWnd, HDC hdc) {
    RECT rect;
    GetClientRect(hWnd, &rect);

    if (isBonobonoVisible) {
        // ���뺸�� �׸���
        HBRUSH hBrush = CreateSolidBrush(RGB(127, 200, 255)); // �Ǻ�
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 231, 109, 567, 456);
        DeleteObject(hBrush);

        if (blink) {
            // ���뺸�� ������ �� �׸���
            HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 279, 241, NULL);
            LineTo(hdc, 296, 256);
            MoveToEx(hdc, 295, 255, NULL);
            LineTo(hdc, 279, 263);
            DeleteObject(hPen);

            // ���뺸�� ���� �� �׸���
            hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 521, 247, NULL);
            LineTo(hdc, 504, 256);
            MoveToEx(hdc, 504, 256, NULL);
            LineTo(hdc, 519, 263);
            DeleteObject(hPen);
        }
        else {

            // ���뺸�� ���� �� �׸���
            hBrush = CreateSolidBrush(RGB(0, 0, 0));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 264, 256, 274, 279);
            Ellipse(hdc, 527, 256, 540, 279);
            DeleteObject(hBrush);

            // ���뺸�� �� �� �׸���
            hBrush = CreateSolidBrush(RGB(255, 255, 255));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 266, 262, 270, 269);
            Ellipse(hdc, 531, 262, 535, 269);
            DeleteObject(hBrush);

        }

        // ���뺸�� �� �׸���
        hBrush = CreateSolidBrush(RGB(255, 150, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 375, 289, 421, 376);
        DeleteObject(hBrush);

        // ���뺸�� �ֵ��� �׸���
        hBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 338, 277, 400, 329);
        Ellipse(hdc, 400, 277, 458, 329);
        DeleteObject(hBrush);

        // ���뺸�� �� �׸���
        hBrush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 380, 262, 421, 304);
        DeleteObject(hBrush);

        // ���뺸�� ������ ���� �׸���
        HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 328, 294, NULL);
        LineTo(hdc, 362, 302);
        MoveToEx(hdc, 368, 310, NULL);
        LineTo(hdc, 329, 331);
        DeleteObject(hPen);

        // ���뺸�� ���� ���� �׸���
        hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 439, 301, NULL);
        LineTo(hdc, 478, 282);
        MoveToEx(hdc, 440, 313, NULL);
        LineTo(hdc, 479, 322);
        DeleteObject(hPen);

    }

    
}


// ���̾� ��Ÿ���� ����
bool isRyanVisible = false;

// ���̾� �׸��� �Լ�
void DrawRyan(HWND hWnd, HDC hdc) {
    RECT rect;
    GetClientRect(hWnd, &rect);

    if (isRyanVisible) {
        // ���̾� �׸���
        HBRUSH hBrush = CreateSolidBrush(RGB(255, 200, 15)); 
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 237, 89, 361, 199);//��
        Ellipse(hdc, 489, 88, 602, 199);//��
        Ellipse(hdc, 264, 122, 593, 441);//��
        DeleteObject(hBrush);

        // ���̾� �ֵ��� �׸���
        hBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 388, 268, 430, 305);
        Ellipse(hdc, 428, 268, 469, 305);
        DeleteObject(hBrush);

        // ���̾� �� �׸���
        hBrush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 344, 230, 365, 249);
        Ellipse(hdc, 490,230, 512, 249);
        DeleteObject(hBrush);
        
        // ���̾� ������ ���� �׸���
        HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 322, 195, NULL);
        LineTo(hdc, 379, 195);
        MoveToEx(hdc, 322, 197, NULL);
        LineTo(hdc, 379, 197);
        MoveToEx(hdc, 322, 199, NULL);
        LineTo(hdc, 379, 199);
        DeleteObject(hPen);

        // ���̾� ���� ���� �׸���
        hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
        SelectObject(hdc, hPen);
        MoveToEx(hdc, 472, 195, NULL);
        LineTo(hdc, 528, 195);
        MoveToEx(hdc, 472, 197, NULL);
        LineTo(hdc, 528, 197);
        MoveToEx(hdc, 472, 199, NULL);
        LineTo(hdc, 528, 199);
        DeleteObject(hPen);

        
      
    }
}

void BUTTON(HWND hWnd, HDC hdc) {
    if (isBoxVisible)
    {
        DrawBox(hWnd, hdc);
    }
    else if (isCircleVisible)
    {
        DrawCircle(hWnd, hdc);
    }
    else if (isBonobonoVisible)
    {
        DrawBonobono(hWnd, hdc);
    }
    else if (isRyanVisible)
    {
        DrawRyan(hWnd, hdc);
    }
}



// ������ ���ν���
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
;

    switch (message) {
    case WM_CREATE:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        RECT box;
        GetClientRect(hWnd, &box);

        // ū �簢�� �׸���
        HBRUSH transparentBrush = CreateSolidBrush(RGB(255, 240, 200));
        SelectObject(hdc, transparentBrush);
        RECT bigbox = { 8, 8, 800 - 8, 480 - 8 };
        Rectangle(hdc, bigbox.left, bigbox.top, bigbox.right, bigbox.bottom);

        // ���� �簢�� �׸���
        HBRUSH drawingBrush = CreateSolidBrush(RGB(255, 255, 255));
        RECT smallBox;
        smallBox.left = bigbox.left + 8;
        smallBox.top = bigbox.top + 8;
        smallBox.right = bigbox.right - 8;
        smallBox.bottom = bigbox.bottom - 8;
        Rectangle(hdc, smallBox.left, smallBox.top, smallBox.right, smallBox.bottom);

        
        DeleteObject(transparentBrush);

        DrawBox(hWnd, hdc);
        EndPaint(hWnd, &ps);

        break;
    }

    case WM_COMMAND:
        if (LOWORD(wParam) == 1) {
            // ù ��° ��ư Ŭ��
            isBoxVisible = true;
            isCircleVisible = false;
            isBonobonoVisible = false;
            isRyanVisible = false;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 2) {
            // �� ��° ��ư Ŭ��
            isBoxVisible = false;
            isCircleVisible = true;
            isBonobonoVisible = false;
            isRyanVisible = false;
            InvalidateRect(hWnd, NULL, TRUE);
            
        }
        else if (LOWORD(wParam) == 3) {
            // �� ��° ��ư Ŭ��
            isBoxVisible = false;
            isCircleVisible = false;
            isBonobonoVisible = true;
            isRyanVisible = false;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 4) {
            // �� ��° ��ư Ŭ��
            isBoxVisible = false;
            isCircleVisible = false;
            isBonobonoVisible = false;
            isRyanVisible = true;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else
        {
            isBoxVisible = false;
            isCircleVisible = false;
            isBonobonoVisible = false;
            isRyanVisible = false;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
 
    case WM_LBUTTONDOWN:
    {
        
       
        //������
        startPoint.x = LOWORD(lParam);
        startPoint.y = HIWORD(lParam);
        isMouseLButtonPressed = 1;
    }
    break;
    
    case WM_MOUSEMOVE:
    {

        // ���콺 �̵� ��
        if (isMouseLButtonPressed)
        {
            endPoint.x = LOWORD(lParam);
            endPoint.y = HIWORD(lParam);

            // WM_PAINT �޽����� �����Ͽ� �׸� ȭ�鿡 �׸��ϴ�.
            InvalidateRect(hWnd, NULL, TRUE);
        }    

    }
    break;

    case WM_LBUTTONUP:
    {

        //����
        endPoint.x = LOWORD(lParam);
        endPoint.y = HIWORD(lParam);
        isMouseLButtonPressed = 0;
        InvalidateRect(hWnd, NULL, TRUE);
    }
    break;

    case WM_RBUTTONDOWN:
    {
        moveStartPoint.x = LOWORD(lParam);
        moveEndPoint.y = HIWORD(lParam);

        disx = moveStartPoint.x - startPoint.x;
        disy = moveEndPoint.y - startPoint.y;

        startPoint.x += disx;
        startPoint.y += disy;
        endPoint.x += disx;
        endPoint.y += disy;



        // WM_PAINT �޽����� �����Ͽ� �׸� ȭ�鿡 �׸��ϴ�.
        InvalidateRect(hWnd, NULL, TRUE);
    }
    break;



    case WM_KEYDOWN:
    {
        
        if (wParam == VK_SPACE)
        {
            blink = true;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        
    }
    break;

    case WM_KEYUP:
    {
        if (wParam == VK_SPACE)
        {
            blink = false;
            InvalidateRect(hWnd, NULL, TRUE);
        }
    }
    break;


    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // ������ �簢�� �׸���
        HBRUSH transparentBrush = CreateSolidBrush(RGB(255, 240, 200));
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);
        Rectangle(hdc, 8, 8, 800 - 8, 480 - 8);

        HBRUSH drawingBrush = CreateSolidBrush(RGB(255, 255, 255));
        oldBrush = (HBRUSH)SelectObject(hdc, drawingBrush);
        Rectangle(hdc, 16, 88, 800 - 16, 480 - 16);

        SelectObject(hdc, oldBrush);
        DeleteObject(transparentBrush);

        BUTTON(hWnd, hdc);
        EndPaint(hWnd, &ps);



    }
    break;

    
    

    case WM_DESTROY:
        DestroyWindow(hWnd);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}



// ���α׷� ������
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    hInst = hInstance;
    HWND hButton1, hButton2, hButton3, hButton4, hButton5;

    WNDCLASSEX wcex;
    memset(&wcex, 0, sizeof(wcex));
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.hInstance = hInstance;
    wcex.hbrBackground = CreateSolidBrush(RGB(255, 240, 200));
    wcex.lpszClassName = L"TransparentWindowWithButtons";
    RegisterClassEx(&wcex);

    // Window viewport ���� ����
    RECT rect = { 150, 100, 800, 480 };
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, 0);
    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;


    hMainWnd = CreateWindow(L"TransparentWindowWithButtons", L"MidtermExam", WS_OVERLAPPEDWINDOW,
        100, 100, windowWidth+20, windowHeight+35, NULL, NULL, hInstance, NULL);

    if (!hMainWnd)
        return FALSE;

    
    //��ư
    hButton1 = CreateWindow(
        L"BUTTON", L"Box", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        16, 16, 140, 64, hMainWnd, (HMENU)1, hInst, NULL);

    hButton2 = CreateWindow(
        L"BUTTON", L"Circle", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        172, 16, 140, 64, hMainWnd, (HMENU)2, hInst, NULL);

    hButton3 = CreateWindow(
        L"BUTTON", L"Bonobono", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        328, 16, 140, 64, hMainWnd, (HMENU)3, hInst, NULL);

    hButton4 = CreateWindow(
        L"BUTTON", L"Ryan", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        484, 16, 140, 64, hMainWnd, (HMENU)4, hInst, NULL);

    hButton5 = CreateWindow(
        L"BUTTON", L"Cube", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        640, 16, 140, 64, hMainWnd, (HMENU)5, hInst, NULL);


    ShowWindow(hMainWnd, nCmdShow);
    UpdateWindow(hMainWnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}