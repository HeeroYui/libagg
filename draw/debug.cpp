/**
 *******************************************************************************
 * @file draw/debug.h
 * @brief draw : log wrapper (header)
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


#include <draw/debug.h>

int32_t draw::getLogId(void) {
	static int32_t g_val = etk::log::registerInstance("draw");
	return g_val;
}

