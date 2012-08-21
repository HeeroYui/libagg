/**
 *******************************************************************************
 * @file draw/Image.h
 * @brief draw Imaging system (header)
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

#ifndef __EWOL_IMAGE_H__
#define __EWOL_IMAGE_H__

#include <etk/Types.h>
#include <etk/Vector.h>
#include <draw/Debug.h>
#include <draw/Color.h>
#include <agg/agg_pixfmt_rgba.h>
#include <agg/agg_color_rgba.h>
#include <agg/agg_basics.h>
#include <agg/agg_rendering_buffer.h>
#include <agg/agg_rasterizer_scanline_aa.h>
#include <agg/agg_scanline_p.h>
#include <agg/agg_renderer_scanline.h>
#include <agg/agg_path_storage.h>
#include <agg/agg_conv_transform.h>
#include <agg/agg_bounding_rect.h>
#include <agg/agg_color_rgba.h>
#include <agg/agg_pixfmt_rgba.h>

namespace draw
{
	
	// basic definition type for the renderer
	typedef agg::renderer_base<agg::pixfmt_rgba32>           rendererBase_t;
	typedef agg::renderer_scanline_aa_solid<rendererBase_t>  rendererSolid_t;
	
	class Image {
		private:
			Vector2D<int32_t>             m_size;
			etk::Vector<draw::Color>      m_data;
			agg::rendering_buffer *       m_renderingBuffer;
			agg::pixfmt_rgba32 *          m_pixFrame;
			rendererBase_t *              m_renderBase;
			rendererSolid_t *             m_renderArea;
			agg::rasterizer_scanline_aa<> m_rasterizer;  //!< AGG renderer system
			agg::scanline_p8              m_scanLine;    //!< 
			// curent color for the system ...
			agg::rgba8                    m_fillColor;
			agg::rgba8                    m_strokeColor;
			float                         m_strokeSize;
		public:
			// constructor :
			Image(Vector2D<int32_t> size);
			Image(void);
			// destructor
			~Image(void);
			// initialiser
			void Init(void);
		
		// EWOL internal API for Texture system :
		public:
			void* GetTextureDataPointer(void) { return &m_data[0]; };
		
		// -----------------------------------------------
		// -- basic tools :
		// -----------------------------------------------
		public :
			//void Resize(Vector2D<int32_t> size);
			//void Resize(Vector2D<int32_t> startPos, Vector2D<int32_t> size);
			
			Vector2D<int32_t> GetSize(void) const
			{
				return m_size;
			};
			int32_t GetWidth(void) const
			{
				return m_size.x;
			};
			int32_t GetHeight(void) const
			{
				return m_size.y;
			};
			
			//void Move(Vector2D<int32_t> pos);
			
			//void Rotate(float angle); // radian
			
			//void Zoom(float coefficient);
			
			
			void Clear(void)
			{
				for (int32_t iii=0; iii<m_size.x*m_size.y; iii++) {
					m_data[iii] = m_fillColor;
				}
			}
			
			//void Mirror(bool horizontally=true) const ;
			
			//Image & operator= (const Image &image)
			
			draw::Color Get(Vector2D<int32_t> pos)
			{
				draw::Color outColor(0x00000000);
				if(    pos.x>0 && pos.x<m_size.x
				    && pos.y>0 && pos.y<m_size.y) {
					outColor = m_data[pos.x+pos.y*m_size.x];
				}
				return outColor;
			}
			
			void Set(Vector2D<int32_t> pos, draw::Color newColor)
			{
				if(    pos.x>0 && pos.x<m_size.x
				    && pos.y>0 && pos.y<m_size.y) {
					m_data[pos.x+pos.y*m_size.x] = newColor;
				}
			}
			
			//Image GetSubImage(Vector2D<int32_t> startPos, Vector2D<int32_t> size) const;
			
			//void SetData(uint8_t *data, Vector2D<int32_t> size);
			
		// -----------------------------------------------
		// -- Drawing tools :
		// -----------------------------------------------
		public :
			void Begin(void);
			void End(void);
			void SetFillColor(draw::Color newColor) {
				m_fillColor = newColor;
			}
			void SetStrokeColor(draw::Color newColor) {
				m_strokeColor = newColor;
			}
			void SetStrokeSize(float thickness) {
				m_strokeSize = thickness;
			}
			void MoveTo(Vector2D<float> pos);
			void MoveToAbs(Vector2D<float> pos);
			void LineTo(Vector2D<float> pos);
			void LineToAbs(Vector2D<float> pos);
			void Join(void);
			void Draw(void);
			
			void Line(Vector2D<float> posStart, Vector2D<float> posEnd);
			void Rectangle(Vector2D<float> pos, Vector2D<float> size);
			void Circle(Vector2D<float> pos, float radius, float angleStart=0, float angleStop=2*M_PI);
			void Disc(Vector2D<float> pos, float radius, float angleStart=0, float angleStop=2*M_PI);
	};
	
};

#endif

