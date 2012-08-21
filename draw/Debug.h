/**
 *******************************************************************************
 * @file draw/Debug.h
 * @brief draw : log wrapper (Sources)
 * @author Edouard DUPIN
 * @date 21/08/2012
 * @par Project
 * Ewol
 *
 * @par Copyright
 * Copyright 2011 Edouard DUPIN, all right reserved
 *
 * This software is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY.
 *
 * Licence summary : 
 *    You can modify and redistribute the sources code and binaries.
 *    You can send me the bug-fix
 *
 * Term of the licence in in the file licence.txt.
 *
 *******************************************************************************
 */

#ifndef __DRAW_DEBUG_H__
#define __DRAW_DEBUG_H__

#include <etk/Types.h>
#include <etk/Debug.h>

extern const char * drawLibName;

#define DRAW_CRITICAL(data)			ETK_CRITICAL(drawLibName, data)
#define DRAW_WARNING(data)			ETK_WARNING(drawLibName, data)
#define DRAW_ERROR(data)			ETK_ERROR(drawLibName, data)
#define DRAW_INFO(data)				ETK_INFO(drawLibName, data)
#define DRAW_DEBUG(data)			ETK_DEBUG(drawLibName, data)
#define DRAW_VERBOSE(data)			ETK_VERBOSE(drawLibName, data)
#define DRAW_ASSERT(cond, data)		ETK_ASSERT(drawLibName, cond, data)
#define DRAW_CHECK_INOUT(cond)		ETK_CHECK_INOUT(drawLibName, cond)
#define DRAW_TODO(cond)				ETK_TODO(drawLibName, cond)

#endif

