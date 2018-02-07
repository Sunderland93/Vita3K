// Vita3K emulator project
// Copyright (C) 2018 Vita3K team
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#pragma once

#include <module/module.h>

// SceDisplay
BRIDGE_DECL(_sceDisplayGetFrameBuf)
BRIDGE_DECL(_sceDisplayGetFrameBufInternal)
BRIDGE_DECL(_sceDisplayGetMaximumFrameBufResolution)
BRIDGE_DECL(_sceDisplayGetResolutionInfoInternal)
BRIDGE_DECL(_sceDisplaySetFrameBuf)
BRIDGE_DECL(_sceDisplaySetFrameBufForCompat)
BRIDGE_DECL(_sceDisplaySetFrameBufInternal)
BRIDGE_DECL(sceDisplayGetPrimaryHead)
BRIDGE_DECL(sceDisplayGetRefreshRate)
BRIDGE_DECL(sceDisplayGetVcount)
BRIDGE_DECL(sceDisplayGetVcountInternal)
BRIDGE_DECL(sceDisplayRegisterVblankStartCallback)
BRIDGE_DECL(sceDisplayUnregisterVblankStartCallback)
BRIDGE_DECL(sceDisplayWaitSetFrameBuf)
BRIDGE_DECL(sceDisplayWaitSetFrameBufCB)
BRIDGE_DECL(sceDisplayWaitSetFrameBufMulti)
BRIDGE_DECL(sceDisplayWaitSetFrameBufMultiCB)
BRIDGE_DECL(sceDisplayWaitVblankStart)
BRIDGE_DECL(sceDisplayWaitVblankStartCB)
BRIDGE_DECL(sceDisplayWaitVblankStartMulti)
BRIDGE_DECL(sceDisplayWaitVblankStartMultiCB)

// SceDisplayUser
BRIDGE_DECL(sceDisplayGetFrameBuf)
BRIDGE_DECL(sceDisplayGetFrameBufInternal)
BRIDGE_DECL(sceDisplayGetMaximumFrameBufResolution)
BRIDGE_DECL(sceDisplayGetResolutionInfoInternal)
BRIDGE_DECL(sceDisplaySetFrameBuf)
BRIDGE_DECL(sceDisplaySetFrameBufForCompat)
BRIDGE_DECL(sceDisplaySetFrameBufInternal)
