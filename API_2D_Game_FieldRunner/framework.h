// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <string>
#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;
/*누수 체크 헤더*/
// ===============================
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
// ===============================

#include "External.h"
#include "Define.h"
#include "Const.h"
#include "Template.h"
#include "Struct.h"
#include "Function.h"
#include "Enum.h"
#include "AbstractFactory.h"

// Manager
#include "TimeManager.h"
#include "BmpManager.h"
#include "KeyMouseManager.h"

// 콘솔창 띄우기
#ifdef _DEBUG
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 
#else

#endif