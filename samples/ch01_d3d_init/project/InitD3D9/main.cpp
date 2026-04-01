#include <windows.h>
#include "d3dUtility.h"

/*
* Global variables
*/
IDirect3DDevice9* Device = 0;	// instantiating a global variable for the device

const int Width = 640;
const int Height = 480;

// Initialization
bool Setup()
{
    D3DXMATRIX proj;
    D3DXMatrixPerspectiveFovLH(
        &proj,							// result
        D3DX_PI * 0.5f,					// 90 - degrees
        (float)Width / (float)Height,	// aspect ratio
        1.0f,							// near plane
        1000.0f);						// far plane
    Device->SetTransform(D3DTS_PROJECTION, &proj);

    // Set wire-frame mode render state.
    Device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

    return true;
}

// Cleanup
void Cleanup()
{
}

bool Display(float timeDelta)
{
    if (Device)
    {
        Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
            0x00000000, 1.0f, 0);

        Device->Present(0, 0, 0, 0); // present backbuffer
    }

    return true;
}

LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_KEYDOWN:
        if (wParam == VK_ESCAPE)
            DestroyWindow(hwnd);
        break;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

// The entry point for any Windows program
int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nShowCmd)
{
    if (!d3d::InitD3D(hInstance,
        800, 600, true, D3DDEVTYPE_HAL, &Device))
    {
        ::MessageBox(0, "InitD3D() - FAILED", 0, 0);
        return 0;
    }

    if (!Setup())
    {
        ::MessageBox(0, "InitD3D() - FAILED", 0, 0);
        return 0;
    }

    d3d::EnterMsgLoop(Display);

    Cleanup();

    // return 0 to Windows
    return 0;
}