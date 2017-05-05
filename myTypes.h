#ifndef PROG_PART_2_MYTYPES_H
#define PROG_PART_2_MYTYPES_H

#pragma once

//Fun��o para possibilitar o uso de carateres portugueses caso o sistema operativo seja o windows
#ifdef _WIN32
#include <windows.h>
#define setPTChar() SetConsoleCP(1252); SetConsoleOutputCP(1252);
#else
#define setPTChar() void
#endif

#endif //PROG_PART_2_MYTYPES_H
