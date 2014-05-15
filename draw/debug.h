/**
 *******************************************************************************
 * @file draw/debug.h
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

#include <etk/log.h>

namespace draw {
	int32_t getLogId();
};
// TODO : Review this problem of multiple intanciation of "std::stringbuf sb"
#define DRAW_BASE(info,data) \
	do { \
		if (info <= etk::log::getLevel(draw::getLogId())) { \
			std::stringbuf sb; \
			std::ostream tmpStream(&sb); \
			tmpStream << data; \
			etk::log::logStream(draw::getLogId(), info, __LINE__, __class__, __func__, tmpStream); \
		} \
	} while(0)

#define DRAW_CRITICAL(data)      DRAW_BASE(1, data)
#define DRAW_ERROR(data)         DRAW_BASE(2, data)
#define DRAW_WARNING(data)       DRAW_BASE(3, data)
#ifdef DEBUG
	#define DRAW_INFO(data)          DRAW_BASE(4, data)
	#define DRAW_DEBUG(data)         DRAW_BASE(5, data)
	#define DRAW_VERBOSE(data)       DRAW_BASE(6, data)
	#define DRAW_TODO(data)          DRAW_BASE(4, "TODO : " << data)
#else
	#define DRAW_INFO(data)          do { } while(false)
	#define DRAW_DEBUG(data)         do { } while(false)
	#define DRAW_VERBOSE(data)       do { } while(false)
	#define DRAW_TODO(data)          do { } while(false)
#endif

#define DRAW_ASSERT(cond,data) \
	do { \
		if (!(cond)) { \
			DRAW_CRITICAL(data); \
			assert(!#cond); \
		} \
	} while (0)

#endif

