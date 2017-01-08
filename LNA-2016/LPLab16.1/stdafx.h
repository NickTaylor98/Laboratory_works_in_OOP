// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SEP 4096
#define TOTAL_KA _countof(FSATable)
#define ARR 255
#define MAX_EL 8192
using uc = unsigned char;

#include "targetver.h"
#include <stack>
#include <stdio.h>
#include <tchar.h>
//#include <fstream>
#include <ctime>


#include "Error.h"
#include "FST.h"
#include "In.h"
#include "Log.h"
#include "Parm.h"
#include "LT.h"
#include "IT.h"
#include "Parsing.h"
#include "Greibach.h"
#include "Pd_automat.h"
#include "PolishNotation.h"
#include "SA.h"