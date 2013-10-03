/**
 *******************************************************************************
 * @file draw/Image.cpp
 * @brief draw Imaging system (Sources)
 * @author Edouard DUPIN
 * @date 21/08/2012
 * @par Project
 * draw
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

#include <draw/Image.h>


draw::Image::Image(void) :
	m_renderingBuffer(NULL),
	m_pixFrame(NULL),
	m_renderBase(NULL),
	m_renderArea(NULL),
	m_fillColor(0,0,0,0),
	m_strokeColor(0,0,0,0),
	m_strokeSize(0)
{
	m_size.setX(32);
	m_size.setY(32);
	Init();
}

draw::Image::Image(ivec2 size) :
	m_renderingBuffer(NULL),
	m_pixFrame(NULL),
	m_renderBase(NULL),
	m_renderArea(NULL),
	m_fillColor(0,0,0,0),
	m_strokeColor(0,0,0,0),
	m_strokeSize(0)
{
	m_size = size;
	Init();
}

void draw::Image::Init(void)
{
	// basic element :
	draw::Color tmpBg(0,0,0,0);
	// preallocate data with a basic bg elements :
	m_data.reSize(m_size.x()*m_size.y(), tmpBg);
	if (m_size.x()*m_size.y() > m_data.size()) {
		DRAW_ERROR("Allocation of data buffer in error");
		return;
	}
	// Allocate the AGG renderer system :
	m_renderingBuffer = new agg::rendering_buffer((uint8_t*)&m_data[0], m_size.x(), m_size.y(), m_size.x()*sizeof(draw::Color));
	if (NULL == m_renderingBuffer) {
		DRAW_ERROR("Allocation of the m_renderingBuffer for SVG drawing error");
		return;
	}
	
	m_pixFrame = new agg::pixfmt_rgba32(*m_renderingBuffer);
	if (NULL == m_pixFrame) {
		DRAW_ERROR("Allocation of the m_pixFrame for Image system error");
		delete(m_renderingBuffer);
		m_renderingBuffer = NULL;
		return;
	}
	
	m_renderBase = new rendererBase_t(*m_pixFrame);
	if (NULL == m_renderBase) {
		DRAW_ERROR("Allocation of the m_renderBase for Image system error");
		delete(m_pixFrame);
		m_pixFrame = NULL;
		delete(m_renderingBuffer);
		m_renderingBuffer = NULL;
		return;
	}
	
	m_renderArea = new rendererSolid_t(*m_renderBase);
	if (NULL == m_renderArea) {
		DRAW_ERROR("Allocation of the m_renderArea for Image system error");
		delete(m_renderArea);
		m_renderArea = NULL;
		delete(m_pixFrame);
		m_pixFrame = NULL;
		delete(m_renderingBuffer);
		m_renderingBuffer = NULL;
		return;
	}
}

draw::Image::~Image(void)
{
	if (NULL != m_renderArea) {
		delete(m_renderArea);
		m_renderArea = NULL;
	}
	if (NULL != m_renderBase) {
		delete(m_renderBase);
		m_renderBase = NULL;
	}
	if (NULL != m_pixFrame) {
		delete(m_pixFrame);
		m_pixFrame = NULL;
	}
	if (NULL != m_renderingBuffer) {
		delete(m_renderingBuffer);
		m_renderingBuffer = NULL;
	}
}

void draw::Image::Resize(ivec2 size)
{
	if (NULL != m_renderArea) {
		delete(m_renderArea);
		m_renderArea = NULL;
	}
	if (NULL != m_renderBase) {
		delete(m_renderBase);
		m_renderBase = NULL;
	}
	if (NULL != m_pixFrame) {
		delete(m_pixFrame);
		m_pixFrame = NULL;
	}
	if (NULL != m_renderingBuffer) {
		delete(m_renderingBuffer);
		m_renderingBuffer = NULL;
	}
	m_size = size;
	// basic element :
	draw::Color tmpBg(0,0,0,0);
	// preallocate data with a basic bg elements :
	m_data.reSize(m_size.x()*m_size.y(), tmpBg);
	if (m_size.x()*m_size.y() > m_data.size()) {
		DRAW_ERROR("Allocation of data buffer in error");
		return;
	}
	// Allocate the AGG renderer system :
	m_renderingBuffer = new agg::rendering_buffer((uint8_t*)&m_data[0], m_size.x(), m_size.y(), m_size.x()*sizeof(draw::Color));
	if (NULL == m_renderingBuffer) {
		DRAW_ERROR("Allocation of the m_renderingBuffer for SVG drawing error");
		return;
	}
	
	m_pixFrame = new agg::pixfmt_rgba32(*m_renderingBuffer);
	if (NULL == m_pixFrame) {
		DRAW_ERROR("Allocation of the m_pixFrame for Image system error");
		delete(m_renderingBuffer);
		m_renderingBuffer = NULL;
		return;
	}
	
	m_renderBase = new rendererBase_t(*m_pixFrame);
	if (NULL == m_renderBase) {
		DRAW_ERROR("Allocation of the m_renderBase for Image system error");
		delete(m_pixFrame);
		m_pixFrame = NULL;
		delete(m_renderingBuffer);
		m_renderingBuffer = NULL;
		return;
	}
	
	m_renderArea = new rendererSolid_t(*m_renderBase);
	if (NULL == m_renderArea) {
		DRAW_ERROR("Allocation of the m_renderArea for Image system error");
		delete(m_renderArea);
		m_renderArea = NULL;
		delete(m_pixFrame);
		m_pixFrame = NULL;
		delete(m_renderingBuffer);
		m_renderingBuffer = NULL;
		return;
	}
}


void draw::Image::Begin(void)
{
	
}

void draw::Image::End(void)
{
	
}

void draw::Image::MoveTo(vec2 pos)
{
	
}

void draw::Image::MoveToAbs(vec2 pos)
{
	
}

void draw::Image::LineTo(vec2 pos)
{
	
}

void draw::Image::LineToAbs(vec2 pos)
{
	
}
// link the curent line with his start
void draw::Image::Join(void)
{
	
}
// generate the display
void draw::Image::draw(void)
{
	
}

void draw::Image::Dot(vec2 pos)
{
	/*
		Begin();
		MoveTo(pos);
		LineTo(pos+etk::Vector2D<float>(1,1));
		End();
	*/
	set(pos, m_fillColor);
}

