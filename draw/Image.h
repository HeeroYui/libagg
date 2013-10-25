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

#ifndef __DRAW_IMAGE_H__
#define __DRAW_IMAGE_H__

#include <etk/types.h>
#include <etk/Vector.h>
#include <etk/math/Vector2D.h>
#include <draw/debug.h>
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

#define BASIC_GRADIENT

#ifndef BASIC_GRADIENT
class Grid
{
	public:
		etk::Vector2D<int32_t> m_size;
		etk::Vector<int32_t> m_data;
		int32_t m_outsideVal;
		int32_t m_errorVal;
		Grid(ivec2 _size) {
			m_size = _size;
			m_outsideVal = 20;
			m_errorVal = 0;
			// basic element :
			int32_t tmpPoint = 0;
			// preallocate data with a basic bg elements :
			m_data.reSize(m_size.x()*m_size.y(), tmpPoint);
		};
		~Grid(void) { };
		void setOutsideVal(int32_t _newVal) {
			m_outsideVal = _newVal;
		}
		void setErrorVal(int32_t _newVal) {
			m_errorVal = _newVal;
		}
		void setInide(etk::Vector2D<int32_t> _pos) {
			if(    _pos.x()>=0 && _pos.x()<m_size.x()
			    && _pos.y()>=0 && _pos.y()<m_size.y()) {
				m_data[_pos.x()+_pos.y()*m_size.x()]=0;
			}
		};
		void setOutside(etk::Vector2D<int32_t> _pos) {
			if(    _pos.x()>=0 && _pos.x()<m_size.x()
			    && _pos.y()>=0 && _pos.y()<m_size.y()) {
				m_data[_pos.x()+_pos.y()*m_size.x()]=m_outsideVal;
			}
		};
		
		int32_t get(etk::Vector2D<int32_t> _pos) {
			;
			if(    _pos.x()>0 && _pos.x()<m_size.x()
			    && _pos.y()>0 && _pos.y()<m_size.y()) {
				return m_data[_pos.x()+_pos.y()*m_size.x()];
			}
			return m_errorVal;
		};
		
		void set(etk::Vector2D<int32_t> _pos, int32_t _val) {
			if(    _pos.x()>0 && _pos.x()<m_size.x()
			    && _pos.y()>0 && _pos.y()<m_size.y()) {
				m_data[_pos.x()+_pos.y()*m_size.x()] = _val;
			}
		};
		
};
#else
class Grid {
	public:
		ivec2 m_size;
		etk::Vector<ivec2> m_data;
		int32_t m_outsideVal;
		int32_t m_errorVal;
		Grid(ivec2 _size) {
			m_size = _size;
			m_outsideVal = 20;
			m_errorVal = 0;
			// basic element :
			etk::Vector2D<int32_t> tmpPoint(0,0);
			// preallocate data with a basic bg elements :
			m_data.reSize(m_size.x()*m_size.y(), tmpPoint);
		};
		~Grid(void) { };
		void setOutsideVal(int32_t _newVal) {
			m_outsideVal = _newVal;
		}
		void setErrorVal(int32_t _newVal) {
			m_errorVal = _newVal;
		}
		void setInide(ivec2 _pos) {
			//if(    pos.x>=0 && pos.x<m_size.x
			//    && pos.y>=0 && pos.y<m_size.y) {
				m_data[_pos.x()+_pos.y()*m_size.x()].setX(0);
				m_data[_pos.x()+_pos.y()*m_size.x()].setY(0);
			//}
		};
		void setOutside(ivec2 _pos) {
			//if(    pos.x>=0 && pos.x<m_size.x
			//    && pos.y>=0 && pos.y<m_size.y) {
				m_data[_pos.x()+_pos.y()*m_size.x()].setX(m_outsideVal);
				m_data[_pos.x()+_pos.y()*m_size.x()].setY(m_outsideVal);
			//}
		};
		
		ivec2 get(ivec2 _pos) {
			//if(    _pos.x>0 && _pos.x<m_size.x
			//    && _pos.y>0 && _pos.y<m_size.y) {
				return m_data[_pos.x()+_pos.y()*m_size.x()];
			//}
			//return etk::Vector2D<int32_t>(m_errorVal,m_errorVal);
		};
		
		void set(ivec2 _pos, ivec2 _val) {
			//if(    pos.x>0 && pos.x<m_size.x
			//    && pos.y>0 && pos.y<m_size.y) {
				m_data[_pos.x()+_pos.y()*m_size.x()] = _val;
			//}
		};
		
