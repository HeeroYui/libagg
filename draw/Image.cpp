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

void GenerateSDF( Grid &g )
{
	// Pass 0
	Vector2D<int32_t> tmpPos;
	for (tmpPos.y=1 ; tmpPos.y<g.m_size.y-1 ; tmpPos.y++) {
		for (tmpPos.x=1 ; tmpPos.x<g.m_size.x-1 ; tmpPos.x++) {
			Vector2D<int32_t> p = g.Get(tmpPos);
			g.Compare(p, tmpPos, -1,  0 );
			g.Compare(p, tmpPos,  0, -1 );
			g.Compare(p, tmpPos, -1, -1 );
			g.Compare(p, tmpPos,  1, -1 );
			g.Set(tmpPos, p);
		}
		for (tmpPos.x=g.m_size.x-2 ; tmpPos.x>0 ; tmpPos.x--) {
			Vector2D<int32_t> p = g.Get(tmpPos);
			g.Compare(p, tmpPos, 1, 0 );
			g.Set(tmpPos, p );
		}
	}
	// Pass 1
	for (tmpPos.y=g.m_size.y-2 ; tmpPos.y>0 ; tmpPos.y--) {
		for (tmpPos.x=g.m_size.x-2 ; tmpPos.x>0 ; tmpPos.x--) {
			Vector2D<int32_t> p = g.Get(tmpPos);
			g.Compare(p, tmpPos,  1,  0 );
			g.Compare(p, tmpPos,  0,  1 );
			g.Compare(p, tmpPos, -1,  1 );
			g.Compare(p, tmpPos,  1,  1 );
			g.Set(tmpPos, p);
		}
		for (tmpPos.x=1 ; tmpPos.x<g.m_size.x-1 ; tmpPos.x++) {
			Vector2D<int32_t> p = g.Get(tmpPos);
			g.Compare(p, tmpPos, -1,  0 );
			g.Set(tmpPos, p);
		}
	}
}

// see : http://www.codersnotes.com/notes/signed-distance-fields

void draw::Image::DistanceField(void)
{
	DistanceField(Vector2D<int32_t>(0,0), m_size);
}
void draw::Image::DistanceField(Vector2D<int32_t> pos, Vector2D<int32_t> size)
{
	Grid grid1(size);
	Grid grid2(size);
	grid1.SetOutsideVal(50);
	grid2.SetOutsideVal(50);
	
	Vector2D<int32_t> tmpPos;
	for(tmpPos.y=0 ; tmpPos.y<size.x ; tmpPos.y++ ) {
		for(tmpPos.x=0 ; tmpPos.x<size.y ; tmpPos.x++ ) {
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
	GenerateSDF( grid1 );
	GenerateSDF( grid2 );
	
	for(tmpPos.y=0 ; tmpPos.y<size.x ; tmpPos.y++ ) {
		for(tmpPos.x=0 ; tmpPos.x<size.y ; tmpPos.x++ ) {
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
}

