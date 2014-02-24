cmake_minimum_required(VERSION 2.8)

# Declare the project
project(agg)

##
## Include C++ X11 dependency ... (check correct flags)
##
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
	CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
	if(COMPILER_SUPPORTS_CXX0X)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
	else()
		message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
	endif()
endif()


# set output path:
set(LIBRARY_OUTPUT_PATH lib/${CMAKE_BUILD_TYPE})

include_directories(.)
include_directories(agg/)
include_directories(agg/util/)

#Create src file list
set(src_files
	agg/agg_arc.cpp
	agg/agg_arrowhead.cpp
	agg/agg_bezier_arc.cpp
	agg/agg_bspline.cpp
	agg/agg_curves.cpp
	agg/agg_embedded_raster_fonts.cpp
	agg/agg_font_freetype.cpp
	agg/agg_gsv_text.cpp
	agg/agg_image_filters.cpp
	agg/agg_line_aa_basics.cpp
	agg/agg_line_profile_aa.cpp
	agg/agg_rounded_rect.cpp
	agg/agg_sqrt_tables.cpp
	agg/agg_trans_affine.cpp
	agg/agg_trans_double_path.cpp
	agg/agg_trans_single_path.cpp
	agg/agg_trans_warp_magnifier.cpp
	agg/agg_vcgen_bspline.cpp
	agg/agg_vcgen_contour.cpp
	agg/agg_vcgen_dash.cpp
	agg/agg_vcgen_markers_term.cpp
	agg/agg_vcgen_smooth_poly1.cpp
	agg/agg_vcgen_stroke.cpp
	agg/agg_vpgen_clip_polygon.cpp
	agg/agg_vpgen_clip_polyline.cpp
	agg/agg_vpgen_segmentator.cpp
	draw/debug.cpp
	draw/Color.cpp
	draw/Image.cpp
)

include_directories(${etk_SOURCE_DIR})
include_directories(${linearmath_SOURCE_DIR}/bullet/src/)

#Create a static Lib:
add_library(agg STATIC ${src_files} )
include_directories(${freetype_SOURCE_DIR})
target_link_libraries(agg freetype etk)

