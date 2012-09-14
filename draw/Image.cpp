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
	m_size.x = 32;
	m_size.y = 32;
	Init();
}

draw::Image::Image(Vector2D<int32_t> size) :
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
	m_data.ReSize(m_size.x*m_size.y, tmpBg);
	if (m_size.x*m_size.y > m_data.Size()) {
		DRAW_ERROR("Allocation of data buffer in error");
		return;
	}
	// Allocate the AGG renderer system :
	m_renderingBuffer = new agg::rendering_buffer((uint8_t*)&m_data[0], m_size.x, m_size.y, m_size.x*sizeof(draw::Color));
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

void draw::Image::Resize(Vector2D<int32_t> size)
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
	m_data.ReSize(m_size.x*m_size.y, tmpBg);
	if (m_size.x*m_size.y > m_data.Size()) {
		DRAW_ERROR("Allocation of data buffer in error");
		return;
	}
	// Allocate the AGG renderer system :
	m_renderingBuffer = new agg::rendering_buffer((uint8_t*)&m_data[0], m_size.x, m_size.y, m_size.x*sizeof(draw::Color));
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

void draw::Image::MoveTo(Vector2D<float> pos)
{
	
}

void draw::Image::MoveToAbs(Vector2D<float> pos)
{
	
}

void draw::Image::LineTo(Vector2D<float> pos)
{
	
}

void draw::Image::LineToAbs(Vector2D<float> pos)
{
	
}
// link the curent line with his start
void draw::Image::Join(void)
{
	
}
// generate the display
void draw::Image::Draw(void)
{
	
}

void draw::Image::Line(Vector2D<float> posStart, Vector2D<float> posEnd)
{
	Begin();
	MoveTo(posStart);
	LineTo(posEnd);
	End();
}

void draw::Image::Rectangle(Vector2D<float> pos, Vector2D<float> size)
{
	Begin();
	Vector2D<float> tmp = pos;
	MoveTo(pos);
	tmp.x += size.x;
	LineTo(tmp);
	tmp.y += size.y;
	LineTo(tmp);
	tmp.x -= size.x;
	LineTo(tmp);
	Join();
	End();
}

void draw::Image::Circle(Vector2D<float> pos, float radius, float angleStart, float angleStop)
{
	
}

void draw::Image::Disc(Vector2D<float> pos, float radius, float angleStart, float angleStop)
{
	
}
#ifdef BASIC_GRADIENT

void Grid::GenerateSDF()
{
	// Pass 0
	Vector2D<int32_t> tmpPos;
	for (tmpPos.y=1 ; tmpPos.y<m_size.y-1 ; tmpPos.y++) {
		for (tmpPos.x=1 ; tmpPos.x<m_size.x-1 ; tmpPos.x++) {
			Vector2D<int32_t> p = Get(tmpPos);
			Compare(p, tmpPos, -1,  0 );
			Compare(p, tmpPos,  0, -1 );
			Compare(p, tmpPos, -1, -1 );
			Compare(p, tmpPos,  1, -1 );
			Set(tmpPos, p);
		}
		for (tmpPos.x=m_size.x-2 ; tmpPos.x>0 ; tmpPos.x--) {
			Vector2D<int32_t> p = Get(tmpPos);
			Compare(p, tmpPos, 1, 0 );
			Set(tmpPos, p );
		}
	}
	// Pass 1
	for (tmpPos.y=m_size.y-2 ; tmpPos.y>0 ; tmpPos.y--) {
		for (tmpPos.x=m_size.x-2 ; tmpPos.x>1 ; tmpPos.x--) {
			Vector2D<int32_t> p = Get(tmpPos);
			Compare(p, tmpPos,  1,  0 );
			Compare(p, tmpPos,  0,  1 );
			Compare(p, tmpPos, -1,  1 );
			Compare(p, tmpPos,  1,  1 );
			Set(tmpPos, p);
		}
		for (tmpPos.x=1 ; tmpPos.x<m_size.x-1 ; tmpPos.x++) {
			Vector2D<int32_t> p = Get(tmpPos);
			Compare(p, tmpPos, -1,  0 );
			Set(tmpPos, p);
		}
	}
}

// see : http://www.codersnotes.com/notes/signed-distance-fields

void draw::Image::DistanceField(void)
{
	DistanceField(Vector2D<int32_t>(0,0), m_size);
}
#endif

