# CLAUDE.md — 프로젝트 가이드

## 프로젝트 개요

Frank D. Luna의 『Introduction to 3D Game Programming with DirectX 9.0』 예제 코드 저장소입니다.
원본 소스: [d3dcoder.net](https://www.d3dcoder.net/default.htm)

## 필수 SDK

- [DirectX SDK (June 2010)](https://www.microsoft.com/en-us/download/details.aspx?id=6812)

## 저장소 구조

```
frank-luna-dx9-samples/
├── Book Part II Code/      # 기초 파트 (챕터 1~8)
│   ├── Chapter 1/D3D9 Init/        — Direct3D 초기화 (d3dInit.cpp, d3dUtility.h/cpp)
│   ├── Chapter 3/                  — Triangle, Cube, Teapot, D3DXCreate
│   ├── Chapter 4/Colore Triangle/  — 정점 컬러
│   ├── Chapter 5/                  — directional light, point light, spotlight, lit pyramid
│   ├── Chapter 6/                  — AddressModes, TexQuad, TexCube
│   ├── Chapter 7/                  — MtrlAlpha, texAlpha
│   └── Chapter 8/                  — Stencil Mirror, Stencil Shadow, Stencil Mirror Shadow
└── Book Part III Code/     # 심화 파트 (챕터 9~15)
    ├── Chapter 9/                  — CFont, ID3DXFont, D3DXCreateText
    ├── Chapter 10/                 — D3DXCreateMeshFVF
    ├── Chapter 11/                 — XFile, Bounding Volumes, Progressive Mesh
    ├── Chapter 12/Camera/          — 카메라 구현
    ├── Chapter 13/                 — Terrain, Terrain2
    ├── Chapter 14/                 — Snow System, Firework System, Laser System
    └── Chapter 15/Pick/            — 피킹
```

## 코드 탐색 가이드

### 핵심 유틸리티 파일

- `Book Part II Code/Chapter 1/D3D9 Init/d3dUtility.h` — D3D 헬퍼 함수 헤더 (대부분 예제에서 재사용)
- `Book Part II Code/Chapter 1/D3D9 Init/d3dUtility.cpp` — D3D 헬퍼 함수 구현
- `Book Part II Code/Chapter 1/D3D9 Init/d3dInit.cpp` — WinMain, 메시지 루프, D3D 초기화 패턴

### 주제별 예제 찾기

| 주제 | 경로 |
|------|------|
| Direct3D 초기화 패턴 | `Book Part II Code/Chapter 1/D3D9 Init/` |
| 정점 버퍼 / 인덱스 버퍼 | `Book Part II Code/Chapter 3/` |
| 조명 (Directional/Point/Spot) | `Book Part II Code/Chapter 5/` |
| 텍스처 매핑 | `Book Part II Code/Chapter 6/` |
| 알파 블렌딩 / 투명도 | `Book Part II Code/Chapter 7/` |
| 스텐실 버퍼 (거울, 그림자) | `Book Part II Code/Chapter 8/` |
| 폰트 렌더링 | `Book Part III Code/Chapter 9/` |
| 메시 생성 (D3DXCreateMesh) | `Book Part III Code/Chapter 10/` |
| X파일 로딩 | `Book Part III Code/Chapter 11/XFile/` |
| 바운딩 볼륨 | `Book Part III Code/Chapter 11/Bounding Volumes/` |
| 카메라 | `Book Part III Code/Chapter 12/Camera/` |
| 지형(하이트맵) | `Book Part III Code/Chapter 13/` |
| 파티클 시스템 | `Book Part III Code/Chapter 14/` |
| 마우스 피킹 | `Book Part III Code/Chapter 15/Pick/` |

## 코드 패턴

각 예제는 보통 다음 구조를 따릅니다:

```cpp
// WinMain — 윈도우 생성 및 D3D 초기화
bool Setup();    // 리소스 생성 (정점 버퍼, 텍스처 등)
void Cleanup();  // 리소스 해제
bool Display(float timeDelta);  // 매 프레임 렌더링 로직
```

## 검색 팁

- 특정 D3D API 사용법 찾기: `Grep "IDirect3DDevice9"` 또는 `Grep "D3DXCreate"`
- 특정 챕터 전체 읽기: `Read` 도구로 `.cpp` 파일 직접 열기
- 파일 목록 확인: `Glob "**/*.cpp"` 또는 `Glob "**/*.h"`