		void Compare(ivec2 &_p, ivec2 _pos, int32_t _offsetx, int32_t _offsety ) {
			_pos += ivec2(_offsetx,_offsety);
			ivec2 other = get(_pos);
			other += ivec2(_offsetx,_offsety);
			if (other.dot(_p) < _p.dot(_p)) {
				_p = other;
			}
		};
		void generateSDF(void);
};
#endif


namespace draw
{
	
	// basic definition type for the renderer
	typedef agg::renderer_base<agg::pixfmt_rgba32>           rendererBase_t;
	typedef agg::renderer_scanline_aa_solid<rendererBase_t>  rendererSolid_t;
	
	class Image {
		private:
			ivec2 m_size;
			etk::Vector<draw::Color> m_data;
			agg::rendering_buffer * m_renderingBuffer;
			agg::pixfmt_rgba32 * m_pixFrame;
			rendererBase_t * m_renderBase;
			rendererSolid_t * m_renderArea;
			agg::rasterizer_scanline_aa<> m_rasterizer;  //!< AGG renderer system
			agg::scanline_p8 m_scanLine;    //!< 
			// curent color for the system ...
			agg::rgba8 m_fillColor;
			agg::rgba8 m_strokeColor;
			float m_strokeSize;
		public:
			// constructor :
			Image(ivec2 size);
			Image(void);
			// destructor
			~Image(void);
			// initialiser
			void init(void);
		
		// EWOL internal API for Texture system :
		public:
			void* getTextureDataPointer(void) { return &m_data[0]; };
		
		// -----------------------------------------------
		// -- basic tools :
		// -----------------------------------------------
		public :
			void resize(ivec2 size);
			//void Resize(etk::Vector2D<int32_t> startPos, Vector2D<int32_t> size);
			
			ivec2 getSize(void) const {
				return m_size;
			};
			int32_t getWidth(void) const {
				return m_size.x();
			};
			int32_t getHeight(void) const {
				return m_size.y();
			};
			
			//void Move(etk::Vector2D<int32_t> pos);
			
			//void Rotate(float angle); // radian
			
			//void Zoom(float coefficient);
			
			
			void clear(void) {
				for (int32_t iii=0; iii<m_size.x()*m_size.y(); iii++) {
					m_data[iii] = m_fillColor;
				}
			}
			
			//void Mirror(bool horizontally=true) const ;
			
			//Image & operator= (const Image &image)
			
			draw::Color get(ivec2 pos) {
				draw::Color outColor(0x00000000);
				if(    pos.x()>0 && pos.x()<m_size.x()
				    && pos.y()>0 && pos.y()<m_size.y()) {
					outColor = m_data[pos.x()+pos.y()*m_size.x()];
				}
				return outColor;
			}
			
			void set(ivec2 pos, draw::Color newColor) {
				if(    pos.x()>=0 && pos.x()<m_size.x()
				    && pos.y()>=0 && pos.y()<m_size.y()) {
					m_data[pos.x()+pos.y()*m_size.x()] = newColor;
				}
			}
			
			//Image getSubImage(etk::Vector2D<int32_t> startPos, Vector2D<int32_t> size) const;
			
			//void setData(uint8_t *data, etk::Vector2D<int32_t> size);
			
		// -----------------------------------------------
		// -- drawing tools :
		// -----------------------------------------------
		public :
			void begin(void);
			void end(void);
			void setFillColor(draw::Color newColor) {
				m_fillColor = newColor;
			}
			void setStrokeColor(draw::Color newColor) {
				m_strokeColor = newColor;
			}
			void setStrokeSize(float thickness) {
				m_strokeSize = thickness;
			}
			void moveTo(vec2 pos);
			void moveToAbs(vec2 pos);
			void lineTo(vec2 pos);
			void lineToAbs(vec2 pos);
			void join(void);
			void draw(void);
			
			void line(vec2 posStart, vec2 posEnd);
			void dot(vec2 pos);
			void rectangle(vec2 pos, vec2 size);
			void circle(vec2 pos, float radius, float angleStart=0, float angleStop=2*M_PI);
			void disc(vec2 pos, float radius, float angleStart=0, float angleStop=2*M_PI);
			// generate the distant field from the alpha value of the Image
			void distanceField(void);
			void distanceField(ivec2 pos, ivec2 size, int32_t upscaler=1, int32_t startPos=0);
			
			void saveFile(const char * file) {};
		private:
			
			
	};
	
};

#endif