#define META_DIST   (8)
void draw::Image::DistanceField(Vector2D<int32_t> pos, Vector2D<int32_t> size, int32_t upscaler, int32_t startPos)
{
	#ifndef BASIC_GRADIENT
	float maxVal = 1/(1000.0*sqrt(META_DIST*META_DIST+META_DIST*META_DIST));
	Vector2D<int32_t> tmpPos;
	// generate distance system ... matrix ...
	Grid grid2(Vector2D<int32_t>(META_DIST*2,META_DIST*2));
	for(tmpPos.y=0 ; tmpPos.y<META_DIST*2 ; tmpPos.y++ ) {
		for(tmpPos.x=0 ; tmpPos.x<META_DIST*2 ; tmpPos.x++ ) {
			int32_t val = 1000.0*sqrt((tmpPos.x-META_DIST)*(tmpPos.x-META_DIST) + (tmpPos.y-META_DIST)*(tmpPos.y-META_DIST));
			grid2.Set(tmpPos, val);
		}
	}
	Grid grid1(size);
	grid1.SetErrorVal(0);
	
	for(tmpPos.y=0 ; tmpPos.y<size.y ; tmpPos.y++ ) {
		for(tmpPos.x=0 ; tmpPos.x<size.x ; tmpPos.x++ ) {
			draw::Color tmpColor = Get(pos+tmpPos);
			// Points inside get marked with a x/y of zero.
			// Points outside get marked with an infinitely large distance.
			if (tmpColor.a<=0x7F) {
				grid1.SetInide(tmpPos);
			} else {
				grid1.SetOutside(tmpPos);
			}
		}
	}
	for(tmpPos.y=startPos ; tmpPos.y<size.y ; tmpPos.y+=upscaler ) {
		for(tmpPos.x=startPos ; tmpPos.x<size.x ; tmpPos.x+=upscaler ) {
			int32_t insideOrOutsideCurrentPixel = grid1.Get(tmpPos);
			// when out no distance find ...
			grid1.SetErrorVal(insideOrOutsideCurrentPixel);
			
			Vector2D<int32_t> tmpPos2;
			int32_t newDist = 50000000;
			for(tmpPos2.y=-META_DIST ; tmpPos2.y<META_DIST ; tmpPos2.y++ ) {
				for(tmpPos2.x=-META_DIST ; tmpPos2.x<META_DIST ; tmpPos2.x++ ) {
					// we have an opposite factor ...
					if (insideOrOutsideCurrentPixel != grid1.Get(tmpPos+tmpPos2)) {
						// get new distance
						int32_t tmpDist = grid2.Get(tmpPos2 + Vector2D<int32_t>(META_DIST,META_DIST));
						if (newDist > tmpDist) {
							newDist = tmpDist;
						}
					}
				}
			}
			// set the finded distance :
			draw::Color tmpColor = Get(pos+tmpPos);
			float tmpValue = ((1.0-((float)newDist * maxVal)) * 0.5) * 128.0;
			if (tmpColor.a<=0x7F) {
				tmpColor.a = etk_avg(0, tmpValue, 255);
			} else {
				tmpColor.a = etk_avg(0, 255-tmpValue, 255);
			}
			Set(pos+tmpPos, tmpColor);
		}
	}
	#else
	Grid grid1(size);
	Grid grid2(size);
	grid1.SetOutsideVal(500000);
	grid2.SetOutsideVal(500000);
	grid1.SetErrorVal(0);
	grid2.SetErrorVal(500000);
	
	Vector2D<int32_t> tmpPos;
	for(tmpPos.y=0 ; tmpPos.y<size.y ; tmpPos.y++ ) {
		for(tmpPos.x=0 ; tmpPos.x<size.x ; tmpPos.x++ ) {
			draw::Color tmpColor = Get(pos+tmpPos);
			// Points inside get marked with a x/y of zero.
			// Points outside get marked with an infinitely large distance.
			if (tmpColor.a<=0x7F) {
				grid1.SetInide(tmpPos);
				grid2.SetOutside(tmpPos);
			} else {
				grid2.SetInide(tmpPos);
				grid1.SetOutside(tmpPos);
			}
		}
	}
	// Generate the SDF:
	grid1.GenerateSDF();
	grid2.GenerateSDF();
	
	for(tmpPos.y=startPos ; tmpPos.y<size.y ; tmpPos.y+=upscaler ) {
		for(tmpPos.x=startPos ; tmpPos.x<size.x ; tmpPos.x+=upscaler ) {
			Vector2D<int32_t> elem1 = grid1.Get(tmpPos);
			Vector2D<int32_t> elem2 = grid2.Get(tmpPos);
			// Calculate the actual distance from the x/y
			float dist1 = sqrt( (double)elem1.QuadDist() );
			float dist2 = sqrt( (double)elem2.QuadDist() );
			float dist = dist1 - dist2;
			/*
			if (tmpPos.y < 32) {
				if (tmpPos.x < 32) {
					DRAW_DEBUG( "generate Distance : " << dist1 << "," << dist2 << " ==> " << (dist*3 + 128));
				} else if (tmpPos.x == 32) {
					DRAW_DEBUG( " ---" );
				}
			}
			*/
			draw::Color tmpColor = Get(pos+tmpPos);
			// Clamp and scale it, just for display purposes.
			tmpColor.a = etk_avg(0, (dist*3 + 128), 255);
			Set(pos+tmpPos, tmpColor);
		}
	}
	#endif
}