void draw::Image::Line(vec2 posStart, vec2 posEnd)
{
	Begin();
	MoveTo(posStart);
	LineTo(posEnd);
	End();
}

void draw::Image::Rectangle(vec2 pos, vec2 size)
{
	Begin();
	vec2 tmp = pos;
	MoveTo(pos);
	tmp += vec2(size.x(),0);
	LineTo(tmp);
	tmp += vec2(0,size.y());
	LineTo(tmp);
	tmp -= vec2(size.x(),0);
	LineTo(tmp);
	Join();
	End();
}

void draw::Image::Circle(vec2 pos, float radius, float angleStart, float angleStop)
{
	
}

void draw::Image::Disc(vec2 pos, float radius, float angleStart, float angleStop)
{
	
}
#ifdef BASIC_GRADIENT

void Grid::generateSDF()
{
	// Pass 0
	ivec2 tmpPos(1,1);
	for (tmpPos.setY(1) ; tmpPos.y()<m_size.y()-1 ; tmpPos+=vec2(0,1)) {
		for (tmpPos.setX(1) ; tmpPos.x()<m_size.x()-1 ; tmpPos+=vec2(1,0) ) {
			ivec2 p = get(tmpPos);
			Compare(p, tmpPos, -1,  0 );
			Compare(p, tmpPos,  0, -1 );
			Compare(p, tmpPos, -1, -1 );
			Compare(p, tmpPos,  1, -1 );
			set(tmpPos, p);
		}
		for (tmpPos.setX(m_size.x()-2) ; tmpPos.x()>0 ; tmpPos-=vec2(1,0) ) {
			ivec2 p = get(tmpPos);
			Compare(p, tmpPos, 1, 0 );
			set(tmpPos, p );
		}
	}
	// Pass 1
	for (tmpPos.setY(m_size.y()-2) ; tmpPos.y()>0 ; tmpPos-=vec2(0,1)) {
		for (tmpPos.setX(m_size.x()-2) ; tmpPos.x()>1 ; tmpPos-=vec2(1,0)) {
			ivec2 p = get(tmpPos);
			Compare(p, tmpPos,  1,  0 );
			Compare(p, tmpPos,  0,  1 );
			Compare(p, tmpPos, -1,  1 );
			Compare(p, tmpPos,  1,  1 );
			set(tmpPos, p);
		}
		for (tmpPos.setX(1) ; tmpPos.x()<m_size.x()-1 ; tmpPos+=vec2(1,0)) {
			ivec2 p = get(tmpPos);
			Compare(p, tmpPos, -1,  0 );
			set(tmpPos, p);
		}
	}
}

// see : http://www.codersnotes.com/notes/signed-distance-fields

void draw::Image::DistanceField(void)
{
	DistanceField(ivec2(0,0), m_size);
}
#endif

