#pragma once

// constexpr	- 컴파일 시점 const
// const		- 런타임 시점 const
// 창 크기
constexpr int WINCX{ 1440 };
constexpr int WINCY{ 960 };

/*GameObject Update Event*/
constexpr int OBJ_NOEVENT{ 0 };
constexpr int OBJ_DEAD{ 1 };

constexpr DWORD PINK_COLOR{ RGB(255,0,255) };
constexpr DWORD BLACK_COLOR{ RGB(0,0,0) };


constexpr float PI{ 3.141592f };
constexpr float RADIAN{ 180.f / PI };
constexpr float DEGREE{ PI / 180.f };


// TILE POSITION
constexpr int TILE_START_PX{ 2 };
constexpr int TILE_START_PY{ 120 };

// TILE SIZE
constexpr int TILECX{ 64 };
constexpr int TILECY{ 64 };

// Tile 갯수
constexpr int TILEX{ 21 };
constexpr int TILEY{ 11 };

// Tower Size
constexpr int TOWER_SIZE{ 200 };
// Tower Max Level
constexpr int MAX_TOWER_LEVEL{ 3 };
// 가격
constexpr int GatlingPrice{ 5 };
constexpr int GooPrice{ 10 };
constexpr int FlamePrice{ 20 };
constexpr int MortarPrice{ 30 };

// 최대 점수 저장갯수
constexpr int MAX_SCORE{ 10 };