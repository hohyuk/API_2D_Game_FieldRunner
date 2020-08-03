#pragma once

// constexpr	- 컴파일 시점 const
// const		- 런타임 시점 const
// 창 크기
constexpr int WINCX{ 1440 };
constexpr int WINCY{ 960 };

constexpr DWORD PINK_COLOR{ RGB(255,0,255) };

constexpr float PI{ 3.141592f };

// TILE POSITION
constexpr int TILE_START_PX{ 130 };
constexpr int TILE_START_PY{ 120 };

// TILE SIZE
constexpr int TILECX{ 64 };
constexpr int TILECY{ 64 };

// Tile 갯수
constexpr int TILEX{ 19 };
constexpr int TILEY{ 11 };