#define META_DIST   (8)
void draw::Image::DistanceField(ivec2 pos, ivec2 size, int32_t upscaler, int32_t startPos)
{
	#ifndef BASIC_GRADIENT
	float maxVal = 1/(1000.0*sqrtf(META_DIST*META_DIST+META_DIST*META_DIST));
	etk::Vector2D<int32_t> tmpPos;
	// generate distance system ... matrix ...
	Grid grid2(ivec2(META_DIST*2,META_DIST*2));
	for(tmpPos.setY(0) ; tmpPos.y()<META_DIST*2 ; tmpPos+=vec2(0,1) ) {
		for(tmpPos.setX(0) ; tmpPos.x<META_DIST*2 ; tmpPos+=vec2(1,0) ) {
			int32_t val = 1000.0*sqrtf((tmpPos.x()-META_DIST)*(tmpPos.x()-META_DIST) + (tmpPos.y()-META_DIST)*(tmpPos.y()-META_DIST));
			grid2.set(tmpPos, val);
		}
	}
	Grid grid1(size);
	grid1.setErrorVal(0);
	
	for(tmpPos.setY(0) ; tmpPos.y()<size.y() ; tmpPos+=vec2(0,1) ) {
		for(tmpPos.setX(0) ; tmpPos.x<size.x() ; tmpPos+=vec2(1,0) ) {
			draw::Color tmpColor = get(pos+tmpPos);
			// Points inside get marked with a x/y of zero.
			// Points outside get marked with an infinitely large distance.
			if (tmpColor.a<=0x7F) {
				grid1.setInide(tmpPos);
			} else {
				grid1.setOutside(tmpPos);
			}
		}
	}
	for(tmpPos.setY(startPos) ; tmpPos.y()<size.y() ; tmpPos+=vec2(0,upscaler) ) {
		for(tmpPos.setX(startPos) ; tmpPos.x<size.x() ; tmpPos+=vec2(upscaler,0) ) {
			int32_t insideOrOutsideCurrentPixel = grid1.get(tmpPos);
			// when out no distance find ...
			grid1.setErrorVal(insideOrOutsideCurrentPixel);
			
			ivec2 tmpPos2;
			int32_t newDist = 50000000;
			for(tmpPos2.setY(-META_DIST) ; tmpPos2.y()<META_DIST ; tmpPos+=vec2(0,1) ) {
				for(tmpPos2.setX(-META_DIST) ; tmpPos2.x()<META_DIST ; tmpPos+=vec2(1,0) ) {
					// we have an opposite factor ...
					if (insideOrOutsideCurrentPixel != grid1.get(tmpPos+tmpPos2)) {
						// get new distance
						int32_t tmpDist = grid2.get(tmpPos2 + ivec2(META_DIST,META_DIST));
						if (newDist > tmpDist) {
							newDist = tmpDist;
						}
					}
				}
			}
			// set the finded distance :
			draw::Color tmpColor = get(pos+tmpPos);
			float tmpValue = ((1.0-((float)newDist * maxVal)) * 0.5) * 128.0;
			if (tmpColor.a<=0x7F) {
				tmpColor.a = etk_avg(0, tmpValue, 255);
			} else {
				tmpColor.a = etk_avg(0, 255-tmpValue, 255);
			}
			set(pos+tmpPos, tmpColor);
		}
	}
	#else
	Grid grid1(size);
	Grid grid2(size);
	grid1.setOutsideVal(500000);
	grid2.setOutsideVal(500000);
	grid1.setErrorVal(0);
	grid2.setErrorVal(500000);
	
	ivec2 tmpPos;
	for(tmpPos.setY(0) ; tmpPos.y()<size.y() ; tmpPos+=vec2(0,1) ) {
		for(tmpPos.setX(0) ; tmpPos.x()<size.x() ; tmpPos+=vec2(1,0) ) {
			draw::Color tmpColor = get(pos+tmpPos);
			// Points inside get marked with a x/y of zero.
			// Points outside get marked with an infinitely large distance.
			if (tmpColor.a<=0x7F) {
				grid1.setInide(tmpPos);
				grid2.setOutside(tmpPos);
			} else {
				grid2.setInide(tmpPos);
				grid1.setOutside(tmpPos);
			}
		}
	}
	// generate the SDF:
	grid1.generateSDF();
	grid2.generateSDF();
	
	for(tmpPos.setY(startPos) ; tmpPos.y()<size.y() ; tmpPos+=vec2(0,upscaler) ) {
		for(tmpPos.setX(startPos) ; tmpPos.x()<size.x() ; tmpPos+=vec2(upscaler,0) ) {
			ivec2 elem1 = grid1.get(tmpPos);
			ivec2 elem2 = grid2.get(tmpPos);
			// Calculate the actual distance from the x/y
			float dist1 = elem1.length();
			float dist2 = elem2.length();
			float dist = dist1 - dist2;
			/*
			if (tmpPos.y < 32) {
				if (tmpPos.x < 32) {
					DRAW_DEBUG( "generate Distance : " << dist1 << "," << dist2 << "  == > " << (dist*3 + 128));
				} else if (tmpPos.x == 32) {
					DRAW_DEBUG( " ---" );
				}
			}
			*/
			draw::Color tmpColor = get(pos+tmpPos);
			// Clamp and scale it, just for display purposes.
			tmpColor.a = etk_avg(0, (dist*3 + 128), 255);
			set(pos+tmpPos, tmpColor);
		}
	}
	#endif
}

